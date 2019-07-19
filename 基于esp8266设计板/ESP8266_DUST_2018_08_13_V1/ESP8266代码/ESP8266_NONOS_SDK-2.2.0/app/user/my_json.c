/*
 * my_json.c
 *
 *  Created on: 2016年9月3日
 *      Author: Administrator
 */


#include "user_json.h"
#include "ets_sys.h"
#include "os_type.h"
#include "osapi.h"
#include "mem.h"
#include "user_interface.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct {
	int udp_ip[4];
}config_ip;

static config_ip  udpip_buf;


//LOCAL int jsonTree_set(struct jsontree_context *js_ctx, struct jsonparse_state *parser);
void setJsonObject(char *json);







LOCAL  config_ip ICACHE_FLASH_ATTR
*Cuuionfig_ip(void)
{

	//ip_addr_t  udp_remote_ip[4];
	//os_memcpy(udp_remote_ip, &ipConfig.ip, 4);

	struct ip_info  ipConfig;
	wifi_get_ip_info(STATION_IF, &ipConfig);   //查看当前本届IP
	udpip_buf.udp_ip[0]=ipConfig.ip.addr&0xff;
	udpip_buf.udp_ip[1]=(ipConfig.ip.addr>>8)&0xff;
	udpip_buf.udp_ip[2]=(ipConfig.ip.addr>>16)&0xff;
	udpip_buf.udp_ip[3]=(ipConfig.ip.addr>>24)&0xff;

	return  &udpip_buf;
}


 //json 存入需要的数据
LOCAL int ICACHE_FLASH_ATTR
jsonTree_get(struct jsontree_context *js_ctx)
{
    const char *path = jsontree_path_name(js_ctx, js_ctx->depth - 1);


    if (os_strncmp(path, "cmd", os_strlen("cmd")) == 0)
     {
     	jsontree_write_string(js_ctx, "imd");

     }
    else if (os_strncmp(path, "ip", os_strlen("ip")) == 0)
     {

        config_ip *conf_ip;
        conf_ip = Cuuionfig_ip();
    //	jsontree_write_atom(js_ctx, "{");
    	jsontree_write_int_array(js_ctx, conf_ip->udp_ip,4);
    //	jsontree_write_atom(js_ctx, "}");

     }
    else if (os_strncmp(path, "port", os_strlen("port")) == 0)
    {
    	jsontree_write_string(js_ctx, "9898");

     }
    else if (os_strncmp(path, "protocol", os_strlen("protocol")) == 0)
     {
     	jsontree_write_string(js_ctx, "UDP");

      }
    else if (os_strncmp(path, "dust_data", os_strlen("dust_data")) == 0)
     {
    	const int dustdata[10]={0};

     	jsontree_write_string(js_ctx, "send dust data");

     	jsontree_write_atom(js_ctx, "[");
     	jsontree_write_int_array(js_ctx, dustdata,10);
     	jsontree_write_atom(js_ctx, "]");

      }
    return 0;
}







//初始化一个Json数据回调函数
//JSONTREE_CALLBACK第一个参数为生成Json数据的函数指针，第二个为获取Json数据的函数指针
LOCAL struct jsontree_callback jsonCallback = JSONTREE_CALLBACK(jsonTree_get, NULL);   //



JSONTREE_OBJECT(jsonesp8266,
                JSONTREE_PAIR("cmd", &jsonCallback),
                JSONTREE_PAIR("ip", &jsonCallback),
                JSONTREE_PAIR("port", &jsonCallback),
				JSONTREE_PAIR("protocol", &jsonCallback),
				JSONTREE_PAIR("dust_data", &jsonCallback));


JSONTREE_OBJECT(jsonTestTree,
                JSONTREE_PAIR("jsonTest", &jsonesp8266));




//json  send data
#define LENGTH 512
char* ICACHE_FLASH_ATTR
getJsonTree(void)
{
    static char jsonbuf[LENGTH];
    os_memset(jsonbuf, 0, LENGTH);      //初始化字符串
	json_ws_send((struct jsontree_value *)&jsonTestTree, "jsonTest", jsonbuf);

	return jsonbuf;

}



