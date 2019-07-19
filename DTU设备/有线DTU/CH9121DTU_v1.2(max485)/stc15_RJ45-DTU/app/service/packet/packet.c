#include "config.h"
#include "packet.h"
#include "usart1.h"
#include "sys_clock.h"
#include "crc16.h"

#if 1
//01 03 00 00 00 06 c5 c8
uint8_t code send_cmd[]={0x01,0x03,0x00,0x00,0x00,0x06,0xc5,0xc8}; //查询所有数据
/*返回实例：01 03 0C 09 C4 1B 8F 1F 40 01 90 01 1E 00 00 96 A7 */
void RS485_coil()
{
		static uint32_t timer0_1=0, timer0_2=0;
		timer0_1 = get_sys_ticks();
		if((timer0_1 - timer0_2)>1000)  //每 30秒轮询一次
		{ 
		  /*执行函数*/
			Printf1(send_cmd,sizeof(send_cmd));
			/**/
			timer0_2 = get_sys_ticks(); 
		}
}
uint8_t code DAT[]  = "\"data\":{"; 
uint8_t code T[]  = "\"tmp\":";      //温度
uint8_t code PH[] = "\"PH\":";     // PH
uint8_t code DO[] = "\"DO\":";     //余氯
uint8_t code NTU[]= "\"NTU\":";    //浊度
uint8_t code GC[] = "\"GC\":";     //电导
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
					printf("%s","{");
					printf("\"devid\":\"WH%s\",",chip_ID);
					printf("%s",DAT);
				  printf("%s%.2f,",T,(float)(packet->data12[0]<<8|packet->data12[1])/100);
					printf("%s%.3f,",PH,(float)(packet->data12[2]<<8|packet->data12[3])/1000);
  				printf("%s%.3f,",DO,(float)(packet->data12[4]<<8|packet->data12[5])/1000);
					printf("%s%.2f,",NTU,(float)(packet->data12[6]<<8|packet->data12[7])/100); 
					printf("%s%d",GC,(int)(packet->data12[8]<<8|packet->data12[9]));
					printf("%s","}");
					printf("%s","}");
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