
#ifndef		__CONFIG_H
#define		__CONFIG_H


/*********************************************************/

//#define MAIN_Fosc		22118400L	//定义主时钟
//#define MAIN_Fosc		12000000L	//定义主时钟
#define MAIN_Fosc		11059200L	//定义主时钟
//#define MAIN_Fosc		 5529600L	//定义主时钟
//#define MAIN_Fosc		24000000L	//定义主时钟
typedef  unsigned int uint;
typedef  unsigned char uchar;

/*********************************************************/

#include	"STC15Fxxxx.H"


#include "stdlib.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

sbit LED1 = P0^2;
sbit LED2 = P0^3;
sbit Link = P0^0;

extern uint8_t UsartX_send ;
extern char chip_ID[20];
#endif
