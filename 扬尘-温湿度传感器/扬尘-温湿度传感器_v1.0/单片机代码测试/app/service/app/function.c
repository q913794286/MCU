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
#include "packet_dust.h"
#include "packet_route.h"

timer_out timerout1, timerout2;		 //定义超时结构体
//static S_config s_config;

//void uart_check_TimeOut(void);
void usart1_cmd_write(void);
void usart1_and_usart2(void);
extern void USRT1_config(u32 buad);
volatile uint8_t send_flg = 0;



void init_config()
{
//    LED_SYS_STATE_ON;
//	LED_ROUTER_STATE_ON;
//	delay_ms(500);
//	delay_ms(500);
//	LED_SYS_STATE_OFF;
//	LED_ROUTER_STATE_OFF;
}

sbit dust_set   = P1^2;
sbit dust_reset = P0^3;

void init_gpio_dust()
{
	dust_set   = 1;
	dust_reset = 1;	
}

void function(void)
{
	uint32_t v;
	uint8_t i;
	uint16_t timer0_1, timer0_2=0;
//	uint16_t t, ah;

	uint16_t dust_buf[6];
	init_config();
	init_gpio_dust();
//	WDT_reset(7);
//	printf("123");
//	printf("pm2.5(1)=%d\n", (int) data_pm251);
	Printf1("1234",4);
	while(1)
	{
//	 	uart1_check_TimeOut();  //串口超时检测
//	  	uart2_check_TimeOut(); 

		

	    
	
        timer0_1 = get_sys_ticks();
        if((timer0_1 - timer0_2)>500)
		{
		 LED_SYS_STATE_OFF; 
		  v = get_dustvo(dust_buf);

//        delay_ms(500);
        if(v == 0) {
//            DEBUG_OUT("dust sensor not ready\n");
            memset(dust_buf, 0xff, sizeof(dust_buf));
        } else {

            data_pm251 = dust_buf[0];
            data_pm101 = dust_buf[1];
            data_pm252 = dust_buf[2];
            data_pm102 = dust_buf[3];
			data_temp  = dust_buf[4];
			data_airhum= dust_buf[5];
        }
		timer0_2 = get_sys_ticks();
		}

		
		if (send_flg == 1)
		 {
		  send_flg = 0;
		  LED_ROUTER_STATE_OFF;
		  term_process();
		  delay_ms(5);
		 }
//        disableInterrupts();

//        data_temp = t;
//        data_airhum = ah;

//        enableInterrupts();

//		printf("pm2.5(1)=%d\n", (int) data_pm251);
//		printf("pm10(1)=%d\n", (int) data_pm101);
//		printf("pm2.5(2)=%d\n", (int) data_pm252);
//	    printf("pm10(2)=%d\n", (int) data_pm102);
//		printf("temp=%d\n", (int) data_temp);
//		printf("hum=%d\n", (int) data_airhum);

//		for(i = 0; i< 10; i++) {
//						
////            WDT_reset(7);
//            delay_ms(500);
//        }
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



