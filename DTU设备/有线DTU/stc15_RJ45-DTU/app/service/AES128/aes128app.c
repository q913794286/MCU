							   
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "aes.h"
#include "aes128app.h"
#include "usart1.h"

// Enable both ECB and CBC mode. Note this can be done before including aes.h or at compile-time.
// E.g. with GCC by using the -D flag: gcc -c aes.c -DCBC=0 -DECB=1
#define CBC 1
//#define ECB 1

#include "aes.h"

 void phex(uint8_t* str);



// prints string as hex
void phex(uint8_t* str)
{
    unsigned char i;
    for(i = 0; i < 16; ++i)
        printf("%.2x", str[i]);
    printf("\n");
}


/*
CBC解密
*/
int app_decrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t *out)
{
	uint16_t len;
	uint16_t cnt, Sa, Re;
	//确保数组大小为16的倍数
	len = sizeof(in);
	Sa = len/16;
	Re = len%16;
	for(cnt=len; cnt<(Sa+1)*16; cnt++)
	{in[cnt]=Re;}
	AES128_CBC_decrypt_buffer(out+0, in+0,  64, key, iv);
	return len;
}

/*
CBC加密
*/
//uint8_t buff[255];
int app_encrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t len, uint8_t *out)
{
	uint16_t cnt, Sa, Re;
	
	//确保数组大小为16的倍数
	Sa = len/16;
	Re = len%16;
	if(Re)
	{
	for(cnt=len;cnt<(len+16-Re);cnt++)
	  in[cnt] = (16-Re);
	}
//	Printf1(in,(Sa+1)*16);
	AES128_CBC_encrypt_buffer(out, in, (Sa+1)*16, key, iv);
//    printf("AES128_CBC_encrypt SUCCESS!\n");
//	Printf1(out,(Sa+1)*16);
	return (Sa+1)*16;
}



