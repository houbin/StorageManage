#ifndef _JVNSDKDEF_H
#define _JVNSDKDEF_H

#ifndef WIN32
   #include <sys/socket.h>
   #include <netinet/in.h>
   typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[ 8 ];
    } GUID;
    #define MAX_PATH 256
	typedef  struct sockaddr_in  SOCKADDR_IN;
	typedef  struct sockaddr  SOCKADDR;
    #define FALSE 0
    #define TRUE  1
    
#else
	#include <winsock.h>	
#endif

/*ʵʱ�����������*/
#define JVN_DATA_I           0x01//��ƵI֡
#define JVN_DATA_B           0x02//��ƵB֡
#define JVN_DATA_P           0x03//��ƵP֡
#define JVN_DATA_A           0x04//��Ƶ
#define JVN_DATA_S           0x05//֡�ߴ�
#define JVN_DATA_OK          0x06//��Ƶ֡�յ�ȷ��
#define JVN_DATA_DANDP       0x07//���ػ�ط��յ�ȷ��
#define JVN_DATA_O           0x08//�����Զ�������
#define JVN_DATA_SKIP        0x09//��ƵS֡
#define JVN_DATA_SPEED		 0x64//��������
#define JVN_DATA_HEAD        0x66//��Ƶ����ͷ�������ݳ��ֵ�ͬʱ����ջ���
/*��������*/
#define JVN_REQ_CHECK        0x10//����¼�����
#define JVN_REQ_DOWNLOAD     0x20//����¼������
#define JVN_REQ_PLAY         0x30//����Զ�̻ط�
#define JVN_REQ_CHAT         0x40//������������
#define JVN_REQ_TEXT         0x50//�����ı�����
#define JVN_REQ_CHECKPASS    0x71//���������֤
#define JVN_REQ_RECHECK      0x13//Ԥ��֤
#define JVN_REQ_RATE		 0x63//�ֿ���������
	
/*���󷵻ؽ������*/
#define JVN_RSP_CHECKDATA    0x11//�������
#define JVN_RSP_CHECKOVER    0x12//�������
#define JVN_RSP_DOWNLOADDATA 0x21//��������
#define JVN_RSP_DOWNLOADOVER 0x22//�����������
#define JVN_RSP_DOWNLOADE    0x23//��������ʧ��
#define JVN_RSP_PLAYDATA     0x31//�ط�����
#define JVN_RSP_PLAYOVER     0x32//�ط����
#define JVN_RSP_PLAYE        0x39//�ط�ʧ��
#define JVN_RSP_CHATDATA     0x41//��������
#define JVN_RSP_CHATACCEPT   0x42//ͬ����������
#define JVN_RSP_TEXTDATA     0x51//�ı�����
#define JVN_RSP_TEXTACCEPT   0x52//ͬ���ı�����
#define JVN_RSP_CHECKPASS    0x72//�����֤
#define JVN_RSP_CHECKPASST   0x72//�����֤�ɹ� ΪTCP����
#define JVN_RSP_CHECKPASSF   0x73//�����֤ʧ�� ΪTCP����
#define JVN_RSP_NOSERVER     0x74//�޸�ͨ������
#define JVN_RSP_INVALIDTYPE  0x7A//����������Ч
#define JVN_RSP_OVERLIMIT    0x7B//���ӳ�����������������Ŀ
#define JVN_RSP_DLTIMEOUT    0x76//���س�ʱ
#define JVN_RSP_PLTIMEOUT    0x77//�طų�ʱ
#define JVN_RSP_RECHECK      0x14//Ԥ��֤
#define JVN_RSP_OLD          0x15//�ɰ����ػظ�

