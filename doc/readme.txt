Overview
========

This project is used to work with LVGL GUI Guider. The GUI Guider generated
code is placed in the folder "generated". The example generated code shows a
button in the panel.

Toolchain supported
===================
- GCC ARM Embedded  10.3.1
- MCUXpresso  11.7.0
- IAR embedded Workbench  9.30.1
- Keil MDK  5.37

Hardware requirements
=====================
- Micro USB cable
- MCX-N9XX-EVK board
- 
- LCD-PAR-S035 - parallel interface, small and 035 stands for size 3.5
- Personal Computer

Board settings
==============
connect the display board to the J12 header 

Prepare the Demo
================
1.  Power the board using a micro USB cable connected to J2 USB port on the board, attach debugger to J5 connector
2.  Build the project.
3.  Download the program to the target board.
4.  Reset the SoC and run the project.
Select the Board
in the preprocessor includes add 
LCD_SSD1963 to use the Micro E lcd
LCD_ST7796S_IPS to use the Low Cost LCD

in lvgl_guider.c 
change the MACRO LCD whit 
MikroEDisplay to Micro E 
LowCostDisplay to Low Cost
Running the demo
================
