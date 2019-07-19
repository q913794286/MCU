
#include "driver/uart.h"  //串口0需要的头文件
#include "osapi.h"  //串口1需要的头文件
#include "user_interface.h" //WIFI连接需要的头文件
#include "espconn.h"//TCP连接需要的头文件
#include "mem.h" //系统操作需要的头文件
#include "my_json.h"
#include "os_type.h"



struct espconn user_udp_espconn;
os_timer_t checkTimer_wifistate;





//单播方式
void ICACHE_FLASH_ATTR
udp_unicast_signal(void)
{
	user_udp_espconn.proto.udp = (esp_udp *) os_zalloc(sizeof(esp_udp));
	user_udp_espconn.type = ESPCONN_UDP;
	user_udp_espconn.proto.udp->local_port = 9898;  //本地端口
	user_udp_espconn.proto.udp->remote_port = 4321; //目标端口
	const char udp_remote_ip[4] = { 192, 168, 1, 80 };
	os_memcpy(user_udp_espconn.proto.udp->remote_ip, udp_remote_ip, 4);

}


//广播方式
void ICACHE_FLASH_ATTR
udp_communit_signal(void)
{
	user_udp_espconn.proto.udp = (esp_udp *) os_zalloc(sizeof(esp_udp));
	user_udp_espconn.type = ESPCONN_UDP;
	user_udp_espconn.proto.udp->local_port = 9898;  //本地端口
	user_udp_espconn.proto.udp->remote_port = 4321; //目标端口
	const char udp_remote_ip[4] = { 255, 255, 255, 255 };
	os_memcpy(user_udp_espconn.proto.udp->remote_ip, udp_remote_ip, 4);
}




//创建多播组
void ICACHE_FLASH_ATTR
udp_Multicast_group(void)
{

	user_udp_espconn.proto.udp->local_port = 9898;	 		  //本地端口
    user_udp_espconn.proto.udp->remote_port = 4321;	 		  //目标端口

    ip_addr_t udp_remote_ip[4] = {0};	 	//目标IP地址（广播）
 	ip_addr_t udp_multicast_ip[4] = {224, 0, 0, 50 };	 	//目标IP地址（广播）

    struct ip_info ipConfig;
	wifi_get_ip_info(STATION_IF, &ipConfig);   //查看当前本届IP
	os_memcpy(udp_remote_ip, &ipConfig.ip, 4);

    uint8  erov = espconn_igmp_join(udp_remote_ip,udp_multicast_ip);
    if(erov == 0)
      {
        os_printf("加入多播组成功");
       }
    else
      {
        os_printf("加入多播组失败");
       }
}



void ICACHE_FLASH_ATTR
user_udp_sent_cb(void *arg)   //发送
{

	os_printf("\r\n发送成功！\r\n");

}


void ICACHE_FLASH_ATTR
user_udp_recv_cb(void *arg, char *pdata, unsigned short len) //接收
{


	//os_printf("接收数据：%s", pdata);

	 udp_gpio_led(pdata, len);


	  char *p = getJsonTree();

     os_printf("%s\n", p);

	//每次发送数据确保参数不变
	//udp_unicast_signal();     //UDP unicast communication
 	udp_communit_signal();   //UDP communication
	//udp_Multicast_group();   // UDP Multicast group communication

    //espconn_sent((struct espconn *) arg, pdata, len); //发送数据

  //  espconn_sent((struct espconn *) arg, "已经收到啦！", strlen("已经收到啦!")); //发送数据

}





void Check_WifiState_UDP(void) {

	uint8 getState = wifi_station_get_connect_status();

	//如果状态正确，证明已经连接
	if (getState == STATION_GOT_IP) {

		os_printf("WIFI连接成功！");
		//os_timer_disarm(&checkTimer_wifistate);   //测试时断开此处就能不停的发数据		wifi_set_broadcast_if(0x01);	 //设置 ESP8266 发送 UDP广播包时，从 station 接口发送
		user_udp_espconn.proto.udp = (esp_udp *) os_zalloc(sizeof(esp_udp));//分配空间
		user_udp_espconn.type = ESPCONN_UDP;	 		  //设置类型为UDP协议

		//udp_unicast_signal();   //UDP unicast communication
		udp_communit_signal();   //UDP communication
		//udp_Multicast_group();   // UDP Multicast group communication


		espconn_regist_recvcb(&user_udp_espconn, user_udp_recv_cb);	 		//接收
	//	espconn_regist_sentcb(&user_udp_espconn, user_udp_sent_cb);	 		//发送
		espconn_create(&user_udp_espconn);	 		  //建立 UDP 传输


		espconn_sent(&user_udp_espconn, "连接到服务器！", strlen("连接到服务器")); //发送数据

	}
}





void udp_client_init() //初始化
{
//	wifi_set_opmode(0x01); //设置为STATION模式
//	struct station_config stationConf;
//	os_strcpy(stationConf.ssid, "meizu");	  //改成你要连接的 路由器的用户名
//	os_strcpy(stationConf.password, "12345678"); //改成你要连接的路由器的密码
//	wifi_station_set_config(&stationConf);	  //设置WiFi station接口配置，并保存到 flash
//	wifi_station_connect();	  //连接路由器

	os_timer_disarm(&checkTimer_wifistate);	  //取消定时器定时
	os_timer_setfn(&checkTimer_wifistate, (os_timer_func_t *) Check_WifiState_UDP,
	NULL);	  //设置定时器回调函数
	os_timer_arm(&checkTimer_wifistate, 10000, 1);	  //启动定时器，单位：毫秒

}



