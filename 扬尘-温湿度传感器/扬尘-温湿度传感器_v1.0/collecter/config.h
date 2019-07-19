
#ifndef		__CONFIG_H
#define		__CONFIG_H

//#include 	"rtx51tny.h"

/*********************************************************/

//#define MAIN_Fosc		22118400L	//������ʱ��
//#define MAIN_Fosc		12000000L	//������ʱ��
#define MAIN_Fosc		11059200L	//������ʱ��
//#define MAIN_Fosc		 5529600L	//������ʱ��
//#define MAIN_Fosc		24000000L	//������ʱ��
typedef  unsigned int uint;
typedef  unsigned char uchar;


/*********************************************************/
#include	"STC15Fxxxx.H"


#include "stdlib.h"
#include <stdio.h>
#include <stdint.h>
#include "mystring.h"

sbit LED1 = P0^0;
sbit LED2 = P0^1;
#define LED_SYS_STATE_ON   LED1=0;
#define LED_SYS_STATE_OFF  LED1=1;
#define LED_ROUTER_STATE_ON  LED2=0;
#define LED_ROUTER_STATE_OFF  LED2=1;

#endif
