/*****************************************************************************************/
/* Author : Basma Ashraf                                                                 */
/* Date   : 01 11 2020                                                                   */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef USART1_CONFIG_H
#define USART1_CONFIG_H

#define F_CLK				8000000
#define USART1_BOUD_RATE	115200

/* Options:
			0: 8 data bits
			1: 9 data bits   */
#define USART1_WORD_LENGTH					0

/* Options:
			0: Parity disabled
			1: Parity enabled   */
#define USART1_PARITY_ENABLE				0

/* Options:
			0: even
			1: odd       */
#define USART1_PARITY_SELECTION				0

/* Options:
			0: disabled
			1: enabled   */
#define USART1_PARITY_INTERRUPT_ENABLE		0

/* Options:
			0: disabled
			1: enabled   */
#define USART1_TX_INTERRUPT_ENABLE			0

/* Options:
			0: disabled
			1: enabled   */
#define USART1_TRANSMISSION_COMPLETE_INTERRUPT_ENABLE	0

/* Options:
			0: disabled
			1: enabled   */
#define USART1_RX_INTERRUPT_ENABLE			0

/* Options:
			0: 1 stop bit
			2: 2 stop bits   */
#define USART1_STOP_BIT			0
#endif
