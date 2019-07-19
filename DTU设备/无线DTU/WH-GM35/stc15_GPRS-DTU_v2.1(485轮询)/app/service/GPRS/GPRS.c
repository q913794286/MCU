
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "usart1.h"
#include "GPRS.h"
#include "delay.h"
#include "sys_clock.h"
#include "aes128app.h"
#include "mystring.h"

uint8_t code *AT   ="AT";
uint8_t code *GMM  ="AT+GMM";   		//获取型号
uint8_t code *CGSN ="AT+CGSN";  		//获取IME"
uint8_t code *ATF  ="AT&F";     		//设置所有 TA 参数为出厂配置
uint8_t code *ATW  ="AT&W";     		//保存用户配置参数
uint8_t code *CFUN ="AT+CFUN=1"; 		//设置模块功能
uint8_t code *ICF  ="AT+ICF=3,0";       // 数据位8 无奇偶校验 停止位1
uint8_t code *IPR  ="AT+IPR=115200";    // 波特率设置为115200
uint8_t code *CLCK ="AT+CLCK=SC,2";         //返回eer则卡不可用或无sim卡

uint8_t code *CPIN ="AT+CPIN?";

uint8_t code *COPS ="AT+COPS?";         // 查看模式=0/1是能上网
uint8_t code *CREG1 ="AT+CREG=1";        //启用网络注册非请求结果码 	
uint8_t code *CREG2 ="AT+CREG?";			// 返回接货1,1网络注册成

uint8_t code *CSQ  ="AT+CSQ";           // 查询信号质量
uint8_t code *CGREG="AT+CGREG?";
uint8_t code *CGATT="AT+CGATT=1"; 		//使用模块附着GPRS网络"
uint8_t code *CCSTT ="AT+CSTT=\"CMNET\"";	 		//APN
uint8_t code *UCSTT ="AT+CSTT=\"3gnet\"";
uint8_t code *CGAUTO="AT+CGAUTO=1";    //自动响应网络请求 PDP PDP上
uint8_t code *CIFSR="AT+CIFSR";        //获取IP地址
uint8_t code *CIPMUX0 = "AT+CIPMUX=0";
uint8_t code *CIPMUX1 = "AT+CIPMUX=1";

//uint8_t code *CIPSTART = "AT+CIPSTART=\"UDP\",\"139.159.141.194\",2249    ";   //建立 TCP/UDP链接
uint8_t code *CIPSTART = "AT+CIPSTART=" ;

uint8_t code *CIPSEND = "AT+CIPSEND"; //发送命令
uint8_t code *CIPSHUT  = "AT+CIPSHUT";  //关闭 GPRS/CSD PDP场 
uint8_t code *CIICR    = "AT+CIICR";  //激活移动场景（或发起GPST/CSD无线链接）
uint8_t code *CIPSTATUS = "AT+CIPSTATUS";  //查询连接状态

uint8_t code *CDNSGIP = "AT+CDNSGIP=";	 //设置域名解析服务器
uint8_t code *DNSserver="8.8.8.8";		//DNS
uint8_t code *CIPMODE   ="AT+CIPMODE=1"; //是否进入透传模式；
void send_string(uint8_t *s)
{
  while(*s != '\0') {
 	 TX2_write2buff(*s++);
 }
}

void AT_Send(uint8_t *ATX)                                     //发送AT指令：sim卡机初始化   
{    
  (void)memset(RX2_Buffer,0,COM_RX2_Lenth);	//对接收数据缓冲区初始化        
  COM2.RX_Cnt=0;                                          
  send_string(ATX);   					 //发送AT命令
  send_string("\r");  
  delay_ms(500);                                 //延时1s，等待应答   
}

u8 gprs_status;
u8 gprs_cmd(u8 *cmd, u8 *input, u8 *ck_str, u8 outtime_s)
{
	uint16_t tartt_time, second_time;
	uint8_t res=0;

  COM2.RX_Cnt = 0;
	tartt_time = get_sys_ticks();
	AT_Send(cmd);
	delay_ms(500);
	res=1;
	while(!strstr(input,ck_str)) //确认模块正常
	{   
		second_time	= get_sys_ticks();
		if(second_time%100==0)
		printf("T=%d\n",second_time/100);		
		if((second_time - tartt_time)>outtime_s) 
		{			
			return res=0; 
			break;
		} 		
	}//5s无应答跳出}
	COM2.RX_Cnt = 0;
	return 	res;
}

