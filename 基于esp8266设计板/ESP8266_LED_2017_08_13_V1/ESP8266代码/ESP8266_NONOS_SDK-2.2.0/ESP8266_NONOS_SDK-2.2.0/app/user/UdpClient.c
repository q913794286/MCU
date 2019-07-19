
#include "driver/uart.h"  //����0��Ҫ��ͷ�ļ�
#include "osapi.h"  //����1��Ҫ��ͷ�ļ�
#include "user_interface.h" //WIFI������Ҫ��ͷ�ļ�
#include "espconn.h"//TCP������Ҫ��ͷ�ļ�
#include "mem.h" //ϵͳ������Ҫ��ͷ�ļ�
#include "my_json.h"
#include "os_type.h"



struct espconn user_udp_espconn;
os_timer_t checkTimer_wifistate;





//������ʽ
void ICACHE_FLASH_ATTR
udp_unicast_signal(void)
{
	user_udp_espconn.proto.udp = (esp_udp *) os_zalloc(sizeof(esp_udp));
	user_udp_espconn.type = ESPCONN_UDP;
	user_udp_espconn.proto.udp->local_port = 9898;  //���ض˿�
	user_udp_espconn.proto.udp->remote_port = 4321; //Ŀ��˿�
	const char udp_remote_ip[4] = { 192, 168, 1, 80 };
	os_memcpy(user_udp_espconn.proto.udp->remote_ip, udp_remote_ip, 4);

}


//�㲥��ʽ
void ICACHE_FLASH_ATTR
udp_communit_signal(void)
{
	user_udp_espconn.proto.udp = (esp_udp *) os_zalloc(sizeof(esp_udp));
	user_udp_espconn.type = ESPCONN_UDP;
	user_udp_espconn.proto.udp->local_port = 9898;  //���ض˿�
	user_udp_espconn.proto.udp->remote_port = 4321; //Ŀ��˿�
	const char udp_remote_ip[4] = { 255, 255, 255, 255 };
	os_memcpy(user_udp_espconn.proto.udp->remote_ip, udp_remote_ip, 4);
}




//�����ಥ��
void ICACHE_FLASH_ATTR
udp_Multicast_group(void)
{

	user_udp_espconn.proto.udp->local_port = 9898;	 		  //���ض˿�
    user_udp_espconn.proto.udp->remote_port = 4321;	 		  //Ŀ��˿�

    ip_addr_t udp_remote_ip[4] = {0};	 	//Ŀ��IP��ַ���㲥��
 	ip_addr_t udp_multicast_ip[4] = {224, 0, 0, 50 };	 	//Ŀ��IP��ַ���㲥��

    struct ip_info ipConfig;
	wifi_get_ip_info(STATION_IF, &ipConfig);   //�鿴��ǰ����IP
	os_memcpy(udp_remote_ip, &ipConfig.ip, 4);

    uint8  erov = espconn_igmp_join(udp_remote_ip,udp_multicast_ip);
    if(erov == 0)
      {
        os_printf("����ಥ��ɹ�");
       }
    else
      {
        os_printf("����ಥ��ʧ��");
       }
}



void ICACHE_FLASH_ATTR
user_udp_sent_cb(void *arg)   //����
{

	os_printf("\r\n���ͳɹ���\r\n");

}


void ICACHE_FLASH_ATTR
user_udp_recv_cb(void *arg, char *pdata, unsigned short len) //����
{


	//os_printf("�������ݣ�%s", pdata);

	 udp_gpio_led(pdata, len);


	  char *p = getJsonTree();

     os_printf("%s\n", p);

	//ÿ�η�������ȷ����������
	//udp_unicast_signal();     //UDP unicast communication
 	udp_communit_signal();   //UDP communication
	//udp_Multicast_group();   // UDP Multicast group communication

    //espconn_sent((struct espconn *) arg, pdata, len); //��������

  //  espconn_sent((struct espconn *) arg, "�Ѿ��յ�����", strlen("�Ѿ��յ���!")); //��������

}





void Check_WifiState_UDP(void) {

	uint8 getState = wifi_station_get_connect_status();

	//���״̬��ȷ��֤���Ѿ�����
	if (getState == STATION_GOT_IP) {

		os_printf("WIFI���ӳɹ���");
		//os_timer_disarm(&checkTimer_wifistate);   //����ʱ�Ͽ��˴����ܲ�ͣ�ķ�����		wifi_set_broadcast_if(0x01);	 //���� ESP8266 ���� UDP�㲥��ʱ���� station �ӿڷ���
		user_udp_espconn.proto.udp = (esp_udp *) os_zalloc(sizeof(esp_udp));//����ռ�
		user_udp_espconn.type = ESPCONN_UDP;	 		  //��������ΪUDPЭ��

		//udp_unicast_signal();   //UDP unicast communication
		udp_communit_signal();   //UDP communication
		//udp_Multicast_group();   // UDP Multicast group communication


		espconn_regist_recvcb(&user_udp_espconn, user_udp_recv_cb);	 		//����
	//	espconn_regist_sentcb(&user_udp_espconn, user_udp_sent_cb);	 		//����
		espconn_create(&user_udp_espconn);	 		  //���� UDP ����


		espconn_sent(&user_udp_espconn, "���ӵ���������", strlen("���ӵ�������")); //��������

	}
}





void udp_client_init() //��ʼ��
{
//	wifi_set_opmode(0x01); //����ΪSTATIONģʽ
//	struct station_config stationConf;
//	os_strcpy(stationConf.ssid, "meizu");	  //�ĳ���Ҫ���ӵ� ·�������û���
//	os_strcpy(stationConf.password, "12345678"); //�ĳ���Ҫ���ӵ�·����������
//	wifi_station_set_config(&stationConf);	  //����WiFi station�ӿ����ã������浽 flash
//	wifi_station_connect();	  //����·����

	os_timer_disarm(&checkTimer_wifistate);	  //ȡ����ʱ����ʱ
	os_timer_setfn(&checkTimer_wifistate, (os_timer_func_t *) Check_WifiState_UDP,
	NULL);	  //���ö�ʱ���ص�����
	os_timer_arm(&checkTimer_wifistate, 10000, 1);	  //������ʱ������λ������

}



