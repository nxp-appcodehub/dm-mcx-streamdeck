/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file is manually written while it is supposed to be generated by the MCUXpresso Config Tools.
 * Will update when the device is supported by MCUXpresso Config Tools.
 **********************************************************************************************************************/

#include "fsl_common.h"
#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

void BOARD_InitBootPins(void)
{
    BOARD_InitPins();

}

void BOARD_InitPins(void)
{ 
	 CLOCK_EnableClock(kCLOCK_Port0);
	    CLOCK_EnableClock(kCLOCK_Port1);
	    CLOCK_EnableClock(kCLOCK_Port2);
	    CLOCK_EnableClock(kCLOCK_Port3);
	    CLOCK_EnableClock(kCLOCK_Port4);

	    CLOCK_EnableClock(kCLOCK_Gpio0);
	    CLOCK_EnableClock(kCLOCK_Gpio1);
	    CLOCK_EnableClock(kCLOCK_Gpio2);
	    CLOCK_EnableClock(kCLOCK_Gpio3);
	    CLOCK_EnableClock(kCLOCK_Gpio4);

	     /*debug uart pin configuration*/
	    PORT_SetPinMux(PORT3, 20U, kPORT_MuxAlt3);//uart6_rx P3_20
	    PORT_SetPinMux(PORT3, 21U, kPORT_MuxAlt3);//uart6_tx P3_21

	     /*I3C0 pin configuration*/
	    PORT0->PCR[20] = 10<<8 | 1<<5 | 1<<12;//I3C0_SDA,P0_20
	    PORT0->PCR[21] = 10<<8 | 1<<5 | 1<<12;//I3C0_SCL,P0_21
	    PORT0->PCR[22] = 10<<8 | 1<<12;       //I3C0_PUR,P0_22

	     /*camera control pin configuration*/
	    PORT_SetPinMux(PORT1, 18U, 0);/* PORT1_18 is configured as GPIO, P1_18/EZH_LCD_D14_CAMERA_PDOWN */
	    GPIO1->PDDR |=(1U << 18);//SET PDOWN pin output
	    GPIO1->PCOR |=(1U << 18);//SET PDOWN LOW

	    PORT_SetPinMux(PORT1, 19U, 0);/* PORT1_19 is configured as GPIO, P1_19/EZH_LCD_D15_CAMERA_RST   */
	    GPIO1->PDDR |=(1U << 19);//SET RESET pin output
	    GPIO1->PSOR |=(1U << 19);//SET RESET HIHG

	    PORT0->PCR[10] = 1<<12 |( 1<<6 );/* PORT0_10 is configured as GPIO, P0_10/EZH_CAMERA_VSYNC */
	    PORT0->PCR[11] = 1<<12 |( 1<<6 );/* PORT0_11 is configured as GPIO, P0_11/EZH_CAMERA_HSYNC */
	    PORT0->PCR[14] = 1<<12 |( 1<<6 );/* PORT0_14 is configured as GPIO, P0_14/EZH_CAMERA_PCLK */

	    PORT_SetPinMux(PORT2, 2U, kPORT_MuxAsGpio);/* CLKOUT AT P2_2    P0_6/P2_2/CAMERA_CLKIN*/

	    PORT1->PCR[22] = 7<<8 ;//EZH_PIO18, PIO1_22 , output for debugging

	    PORT1->PCR[4]  = (7<<8) |(1<<12); //EZH_PIO0, PIO1_4,P1_4/EZH_LCD_D0_CAMERA_D0/SAI0_TXD1
	    PORT1->PCR[5]  = (7<<8) |(1<<12); //EZH_PIO1, PIO1_5,P1_5/EZH_LCD_D1_CAMERA_D1
	    PORT1->PCR[6]  = (7<<8) |(1<<12); //EZH_PIO2, PIO1_6,P1_6/EZH_LCD_D2_CAMERA_D2
	    PORT1->PCR[7]  = (7<<8) |(1<<12); //EZH_PIO3, PIO1_7,P1_7/EZH_LCD_D3_CAMERA_D3
	    PORT1->PCR[8]  = (7<<8) |(1<<12); //EZH_PIO4, PIO1_8,P1_8/EZH_LCD_D4_CAMERA_D4
	    PORT1->PCR[9]  = (7<<8) |(1<<12); //EZH_PIO5, PIO1_9,P1_9/EZH_LCD_D5_CAMERA_D5
	    PORT1->PCR[10] = (7<<8) |(1<<12); //EZH_PIO6, PIO1_10,P1_10/EZH_LCD_D6_CAMERA_D6
	    PORT1->PCR[11] = (7<<8) |(1<<12); //EZH_PIO7, PIO1_11,P1_11/EZH_LCD_D7_CAMERA_D7

	     /*I2C0 pin configuration*/
	    const port_pin_config_t port0_16_pinP0_config = {/* Internal pull-up resistor is enabled */
	                                                     kPORT_PullUp,
	                                                     /* Low internal pull resistor value is selected. */
	                                                     kPORT_LowPullResistor,
	                                                     /* Fast slew rate is configured */
	                                                     kPORT_FastSlewRate,
	                                                     /* Passive input filter is disabled */
	                                                     kPORT_PassiveFilterDisable,
	                                                     /* Open drain output is disabled */
	                                                     kPORT_OpenDrainDisable,
	                                                     /* Low drive strength is configured */
	                                                     kPORT_LowDriveStrength,
	                                                     /* Pin is configured as PIO0_16 */
	                                                     kPORT_MuxAlt2,
	                                                     /* Digital input enabled */
	                                                     kPORT_InputBufferEnable,
	                                                     /* Digital input is not inverted */
	                                                     kPORT_InputNormal,
	                                                     /* Pin Control Register fields [15:0] are not locked */
	                                                     kPORT_UnlockRegister};
	    /* PORT0_16 (pin P0) is configured as I2C_SDA */
	    PORT_SetPinConfig(PORT0, 16U, &port0_16_pinP0_config);

	    const port_pin_config_t port0_17_pinP1_config = {/* Internal pull-up resistor is enabled */
	                                                     kPORT_PullUp,
	                                                     /* Low internal pull resistor value is selected. */
	                                                     kPORT_LowPullResistor,
	                                                     /* Fast slew rate is configured */
	                                                     kPORT_FastSlewRate,
	                                                     /* Passive input filter is disabled */
	                                                     kPORT_PassiveFilterDisable,
	                                                     /* Open drain output is disabled */
	                                                     kPORT_OpenDrainDisable,
	                                                     /* Low drive strength is configured */
	                                                     kPORT_LowDriveStrength,
	                                                     /* Pin is configured as PIO0_17 */
	                                                     kPORT_MuxAlt2,
	                                                     /* Digital input enabled */
	                                                     kPORT_InputBufferEnable,
	                                                     /* Digital input is not inverted */
	                                                     kPORT_InputNormal,
	                                                     /* Pin Control Register fields [15:0] are not locked */
	                                                     kPORT_UnlockRegister};
	    /* PORT0_17 (pin P1) is configured as I2C_SCL */
	    PORT_SetPinConfig(PORT0, 17U, &port0_17_pinP1_config);

	     /*I2C2 pin configuration*/
	    const port_pin_config_t port4_0_pinP1_config = {/* Internal pull-up resistor is enabled */
	                                                     kPORT_PullUp,
	                                                     /* Low internal pull resistor value is selected. */
	                                                     kPORT_LowPullResistor,
	                                                     /* Fast slew rate is configured */
	                                                     kPORT_FastSlewRate,
	                                                     /* Passive input filter is disabled */
	                                                     kPORT_PassiveFilterDisable,
	                                                     /* Open drain output is disabled */
	                                                     kPORT_OpenDrainDisable,
	                                                     /* Low drive strength is configured */
	                                                     kPORT_LowDriveStrength,
	                                                     /* Pin is configured as PIO0_6 */
	                                                     kPORT_MuxAlt2,
	                                                     /* Digital input enabled */
	                                                     kPORT_InputBufferEnable,
	                                                     /* Digital input is not inverted */
	                                                     kPORT_InputNormal,
	                                                     /* Pin Control Register fields [15:0] are not locked */
	                                                     kPORT_UnlockRegister};
	    /* PORT4_0 (pin P1) is configured as I2C_SDA */
	    PORT_SetPinConfig(PORT4, 0U, &port4_0_pinP1_config);
	    PORT_SetPinMux(PORT4, 0U, kPORT_MuxAlt2);

	    const port_pin_config_t port4_1_pinP2_config = {/* Internal pull-up resistor is enabled */
	                                                     kPORT_PullUp,
	                                                     /* Low internal pull resistor value is selected. */
	                                                     kPORT_LowPullResistor,
	                                                     /* Fast slew rate is configured */
	                                                     kPORT_FastSlewRate,
	                                                     /* Passive input filter is disabled */
	                                                     kPORT_PassiveFilterDisable,
	                                                     /* Open drain output is disabled */
	                                                     kPORT_OpenDrainDisable,
	                                                     /* Low drive strength is configured */
	                                                     kPORT_LowDriveStrength,
	                                                     /* Pin is configured as PIO0_6 */
	                                                     kPORT_MuxAlt2,
	                                                     /* Digital input enabled */
	                                                     kPORT_InputBufferEnable,
	                                                     /* Digital input is not inverted */
	                                                     kPORT_InputNormal,
	                                                     /* Pin Control Register fields [15:0] are not locked */
	                                                     kPORT_UnlockRegister};
	    /* PORT4_1 (pin P2) is configured as I2C_SCL */
	    PORT_SetPinConfig(PORT4, 1U, &port4_1_pinP2_config);
	    PORT_SetPinMux(PORT4, 1U, kPORT_MuxAlt2);

}
/* Configure port mux of FlexIO data pins */
void FLEXIO_8080_Config_Data_Pin(void)
{

    FLEXIO_DATA0_PORT->PCR[FLEXIO_DATA0_PIN] = PORT_PCR_MUX(FLEXIO_DATA0_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D0 */
    FLEXIO_DATA1_PORT->PCR[FLEXIO_DATA1_PIN] = PORT_PCR_MUX(FLEXIO_DATA1_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D1 */
    FLEXIO_DATA2_PORT->PCR[FLEXIO_DATA2_PIN] = PORT_PCR_MUX(FLEXIO_DATA2_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D2 */
    FLEXIO_DATA3_PORT->PCR[FLEXIO_DATA3_PIN] = PORT_PCR_MUX(FLEXIO_DATA3_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D3 */
    FLEXIO_DATA4_PORT->PCR[FLEXIO_DATA4_PIN] = PORT_PCR_MUX(FLEXIO_DATA4_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D4 */
    FLEXIO_DATA5_PORT->PCR[FLEXIO_DATA5_PIN] = PORT_PCR_MUX(FLEXIO_DATA5_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D5 */
    FLEXIO_DATA6_PORT->PCR[FLEXIO_DATA6_PIN] = PORT_PCR_MUX(FLEXIO_DATA6_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D6 */
    FLEXIO_DATA7_PORT->PCR[FLEXIO_DATA7_PIN] = PORT_PCR_MUX(FLEXIO_DATA7_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D7 */

    FLEXIO_DATA8_PORT->PCR[FLEXIO_DATA8_PIN] = PORT_PCR_MUX(FLEXIO_DATA8_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D8 */
    FLEXIO_DATA9_PORT->PCR[FLEXIO_DATA9_PIN] = PORT_PCR_MUX(FLEXIO_DATA9_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D9 */
    FLEXIO_DATA10_PORT->PCR[FLEXIO_DATA10_PIN] = PORT_PCR_MUX(FLEXIO_DATA10_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);    /* FXIO0_D10 */
    FLEXIO_DATA11_PORT->PCR[FLEXIO_DATA11_PIN] = PORT_PCR_MUX(FLEXIO_DATA11_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);    /* FXIO0_D11 */
    FLEXIO_DATA12_PORT->PCR[FLEXIO_DATA12_PIN] = PORT_PCR_MUX(FLEXIO_DATA12_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);    /* FXIO0_D12 */
    FLEXIO_DATA13_PORT->PCR[FLEXIO_DATA13_PIN] = PORT_PCR_MUX(FLEXIO_DATA13_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);    /* FXIO0_D13 */
    FLEXIO_DATA14_PORT->PCR[FLEXIO_DATA14_PIN] = PORT_PCR_MUX(FLEXIO_DATA14_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);    /* FXIO0_D14 */
    FLEXIO_DATA15_PORT->PCR[FLEXIO_DATA15_PIN] = PORT_PCR_MUX(FLEXIO_DATA15_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);    /* FXIO0_D15 */
}

/* Configure FLEXIO_WR pin as FlexIO function */
void FLEXIO_8080_Config_WR_FlexIO(void)
{
    FLEXIO_WR_PORT->PCR[FLEXIO_WR_PIN] = PORT_PCR_MUX(FLEXIO_WR_PIN_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
//    FLEXIO_WR_PORT->PCR[FLEXIO_WR_PIN] = PORT_PCR_MUX(FLEXIO_WR_PIN_MUX);
}

/* Configure FLEXIO_WR pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_WR_GPIO(void)
{
    FLEXIO_WR_GPIO->PSOR |= 1U << FLEXIO_WR_PIN;
    FLEXIO_WR_GPIO->PDDR |= 1U << FLEXIO_WR_PIN;
    FLEXIO_WR_PORT->PCR[FLEXIO_WR_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Configure FLEXIO_RD pin as FlexIO function */
void FLEXIO_8080_Config_RD_FlexIO(void)
{
    FLEXIO_RD_PORT->PCR[FLEXIO_RD_PIN] = PORT_PCR_MUX(FLEXIO_RD_PIN_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Configure FLEXIO_RD pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_RD_GPIO(void)
{
    FLEXIO_RD_GPIO->PSOR |= 1U << FLEXIO_RD_PIN;
    FLEXIO_RD_GPIO->PDDR |= 1U << FLEXIO_RD_PIN;
    FLEXIO_RD_PORT->PCR[FLEXIO_RD_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Configure FLEXIO_CS pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_CS_GPIO(void)
{
    FLEXIO_CS_GPIO->PSOR |= 1U << FLEXIO_CS_PIN;
    FLEXIO_CS_GPIO->PDDR |= 1U << FLEXIO_CS_PIN;
    FLEXIO_CS_PORT->PCR[FLEXIO_CS_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Set FLEXIO_CS pin's level */
void FLEXIO_8080_Set_CS_Pin(bool level)
{
    if(level)
    {
        FLEXIO_CS_GPIO->PSOR |= 1U << FLEXIO_CS_PIN;
    }
    else
    {
        FLEXIO_CS_GPIO->PCOR |= 1U << FLEXIO_CS_PIN;
    }
}

/* Configure RS pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_RS_GPIO(void)
{
    FLEXIO_RS_GPIO->PSOR |= 1U << FLEXIO_RS_PIN;
    FLEXIO_RS_GPIO->PDDR |= 1U << FLEXIO_RS_PIN;
    FLEXIO_RS_PORT->PCR[FLEXIO_RS_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Set RS pin's level */
void FLEXIO_8080_Set_RS_Pin(bool level)
{
    if(level)
    {
        FLEXIO_RS_GPIO->PSOR |= 1U << FLEXIO_RS_PIN;
    }
    else
    {
        FLEXIO_RS_GPIO->PCOR |= 1U << FLEXIO_RS_PIN;
    }
}

/* Configure ReSet pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_ReSet_GPIO(void)
{
    FLEXIO_ReSet_GPIO->PCOR |= 1U << FLEXIO_ReSet_PIN;
    FLEXIO_ReSet_GPIO->PDDR |= 1U << FLEXIO_ReSet_PIN;
    FLEXIO_ReSet_PORT->PCR[FLEXIO_ReSet_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Set ReSet pin's level */
void FLEXIO_8080_Set_ReSet_Pin(bool level)
{
    if(level)
    {
        FLEXIO_ReSet_GPIO->PSOR |= 1U << FLEXIO_ReSet_PIN;
    }
    else
    {
        FLEXIO_ReSet_GPIO->PCOR |= 1U << FLEXIO_ReSet_PIN;
    }
}

/* Configure ReSet pin as GPIO function and outputting high level */
void LCD_Touch_Config_INT_GPIO_Output(void)
{
    LCD_Touch_INT_GPIO->PSOR |= 1U << LCD_Touch_INT_PIN;
    LCD_Touch_INT_GPIO->PDDR |= 1U << LCD_Touch_INT_PIN;
    LCD_Touch_INT_PORT->PCR[LCD_Touch_INT_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}
/* Configure ReSet pin as GPIO function and outputting high level */
void LCD_Touch_Config_INT_GPIO_Input(void)
{
    LCD_Touch_INT_GPIO->PDDR &= ~(1U << LCD_Touch_INT_PIN);
    LCD_Touch_INT_PORT->PCR[LCD_Touch_INT_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Set ReSet pin's level */
void LCD_Touch_Set_INT_Pin(bool level)
{
    if(level)
    {
        LCD_Touch_INT_GPIO->PSOR |= 1U << LCD_Touch_INT_PIN;
    }
    else
    {
        LCD_Touch_INT_GPIO->PCOR |= 1U << LCD_Touch_INT_PIN;
    }
}


/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
