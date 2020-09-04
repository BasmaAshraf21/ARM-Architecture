/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 26 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


void SysTick_voidInit(void)
{
	STK_CTRL = 0x03;
}

u8 SysTick_u8ClrFlag(void)
{
	u8 value = GET_BIT(STK_CTRL,16);
	return value;
}

void SysTick_voidLoad(u32 ValueTimer )
{
	STK_LOAD = ValueTimer;
}

u32 SysTick_u32GetValue(void)
{
	u32 ValueNumber = STK_VAL;
	return ValueNumber;
}
