/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 21 sep 2020                         */
/* Version : V01                                 */
/*************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void HTFT_voidInitialize(void)
{
	/* Reset pulse */
	MGPIO_voidSetPinValue(TFT_RSt_PIN, HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RSt_PIN, LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RSt_PIN, HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RSt_PIN, LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RSt_PIN, HIGH);
	MSTK_voidSetBusyWait(120000);
	
	/* Sleep Out Command */
	voidWriteCommand(0x11);
	
	/* wait 150 msec */
	MSTK_voidSetBusyWait(150000);
	
	/* Color Mode */
	voidWriteCommand(0x3A);
	voidWriteData(0x05);
	
	/* Diplay On */
	voidWriteCommand(0x29);
}
void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	u16 counter;
	/* Set x Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/* Set y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(counter=0; counter < 20480; counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_Image[counter]>>8);
		/* write the low byte */
		voidWriteData(Copy_Image[counter] & 0x00ff);
	}
}

void HTFT_voidFillColor(u16 Copy_Color)
{
	u16 counter;
	/* Set x Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/* Set y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(counter=0; counter < 20480; counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_Color>>8);
		/* write the low byte */
		voidWriteData(Copy_Color & 0x00ff);
	}
}

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16 Copy_Color)
{
	u16 counter;

	u16 size = (x2 - x1) * (y2 - y1);

	/* Set x Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);

	/* Set y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(counter=0; counter < 20480; counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_Color>>8);
		/* write the low byte */
		voidWriteData(Copy_Color & 0x00ff);
	}
}

static voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	/* set A0 PIN to Low */
	MGPIO_voidSetPinValue(TFT_A0_PIN,LOW);
	MSPI1_voidSendReceiveSynch(Copy_u8Command,&Local_u8Temp);
}

static voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	/* set A0 High */
	MGPIO_voidSetPinValue(TFT_A0_PIN,HIGH);
	MSPI1_voidSendReceiveSynch(Copy_u8Data,&Local_u8Temp);
}
