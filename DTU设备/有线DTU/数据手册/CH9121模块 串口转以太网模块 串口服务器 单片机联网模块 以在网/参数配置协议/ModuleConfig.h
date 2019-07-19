
// ������������CH9121ͨ�ŵĻ������ݽṹ�������ýṹ��������

#ifndef __MODULECONFIG_H__
#define __MODULECONFIG_H__

//�������Ͷ���
#define UCHAR  unsigned char
#define USHORT unsigned short
#define ULONG  unsigned long

#define NET_MODULE_DATA_LENGTH    255   //��CH9121ͨ��ʱ����������󳤶�

#define MODULE_CFG_LEN_NEW   ( 74 + 65*2 )

//ͨ��������
#define NET_MODULE_CMD_SET      0X01    //���������е�CH9121
#define NET_MODULE_CMD_GET      0X02    //��ȡĳ��CH9121������
#define NET_MODULE_CMD_RESET    0X03    //��ȡĳ��CH9121������
#define NET_MODULE_CMD_SEARCH   0X04    //���������е�CH9121

//Ӧ��������
#define NET_MODULE_ACK_SET      0X81    //��Ӧ����������
#define NET_MODULE_ACK_GET      0X82    //��Ӧ��ȡ������
#define NET_MODULE_ACK_RESET    0X83    //��ȡĳ��CH9121������
#define NET_MODULE_ACK_SEARCH   0X84    //��Ӧ����������

//У��ʹ���ʱ��Ӧ��������
#define NET_MODULE_NAK_SEARCH    0xC0    //����У���
#define NET_MODULE_NAK_SET       0XC1    //����У���
#define NET_MODULE_NAK_GET       0XC2    //��ȡУ���

#define CH9121_CFG_FLAG        "CH9121_CFG_FLAG"    //������ʶͨ��


//����ͨ�Žṹ��
typedef struct NET_COMM {
  unsigned char flag[16];                     //ͨ�ű�ʶ����Ϊ�����ù㲥��ʽ����ͨ�ŵģ����������һ���̶�ֵ
  unsigned char cmd;                          //����ͷ
  unsigned char id[6];                        //CH9121MAC��ַ
  unsigned char pcid[6];                      //PC��MAC��ַ
  unsigned char len;                          //����������
  unsigned char data[NET_MODULE_DATA_LENGTH]; //������������
}net_comm,*pnet_comm;

//CH9121��ʶ
#define  NET_MODULE_TYPE_TCP_S    0X00         //CH9121��ΪTCP SERVER
#define  NET_MODULE_TYPE_TCP_C    0X01         //CH9121��ΪTCP CLIENT
#define  NET_MODULE_TYPE_UDP_S    0X02         //CH9121��ΪUDP SERVER
#define NET_MODULE_TYPE_UDP_C     0X03         //CH9121��ΪUDP CLIENT

//У��λ��ʶ
#define NET_MODULE_VERIFY_NULL    0X04         //��У��
#define NET_MODULE_VERIFY_ODD     0X00         //��У��
#define NET_MODULE_VERIFY_EVEN    0X01         //żУ��
#define NET_MODULE_VERIFY_MARK    0X02         //markУ��
#define NET_MODULE_VERIFY_SPACE   0X03         //spaceУ��


/* �豸Ӳ����Ϣ�ṹ�嶨�� */
#define CH9121_DEV_TYPE             0x30
#define CH9121_DEV_AUX_TYPE         0x01
#define CH9121_DEV_HARDWARE_VER     0x02
#define CH9121_DEV_SOFTWARE_VER     0x02   

/* ���豸������Ϣ�ṹ�嶨�� */

#define CH9121_DevType         0x21
#define CH9121_AuxDevType      0x21
#define CH9121_DevbIndex       0x01
#define CH9121_DevHardwareVer  0x02
#define CH9121_SoftwareVer     0x02
#define CH9121_VER    (((CH9121_DevHardwareVer<<4) & 0xF0) | (CH9121_SoftwareVer & 0x0f))



