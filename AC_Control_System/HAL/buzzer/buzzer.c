/*
 * File   : buzzer.h
 *
 * Author: Tarek Gohry
 * 
 */ 

#include "buzzer.h"

void BUZZER_init()
{
	DIO_init(BUZ_PIN, BUZ_PORT, DIO_OUT);
}

void BUZZER_on()
{
	DIO_write(BUZ_PIN, BUZ_PORT, DIO_U8_PIN_HIGH);
}

void BUZZER_off()
{
	DIO_write(BUZ_PIN, BUZ_PORT, DIO_U8_PIN_LOW);
}