/*��������*/
#define JVN_CMD_DOWNLOADSTOP 0x24//ֹͣ��������
#define JVN_CMD_PLAYUP       0x33//���
#define JVN_CMD_PLAYDOWN     0x34//����
#define JVN_CMD_PLAYDEF      0x35//ԭ�ٲ���
#define JVN_CMD_PLAYSTOP     0x36//ֹͣ����
#define JVN_CMD_PLAYPAUSE    0x37//��ͣ����
#define JVN_CMD_PLAYGOON     0x38//��������
#define JVN_CMD_CHATSTOP     0x43//ֹͣ��������
#define JVN_CMD_PLAYSEEK     0x44//���Ŷ�λ		��֡��λ ��Ҫ���� ֡��(1~���֡)
#define JVN_CMD_TEXTSTOP     0x53//ֹͣ�ı�����
#define JVN_CMD_YTCTRL       0x60//��̨����
#define JVN_CMD_VIDEO        0x70//ʵʱ���
#define JVN_CMD_VIDEOPAUSE   0x75//��ͣʵʱ���
#define JVN_CMD_TRYTOUCH     0x78//�򶴰�
#define JVN_CMD_FRAMETIME    0x79//֡����ʱ����(��λms)
#define JVN_CMD_DISCONN      0x80//�Ͽ�����
#define JVN_CMD_MOTYPE		 0x72//UDP�ֻ����� ע����ֵ������һ���Ͷ���ֵ��ͬ����Ӧ���⣬�ݱ�������
#define JVN_CMD_ONLYI        0x61//��ͨ��ֻ���ؼ�֡
#define JVN_CMD_FULL         0x62//��ͨ���ָ���֡
#define JVN_CMD_ALLAUDIO	 0x65//��Ƶȫת��
/*������ͨ�������Ľ�����Ϣ*/
#define JVN_CMD_RELOGIN		 0x89//֪ͨ�������µ�½
#define JVN_CMD_CLEAR		 0x8A//֪ͨ�������߲����������Ϣ��������ͨ����
#define JVN_CMD_REGCARD		 0x8B//����ע��忨��Ϣ��������



#define JVN_CMD_CARDCHECK    0x91//�忨��֤
#define JVN_CMD_CHANNELCOUNT 0x97//�ֿز�ѯ���������е�ͨ����Ŀ
#define JVN_CMD_PUSHMSG		 0x106//������������Ϣ

/*�ͻ�����ý����������*/
#define JVN_REQ_CONNSTREAM_SVR    0xD0//����������ý�����������
#define JVN_REQ_CONNSTREAM_CLT    0xD1//����������ý��������ֿ�
#define JVN_RSP_CONNSTREAM_SVR    0xD2//�ظ�
#define JVN_RSP_CONNSTREAM_CLT    0xD3
#define JVN_NOTIFY_ID			  0xD4
#define JVN_RSP_ID				  0xD5
#define JVN_CMD_CONNSSERVER		  0xD6
#define JVN_RSP_NEWCLIENT         0xD9

/*�������豸����*/
#define JVN_REQ_LANSERCH  0x01//�������豸��������
#define JVN_CMD_LANSALL   1//����������������ά�豸
#define JVN_CMD_LANSYST   2//����������ָ������ͨ������豸
#define JVN_CMD_LANSTYPE  3//����������ָ����ϵ���豸
#define JVN_CMD_LANSNAME  4//����������ָ���������豸
#define JVN_RSP_LANSERCH  0x02//�������豸������Ӧ����

#define JVN_DEVICENAMELEN  100//�豸������������

/*�������㲥*/
#define JVN_REQ_BC  0x03//�������㲥����
#define JVN_RSP_BC  0x04//�������㲥��Ӧ����

/*������������*/
#define JVN_REQ_TOOL 0x05//������Ϣ
#define JVN_RSP_TOOL 0x06//�豸��Ӧ

#define JVN_ALLSERVER     0//���з���
#define JVN_ONLYNET       1//ֻ����������

#define JVN_NOTURN        0//����ͨ��ʽʱ����ת��
#define JVN_TRYTURN       1//����ͨ��ʽʱ����ת��
#define JVN_ONLYTURN      2//����ͨ��ʽʱ����ת��

#define JVN_CONNTYPE_LOCAL  1//����������
#define JVN_CONNTYPE_P2P    2//P2P��͸����
#define JVN_CONNTYPE_TURN   3//ת��

#define JVN_LANGUAGE_ENGLISH  1
#define JVN_LANGUAGE_CHINESE  2

#define JVN_TRANS_ONLYI   1//�ؼ�֡ת��
#define JVN_TRANS_ALL     2//����ת��/��������

#define TYPE_PC_UDP      1//�������� UDP ֧��UDP�շ���������
#define TYPE_PC_TCP      2//�������� TCP ֧��TCP�շ���������
#define TYPE_MO_TCP      3//�������� TCP ֧��TCP�շ�������,��ͨ��Ƶ֡�Ȳ��ٷ��ͣ�ֻ�ܲ���ר�ýӿ��շ�����(�������ֻ����)
#define TYPE_MO_UDP      4//�������� UDP 
#define TYPE_3GMO_UDP    5//�������� 3GUDP
#define TYPE_3GMOHOME_UDP 6//�������� 3GHOME


