/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "S32K144.h"
#include "My_led_n_sw.h"
#include "pin_n_clock.h"

void WDOG_disable (void);

void delay (void)
{
	int a= 1000000;
	while(a--);
}

int main(void)
{
	WDOG_disable();
	Init_clocks(PORT_C);
	Init_clocks(PORT_D);

	INIT_LEDS;
	INIT_SW;

	for(;;)
	{
		if( SW3)
		{
			LED_BLUE_ON;
		}

		else if( SW2)
		{
			LED_RED_ON;
		}

		else
		{
			LED_BLUE_OFF;
			LED_RED_OFF;
			LED_GREEN_OFF;
		}
	}


    return 0;
}

void WDOG_disable (void)
{
  WDOG->CNT=0xD928C520;     /* Unlock watchdog 		*/
  WDOG->TOVAL=0x0000FFFF;   /* Maximum timeout value 	*/
  WDOG->CS = 0x00002100;    /* Disable watchdog 		*/
}
