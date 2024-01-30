/*
 * Copyright 2019, 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LVGL_SUPPORT_H
#define LVGL_SUPPORT_H

#include <stdint.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if LCD_SSD1963
#define LCD_WIDTH           800
#define LCD_HEIGHT          480
#endif
#if (LCD_ST7796S_TFT||LCD_ST7796S_IPS)
#define LCD_WIDTH           480
#define LCD_HEIGHT          320
#endif
#define LCD_FB_BYTE_PER_PIXEL 2
/* The virtual buffer for DBI panel, it should be ~1/10 screen size. */
#define LCD_VIRTUAL_BUF_SIZE (LCD_WIDTH * 32)

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void lv_port_disp_init(void);
void PMIC_Init(void);
void lv_port_indev_init(void);


#if defined(__cplusplus)
}
#endif

#endif /*LVGL_SUPPORT_H */
