
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "usart1.h"
#include "GPRS.h"
#include	"delay.h"

uint8_t code *AT   ="AT";
uint8_t code *GMM  ="AT+GMM";   		//获取型号
uint8_t code *CGSN ="AT+CGSN";  		//获取IME"
uint8_t code *ATF  ="AT&F";     		//设置所有 TA 参数为出厂配置
uint8_t code *ATW  ="AT&W";     		//保存用户配置参数
uint8_t code *CFUN ="AT+CFUN=1"; 		//设置模块功能
uint8_t code *ICF  ="AT+ICF=3,0";       // 数据位8 无奇偶校验 停止位1
uint8_t code *IPR  ="AT+IPR=115200";    // 波特率设置为115200
uint8_t code *CLCK ="AT+CLCK=SC,2";         //返回eer则卡不可用或无sim卡

uint8_t code *COPS ="AT+COPS?";         // 查看模式=0/1是能上网
uint8_t code *CREG1 ="AT+CREG=1";        //启用网络注册非请求结果码 	
uint8_t code *CREG2 ="AT+CREG?";			// 返回接货1,1网络注册成

uint8_t code *CSQ  ="AT+CSQ";           // 查询信号质量

uint8_t code *CGATT="AT+CGATT=1"; 		//GPRS分离"
uint8_t code *CCSTT ="AT+CSTT=\"cmnet\"";	 		//APN
uint8_t code *UCSTT ="AT+CSTT=3gnet";
uint8_t code *CGAUTO="AT+CGAUTO=1";    //自动响应网络请求 PDP PDP上
uint8_t code *CIFSR="AT+CIFSR";        //获取IP地址
uint8_t code *CIPMUX0 = "AT+CIPMUX=0";
uint8_t code *CIPMUX1 = "AT+CIPMUX=1";
uint8_t code *CGREG   = "AT+CGREG?";

uint8_t code *CIPSTART = "AT+CIPSTART=\"UDP\",\"139.159.141.194\",2249";   //建立 TCP/UDP链接

uint8_t code *CIPSEND = "AT+CIPSEND"; //发送命令
uint8_t code *CIPSHUT  = "AT+CIPSHUT";  //关闭 GPRS/CSD PDP场 
uint8_t code *CIICR    = "AT+CIICR";  //激活移动场景（或发起GPST/CSD无线链接）
uint8_t code *CIPSTATUS = "AT+CIPSTATUS";  //查询连接状态

uint8_t code *CDNSGIP = "AT+CDNSGIP=";	 //设置域名解析服务器
uint8_t code *DNSserver="8.8.8.8";		//DNS
uint8_t code *CIPMODE   ="AT+CIPMODE=1"; //进入透传模式；
void send_string(uint8_t *s)
{
  PrintString2(s);
}

void AT_Send(uint8_t *ATX)                                     //发送AT指令：sim卡机初始化   
{    
  (void)memset(RX2_Buffer,0,COM_RX2_Lenth);	//对接收数据缓冲区初始化        
  COM2.RX_Cnt=0;                                          
  send_string(ATX);   					 //发送AT命令
  send_string("\r\n");  
  delay_ms(500);                                 //延时1s，等待应答   
}


void init_GPRS()
{

	do{AT_Send(AT);
	  printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //确认模块正常	
	/*
	 *波特率设置
	*/
   /*

   	*模块及SIM卡检测
   */
	do {AT_Send(GMM);
	 printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //获取IME
	
	/*
	 *网络服务注册
	*/	
	do{ AT_Send(CLCK);
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //检测有无sim卡

	do{ AT_Send(COPS);
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //设置全功能模式(默认)
	/*
	 * GPRS服务注册
	*/
	if(!strstr(RX2_Buffer,"46000"))		//设置APN
	{								
		do{ AT_Send(CCSTT);
			printf("%s",RX2_Buffer);
		}while(!strstr(RX2_Buffer,"OK"));  //cmnet
	}
	if(!strstr(RX2_Buffer,"46001")){
		do{ AT_Send(UCSTT);
			printf("%s",RX2_Buffer);
		}while(!strstr(RX2_Buffer,"OK"));  //3gnet
	}

	/*
	 * TCP/IP 服务配置
	*/
	do{ AT_Send(CIICR);				   
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK"));	//激活场景							 	

	do{ AT_Send(CIPMODE);				   
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK"));  //进入透传模式

	do{ AT_Send(CIPMODE);				   
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK"));  //设置服务器地址										
}									  


void check_gprs()
{
  Power_OFF;
  os_wait2(K_SIG|K_IVL,200);
  Power_ON; 

}

