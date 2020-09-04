/*************************************************/
/* Author  : Basma Ashraf                        */
/* Date    : 31 August 2020                         */
/* Version : V01                                 */
/*************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


u8 cols[16] ={LEDMRX_COL0_PIN, LEDMRX_COL1_PIN, LEDMRX_COL2_PIN, LEDMRX_COL3_PIN, LEDMRX_COL4_PIN, LEDMRX_COL5_PIN, LEDMRX_COL6_PIN, LEDMRX_COL7_PIN};
void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);


	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);
}


void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1){
	/* colum 0 */
	/* Disable All Colmuns*/
	DisableAllCols();
	/* Enable Column 0 */
	SetRowValue(Copy_u8Data[0]);
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec

	/* colum 1 */
	DisableAllCols();
	SetRowValue(Copy_u8Data[1]);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec

	/* colum 2 */
	DisableAllCols();
	SetRowValue(Copy_u8Data[2]);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec

	/* colum 3 */
	DisableAllCols();
	SetRowValue(Copy_u8Data[3]);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec

	/* colum 4 */
	DisableAllCols();
	SetRowValue(Copy_u8Data[4]);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec

	/* colum 5 */
	DisableAllCols();
	SetRowValue(Copy_u8Data[5]);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec

	/* colum 6 */
	DisableAllCols();
	SetRowValue(Copy_u8Data[6]);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec

	/* colum 7 */
	DisableAllCols();
	SetRowValue(Copy_u8Data[7]);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec
	}

}
void HLEDMRX_Animation(u8 *Copy_u8Data)
{

	while(1)
	{
		for(u8 i = 0; i < 26; i++)
		{
			u8 x = 0;
			u8 Local_Data[8] ={Copy_u8Data[i],Copy_u8Data[i+1],Copy_u8Data[i+2],Copy_u8Data[i+3],Copy_u8Data[i+4],Copy_u8Data[i+5],Copy_u8Data[i+6],Copy_u8Data[i+7]};
			while (x < 50)
			{
				x++;
				for(u8 k = 0; k < 8; k++)
				{
					DisableAllCols();
					SetRowValue(Local_Data[k]);
					MGPIO_voidSetPinValue(cols[k*2],cols[k*2 + 1],LOW);
					MSTK_voidSetBusyWait(2500); //2.5 msec
				}
			}
		}
	}
}

static void DisableAllCols(void)
{
	/* Disable All Colmuns*/
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,HIGH);
}

static void SetRowValue(u8 Copy_u8Value)
{
	u8 Local_u8BIT;

	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Local_u8BIT);

}


