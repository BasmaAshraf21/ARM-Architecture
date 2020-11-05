/*****************************************************************************************/
/* Author : Basma Ashraf                                                                 */
/* Date   : 01 11 2020                                                                   */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include  "USART_config.h"
#include "USART_private.h"

#include<math.h>

void USART1_voidInit(void)
{
	/* put boud rate in BRR register */
	f32 USARTDIV;
	u16 mantissa;
	u8 fraction;
	
	USARTDIV = (f32)F_CLK/(16*USART1_BOUD_RATE);
	mantissa = (u16)USARTDIV;
	fraction = round((USARTDIV - mantissa) * 16) ;
	if(fraction > 15)
	{
		USART1->BRR |= ((mantissa + 1) << 4);
		USART1->BRR |= 0b0000;
	}
	else
	{
		USART1->BRR |= (mantissa << 4);
		USART1->BRR |= fraction;
	}

	USART1->CR1 |= USART1_WORD_LENGTH << 12;
	USART1->CR1 |= USART1_PARITY_ENABLE <<10;
	USART1->CR1 |= USART1_PARITY_SELECTION << 9;
	USART1->CR1 |= USART1_PARITY_INTERRUPT_ENABLE << 8;
	USART1->CR1 |= USART1_TX_INTERRUPT_ENABLE << 7;
	USART1->CR1 |= USART1_TRANSMISSION_COMPLETE_INTERRUPT_ENABLE << 6;
	USART1->CR1 |= USART1_RX_INTERRUPT_ENABLE << 5;
	USART1->CR1 |= 1<<3; /* enable transmitter */
	USART1->CR1 |= 1<<2; /* enable receiver */
	USART1->CR2 |= USART1_STOP_BIT << 12 ;
	USART1->CR1 |= 1<<13; /* enable USART1 */
}

void USART1_voidSendByte(u8 copy_u8Data)
{
	USART1->DR = copy_u8Data;
	while(!(GET_BIT(USART1->SR,6)));

}

void USART1_voidSendString(u8 const*arr)
{
	u8 i=0;
	while(arr[i]!='\0')
	{
		USART1_voidSendByte(arr[i]);
		i++;
	}
}

u8 USART1_u8ReceiveByte(u32 Copy_u32timeout)
{
	u8 Local_u8ReceivedData = 0;
	u32 count = 0;
	while(!(GET_BIT(USART1->SR,5)))
	{
		count++;
		if(count == Copy_u32timeout)
		{
			Local_u8ReceivedData = 255;
			break;
		}
	}
	
	if(Local_u8ReceivedData == 0)
	{
		Local_u8ReceivedData = USART1->DR;
	}
	
	return Local_u8ReceivedData;
}

void USART1_voidReceiveString(u8 *arr)
{
	u8 i = 0;
	arr[i]=USART1_u8ReceiveByte(1000);
	while(arr[i] != '#')
	{
		i++;
		arr[i] = USART1_u8ReceiveByte(1000) ;

	}
	arr[i] = '\0' ;
}
