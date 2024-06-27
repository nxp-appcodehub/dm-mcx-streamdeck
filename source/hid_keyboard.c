/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016, 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"
#include "usb_device_class.h"
#include "usb_device_hid.h"
#include "usb_device_ch9.h"
#include "usb_device_descriptor.h"
#include "composite.h"
#include "hid_keyboard.h"
#include "fsl_debug_console.h"
#include <stdio.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
 bool completition_event = false;
 uint16_t selected_icon = kUSB_Direction1_NULL;
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE) static uint8_t s_KeyboardBuffer[USB_HID_KEYBOARD_REPORT_LENGTH];
static usb_device_composite_struct_t *s_UsbDeviceComposite;
static usb_device_hid_keyboard_struct_t s_UsbDeviceHidKeyboard;

/*******************************************************************************
 * Code
 ******************************************************************************/

void pressed_icon_event(usb_direction_t usb_direction){
	completition_event=true;
	 switch(usb_direction)
	{
	case kUSB_Direction0:
		selected_icon = kUSB_Direction0;
		break;
	case kUSB_Direction1:
		selected_icon = kUSB_Direction1;
		break;
	case kUSB_Direction2:
		selected_icon = kUSB_Direction2;
		break;
	case kUSB_Direction3:
		selected_icon = kUSB_Direction3;
		break;
	case kUSB_Direction4:
		selected_icon = kUSB_Direction4;
		break;
	case kUSB_Direction5:
		selected_icon = kUSB_Direction5;
		break;
	case kUSB_Direction6:
		selected_icon = kUSB_Direction6;	
		break;
	case kUSB_Direction7:
		selected_icon = kUSB_Direction7;	
		break;
	case kUSB_Direction8:
		selected_icon = kUSB_Direction8;	
		break;
	case kUSB_Direction9:
		selected_icon = kUSB_Direction9;	
		break;

	case kUSB_Direction0_NULL:
		selected_icon = kUSB_Direction0_NULL;
		break;
	case kUSB_Direction1_NULL:
		selected_icon = kUSB_Direction1_NULL;
		break;
	case kUSB_Direction2_NULL:
		selected_icon = kUSB_Direction2_NULL;
		break;
	case kUSB_Direction3_NULL:
		selected_icon = kUSB_Direction3_NULL;
		break;
	case kUSB_Direction4_NULL:
		selected_icon = kUSB_Direction4_NULL;
		break;
	case kUSB_Direction5_NULL:
		selected_icon = kUSB_Direction5_NULL;
		break;
	case kUSB_Direction6_NULL:
		selected_icon = kUSB_Direction6_NULL;
		break;
	case kUSB_Direction7_NULL:
		selected_icon = kUSB_Direction7_NULL;
		break;
	case kUSB_Direction8_NULL:
		selected_icon = kUSB_Direction8_NULL;
		break;
	case kUSB_Direction9_NULL:
		selected_icon = kUSB_Direction9_NULL;
		break;
	}
}
usb_status_t USB_DeviceHidKeyboardAction(void)
{
	 if((selected_icon == kUSB_Direction0_NULL) || (selected_icon == kUSB_Direction6_NULL) || (selected_icon == kUSB_Direction7_NULL)){
		 s_UsbDeviceHidKeyboard.buffer[1] = 0x00U;
		 s_UsbDeviceHidKeyboard.buffer[0] = MULTIMEDIA_KEYBOARD;
	 }
	 else if((selected_icon == kUSB_Direction1_NULL) || (selected_icon == kUSB_Direction2_NULL) || (selected_icon == kUSB_Direction3_NULL) ||
	     		(selected_icon == kUSB_Direction4_NULL) || (selected_icon == kUSB_Direction5_NULL) || (selected_icon == kUSB_Direction8_NULL) ||
	 			(selected_icon == kUSB_Direction9_NULL)){
		 s_UsbDeviceHidKeyboard.buffer[3] = 0x00U;
		 s_UsbDeviceHidKeyboard.buffer[2] = 0x00U;
		 s_UsbDeviceHidKeyboard.buffer[1] = 0x00U;
		 s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
	 }

    if(completition_event==true){
		switch (selected_icon)
		{
			case kUSB_Direction0:/*mute - unmute*/
				s_UsbDeviceHidKeyboard.buffer[0] = MULTIMEDIA_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = 0x10U;
				PRINTF("USB COMMAND 0");
	
				break;
			case kUSB_Direction1:/*clip 1*/
				s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = MODIFERKEYS_LEFT_CTRL;
				s_UsbDeviceHidKeyboard.buffer[2] = 0x00U;
				s_UsbDeviceHidKeyboard.buffer[3] = KEY_1_EXCLAMATION_MARK;
				PRINTF("USB COMMAND 1");
                                
				break;
			case kUSB_Direction2:/*live streaming*/
				s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = MODIFERKEYS_LEFT_CTRL;
				s_UsbDeviceHidKeyboard.buffer[2] = 0x00U;
				s_UsbDeviceHidKeyboard.buffer[3] = KEY_L;
				PRINTF("USB COMMAND 2");
                                
				break;
			case kUSB_Direction3:/*clip 2*/
				s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = MODIFERKEYS_LEFT_CTRL;
				s_UsbDeviceHidKeyboard.buffer[2] = 0x00U;
				s_UsbDeviceHidKeyboard.buffer[3] = KEY_2_AT;
				PRINTF("USB COMMAND 3");
	
				break;
			case kUSB_Direction4:/*rec*/
				s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = MODIFERKEYS_LEFT_CTRL;
				s_UsbDeviceHidKeyboard.buffer[2] = 0x00U;
				s_UsbDeviceHidKeyboard.buffer[3] = KEY_R;
				PRINTF("USB COMMAND 4");
				
				break;
			case kUSB_Direction5:/*clip 3*/
				s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = MODIFERKEYS_LEFT_CTRL;
				s_UsbDeviceHidKeyboard.buffer[2] = 0x00U;
				s_UsbDeviceHidKeyboard.buffer[3] = KEY_3_NUMBER_SIGN;
				PRINTF("USB COMMAND 5");
	
				break;
			case kUSB_Direction6:/*volume up*/
				s_UsbDeviceHidKeyboard.buffer[0] = MULTIMEDIA_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = 0x20;
				PRINTF("USB COMMAND 6");
                                
				break;
			case kUSB_Direction7:/*volume down*/
				s_UsbDeviceHidKeyboard.buffer[0] = MULTIMEDIA_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = 0x40;
				PRINTF("USB COMMAND 7");
	
				break;
			case kUSB_Direction8:
				s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = MODIFERKEYS_LEFT_CTRL;
				s_UsbDeviceHidKeyboard.buffer[2] = 0x00;
				s_UsbDeviceHidKeyboard.buffer[3] = KEY_7_AMPERSAND;

				break;
			case kUSB_Direction9:
				s_UsbDeviceHidKeyboard.buffer[0] = NORMAL_KEYBOARD;
				s_UsbDeviceHidKeyboard.buffer[1] = MODIFERKEYS_LEFT_CTRL;
				s_UsbDeviceHidKeyboard.buffer[2] = 0x00;
				s_UsbDeviceHidKeyboard.buffer[3] = KEY_4_DOLLAR;
				break;
			default:
				break;
		}
    }
    completition_event=false;

    if((selected_icon == kUSB_Direction0) || (selected_icon == kUSB_Direction6) || (selected_icon == kUSB_Direction7) ||
       (selected_icon == kUSB_Direction0_NULL) || (selected_icon == kUSB_Direction6_NULL) || (selected_icon == kUSB_Direction7_NULL)){

    	return USB_DeviceHidSend(s_UsbDeviceComposite->hidKeyboardHandle, USB_HID_KEYBOARD_ENDPOINT_IN,
    	                             s_UsbDeviceHidKeyboard.buffer, 0x03);
    }
    else if((selected_icon == kUSB_Direction1) || (selected_icon == kUSB_Direction2) || (selected_icon == kUSB_Direction3) ||
    		(selected_icon == kUSB_Direction4) || (selected_icon == kUSB_Direction5) || (selected_icon == kUSB_Direction8) ||
			(selected_icon == kUSB_Direction9) ||
			(selected_icon == kUSB_Direction1_NULL) || (selected_icon == kUSB_Direction2_NULL) || (selected_icon == kUSB_Direction3_NULL) ||
			(selected_icon == kUSB_Direction4_NULL) || (selected_icon == kUSB_Direction5_NULL) || (selected_icon == kUSB_Direction8_NULL) ||
			(selected_icon == kUSB_Direction9_NULL)){

    	return USB_DeviceHidSend(s_UsbDeviceComposite->hidKeyboardHandle, USB_HID_KEYBOARD_ENDPOINT_IN,
    	                             s_UsbDeviceHidKeyboard.buffer, USB_HID_KEYBOARD_REPORT_LENGTH);
    }

}

