/*
 * Copyright 2019-2021, 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "lvgl_support.h"
#include "lvgl.h"
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "semphr.h"
#endif

#include "board.h"
#include "lvgl_support.h"
#include "fsl_gpio.h"
#include "fsl_debug_console.h"
#include "lcd_drv.h"
#include "fsl_lpi2c.h"

#if (LCD_ST7796S_TFT||LCD_ST7796S_IPS)
#include "fsl_gt911.h"
#endif

#if (LCD_SSD1963)
#include "fsl_ft5406.h"
#endif

#include "fsl_port.h"
#include "fsl_lpflexcomm.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define USE_PCA9420_DRIVE_LCD        1
/* I2C for the touch. */
#define DEMO_TOUCH_I2C               LPI2C2
#define DEMO_TOUCH_I2C_CLOCK_FREQ    CLOCK_GetBusClkFreq()
#define DEMO_I2C_BAUDRATE            400000U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
static void DEMO_Rounder(lv_disp_drv_t * disp_drv, lv_area_t * area);
static void DEMO_InitTouch(void);
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data);
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Touch driver handle. */
#if (LCD_ST7796S_TFT||LCD_ST7796S_IPS)
gt911_handle_t touchHandle;
#endif

#if (LCD_SSD1963)
ft5406_handle_t touchHandle;
#endif
/* Touch interrupt occurs. */
volatile bool touchFlag = false;
static volatile bool s_transferDone;
SDK_ALIGN(static uint8_t s_frameBuffer[1][LCD_VIRTUAL_BUF_SIZE * LCD_FB_BYTE_PER_PIXEL], 32);
/*******************************************************************************
 * Code
 ******************************************************************************/

void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t disp_buf;

    memset(s_frameBuffer, 0, sizeof(s_frameBuffer));
    lv_disp_draw_buf_init(&disp_buf, s_frameBuffer[0], NULL, LCD_VIRTUAL_BUF_SIZE);

    /*-------------------------
     * Initialize your display
     * -----------------------*/
//    DEMO_InitLcd();

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv;      /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = DEMO_FlushDisplay;
    disp_drv.rounder_cb = DEMO_Rounder; 
    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}
static void DEMO_Rounder(lv_disp_drv_t * disp_drv, lv_area_t * area)
{
  /* Update the areas as needed.
   * For example it makes the area to start only on 8th rows and have Nx8 pixel height.*/
   area->x1 &= ~0x1f;
   area->x2 |= 0x1f;
}

static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    LCD_FillPicDMA((AreaPoints_t *)area, ( uint16_t *)color_p);
    lv_disp_flush_ready(disp_drv);
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad */
    DEMO_InitTouch();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = DEMO_ReadTouch;
    lv_indev_drv_register(&indev_drv);
}

static void DEMO_InitTouch(void)
{
    status_t status;
    lpi2c_master_config_t masterConfig;

    /*
     * masterConfig.enableMaster = true;
     * masterConfig.baudRate_Bps = 100000U;
     * masterConfig.enableTimeout = false;
     */
    LPI2C_MasterGetDefaultConfig(&masterConfig);

    /* Change the default baudrate configuration */
    masterConfig.baudRate_Hz = DEMO_I2C_BAUDRATE;

    LP_FLEXCOMM_Init(2, LP_FLEXCOMM_PERIPH_LPI2C);
    /* Initialize the I2C master peripheral */
    LPI2C_MasterInit(DEMO_TOUCH_I2C, &masterConfig, CLOCK_GetFreq(kCLOCK_Fro12M));
    /* Initialize the touch handle. */
#if LCD_SSD1963
    status = FT5406_Init(&touchHandle, DEMO_TOUCH_I2C);
#endif
    
#if (LCD_ST7796S_TFT||LCD_ST7796S_IPS)
    status = GT911_Init(&touchHandle, DEMO_TOUCH_I2C);
#endif

    if (status != kStatus_Success)
    {
        PRINTF("Touch panel init failed\n");
        assert(0);
    }
}
/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    touch_event_t touch_event;
    static int touch_x = 0;
    static int touch_y = 0;
    
    data->state = LV_INDEV_STATE_REL;   
#if LCD_SSD1963
    if (kStatus_Success == FT5406_GetSingleTouch(&touchHandle, &touch_event, &touch_x, &touch_y))
    {
        if ((touch_event == kTouch_Down) || (touch_event == kTouch_Contact))
        {
            data->state = LV_INDEV_STATE_PR;
        }
    }
#endif
#if (LCD_ST7796S_TFT||LCD_ST7796S_IPS)
    if (kStatus_Success == GT911_GetSingleTouch(&touchHandle, &touch_event, &touch_x, &touch_y))
    {
        if ((touch_event == kTouch_Down) || (touch_event == kTouch_Contact))
        {
            data->state = LV_INDEV_STATE_PR;
        }
    }
#endif
    /*Set the last pressed coordinates*/
    data->point.x = touch_x;
    data->point.y = touch_y;
}
