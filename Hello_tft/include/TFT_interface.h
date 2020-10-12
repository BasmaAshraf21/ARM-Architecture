/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 21 sep 2020                          */
/* Version : V01                                 */
/*************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInitialize(void);
void HTFT_voidDisplayImage(const u16* Copy_Image);
void HTFT_voidFillColor(u16 Copy_Color);
void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16 Copy_Color);
#endif