usb_status_t USB_DeviceHidKeyboardCallback(class_handle_t handle, uint32_t event, void *param)
{
    usb_status_t error = kStatus_USB_InvalidRequest;

    switch (event)
    {
        case kUSB_DeviceHidEventSendResponse:
            if (s_UsbDeviceComposite->attach)
            {

            }
            break;
        case kUSB_DeviceHidEventGetReport:
        case kUSB_DeviceHidEventSetReport:
        case kUSB_DeviceHidEventRequestReportBuffer:
            break;
        case kUSB_DeviceHidEventGetIdle:
        case kUSB_DeviceHidEventGetProtocol:
        case kUSB_DeviceHidEventSetIdle:
        case kUSB_DeviceHidEventSetProtocol:
            error = kStatus_USB_Success;
            break;
        default:
            break;
    }

    return error;
}

usb_status_t USB_DeviceHidKeyboardSetConfigure(class_handle_t handle, uint8_t configure)
{
    if (USB_COMPOSITE_CONFIGURE_INDEX == configure)
    {
        return USB_DeviceHidKeyboardAction(); /* run the cursor movement code */
    }
    return kStatus_USB_Error;
}

usb_status_t USB_DeviceHidKeyboardSetInterface(class_handle_t handle, uint8_t interface, uint8_t alternateSetting)
{
    if (USB_HID_KEYBOARD_INTERFACE_INDEX == interface)
    {
        return USB_DeviceHidKeyboardAction(); /* run the cursor movement code */
    }
    return kStatus_USB_Error;
}

usb_status_t USB_DeviceHidKeyboardInit(usb_device_composite_struct_t *deviceComposite)
{
    s_UsbDeviceComposite          = deviceComposite;
    s_UsbDeviceHidKeyboard.buffer = s_KeyboardBuffer;
    return kStatus_USB_Success;
}
