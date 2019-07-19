
#include	"delay.h"
#include	"config.h"

#include <sys_clock.h>


void  delay_ms(unsigned int ms)
{
    uint16_t start = get_sys_ticks();
    uint16_t ticks;
	 do{
         ticks = get_sys_ticks();
     }while(ticks - start  < ms / 10);
}

//1sÑÓÊ±
void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}