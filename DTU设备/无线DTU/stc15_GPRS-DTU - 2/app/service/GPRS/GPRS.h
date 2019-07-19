#ifndef __GPRS_H
#define __GPRS_H

sbit Power = P0^0;
#define Power_ON  Power=0;
#define Power_OFF  Power=1;

typedef struct{
	uint8_t *baud;
	uint8_t *server;
}S_config;

extern S_config s_config;
extern u8 gprs_status;

void init_GPRS( S_config *s);
void check_gprs();
u8 gprs_cmd(u8 *cmd, u8 *input, u8 *ck_str, u8 outtime_s);



#endif
