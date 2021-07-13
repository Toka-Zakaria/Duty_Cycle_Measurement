/**********************************************************************************
 * [FILE NAME]: main.c
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Nov 5, 2020
 *
 * [Description]: Application to determine Duty Cycle of wave form
 *
 ***********************************************************************************/

#include"application_functions.h"



uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;



int main(void)
{
	uint32 dutyCycle = 0;
	SREG |= (1<<7);

	LCD_init();

	External_Interrupt_ConfigType edge= {INTERRUPT0, Raising};


	Timer_ConfigType timer= {0,0, Timer1, F_CPU_CLOCK, Overflow, 0};



	/*start the timer*/
	//Timer_setCallBack(timer_func, Timer1);
	Timer_init(&timer);

	/*start interrupt*/
	Interrupt_setCallBack(EdgeDetection, INTERRUPT0);
	External_Interrupt_init(&edge);





	while(1)
	{

		if(g_edgeCount == 4)
		{
			Timer_DeInit(Timer1);
			External_Interrupt_Deinit(INTERRUPT0);

			g_edgeCount = 0;
			LCD_displayString("Duty = ");
			/* calculate the dutyCycle */
			dutyCycle = ((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;
			/* display the dutyCycle on LCD screen */
			LCD_intgerToString(dutyCycle);
			//LCD_intgerToString(TCNT1);
			LCD_displayCharacter('%');
		}

	}/*end of Super loop*/


}/*end of main*/

