/*
 * temp_sensor.c
 *
 * Created: 4/19/2023 2:10:59 AM
 *  Author: Mahmoud
 */ 
#include "temp_sensor.h"

EN_tempsensorEror_T TEMPSENSOR_init(void)
{
	
}
EN_tempsensorEror_T TEMPSENSOR_updateValue(void)
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