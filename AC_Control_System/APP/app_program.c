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
extern u8 u8_g_timeOut;
extern u8 u8_g_pressFlag;
extern u8_g_keypadPressFlag;
u16 u16_g_temperatureValue = 0;
/* The pattern */

u8 u8_g_pattern[] = {0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};

/*******************************************************************************************************************************************************************/ 
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
    LCD_sendString("Welcome");
    LCD_setCursor(1,0);
    LCD_sendString("Hacker Kermit");
    TIMER_delay_ms(1000);
	LCD_clear();
	
	LCD_setCursor(0,0);
    LCD_sendString("AC Control");
    LCD_setCursor(1,0);
    LCD_sendString("default temp=20 ");
    TIMER_delay_ms(1000);
	LCD_clear();

   /******************************************************************/
}



void APP_startProgram  ( void )
{
	APP_adjustTemp();
	u16 str[50];
    u8 u8_l_modeSelect = ADJUST;
    while (1)
    {
		LCD_setCursor(0,0);
		TEMPSENSOR_getValue(&u16_g_temperatureValue);
		sprintf(str, "%d", u16_g_temperatureValue);
		LCD_sendString(str);
		
        KPD_getPressedKey(&u8_l_modeSelect);
        switch(u8_l_modeSelect)
        {
            case ADJUST:
				 APP_adjustTemp();
                break;
            case RESET_TO_DEFAULT:
				 	
                break;
        }
    }
}


void APP_adjustTemp()
{
	LCD_clear();
	LCD_setCursor(0,0);
	LCD_sendString("1 incre, 2 decre"); 
	LCD_setCursor(1,0);
	LCD_sendString("3 set temperature");
	TIMER_delay_ms(2000);
	/*Storing the entered within 3 seconds*/
	TIMER_intDelay_ms(3000);    //wait a 3 seconds and scan the keypad
	u8 u8_l_pressedkey = 0;
	KPD_getPressedKey(&u8_l_pressedkey);
	switch(u8_l_pressedkey)
	{ 
		case INCREMENT:
			APP_incrementTemperatureValue(&u16_g_temperatureValue);
		break;
		case DECREMENT:
			APP_decrementTemperatureValue(&u16_g_temperatureValue);
		break;
		case SET:
			APP_setTemperatureValue(&u16_g_temperatureValue);
		break;
	}

    
    KPD_disableKPD();

    u8 u8_l_customShapeCell = 0;
    u8 u8_l_miniTemp = 18;
    LCD_setCursor(1,0);
    LCD_storeCustomCharacter(
    u8_g_pattern,
    LCD_CUSTOMCHAR_LOC0
    );
    LCD_setCursor(1,0);
    for(u8_l_customShapeCell; u8_l_customShapeCell < (u8_l_enteredTemp - u8_l_miniTemp); u8_l_customShapeCell++)
    {
	    LCD_sendChar(LCD_CUSTOMCHAR_LOC0);
    }
    if(u8_l_enteredTemp == 0)
		u8_l_enteredTemp = DEFAULT_TEMP;
    LCD_clear();	
}

void APP_incrementTemperatureValue(&u16_g_temperatureValue)
{	
	u8 u8_l_pressedkey = 0;
	u8 u8_l_customShapeCell = 0;
	u16 str[50];
	LCD_setCursor(0,0);
	LCD_sendString("Min=18    Max=34");
	/*Storing the entered within 3 seconds*/
	TIMER_intDelay_ms(3000);    //wait a 3 seconds and scan the keypad
	while( u8_g_timeOut == 0 )
	{
		KPD_getPressedKey(&u8_l_pressedkey);
		if(INCREMENT == u8_l_pressedkey )
		{
			*u16_g_temperatureValue++;
		}
	}
	sprintf(str, "%d", u16_g_temperatureValue);
	LCD_setCursor(0,8);
	LCD_sendString(str);
	LCD_setCursor(1,0);
    for(u8_l_customShapeCell; u8_l_customShapeCell < (u16_g_temperatureValue - MINIMUM_TEMP); u8_l_customShapeCell++)
    {
	    LCD_sendChar(LCD_CUSTOMCHAR_LOC0);
    }

}

void APP_decrementTemperatureValue(&u16_g_temperatureValue)
{
	u8 u8_l_pressedkey = 0;
	u8 u8_l_customShapeCell = 0;
	u16 str[50];
	LCD_setCursor(0,0);
	LCD_sendString("Min=18    Max=34");
	/*Storing the entered within 3 seconds*/
	TIMER_intDelay_ms(3000);    //wait a 3 seconds and scan the keypad
	while( u8_g_timeOut == 0 )
	{
		KPD_getPressedKey(&u8_l_pressedkey);
		if(INCREMENT == u8_l_pressedkey )
		{
			*u16_g_temperatureValue--;
		}
	}
	sprintf(str, "%d", u16_g_temperatureValue);
	LCD_setCursor(0,8);
	LCD_sendString(str);
	LCD_setCursor(1,0);
	for(u8_l_customShapeCell; u8_l_customShapeCell < (u16_g_temperatureValue - MINIMUM_TEMP); u8_l_customShapeCell++)
	{
		LCD_sendChar(LCD_CUSTOMCHAR_LOC0);
	}
}

void APP_setTemperatureValue(&u16_g_temperatureValue)
{
	
}
void APP_resetTemperatureValue(&u16_g_temperatureValue)
{
	
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

	u8_l_tmepString[stringIndex] = 0;
	u8_l_enteredTemp = u8_l_tmepString[1] + ( u8_l_tmepString[0] * 10 );
	LCD_setCursor(1,0);
	LCD_sendString(u8_l_tmepString);
	u8 u8_l_enteredTemp = 0;
	u8 u8_l_enteredTempReminder = 0;
	u8 u8_l_enteredAscii;
	LCD_setCursor(0,0);