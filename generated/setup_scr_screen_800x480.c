/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"


#if (LCD_SSD1963)

void setup_scr_screen_800x480(lv_ui *ui)
{
	//Write codes screen_800x480
	ui->screen_800x480 = lv_obj_create(NULL);
	ui->g_kb_screen_800x480 = lv_keyboard_create(ui->screen_800x480);
	lv_obj_add_event_cb(ui->g_kb_screen_800x480, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_screen_800x480, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(ui->g_kb_screen_800x480, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_size(ui->screen_800x480, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen_800x480, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_800x480, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_800x480, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_800x480_img_1
//	ui->screen_800x480_img_1 = lv_img_create(ui->screen_800x480);
//	lv_obj_add_flag(ui->screen_800x480_img_1, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->screen_800x480_img_1, &_Fondo_03_alpha_800x480);
//	lv_img_set_pivot(ui->screen_800x480_img_1, 50,50);
//	lv_img_set_angle(ui->screen_800x480_img_1, 0);
//	lv_obj_set_pos(ui->screen_800x480_img_1, 0, 0);
//	lv_obj_set_size(ui->screen_800x480_img_1, 800, 480);
//	lv_obj_set_scrollbar_mode(ui->screen_800x480_img_1, LV_SCROLLBAR_MODE_OFF);
//
//	//Write style for screen_800x480_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
//	lv_obj_set_style_img_opa(ui->screen_800x480_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_800x480_imgbtn_1
	ui->screen_800x480_imgbtn_1 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_mic_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_mic_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_1_label = lv_label_create(ui->screen_800x480_imgbtn_1);
	lv_label_set_text(ui->screen_800x480_imgbtn_1_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_1, 45, 79);
	lv_obj_set_size(ui->screen_800x480_imgbtn_1, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_1, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_1, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_1, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes screen_800x480_imgbtn_2
	ui->screen_800x480_imgbtn_2 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_cam1_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_2, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_cam1_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_2_label = lv_label_create(ui->screen_800x480_imgbtn_2);
	lv_label_set_text(ui->screen_800x480_imgbtn_2_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_2, 45, 259);
	lv_obj_set_size(ui->screen_800x480_imgbtn_2, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_2, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_2, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_2, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes screen_800x480_imgbtn_3
	ui->screen_800x480_imgbtn_3 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_live_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_3, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_live_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_3_label = lv_label_create(ui->screen_800x480_imgbtn_3);
	lv_label_set_text(ui->screen_800x480_imgbtn_3_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_3, 233, 79);
	lv_obj_set_size(ui->screen_800x480_imgbtn_3, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_3, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_3, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_3, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes screen_800x480_imgbtn_4
	ui->screen_800x480_imgbtn_4 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_cam2_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_4, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_cam2_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_4_label = lv_label_create(ui->screen_800x480_imgbtn_4);
	lv_label_set_text(ui->screen_800x480_imgbtn_4_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_4_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_4, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_4, 233, 259);
	lv_obj_set_size(ui->screen_800x480_imgbtn_4, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_4, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_4, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_4, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes screen_800x480_imgbtn_5
	ui->screen_800x480_imgbtn_5 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_rec_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_5, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_rec_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_5_label = lv_label_create(ui->screen_800x480_imgbtn_5);
	lv_label_set_text(ui->screen_800x480_imgbtn_5_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_5_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_5, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_5, 421, 79);
	lv_obj_set_size(ui->screen_800x480_imgbtn_5, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_5, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_5, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_5, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes screen_800x480_imgbtn_6
	ui->screen_800x480_imgbtn_6 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_cam3_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_6, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_cam3_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_6_label = lv_label_create(ui->screen_800x480_imgbtn_6);
	lv_label_set_text(ui->screen_800x480_imgbtn_6_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_6_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_6, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_6, 421, 259);
	lv_obj_set_size(ui->screen_800x480_imgbtn_6, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_6, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_6, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_6, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes screen_800x480_imgbtn_7
	ui->screen_800x480_imgbtn_7 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_7, LV_IMGBTN_STATE_RELEASED, NULL, &_vol02_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_7, LV_IMGBTN_STATE_PRESSED, NULL, &_vol002_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_7_label = lv_label_create(ui->screen_800x480_imgbtn_7);
	lv_label_set_text(ui->screen_800x480_imgbtn_7_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_7_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_7_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_7, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_7, 610, 79);
	lv_obj_set_size(ui->screen_800x480_imgbtn_7, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_7, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_7, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_7, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_7, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write codes screen_800x480_imgbtn_8
	ui->screen_800x480_imgbtn_8 = lv_imgbtn_create(ui->screen_800x480);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_8, LV_IMGBTN_STATE_RELEASED, NULL, &_vol01_ina_alpha_143x144, NULL);
	lv_imgbtn_set_src(ui->screen_800x480_imgbtn_8, LV_IMGBTN_STATE_PRESSED, NULL, &_vol001_act_alpha_143x144, NULL);
	lv_obj_add_flag(ui->screen_800x480_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_800x480_imgbtn_8_label = lv_label_create(ui->screen_800x480_imgbtn_8);
	lv_label_set_text(ui->screen_800x480_imgbtn_8_label, "");
	lv_label_set_long_mode(ui->screen_800x480_imgbtn_8_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_800x480_imgbtn_8_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_800x480_imgbtn_8, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_800x480_imgbtn_8, 610, 259);
	lv_obj_set_size(ui->screen_800x480_imgbtn_8, 143, 144);
	lv_obj_set_scrollbar_mode(ui->screen_800x480_imgbtn_8, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_800x480_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_8, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_800x480_imgbtn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_800x480_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_8, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_8, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_800x480_imgbtn_8, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_800x480_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_800x480_imgbtn_8, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_800x480_imgbtn_8, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_800x480_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_800x480);

	
	//Init events for screen.
	events_init_screen_800x480(ui);
}
#endif
