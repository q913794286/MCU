#include "ets_sys.h"
#include "user_interface.h"
#include "os_type.h"
#include "osapi.h"
#include "pwm.h"
#include "gpio.h"



#define PERIOD   8000   //周期    200HZ

#define RGB555(X)  (int)((X*1000*PERIOD)/(255*45))




void ICACHE_FLASH_ATTR
gpio_init_led(void)
{
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_GPIO12);  //设置输出模式
	//gpio_output_set(0, BIT12, BIT12, 0);      //设置输出低电平
	gpio_output_set(BIT12, 0, BIT12, 0);      //设置输出高电平
	//GPIO_OUTPUT_SET(12,1);

	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_GPIO15);  //设置输出模式
	//gpio_output_set(0, BIT15, BIT15, 0);      //设置输出低电平
	gpio_output_set(BIT15, 0, BIT15, 0);      //设置输出高电平
	//GPIO_OUTPUT_SET(15,1);

	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_GPIO13);  //设置输出模式
	//gpio_output_set(0, BIT13, BIT13, 0);      //设置输出低电平
	gpio_output_set(BIT13, 0, BIT13, 0);      //设置输出高电平
	//GPIO_OUTPUT_SET(13,1);

}



void PWM_RGB555(char R,char G, char B )
{

    pwm_set_duty(RGB555(R),1);  // red
	pwm_set_duty(RGB555(G),0);  //green
	pwm_set_duty(RGB555(B),2);  //blue
	pwm_start();
}






void ICACHE_FLASH_ATTR
pwm_Init_led(void)
{



	uint32 io_info[3][3]={
			{PERIPHS_IO_MUX_MTDI_U,FUNC_GPIO12,12},
			{PERIPHS_IO_MUX_MTDO_U,FUNC_GPIO15,15},
			{PERIPHS_IO_MUX_MTCK_U,FUNC_GPIO13,13},
	   };

	uint32 pwm_duty_init[3]={0};

    pwm_init(PERIOD,pwm_duty_init,3,io_info);
    PWM_RGB555(0,0,0);
    //设置 PWM 某个通道信号的占空比, duty 占空比的值, type当前要设置的PWM通道
   // pwm_set_duty(2222,2);

    //设置完成后，需要调用 pwm_start,PWM 开始
  //  pwm_start();
  //  os_printf("\r\npwm初始化\r\n");
}







void ICACHE_FLASH_ATTR
udp_gpio_led(char *dta,unsigned short len)
{



	PWM_RGB555(0,0,0);

	PWM_RGB555(dta[0],dta[1],dta[2]);

	os_printf("接收数据：%x", dta);

}


/*
 * function: user_gpio_timer_init
 * description:
 */
void ICACHE_FLASH_ATTR
user_gpio_timer_init(void) {

	 //static  os_timer_t gpio_timer;

// 管脚功能选择

	//os_timer_disarm(&gpio_timer);
	//os_timer_setfn(&gpio_timer, (os_timer_func_t *) display, NULL);
	//os_timer_arm(&gpio_timer, 1000, 0);

	//os_printf("user_gpio_timer_init\r\n");

}











