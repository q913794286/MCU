
#include "packet_dust.h"
#include "packet_route.h"
#include <string.h>
#include "gpio.h"
#include "USART1.h"
#include "delay.h"

#define USART_RE (1<<2)

#define DEBUG_OUT //printf

//struct frame{
//    uint8_t head1;
//    uint8_t head2;
//    uint16_t len;
//    uint16_t data1;
//    uint16_t data2;
//    uint16_t data3;
//    uint16_t data4;
//    uint16_t data5;
//    uint16_t data6;
//    uint16_t data7;
//    uint16_t data8;
//    uint16_t data9;
//    uint16_t data10;
//    uint16_t data11;
//    uint16_t data12;
//};

uint16_t data_temp = 0xffff;
uint16_t data_airhum = 0xffff;
uint16_t data_pm251 = 0xffff;
uint16_t data_pm252 = 0xffff;
uint16_t data_pm101 = 0xffff;
uint16_t data_pm102 = 0xffff;
uint16_t si = 0;

#define DUST_VO_COUNT 20

static xdata uint8_t  recv_buf2[128];
static volatile uint8_t save_index = 0;
volatile uint8_t dust_ready = 0;

volatile uint16_t dust_vo[6] ;
volatile uint16_t dust_vref = 0;


void cfg_uart_write(uint8_t *src, uint16_t length)
{
    while( length--) {
		TX2_write2buff(*src++);
    }
}

uint16_t get_dustvo(uint16_t *buf)
{

    uint8_t;

    if(dust_ready) {

	 EA =0;
//	S2_RX_Disable()	;
//        disableInterrupts(); 
//        UART2_INT_DISABLE();
        dust_ready = 0;
        memcpy(buf, dust_vo, sizeof(dust_vo));
		delay_ms(1);		
		UART2_INT_ENABLE();
//        enableInterrupts();
//	 S2_RX_EN()	;
		EA=1;								//允许串2接收
//        for(i = 0; i< DUST_VO_COUNT; i++)
//            printf("%u ",  buf[i]);
//        printf("\n");

        return 1;
    }

    return 0;
}

static void save_dustvo(uint16_t v1, uint16_t v2, uint16_t v3, uint16_t v4, uint16_t temp_vo, uint16_t hum_vo)
{
    dust_vo[0] = v1;
    dust_vo[1] = v2;
    dust_vo[2] = v3;
    dust_vo[3] = v4;
	dust_vo[4] = temp_vo/10;
	dust_vo[5] = hum_vo/10;  
    dust_ready = 1;
}

void dust_uart_isr(uint8_t byte)
{
    static uint8_t received_bytes = 0;
    uint8_t read_index = 0;
    //term_packet_head_t *packet;
    //printf("%02X ", (int) byte);

    if(received_bytes >= sizeof(recv_buf2))
        received_bytes = 0;
    recv_buf2[received_bytes] = byte;
    received_bytes++;

    while(received_bytes >= 32) {
		 LED_SYS_STATE_ON;
        if(recv_buf2[read_index] == 0x42 &&
                recv_buf2[read_index + 1] == 0x4d) {
//            uint16_t vref;
            uint8_t sum = 0;
            struct frame *frm = (struct frame *) &recv_buf2[read_index];
//            for(i = 1; i< 5; i++)
//                sum += recv_buf2[read_index + i];
			 
            if(1 /*sum == recv_buf2[read_index + 5]*/) {
                save_dustvo(frm->data2, frm->data3, frm->data5, frm->data6, frm->data11, frm->data12);	 //保存得到的数据
                }

            received_bytes -= 32;
            read_index += 32;
            continue;

        }//end of  if(receivBuffer[readIndex+packet->packetSize] == PACKET_END_BYTE)

        received_bytes--;
        read_index++;
    }// end of while

    if(read_index != 0)
        memmove(recv_buf2, &recv_buf2[read_index], received_bytes);
}


