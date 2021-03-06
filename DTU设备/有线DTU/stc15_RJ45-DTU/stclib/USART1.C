
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/


#include "USART1.h"
#include "function.h"

/*************** 装载串口发送缓冲 *******************************/
COMx_Define	COM1,COM2;
u8 xdata TX1_Buffer[COM_TX1_Lenth];	//发送缓冲
u8 xdata RX1_Buffer[COM_RX1_Lenth];	//接收缓冲

u8 xdata TX2_Buffer[COM_TX2_Lenth];	//发送缓冲
u8 xdata RX2_Buffer[COM_RX2_Lenth];	//接收缓冲




//u8 RecBuf[20];
u8 rec,count;
u8 Rec_over;
volatile uint8_t uart1_cmd;
u8 USART_Configuration(u8 UARTx, COMx_InitDefine *COMx)
{
	u8	i;
	u32	j;
	
	if(UARTx == USART1)
	{
		COM1.id = 1;
		COM1.TX_read    = 0;
		COM1.TX_write   = 0;
		COM1.B_TX_busy  = 0;
		COM1.RX_Cnt     = 0;
		COM1.RX_TimeOut = 0;
		COM1.B_RX_OK    = 0;
		uart1_cmd		= 0;
		for(i=0; i<COM_TX1_Lenth; i++)	TX1_Buffer[i] = 0;
		for(i=0; i<COM_RX1_Lenth; i++)	RX1_Buffer[i] = 0;

		if(COMx->UART_Mode > UART_9bit_BRTx)	return 2;	//模式错误
		if(COMx->UART_Polity == PolityHigh)		PS = 1;	//高优先级中断
		else									PS = 0;	//低优先级中断
		SCON = (SCON & 0x3f) | COMx->UART_Mode;
		if((COMx->UART_Mode == UART_9bit_BRTx) ||(COMx->UART_Mode == UART_8bit_BRTx))	//可变波特率
		{
			j = (MAIN_Fosc / 4) / COMx->UART_BaudRate;	//按1T计算
			if(j >= 65536UL)	return 2;	//错误
			j = 65536UL - j;
			if(COMx->UART_BRT_Use == BRT_Timer1)
			{
				TR1 = 0;
				AUXR &= ~0x01;		//S1 BRT Use Timer1;
				TMOD &= ~(1<<6);	//Timer1 set As Timer
				TMOD &= ~0x30;		//Timer1_16bitAutoReload;
				AUXR |=  (1<<6);	//Timer1 set as 1T mode
				TH1 = (u8)(j>>8);
				TL1 = (u8)j;
				ET1 = 0;	//禁止中断
				TMOD &= ~0x40;	//定时
				INT_CLKO &= ~0x02;	//不输出时钟
				TR1  = 1;
			}
			else if(COMx->UART_BRT_Use == BRT_Timer2)
			{
				AUXR &= ~(1<<4);	//Timer stop
				AUXR |= 0x01;		//S1 BRT Use Timer2;
				AUXR &= ~(1<<3);	//Timer2 set As Timer
				AUXR |=  (1<<2);	//Timer2 set as 1T mode
				TH2 = (u8)(j>>8);
				TL2 = (u8)j;
				IE2  &= ~(1<<2);	//禁止中断
				AUXR &= ~(1<<3);	//定时
				AUXR |=  (1<<4);	//Timer run enable
			}
			else return 2;	//错误
		}
		else if(COMx->UART_Mode == UART_ShiftRight)
		{
			if(COMx->BaudRateDouble == ENABLE)	AUXR |=  (1<<5);	//固定波特率SysClk/2
			else								AUXR &= ~(1<<5);	//固定波特率SysClk/12
		}
		else if(COMx->UART_Mode == UART_9bit)	//固定波特率SysClk*2^SMOD/64
		{
			if(COMx->BaudRateDouble == ENABLE)	PCON |=  (1<<7);	//固定波特率SysClk/32
			else								PCON &= ~(1<<7);	//固定波特率SysClk/64
		}
		if(COMx->UART_Interrupt == ENABLE)	ES = 1;	//允许中断
		else								ES = 0;	//禁止中断
		if(COMx->UART_RxEnable == ENABLE)	REN = 1;	//允许接收
		else								REN = 0;	//禁止接收
		P_SW1 = (P_SW1 & 0x3f) | (COMx->UART_P_SW & 0xc0);	//切换IO
		if(COMx->UART_RXD_TXD_Short == ENABLE)	PCON2 |=  (1<<4);	//内部短路RXD与TXD, 做中继, ENABLE,DISABLE
		else									PCON2 &= ~(1<<4);
		return	0;
	}

	if(UARTx == USART2)
	{
		COM2.id = 2;
		COM2.TX_read    = 0;
		COM2.TX_write   = 0;
		COM2.B_TX_busy  = 0;
		COM2.RX_Cnt     = 0;
		COM2.RX_TimeOut = 0;
		COM2.B_RX_OK    = 0;
		for(i=0; i<COM_TX2_Lenth; i++)	TX2_Buffer[i] = 0;
		for(i=0; i<COM_RX2_Lenth; i++)	RX2_Buffer[i] = 0;

		if((COMx->UART_Mode == UART_9bit_BRTx) ||(COMx->UART_Mode == UART_8bit_BRTx))	//可变波特率
		{
			if(COMx->UART_Polity == PolityHigh)		IP2 |=  1;	//高优先级中断
			else									IP2 &= ~1;	//低优先级中断
			if(COMx->UART_Mode == UART_9bit_BRTx)	S2CON |=  (1<<7);	//9bit
			else									S2CON &= ~(1<<7);	//8bit
			j = (MAIN_Fosc / 4) / COMx->UART_BaudRate;	//按1T计算
			if(j >= 65536UL)	return 2;	//错误
			j = 65536UL - j;
			AUXR &= ~(1<<4);	//Timer stop
			AUXR &= ~(1<<3);	//Timer2 set As Timer
			AUXR |=  (1<<2);	//Timer2 set as 1T mode
			TH2 = (u8)(j>>8);
			TL2 = (u8)j;
			IE2  &= ~(1<<2);	//禁止中断
			AUXR |=  (1<<4);	//Timer run enable
		}
		else	return 2;	//模式错误
		if(COMx->UART_Interrupt == ENABLE)	IE2   |=  1;		//允许中断
		else								IE2   &= ~1;		//禁止中断
		if(COMx->UART_RxEnable == ENABLE)	S2CON |=  (1<<4);	//允许接收
		else								S2CON &= ~(1<<4);	//禁止接收
		P_SW2 = (P_SW2 & ~1) | (COMx->UART_P_SW & 0x01);	//切换IO
	}
	return 3;	//其它错误
}

