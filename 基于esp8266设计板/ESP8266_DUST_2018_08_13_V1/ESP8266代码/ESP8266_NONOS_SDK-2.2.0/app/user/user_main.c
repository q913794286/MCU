/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2016 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on ESPRESSIF SYSTEMS ESP8266 only, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "ets_sys.h"
#include "osapi.h"

#include "user_interface.h"
#include "driver/uart_register.h"
#include "driver/uart.h"
#include "key.h"
/******user***************/
#include "smart_config.h"
#include "user_dht.h"
#include "user_mqtt.h"
#include "my_json.h"
#include "uart.h"
#include "user_interface.h"
#include "mem.h"



/******************************************************************************
 * FunctionName : user_rf_cal_sector_set
 * Description  : SDK just reversed 4 sectors, used for rf init data and paramters.
 *                 We add this function to force users to set rf cal sector, since
 *                we don't know which sector is free in user's application.
 *                sector map for last several sectors : ABCCC
 *                A : rf cal
 *                B : rf init data
 *                C : sdk parameters
 * Parameters   : none
 * Returns      : rf cal sector
*******************************************************************************/
uint32 ICACHE_FLASH_ATTR
user_rf_cal_sector_set(void)
{
    enum flash_size_map size_map = system_get_flash_size_map();
    uint32 rf_cal_sec = 0;

    switch (size_map) {
        case FLASH_SIZE_4M_MAP_256_256:
            rf_cal_sec = 128 - 5;
            break;

        case FLASH_SIZE_8M_MAP_512_512:
            rf_cal_sec = 256 - 5;
            break;

        case FLASH_SIZE_16M_MAP_512_512:
        case FLASH_SIZE_16M_MAP_1024_1024:
            rf_cal_sec = 512 - 5;
            break;

        case FLASH_SIZE_32M_MAP_512_512:
        case FLASH_SIZE_32M_MAP_1024_1024:
            rf_cal_sec = 1024 - 5;
            break;

        case FLASH_SIZE_64M_MAP_1024_1024:
            rf_cal_sec = 2048 - 5;
            break;
        case FLASH_SIZE_128M_MAP_1024_1024:
            rf_cal_sec = 4096 - 5;
            break;
        default:
            rf_cal_sec = 0;
            break;
    }

    return rf_cal_sec;
}


static void Switch_ShortPress_Handler( void )
{
	os_printf("按键操作成功");
	int status;
    if( status == true )
    {
        status = false;
    }
    else
    {
        status = true;
    }
}


void ICACHE_FLASH_ATTR
user_rf_pre_init(void)
{
}



//********************************************************//

#define SIG_RX 0
#define TEST_QUEUE_LEN 4
os_event_t *testQueue;



void test_task (os_event_t *e)
{
  switch (e->sig){
  case 0:
	  os_printf("SDK:%c\n", e->par);
   break;
  case 1:

	  os_printf("实现第二个");
   break;
   default:
  break;
 }
}


void task_init(void) {
testQueue=(os_event_t *)os_malloc(sizeof(os_event_t)*TEST_QUEUE_LEN);
system_os_task(test_task,USER_TASK_PRIO_0,testQueue,TEST_QUEUE_LEN);
os_printf("任务创建成功");
}


void task_post(os_param_t *sh) {
	system_os_post(USER_TASK_PRIO_0, SIG_RX, 0);
}



//*****************************************//
static struct keys_param switch_param;
static struct single_key_param *switch_signle;
static bool status = true;

#define SWITCH_Pin_NUM         5
#define SWITCH_Pin_FUNC        FUNC_GPIO5
#define SWITCH_Pin_MUX         PERIPHS_IO_MUX_GPIO5_U



void ICACHE_FLASH_ATTR
user_init(void)
{

	 os_printf("SDK version:%s\n", system_get_sdk_version());

    uart_init(BIT_RATE_115200,BIT_RATE_115200);
    uart0_sendStr("\r\n初始化完成\r\n");


/*************key distribution network*****************************/
    switch_signle = key_init_single( SWITCH_Pin_NUM, SWITCH_Pin_MUX,
                                     SWITCH_Pin_FUNC,
									 NULL,
									 &smartconfig_init);
    switch_param.key_num = 1;
    switch_param.single_key = &switch_signle;
    key_init( &switch_param );

    // smartconfig_init();
    gpio_init_led();  //LED GPIO 初始化
    pwm_Init_led();   //LED pwm 初始化
/*********smart_config*********************************************/
     // task_init();   //创建任务
      udp_client_init();
     // tcp_client_init();
     // system_os_post(USER_TASK_PRIO_0, SIG_RX, 0);
     // system_soft_wdt_feed();//这里我们喂下看门狗  ，不让看门狗复位


/************json*****************************************************/





    //   setJsonTree(p);
/*******mqtt_***********************************************************/
//    mqtt_init();
/*******显示DHT11******************************************************/
//    Dis_DHT11();

//	os_timer_disarm(&printf_timer);	//启动定时器前先取消定时器定时
//	os_timer_setfn(&printf_timer, (os_timer_func_t *) prinfss,NULL);	//设置定时器回调函数
//	os_timer_arm(&printf_timer, 1000, 1);	//启动定时器
}


