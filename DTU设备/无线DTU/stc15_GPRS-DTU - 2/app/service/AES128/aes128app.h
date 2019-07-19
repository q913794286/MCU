#ifndef __AES128APP_H
#define __AES128APP_H

typedef struct{
	uint8_t id[8];
	uint8_t key[16];
	uint8_t iv[16];
	uint8_t state;
}AES128;

extern AES128 aes128;																			

int app_encrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t len, uint8_t *out); //EBCº”√‹
int app_decrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t *out); //EBCΩ‚√‹


#endif
