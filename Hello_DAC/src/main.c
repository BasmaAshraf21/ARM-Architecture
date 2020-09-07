#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "DIO_private.h"

#include "file.h"

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


	MGPIO_voidSetPinDirection(GPIOA, 0, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 1, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 2, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 3, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 4, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 5, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 6, 0b0010);
	MGPIO_voidSetPinDirection(GPIOA, 7, 0b0010);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125, voidSetDAC);

	while(1)
	{

	}
}