/*

LOCAL int ICACHE_FLASH_ATTR
jsonTree_set(struct jsontree_context *js_ctx, struct jsonparse_state *parser)
{
    int type;

    while ((type = jsonparse_next(parser)) != 0) {
    	//如果是KEY类型
        if (type == JSON_TYPE_PAIR_NAME) {
            char buffer[64];
            os_bzero(buffer, 64);

            if (jsonparse_strcmp_value(parser, "cmd") == 0) {
                jsonparse_next(parser);	//返回的是冒号字符
                type = jsonparse_next(parser);	//返回的是双引号字符
                os_printf("String Value type = %c\n", type);	// = "

                //如果Value是字符串类型，则读取数据到buffer
                if (JSON_TYPE_STRING == type){	//#define JSON_TYPE_STRING '"'
                	jsonparse_copy_value(parser, buffer, sizeof(buffer));
                	os_printf("String Value = %s\n", buffer);
                }

            } else if (jsonparse_strcmp_value(parser, "Integer") == 0) {
                jsonparse_next(parser);
                type = jsonparse_next(parser);


                os_printf("Integer Value type = %c\n", type);	// = 0
                //如果Value是数值类型
                if(JSON_TYPE_NUMBER == type){	//#define JSON_TYPE_NUMBER '0'
                	//jsonparse_copy_value(parser, buffer, sizeof(buffer));
                	int num = 0;
                	num = jsonparse_get_value_as_int(parser);
                	os_printf("Integer Value = %d\n", num);		// = 1
                }
            } else if (jsonparse_strcmp_value(parser, "Array") == 0) {
                jsonparse_next(parser);	//跳过冒号
                type = jsonparse_next(parser);
                os_printf("Array Value type = %c\n", type);		// = [

                //如果Value是数组类型
                if(JSON_TYPE_ARRAY == type){	//#define JSON_TYPE_ARRAY '['
                	//jsonparse_copy_value(parser, buffer, sizeof(buffer));
                	int length = jsonparse_get_len(parser);
                	os_printf("Array Length = %d\n", length);	//= 5, 数据是[0,1,2]，可能把逗号也算在内

                	int i;
                	int num = 100;
                	//循环读取数组的数据
                	for(i=0; i<length; i++){
                		type = jsonparse_next(parser);
                		// 如果是逗号，则直接打印, 如果是数值则打印0
                		os_printf("Array[%d] type = %c ", i, type);

                		//如果是数值类型，则转换成int并打印出来
                		if(JSON_TYPE_NUMBER==type){
                        	num = jsonparse_get_value_as_int(parser);
                        	os_printf("Array[%d] = %d\n", i, num);
                		}
                		//后面可以添加else if判断是否是其他类型
                		//比如 else if(JSON_TYPE_OBJECT==type),判断是否是Json对象
                		else{
                			os_printf("\n");
                		}
                	}
                }
            }
#if 1
            else if (jsonparse_strcmp_value(parser, "JsonObject") == 0) {
                jsonparse_next(parser);	//跳过冒号
                type = jsonparse_next(parser);
                os_printf("JsonObject Value type = %c\n", type);		// = {

                if(JSON_TYPE_OBJECT == type){	//#define JSON_TYPE_OBJECT '{'
                	int length = jsonparse_get_len(parser);
                	os_printf("JsonObject Length = %d\n", length);

                	//char temp[128] = {0};
                	//jsonparse_copy_value(parser, temp, 128);
                	//os_printf("JsonObject Value = %s\n", temp);

                	//循环读取数据
                	int i = 0;
                	//for(i=0; i<length; i++){
                	while(type != '}'){
                		i++;
                		type = jsonparse_next(parser);

                		os_printf("JsonObject[%d] type = %c", i, type);
                		os_printf("\n");
                		//os_memset(temp, 0, 128);
                    	//jsonparse_copy_value(parser, temp, 128);
                    	//os_printf("JsonObject Value = %s\n", temp);
                		//读取第二层的Json对象的数据
                		jsonObject_set(parser);
                	}
                }

            }
#endif
        }
    }

    return 0;
}


*/
/*
//json   receive data
void ICACHE_FLASH_ATTR
setJsonTree(char *json)
{
    struct jsontree_context js;

    jsontree_setup(&js, (struct jsontree_value *)&jsonTestTree, json_putchar);
    json_parse(&js, json);
}
*/

