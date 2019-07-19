#include "ets_sys.h"
#include "user_interface.h"
#include "os_type.h"
#include "osapi.h"
#include "pwm.h"
#include "gpio.h"



#define PERIOD   8000   //����    200HZ

#define RGB555(X)  (int)((X*1000*PERIOD)/(255*45))




void ICACHE_FLASH_ATTR
gpio_init_led(void)
{
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_GPIO12);  //�������ģʽ
	//gpio_output_set(0, BIT12, BIT12, 0);      //��������͵�ƽ
	gpio_output_set(BIT12, 0, BIT12, 0);      //��������ߵ�ƽ
	//GPIO_OUTPUT_SET(12,1);

	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_GPIO15);  //�������ģʽ
	//gpio_output_set(0, BIT15, BIT15, 0);      //��������͵�ƽ
	gpio_output_set(BIT15, 0, BIT15, 0);      //��������ߵ�ƽ
	//GPIO_OUTPUT_SET(15,1);

	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_GPIO13);  //�������ģʽ
	//gpio_output_set(0, BIT13, BIT13, 0);      //��������͵�ƽ
	gpio_output_set(BIT13, 0, BIT13, 0);      //��������ߵ�ƽ
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
    //���� PWM ĳ��ͨ���źŵ�ռ�ձ�, duty ռ�ձȵ�ֵ, type��ǰҪ���õ�PWMͨ��
   // pwm_set_duty(2222,2);

    //������ɺ���Ҫ���� pwm_start,PWM ��ʼ
  //  pwm_start();
  //  os_printf("\r\npwm��ʼ��\r\n");
}







void ICACHE_FLASH_ATTR
udp_gpio_led(char *dta,unsigned short len)
{



	PWM_RGB555(0,0,0);

	PWM_RGB555(dta[0],dta[1],dta[2]);

	os_printf("�������ݣ�%x", dta);

}


/*
 * function: user_gpio_timer_init
 * description:
 */
void ICACHE_FLASH_ATTR
user_gpio_timer_init(void) {

	 //static  os_timer_t gpio_timer;

// �ܽŹ���ѡ��

	//os_timer_disarm(&gpio_timer);
	//os_timer_setfn(&gpio_timer, (os_timer_func_t *) display, NULL);
	//os_timer_arm(&gpio_timer, 1000, 0);

	//os_printf("user_gpio_timer_init\r\n");

}











