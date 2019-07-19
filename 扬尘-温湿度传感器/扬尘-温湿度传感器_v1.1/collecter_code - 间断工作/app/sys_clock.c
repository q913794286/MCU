//
// Created by anche on 2018/8/14.
//

#include "sys_clock.h"

#include <stc_timer.h>

data volatile uint16_t sys_ticks = 0;

void sys_clock_init(void) 
{
    TIM_InitTypeDef		TIM_InitStructure;					//
    TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
    TIM_InitStructure.TIM_Polity    = PolityHigh;			//指 PolityHigh,PolityLow
    TIM_InitStructure.TIM_Interrupt = ENABLE;				//,   ENABLE或DISABLE
    TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//指     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
    TIM_InitStructure.TIM_ClkOut    = DISABLE;				// ENABLE或DISABLE
    TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / (100UL * 12UL));		//初值,
    TIM_InitStructure.TIM_Run       = ENABLE;				// ENABLE或DISABLE
    Timer_Inilize(Timer0,&TIM_InitStructure);				//Timer0	  Timer0,Timer1,Timer2
}


uint16_t get_sys_ticks(void) 
{
    uint32_t ticks;
    TR0 = 0;
    ticks = sys_ticks;
    TR0 = 1;
    return ticks;
}

