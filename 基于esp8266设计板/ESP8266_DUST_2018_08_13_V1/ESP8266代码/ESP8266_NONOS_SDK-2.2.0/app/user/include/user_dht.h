/**********************************************************
      Make in goouuu.com
	  Maker:MDC
***********************************************************/
#ifndef USER_DHT11_H
#define USER_DHT11_H

uint8 ICACHE_FLASH_ATTR
ReadDHT11(uint8 *dht);

void ICACHE_FLASH_ATTR
DHT11_NumToString(uint8 dht,uint8 *str);

void ICACHE_FLASH_ATTR
Dis_DHT11(void);
#endif