/*������������*/
#define CMD_TYPE_CLEARBUFFER    1//���غͷֿ���ջ��棬���½��л���


/*��̨��������*/
#define JVN_YTCTRL_U      1//��
#define JVN_YTCTRL_D      2//��
#define JVN_YTCTRL_L      3//��
#define JVN_YTCTRL_R      4//��
#define JVN_YTCTRL_A      5//�Զ�
#define JVN_YTCTRL_GQD    6//��Ȧ��
#define JVN_YTCTRL_GQX    7//��ȦС
#define JVN_YTCTRL_BJD    8//�佹��
#define JVN_YTCTRL_BJX    9//�佹С
#define JVN_YTCTRL_BBD    10//�䱶��
#define JVN_YTCTRL_BBX    11//�䱶С

#define JVN_YTCTRL_UT     21//��ֹͣ
#define JVN_YTCTRL_DT     22//��ֹͣ
#define JVN_YTCTRL_LT     23//��ֹͣ
#define JVN_YTCTRL_RT     24//��ֹͣ
#define JVN_YTCTRL_AT     25//�Զ�ֹͣ
#define JVN_YTCTRL_GQDT   26//��Ȧ��ֹͣ
#define JVN_YTCTRL_GQXT   27//��ȦСֹͣ
#define JVN_YTCTRL_BJDT   28//�佹��ֹͣ
#define JVN_YTCTRL_BJXT   29//�佹Сֹͣ
#define JVN_YTCTRL_BBDT   30//�䱶��ֹͣ
#define JVN_YTCTRL_BBXT   31//�䱶Сֹͣ
#define JVN_YTCTRL_FZ1    32//����1
#define JVN_YTCTRL_FZ1T   33//����1ֹͣ
#define JVN_YTCTRL_FZ2    34//����2
#define JVN_YTCTRL_FZ2T   35//����2ֹͣ
#define JVN_YTCTRL_FZ3    36//����3
#define JVN_YTCTRL_FZ3T   37//����3ֹͣ
#define JVN_YTCTRL_FZ4    38//����4
#define JVN_YTCTRL_FZ4T   39//����4ֹͣ

#define JVN_YTCTRL_RECSTART  41//Զ��¼��ʼ
#define JVN_YTCTRL_RECSTOP	 42//Զ��¼��ʼ

/*Զ�̿���ָ��(���ֿ�Ӧ�ò�Լ��)*/
#define RC_DISCOVER		0x01 
#define RC_GETPARAM		0x02 
#define RC_SETPARAM		0x03 
#define RC_VERITY		0x04 
#define RC_SNAPSLIST	0x05 
#define RC_GETFILE		0x06 
#define RC_USERLIST		0x07 
#define RC_PRODUCTREG	0X08 
#define RC_GETSYSTIME	0x09 
#define RC_SETSYSTIME	0x0a 
#define RC_DEVRESTORE	0x0b 
#define RC_SETPARAMOK	0x0c 
#define RC_DVRBUSY		0X0d 
#define RC_GETDEVLOG	0x0e 
#define RC_DISCOVER2	0x0f	//zwq20111206,csst����ͨ����ֱ�ӵ�¼���������㲥����

#define JVN_VC_BrightUp			0x10 //��Ƶ����
#define JVN_VC_BrightDown		0x11
#define JVN_VC_ContrastUp		0x12
#define JVN_VC_ContrastDown		0x13
#define JVN_VC_SaturationUp		0x14
#define JVN_VC_SaturationDown	0x15
#define JVN_VC_HueUp			0x16
#define JVN_VC_HueDown			0x17
#define JVN_VC_SharpnessUp		0x18
#define JVN_VC_SharpnessDown	0x19
#define JVN_VC_PRESENT          0x20 //Ԥ��λ����

typedef struct _PLAY_INFO_
{
	unsigned char ucCommand;//������
	int nClientID;//��Ӧ�Żط�
	
	int nConnectionType;
	
	char strFileName[MAX_PATH];//�ļ���
	
	int nSeekPos;//��λʱ��Ҫ��λ��λ�� ֡
	
}PLAY_INFO;//���Żص�ʹ�õĽṹ

