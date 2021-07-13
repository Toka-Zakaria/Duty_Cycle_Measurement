/**********************************************************************************
 * [FILE NAME]: application_functions.c
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Dec 12, 2020
 *
 * [Description]:  File of All functions used in the application.
 ***********************************************************************************/


#include"application_functions.h"

void EdgeDetection(void)
{
	g_edgeCount++;


	if(g_edgeCount == FIRST_EDGE)
	{

		TIMER1_INITIAL_VALUE_REGISTER=0;

		External_Interrupt_ConfigType edge= {INTERRUPT0,Falling};
		Interrupt_setCallBack(EdgeDetection, INTERRUPT0);
		External_Interrupt_init(&edge);

	}

	if(g_edgeCount == SECOND_EDGE)
	{
		g_timeHigh=  TIMER1_INITIAL_VALUE_REGISTER;

		External_Interrupt_ConfigType edge= {INTERRUPT0, Raising};
		Interrupt_setCallBack(EdgeDetection, INTERRUPT0);
		External_Interrupt_init(&edge);


	}

	if(g_edgeCount == THIRD_EDGE)
	{
		g_timePeriod = TIMER1_INITIAL_VALUE_REGISTER;

		External_Interrupt_ConfigType edge= {INTERRUPT0, Falling};
		Interrupt_setCallBack(EdgeDetection, INTERRUPT0);
		External_Interrupt_init(&edge);

	}


	if(g_edgeCount == FOURTH_EDGE)
	{
		g_timePeriodPlusHigh = TIMER1_INITIAL_VALUE_REGISTER;

		TIMER1_INITIAL_VALUE_REGISTER=0;

		External_Interrupt_ConfigType edge= {INTERRUPT0, Falling};
		Interrupt_setCallBack(EdgeDetection, INTERRUPT0);
		External_Interrupt_init(&edge);

	}


}



