/*****************************************************************************************/
/* Author : Basma Ashraf                                                                 */
/* Date   : 01 11 2020                                                                   */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef USART1_PRIVATE_H
#define USART1_PRIVATE_H

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART1_register;
#define USART1	((USART1_register*)0x40013800)


#endif