typedef struct STLANTOOLINFO 
{
	unsigned char  uchType;      //��Ϣ���ͣ�1���Թ��ߵĹ㲥��2���Թ��ߵ����ã�3�豸��Ӧ��
	
	/*������Ϣ*/
	char chPName[256]; //�û������������IPC��ȫ�ԣ���ֹ��������
	char chPWord[256]; //���룬�������IPC��ȫ�ԣ���ֹ��������
	int nYSTNUM;       //����ͨ���룬���ڹ������豸��������
	char chCurTime[20];//ϵͳʱ�䣬���ڹ������豸�������� xxxx-xx-xx xx:xx:xx
	char *pchData;     //�������ݣ����ڹ������豸��������
	int nDLen;         //�������ݳ��ȣ����ڹ������豸��������
	
	/*Ӧ����Ϣ*/
	int nCardType;     //�豸���ͣ������豸Ӧ��ʱ�ĸ�����Ϣ
	int	nDate;         //�������� ���� 20091011
	int	nSerial;       //�������к�
	GUID guid;         //ΨһGUID
	char chGroup[4];   //�豸����ţ������豸Ӧ��ʱ�ĸ�����Ϣ
	
	char chIP[16];
	int nPort;
	
}STLANTOOLINFO;//����������������Ϣ����


#define  NET_MOD_UNKNOW 0 // δ��
#define  NET_MOD_WIFI   1 //wifi ģʽ
#define  NET_MOD_WIRED  2 // ����ģʽ

#define  DEV_SET_ALL      0 // ����ȫ��
#define  DEV_SET_NET      1 //�����豸֧�ֵ�����ģʽ
#define  DEV_SET_CUR_NET  2 //�����豸��ǰ����ģʽ
#define  DEV_SET_NAME     3 // ���ñ���

typedef struct  
{
	char chDeviceName[100];//�豸����
	int nCurNetMod;// �豸��ǰ����ģʽ�����ߣ�wifi������
	int nNetMod; //�豸֧�ֵ�����ģʽ��Ϊ ����ģʽ��������ֵ  nNetMod = NET_MOD_WIFI;
}STDEVINFO; //�豸����
typedef struct STBASEYSTNO
{
	char chGroup[4];
	int nYSTNO;
	int nChannel;
	char chPName[MAX_PATH];
	char chPWord[MAX_PATH];
	int nConnectStatus;//����״̬ ����ʱ=0����ѯʱ��ʾ״̬ 0 δ���� 1 ���� 2 ת�� 3����	
}STBASEYSTNO;//����ͨ���������Ϣ�����ڳ�ʼ��С���ֵ�������

typedef struct 
{
	char chGroup[4];
	int nYSTNO;
	int nCardType;
	int nChannelCount;
	char chClientIP[16];
	int nClientPort;
	int nVariety;
	char chDeviceName[100];
#ifndef WIN32
	int bTimoOut;
#else
	BOOL bTimoOut;
#endif
	int nNetMod;//���� �Ƿ����wifi����: nNetMod & NET_MOD_WIFI
	int nCurMod;//���� ��ǰʹ�õ�(wifi������)��nCurMod(NET_MOD_WIFI �� NET_MOD_WIRED)
	char chNickName[36];//�ǳ�
	int nPrivateSize;//�Զ�������ʵ�ʳ���
	char chPrivateInfo[500];//�Զ�����������
}STLANSRESULT;//�������豸�������

