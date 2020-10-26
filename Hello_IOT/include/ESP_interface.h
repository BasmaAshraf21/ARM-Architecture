/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 29 sep 2020                          */
/* Version : V01                                 */
/*************************************************/
#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_voidInit(void);
void ESP_voidConnctToRouter (char *pu8WIFIName, char* pu8WIFIPass) ;
void ESP_voidConnectToServer(char* pu8Mode, char* pu8IP, char* pu8Port) ;
u8 ESP_u8ExecuteRequest     (char* pu8Request) ;


#endif
