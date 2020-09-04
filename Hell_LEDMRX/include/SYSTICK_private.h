/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 08 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


/* Systick Register */

#define MSTK_CTRL		 *((u32*)0xE000E010)
#define MSTK_LOAD		 *((u32*)0xE000E014)
#define MSTK_VAL			 *((u32*)0xE000E018)


#define     MSTK_SRC_AHB           0
#define     MSTK_SRC_AHB_8         1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1

#endif
