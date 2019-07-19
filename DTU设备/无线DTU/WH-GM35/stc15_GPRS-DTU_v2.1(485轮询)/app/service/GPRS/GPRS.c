
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
uint8_t code *GMM  ="AT+GMM";   		//��ȡ�ͺ�
uint8_t code *CGSN ="AT+CGSN";  		//��ȡIME"
uint8_t code *ATF  ="AT&F";     		//�������� TA ����Ϊ��������
uint8_t code *ATW  ="AT&W";     		//�����û����ò���
uint8_t code *CFUN ="AT+CFUN=1"; 		//����ģ�鹦��
uint8_t code *ICF  ="AT+ICF=3,0";       // ����λ8 ����żУ�� ֹͣλ1
uint8_t code *IPR  ="AT+IPR=115200";    // ����������Ϊ115200
uint8_t code *CLCK ="AT+CLCK=SC,2";         //����eer�򿨲����û���sim��

uint8_t code *CPIN ="AT+CPIN?";

uint8_t code *COPS ="AT+COPS?";         // �鿴ģʽ=0/1��������
uint8_t code *CREG1 ="AT+CREG=1";        //��������ע����������� 	
uint8_t code *CREG2 ="AT+CREG?";			// ���ؽӻ�1,1����ע���

uint8_t code *CSQ  ="AT+CSQ";           // ��ѯ�ź�����
uint8_t code *CGREG="AT+CGREG?";
uint8_t code *CGATT="AT+CGATT=1"; 		//ʹ��ģ�鸽��GPRS����"
uint8_t code *CCSTT ="AT+CSTT=\"CMNET\"";	 		//APN
uint8_t code *UCSTT ="AT+CSTT=\"3gnet\"";
uint8_t code *CGAUTO="AT+CGAUTO=1";    //�Զ���Ӧ�������� PDP PDP��
uint8_t code *CIFSR="AT+CIFSR";        //��ȡIP��ַ
uint8_t code *CIPMUX0 = "AT+CIPMUX=0";
uint8_t code *CIPMUX1 = "AT+CIPMUX=1";

//uint8_t code *CIPSTART = "AT+CIPSTART=\"UDP\",\"139.159.141.194\",2249    ";   //���� TCP/UDP����
uint8_t code *CIPSTART = "AT+CIPSTART=" ;

uint8_t code *CIPSEND = "AT+CIPSEND"; //��������
uint8_t code *CIPSHUT  = "AT+CIPSHUT";  //�ر� GPRS/CSD PDP�� 
uint8_t code *CIICR    = "AT+CIICR";  //�����ƶ�����������GPST/CSD�������ӣ�
uint8_t code *CIPSTATUS = "AT+CIPSTATUS";  //��ѯ����״̬

uint8_t code *CDNSGIP = "AT+CDNSGIP=";	 //������������������
uint8_t code *DNSserver="8.8.8.8";		//DNS
uint8_t code *CIPMODE   ="AT+CIPMODE=1"; //�Ƿ����͸��ģʽ��
void send_string(uint8_t *s)
{
  while(*s != '\0') {
 	 TX2_write2buff(*s++);
 }
}

void AT_Send(uint8_t *ATX)                                     //����ATָ�sim������ʼ��   
{    
  (void)memset(RX2_Buffer,0,COM_RX2_Lenth);	//�Խ������ݻ�������ʼ��        
  COM2.RX_Cnt=0;                                          
  send_string(ATX);   					 //����AT����
  send_string("\r");  
  delay_ms(500);                                 //��ʱ1s���ȴ�Ӧ��   
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
	while(!strstr(input,ck_str)) //ȷ��ģ������
	{   
		second_time	= get_sys_ticks();
		if(second_time%100==0)
		printf("T=%d\n",second_time/100);		
		if((second_time - tartt_time)>outtime_s) 
		{			
			return res=0; 
			break;
		} 		
	}//5s��Ӧ������}
	COM2.RX_Cnt = 0;
	return 	res;
}

