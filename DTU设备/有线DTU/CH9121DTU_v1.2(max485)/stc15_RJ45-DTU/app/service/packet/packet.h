#ifndef __packet_h
#define __packet_h


struct frame{
    uint8_t addr;
    uint8_t func;
    uint8_t data_size;
    uint8_t data12[12];
		uint8_t crcL;
		uint8_t crcH;	
};

void RS485_coil();
void Unpack(uint8_t byte);



#endif