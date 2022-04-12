/*
 * NVIC.h
 *
 *  Created on: Jun 25, 2021
 *      Author: migue
 */

#ifndef NVIC_H_
#define NVIC_H_

#include "S32K144.h"

void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPriority(IRQn_Type IRQn, uint8_t Prio);



#endif /* NVIC_H_ */
