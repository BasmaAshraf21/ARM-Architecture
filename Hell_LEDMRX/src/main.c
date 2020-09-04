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
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMRX_interface.h"



void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , 2);
	RCC_voidEnableClock(RCC_APB2 , 3);

	MSTK_voidInit();
	u8 data[34]={0, 255, 145, 170, 68, 0, 254, 17, 17, 17, 254, 0, 131, 133, 137, 145, 161, 65, 0, 255, 1, 2, 4, 2, 1, 255, 0, 254, 17, 17, 17, 254, 0, 0};
	HLEDMRX_voidInit();
	HLEDMRX_Animation(data);

}
