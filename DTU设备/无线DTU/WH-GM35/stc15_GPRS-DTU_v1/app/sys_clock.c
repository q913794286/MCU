//
// Created by anche on 2018/8/14.
//

#include "sys_clock.h"

#include <stc_timer.h>

data volatile uint16_t sys_ticks = 0;

//void sys_clock_init(void) 
//{
//    TIM_InitTypeDef		TIM_InitStructure;					//�ṹ����
//    TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//ָ������ģʽ,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
//    TIM_InitStructure.TIM_Polity    = PolityHigh;			//ָ���ж����ȼ�, PolityHigh,PolityLow
//    TIM_InitStructure.TIM_Interrupt = ENABLE;				//�ж��Ƿ�����,   ENABLE��DISABLE
//    TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//ָ��ʱ��Դ,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
//    TIM_InitStructure.TIM_ClkOut    = DISABLE;				//�Ƿ������������, ENABLE��DISABLE
//    TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / (100UL * 12UL));		//��ֵ,
//    TIM_InitStructure.TIM_Run       = ENABLE;				//�Ƿ��ʼ����������ʱ��, ENABLE��DISABLE
//    Timer_Inilize(Timer0,&TIM_InitStructure);				//��ʼ��Timer0	  Timer0,Timer1,Timer2
//}


uint16_t get_sys_ticks(void) 
{
    uint32_t ticks;
 //   TR0 = 0;
    ticks = sys_ticks;
 //   TR0 = 1;
    return ticks;
}
