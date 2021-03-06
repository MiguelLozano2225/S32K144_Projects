/*
 * pin_n_clock.h
 *
 *  Created on: Jun 21, 2021
 *      Author: migue
 */

#ifndef PIN_N_CLOCK_H_
#define PIN_N_CLOCK_H_

#include "S32K144.h"

typedef enum
{
	PORT_A = 73U,
	PORT_B,
	PORT_C,
	PORT_D
}MyClocks_en ;

typedef enum
{
	LedRedState,
	LedBlueState,
	LedGreenState
}StateMachine_en;

void Init_clocks(MyClocks_en Clock);
void Init_Pins(void);

void LedGreen(void);
void LedBlue(void);
void LedRed(void);

#endif /* PIN_N_CLOCK_H_ */
