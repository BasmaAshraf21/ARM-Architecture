/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 26 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#include <SYSTICK_config.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"

/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
#if MSTK_CLK_SRC == MSTK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	MSTK_CTRL = 0x00000004;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	MSTK_CTRL = 0;
	MSTK_CTRL = 0x00;
#endif
}
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	MSTK_LOAD = Copy_u32Ticks;
	SET_BIT(MSTK_CTRL, 0);
	while((GET_BIT(MSTK_CTRL,16)) == 0) asm("NOP");
	CLR_BIT(MSTK_CTRL, 0);
	MSTK_LOAD = 0;
	MSTK_VAL  = 0;
}
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{

	MSTK_LOAD = Copy_u32Ticks;
	SET_BIT(MSTK_CTRL, 0);
	MSTK_CallBack = Copy_ptr ;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	SET_BIT(MSTK_CTRL, 1);

}

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{

	MSTK_LOAD = Copy_u32Ticks;
	SET_BIT(MSTK_CTRL, 0);
	MSTK_CallBack = Copy_ptr ;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	SET_BIT(MSTK_CTRL, 1);
}

void MSTK_voidStopInterval(void)
{
	CLR_BIT(MSTK_CTRL, 1);
	SET_BIT(MSTK_CTRL, 0);
	MSTK_LOAD = 0;
	MSTK_VAL  = 0;
}

u32  MSTK_u32GetElapsedTime(void)
{
	u32 ElapsedTime = MSTK_LOAD - MSTK_VAL;
	return ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Value_Val = MSTK_VAL;
	return Value_Val;
}

void SysTick_Handler(void)
{	u8 Local_u8Temporary;
if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK_CTRL, 1);

		/* Stop Timer */
		SET_BIT(MSTK_CTRL, 0);
		MSTK_LOAD = 0;
		MSTK_VAL  = 0;
	}
	MSTK_CallBack();
	Local_u8Temporary = GET_BIT(MSTK_CTRL,16);
}

/**************************************/
