/*
 * app_interface.h
 *
 *   Created on: Apr 10, 2023
 *       Author: Hacker Kermit - https://github.com/AbdelrhmanWalaa/Moving-Car-Project.git
 *  Description: This file contains all Application (APP) functions' prototypes and definitions (Macros) to avoid magic numbers.
 */ 

#ifndef APP_H_
#define APP_H_

/*******************************************************************************************************************************************************************/
/* APP Includes */
/* LIB */
#include "../LIB/std.h"
#include "../LIB/bit_math.h"

/* MCAL */
#include "../MCAL/timer/timer_interface.h"
#include "../MCAL/dio/dio_interface.h"
#include "../MCAL/dio/dio_private.h"

/*HAl*/
#include "../HAL/temp_sensor/temp_sensor.h"
#include "../hal/lcd/lcd_interface.h"
//#include "../HAL/kpd/kpd_interface.h"
#include "../HAL/kpd/keypad.h"
/*******************************************************************************************************************************************************************/
/* APP Macros */
#define DEFAULT_TEMP     20
#define FREE_CELLS       12
#define MINIMUM_TEMP	 18

/* APP Modes */

#define INCREMENT			'1'
#define DECREMENT			'2'
#define SET					'3'
#define ADJUST				'4'
#define RESET_TO_DEFAULT	'5'

/*******************************************************************************************************************************************************************/
/* APP Functions' Prototypes */

void APP_initialization( void );
void APP_startProgram  ( void );
void APP_incrementTemperatureValue(&u16_g_temperatureValue);
void APP_decrementTemperatureValue(&u16_g_temperatureValue);
void APP_setTemperatureValue(&u16_g_temperatureValue);
void APP_resetTemperatureValue(&u16_g_temperatureValue);
/*******************************************************************************************************************************************************************/

#endif /* APP_H_ */