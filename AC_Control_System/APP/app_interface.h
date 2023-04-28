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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* MCAL */
#include "../MCAL/timer/timer_interface.h"
#include "../MCAL/dio/dio_interface.h"
#include "../MCAL/dio/dio_private.h"

/*HAl*/
#include "../HAL/temp_sensor/temp_sensor.h"
#include "../hAL/lcd/lcd_interface.h"
#include "../HAL/kpd/kpd_interface.h"
#include "../HAL/buzzer/buzzer.h"
/*******************************************************************************************************************************************************************/
/* APP Macros */
#define DEFAULT_TEMP            20      // required = 20
#define MINIMUM_TEMP	        18
#define MAXIMUM_TEMP	        35

/* APP Delays */
#define WELCOME_MSG_DELAY       1000      // required 1 second
#define CONTROLS_MSG_DELAY      2000      // optional msg ( 2 seconds )
#define RESET_MSG_DELAY         1000    // optional msg ( 1 second )
#define REQ_TMP_MSG_DELAY       500      // required to be 0.5s
#define WRONG_ENTRY_BUZZ_DELAY  1000    // optional buzz (1 second)
#define TIMEOUT_MS_DELAY        10000   // required 10 seconds

/* APP STATES */
#define STATE_RUNNING           1
#define STATE_ADJUST            4

/* APP Buttons */
#define BTN_INCREMENT			'1'
#define BTN_DECREMENT			'2'
#define BTN_SET					'3'
#define BTN_ADJUST				'4'
#define BTN_RESET_TO_DEFAULT	'5'

/* APP Actions */
#define ACTION_INCREMENT			1
#define ACTION_DECREMENT			2

/*******************************************************************************************************************************************************************/
/* APP Functions' Prototypes */

void APP_initialization( void );
void APP_startProgram  ( void );

void APP_changeTemp(u8 u8_a_action);
void APP_switchState(u8 u8_a_state);
void APP_resetToDefault();
void APP_startAdjustTemp();
/*******************************************************************************************************************************************************************/

#endif /* APP_H_ */