#ifndef __packet_dust_h
#define __packet_dust_h
#include "config.h"

struct frame{
    uint8_t head1;
    uint8_t head2;
    uint16_t len;
    uint16_t data1;
    uint16_t data2;
    uint16_t data3;
    uint16_t data4;
    uint16_t data5;
    uint16_t data6;
    uint16_t data7;
	uint16_t data8;
    uint16_t data9;
    uint16_t data10;
    uint16_t data11;
    uint16_t data12;
};

extern uint16_t data_temp;
extern uint16_t data_airhum;
extern uint16_t data_pm251;
extern uint16_t data_pm252;
extern uint16_t data_pm101;
extern uint16_t data_pm102;

uint16_t get_dustvo(uint16_t *buf);
void dust_uart_isr(uint8_t byte);
void cfg_uart_write(uint8_t *src, uint16_t length);

#endif