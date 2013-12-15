/*
 * main.h
 *
 *  Created on: 14 gru 2013
 *      Author: michal
 *      Projec: F3_GPIOLedShift
 */

#ifndef MAIN_H_
#define MAIN_H_


void Clock_Init(void);

#define L3 GPIO_Pin_9		//ledy na porcie E
#define L4 GPIO_Pin_8
#define L5 GPIO_Pin_10
#define L6 GPIO_Pin_15
#define L7 GPIO_Pin_11
#define L8 GPIO_Pin_14
#define L9 GPIO_Pin_12
#define L10 GPIO_Pin_13

#define DELAY	(1000)

#include "stm32f3_discovery.h"
#include "stm32f30x.h"
#include "stm32f30x_gpio.h"		//GPIO init
#include "stm32f30x_rcc.h"		//Zegar RCC
#include "common.h"

#include <stdint.h>

void Clock_Init(void);
void IO_Init(void);

#endif /* MAIN_H_ */
