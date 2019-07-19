#ifndef __FUNCTION__H
#define __FUNCTION__H


void function(void);

void uart1_set_TimeOut(uint16_t ms);
void uart2_set_TimeOut(uint16_t ms);
void uart1_check_TimeOut(void);
void uart2_check_TimeOut(void);

void usart1_and_usart2();
void usart1_cmd_write();
void gprs_conf();

void GPRS_check(uint16_t check_times);
void Unpack(uint8_t byte);

struct frame{
    uint8_t addr;
    uint8_t func;
    uint8_t data_size;
    uint8_t data12[12];
		uint8_t crcL;
		uint8_t crcH;	
};
#endif