S_config s_config;
void init_GPRS(S_config *s)
{	
	uint8_t *addr;
	uint8_t res;
	/*建立AT命令链接，至少发送五次AT*/
	printf("AT_init\n");

	gprs_cmd(AT,RX2_Buffer,"OK",500);  //连续发送5次AT命令进入配置模式
  gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	printf("%s%s%s","AT5:",RX2_Buffer,"\n");
	/*
	 *波特率设置
	*/
	res = gprs_cmd(IPR,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","波特率:",RX2_Buffer,"\n");
	else
		printf("%s","波特率设置失败！");
   /*
   	*保存设置
   */
   gprs_cmd(ATW,RX2_Buffer,"OK",500);	
   /*
   	* 检测
   */
	res = gprs_cmd(CPIN,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","SIM状态:",RX2_Buffer,"\n");
	else
		printf("%s","SIM卡检测失败！");

	res = gprs_cmd(CSQ,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","信号强度:",RX2_Buffer,"\n");
	else
		printf("%s","无信号强度！");

	res = gprs_cmd(CREG2,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","GSM注册状态:",RX2_Buffer,"\n");
	else
		printf("%s","GSM卡注册失败！");
	
	res = gprs_cmd(CGREG,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","GPRS注册状态:",RX2_Buffer,"\n");
	else
		printf("%s","GPRS状态注册失败！");
	/*
	 *网络服务注册
	*/
	res = gprs_cmd(COPS,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","网络状态:",RX2_Buffer,"\n");
	else
		printf("%s","查询网络状态失败！");

	res = gprs_cmd(CIPMUX0,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","单服务器模式:",RX2_Buffer,"\n");
	else
		printf("%s","设置单服务模式失败！");

	/*
	 *使用模块附着GPRS网络
	*/
	res = gprs_cmd(CGATT,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","GPRS附着:",RX2_Buffer,"\n");
	else
		printf("%s","GPRS附着失败！");
	/*
	 * GPRS服务注册
	*/
	res = gprs_cmd(COPS,RX2_Buffer,"OK",500); //查询当前运行商编号
	if(res==1)
		printf("%s%s%s","运行商:",RX2_Buffer,"\n");
	else 
		printf("%s","读取运行商失败！");

	res = gprs_cmd(CIPMODE,RX2_Buffer,"OK",500);	//入透传模式；
	if(res==1)
		printf("%s%s%s","入透传模式:",RX2_Buffer,"\n");
	else
		printf("%s","进入透传失败！");

	if(!strstr(RX2_Buffer,"46000"))		//设置APN
	{	
		gprs_cmd(CCSTT,RX2_Buffer,"OK",500);
		printf("%s%s%s","CMNET:",RX2_Buffer,"\n");							
	}
	else if(!strstr(RX2_Buffer,"46001")){
		gprs_cmd(UCSTT,RX2_Buffer,"OK",500);
		printf("%s%s%s","3GNET:",RX2_Buffer,"\n");
	}
	/*
	 * TCP/IP 服务配置
	*/


	res = gprs_cmd(CIICR,RX2_Buffer,"OK",500);  // 激活移动场景（或发起GPST/CSD无线链接）
	if(res==1)
		printf("%s%s%s","激活移动场景:",RX2_Buffer,"\n");
	else
		printf("%s","激活移动场景失败！");						 	
	
	res = gprs_cmd(CIFSR,RX2_Buffer,"OK",500);		//获取IP地址
//	if(res==1)
		printf("%s%s%s","获取IP地址:",RX2_Buffer,"\n");
//	else
//		printf("%s","获取IP失败！");
	
	strcat(addr,CIPSTART);
	strcat(addr,s->server);
//	trim(addr, p1);
//	sprintf(addr,"%s%s",CIPSTART,s->server);
	printf("server=%s\r\n",addr);
	gprs_status = gprs_cmd(addr, RX2_Buffer, "CONNECT", 1000);		   //服务器连接成功
	if(gprs_status==1)
		printf("%s%s%s","连接服务器:",RX2_Buffer,"\n");
	else
		printf("%s","链接服务器失败！");		
								
}									  