/*���ػص�����*/
#ifndef WIN32//LINUX
	typedef int (*FUNC_SCHECKPASS_CALLBACK)(int nLocalChannel, char chClientIP[16], int nClientPort, char *pName, char *pWord);
	typedef void (*FUNC_SCONNECT_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort, char *pName, char *pWord);
	typedef void (*FUNC_SONLINE_CALLBACK)(int nLocalChannel, unsigned char uchType);
	typedef void (*FUNC_SCHECKFILE_CALLBACK)(int nLocalChannel, int nClientID, char chClientIP[16], int nClientPort, char chStartTime[14], char chEndTime[14], unsigned char *pBuffer, int *nSize);
	typedef void (*FUNC_SCHAT_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort, unsigned char  *pBuffer, int nSize);
	typedef void (*FUNC_STEXT_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort, unsigned char  *pBuffer, int nSize);
	typedef void (*FUNC_SYTCTRL_CALLBACK)(int nLocalChannel, int nClientID, int nType, char chClientIP[16], int nClientPort);
	typedef void (*FUNC_SBCDATA_CALLBACK)(int nBCID, unsigned char *pBuffer, int nSize, char chIP[16], int nPort);
	typedef int (*FUNC_SFPLAYCTRL_CALLBACK)(PLAY_INFO* pData);
	typedef void (*FUNC_DLFNAME_CALLBACK)(char chFilePathName[256]);
	typedef int (*FUNC_LANTOOL_CALLBACK)(STLANTOOLINFO* pData);//0������Ӧ1��Ӧ
	typedef void (*FUNC_RECVSERVERMSG_CALLBACK)(int nType, char *chPushMsg, int nMsgLen, struct sockaddr_in *svrAddr);//����ע�᷵����Ϣ nType = 0��ʾע�᷵����Ϣ��=1��ʾ�������ز�����=2ɾ����������ֵ��=3��ѯ��������ֵ
	//nType = 0ʱ��chPushMsgΪ��ֵ�ַ�����-1����δ���ߡ�0ע��ɹ���1����ע���������ַ��ʱ��2�󶨱��ض˿�ʧ�ܡ�3����ע�������ʧ�ܡ�
				   //4ע������ظ���5ע����Ϣ��Ч��6ע���������ֵ���ճ�ʱ��7��������ʧ�ܡ�8���������������ʧ��
	//nType = 1ʱ��������Ϣ���������
	//nType = 2ʱ��ɾ����������ֵ��chPushMsgΪ��ֵ�ַ�����-1ɾ��ʧ�ܡ�0ɾ���ɹ���1����ע���������ַ��ʱ��2�󶨱��ض˿�ʧ�ܡ�3����ע�������ʧ�ܡ�7��������ʧ�ܡ�8���������������ʧ��
	//nType = 3ʱ����ѯ��������ֵ��chPushMsgΪ�����ַ�����6<=nMsgLen<=32ʱ��ѯ�ɹ���chPushMsgΪ�����ַ���������ֵ��ʾ��ѯʧ�ܻ򲻴��ڣ�nMsgLen=0����1����ע���������ַ��ʱ��2�󶨱��ض˿�ʧ�ܡ�3����ע�������ʧ�ܡ�7��������ʧ�ܡ�8���������������ʧ��
	typedef void (*FUNC_RECVCLIENTMSG_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort);//�ֿؿ�����Ϣ�ص���uchType �ص���Ϣ���ͣ�JVN_CMD_VIDEO ��Ƶ���䣬JVN_CMD_VIDEOPAUSE ��ͣ����
