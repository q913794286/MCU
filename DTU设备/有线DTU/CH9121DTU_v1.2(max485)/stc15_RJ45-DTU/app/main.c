/*c51 Uip 移植实例
*环境 KEIL
*www.anchey.com ancheel
*/
#include	"config.h"
#include	"USART1.h"
#include	"delay.h"
#include	"GPIO.h"
#include  "usart1.h"

#include   "sys_clock.h"
#include "function.h"

uint8_t UsartX_send ;

void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//结构定义
	GPIO_InitStructure.Pin  = GPIO_Pin_All;		//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
	GPIO_InitStructure.Mode = GPIO_PullUp;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);	//初始化	
				
}

/*************  串口1初始化函数 *****************/
void	UART_config(void)
{
	COMx_InitDefine		COMx_InitStructure;					//结构定义
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//模式,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			//使用波特率,   BRT_Timer1, BRT_Timer2 (注意: 串口2固定使用BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = 9600ul;			//波特率, 一般 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//接收允许,   ENABLE或DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//波特率加倍, ENABLE或DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//中断允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//中断优先级, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//切换端口,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(必须使用内部时钟)
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;		//内部短路RXD与TXD, 做中继, ENABLE,DISABLE
	USART_Configuration(USART1, &COMx_InitStructure);		//初始化串口1 USART1,USART2

	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//模式,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BaudRate  = 9600ul;			//波特率,     110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//接收允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//中断允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//中断优先级, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART2_SW_P10_P11;	//切换端口,   UART2_SW_P10_P11,UART2_SW_P46_P47
	USART_Configuration(USART2, &COMx_InitStructure);		//初始化串口2 USART1,USART2
//	Printf1("123",3);
//	PrintString1("STC15F2K60S2 UART1 Test Prgramme!\r\n");	//SUART1发送一个字符串
//	PrintString2("STC15F2K60S2 UART2 Test Prgramme!\r\n");	//SUART2发送一个字符串
}


void dtu_config()
{
    char start_state;
	uint16_t tartt_time, second_time,thred_time;
	start_state =1;
	uart1_cmd = 0;
//	config_mode = 0;
	printf("task0\r\n");															

	tartt_time = get_sys_ticks();
	while(1)
	{
		while(start_state)
		{
		   second_time = get_sys_ticks();	
			 
			 if(second_time%100==0)  {if(second_time!=thred_time) printf("s=%ds\r\n",second_time/100);}			 
		   if((second_time - tartt_time)>500){start_state=0; goto start_x;}//10秒无操作退出
		   if(uart1_cmd==1) {printf("in-cfg-OK\r\n"); start_state=0;		break;}
			 thred_time = second_time;
		}
	   switch(uart1_cmd)
	   {	 			
			 case 1:	Printf1("ok",2);		//进入配置模式
								break;
			 case 2:	usart1_cmd_write();  	//进入参数单片机配置
								Printf1("ok",2);
								break;
			 case 3:	usart1_and_usart2();	//收到数据转发
								break;
			 case 4:	uart1_cmd = 0;
								goto start_x;	//退出命令退出配置
								break;
		  default:  break;
	   }

	  }
start_x: 
   printf("quit-OK\r\n");		
		
}
void main(void)
{
  UsartX_send = 1;
	GPIO_config();
	UART_config();
	sys_clock_init();
	EA = 1;
	//定时器稳定前尽可能不要操作串口
//  dtu_config();
  LED1 = 1;
	LED2 = 1;
	function();
   	//debug_loop();
}


char putchar(char c)
{
//    if(c == '\n') 
//	{
//        SBUF = '\r';		   
//        while(!TI);
//    }

	if(UsartX_send == 1)
	{
		SBUF = c;
		while(!TI);
		TI = 0;
	}
	if(UsartX_send == 2)
	{
		S2BUF = c;
		while(!TI2);                 
		CLR_TI2();
	}
    return c;
}