__packed typedef struct _DEVICEHW_CONFIG
{
  UCHAR  bDevType;                /* �豸���ͣ�ֻ�� */
  UCHAR  bAuxDevType;             /* �豸������, ֻ��*/
  UCHAR  bIndex;                  /* �豸���, ֻ��*/
  UCHAR  bDevHardwareVer;         /* �豸Ӳ���汾��,ֻ�� */  
  UCHAR  bDevSoftwareVer;         /* �豸����汾��,ֻ�� */  
  UCHAR  szModulename[21];        /* �û���ͬCH9121��*/
  UCHAR  bDevMAC[ 6 ];            /* CH9121����MAC��ַ */  
  UCHAR  bDevIP[ 4 ];             /* CH9121IP��ַ*/
  UCHAR  bDevGWIP[ 4 ];           /* CH9121����IP */
  UCHAR  bDevIPMask[ 4 ];         /* CH9121�������� */
  UCHAR  bDhcpEnable;             /* DHCP ʹ�ܣ��Ƿ�����DHCP,1:���ã�0��������*/
  USHORT breserved1;              /* Ԥ����δ���� */
  UCHAR  breserved2[8];           /* Ԥ����δ����*/
  UCHAR  breserved3;              /* Ԥ����δ����*/
  UCHAR  breserved4[8];           /* Ԥ����δ����*/
  UCHAR  breserved5;              /* Ԥ����δ����*/
  UCHAR  bComcfgEn;               /* ����Э�����ñ�־ 1������ 0������*/
  UCHAR  breserved6[8];           /* Ԥ����δ����*/
}DeviceHWConfigS,*pDeviceHWConfigS;

__packed typedef struct _DEVICEPORT_CONFIG
{
  UCHAR  bIndex;                   /* ���豸��ţ�ֻ��  */
  UCHAR  bPortEn;                  /* �˿����ñ�־ 1������ ��0�������� */
  UCHAR  bNetMode;                 /* ���繤��ģʽ: 0: TCP SERVER;1: TCP CLENT; 2: UDP SERVER 3��UDP CLIENT; */
  UCHAR  bRandSportFlag;           /* TCP �ͻ���ģʽ��������ض˿ںţ�1����� 0: �����*/
  USHORT wNetPort;                 /* ���ض˿ں� */  
  UCHAR  bDesIP[ 4 ];              /* Ŀ��IP��ַ */
  USHORT wDesPort;                 /* Ŀ�Ķ˿ں� */
  ULONG  dBaudRate;                /* ���ڲ�����: 300---921600bps */
  UCHAR  bDataSize;                /* ��������λ: 5---8λ */  
  UCHAR  bStopBits;                /* ����ֹͣλ: 0��ʾ1��ֹͣλ; 1��ʾ1.5��ֹͣλ; 2��ʾ2��ֹͣλ */  
  UCHAR  bParity;                  /* ����У��λ: 4��ʾ��У�飬0��ʾ��У��; 1��ʾżУ��; 2��ʾ��־λ(MARK,��1); 3��ʾ�հ�λ(SPACE,��0);  */    
  UCHAR  bPHYChangeHandle;         /* PHY�Ͽ���Socket������1���ر�Socket 0��������*/
  ULONG  dRxPktlength;             /* ����RX���ݴ�����ȣ����1024 */
  ULONG  dRxPktTimeout;            /* ����RX���ݴ��ת�������ȴ�ʱ��,��λΪ: 10ms,0���ʾ�رճ�ʱ���� */
  UCHAR  bResv;                    /* Ԥ��δ����*/  
  UCHAR  bResetCtrl;               /* ���ڸ�λ����: 0��ʾ����մ������ݻ�����; 1��ʾ����ʱ��մ������ݻ����� */  
  UCHAR  bDNSFlag;                 /* �����������ñ�־��1������ 0��������*/
  UCHAR  szDomainname[20];         /* TCP�ͻ���ģʽ�£�Ŀ�ĵ�ַ������*/
  UCHAR  breserved[14];            /* ����*/
}DevicePortConfigS,*pDevicePortConfigS;


__packed typedef struct _NET_DEVICE_CONFIG
{   
  DeviceHWConfigS     HWCfg;        /*��������ṹ��*/
  DevicePortConfigS   PortCfg[2];   /*͸��ͨ������*/
}NetDeviceConfigS,*pNetDeviceConfigS;



#endif