#else//WINDOWS
	typedef bool (*FUNC_SCHECKPASS_CALLBACK)(int nLocalChannel, char chClientIP[16], int nClientPort, char *pName, char *pWord);
	typedef void (*FUNC_SCONNECT_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort, char *pName, char *pWord);
	typedef void (*FUNC_SONLINE_CALLBACK)(int nLocalChannel, unsigned char uchType);
	typedef void (*FUNC_SCHECKFILE_CALLBACK)(int nLocalChannel, int nClientID, char chClientIP[16], int nClientPort, char chStartTime[14], char chEndTime[14], unsigned char *pBuffer, int &nSize);
	typedef void (*FUNC_SCHAT_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort, unsigned char  *pBuffer, int nSize);
	typedef void (*FUNC_STEXT_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort, unsigned char  *pBuffer, int nSize);
	typedef void (*FUNC_SYTCTRL_CALLBACK)(int nLocalChannel, int nClientID, int nType, char chClientIP[16], int nClientPort);
	typedef void (*FUNC_SBCDATA_CALLBACK)(int nBCID, unsigned char *pBuffer, int nSize, char chIP[16], int nPort);
	typedef bool (*FUNC_SFPLAYCTRL_CALLBACK)(PLAY_INFO* pData);
	typedef void (*FUNC_DLFNAME_CALLBACK)(char chFilePathName[256]);
	typedef int (*FUNC_LANTOOL_CALLBACK)(STLANTOOLINFO* pData);//0������Ӧ1��Ӧ
	typedef void (*FUNC_RECVSERVERMSG_CALLBACK)(int nType, char *chPushMsg, int nMsgLen, SOCKADDR_IN *svrAddr);//����ע�᷵����Ϣ nType = 0��ʾע�᷵����Ϣ��=1��ʾ�������ز�����=2ɾ����������ֵ��=3��ѯ��������ֵ
	//nType = 0ʱ��chPushMsgΪ��ֵ�ַ�����-1����δ���ߡ�0ע��ɹ���1����ע���������ַ��ʱ��2�󶨱��ض˿�ʧ�ܡ�3����ע�������ʧ�ܡ�
				   //4ע������ظ���5ע����Ϣ��Ч��6ע���������ֵ���ճ�ʱ��7��������ʧ�ܡ�8���������������ʧ��
	//nType = 1ʱ��������Ϣ���������
	//nType = 2ʱ��ɾ����������ֵ��chPushMsgΪ��ֵ�ַ�����-1ɾ��ʧ�ܡ�0ɾ���ɹ���1����ע���������ַ��ʱ��2�󶨱��ض˿�ʧ�ܡ�3����ע�������ʧ�ܡ�7��������ʧ�ܡ�8���������������ʧ��
	//nType = 3ʱ����ѯ��������ֵ��chPushMsgΪ�����ַ�����6<=nMsgLen<=32ʱ��ѯ�ɹ���chPushMsgΪ�����ַ���������ֵ��ʾ��ѯʧ�ܻ򲻴��ڣ�nMsgLen=0����1����ע���������ַ��ʱ��2�󶨱��ض˿�ʧ�ܡ�3����ע�������ʧ�ܡ�7��������ʧ�ܡ�8���������������ʧ��
	typedef void (*FUNC_RECVCLIENTMSG_CALLBACK)(int nLocalChannel, int nClientID, unsigned char uchType, char chClientIP[16], int nClientPort);//�ֿؿ�����Ϣ�ص���uchType �ص���Ϣ���ͣ�JVN_CMD_VIDEO ��Ƶ���䣬JVN_CMD_VIDEOPAUSE ��ͣ����
#endif

typedef void ( * FUNC_EXAM_CALLBACK )(int nExamID,int nErrorID,char *pErrorText);//�ص�����

/*
0	���ɹ�
1	�޷���ȡ������ip��ַ
2	ping���ز�ͨ
3	dns�޷�����
4	��ȡ�������б�����޷�ʹ��http��û����ȷ�ı���
5	�������ͨ�Ų��Ǻܳ�ͨ
6	YST�˿��쳣����Ҫ�����˿�
7	�������ߴ��󣬲ο����صľ�����Ϣ
*/

/*�ֿػص�����*/
#ifndef WIN32//LINUX
	typedef void (*FUNC_CCONNECT_CALLBACK)(int nLocalChannel, unsigned char uchType, char *pMsg, int nPWData);
	typedef void (*FUNC_CNORMALDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nWidth, int nHeight);
	typedef void (*FUNC_CCHECKRESULT_CALLBACK)(int nLocalChannel,unsigned char *pBuffer, int nSize);
	typedef void (*FUNC_CCHATDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize);
	typedef void (*FUNC_CTEXTDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize);
	typedef void (*FUNC_CDOWNLOAD_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nFileLen);
	typedef void (*FUNC_CPLAYDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nWidth, int nHeight, int nTotalFrame);
	typedef void (*FUNC_CBUFRATE_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nRate);
	typedef void (*FUNC_CLANSDATA_CALLBACK)(STLANSRESULT stLSResult);
	typedef void (*FUNC_CBCDATA_CALLBACK)(int nBCID, unsigned char *pBuffer, int nSize, char chIP[16], int bTimeOut);
	typedef int (*FUNC_CLANTDATA_CALLBACK)(STLANTOOLINFO *pLANTData);
	typedef void (*FUNC_COMM_DATA_CALLBACK)(int nType,unsigned char *chGroup,char* chFileName,unsigned char *pBuffer, int *nSize);//nType = 1��д 2�Ƕ�
