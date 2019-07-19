
#include "packet_route.h"
#include "packet_dust.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "USART1.h"
#include <gpio.h>
//#include <timer.h>


//#include <stm8s_eeprom.h>
//#include <stm8s_iwdg.h>

//#include "../inc/router_comm.h"


void sys_reset() 
{
//    /* Enable the access to the IWDG registers*/
//    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
//    /* Fixe IWDG Reset period */
//    IWDG_SetPrescaler(IWDG_Prescaler_4);
//    IWDG_SetReload(0x10);
//    while(1);
}


#define VERSION_MAJOR 00
#define VERSION_MINOR 02

extern volatile uint16_t power_voltage, battery_voltage;
extern volatile uint8_t power_state;

static xdata uint8_t recv_buf1[512];  //最小缓存200
static xdata uint8_t send_buf[128];

//volatile tick_t last_comm_tick = 0;
volatile uint8_t router_connected = 0;
volatile uint8_t router_wait = 0;

struct packet_state {
    uint8_t power_state;
    uint16_t power_volt;
    uint16_t battery_volt;
};


void router_uart_write(uint8_t *src, uint16_t length)
{

//    watchdog_reset();//��λ���Ź�
    while( length--) {

		TX1_write2buff(*src++);
    }
//
//    watchdog_reset();//��λ���Ź�
}
/*
typedef struct {

    uint8_t flag1;
    uint8_t addr;
    uint8_t flag2;
    uint8_t cmd;
    uint8_t data_size;
    uint8_t dat[1];

} term_packet_head_t;
*/

void term_process(term_packet_head_t *packet)
{
//    struct packet_state *state;
    term_packet_head_t *send_pkt = (term_packet_head_t *) send_buf;
    uint8_t tmp, i;
    uint8_t send_cmd = packet->cmd;
//    uint8_t buf[16];
	  
    send_pkt->flag1 = 0xc3;
    send_pkt->flag2 = 0x3c;
    send_pkt->cmd =  packet->cmd;
    send_pkt->addr = 0x01;


    switch(send_cmd) {
     case 0x01:
        send_pkt->data_size = 9;

        //�¶�
        send_pkt->dat[0] = 0;
        send_pkt->dat[1] = data_temp & 0xff;
        send_pkt->dat[2] = data_temp >> 8;

        send_pkt->dat[3] = 1;
        send_pkt->dat[4] = data_airhum & 0xff;
        send_pkt->dat[5] = data_airhum >> 8;

        send_pkt->dat[6] = 2;

        send_pkt->dat[7] = data_pm252 & 0xff;
        send_pkt->dat[8] = data_pm252 >> 8;

        tmp = 0;
        for(i = 0; i< 9; i++)
            tmp += send_pkt->dat[i];

        send_pkt->dat[9] = tmp;
        send_pkt->dat[10] = TERM_END_FLAG;
        router_uart_write(send_buf, send_pkt->data_size + 7);
				LED_ROUTER_STATE_OFF;
        break;

    case 0x02:
        send_pkt->data_size = 15;

        //�¶�
        send_pkt->dat[0] = 0;
        send_pkt->dat[1] = data_temp & 0xff;
        send_pkt->dat[2] = data_temp >> 8;

        send_pkt->dat[3] = 1;
        send_pkt->dat[4] = data_airhum & 0xff;
        send_pkt->dat[5] = data_airhum >> 8;

        send_pkt->dat[6] = 2;

        send_pkt->dat[7] = data_pm251 & 0xff;
        send_pkt->dat[8] = data_pm251 >> 8;

        send_pkt->dat[9] = data_pm101 & 0xff;
        send_pkt->dat[10] = data_pm101 >> 8;

        send_pkt->dat[11] = data_pm252 & 0xff;
        send_pkt->dat[12] = data_pm252 >> 8;

        send_pkt->dat[13] = data_pm102 & 0xff;
        send_pkt->dat[14] = data_pm102 >> 8;

        tmp = 0;
        for(i = 0; i< 15; i++)
            tmp += send_pkt->dat[i];

        send_pkt->dat[15] = tmp;
        send_pkt->dat[16] = TERM_END_FLAG;
				
        router_uart_write(send_buf, send_pkt->data_size + 7);
				LED_ROUTER_STATE_OFF;

        break;
    }

}

extern volatile uint8_t send_flg;

void router_uart_isr(uint8_t byte)
{
    static uint16_t received_bytes = 0;
    uint16_t read_index = 0;
    term_packet_head_t *packet;

    // LED2 = !LED2;
	
    
    if(received_bytes >= sizeof( recv_buf1)) {
 //       recv_buf1[0] = byte;
        received_bytes = 0;
    }
		recv_buf1[received_bytes] = byte;
		received_bytes++;
    while(received_bytes >= TERM_PACKET_MIN_SIZE) {

 //       LED_ROUTER_STATE_OFF;
		
        packet = (term_packet_head_t*) &recv_buf1[read_index];

        if(packet->flag1 == TERM_START_FLAG1 &&
                    packet->flag2 == TERM_START_FLAG2) {

            if(packet->addr == 0x01 &&
                    packet->data_size <= 200) {

                if(packet->data_size + 7 > received_bytes)
                    return;
				
                if(recv_buf1[read_index+packet->data_size + 6] == TERM_END_FLAG) {

                    uint8_t i, sum = 0;
					 
//                    for(i = 0; i< packet->data_size; i++)
//                        sum += packet->dat[i];
					   
//                     if(1/*sum == packet->dat[packet->data_size]*/) {
// 					   send_flg = 1;
// //					   LED_ROUTER_STATE_OFF;
// 					   send_cmd = packet->cmd;
					   
					  
//                     }
										LED_ROUTER_STATE_ON;
                    term_process(packet);
//										memset(recv_buf1,0,sizeof(recv_buf1));
                    received_bytes  -= packet->data_size + 7;
                    read_index += packet->data_size + 7;
                    continue;
                }
            }

        }//end of  if(receivBuffer[readIndex+packet->packetSize] == PACKET_END_BYTE)
        received_bytes--;
        read_index++;
    }// end of while

    if(read_index != 0)
        memmove(recv_buf1, &recv_buf1[read_index], received_bytes);

}



