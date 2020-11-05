/*
 * main.c
 *
 *  Created on: 01 / 11 / 2020
 *      Author: Basma Ashraf
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "ESP_interface.h"
#include "ESP_config.h"


void LED_ON   (void)   ;
void LED_OFF  (void)   ;


int main (void)
{
	RCC_voidInitSysClock();

	/* Enable Peripheral 2 on ABP2 Bus (GPIOA) */
		RCC_voidEnableClock(RCC_APB2, 2);
		RCC_voidEnableClock(RCC_APB2 , 14);
		MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_10MHZ_AFPP);
		MGPIO_voidSetPinDirection(GPIOA, PIN10, INPUT_FLOATING);
		MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);
		MSTK_voidInit();

	u8  Led_Status = 0;
	USART1_voidInit();

	while(1)
	{

		ESP_voidInit();
		/* Connect to Router, sending name and password as strings*/
		ESP_voidConnectToWIFI(ROUTER_SSID, ROUTER_PASSWORD);

		/*Connecting to server, sending data transmit mode UDP or TCP and IP of server and port number as strings*/
		/* We connect each time as my server is free one and disconnects automatically, if you got a server yourself you don't
		 * have to do so
		 */
		Led_Status = ESP_voidConnectToServer(IP);


		switch ( Led_Status )
		{
			case '0' : LED_OFF() ; break ;
			case '1' : LED_ON () ; break ;

		}


	}

	return 0 ;
}

void LED_ON (void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN0, HIGH);
}

/**-----------------------------------------------------------------------------------------------------------*/

void LED_OFF (void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN0, LOW);
}

/**-----------------------------------------------------------------------------------------------------------*/




