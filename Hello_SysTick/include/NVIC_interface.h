/*********************************************************************************/
/* Author    : Basma Ashraf                                                       */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                     */
/*********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber); 
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8getActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(u8 Copy_PeripheralIdx , u8 Copy_u8Priority);
void MNVIC_voidInt(void);
#endif
