/*
 * smart_config.h
 *
 *  Created on: 2018Äê6ÔÂ22ÈÕ
 *      Author: clx
 */

#ifndef SMART_CONFIG_H_
#define SMART_CONFIG_H_

#include "ets_sys.h"
#include "smartconfig.h"

LOCAL void ICACHE_FLASH_ATTR
airkiss_wifilan_time_callback(void);

LOCAL void ICACHE_FLASH_ATTR
airkiss_wifilan_recv_callbk(void *arg, char *pdata, unsigned short len);

void ICACHE_FLASH_ATTR
airkiss_start_discover(void);

void ICACHE_FLASH_ATTR
smartconfig_done(sc_status status, void *pdata);
void smartconfig_init(void);
#endif /* APP_USER_INCLUDE_SMART_CONFIG_H_ */
