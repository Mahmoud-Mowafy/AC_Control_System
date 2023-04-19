/*
 * temp_sensor.h
 *
 * Created: 4/19/2023 2:11:17 AM
 *  Author: Mahmoud Mowafey
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

/*MCAL*/  
#include "../../MCAL/dio/dio_interface.h"
#include "../../MCAL/adc/adc_interface.h"
/*HAL*/
#include "../kpd/KPD_Interface.h"
/*LIB*/
#include "../../LIB/bit_math.h"
#include "../../LIB/std.h"
/******************************************************************************************/
typedef enum {
	TEMPSENSOR_OK,
	TEMPSENSOR_ERROR
	}EN_tempsensorEror_T;
	
EN_tempsensorEror_T TEMPSENSOR_init(void);
EN_tempsensorEror_T TEMPSENSOR_updateValue(void);
#endif /* TEMP_SENSOR_H_ */