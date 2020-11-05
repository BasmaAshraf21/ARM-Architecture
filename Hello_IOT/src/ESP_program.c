/*****************************************************************************************/
/* Author : Basma Ashraf                                                                 */
/* Date   : 01 11 2020                                                                   */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "SYSTICK_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void ESP_voidInit(void)
{
	u8 Local_u8ValidFlag = 0;

	while(Local_u8ValidFlag == 0)
	{
		/* disable ecco */
		USART1_voidSendString("ATE1\r\n");
		Local_u8ValidFlag = u8ValidateCmd(ECHO_TIMEOUT);
	}
	Local_u8ValidFlag = 0;

	while(Local_u8ValidFlag == 0)
	{
		/* select wifi mode */
		USART1_voidSendString("AT+CWMODE=1\r\n");
		Local_u8ValidFlag = u8ValidateCmd(MODE_TIMEOUT);
	}
}

void ESP_voidConnectToWIFI(u8 *copy_u8Name ,u8 *copy_u8Password)
{
	u8 Local_u8ValidFlag = 0;
	u8 i = 0;
	u8 j = 0;
	u8 command[100]={"AT+CWJAP_CUR="};

	command[13]='"';
	while(copy_u8Name[i] != '\0')
	{
		command[14+i]=copy_u8Name[i];
		i++;
	}
	command[14+i]='"';
	i++;
	command[14+i]=',';
	i++;
	command[14+i]='"';
	i++;

	while(copy_u8Password[j] != '\0')
	{
		command[14+i]=copy_u8Password[j];
		i++;
		j++;
	}
	command[14+i]='"';
	i++;
	command[14+i]='\r';
	i++;
	command[14+i]='\n';
	while(Local_u8ValidFlag == 0)
	{
		/*Connect to WiFi of name Copy_u8StrSsid and password Copy_u8StrPassword*/
		USART1_voidSendString(command);
		/*	Check command is done right
			AT+CWJAP_CUR="SSID","Pass" returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd(ROUTER_TIMEOUT);
	}

}

u8 ESP_voidConnectToServer(u8 *copy_u8IP)
{
	u8 Local_u8ValidFlag = 0;
	u8 Local_u8Temp_char = 0;
	u16 i=0;
	u8 Local_u8TempChar  = 0;
	u8 command[100] = {"AT+CIPSTART="};
	command[12]='"';
	command[13]='T';
	command[14]='C';
	command[15]='P';
	command[16]='"';
	command[17]=',';
	command[18]='"';
	while(copy_u8IP[i] != '\0')
	{
		command[19+i]=copy_u8IP[i];
		i++;
	}
	command[19+i]='"';
	i++;
	command[19+i]=',';
	i++;
	command[19+i]='8';
	i++;
	command[19+i]='0';
	i++;
	command[19+i]='\r';
	i++;
	command[19+i]='\n';

	while(Local_u8ValidFlag == 0)
	{
		USART1_voidSendString(command);
		Local_u8ValidFlag = u8ValidateCmd(SERVER_TIMEOUT);
	}
		Local_u8ValidFlag = 0;
	while(Local_u8ValidFlag == 0)
	{
		//USART1_voidSendString("AT+CIPSEND=39\r\n");
		USART1_voidSendString("AT+CIPSEND=46\r\n");
		Local_u8ValidFlag = u8ValidateCmd(PREREQUEST_TIMEOUT);
	}
	Local_u8ValidFlag = 0;
	while(Local_u8ValidFlag == 0)
	{
		//USART1_voidSendString("GET http://iot.freeoda.com/status.txt\r\n");
		USART1_voidSendString("GET http://embedded.freetzi.com/status.txt\r\n");
		Local_u8ValidFlag = u8ValidateCmd(REQUEST_TIMEOUT);
	}
	for(u8 i = 0; i < 98; i++)
	{
			/*Checking that the data recieved have IPD*/
		if(Local_u8Response[i] == 'I' && Local_u8Response[i+1] == 'P' && Local_u8Response[i+2] == 'D')
		{

			/*Return data in the 6th postion after the I*/
			Local_u8Temp_char = Local_u8Response[i+6];
		}
	}

	return Local_u8Temp_char ;
}

static u8 u8ValidateCmd(u32 Copy_u32timeout)
{
	u8 Local_u8ValidFlag = 0;
	u8 Local_u8Counter   = 0;
	u8 Local_u8TempChar  = 0;

	for(u8 i = 0; i < 100; i++)
	{
		Local_u8Response[i] = 0;
	}

	/*Make sure that the MC is not receiving any more data from the ESP*/
	while (Local_u8TempChar != 255)
	{
		Local_u8TempChar = USART1_u8ReceiveByte(Copy_u32timeout);
		Local_u8Response[Local_u8Counter] = Local_u8TempChar;
		Local_u8Counter++;
	}

	/*	Deleting last element as it is always 255 for stop receiving data	*/
	Local_u8Response[Local_u8Counter-1] = 0;

	/*Strcmp returns 0 if the two strings are iqentical*/
	//Local_u8ValidFlag = strcmp(Copy_u8StrCmd, Local_u8Response);

	/* Checks if any of the received data contains the word "OK" meaning the command is done successfully*/
	for(u8 i = 0; i < Local_u8Counter - 2; i ++)
	{
		if(Local_u8Response[i] == 'O' && Local_u8Response[i+1] == 'K')
		{
			Local_u8ValidFlag = 1;
		}
	}
	return Local_u8ValidFlag;
}
