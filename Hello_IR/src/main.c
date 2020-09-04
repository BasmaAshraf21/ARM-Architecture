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


void StopLedAnimation(void);
volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

void LEDMXE_ANIMATION(void);
void Led_Animation(void);
void LEDMXE_Player(void);


void voidPlay(void)
{

	switch (u8Data)
	{
		case 70 : LEDMXE_Player(); break;
		case 69 :  break;

	}
}

void voidTakeAction()
{
	u8 i;
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		voidPlay();

	}

	else
	{
		/* Invalid Frame */
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{

	if (u8StartFlag == 0)
		{
			/* Start Timer */
			MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
			u8StartFlag = 1;
		}

		else
		{
			u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
			MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
			u8EdgeCounter++;
		}

}



void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* GPIOA Enable Clock */
	RCC_voidEnableClock(RCC_APB2 , 3);
	/* IO Pins Initialization */

	MGPIO_voidSetPinDirection(GPIOA,0,0b0100); /* A0 Input Floating        */
	//MGPIO_voidSetPinDirection(GPIOA,1,0b0010); /* A1 Output PP "RED"       */
	//MGPIO_voidSetPinDirection(GPIOA,2,0b0010); /* A1 Output PP "GREEN"     */
	//MGPIO_voidSetPinDirection(GPIOA,3,0b0010); /* A1 Output PP "BLUE"      */
	//MGPIO_voidSetPinDirection(GPIOA,4,0b0010); 
	//MGPIO_voidSetPinDirection(GPIOA,5,0b0010); 
	//MGPIO_voidSetPinDirection(GPIOA,6,0b0010); 
	//MGPIO_voidSetPinDirection(GPIOA,7,0b0010); 
	//MGPIO_voidSetPinDirection(GPIOA,8,0b0010); 



	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */
	u8 data[16] = {16, 11, 255, 75, 208, 0, 64, 0};
	HLEDMRX_voidInit();
	HLEDMRX_voidDisplay(data);
	while(1)
	{

	}

}
typedef enum {
	LED_LEFT  ,
	LED_RIGHT
}led_state;

/* Global variables */
led_state Global_state = LED_LEFT ;
u8 PIN_NUMBER = 1;
counter = 0;

void Led_Animation(void)
{
	switch(Global_state)
	{
		case LED_LEFT:
			MGPIO_voidSetPinValue(GPIOA,PIN_NUMBER,HIGH);
			if(PIN_NUMBER==1)
			{
				asm("NOP");
			}
			else
			{
				MGPIO_voidSetPinValue(GPIOA,(PIN_NUMBER-1),LOW);
			}
			PIN_NUMBER++;
			if (PIN_NUMBER > 8){Global_state = LED_RIGHT; PIN_NUMBER = 8;}
			break;

		case LED_RIGHT:
			MGPIO_voidSetPinValue(GPIOA,PIN_NUMBER,HIGH);
			MGPIO_voidSetPinValue(GPIOA,(PIN_NUMBER+1),LOW);
			PIN_NUMBER--;
			if(PIN_NUMBER == 0){Global_state = LED_LEFT; counter++; }
			if(counter == 4){asm("NOP"); }

			break;

	}

}

void StopLedAnimation(void)
{
		MGPIO_voidSetPinValue(GPIOA,PIN_NUMBER,LOW);
		PIN_NUMBER++;
}
void LEDMXE_ANIMATION(void)
{
	u8 data[34] = {0, 255, 145, 170, 68, 0, 254, 17, 17, 17, 254, 0, 131, 133, 137, 145, 161, 65, 0, 255, 1, 2, 4, 2, 1, 255, 0, 254, 17, 17, 17, 254, 0, 0};
	HLEDMRX_voidInit();
	HLEDMRX_Animation(data);
}

void LEDMXE_Player(void)
{
	u8 data[24] = {16, 11, 255, 75, 208, 0, 64, 0, 16, 11, 255, 75, 80, 64, 8, 0,16, 11, 255, 75, 208, 0, 64, 0};
	HLEDMRX_voidInit();
	HLEDMRX_Player(data);
}

