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

void main(void)
{
	/* Initialize Clock */
	RCC_voidInitSysClock();
	/* Enable Peripheral 2 on ABP2 Bus (GPIOA) */
	RCC_voidEnableClock(RCC_APB2, 2); /* Enable GPIOA Clock */


	/* Pins Mode */
	MGPIO_voidSetPinDirection(GPIOA,0,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,1,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,2,0b0010);

	/* INVIC Initialize */
	MNVIC_voidInt();

	MNVIC_voidSetPriority(6, 0b01000000); /* EXTI0 Group 1 Sub 0 */
	MNVIC_voidSetPriority(7, 0b00110000); /* EXTI0 Group 0 Sub 3 */


	/* Enable EXTI0 Interrupt From NVIC */
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */
	MNVIC_voidEnableInterrupt(7); /* EXTI1 */
	MNVIC_voidSetPendingFlag(6);

	while(1)
	{

	}


}
void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,0,HIGH);
	MNVIC_voidSetPendingFlag(7); /* Set Pending Flag EXTI1 */
	MGPIO_voidSetPinValue(GPIOA,1,HIGH);
}
void EXTI1_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,2,HIGH);
}

