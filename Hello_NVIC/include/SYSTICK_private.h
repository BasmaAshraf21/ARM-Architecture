/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 08 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


/* Systick Register */

#define STK_CTRL		 *((u32*)0xE000E010)
#define STK_LOAD		 *((u32*)0xE000E014)
#define STK_VAL			 *((u32*)0xE000E018)



#endif