uint8_t temp;
/********************* UART1中断函数************************/
void UART1_int (void) interrupt UART1_VECTOR using 1
{
	u8 buf;
	 static	uint8_t cmd_flg=0;
	
    if(RI)
	{
		RI = 0;
	    if(COM1.B_RX_OK == 0)
	    {		
       	if(uart1_cmd == 0)
			{	
				uart1_set_TimeOut(200); 	//200ms未收到数据则接收结束
			}
			 buf= SBUF;
				if(COM1.RX_Cnt >= COM_RX1_Lenth)	COM1.RX_Cnt = 0;

				RX1_Buffer[COM1.RX_Cnt++] = buf;
				COM1.RX_TimeOut = TimeOutSet1;

				
		  
			switch(buf)
			{
				case 'M': cmd_flg = 1; COM1.RX_Cnt = 0; break;
				case 'U': if(cmd_flg == 1 && COM1.RX_Cnt == 1){uart1_cmd = 1; cmd_flg = 0; COM1.RX_Cnt = 0;} break; //进入配置模式

				case 'S': cmd_flg = 2; COM1.RX_Cnt = 0; break;
				case 'X': if(cmd_flg == 2 && COM1.RX_Cnt == 1){uart1_cmd = 2; cmd_flg = 0; COM1.RX_Cnt = 0;} break;	 //单片机配置

//				case 'G': cmd_flg = 3; COM1.RX_Cnt = 0; break;
//				case 'Y': if(cmd_flg == 3 && COM1.RX_Cnt == 1){uart1_cmd = 3; cmd_flg = 0; COM1.RX_Cnt = 0;} break;	 //GPRS机配置

				case 'Q': cmd_flg = 4; COM1.RX_Cnt = 0; break;
				case 'Z': if(cmd_flg == 4 && COM1.RX_Cnt == 1){uart1_cmd = 4; cmd_flg = 0; COM1.RX_Cnt = 0;} break; //退出单片机配置模式
				
			}				

		
		}
	}
//==============免断电下载命令 af af af af af 7f=========================
			if(SBUF == 0xaf)
			{			   
			   temp ++;
			}
            if(temp==5)
            {
                if(SBUF == 0x7f)
                {
                    ISP_CONTR = 0x60;
                    temp = 0;
                }
			}
//=====================================================================		    
	if(TI)
	{
		TI = 0;
//		if(COM1.TX_read != COM1.TX_write)
//		{
//		 	SBUF = TX1_Buffer[COM1.TX_read];
//			if(++COM1.TX_read >= COM_TX1_Lenth)		COM1.TX_read = 0;
//		}
//		else	
		COM1.B_TX_busy = 0;
	}
}

