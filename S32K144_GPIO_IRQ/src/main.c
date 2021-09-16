/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "S32K144.h"
#include "pin_n_clock.h"
#include "My_led_n_sw.h"
#include "NVIC.h"

void WDOG_disable (void);


int main(void)
{
	Init_clocks(PORT_C);
	Init_clocks(PORT_D);

	PORTC->PCR[12] |= PORT_PCR_MUX(1)			/*Config PTC12 as GPIO*/
					| PORT_PCR_IRQC(0b1100);	/*Cofig PTC as interrupt*/

	INIT_LEDS;

	NVIC_EnableIRQ(PORTC_IRQn);

	for(;;)
	{
		LED_BLUE_OFF;
		LED_RED_OFF;
		LED_GREEN_OFF;
	}

	return 0;
}

void PORTC_IRQHandler (void)
{

	LED_BLUE_ON;
	PORTC->PCR[12] |= PORT_PCR_ISF_MASK;

}

void WDOG_disable (void)
{
  WDOG->CNT=0xD928C520;     /* Unlock watchdog 		*/
  WDOG->TOVAL=0x0000FFFF;   /* Maximum timeout value 	*/
  WDOG->CS = 0x00002100;    /* Disable watchdog 		*/
}
