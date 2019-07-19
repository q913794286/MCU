#ifndef __GPRS_H
#define __GPRS_H

sbit Power = P0^0;
#define Power_ON  Power=0;
#define Power_OFF  Power=1;

void init_GPRS();
void check_gprs();



#endif