/********************* UART2中断函数************************/
void UART2_int (void) interrupt UART2_VECTOR using 2
{
	if(RI2)
	{
		CLR_RI2();
		if(COM2.B_RX_OK == 0)	 //确认串口已经初始化
		{
			uart2_set_TimeOut(200); //200ms未收到数据则接收结束
			if(COM2.RX_Cnt >= COM_RX2_Lenth)	COM2.RX_Cnt = 0; //为防止内存溢出，接收缓存溢出时清零
			RX2_Buffer[COM2.RX_Cnt++] = S2BUF;
			COM2.RX_TimeOut = TimeOutSet2;
		}
	}

	if(TI2)
	{
		CLR_TI2();
//		if(COM2.TX_read != COM2.TX_write)
//		{
//		 	S2BUF = TX2_Buffer[COM2.TX_read];
//			if(++COM2.TX_read >= COM_TX2_Lenth)		COM2.TX_read = 0;
//		}
//		else
			COM2.B_TX_busy = 0;
	}

}

void TX1_write2buff(u8 dat)	//写入发送缓冲，指针+1
{
//	TX1_Buffer[COM1.TX_write] = dat;	//装发送缓冲
//	if(++COM1.TX_write >= COM_TX1_Lenth)	COM1.TX_write = 0;
//
//	if(COM1.B_TX_busy == 0)		//空闲
//	{  
//		COM1.B_TX_busy = 1;		//标志忙
//		TI = 1;					//触发发送中断
//	}
	while(COM1.B_TX_busy);
	COM1.B_TX_busy = 1;
	SBUF = dat;
}

void PrintString1(u8 *puts)
{
    for (; *puts != 0;	puts++) TX1_write2buff(*puts); 	//遇到停止符0结束
}

void Printf1(u8 *puts, u8 len)
{
	u8 i;
	for( i=0;i<len;i++)
	{
		TX1_write2buff(puts[i]);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TX2_write2buff(u8 dat)	//写入发送缓冲，指针+1
{	
//	TX2_Buffer[COM2.TX_write] = dat;	//装发送缓冲
//	if(++COM2.TX_write >= COM_TX2_Lenth)	COM2.TX_write = 0;
//
//	if(COM2.B_TX_busy == 0)		//空闲
//	{  
//		COM2.B_TX_busy = 1;		//标志忙
//		SET_TI2();				//触发发送中断
//	}
	while(COM2.B_TX_busy);
	COM2.B_TX_busy = 1;
	S2BUF = dat;
}

void PrintString2(u8 *puts)
{
    for (; *puts != 0;	puts++)  TX2_write2buff(*puts); 	//遇到停止符0结束
}

void Printf2(u8 *puts, u8 len)
{
	u8 i;
	for( i=0;i<len;i++)
	{
	TX2_write2buff(puts[i]);
	}
}







