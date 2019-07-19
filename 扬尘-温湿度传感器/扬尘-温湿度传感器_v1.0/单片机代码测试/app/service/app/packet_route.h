#ifndef __packet_rout_h
#define __packet_rout_h
#include "config.h"


#define TERM_START_FLAG1 0xc3
#define TERM_START_FLAG2 0x3c
#define TERM_END_FLAG 0XE7

#define TERM_PACKET_MIN_SIZE 6

typedef struct {

    uint8_t flag1;
    uint8_t addr;
    uint8_t flag2;
    uint8_t cmd;
    uint8_t data_size;
    uint8_t dat[1];

} term_packet_head_t;

void router_uart_isr(uint8_t byte);
void term_process();
void router_uart_write(uint8_t *src, uint16_t length);

#endif