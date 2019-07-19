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

timer_out timerout1, timerout2;		 //定义超时结构体
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
	 	uart1_check_TimeOut();  //串口超时检测
	  	uart2_check_TimeOut(); 
	 }
}

#if 1
/*
*串口接收超时设置
* 功能：设置或刷新超时时间
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
*串口接收超时检测
*/

void uart1_check_TimeOut(void)
{
    uint16_t count1;
    if(COM1.RX_TimeOut > 0)		//超时计数
    {
        count1 = get_sys_ticks();
        if((count1 - timerout1.start)>timerout1.ms)
        {

 			COM1.RX_TimeOut = 0;  //接收超时清零
            COM1.RX_Cnt = 0;      //接收计数清零
        }
    }
}

void uart2_check_TimeOut(void)
{
	 uint16_t count2;
	
    if(COM2.RX_TimeOut > 0)		//超时计数
    {
        count2 = get_sys_ticks();
        if((count2 - timerout2.start)>timerout2.ms)
        {            

			COM2.RX_TimeOut = 0;  //接收超时清零
            COM2.RX_Cnt = 0;      //接收计数清零
        }
    }
}
#endif



