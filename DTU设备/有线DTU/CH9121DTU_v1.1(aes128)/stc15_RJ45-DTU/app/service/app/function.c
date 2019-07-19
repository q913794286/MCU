#include "config.h"
#include "USART1.h"
#include "delay.h"
#include "GPIO.h"
#include "eeprom.h"

#include <stdio.h>
#include <string.h>
#include "sys_clock.h"
#include "function.h"
#include "aes.h"
#include "aes128app.h"
#include "crc16.h"

timer_out timerout1, timerout2;		 //���峬ʱ�ṹ��
AES128 aes128={ 
				{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07},
				{0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c },
   			    {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }				
				};


//void uart_check_TimeOut(void);
void usart1_cmd_write();
void usart1_and_usart2();

void function(void)
{
	uart1_cmd = 0; //�������

	EEPROM_read_n(0x00,RX2_Buffer,48);
    delay_ms(6);
//	memcpy(aes128.key, &RX2_Buffer[0],16);
//	memcpy(aes128.iv, &RX2_Buffer[16],16);
//	memcpy(aes128.id, &RX2_Buffer[32],16);

	while(1)
	{
	 /*	 uart1_cmd = 0 �����������ܷ�����
	  *	 uart1_cmd = 1 �����������ģʽ
	  *  uart1_cmd = 2 ���뵥Ƭ���������ݣ�
	  *  uart1_cmd = 3 ����GPRS��������
	  *  uart1_cmd = 4 �˳�����ģʽ  
	  */
	   switch(uart1_cmd)
	   {
	   	 case 0: 	uart1_check_TimeOut();  //���ڳ�ʱ���
	  				uart2_check_TimeOut(); 		 			
					break;
		 case 1:	Printf1("ok",2);		//��������ģʽ
		 			break;
		 case 2:	usart1_cmd_write();  	//���������Ƭ������
		 			Printf1("ok",2);
		 			break;
		 case 3:	usart1_and_usart2();	//����GPRS��������
		 			break;
		 case 4:	uart1_cmd = 0;
		 			break;
	   }
	}
}

#if 1
/*
*���ڽ��ճ�ʱ����
* ���ܣ����û�ˢ�³�ʱʱ��
*/
void uart1_set_TimeOut(uint16_t ms)
{

    timerout1.start = get_sys_ticks();
    timerout1.ms = ms;
}

void uart2_set_TimeOut(uint16_t ms)
{

    timerout2.start = get_sys_ticks();
    timerout2.ms = ms;
}

/*
*���ڽ��ճ�ʱ���
*/
//u8 code sbuf1[]={0xc3,0x01};
//u8 code cc[]={0xC3, 0x01, 
//			  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
//			  0x00, 0x10, 
//			  0x86, 0xE2, 0x93, 0x97, 0x4B, 0x38, 0x3F, 0xA5, 0x10, 0xF0, 0x76, 0xBF, 0xD8, 0x6E, 0x68, 0x72
//			  };
void uart1_check_TimeOut(void)
{
    uint16_t count1;
	uint8_t  tmp[20];
	uint16_t crc;
	uint16_t data_len;
    if(COM1.RX_TimeOut > 0)		//��ʱ����
    {
        count1 = get_sys_ticks();
        if((count1 - timerout1.start)>timerout1.ms)
        {
//            COM1.RX_TimeOut = 0;  //���ճ�ʱ����
//            COM1.RX_Cnt = 0;		  //���ռ�������
            /*
             *����1��ⳬʱ����
             *���ܡ��������2����
            */
			//app_encrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t len, uint8_t *out);; //EBC����
            data_len = app_encrypt_cbc(aes128.key, aes128.iv, RX1_Buffer, COM1.RX_TimeOut-1, TX2_Buffer);	  //���ܷ������ݳ���RX2_Buffer	
//			Printf1(RX2_Buffer,COM1.RX_TimeOut);  //data	

//		    tmp[0] = sbuf1[0];
//			tmp[1] = sbuf1[1];
			memcpy(&tmp[2], aes128.id, 8);
			tmp[10] = (data_len>>8)&0xff;
			tmp[11] = data_len&0xff;

			crc = crc16_2(tmp, 12, TX2_Buffer, data_len);  

			Printf2(tmp,12);			//head cmd id(8B) len(2B)
			Printf2(TX2_Buffer,data_len);  //data
			TX2_write2buff((crc>>8)&0xff);	  //crc
			TX2_write2buff(crc&0xff);		  //crc
			TX2_write2buff(0xe7);			  //end

 			COM1.RX_TimeOut = 0;  //���ճ�ʱ����
            COM1.RX_Cnt = 0;      //���ռ�������
        }
    }
}

void uart2_check_TimeOut(void)
{
	 uint16_t count2;
	
    if(COM2.RX_TimeOut > 0)		//��ʱ����
    {
        count2 = get_sys_ticks();
        if((count2 - timerout2.start)>timerout2.ms)
        {            
            /*
             *����2��ⳬʱ����
             * ���ܡ��������2����
            */ 
        }
    }
}
#endif



void usart1_cmd_write()
{

//void 	EEPROM_write_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number);
//void	EEPROM_SectorErase(uint16_t EE_address);
	memcpy(aes128.id, &RX1_Buffer[1], 8);
	memcpy(aes128.key, &RX1_Buffer[9], 16);
	memcpy(aes128.iv, &RX1_Buffer[25], 16);

	EEPROM_SectorErase(0x00);
	delay_ms(6);		//����ʱ��4ms~6ms  
	EEPROM_write_n(0x00,&RX1_Buffer[1],COM1.RX_Cnt);	  //uart1_cnt = 48Byte
	delay_ms(6);
	Printf1("ok",2);
//	ISP_CONTR = 0x60; //���óɹ�����
}

sbit LED1 = P1^1;
sbit LED2 = P1^2;
sbit LED_state1 = P1^3;
sbit GPIO_power = P1^4;

void MCU_check(uint16_t check_time)
{
	static uint16_t start_T;
	static uint8_t CT;
	if(CT == 0)
	{
		start_T = get_sys_ticks();
		CT = 1;
	}

	if((get_sys_ticks() - start_T)>check_time)
	{
		CT = 0;
		if((LED1 || LED2) == 1)
		{
			LED_state1 = 1;
			delay_ms(10000);
			LED_state1 = 0; 
		}
		else
		{
		   GPIO_power = 1;
		   delay_ms(2000);
		   GPIO_power = 0;
		}
	}	
}

void usart1_and_usart2()
{
	uint16_t i;
	if((COM1.RX_TimeOut > 0)&&(COM2.RX_TimeOut == 0))		//��ʱ����
	{
		if(--COM1.RX_TimeOut == 0)
		{
			if(COM1.RX_Cnt > 0)
			{
				for(i=0; i<COM1.RX_Cnt; i++)	TX2_write2buff(RX1_Buffer[i]);	//�յ�������ԭ������
			}
			COM1.RX_Cnt = 0;
		}
	}
	if((COM2.RX_TimeOut > 0) && (COM1.RX_TimeOut == 0))		//��ʱ����
	{
		if(--COM2.RX_TimeOut == 0)
		{
			if(COM2.RX_Cnt > 0)
			{
				for(i=0; i<COM2.RX_Cnt; i++)	TX1_write2buff(RX2_Buffer[i]);	//�յ�������ԭ������
			}
			COM2.RX_Cnt = 0;
		}
	}
}