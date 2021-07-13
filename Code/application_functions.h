/**********************************************************************************
 * [FILE NAME]: application_functions.h
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Dec 12, 2020
 *
 * [Description]:  File of All types Declaration and Functions prototypes of
 *                 application functions configuration.
 ***********************************************************************************/

#ifndef APPLICATION_FUNCTIONS_H_
#define APPLICATION_FUNCTIONS_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#include"timer.h"
#include"external_interrupts.h"
#include "lcd.h"


#define FIRST_EDGE        1
#define SECOND_EDGE       2
#define THIRD_EDGE        3
#define FOURTH_EDGE       4



extern uint8 g_edgeCount ;
extern uint16 g_timeHigh ;
extern uint16 g_timePeriod;
extern uint16 g_timePeriodPlusHigh;

void EdgeDetection(void);

void timer_func(void);


#endif /* APPLICATION_FUNCTIONS_H_ */
