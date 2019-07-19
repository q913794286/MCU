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
//#include "cJSON.h"

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
void RS485_coil();



void init_config()
{
	uint8_t s_buf[50];
	uint8_t *ptr,*ptr2;
	S_config config;
	uint8_t sta=0;
	unsigned long baud;
	
	uart1_cmd = 0; 			//命令接收
	
	//serial
	memcpy(s_buf,0,50);
	EEPROM_read_n(0x200,&s_buf,50);
    delay_ms(6);
	ptr2 = strtrim(s_buf);	//将多余的空格去掉
	while((ptr = strsep(&ptr2, ";")) != NULL){	//字符串分割(以;好分格)  波特率;服务类型+服务器地址+端口
	   if(sta==0)
	  	{
			config.baud = ptr; 
		}
	   if(sta==1) 
	   {
			config.server = ptr;
	   	}
	   sta++;
	}
	baud =strtoul(config.baud,NULL,10);	  //串口波特率字符串转换成10进制
	printf("parameter: \r\n");
	printf("baud=%ld\r\n",baud);
	printf("server=%s\r\n",config.server);
	if(baud<1200)
		{USRT1_config(9600);	  //串口二配置后再次初始化
		printf("default baud 9600\r\n");}
	else
		USRT1_config(baud);	  //串口二配置后再次初始化。

	init_GPRS(&config); //GPRS模块初始化
//	aes128.state=1;
}

/*******功能执行主函数**************/
void function(void)
{
	
	init_config();
	while(1)
	{
	 /*	 uart1_cmd = 0 进入正常发数据
	  *	 uart1_cmd = 1 进入进入配置模式
	  *  uart1_cmd = 2 进入查询模式 
	  *  uart1_cmd = 3 进入单片机保存数据；
	  *  uart1_cmd = 4 进入GPRS配置数据
	  *  uart1_cmd = 5 退出配置模式  
	  */
		/*串口超时执行函数 */
//	 	uart1_check_TimeOut();  
	  uart2_check_TimeOut(); 
		/*GPRS网络状态监测函数*/
//		GPRS_check(10); 		//10分钟做一次网络监测 
		
		/*RS485指令轮询函数*/
	  RS485_coil();
	 }
}
#if 1
uint8_t code send_cmd[]={0x01,0x03,0x00,0x00,0x06,0xc5,0xc8}; //查询所有数据
/*返回实例：01 03 0C 09 C4 1B 8F 1F 40 01 90 01 1E 00 00 96 A7 */
void RS485_coil()
{
		static uint32_t timer0_1=0, timer0_2=0;
		timer0_1 = get_sys_ticks();
		if((timer0_1 - timer0_2)>500)  //每 5秒轮询一次
		{ 
		  /*执行函数*/
			Printf1(send_cmd,sizeof(send_cmd));
			/**/
			timer0_2 = get_sys_ticks(); 
		}
}

const uint8_t code T[]  = "\"T\":";      //温度
const uint8_t code PH[] = "\"PH\":";     // PH
const uint8_t code DO[] = "\"DO\":";     //余氯
const uint8_t code NTU[]= "\"NTU\":";    //浊度
const uint8_t code GC[] = "\"GC\":";     //电导
//char text1[]="\n{\n\"name\": \"Jack (\\\"Bee\\\") Nimble\", \n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  false,\"frame rate\": 24\n}\n}";
void Unpack(uint8_t byte)
{
	static uint16_t received_bytes = 0;
	uint8_t read_index = 0;
	struct frame *packet;
	uint16_t crc;
	
	if(received_bytes >= sizeof(RX1_Buffer)) received_bytes=0;
	RX1_Buffer[received_bytes] = byte;
  received_bytes++;
	
	while(received_bytes>=17)
	{  
	   
	   packet = (struct frame*) &RX1_Buffer[read_index];
//		 packet->data12 = (uint8_t *)malloc(sizeof(uint8_t)*12);
		 if(packet->addr == 0x01 && packet->func == 0x03)
 		 {
		   if(packet->data_size + 5 > received_bytes) return;
			 crc = crc16(&RX1_Buffer[read_index],packet->data_size+3);
//			 TX1_write2buff(crc>>8&0xff);
//			 TX1_write2buff(crc&0xff);
//       TX1_write2buff(packet->crcH);
//			 TX1_write2buff(packet->crcL);
			 if((packet->crcL == (crc>>8&0xff))&&(packet->crcH == (crc&0xff)))
			 {
//				printf(text1);
				  UsartX_send = 2;
					printf("%s\r\n","{");
				  printf("%s%.2f%s",T,(float)(packet->data12[0]<<8|packet->data12[1])/100,",\r\r\n");
					printf("%s%.3f,\r\r\n",PH,(float)(packet->data12[2]<<8|packet->data12[3])/1000);
  				printf("%s%.3f,\r\r\n",DO,(float)(packet->data12[4]<<8|packet->data12[5])/1000);
					printf("%s%.2f,\r\r\n",NTU,(float)(packet->data12[6]<<8|packet->data12[7])/100); 
					printf("%s%d\n",GC,(int)(packet->data12[8]<<8|packet->data12[9]));
					printf("%s\r\r\n","}");
					UsartX_send = 1;
					received_bytes -= packet->data_size+5;
          read_index += packet->data_size+5;
					continue;
			 }			 
		 }
		 received_bytes--;
     read_index++;
		 
	}
	if(read_index != 0)
        memmove(RX1_Buffer, &RX1_Buffer [read_index], received_bytes);
}

