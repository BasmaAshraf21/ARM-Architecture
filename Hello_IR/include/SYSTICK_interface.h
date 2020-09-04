/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 26 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


/* Apply Clock choice from configuration file 
   Disable SysTick interrupt 
   Disable Systick                          */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);


void SysTick_voidInit(void);
u8 SysTick_u8ClrFlag(void);
void SysTick_voidLoad(u32 ValueTimer );
u32 SysTick_u32GetValue(void);

#endif
