/*
 * NVIC.c
 *
 *  Created on: Jun 25, 2021
 *      Author: migue
 */


#include "NVIC.h"

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	S32_NVIC->ICPR[IRQn>>5U] = 1 << (IRQn & 0x1FU);
	S32_NVIC->ISER[IRQn>>5U] = 1 << (IRQn & 0x1FU);
}

void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{

}

void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	S32_NVIC->ICER[IRQn>>5U] = 1 << (IRQn & 0x1FU);
}

void NVIC_SetPriority(IRQn_Type IRQn, uint8_t Prio)
{

}