#endif

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
u8 code sbuf1[]={0xc3,0x01};
//u8 code cc[]={0xC3, 0x01, 
//			  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
//			  0x00, 0x10, 
//			  0x86, 0xE2, 0x93, 0x97, 0x4B, 0x38, 0x3F, 0xA5, 0x10, 0xF0, 0x76, 0xBF, 0xD8, 0x6E, 0x68, 0x72
//			  };
void uart1_check_TimeOut(void)
{
    uint16_t count1;
#if AES		
		uint8_t  tmp[20];
		uint16_t crc;
		uint16_t data_len;
#endif		
    if(COM1.RX_TimeOut > 0)		//超时计数
    {
        count1 = get_sys_ticks();
        if((count1 - timerout1.start)>timerout1.ms)
        {
#if AES
			if(aes128.state==2)
	        {  
			    /*
	             *串口1检测超时动作
	             *加密、封包串口2发送
	            */
				//app_encrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t len, uint8_t *out);; //EBC加密
	      data_len = app_encrypt_cbc(aes128.key, aes128.iv, RX1_Buffer, COM1.RX_TimeOut-1, TX2_Buffer);	  //加密返回数据长度RX2_Buffer	
	//			Printf1(RX2_Buffer,COM1.RX_TimeOut);  //data	
	
			  tmp[0] = sbuf1[0];
				tmp[1] = sbuf1[1];
				memcpy(&tmp[2], aes128.id, 8);
				tmp[10] = (data_len>>8)&0xff;
				tmp[11] = data_len&0xff;
	
				crc = crc16_2(tmp, 12, TX2_Buffer, data_len);  
	
				Printf2(tmp,12);			//head cmd id(8B) len(2B)
				Printf2(TX2_Buffer,data_len);  //data
				TX2_write2buff((crc>>8)&0xff);	  //crc
				TX2_write2buff(crc&0xff);		  //crc
				TX2_write2buff(0xe7);			  //end
			}
			if(aes128.state==1)
			{
#endif
//			  Printf2(RX1_Buffer,COM1.RX_Cnt);
#if AES			
			}
#endif
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
            /*
             *串口2检测超时动作
             * 加密、封包串口2发送
            */ 
//			PrintString1(RX2_Buffer);
//			printf("123");
//				if(aes128.state==2){}
//				if(aes128.state==1)
//				{
					Printf1(RX2_Buffer,COM2.RX_Cnt);
//				}
				COM2.RX_TimeOut = 0;  //接收超时清零
				COM2.RX_Cnt = 0;      //接收计数清零
        }
    }
}


void usart1_cmd_write()
{

//void 	EEPROM_write_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number);
//void	EEPROM_SectorErase(uint16_t EE_address);
	//printf(RX1_Buffer);
//	memcpy(aes128.key, &RX1_Buffer[0],16);
//	memcpy(aes128.iv, &RX1_Buffer[16],16);
//	memcpy(aes128.id, &RX1_Buffer[32],8);

	EEPROM_SectorErase(0x00);
	delay_ms(6);		//擦除时间4ms~6ms  
	EEPROM_write_n(0x00,RX1_Buffer,COM1.RX_Cnt);	  //uart1_cnt = 41Byte
	delay_ms(6);
	Printf1("ok",2);
	memset(RX1_Buffer,0,128);
	COM1.RX_Cnt = 0;
//	ISP_CONTR = 0x60; //配置成功重启
}
#endif

void gprs_conf()
{	
  EEPROM_SectorErase(0x200);
	delay_ms(10);		//擦除时间4ms~6ms  
	EEPROM_write_n(0x200,RX1_Buffer,50);	  //uart1_cnt = 48Byte
	delay_ms(6);
	Printf1("ok\n",4);

	memset(RX1_Buffer,0,128);
	COM1.RX_Cnt = 0;
}



sbit LED1 = P3^5;
sbit LED2 = P3^4;

uint8_t second,minute;
void GPRS_check(uint16_t times)
{
	static uint16_t start_T;

	start_T = get_sys_ticks();
	if((get_sys_ticks() - start_T)>100)
	{	
		if(gprs_status==1) LED1=1;
		else 
		LED1=~LED1;	
		LED2=~LED2;
		if(++second>=60)
		{
			second=0;
			if(++minute>=times)
			{ 				
				if(gprs_cmd("AT", RX2_Buffer, "OK", 500)==0)	//检测是否断网	断网则返回OK
				{
					Power = 1;  //关GPRS模块电源
					delay_ms(100);		   
					Power = 0;  //开GPRS模块电源
					delay_ms(200);
					ISP_CONTR = 0x60;  //点偏激重启
				}
				minute=0;
			}
		}		  
	}	
}

void usart1_and_usart2()
{
 	static uint16_t count1, count2;
	
    if(COM1.RX_TimeOut > 0)		//超时计数
    {
        count1 = get_sys_ticks();
        if((count1 - timerout1.start)>timerout1.ms)
        {    
						UsartX_send = 2;
						printf(RX1_Buffer);
						UsartX_send = 1;
						//Printf2(RX1_Buffer,COM1.RX_Cnt);
//						Printf2('\r');
						memset(RX1_Buffer,0,128);
						COM1.RX_TimeOut = 0;  //接收超时清零
						COM1.RX_Cnt = 0;      //接收计数清零
        }
    }
	
    if(COM2.RX_TimeOut > 0)		//超时计数
    {
        count2 = get_sys_ticks();
        if((count2 - timerout2.start)>timerout2.ms)
        {            
//						Printf1(RX2_Buffer,COM2.RX_Cnt);
//						Printf1("\r\n");						
						printf(RX2_Buffer);
						printf("\r");
						memset(RX2_Buffer,0,128);
						COM2.RX_TimeOut = 0;  //接收超时清零
						COM2.RX_Cnt = 0;      //接收计数清零
        }
    }
}
