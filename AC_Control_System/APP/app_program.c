/*
 * app_program.c
 *
 *   Created on: Apr 10, 2023
 *       Author: Hacker Kermit - 
 *  Description: This file contains all Application (APP) functions' implementation.
 */ 

/* APP */
#include "app_interface.h"

/*******************************************************************************************************************************************************************/
/* Declaration and Initialization */

/* Global variable to store appMode */
u16 u16_g_lmTemperatureVal;

/*******************************************************************************************************************************************************************/ 
/*

*/
void APP_initialization( void )
{
	/* HAL Initialization */

	/* MCAL Initialization */
		
	TIMER_timer0NormalModeInit( DISABLED, NULL );
	TIMER_timer2NormalModeInit( DISABLED, NULL );
	
	TEMPSENSOR_init();
	TEMPSENSOR_updateValue();
	
	
	LCD_init();
    LCD_sendString("Welcome");
    LCD_setCursor(1,0);
    LCD_sendString("Hacker Kermit Team");
    TIMER_delay_ms(1000);

    LCD_sendString("AC Control System");
    LCD_setCursor(1,0);
    LCD_sendString("The default temp = 20 ");
    TIMER_delay_ms(1000);
	LCD_clear();

    LCD_sendString("Please enter your desired temp");
    LCD_setCursor(1,0);
    LCD_sendString("Hacker Kermit Team");
    TIMER_delay_ms(1000);
	LCD_setCursor(0,0);

	LCD_clear();
	
	
}



void APP_startProgram  ( void )
{
	u16 str[50];
	TEMPSENSOR_getValue();
// 	while(1)
// 	{
// 		LCD_setCursor(0,0);
// 		TEMPSENSOR_getValue();
// 	sprintf(str, "%d", u16_g_lmTemperatureVal);
// 	LCD_sendString(str );
// 	}
}