#else//WINDOWS
	typedef void (*FUNC_CCONNECT_CALLBACK)(int nLocalChannel, unsigned char uchType, char *pMsg, int nPWData);
	typedef void (*FUNC_CNORMALDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nWidth, int nHeight);
	typedef void (*FUNC_CCHECKRESULT_CALLBACK)(int nLocalChannel,unsigned char *pBuffer, int nSize);
	typedef void (*FUNC_CCHATDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize);
	typedef void (*FUNC_CTEXTDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize);
	typedef void (*FUNC_CDOWNLOAD_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nFileLen);
	typedef void (*FUNC_CPLAYDATA_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nWidth, int nHeight, int nTotalFrame);
	typedef void (*FUNC_CBUFRATE_CALLBACK)(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer, int nSize, int nRate);
	typedef void (*FUNC_CLANSDATA_CALLBACK)(STLANSRESULT stLSResult);
	typedef void (*FUNC_CBCDATA_CALLBACK)(int nBCID, unsigned char *pBuffer, int nSize, char chIP[16], BOOL bTimeOut);
	typedef int (*FUNC_CLANTDATA_CALLBACK)(STLANTOOLINFO *pLANTData);
	typedef void (*FUNC_COMM_DATA_CALLBACK)(int nType,unsigned char *chGroup,char* chFileName,unsigned char *pBuffer, int *nSize);//nType = 1��д 2�Ƕ�
#endif

typedef int (*FUNC_DEVICE_CALLBACK)(int nType,char* pGroup,int nYST,char* pIP,int nPort);


typedef void (*FUNC_POSITION_CALLBACK)(int nPosID,char* pKey,char* pCountry,char* pProvince,char* pCity);
/************���ػص�������������***************/
/*FUNC_SCONNECT_CALLBACK*/
#define JVN_SCONNECTTYPE_PCCONNOK  0X01//��PC�ֿ����ӳɹ�
#define JVN_SCONNECTTYPE_DISCONNOK 0X02//�зֿضϿ����ӳɹ�
#define JVN_SCONNECTTYPE_DISCONNE  0X03//�����쳣�Ͽ�
#define JVN_SCONNECTTYPE_MOCONNOK  0X04//���ƶ��豸�ֿ����ӳɹ�
/*FUNC_SONLINE_CALLBACK*/
#define JVN_SONLINETYPE_ONLINE     0x01//����
#define JVN_SONLINETYPE_OFFLINE    0x02//����
#define JVN_SONLINETYPE_CLEAR      0x03//YST������Ч��Ӧ�����������

/************�ֿػص�������������***************/
/*FUNC_CCONNECT_CALLBACK*/
#define JVN_CCONNECTTYPE_CONNOK    0X01//���ӳɹ�
#define JVN_CCONNECTTYPE_DISOK     0X02//�Ͽ����ӳɹ�
#define JVN_CCONNECTTYPE_RECONN    0X03//�����ظ�����
#define JVN_CCONNECTTYPE_CONNERR   0X04//����ʧ��
#define JVN_CCONNECTTYPE_NOCONN    0X05//û����
#define JVN_CCONNECTTYPE_DISCONNE  0X06//�����쳣�Ͽ�
#define JVN_CCONNECTTYPE_SSTOP     0X07//����ֹͣ�����ӶϿ�
#define JVN_CCONNECTTYPE_DISF      0x08//�Ͽ�����ʧ��


/*����ֵ*/
#define JVN_RETURNOK    0//�ɹ�
#define JVN_PARAERROR   1//��������
#define JVN_RETURNERROR 2//ʧ��
#define JVN_NOMEMERROR  3//�ڴ��Ӳ�̿ռ䲻��

//����IP�Σ������������豸ʱ���á�
typedef struct
{
	char startip[16];//��ʼIP
	char endip[16];//��ֹIP
}IPSECTION;

typedef struct 
{
	char chIP[16];
	int nPort;
	unsigned char uchStatus;// 0 1
	unsigned char uchType;
	unsigned char uchProcType;
	int nDownSpeed;// KB/s
	float fDownTotal;// M
	float fUpTotal;// M
}STPTINFO;

/*��ʼ��SDKʱ�����豸��ص�һЩ��Ϣ�������ڲ����ݲ�ͬ��Ʒ���ò�ͬ�Ĵ���*/
typedef struct 
{
	int nType;//��Ʒ���� 0��ͨĬ�ϲ�Ʒ��1�忨; 2DVR; 3IPC; 4JNVR; 5NVR; 6���ð�СIPC;
	int nMemLimit;//�ڴ����� 0��ͨĬ�ϲ�Ʒ��1�ڴ����(����������20M����)��2�ڴ��������(����Լ20M����)��3�ڴ����(����С��15M����)��
	              //�ڴ������ǰ���£��ڴ�����Խ�ã���������Ч����Խ�ã������ȷ��������Ϊ0��
}STDeviceType;

