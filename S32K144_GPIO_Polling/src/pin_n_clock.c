/*
 * pin_n_clock.c
 *
 *  Created on: Jun 21, 2021
 *      Author: migue
 */

#include "pin_n_clock.h"

void Init_clocks(MyClocks_en Clock)
{
	PCC-> PCCn[Clock] = PCC_PCCn_CGC_MASK; /* Enable clock to PORT C*/
}
