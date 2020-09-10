/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 31 August 2020                         */
/* Version : V01                                 */
/*************************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);
void HLEDMRX_Dancer(u8 *Copy_u8Data);
void delayMs(u32 n);

#endif