S_config s_config;
void init_GPRS(S_config *s)
{	
	uint8_t *addr;
	uint8_t res;
	/*����AT�������ӣ����ٷ������AT*/
	printf("AT_init\n");

	gprs_cmd(AT,RX2_Buffer,"OK",500);  //��������5��AT�����������ģʽ
  gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	gprs_cmd(AT,RX2_Buffer,"OK",500);
	printf("%s%s%s","AT5:",RX2_Buffer,"\n");
	/*
	 *����������
	*/
	res = gprs_cmd(IPR,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","������:",RX2_Buffer,"\n");
	else
		printf("%s","����������ʧ�ܣ�");
   /*
   	*��������
   */
   gprs_cmd(ATW,RX2_Buffer,"OK",500);	
   /*
   	* ���
   */
	res = gprs_cmd(CPIN,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","SIM״̬:",RX2_Buffer,"\n");
	else
		printf("%s","SIM�����ʧ�ܣ�");

	res = gprs_cmd(CSQ,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","�ź�ǿ��:",RX2_Buffer,"\n");
	else
		printf("%s","���ź�ǿ�ȣ�");

	res = gprs_cmd(CREG2,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","GSMע��״̬:",RX2_Buffer,"\n");
	else
		printf("%s","GSM��ע��ʧ�ܣ�");
	
	res = gprs_cmd(CGREG,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","GPRSע��״̬:",RX2_Buffer,"\n");
	else
		printf("%s","GPRS״̬ע��ʧ�ܣ�");
	/*
	 *�������ע��
	*/
	res = gprs_cmd(COPS,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","����״̬:",RX2_Buffer,"\n");
	else
		printf("%s","��ѯ����״̬ʧ�ܣ�");

	res = gprs_cmd(CIPMUX0,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","��������ģʽ:",RX2_Buffer,"\n");
	else
		printf("%s","���õ�����ģʽʧ�ܣ�");

	/*
	 *ʹ��ģ�鸽��GPRS����
	*/
	res = gprs_cmd(CGATT,RX2_Buffer,"OK",500);
	if(res==1)
		printf("%s%s%s","GPRS����:",RX2_Buffer,"\n");
	else
		printf("%s","GPRS����ʧ�ܣ�");
	/*
	 * GPRS����ע��
	*/
	res = gprs_cmd(COPS,RX2_Buffer,"OK",500); //��ѯ��ǰ�����̱��
	if(res==1)
		printf("%s%s%s","������:",RX2_Buffer,"\n");
	else 
		printf("%s","��ȡ������ʧ�ܣ�");

	res = gprs_cmd(CIPMODE,RX2_Buffer,"OK",500);	//��͸��ģʽ��
	if(res==1)
		printf("%s%s%s","��͸��ģʽ:",RX2_Buffer,"\n");
	else
		printf("%s","����͸��ʧ�ܣ�");

	if(!strstr(RX2_Buffer,"46000"))		//����APN
	{	
		gprs_cmd(CCSTT,RX2_Buffer,"OK",500);
		printf("%s%s%s","CMNET:",RX2_Buffer,"\n");							
	}
	else if(!strstr(RX2_Buffer,"46001")){
		gprs_cmd(UCSTT,RX2_Buffer,"OK",500);
		printf("%s%s%s","3GNET:",RX2_Buffer,"\n");
	}
	/*
	 * TCP/IP ��������
	*/


	res = gprs_cmd(CIICR,RX2_Buffer,"OK",500);  // �����ƶ�����������GPST/CSD�������ӣ�
	if(res==1)
		printf("%s%s%s","�����ƶ�����:",RX2_Buffer,"\n");
	else
		printf("%s","�����ƶ�����ʧ�ܣ�");						 	
	
	res = gprs_cmd(CIFSR,RX2_Buffer,"OK",500);		//��ȡIP��ַ
//	if(res==1)
		printf("%s%s%s","��ȡIP��ַ:",RX2_Buffer,"\n");
//	else
//		printf("%s","��ȡIPʧ�ܣ�");
	
	strcat(addr,CIPSTART);
	strcat(addr,s->server);
//	trim(addr, p1);
//	sprintf(addr,"%s%s",CIPSTART,s->server);
	printf("server=%s\r\n",addr);
	gprs_status = gprs_cmd(addr, RX2_Buffer, "CONNECT", 1000);		   //���������ӳɹ�
	if(gprs_status==1)
		printf("%s%s%s","���ӷ�����:",RX2_Buffer,"\n");
	else
		printf("%s","���ӷ�����ʧ�ܣ�");		
								
}									  



