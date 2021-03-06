/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "S32K144.h"
#include "My_led_n_sw.h"
#include "pin_n_clock.h"

void WDOG_disable (void);

int main(void)
{
	WDOG_disable();
	Init_clocks(PORT_C);
	Init_clocks(PORT_D);

	INIT_LEDS;
	StateMachine_en LedState_en = LedRedState;

	for(;;)
	{

		if(LedState_en == LedRedState)
		{
			LedRed();
			LedState_en = LedBlueState;
		}

		else if(LedState_en == LedBlueState)
		{
			LedBlue();
			LedState_en = LedGreenState;
		}

		else if(LedState_en == LedGreenState)
		{
			LedGreen();
			LedState_en = LedRedState;
		}

		else
		{
			LED_GREEN_OFF;
			LED_BLUE_OFF;
			LED_RED_OFF;
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
