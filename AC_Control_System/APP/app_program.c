/*
 * app_program.c
 *
 *   Created on: Apr 10, 2023
 *       Author: Hacker Kermit - 
 *  Description: This file contains all Application (APP) functions' implementation.
 */ 

/* APP */
#include "app_interface.h"

/* ***************************************************************************************************************/
/* Declaration and Initialization */

/* Global variable to store appMode */
extern u8 u8_g_timeOut;
//extern u8 u8_g_pressFlag;
//extern u8 u8_g_keypadPressFlag;
u16 u16_g_desiredTemperatureValue = 0;
u8 u8_g_currentAppState = STATE_ADJUST;

/* ***************************************************************************************************************/
/*

*/
void APP_initialization( void )
{
	/* HAL Initialization */

	/* MCAL Initialization */
		
	TIMER_timer0NormalModeInit( DISABLED, NULL );
	TIMER_timer2NormalModeInit( ENABLED, NULL );
    /*initialize temperature sensor*/
	TEMPSENSOR_init();
    /*initialize Keypad*/
    KPD_initKPD();
    KPD_enableKPD();
    /*initialize LCD*/
 	LCD_init();
	LCD_setCursor(0,4);
    LCD_sendString((u8 *)"Welcome\nHacker Kermit");
    TIMER_delay_ms(2000);
	LCD_clear();

    LCD_sendString((u8 *)"AC Control\ndefault temp: 20");
    TIMER_delay_ms(2000);
	LCD_clear();

    u16_g_desiredTemperatureValue = DEFAULT_TEMP;
   /* ****************************************************************/
}



void APP_startProgram  ( void )
{
    while (1)
    {
        switch (u8_g_currentAppState) {

            case STATE_ADJUST:
                // run the adjust temp screen and algorithm
                APP_startAdjustTemp();
                break;

            case STATE_RUNNING:

                // Clear LCD
                LCD_clear();
                // set cursor to start of second line
                LCD_setCursor(LCD_LINE1, LCD_COL0);

                // read current temperature from sensor
                u16 u16_l_currentTemp = 0;
                TEMPSENSOR_getValue(&u16_l_currentTemp);

                // show current reading on LCD
                u8 str_lcurrentTempStr[17];
                sprintf((char *) str_lcurrentTempStr, "Current temp: %d", u16_l_currentTemp);
                LCD_sendString((u8 *) str_lcurrentTempStr);

                // Check if current temperature is higher than desired
                // in a real world situation we should turn the compressor ON to cool the air
                if(u16_l_currentTemp > u16_g_desiredTemperatureValue)
                {
                    // show bell/buzzer icon
                    LCD_setCursor(LCD_LINE0, LCD_COL15); // last char in first line
                    LCD_sendChar(LCD_CUSTOMCHAR_LOC0); // show bell/buzzer icon on LCD

                    // turn on the buzzer sound
                    BUZZER_on();
                }else{
                    BUZZER_off();
                }
                break;
            default:
                //
                break;
        }
    }
}


