/*
 * app_program.c
 *
 *   Created on: Apr 10, 2023
 *       Author: Hacker Kermit - https://github.com/AbdelrhmanWalaa/Moving-Car-Project.git
 *  Description: This file contains all Application (APP) functions' implementation.
 */ 

/* APP */
#include "app_interface.h"

/*******************************************************************************************************************************************************************/
/* Declaration and Initialization */

/* Global variable to store appMode */


/*******************************************************************************************************************************************************************/ 
/*

*/
void APP_initialization( void )
{
	/* HAL Initialization */

	/* MCAL Initialization */
		
	TIMER_timer0NormalModeInit( DISABLED, NULL );
	TIMER_timer2NormalModeInit( ENABLED, NULL );
	DIO_init(0,DIO_U8_DDR_B_REG,DIO_OUT);
	DIO_write(0, DIO_U8_PORT_B_REG, DIO_U8_PORT_HIGH);
}



void APP_startProgram  ( void )
{
	while(1)
	{
		//DIO_toggle(0,DIO_U8_PORT_B_REG);
		//TIMER_delay_us(200);
		DIO_toggle(0,DIO_U8_PORT_B_REG);
		TIMER_delay_ms(200);
	}
}

