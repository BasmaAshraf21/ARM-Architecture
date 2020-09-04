/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 08 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/* Options : RCC_HSE_CRYSRAL
			 RCC_HSE_RC
			 RCC_HSI
			 RCC_PLL    */
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSRAL

/* PLL Options :
	RCC_PLL_IN_HSI_DIV_2
	RCC_PLL_IN_HSE_DIV_2
	RCC_PLL_IN_HSE      */
/* Note : Select Value Only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT   RCC_PLL_IN_HSE_DIV_2
#endif


/* OPtions: 2 to 16 */
/* Note: Select Value Only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL   4
#endif

#endif