void APP_startAdjustTemp()
{
	LCD_clear();
	LCD_sendString((u8 *) "Please choose\nthe required tmp");
    TIMER_delay_ms(2000);
    LCD_sendString((u8 *) "    Controls\n1(+) 2(-) 3(set)");
    TIMER_delay_ms(2000);


    LCD_clear();

    u8 tempVisualizer[17];
    sprintf((char *)tempVisualizer, "Min:18 %d Max:35", u16_g_desiredTemperatureValue);
//    sprintf((char *)tempVisualizer, "%d°C (XX->XX)", u16_g_desiredTemperatureValue);
    LCD_sendString(tempVisualizer);

    // Next Line
    LCD_setCursor(LCD_LINE1,LCD_COL0);

    u8 str_l_tempPattern[17];
    // -1 to compensate LCD size only allowing 16 chars because the range of our AC temperature
    // is from MINIMUM_TEMP (18) to MAXIMUM_TEMP (35) which is 17 steps
    memset(str_l_tempPattern, '|', u16_g_desiredTemperatureValue - MINIMUM_TEMP - 1);
    LCD_sendString(str_l_tempPattern);

    /* timout 10 seconds */
    TIMER_intDelay_ms(TIMEOUT_MS_DELAY);    // timeout after 10 seconds if no key is pressed

    /* Adjust Screen */
    while(u8_g_currentAppState != STATE_RUNNING)
    {
        /* Check if keypad keys are pressed */
        u8 u8_l_pressedkey = 0;
        KPD_getPressedKey(&u8_l_pressedkey);
        switch (u8_l_pressedkey) {
            case BTN_INCREMENT:
            case BTN_DECREMENT:
                APP_changeTemp(u8_l_pressedkey == BTN_INCREMENT ? ACTION_INCREMENT : ACTION_DECREMENT);

                //reset timeout counter
                TIMER_intDelay_ms(TIMEOUT_MS_DELAY);
                break;

            case BTN_SET:
                // cancel timeout check (timer)
                u8_g_currentAppState = STATE_RUNNING;
                TIMER_timer2Stop();
                KPD_disableKPD();
                break;
            default:
                //
                break;
        }

        if(u8_g_timeOut == 1) {
            u16_g_desiredTemperatureValue = DEFAULT_TEMP;
            u8_g_timeOut = 0;
            KPD_disableKPD();
            u8_g_currentAppState = STATE_RUNNING;
        }
    }
}

void APP_changeTemp(u8 u8_a_action)
{
    LCD_setCursor(LCD_LINE0, LCD_COL7);
    if(u8_a_action == ACTION_INCREMENT)
    {
        u16_g_desiredTemperatureValue++;
        LCD_sendString((u8 *)itoa(u16_g_desiredTemperatureValue, (char *)NULL, 10));
    }else if(u8_a_action == ACTION_DECREMENT)
    {
        u16_g_desiredTemperatureValue--;
        LCD_sendString((u8 *)itoa(u16_g_desiredTemperatureValue, (char *)NULL, 10));
    }
}

void APP_resetToDefault()
{
    u16_g_desiredTemperatureValue = DEFAULT_TEMP;
    u8_g_currentAppState = STATE_RUNNING;
}



// 		u8_l_enteredAscii = u8_l_pressedkey + '0';
// 		LCD_sendChar(u8_l_enteredAscii);
// 		if(u8_g_keypadPressFlag == 1)
// 		{
// 			LCD_setCursor(0,u8_l_cellIndex++);
// 			LCD_sendChar(u8_l_enteredAscii);
// 			u8_l_tmepString[stringIndex++] = u8_l_enteredAscii;
// 			TIMER_delay_ms(100);
// 		}


//     u16 str[50];
//     u8 u8_l_miniTemp = 18;
//     u8 u8_l_maxTemp = 34;
//     u8 u8_l_customShapeCell = 0;
// 	LCD_setCursor(0,0);
//     sprintf(str, "%d", u8_l_miniTemp);
//     LCD_sendString(str);
//
//     LCD_setCursor(0,6);
//     LCD_sendString("Temp");
//
//     LCD_setCursor(0,14);
//     sprintf(str, "%d", u8_l_maxTemp);
//     LCD_sendString(str);
//     /* Each 3-col seperated by two empty col is mapped to be 1 temperature degree */
//     for(u8_l_customShapeCell; u8_l_customShapeCell < (u8_l_enteredTemp - u8_l_miniTemp); u8_l_customShapeCell++)
//     {
//         LCD_storeCustomCharacter(u8_g_pattern, LCD_CUSTOMCHAR_LOC0);
//     }

/*
	u8_l_tmepString[stringIndex] = 0;
	u8_l_enteredTemp = u8_l_tmepString[1] + ( u8_l_tmepString[0] * 10 );
	LCD_setCursor(1,0);
	LCD_sendString(u8_l_tmepString);
	u8 u8_l_enteredTemp = 0;
	u8 u8_l_enteredTempReminder = 0;
	u8 u8_l_enteredAscii;
	LCD_setCursor(0,0);
 */
