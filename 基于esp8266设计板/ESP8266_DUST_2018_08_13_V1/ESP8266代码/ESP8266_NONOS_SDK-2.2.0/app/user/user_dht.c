/******************************************************************************
 * Copyright 2014 goouuu technology (WYB)
 *
 * FileName: user_dht.c
 *
 * Description: Read the temperature and humidity sensor(DHT11)
 			 Use the ReadDHT11 API to read DHT11 data
 *
 * Modification history:
 *     2014/11/29, v1.0 create this file.
*******************************************************************************/
#include "os_type.h"
#include "osapi.h"
#include "gpio.h"
#include "user_dht.h"

#define  DHT11_Pin_In	GPIO_INPUT_GET(GPIO_ID_PIN(14))
#define  DHT11_Pin_Low	GPIO_OUTPUT_SET(GPIO_ID_PIN(14),0)
#define  DHT11_Pin_Hig	GPIO_OUTPUT_SET(GPIO_ID_PIN(14),1)

#define  Ture   0x01
#define  False  0x00;

/******************************************************
 * FunctionName : DHT11_Delay_us
 * Description  : Redefine the delay_us
 * Parameters   : t --> t us
 * Returns      : none
*******************************************************/
void DHT11_Delay_us(uint16 t)
{
  os_delay_us(t);
}

/******************************************************
 * FunctionName : DHT11_Delay_ms
 * Description  : Redefine the delay_ms
 * Parameters   : t --> t ms
 * Returns      : none
*******************************************************/
void DHT11_Delay_ms(uint16 t)
{
  for(;t>0;t--)
  	os_delay_us(1000);
}

/*2*****************************************************
 * FunctionName : DHT11_PortIN
 * Description  : Set the DHT11 Pin Input Mode
 * Parameters   : none
 * Returns      : none
*******************************************************/
void ICACHE_FLASH_ATTR
DHT11_PortIN(void)
{
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U,FUNC_GPIO14);
	GPIO_DIS_OUTPUT(GPIO_ID_PIN(14));
}

/******************************************************
 * FunctionName : DHT11_PortOUT
 * Description  : Set the DHT11 Pin Output Mode
 * Parameters   : none
 * Returns      : none
*******************************************************/
void ICACHE_FLASH_ATTR
DHT11_PortOUT(void)
{
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U,FUNC_GPIO14);
	GPIO_OUTPUT_SET(GPIO_ID_PIN(14),1);
}

/******************************************************
 * FunctionName : StartDHT11
 * Description  : Start to read DHT11
 * Parameters   : none
 * Returns      : Start success return true
*******************************************************/

uint8 ICACHE_FLASH_ATTR
StartDHT11(void)
{
   uint8 result = 0;
   DHT11_PortOUT();
   DHT11_Pin_Low;
   DHT11_Delay_ms(20);
   DHT11_Pin_Hig;
   DHT11_Delay_us(45);
   DHT11_PortIN();
   DHT11_Delay_us(5);
   while(DHT11_Pin_In==0)
   {
	 result++;
	 DHT11_Delay_us(10);
   }
   while(DHT11_Pin_In&&result);
   if(result>3)
	 return Ture;
   else
     return False;
}

/******************************************************
 * FunctionName : DHT11_ReadByte
 * Description  : Read DHT11 one Byte
 * Parameters   : none
 * Returns      : ReadByte
*******************************************************/
uint8 ICACHE_FLASH_ATTR
DHT11_ReadByte(void)
{
	uint8 reader;
	uint8 bitsum;
	reader = 0;	
	DHT11_PortIN();
	for(bitsum=0;bitsum<8;bitsum++)
	{
	  reader = reader << 1;
	  while(DHT11_Pin_In==0);
	  DHT11_Delay_us(50);
	  if(DHT11_Pin_In)
	     reader |= 0x01;
	  while(DHT11_Pin_In);
	}	
	return reader;
}

/******************************************************
 * FunctionName : ReadDHT11
 * Description  : Read DHT11 one Byte
 * Parameters   : result array(len == 4)
 * Returns      : Read DHT11 data Success then return 1
*******************************************************/
uint8 ICACHE_FLASH_ATTR
ReadDHT11(uint8 *dht)
{
	uint8 sum; 
    uint8 checksum=0;
	if(StartDHT11())
	{		
		dht[0]   = DHT11_ReadByte();
		dht[1]   = DHT11_ReadByte();
		dht[2]   = DHT11_ReadByte();
		dht[3]   = DHT11_ReadByte();
		checksum = DHT11_ReadByte();
		sum = (dht[0]+dht[1]+dht[2]+dht[3]);
		if(checksum==sum)
			return Ture;
		else
			return False;
	};
	return False;
}

/******************************************************
 * FunctionName : DHT11_NumToString
 * Description  : change a byte to Dec String
 * Parameters   : dht: the num; tr: Result String Point
 * Returns      : none
*******************************************************/
void ICACHE_FLASH_ATTR
DHT11_NumToString(uint8 dht,uint8 *str)
{
  str[0] = (dht%100)/10 + '0';
  str[1] = dht%10 + '0';
  str[2] = '\0';
}



void ICACHE_FLASH_ATTR
DHT11_cabk(void)
{
	uint8 dhtData[4];
	uint8 outstr[4];

	if(ReadDHT11(dhtData))
	{
		uart0_sendStr("\r\nSuccessFull\r\n");
		uart0_sendStr("\r\nÎÂ¶È\r\n");
		DHT11_NumToString(dhtData[0],outstr);
		uart0_sendStr(outstr);
		DHT11_NumToString(dhtData[1],outstr);
		uart0_sendStr(".");
		uart0_sendStr(outstr);
		DHT11_NumToString(dhtData[2],outstr);
		uart0_sendStr("\r\nÊª¶È\r\n");
		uart0_sendStr(outstr);
		DHT11_NumToString(dhtData[3],outstr);
		uart0_sendStr("./n");
		uart0_sendStr(outstr);

	}
	//else
	//{
	//	uart0_sendStr("\r\nRead-ERROR\r\n");
    //}
}
os_timer_t DHT11_timer;
void  Dis_DHT11(void)
{
	os_timer_disarm(&DHT11_timer);
	os_timer_setfn(&DHT11_timer, (os_timer_func_t *) DHT11_cabk, NULL);
	os_timer_arm(&DHT11_timer, 1000, 1); //1s
}
