#ifndef __CRC16_h
#define __CRC16_h

/********************************************************
*���ƣ�			crc16
*���ܣ�			16λCRCУ��
*���룺			*puchMsg		����У������
                usDataLen		: ��У�����鳤��
*���أ�			16λУ����
********************************************************/
uint16_t crc16(uint8_t *puchMsg, uint16_t usDataLen);
uint16_t crc16_2(uint8_t *puchMsg1, uint16_t usDataLen1,  uint8_t *puchMsg2,  uint16_t usDataLen2);

#endif
