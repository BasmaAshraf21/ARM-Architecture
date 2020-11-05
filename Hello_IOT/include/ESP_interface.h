/*****************************************************************************************/
/* Author : Basma Ashraf                                                                 */
/* Date   : 01 11 2020                                                                   */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef ESP_interface_H
#define ESP_interface_H

void ESP_voidInit(void);
void ESP_voidConnectToWIFI(u8 *copy_u8Name ,u8 *copy_u8Password);
u8 ESP_voidConnectToServer(u8 *copy_u8IP);

#endif
