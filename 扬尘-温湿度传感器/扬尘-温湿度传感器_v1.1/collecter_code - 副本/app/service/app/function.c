#include "config.h"
#include "USART1.h"
#include "delay.h"
#include "GPIO.h"
#include "eeprom.h"
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys_clock.h"
#include "function.h"
#include "packet_dust.h"
#include "packet_route.h"

timer_out timerout1, timerout2;		 //���峬ʱ�ṹ��
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
	uint16_t v;

	uint16_t timer0_1, timer0_2=0;
static data uint16_t  wait_time_out=0;
//	uint16_t t, ah;

	uint16_t dust_buf[6];
	init_config();
	init_gpio_dust();

	// Printf1("1234", 4);
//  WDT_reset(7);   //初始化看门狗
  WDT_CONTR = 0x27;                           //使能看门狗,溢出时间约为8s
	while(1)
	{
//	 	uart1_check_TimeOut();  //���ڳ�ʱ���
//	  uart2_check_TimeOut(); 		
				
        timer0_1 = get_sys_ticks();
        if((timer0_1 - timer0_2)>200) { 
/**********定时工作************************************************/
					wait_time_out++;
					if(wait_time_out > 90)  wait_time_out = 0;   
					if(wait_time_out <= 45)  //工作1分30秒
						{
						 if(wait_time_out > 15) S2_RX_EN();			//允许串口2接收 30、、、、秒后接收数据
//							REN = 1;     //允许串口1接收
							dust_set   = 1;  //传感器工作
						}
					else 		//不工作
					{
//						REN = 0;     //禁串口1接收
						S2_RX_Disable();	//禁止串口2接收
						dust_set   = 0;  //传感器睡眠
						LED_SYS_STATE_OFF;
						LED_SYS_STATE_OFF;
					}
				
/********定時候緩存数据**************************************************/				
				LED_SYS_STATE_OFF
//				WDT_reset(7);     					//喂狗
				WDT_CONTR |= 0x10;                      //清看门狗,否则系统复位
		    v = get_dustvo(dust_buf);

//        delay_ms(500);
        if(v == 0) {
//            DEBUG_OUT("dust sensor not ready\n");
            memset(dust_buf, 0xff, sizeof(dust_buf));
        } else {
             _nop_();
//           EA = 0;
						S2_RX_Disable();	//禁止串口2接收
            _nop_();
            data_pm251 = dust_buf[0];
            data_pm101 = dust_buf[1];
            data_pm252 = dust_buf[2];
            data_pm102 = dust_buf[3];
            data_temp  = dust_buf[4];
            data_airhum= dust_buf[5];
            _nop_();
//            EA = 1;
						S2_RX_EN();			//允许串口2接收
            _nop_();
						
//						printf("data_pm251=%d\n", (int) data_pm251);
//						printf("data_pm101=%d\n", (int) data_pm101);
//						printf("data_pm252=%d\n", (int) data_pm252);
//						printf("data_pm102=%d\n", (int) data_pm102);
//						printf("data_temp=%d\n", (int) data_temp);
//						printf("data_airhum=%d\n", (int) data_airhum);
        }
				timer0_2 = get_sys_ticks();          
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



