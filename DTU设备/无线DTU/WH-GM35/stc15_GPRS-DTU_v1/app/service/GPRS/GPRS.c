
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "usart1.h"
#include "GPRS.h"
#include	"delay.h"

uint8_t code *AT   ="AT";
uint8_t code *GMM  ="AT+GMM";   		//��ȡ�ͺ�
uint8_t code *CGSN ="AT+CGSN";  		//��ȡIME"
uint8_t code *ATF  ="AT&F";     		//�������� TA ����Ϊ��������
uint8_t code *ATW  ="AT&W";     		//�����û����ò���
uint8_t code *CFUN ="AT+CFUN=1"; 		//����ģ�鹦��
uint8_t code *ICF  ="AT+ICF=3,0";       // ����λ8 ����żУ�� ֹͣλ1
uint8_t code *IPR  ="AT+IPR=115200";    // ����������Ϊ115200
uint8_t code *CLCK ="AT+CLCK=SC,2";         //����eer�򿨲����û���sim��

uint8_t code *COPS ="AT+COPS?";         // �鿴ģʽ=0/1��������
uint8_t code *CREG1 ="AT+CREG=1";        //��������ע����������� 	
uint8_t code *CREG2 ="AT+CREG?";			// ���ؽӻ�1,1����ע���

uint8_t code *CSQ  ="AT+CSQ";           // ��ѯ�ź�����

uint8_t code *CGATT="AT+CGATT=1"; 		//GPRS����"
uint8_t code *CCSTT ="AT+CSTT=\"cmnet\"";	 		//APN
uint8_t code *UCSTT ="AT+CSTT=3gnet";
uint8_t code *CGAUTO="AT+CGAUTO=1";    //�Զ���Ӧ�������� PDP PDP��
uint8_t code *CIFSR="AT+CIFSR";        //��ȡIP��ַ
uint8_t code *CIPMUX0 = "AT+CIPMUX=0";
uint8_t code *CIPMUX1 = "AT+CIPMUX=1";
uint8_t code *CGREG   = "AT+CGREG?";

uint8_t code *CIPSTART = "AT+CIPSTART=\"UDP\",\"139.159.141.194\",2249";   //���� TCP/UDP����

uint8_t code *CIPSEND = "AT+CIPSEND"; //��������
uint8_t code *CIPSHUT  = "AT+CIPSHUT";  //�ر� GPRS/CSD PDP�� 
uint8_t code *CIICR    = "AT+CIICR";  //�����ƶ�����������GPST/CSD�������ӣ�
uint8_t code *CIPSTATUS = "AT+CIPSTATUS";  //��ѯ����״̬

uint8_t code *CDNSGIP = "AT+CDNSGIP=";	 //������������������
uint8_t code *DNSserver="8.8.8.8";		//DNS
uint8_t code *CIPMODE   ="AT+CIPMODE=1"; //����͸��ģʽ��
void send_string(uint8_t *s)
{
  PrintString2(s);
}

void AT_Send(uint8_t *ATX)                                     //����ATָ�sim������ʼ��   
{    
  (void)memset(RX2_Buffer,0,COM_RX2_Lenth);	//�Խ������ݻ�������ʼ��        
  COM2.RX_Cnt=0;                                          
  send_string(ATX);   					 //����AT����
  send_string("\r\n");  
  delay_ms(500);                                 //��ʱ1s���ȴ�Ӧ��   
}


void init_GPRS()
{

	do{AT_Send(AT);
	  printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //ȷ��ģ������	
	/*
	 *����������
	*/
   /*

   	*ģ�鼰SIM�����
   */
	do {AT_Send(GMM);
	 printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //��ȡIME
	
	/*
	 *�������ע��
	*/	
	do{ AT_Send(CLCK);
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //�������sim��

	do{ AT_Send(COPS);
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK")); //����ȫ����ģʽ(Ĭ��)
	/*
	 * GPRS����ע��
	*/
	if(!strstr(RX2_Buffer,"46000"))		//����APN
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
	 * TCP/IP ��������
	*/
	do{ AT_Send(CIICR);				   
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK"));	//�����							 	

	do{ AT_Send(CIPMODE);				   
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK"));  //����͸��ģʽ

	do{ AT_Send(CIPMODE);				   
		printf("%s",RX2_Buffer);
	}while(!strstr(RX2_Buffer,"OK"));  //���÷�������ַ										
}									  


void check_gprs()
{
  Power_OFF;
  os_wait2(K_SIG|K_IVL,200);
  Power_ON; 

}

