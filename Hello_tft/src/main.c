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
#include "SYSTICK_interface.h"

#include "TFT_interface.h"
#include "Image.h"

void main(void)
{
	/* RCC Init */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2 );
	RCC_voidEnableClock(RCC_APB2, 12);

	/* PIN Init */
	MGPIO_voidSetPinDirection(GPIOA,1,0b0010); /* A0    */
	MGPIO_voidSetPinDirection(GPIOA,2,0b0010); /* Reset */
	MGPIO_voidSetPinDirection(GPIOA,5,0b1001); /* CLK   */
	MGPIO_voidSetPinDirection(GPIOA,7,0b1001); /* MOSI  */

	/* Init STK */
	MSTK_voidInit();

	/* SPI Init */
	MSPI1_voidInit();

	/*TFT Init */
	HTFT_voidInitialize();

	/* Draw Image */
	//HTFT_voidDisplayImage(image);
	HTFT_voidFillColor(0xffff);
	HTFT_voidDrawRect(0, 10, 0, 30, 0x0000);
}
