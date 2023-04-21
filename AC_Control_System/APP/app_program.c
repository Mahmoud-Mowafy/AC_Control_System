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
	LCD_clear();
	LCD_setCursor(0,0);
	LCD_sendString("Hello");
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

