/*
 * mqtt_main.h
 *
 *  Created on: 2018Äê6ÔÂ22ÈÕ
 *      Author: clx
 */

#ifndef USERMQTT_H_
#define USER_MQTT_H_

void sntpfn();
void wifiConnectCb(uint8_t status);
void mqttConnectedCb(uint32_t *args);
void mqttDisconnectedCb(uint32_t *args);
void mqttPublishedCb(uint32_t *args);
void mqttDataCb(uint32_t *args, const char* topic, uint32_t topic_len, const char *data, uint32_t data_len);
void mqtt_init(void);


#endif /* MQTT_MAIN_H_ */
