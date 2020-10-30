/*********************************************************************************/
/* Author    : Basma Ashraf                                                       */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                     */
/*********************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* 0xE000E100 Base Address */

#define NVIC_ISER0     *((u32*)0xE000E100)  /* Enable External Interrupt From 0 to 31 */
#define NVIC_ISER1     *((u32*)0xE000E104)	/* Enable External Interrupt From 32 to  */


#define NVIC_ICER0     *((u32*)0xE000E180)
#define NVIC_ICER1     *((u32*)0xE000E184)

#define NVIC_ISPR0     *((u32*)0xE000E200)
#define NVIC_ISPR1     *((u32*)0xE000E204)


#define NVIC_ICPR0     *((u32*)0xE000E280)
#define NVIC_ICPR1     *((u32*)0xE000E284)

#define NVIC_IABR0	   *((volatile u32*)0xE000E300)
#define NVIC_IABR1	   *((volatile u32*)0xE000E304)

#define NVIC_IPR 		((u8*)0xE000E400)

#define MNVIC_GROUP_4_SUB_0     0x05FA300
#define MNVIC_GROUP_3_SUB_1	    0x05FA400
#define MNVIC_GROUP_2_SUB_2		0x05FA500
#define MNVIC_GROUP_1_SUB_3		0x05FA600
#define MNVIC_GROUP_0_SUB_4		0x05FA700



#endif
