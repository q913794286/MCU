/*
 * user_pms.c
 *
 *  Created on: 2018年6月28日
 *      Author: clx
 */
#include "os_type.h"
#include "osapi.h"
#include "user_config.h"

#include "uart.h"
#include "user_pms.h"

bool Tick(uint32 ms)
{
	uint32 t1,t2;
	t1 = system_get_time()%1000;
	if(t1==0)
	{
      ms--;
	  if(ms==0)
	  { return true;}
	  else
	  {return false;}

	}
}
int length(u8 *arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}

void Get_PM_value(void)
{
 uint8 num;
 uint16 check;
 if(Uart0_Receive[0]== 0x42 && Uart0_Receive[1]== 0x4d)
 {
	 //校验和计算
	 for(num=0;num<os_strlen(Uart0_Receive);num++)
	 {
		 check +=Uart0_Receive[num++];
	 }
	 //校验和比较
	 if(check == (Uart0_Receive[31]|Uart0_Receive[30]>>0x0f))
	 {
	 uint16 PM25 = Uart0_Receive[7] | Uart0_Receive[6]>>0x0f ;
	 uint16 PM10 = Uart0_Receive[9] | Uart0_Receive[8]>>0x0f ;
	 }

 }
}

	u8 cmd_mod1[]={0x42,0x4d,0xe1,0x00,0x00,0x01 ,0x70 }; //被动式
    u8 cmd_mod2[]={0x42,0x4d,0xe1,0x00,0x01,0x01 ,0x72 }; //主动式
	u8 cmd_none[]={0x42,0x4d,0xe4,0x00,0x01,0x01 ,0x75 }; //正常模式
	u8 cmd_sleep[]={0x42,0x4d,0xe4,0x00,0x00,0x01 ,0x74 }; //待机模式
	u8 cmd_read[]={0x42,0x4d,0xe2,0x00,0x00,0x00 ,0x71 };  //被动式读数
void Read_PM_value(void)
{
  uart0_tx_buffer(cmd_read, 7);
  uint8 fifo_len = (READ_PERI_REG(UART_STATUS(UART0))>>UART_RXFIFO_CNT_S)&UART_RXFIFO_CNT;
  while(!fifo_len)
  {
	  if(Tick(2000)) //如果超时跳出等待
	   {
		  uart0_tx_buffer(cmd_mod1, 7); //重设模式
		  return;
	   }
  }
  if(fifo_len)
  {
	  Get_PM_value();
  }

}

void PM_cabk(void)
{
	uart0_tx_buffer(cmd_read, 7);
}

os_timer_t PM_timer;
void PM_init(void)
{
	os_timer_disarm(&PM_timer);
	os_timer_setfn(&PM_timer, (os_timer_func_t *) PM_cabk, NULL);
	os_timer_arm(&PM_timer, 1000, 1); //1s
}
