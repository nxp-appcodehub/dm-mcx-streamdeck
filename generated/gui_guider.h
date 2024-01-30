/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *g_kb_screen;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_imgbtn_1;
	lv_obj_t *screen_imgbtn_1_label;
	lv_obj_t *screen_imgbtn_2;
	lv_obj_t *screen_imgbtn_2_label;
	lv_obj_t *screen_imgbtn_3;
	lv_obj_t *screen_imgbtn_3_label;
	lv_obj_t *screen_imgbtn_4;
	lv_obj_t *screen_imgbtn_4_label;
	lv_obj_t *screen_imgbtn_5;
	lv_obj_t *screen_imgbtn_5_label;
	lv_obj_t *screen_imgbtn_6;
	lv_obj_t *screen_imgbtn_6_label;
	lv_obj_t *screen_imgbtn_7;
	lv_obj_t *screen_imgbtn_7_label;
	lv_obj_t *screen_imgbtn_8;
	lv_obj_t *screen_imgbtn_8_label;
	lv_obj_t *screen_800x480;
	bool screen_800x480_del;
	lv_obj_t *g_kb_screen_800x480;
	lv_obj_t *screen_800x480_img_1;
	lv_obj_t *screen_800x480_imgbtn_1;
	lv_obj_t *screen_800x480_imgbtn_1_label;
	lv_obj_t *screen_800x480_imgbtn_2;
	lv_obj_t *screen_800x480_imgbtn_2_label;
	lv_obj_t *screen_800x480_imgbtn_3;
	lv_obj_t *screen_800x480_imgbtn_3_label;
	lv_obj_t *screen_800x480_imgbtn_4;
	lv_obj_t *screen_800x480_imgbtn_4_label;
	lv_obj_t *screen_800x480_imgbtn_5;
	lv_obj_t *screen_800x480_imgbtn_5_label;
	lv_obj_t *screen_800x480_imgbtn_6;
	lv_obj_t *screen_800x480_imgbtn_6_label;
	lv_obj_t *screen_800x480_imgbtn_7;
	lv_obj_t *screen_800x480_imgbtn_7_label;
	lv_obj_t *screen_800x480_imgbtn_8;
	lv_obj_t *screen_800x480_imgbtn_8_label;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;





#if (LCD_SSD1963)
void setup_scr_screen_800x480(lv_ui *ui);
//LV_IMG_DECLARE(_Fondo_03_alpha_800x480);
LV_IMG_DECLARE(_mic_ina_alpha_143x144);
LV_IMG_DECLARE(_mic_act_alpha_143x144);
LV_IMG_DECLARE(_cam1_ina_alpha_143x144);
LV_IMG_DECLARE(_cam1_act_alpha_143x144);
LV_IMG_DECLARE(_live_ina_alpha_143x144);
LV_IMG_DECLARE(_live_act_alpha_143x144);
LV_IMG_DECLARE(_cam2_ina_alpha_143x144);
LV_IMG_DECLARE(_cam2_act_alpha_143x144);
LV_IMG_DECLARE(_rec_ina_alpha_143x144);
LV_IMG_DECLARE(_rec_act_alpha_143x144);
LV_IMG_DECLARE(_cam3_ina_alpha_143x144);
LV_IMG_DECLARE(_cam3_act_alpha_143x144);
LV_IMG_DECLARE(_vol02_ina_alpha_143x144);
LV_IMG_DECLARE(_vol002_act_alpha_143x144);
LV_IMG_DECLARE(_vol01_ina_alpha_143x144);
LV_IMG_DECLARE(_vol001_act_alpha_143x144);

#endif
#if (LCD_ST7796S_IPS)
	void setup_scr_screen(lv_ui *ui);
    LV_IMG_DECLARE(_Fondo_03_alpha_480x320);
    LV_IMG_DECLARE(_mic_ina_alpha_86x96);
    LV_IMG_DECLARE(_mic_act_alpha_86x96);
    LV_IMG_DECLARE(_cam1_ina_alpha_86x96);
    LV_IMG_DECLARE(_cam1_act_alpha_86x96);
    LV_IMG_DECLARE(_live_ina_alpha_86x96);
    LV_IMG_DECLARE(_live_act_alpha_86x96);
    LV_IMG_DECLARE(_cam2_ina_alpha_86x96);
    LV_IMG_DECLARE(_cam2_act_alpha_86x96);
    LV_IMG_DECLARE(_rec_ina_alpha_86x96);
    LV_IMG_DECLARE(_rec_act_alpha_86x96);
    LV_IMG_DECLARE(_cam3_ina_alpha_86x96);
    LV_IMG_DECLARE(_cam3_act_alpha_86x96);
    LV_IMG_DECLARE(_vol02_ina_alpha_86x96);
    LV_IMG_DECLARE(_vol002_act_alpha_86x96);
    LV_IMG_DECLARE(_vol01_ina_alpha_86x96);
    LV_IMG_DECLARE(_vol001_act_alpha_86x96);

#endif

    LV_FONT_DECLARE(lv_font_montserratMedium_12)
    LV_FONT_DECLARE(lv_font_simsun_18)
	LV_FONT_DECLARE(lv_font_montserratMedium_18)


#ifdef __cplusplus
}
#endif
#endif
