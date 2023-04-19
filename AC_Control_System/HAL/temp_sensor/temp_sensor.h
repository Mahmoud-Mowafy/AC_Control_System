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

#define TEMPSENSOR_CHANNEL      0
#define TEMPSENSOR_PORT			PORT_A
/******************************************************************************************/
typedef enum {
	TEMPSENSOR_OK,
	TEMPSENSOR_ERROR
	}EN_tempSensorEror_T;
	
EN_tempSensorEror_T TEMPSENSOR_init(void);
EN_tempSensorEror_T TEMPSENSOR_updateValue(void);
EN_tempSensorEror_T TEMPSENSOR_getValue(u16 u16_a_adcValue);
#endif /* TEMP_SENSOR_H_ */