#include "config.h"
#include "USART1.h"
#include "delay.h"
#include "GPIO.h"
#include "eeprom.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys_clock.h"
#include "function.h"
#include "aes.h"
#include "aes128app.h"
#include "crc16.h"
#include "GPRS.h"

timer_out timerout1, timerout2;		 //���峬ʱ�ṹ��
//static S_config s_config;
AES128 aes128;
//AES128 aes128={ {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07} ,
//				{0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c },
//   			    {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }								
//				};

//void uart_check_TimeOut(void);
void usart1_cmd_write(void);
void usart1_and_usart2(void);
extern void USRT1_config(u32 buad);




void init_config()
{

}
void function(void)
{
	
	init_config();
	while(1)
	{
	 	uart1_check_TimeOut();  //���ڳ�ʱ���
	  	uart2_check_TimeOut(); 
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

void uart1_check_TimeOut(void)
{
    uint16_t count1;
    if(COM1.RX_TimeOut > 0)		//��ʱ����
    {
        count1 = get_sys_ticks();
        if((count1 - timerout1.start)>timerout1.ms)
        {

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

			COM2.RX_TimeOut = 0;  //���ճ�ʱ����
            COM2.RX_Cnt = 0;      //���ռ�������
        }
    }
}
#endif



