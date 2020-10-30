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
#include "USART_interface.h"
#include "ESP_interface.h"
#include "ESP_config.h"
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMRX_interface.h"

void LED_ON   (void)   ;
void LED_OFF  (void)   ;


int main (void)
{
	RCC_voidInitSysClock();

	/* Enable Peripheral 2 on ABP2 Bus (GPIOA) */
		RCC_voidEnableClock(RCC_APB2, 2);
		RCC_voidEnableClock(RCC_APB2 , 3);

		MSTK_voidInit();

	u8  Led_Status = '1';

	while(1)
	{
		MUSART1_voidInit();
		ESP_voidInit();
		/* Connect to Router, sending name and password as strings*/
		ESP_voidConnctToRouter(ROUTER_SSID, ROUTER_PASSWORD);

		/*Connecting to server, sending data transmit mode UDP or TCP and IP of server and port number as strings*/
		/* We connect each time as my server is free one and disconnects automatically, if you got a server yourself you don't
		 * have to do so
		 */
		ESP_voidConnectToServer(MODE, IP, PORT);

		/* Send the request as string*/
		Led_Status = ESP_u8ExecuteRequest(REQUEST_LED_STATUS);
		//u8 * data = ESP_u8ExecuteRequest(REQUEST_LED_STATUS);
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
	u8 data[34]={0, 255, 145, 170, 68, 0, 254, 17, 17, 17, 254, 0, 131, 133, 137, 145, 161, 65, 0, 255, 1, 2, 4, 2, 1, 255, 0, 254, 17, 17, 17, 254, 0, 0};
	HLEDMRX_voidInit();
	HLEDMRX_Animation(data);
}

/**-----------------------------------------------------------------------------------------------------------*/

void LED_OFF (void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN0, LOW);
}

/**-----------------------------------------------------------------------------------------------------------*/