/*�������ʱ�����ߴ���ṹ*/
typedef struct 
{
	char chGroup[4];//����ţ�����"A" "AAAA"
	int nCardType;  //��ϵ
	int	nDate;      //�������� ���� 20091011
	int	nSerial;    //�������к�
	GUID guid;      //ΨһGUID MAPIGUID.H
}STGetNum;
/*��ʼ��ʱ�����ߴ���Ľṹ*/
typedef struct
{
    int nCardType; /*��Ʒ���ͣ����磺0xE71A, 0xD800,0xB800, 960*/
    int    nDate;     //��������
    int    nSerial;   //�������к�
    GUID gLoginKey;//�忨GUID
    int  nYstNum;  //����ͨ����
    char chGroup[4];//����ţ�����"A" "AAAA"
    int  nChannelCount; //����ͨ������Ŀ  //old

	unsigned long dwProductType;//��Ʒ��������/*���磺0xE71A4010,0xD8006001,0xB8007001,0xc896ffff*/
    unsigned long dwEncryVer; //���ܰ汾, 0xB567709F������оƬ�а�������ͨ���룬�����ݿ�;0xF097765B�����������룬�����ݿ�;0xB56881B0:�������룬�����ݿ�;
    unsigned long dwDevVer; //����оƬӲ���汾
    int   nUIVer;//���ذ汾
    unsigned long dwOemid;//����id
    unsigned long dwUser;//������ԱID
    
   
    int nMaxConnNum;      //���������
    int nZone;//����-086�й�
    int nSystemType;//ϵͳ�ͺ�-��1�ֽ�ϵͳ����(0x1:windows 0x2:linux 0x3:MacOS 0x4:��׿ 0x5:����)����3�ֽ�ϵͳ�汾�ţ���ϵͳ�汾�����ע��
    /*Windows:6.1; 6.0; 5.2; 5.1; 5.0; 4.9; 4.1; 4.0; 3.1; 3.0; 2.0; 1.0 ��
    linux :2.6; 2.4; 2.2; 2.0; 1.2; 1.1; 1.0 ��
    MAC OS:10.7; 10.6; 10.5; 10.4; 10.3; 10.2; 10.1; 10.0 ��;
    Android 1.1; 1.5; 1.6; 2.0; 2.1; 2.2; 2.3; 2.4; 3.0; 3.1; 3.2; 4.0; 4.1; 4.2; 4.4��    */
    /*���磺win7: 0x103d, win XP: 0x1033; linux2.6: 0x201a, linux2.5: 0x2019; MacOS10.7: 0x306B, MacOS10.6:0x306A; Android4.0: 0x4028; Android4.4: 0x402c*/
    
    char chProducType[64];//��Ʒ�ͺ�-�ַ���
    char chDevType[16];//Ӳ���ͺ�-�ַ���
}STOnline;





typedef struct
{
	unsigned int nTypeLens; //YST_AS_REGCARD	
	//��������
	int nSize;
	char *pacData;
}SOCKET_DATA_TRAN;

//�����ϴ����ݽṹ����һ������ʱ�ϴ��������ñ仯���ϴ�
typedef struct _CHANNEL_INFO
{
	unsigned char uchChannel;	 //ͨ����� ��1��ʼ
	unsigned char uchChnInfo;	//0x0011 0001 ����λ0011��ʾ��������������λ��00��ʾ�������͡�01�Ƿ�������ͨ���� 
	long wBitRate[5];	//����ֵ�����֧��5������λkbps
}CHANNEL_INFO;//17�ֽ�

/***************** �յ��ص�����ʱ���� *****************/


typedef struct
{
	unsigned char uchMemoryUsage;//�ڴ�ʹ���� �ٷֱ�
	unsigned char uchCPUUsage;//CPUʹ���� �ٷֱ�
	unsigned char uchCurrNetMode;//����ģʽ-/*#define NET_MOD_UNKNOW 0 δ����#define NET_MOD_WIFI 1 wifiģʽ��#define NET_MOD_WIRED 2 ����ģʽ*/
	unsigned char uchCount;//CHANNEL_CONNCNT����
	char chChnConnData[500];//uchCount��CHANNEL_CONNCNT�ṹ��
}JVSERVER_INFO;

#endif
