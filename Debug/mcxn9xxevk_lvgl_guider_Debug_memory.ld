/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2024
 * Generated linker script file for MCXN947
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v11.7.1 [Build 9221] [2023-03-28] on Jan 22, 2024, 10:39:01 AM
 */

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH0 (rx) : ORIGIN = 0x0, LENGTH = 0x200000 /* 2M bytes (alias Flash) */  
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x60000 /* 384K bytes (alias RAM) */  
  SRAMX (rwx) : ORIGIN = 0x4000000, LENGTH = 0x18000 /* 96K bytes (alias RAM2) */  
  SRAMH (rwx) : ORIGIN = 0x20060000, LENGTH = 0x8000 /* 32K bytes (alias RAM3) */  
  USB_RAM (rwx) : ORIGIN = 0x400ba000, LENGTH = 0x1000 /* 4K bytes (alias RAM4) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH0 = 0x0  ; /* PROGRAM_FLASH0 */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_PROGRAM_FLASH0 = 0x0 + 0x200000 ; /* 2M bytes */  
  __top_Flash = 0x0 + 0x200000 ; /* 2M bytes */  
  __base_SRAM = 0x20000000  ; /* SRAM */  
  __base_RAM = 0x20000000 ; /* RAM */  
  __top_SRAM = 0x20000000 + 0x60000 ; /* 384K bytes */  
  __top_RAM = 0x20000000 + 0x60000 ; /* 384K bytes */  
  __base_SRAMX = 0x4000000  ; /* SRAMX */  
  __base_RAM2 = 0x4000000 ; /* RAM2 */  
  __top_SRAMX = 0x4000000 + 0x18000 ; /* 96K bytes */  
  __top_RAM2 = 0x4000000 + 0x18000 ; /* 96K bytes */  
  __base_SRAMH = 0x20060000  ; /* SRAMH */  
  __base_RAM3 = 0x20060000 ; /* RAM3 */  
  __top_SRAMH = 0x20060000 + 0x8000 ; /* 32K bytes */  
  __top_RAM3 = 0x20060000 + 0x8000 ; /* 32K bytes */  
  __base_USB_RAM = 0x400ba000  ; /* USB_RAM */  
  __base_RAM4 = 0x400ba000 ; /* RAM4 */  
  __top_USB_RAM = 0x400ba000 + 0x1000 ; /* 4K bytes */  
  __top_RAM4 = 0x400ba000 + 0x1000 ; /* 4K bytes */  
