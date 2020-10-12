#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMRX_interface.h"

#include "DIO_private.h"

#include "Hello.h"
#include "Help.h"
#include "Hungry.h"
#include "Waterr.h"


volatile u16 i = 0;
volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

void voidSetDAC_Hello(void);
void voidSetDAC_Help(void);
void voidSetDAC_Hungry(void);
void voidSetDAC_Water(void);

void voidPlay(void)
{

	switch (u8Data)
	{
		case 12 :voidSetDAC_Hello(); break;
		case 24 :voidSetDAC_Help();  break;
		case 70 :voidSetDAC_Help(); break;
		case 8  :voidSetDAC_Water();  break;

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
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , 2);
	RCC_voidEnableClock(RCC_APB2 , 3);



	MGPIO_voidSetPinDirection(GPIOA, 0, 0b0100); /* A0 Input Floating        */
	MGPIO_voidSetPinDirection(GPIOA, 1, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 2, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 3, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 4, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 5, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 6, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 7, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 8, 0b0010);


	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */


	MSTK_voidInit();

	while(1)
	{


	}
}

void voidSetDAC_Hello(void)
{
	i = 0;

	while(i <= 6385)
	{
		GPIOA_ODR = Hello_raw[i];
		i++;
		MSTK_voidSetBusyWait(125);
	}

}


void voidSetDAC_Help(void)
{
	i = 0;
	while(i <= 3319)
	{
		GPIOA_ODR = Help_raw[i];
		i++;
		MSTK_voidSetBusyWait(125);
	}

}


void voidSetDAC_Hungry(void)
{
	i = 0;

	while(i <= 5630)
	{
		GPIOA_ODR = Humgry_raw[i];
		i++;
	}

}

void voidSetDAC_Water(void)
{
	i = 0;
	while(i <= 24551)
	{
		GPIOA_ODR = Water_raw[i];
			i++;
		MSTK_voidSetBusyWait(125);
	}

}


