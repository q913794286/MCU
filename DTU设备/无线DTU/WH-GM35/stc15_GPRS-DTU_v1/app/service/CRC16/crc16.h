#ifndef __CRC16_h
#define __CRC16_h

/********************************************************
*名称：			crc16
*功能：			16位CRC校验
*输入：			*puchMsg		：待校验数组
                usDataLen		: 待校验数组长度
*返回：			16位校验码
********************************************************/
uint16_t crc16(uint8_t *puchMsg, uint16_t usDataLen);
uint16_t crc16_2(uint8_t *puchMsg1, uint16_t usDataLen1,  uint8_t *puchMsg2,  uint16_t usDataLen2);

#endif
