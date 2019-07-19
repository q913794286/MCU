
// Created by anche on 2018/8/14.
//

#ifndef _SYS_CLOCK__H
#define _SYS_CLOCK__H

#include "config.h"
#include <stdint.h>

typedef struct{
    u16 ms;
    u16 start;
//    u16 end;
}timer_out;

extern timer_out timerout1, timerout2;

extern data volatile uint16_t sys_ticks;




extern void sys_clock_init(void);
extern uint16_t get_sys_ticks(void);

#endif //_SYS_CLOCK_H
