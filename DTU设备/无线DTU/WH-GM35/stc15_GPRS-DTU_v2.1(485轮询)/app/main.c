/*c51 Uip ��ֲʵ��
*���� KEIL
*www.anchey.com ancheel
*/
#include	"config.h"
#include	"USART1.h"
#include	"delay.h"
#include	"GPIO.h"

#include   "sys_clock.h"
#include "function.h"
#include "GPRS.h"
 sbit LED=P3^5;

uint8_t UsartX_send ;

void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//�ṹ����
	GPIO_InitStructure.Pin  = GPIO_Pin_All;		//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
	GPIO_InitStructure.Mode = GPIO_PullUp;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);	//��ʼ��
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);		
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);			
}

/*************  ����1��ʼ������ *****************/
void	UART_config(void)
{
	COMx_InitDefine		COMx_InitStructure;					//�ṹ����
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//ģʽ,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			//ʹ�ò�����,   BRT_Timer1, BRT_Timer2 (ע��: ����2�̶�ʹ��BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = 9600ul;			//������, һ�� 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//��������,   ENABLE��DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//�����ʼӱ�, ENABLE��DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//�ж�����,   ENABLE��DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//�ж����ȼ�, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//�л��˿�,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(����ʹ���ڲ�ʱ��)
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;		//�ڲ���·RXD��TXD, ���м�, ENABLE,DISABLE
	USART_Configuration(USART1, &COMx_InitStructure);		//��ʼ������1 USART1,USART2

	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//ģʽ,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BaudRate  = 115200ul;			//������,     110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//��������,   ENABLE��DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//�ж�����,   ENABLE��DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//�ж����ȼ�, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART2_SW_P10_P11;	//�л��˿�,   UART2_SW_P10_P11,UART2_SW_P46_P47
	USART_Configuration(USART2, &COMx_InitStructure);		//��ʼ������2 USART1,USART2
//	Printf1("123",3);
//	PrintString1("STC15F2K60S2 UART1 Test Prgramme!\r\n");	//SUART1����һ���ַ���
//	PrintString2("STC15F2K60S2 UART2 Test Prgramme!\r\n");	//SUART2����һ���ַ���
}

void USRT1_config(u32 buad)
{
	COMx_InitDefine		COMx_InitStructure;					//�ṹ����
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//ģʽ,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			//ʹ�ò�����,   BRT_Timer1, BRT_Timer2 (ע��: ����2�̶�ʹ��BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = buad;			//������, һ�� 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//��������,   ENABLE��DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//�����ʼӱ�, ENABLE��DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//�ж�����,   ENABLE��DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//�ж����ȼ�, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//�л��˿�,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(����ʹ���ڲ�ʱ��)
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;		//�ڲ���·RXD��TXD, ���м�, ENABLE,DISABLE
	USART_Configuration(USART1, &COMx_InitStructure);		//��ʼ������1 USART1,USART2
}

void init(void)
{
	GPIO_config();
	UART_config();
	sys_clock_init();
	EA = 1;
	//��ʱ���ȶ�ǰ�����ܲ�Ҫ��������

//	printf("%s","123456789\r\n");
//	PrintString1("STC15F2K60S2 UART1 Test Prgramme!\r\n");	//SUART1����һ���ַ���
//	PrintString2("STC15F2K60S2 UART2 Test Prgramme!\r\n");	//SUART2����һ���ַ���
//	while(1);
	
   	//debug_loop();
}

void main() 	 //�������񣬳�ʼ������
{
    char start_state;
	uint16_t tartt_time, second_time,thred_time;
   
	
	init();
	UsartX_send = 1;  //Ĭ��ʹ�ô���1
	start_state =1;
	uart1_cmd = 0;
	config_mode = 1;
	Power_ON;
	printf("task0\r\n");															

	tartt_time = get_sys_ticks();
	
	while(1)
	{
		while(start_state)
		{
		   second_time = get_sys_ticks();				 
			 if(second_time%100==0)  {if(second_time!=thred_time) printf("s=%ds\r\n",second_time/100);}			 
		   if((second_time - tartt_time)>500){start_state=0; goto start_x;}//10���޲����˳�
		   if(uart1_cmd==1) {printf("in-cfg-OK\r\n"); start_state=0;		break;}
			 thred_time = second_time;
		}
	   switch(uart1_cmd)
	   {	 			

		 case 1:				   //�����������
		 			break;
					
		 case 2:	usart1_and_usart2();	//����GPRS��ѯģʽ
//							printf("in-check-ok!");
		 			    break;
#if AES
		 case 3:	delay_ms(500);
							usart1_cmd_write();	    // ����AES����
							printf("uart-cfg-OK\r\n");
							uart1_cmd = 1;
							break;
#endif
		 case 4:
							delay_ms(500);
							gprs_conf();		   // ����GPRS��ʼ������
							uart1_cmd = 1;
							printf("gprs-cfg-OK\r\n");
							break;
		 case 5:	
//					uart1_cmd = 0;
//							printf("quit-OK\r\n");
							printf("quit-cfg-OK\r\n");
							goto start_x;	//�˳������˳�����
							break;
		  default:  break;
	   }

	}
start_x:
	
  Power_ON;
	COM1.RX_Cnt = 0;
	COM2.RX_Cnt = 0;
	COM1.RX_TimeOut=0;
	COM2.RX_TimeOut=0;
	config_mode = 0;     //�����������
	while(1)
	{
		function();
	}	
}

#define S2TI 0x02   //??2?????????  
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
	while(COM2.B_TX_busy);	
	COM2.B_TX_busy = 1;	
	}
    return c;
}


