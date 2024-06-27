/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "hid_keyboard.h"


uint16_t pres_unpres=0x00;
static void screen_imgbtn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
	pressed_icon_event(kUSB_Direction0);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction0_NULL);
	USB_DeviceHidKeyboardAction();//release action
		break;
	}
	default:
		break;
	}
}
static void screen_imgbtn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
#if (LCD_ST7796S_IPS)
	lv_obj_clear_state(guider_ui.screen_imgbtn_4, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.screen_imgbtn_6, LV_STATE_CHECKED);
#endif
#if (LCD_SSD1963)
	lv_obj_clear_state(guider_ui.screen_800x480_imgbtn_4, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.screen_800x480_imgbtn_6, LV_STATE_CHECKED);
#endif
	pressed_icon_event(kUSB_Direction1);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction1_NULL);
	USB_DeviceHidKeyboardAction();//release action
		break;
	}
	default:
		break;
	}
}
static void screen_imgbtn_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
	pressed_icon_event(kUSB_Direction2);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction2_NULL);
	USB_DeviceHidKeyboardAction();//release action
		break;
	}
	default:
		break;
	}
}
static void screen_imgbtn_4_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
#if (LCD_ST7796S_IPS)
	lv_obj_clear_state(guider_ui.screen_imgbtn_2, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.screen_imgbtn_6, LV_STATE_CHECKED);
#endif

#if (LCD_SSD1963)
	lv_obj_clear_state(guider_ui.screen_800x480_imgbtn_2, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.screen_800x480_imgbtn_6, LV_STATE_CHECKED);
#endif
	pressed_icon_event(kUSB_Direction3);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction3_NULL);
	USB_DeviceHidKeyboardAction();//release action
		break;
	}
	default:
		break;
	}
}
static void screen_imgbtn_5_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
	pressed_icon_event(kUSB_Direction4);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction4_NULL);
	USB_DeviceHidKeyboardAction();//release action
		break;
	}
	default:
		break;
	}
}
static void screen_imgbtn_6_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
#if (LCD_ST7796S_IPS)
	lv_obj_clear_state(guider_ui.screen_imgbtn_4, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.screen_imgbtn_2, LV_STATE_CHECKED);
#endif
#if (LCD_SSD1963)
	lv_obj_clear_state(guider_ui.screen_800x480_imgbtn_2, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.screen_800x480_imgbtn_4, LV_STATE_CHECKED);
#endif
	pressed_icon_event(kUSB_Direction5);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction5_NULL);
	USB_DeviceHidKeyboardAction();//release action
		break;
	}
	default:
		break;
	}
}
static void screen_imgbtn_7_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSING:
	{
	vTaskDelay(25);
	pressed_icon_event(kUSB_Direction6);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction6_NULL);
	USB_DeviceHidKeyboardAction();//release action

		break;
	}
	default:
		break;
	}
}
static void screen_imgbtn_8_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSING:
	{
	vTaskDelay(25);
	pressed_icon_event(kUSB_Direction7);
	USB_DeviceHidKeyboardAction();//select action
	vTaskDelay(5);
	pressed_icon_event(kUSB_Direction7_NULL);
	USB_DeviceHidKeyboardAction();//release action

		break;
	}
	default:
		break;
	}
}
void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_imgbtn_1, screen_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_imgbtn_2, screen_imgbtn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_imgbtn_3, screen_imgbtn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_imgbtn_4, screen_imgbtn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_imgbtn_5, screen_imgbtn_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_imgbtn_6, screen_imgbtn_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_imgbtn_7, screen_imgbtn_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_imgbtn_8, screen_imgbtn_8_event_handler, LV_EVENT_ALL, NULL);
}
void events_init_screen_800x480(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_1, screen_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_2, screen_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_3, screen_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_4, screen_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_5, screen_imgbtn_5_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_6, screen_imgbtn_6_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_7, screen_imgbtn_7_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_800x480_imgbtn_8, screen_imgbtn_8_event_handler, LV_EVENT_ALL, ui);
}
void events_init(lv_ui *ui)
{

}
