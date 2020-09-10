#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMRX_interface.h"

#include "DIO_private.h"

#include "file.h"

void LEDMXE_Dancer(void);

volatile u16 i = 0;

void voidSetDAC(void)
{
	GPIOA_ODR = Amaren_raw[i];
	i++;
	if(i == 29536)
	{
		i = 0;
	}

}




void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , 2);
	RCC_voidEnableClock(RCC_APB2 , 3);



	MGPIO_voidSetPinDirection(GPIOA, 0, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 1, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 2, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 3, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 4, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 5, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 6, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 7, 0b0010);
	MGPIO_voidSetPinDirection(GPIOB, 14, 0b0100);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125, voidSetDAC);
	u8 data[32] = {0, 8, 19, 255, 19, 8, 0, 0,0, 16, 11, 255, 75, 132, 0, 0, 0, 8, 19, 255, 19, 8, 0, 0, 0, 132, 75, 255, 11, 16, 0, 0};
	HLEDMRX_voidInit();


	while(1)
	{

		HLEDMRX_Dancer(data);

	}
}

void LEDMXE_Dancer(void)
{
	while(1)
	{
		MSTK_voidInit();
		MSTK_voidSetIntervalPeriodic(125, voidSetDAC);

	}
}
