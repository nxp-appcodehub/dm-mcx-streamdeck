#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG__FONDO_03_ALPHA_800X480
#define LV_ATTRIBUTE_IMG__FONDO_03_ALPHA_800X480
#endif

extern const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG__FONDO_03_ALPHA_800X480 unsigned char _Fondo_03_alpha_800x480_map[];

const lv_img_dsc_t _Fondo_03_alpha_800x480 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 800,
  .header.h = 480,
  .data_size = 384000 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = _Fondo_03_alpha_800x480_map,
};
