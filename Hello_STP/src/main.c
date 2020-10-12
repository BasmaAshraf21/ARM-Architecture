/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"


void main(void)
{

	/* Clock Initialization */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA */

	/* Pins Directions */
	MGPIO_voidSetPinDirection(GPIOA, 0, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 1, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 2, 0b0010);

	/* Timer Init */
	MSTK_voidInit();

	/* STP */

	u8 i;
	while(1)
	{
		for(i=0; i<8; i++)
		{

		HSTP_voidSendSynchrouns(1<<i);
		MSTK_voidSetBusyWait(300000);

		}
	}
}
