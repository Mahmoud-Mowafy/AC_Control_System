/*
 * File   : buzzer.h
 *
 * Author: Tarek Gohry
 * 
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "../../MCAL/dio/dio_interface.h"


/* Macros */
#define BUZ_PORT PORT_B
#define BUZ_PIN 3

/* Prototypes */

/**
 * @brief Initializes the BUZZER module.
 *
 * @return void
 */
void BUZZER_init();
void BUZZER_on(u8 u8_a_buzPort, u8 u8_a_buzPin);
void BUZZER_off(u8 u8_a_buzPort, u8 u8_a_buzPin);

#endif /* BUZZER_H_ */