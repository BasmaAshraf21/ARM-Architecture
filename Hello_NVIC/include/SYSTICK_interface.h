/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 26 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H



void SysTick_voidInit(void);
u8 SysTick_u8ClrFlag(void);
void SysTick_voidLoad(u32 ValueTimer );
u32 SysTick_u32GetValue(void);

#endif
