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
#include "SYSTICK_interface.h"

void Led_Animation(void);
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
	MGPIO_voidSetPinDirection(GPIOA,3,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,4,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,5,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,6,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,7,0b0010);

	SysTick_voidLoad(0);
	SysTick_voidLoad(100000);
	SysTick_voidInit();

	/* INVIC Initialize */
//	MNVIC_voidInt();

//	MNVIC_voidSetPriority(6, 0b01000000); /* EXTI0 Group 1 Sub 0 */
//	MNVIC_voidSetPriority(7, 0b00110000); /* EXTI0 Group 0 Sub 3 */


	/* Enable EXTI0 Interrupt From NVIC */
//	MNVIC_voidEnableInterrupt(6); /* EXTI0 */
//	MNVIC_voidEnableInterrupt(7); /* EXTI1 */
//	MNVIC_voidSetPendingFlag(6);

	while(1)
	{
	}
}

typedef enum {
	LED_LEFT  ,
	LED_RIGHT ,
	LED_IN    ,
	LED_OUT   ,
	LED_BLINK_ON ,
	LED_BLINK_OFF
}led_state;

/* Global variables */
led_state Global_state = LED_LEFT ;

u8 Global_Timer = 0;
u8 PIN_NUMBER = 0;
u8 counter = 0;
u8 IN  = 0;
u8 OUT = 7;
void SysTick_Handler(void)
{
	Global_Timer++;
	Led_Animation();
}

void Led_Animation(void)
{
	switch(Global_state)
	{
	case LED_LEFT:
		if (Global_Timer == 2)
		{
			MGPIO_voidSetPinValue(GPIOA,PIN_NUMBER,HIGH);
			MGPIO_voidSetPinValue(GPIOA,(PIN_NUMBER-1),LOW);
			PIN_NUMBER++;
			Global_Timer = 0;
			if (PIN_NUMBER > 7){Global_state = LED_RIGHT; PIN_NUMBER = 7;}
		}
		break;

	case LED_RIGHT:
		if (Global_Timer == 2)
		{
			MGPIO_voidSetPinValue(GPIOA,PIN_NUMBER,HIGH);
			MGPIO_voidSetPinValue(GPIOA,(PIN_NUMBER+1),LOW);
			PIN_NUMBER--;
			Global_Timer = 0;
			if(PIN_NUMBER == 0){Global_state = LED_LEFT; counter++; }
			if(counter == 4){Global_state = LED_IN; counter = 0; PIN_NUMBER = 0; }
		}
		break;

	case LED_IN:
		if(Global_Timer == 2)
		{
			MGPIO_voidSetPinValue(GPIOA,IN,HIGH);
			MGPIO_voidSetPinValue(GPIOA,OUT,HIGH);
			MGPIO_voidSetPinValue(GPIOA,(IN  - 1),LOW);
			MGPIO_voidSetPinValue(GPIOA,(OUT + 1),LOW);
			IN++;
			OUT--;
			Global_Timer = 0;
			if(IN == 4){Global_state = LED_OUT; }
		}
		break;

	case LED_OUT:
		if(Global_Timer == 2)
		{
			MGPIO_voidSetPinValue(GPIOA,(IN  - 1),HIGH);
			MGPIO_voidSetPinValue(GPIOA,(OUT + 1),HIGH);
			MGPIO_voidSetPinValue(GPIOA,(IN  + 1),LOW);
			MGPIO_voidSetPinValue(GPIOA,(OUT - 1),LOW);
			IN--;
			OUT++;
			Global_Timer = 0;
			if(OUT == 8){Global_state = LED_IN; counter++; IN = 0; OUT = 7;}
			if(counter == 4){Global_state = LED_BLINK_ON; counter = 0;}
		}
		break;

	case LED_BLINK_ON:
		if(Global_Timer == 5)
		{

			MGPIO_voidSetPinValue(GPIOA,0,HIGH);
			MGPIO_voidSetPinValue(GPIOA,1,HIGH);
			MGPIO_voidSetPinValue(GPIOA,2,HIGH);
			MGPIO_voidSetPinValue(GPIOA,3,HIGH);
			MGPIO_voidSetPinValue(GPIOA,4,HIGH);
			MGPIO_voidSetPinValue(GPIOA,5,HIGH);
			MGPIO_voidSetPinValue(GPIOA,6,HIGH);
			MGPIO_voidSetPinValue(GPIOA,7,HIGH);

			Global_state = LED_BLINK_OFF;
		}
		break;
	case LED_BLINK_OFF:
		if(Global_Timer == 10)
		{
			MGPIO_voidSetPinValue(GPIOA,0,LOW);
			MGPIO_voidSetPinValue(GPIOA,1,LOW);
			MGPIO_voidSetPinValue(GPIOA,2,LOW);
			MGPIO_voidSetPinValue(GPIOA,3,LOW);
			MGPIO_voidSetPinValue(GPIOA,4,LOW);
			MGPIO_voidSetPinValue(GPIOA,5,LOW);
			MGPIO_voidSetPinValue(GPIOA,6,LOW);
			MGPIO_voidSetPinValue(GPIOA,7,LOW);
			counter++;
			if(counter > 8){Global_state = LED_LEFT; counter = 0; Global_Timer = 0;}
			else{Global_state = LED_BLINK_ON; Global_Timer = 0;}
		}
		break;
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

