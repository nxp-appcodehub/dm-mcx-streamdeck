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


void ui_init_style(lv_style_t * style)
{
  if (style->prop_cnt > 1)
    lv_style_reset(style);
  else
    lv_style_init(style);
}

void init_scr_del_flag(lv_ui *ui)
{
  
	ui->screen_del = true;
}

void setup_ui(lv_ui *ui)
{


#if (LCD_SSD1963)
	  init_scr_del_flag(ui);
	  setup_scr_screen_800x480(ui);
	  lv_scr_load(ui->screen_800x480);
#endif
#if (LCD_ST7796S_IPS)
    init_scr_del_flag(ui);
    setup_scr_screen(ui);
    lv_scr_load(ui->screen);
#endif
}
