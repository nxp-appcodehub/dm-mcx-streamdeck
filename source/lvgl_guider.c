/*
 * Copyright 2020, 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

#include "flexio_8080_drv.h"
#include "lcd_drv.h"

#include "usb_misc.h"
#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"

#include "usb_device_class.h"
#include "usb_device_hid.h"

#include "usb_device_ch9.h"
#include "usb_device_descriptor.h"

#include "composite.h"

#include "hid_keyboard.h"


#if (defined(FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT > 0U))
#include "fsl_sysmpu.h"
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */

#if (USB_DEVICE_CONFIG_HID < 2U)
#error USB_DEVICE_CONFIG_HID need to > 1U, Please change the MARCO USB_DEVICE_CONFIG_HID in file "usb_device_config.h".
#endif
#include "usb_phy.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LowCostDisplay 		1
#define MikroEDisplay 		2
#define LCD 				LowCostDisplay
/*******************************************************************************
 * Variables
 ******************************************************************************/

static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;

void BOARD_InitHardware(void);
void USB_DeviceClockInit(void);
void USB_DeviceIsrEnable(void);
#if USB_DEVICE_CONFIG_USE_TASK
void USB_DeviceTaskFn(void *deviceHandle);
#endif

static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param);
static void USB_DeviceApplicationInit(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
//
//extern usb_device_class_struct_t g_UsbDeviceHidMouseConfig;
extern usb_device_class_struct_t g_UsbDeviceHidKeyboardConfig;

usb_device_composite_struct_t g_UsbDeviceComposite;

/* Set class configurations */
usb_device_class_config_struct_t g_CompositeClassConfig[USB_COMPOSITE_INTERFACE_COUNT] = {
    {
        USB_DeviceHidKeyboardCallback, /* HID keyboard class callback pointer */
        (class_handle_t)NULL,          /* The HID class handle, This field is set by USB_DeviceClassInit */
        &g_UsbDeviceHidKeyboardConfig, /* The HID keyboard configuration, including class code, subcode, and protocol,
                                  class
                                  type, transfer type, endpoint address, max packet size, etc.*/
    }
//    ,
//    {
//        USB_DeviceHidMouseCallback, /* HID mouse class callback pointer */
//        (class_handle_t)NULL,       /* The HID class handle, This field is set by USB_DeviceClassInit */
//        &g_UsbDeviceHidMouseConfig, /* The HID mouse configuration, including class code, subcode, and protocol, class
//                               type,
//                               transfer type, endpoint address, max packet size, etc.*/
//    }
    };

/* Set class configuration list */
usb_device_class_config_list_struct_t g_UsbDeviceCompositeConfigList = {
    g_CompositeClassConfig,        /* Class configurations */
    USB_DeviceCallback,            /* Device callback pointer */
    USB_COMPOSITE_INTERFACE_COUNT, /* Class count */
};

/*******************************************************************************
 * Code
 ******************************************************************************/
#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U))
void USB1_HS_IRQHandler(void)
{
    USB_DeviceEhciIsrFunction(g_UsbDeviceComposite.deviceHandle);
}
#endif
#if (defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U))
void USB0_FS_IRQHandler(void)
{
    USB_DeviceKhciIsrFunction(g_UsbDeviceComposite.deviceHandle);
}
#endif

void USB_DeviceClockInit(void)
{
#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
    usb_phy_config_struct_t phyConfig = {
        BOARD_USB_PHY_D_CAL,
        BOARD_USB_PHY_TXCAL45DP,
        BOARD_USB_PHY_TXCAL45DM,
    };
#endif
#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
    SPC0->ACTIVE_VDELAY = 0x0500;
    /* Change the power DCDC to 1.8v (By deafult, DCDC is 1.8V), CORELDO to 1.1v (By deafult, CORELDO is 1.0V) */
    SPC0->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_CORELDO_VDD_DS_MASK;
    SPC0->ACTIVE_CFG |= SPC_ACTIVE_CFG_DCDC_VDD_LVL(0x3) | SPC_ACTIVE_CFG_CORELDO_VDD_LVL(0x3) |
                        SPC_ACTIVE_CFG_SYSLDO_VDD_DS_MASK | SPC_ACTIVE_CFG_DCDC_VDD_DS(0x2u);
    /* Wait until it is done */
    while (SPC0->SC & SPC_SC_BUSY_MASK)
        ;
    if (0u == (SCG0->LDOCSR & SCG_LDOCSR_LDOEN_MASK))
    {
        SCG0->TRIM_LOCK = 0x5a5a0001U;
        SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;
        /* wait LDO ready */
        while (0U == (SCG0->LDOCSR & SCG_LDOCSR_VOUT_OK_MASK))
            ;
    }
    SYSCON->AHBCLKCTRLSET[2] |= SYSCON_AHBCLKCTRL2_USB_HS_MASK | SYSCON_AHBCLKCTRL2_USB_HS_PHY_MASK;
    SCG0->SOSCCFG &= ~(SCG_SOSCCFG_RANGE_MASK | SCG_SOSCCFG_EREFS_MASK);
    /* xtal = 20 ~ 30MHz */
    SCG0->SOSCCFG = (1U << SCG_SOSCCFG_RANGE_SHIFT) | (1U << SCG_SOSCCFG_EREFS_SHIFT);
    SCG0->SOSCCSR |= SCG_SOSCCSR_SOSCEN_MASK;
    while (1)
    {
        if (SCG0->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK)
        {
            break;
        }
    }
    SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK | SYSCON_CLOCK_CTRL_CLKIN_ENA_FM_USBH_LPT_MASK;
    CLOCK_EnableClock(kCLOCK_UsbHs);
    CLOCK_EnableClock(kCLOCK_UsbHsPhy);
    CLOCK_EnableUsbhsPhyPllClock(kCLOCK_Usbphy480M, 24000000U);
    CLOCK_EnableUsbhsClock();
    USB_EhciPhyInit(CONTROLLER_ID, BOARD_XTAL0_CLK_HZ, &phyConfig);
#endif
#if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
    CLOCK_AttachClk(kCLK_48M_to_USB0);
    CLOCK_EnableClock(kCLOCK_Usb0Ram);
    CLOCK_EnableClock(kCLOCK_Usb0Fs);
    CLOCK_EnableUsbfsClock();
#endif
}

void USB_DeviceIsrEnable(void)
{
    uint8_t irqNumber;
#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
    uint8_t usbDeviceEhciIrq[] = USBHS_IRQS;
    irqNumber                  = usbDeviceEhciIrq[CONTROLLER_ID - kUSB_ControllerEhci0];
#endif
#if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
    uint8_t usbDeviceKhciIrq[] = USBFS_IRQS;
    irqNumber                  = usbDeviceKhciIrq[CONTROLLER_ID - kUSB_ControllerKhci0];
#endif
    /* Install isr, set priority, and enable IRQ. */
    NVIC_SetPriority((IRQn_Type)irqNumber, USB_DEVICE_INTERRUPT_PRIORITY);
    EnableIRQ((IRQn_Type)irqNumber);
}
#if USB_DEVICE_CONFIG_USE_TASK
void USB_DeviceTaskFn(void *deviceHandle)
{
#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
    USB_DeviceEhciTaskFunction(deviceHandle);
#endif
#if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
    USB_DeviceKhciTaskFunction(deviceHandle);
#endif
}
#endif

/* The Device callback */
static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param)
{
    usb_status_t error = kStatus_USB_InvalidRequest;
    uint16_t *temp16   = (uint16_t *)param;
    uint8_t *temp8     = (uint8_t *)param;

    switch (event)
    {
        case kUSB_DeviceEventBusReset:
        {
            /* USB bus reset signal detected */
            g_UsbDeviceComposite.attach               = 0U;
            g_UsbDeviceComposite.currentConfiguration = 0U;
            error                                     = kStatus_USB_Success;
#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)) || \
    (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U))
            /* Get USB speed to configure the device, including max packet size and interval of the endpoints. */
            if (kStatus_USB_Success == USB_DeviceClassGetSpeed(CONTROLLER_ID, &g_UsbDeviceComposite.speed))
            {
                USB_DeviceSetSpeed(handle, g_UsbDeviceComposite.speed);
            }
#endif
        }
        break;
        case kUSB_DeviceEventSetConfiguration:
            if (0U == (*temp8))
            {
                g_UsbDeviceComposite.attach               = 0U;
                g_UsbDeviceComposite.currentConfiguration = 0U;
                error                                     = kStatus_USB_Success;
            }
            else if (USB_COMPOSITE_CONFIGURE_INDEX == (*temp8))
            {
                /* Set device configuration request */
                g_UsbDeviceComposite.attach = 1U;
//                USB_DeviceHidMouseSetConfigure(g_UsbDeviceComposite.hidMouseHandle, *temp8);
                USB_DeviceHidKeyboardSetConfigure(g_UsbDeviceComposite.hidKeyboardHandle, *temp8);
                g_UsbDeviceComposite.currentConfiguration = *temp8;
                error                                     = kStatus_USB_Success;
            }
            else
            {
                /* no action, return kStatus_USB_InvalidRequest. */
            }
            break;
        case kUSB_DeviceEventSetInterface:
            if (g_UsbDeviceComposite.attach)
            {
                /* Set device interface request */
                uint8_t interface        = (uint8_t)((*temp16 & 0xFF00U) >> 0x08U);
                uint8_t alternateSetting = (uint8_t)(*temp16 & 0x00FFU);
//                if (USB_HID_MOUSE_INTERFACE_INDEX == interface)
//                {
//                    if (alternateSetting < USB_HID_MOUSE_INTERFACE_ALTERNATE_COUNT)
//                    {
//                        g_UsbDeviceComposite.currentInterfaceAlternateSetting[interface] = alternateSetting;
//                        USB_DeviceHidMouseSetInterface(g_UsbDeviceComposite.hidMouseHandle, interface, alternateSetting);
//                        error = kStatus_USB_Success;
//                    }
//                }
                if (USB_HID_KEYBOARD_INTERFACE_INDEX == interface)
                {
                    if (alternateSetting < USB_HID_KEYBOARD_INTERFACE_ALTERNATE_COUNT)
                    {
                        g_UsbDeviceComposite.currentInterfaceAlternateSetting[interface] = alternateSetting;
                        USB_DeviceHidKeyboardSetInterface(g_UsbDeviceComposite.hidKeyboardHandle, interface,
                                                          alternateSetting);
                        error = kStatus_USB_Success;
                    }
                }
                else
                {
                    /* no action, return kStatus_USB_InvalidRequest. */
                }
            }
            break;
        case kUSB_DeviceEventGetConfiguration:
            if (param)
            {
                /* Get current configuration request */
                *temp8 = g_UsbDeviceComposite.currentConfiguration;
                error  = kStatus_USB_Success;
            }
            break;
        case kUSB_DeviceEventGetInterface:
            if (param)
            {
                /* Get current alternate setting of the interface request */
                uint8_t interface = (uint8_t)((*temp16 & 0xFF00U) >> 0x08U);
                if (interface < USB_COMPOSITE_INTERFACE_COUNT)
                {
                    *temp16 = (*temp16 & 0xFF00U) | g_UsbDeviceComposite.currentInterfaceAlternateSetting[interface];
                    error   = kStatus_USB_Success;
                }
            }
            break;
        case kUSB_DeviceEventGetDeviceDescriptor:
            if (param)
            {
                /* Get device descriptor request */
                error = USB_DeviceGetDeviceDescriptor(handle, (usb_device_get_device_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetConfigurationDescriptor:
            if (param)
            {
                /* Get device configuration descriptor request */
                error = USB_DeviceGetConfigurationDescriptor(handle,
                                                             (usb_device_get_configuration_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetStringDescriptor:
            if (param)
            {
                /* Get device string descriptor request */
                error = USB_DeviceGetStringDescriptor(handle, (usb_device_get_string_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetHidDescriptor:
            if (param)
            {
                /* Get hid descriptor request */
                error = USB_DeviceGetHidDescriptor(handle, (usb_device_get_hid_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetHidReportDescriptor:
            if (param)
            {
                /* Get hid report descriptor request */
                error =
                    USB_DeviceGetHidReportDescriptor(handle, (usb_device_get_hid_report_descriptor_struct_t *)param);
            }
            break;
#if (defined(USB_DEVICE_CONFIG_CV_TEST) && (USB_DEVICE_CONFIG_CV_TEST > 0U))
        case kUSB_DeviceEventGetDeviceQualifierDescriptor:
            if (param)
            {
                /* Get Qualifier descriptor request */
                error = USB_DeviceGetDeviceQualifierDescriptor(
                    handle, (usb_device_get_device_qualifier_descriptor_struct_t *)param);
            }
            break;
#endif
        case kUSB_DeviceEventGetHidPhysicalDescriptor:
            if (param)
            {
                /* Get hid physical descriptor request */
                error = USB_DeviceGetHidPhysicalDescriptor(handle,
                                                           (usb_device_get_hid_physical_descriptor_struct_t *)param);
            }
            break;
        default:
            break;
    }

    return error;
}

/* Application initialization */
static void USB_DeviceApplicationInit(void)
{
    USB_DeviceClockInit();
#if (defined(FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT > 0U))
    SYSMPU_Enable(SYSMPU, 0);
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */

    /* Set composite device to default state */
    g_UsbDeviceComposite.speed             = USB_SPEED_HIGH;
    g_UsbDeviceComposite.attach            = 0U;
//    g_UsbDeviceComposite.hidMouseHandle    = (class_handle_t)NULL;
    g_UsbDeviceComposite.hidKeyboardHandle = (class_handle_t)NULL;
    g_UsbDeviceComposite.deviceHandle      = NULL;

    if (kStatus_USB_Success !=
        USB_DeviceClassInit(CONTROLLER_ID, &g_UsbDeviceCompositeConfigList, &g_UsbDeviceComposite.deviceHandle))
    {
        usb_echo("USB device composite demo init failed\r\n");
        return;
    }
    else
    {
        usb_echo("USB device composite demo\r\n");
        /* Get the HID keyboard class handle */
        g_UsbDeviceComposite.hidKeyboardHandle = g_UsbDeviceCompositeConfigList.config[0].classHandle;
        /* Get the HID mouse class handle */
//        g_UsbDeviceComposite.hidMouseHandle = g_UsbDeviceCompositeConfigList.config[1].classHandle;

        USB_DeviceHidKeyboardInit(&g_UsbDeviceComposite);
//        USB_DeviceHidMouseInit(&g_UsbDeviceComposite);
    }

    USB_DeviceIsrEnable();

    /* Start the device function */
    /*Add one delay here to make the DP pull down long enough to allow host to detect the previous disconnection.*/
    SDK_DelayAtLeastUs(5000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    USB_DeviceRun(g_UsbDeviceComposite.deviceHandle);
}

#if USB_DEVICE_CONFIG_USE_TASK
void USB_DeviceTask(void *handle)
{
    while (1U)
    {
        USB_DeviceTaskFn(handle);
    }
}
#endif

static void AppTask(void *param)
{
	PRINTF("HELLO USER");
	USB_DeviceApplicationInit();

#if USB_DEVICE_CONFIG_USE_TASK
	if (g_UsbDeviceComposite.deviceHandle)
	{
		if (xTaskCreate(USB_DeviceTask,                        /* pointer to the task */
						"usb device task",                     /* task name for kernel awareness debugging */
						5000L / sizeof(portSTACK_TYPE),        /* task stack size */
						g_UsbDeviceComposite.deviceHandle,     /* optional task startup argument */
						5U,                                    /* initial priority */
						&g_UsbDeviceComposite.deviceTaskHandle /* optional task handle to create */
						) != pdPASS)
		{
			usb_echo("usb device task create failed!\r\n");
			return;
		}
	}
#endif


    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    s_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    for (;;)
    {
        lv_task_handler();
        vTaskDelay(5);
    }
}

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
#if defined(__CC_ARM) || (defined(__ARMCC_VERSION)) || defined(__GNUC__)
int main(void)
#else
void main(void)
#endif
{
    BaseType_t stat;

    /* Init debug lpuart. */
	CLOCK_AttachClk(kFRO12M_to_FLEXCOMM6);
	CLOCK_EnableClock(kCLOCK_LPFlexComm6);
	CLOCK_EnableClock(kCLOCK_LPUart6);
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom6Clk, 0u);
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom6Clk, 1u);

	/* Init I2C2 for Touch, LCD, PMIC*/
	CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);
	CLOCK_EnableClock(kCLOCK_LPFlexComm2);
	CLOCK_EnableClock(kCLOCK_LPI2c2);
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 0u );
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u );

	SYSCON->LPCAC_CTRL &= ~1;   // rocky: enable LPCAC ICache
	SYSCON->NVM_CTRL &= SYSCON->NVM_CTRL & ~(1<<2|1<<4); // enable flash Data cache

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* Init FlexIO for this demo. */
    Demo_FLEXIO_8080_Init();



#if LCD == MikroEDisplay
    LCD_SSD1963_Init();
#endif
#if LCD == LowCostDisplay
    LCD_ST7796S_IPS_Init();
#endif
//    PRINTF("HELLO USER");
    stat = xTaskCreate(AppTask, "lvgl", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

    if (pdPASS != stat)
    {
        PRINTF("Failed to create lvgl task");
        while (1)
            ;
    }

    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */
}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    PRINTF("Malloc failed. Increase the heap size.");

    for (;;)
        ;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    for (;;)
        ;
}
