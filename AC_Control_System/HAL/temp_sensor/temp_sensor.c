/*
 * TIMER_Program.c
 *
 *     Created on: Apr 19, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *    Description: This file contains all temperature sensor functions' implementation.
 *		MCU Datasheet: AVR ATmega32
 *                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */
#include "temp_sensor.h"

/*define global variable*/
u16 u16_g_adcGetValue = 0;
EN_tempSensorEror_T TEMPSENSOR_init(void)
{
	u8 u8_l_errorState = DIO_init( TEMPSENSOR_CHANNEL, TEMPSENSOR_PORT, DIO_IN);
	if ( u8_l_errorState == TEMPSENSOR_OK )
	{
		return STD_OK;
	}
	else
	{
		return STD_NOK;
	}
}
EN_tempSensorEror_T TEMPSENSOR_updateValue(void)
{
	u8 u8_l_errorState = ADC_startConversion(TEMPSENSOR_CHANNEL);
	if ( u8_l_errorState == TEMPSENSOR_OK )
	{
		return STD_OK;
	}
	else 
	{
		return STD_NOK;
	}
}

EN_tempSensorEror_T TEMPSENSOR_getValue(u16 u16_a_adcValue)
{
	u8 u8_l_errorState = ADC_getDigitalValue( ADC_U8_CC_INT_MODE, &u16_a_adcValue );
	if ( u8_l_errorState == TEMPSENSOR_OK )
	{
		u16_g_adcGetValue = u16_a_adcValue;
		return STD_OK;
	}
	else
	{
		return STD_NOK;
	}	
}