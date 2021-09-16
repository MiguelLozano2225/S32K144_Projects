/*
 * My_led_n_sw.h
 *
 *  Created on: Jun 22, 2021
 *      Author: migue
 */

#ifndef MY_LED_N_SW_H_
#define MY_LED_N_SW_H_
#include "S32K144.h"

#define	INIT_LEDS			(PTD->PDDR |= (1<<0) | (1<<15) | (1<<16));\
							(PORTD->PCR[0] = PORT_PCR_MUX(1));\
							(PORTD->PCR[15] = PORT_PCR_MUX(1));\
							(PORTD->PCR[16] = PORT_PCR_MUX(1));\


#define INIT_SW				(PTC->PDDR &= ~(1<<12));\
							(PTC->PDDR &= ~(1<<13));\
							(PORTC->PCR[12] = PORT_PCR_MUX(1));\
							(PORTC->PCR[13] = PORT_PCR_MUX(1));\

#define LED_BLUE_ON			PTD->PDOR &= ~1
#define LED_BLUE_OFF		PTD->PDOR |=  1

#define LED_RED_ON			PTD->PDOR &= ~(1<<15)
#define LED_RED_OFF			PTD->PDOR |=  (1<<15)

#define LED_GREEN_ON		PTD->PDOR &= ~(1<<16)
#define LED_GREEN_OFF		PTD->PDOR |=  (1<<16)

#define SW2					(PTC->PDIR & (1<<12))

#define SW3					(PTC->PDIR & (1<<13))

#endif /* MY_LED_N_SW_H_ */
