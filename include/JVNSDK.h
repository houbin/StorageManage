#ifndef JVNSDK_H
#define JVNSDK_H

#include "JVNSDKDef.h"
#ifndef WIN32
	#ifdef __cplusplus
		#define JVCLIENT_API extern "C"
	#else
		#define JVCLIENT_API
	#endif
#else
#define JVCLIENT_API extern "C" __declspec(dllexport)
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                     //
//                                      �ֿض˽ӿ�                                                     //
//                                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/***************************************�ӿ��嵥********************************************************
JVNC_InitSDK -----------------01 ��ʼ��SDK��Դ
JVNC_ReleaseSDK --------------02 �ͷ�SDK��Դ��������󱻵���
JVNC_RegisterCallBack --------03 ���÷ֿض˻ص�����
JVNC_Connect -----------------04 ����ĳͨ���������
JVNC_DisConnect --------------05 �Ͽ�ĳͨ����������
JVNC_SendData ----------------06 ��������
JVNC_EnableLog ---------------07 ����д������־�Ƿ���Ч
JVNC_SetLanguage -------------08 ������־/��ʾ��Ϣ����(Ӣ��/����) 
JVNC_TCPConnect --------------09 ��ʽ����ĳͨ���������
JVNC_GetPartnerInfo ----------10 ��ȡ���ڵ���Ϣ
JVNC_RegisterRateCallBack ----11 ע�Ỻ����Ȼص�����
JVNC_StartLANSerchServer -----12 �����������������������ά�豸
JVNC_StopLANSerchServer ------13 ֹͣ��������
JVNC_LANSerchDevice ----------14 ������������ά�豸
JVNC_SetLocalFilePath --------15 �Զ��屾���ļ��洢·����������־�����ɵ������ؼ��ļ���
JVNC_SetDomainName -----------16 �����µ�������ϵͳ�������ȡ�������б�
JVNC_WANGetChannelCount ------17 ͨ��������ȡĳ������ͨ���������е�ͨ������
JVNC_StartBroadcastServer ----18 �����Զ���㲥����
JVNC_StopBroadcastServer -----19 ֹͣ�Զ���㲥����
JVNC_BroadcastOnce -----------20 ���͹㲥��Ϣ
JVNC_ClearBuffer -------------21 �����ػ���

JVNC_EnableHelp---------------22 ����/ͣ�ÿ������ӷ���(����ͨС����ʹ��)
JVNC_SetHelpYSTNO-------------23 ���ö�ĳЩ����ͨ����ĸ���֧��
JVNC_GetHelpYSTNO-------------24 ��ȡ��ĳЩ����ͨ����ĸ���֧��
JVNC_EnableLANTool------------25 ������������������þ������е��豸
JVNC_LANToolDevice------------26 �����������еĿ������豸
JVNC_SendCMD------------------27 �����ض˷���һЩ��������
JVNC_AddFSIpSection-----------28 �������ȷ��͹㲥��IP��
JVNC_MOLANSerchDevice --------29 �ֻ�������������ά�豸
JVNC_RegisterCommonCallBack---30 �ֻ�ר�ûص�ע��
JVNC_QueryPosition------------31 ��ǰ�����ѯ
JVNC_GetExamItem--------------32 ��ȡ��Ҫ������Ŀ
JVNC_ExamItem-----------------33 �����Ŀ
JVNC_GetDemo------------------34 ��ȡ��ʾ��
JVNC_HelperRemove-------------35 ɾ�������ں���
JVNC_HelpQuery----------------36 ��ѯ�����Ƿ����ӳɹ�
JVNC_QueryDevice--------------37 ��ѯ�豸�ǲ����Ѿ����óɹ�(�ֻ�����)
JVNC_SetNet3G-----------------38 ���õ�ǰ���绷��Ϊ3G��һ������
JVNC_WANGetChannelCountByNickName--39 ���ݱ���ͨ��������ѯͨ����
JVNC_GetPositionID------------41 ��ѯ����
*******************************************************************************************************/


/****************************************************************************
*����  : JVNC_InitSDK
*����  : ��ʼ��SDK��Դ�����뱻��һ������ 
*����  : [IN] nLocalStartPort ��������ʹ�õ���ʼ�˿� <0ʱĬ��9200
*����ֵ: TRUE     �ɹ�
         FALSE    ʧ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_InitSDK(int nLocStartPort);
#else
	JVCLIENT_API bool __stdcall	JVNC_InitSDK(int nLocStartPort);
#endif

/****************************************************************************
*����  : JVNC_ReleaseSDK
*����  : �ͷ�SDK��Դ��������󱻵��� 
*����  : ��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_ReleaseSDK();
#else
	JVCLIENT_API void __stdcall	JVNC_ReleaseSDK();
#endif

/****************************************************************************
*����  : JVNC_RegisterSCallBack
*����  : ���÷ֿض˻ص����� 
*����  : [IN] ConnectCallBack   ����������״���ص�����
*����ֵ: ��
*����  : �ֿض˻ص�����������
             �����ض�ͨ��״̬������      (����״̬)
			 ʵʱ��ش���                (�յ�ʵʱ�������)
		     ¼����������������      (�յ�¼��������)
			 ��������/�ı����캯��       (Զ���������ı�����)
			 Զ�����غ�����              (Զ����������)
			 Զ�̻طź�����              (Զ�̻ط�����)
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void  JVNC_RegisterCallBack(FUNC_CCONNECT_CALLBACK ConnectCallBack,
													FUNC_CNORMALDATA_CALLBACK NormalData,
													FUNC_CCHECKRESULT_CALLBACK CheckResult,
													FUNC_CCHATDATA_CALLBACK ChatData,
													FUNC_CTEXTDATA_CALLBACK TextData,
													FUNC_CDOWNLOAD_CALLBACK DownLoad,
													FUNC_CPLAYDATA_CALLBACK PlayData);
#else
	JVCLIENT_API void __stdcall	JVNC_RegisterCallBack(FUNC_CCONNECT_CALLBACK ConnectCallBack,
													FUNC_CNORMALDATA_CALLBACK NormalData,
													FUNC_CCHECKRESULT_CALLBACK CheckResult,
													FUNC_CCHATDATA_CALLBACK ChatData,
													FUNC_CTEXTDATA_CALLBACK TextData,
													FUNC_CDOWNLOAD_CALLBACK DownLoad,
													FUNC_CPLAYDATA_CALLBACK PlayData);
#endif

/****************************************************************************
*����  : JVNC_Connect
*����  : ����ĳͨ���������
*����  : 
		[IN] nType ����ӵ���������,0 IP  1 ���� 2 �ǳ� 3ֻTCP 4 ���� + �˿�
		[IN] nLocalChannel ����ͨ���� >=1
         [IN] nChannel      ����ͨ���� >=1
		 [IN] pchServerIP   ��nYSTNO<0ʱ���ò���ָͨ������IP����nYSTNO>=0ʱ��Ч.
		 [IN] nServerPort   ��nYSTNO<0ʱ���ò���ָͨ������port����nYSTNO>=0ʱ��Ч.
		 [IN] pchPassName   �û���
		 [IN] pchPassWord   ����
		 [IN] nYSTNO        ����ͨ���룬��ʹ��ʱ��-1
		 [IN] chGroup       ����ţ�����"A" "AAAA" ʹ������ͨ����ʱ��Ч
		 [IN] bLocalTry     �Ƿ��������̽��
		 [IN] nTURNType     YST��ʽʱ��Ч,ת����������(����ת��\����ת��(Ĭ��ֵ)\����ת��)
*����ֵ: TRUE  �ɹ�
         FALSE ʧ��
*����  : nLocalChannel <= -2 �� nChannel = -1 �����ӷ���˵�����ͨ����
         �ɱܿ���Ƶ���ݣ������շ���ͨ����
*****************************************************************************/
#ifndef WIN32
	#ifdef MOBILE_CLIENT
	JVCLIENT_API void JVNC_Connect(int nType,int nLocalChannel,int nChannel,
		                          char *pchServerIP,int nServerPort,
		                          char *pchPassName,char *pchPassWord,
		                          int nYSTNO,char chGroup[4],
		                          int bLocalTry,
		                          int nTURNType,
		                          int bCache,
								  int nConnectType,
								  char *chNickName,
								  int bSendRequestVido,
								  int bVIP);
    #else
	JVCLIENT_API void JVNC_Connect(int nType,int nLocalChannel,int nChannel,
											char *pchServerIP,int nServerPort,
											char *pchPassName,char *pchPassWord,
											int nYSTNO,char chGroup[4],
											int bLocalTry,
											int nTURNType,
											int bCache,
											char *chNickName,
											int bVIP);
    #endif
#else
	JVCLIENT_API void __stdcall	JVNC_Connect(int nType,int nLocalChannel,int nChannel,
											char *pchServerIP,int nServerPort,
											char *pchPassName,char *pchPassWord,
											int nYSTNO,char chGroup[4],
											int bLocalTry,
											int nTURNType,
											int bCache,
											char *chNickName,
											int bVIP);
#endif

/****************************************************************************
*����  : JVNC_DisConnect
*����  : �Ͽ�ĳͨ���������� 
*����  : [IN] nLocalChannel ����ͨ���� >=1
*����ֵ: ��
*����  : 
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_DisConnect(int nLocalChannel);
#else
	JVCLIENT_API void __stdcall	JVNC_DisConnect(int nLocalChannel);
#endif

/****************************************************************************
*����  : JVNC_SendData
*����  : �������� 
*����  : [IN] nLocalChannel   ����ͨ���� >=1
         [IN] uchType          �������ͣ��������󣻸��ֿ��ƣ�����Ӧ��
         [IN] pBuffer         ������������
		 [IN] nSize           �������ݳ���
*����ֵ: ��
*����  : ��ͨ�����ӵ����ط�������
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_SendData(int nLocalChannel, unsigned char uchType, unsigned char *pBuffer,int nSize);
#else
	JVCLIENT_API void __stdcall	JVNC_SendData(int nLocalChannel, unsigned char uchType, void *pBuffer,int nSize);
#endif

/****************************************************************************
*����  : JVNS_EnableLog
*����  : ����д������־�Ƿ���Ч 
*����  : [IN] bEnable  TRUE:����ʱд��־��FALSE:��д�κ���־
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_EnableLog(int bEnable);
#else
	JVCLIENT_API void __stdcall	JVNC_EnableLog(bool bEnable);
#endif

/****************************************************************************
*����  : JVNC_SetLanguage
*����  : ������־/��ʾ��Ϣ����(Ӣ��/����) 
*����  : [IN] nLgType  JVNS_LANGUAGE_ENGLISH/JVNS_LANGUAGE_CHINESE
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_SetLanguage(int nLgType);
#else
	JVCLIENT_API void __stdcall	JVNC_SetLanguage(int nLgType);
#endif

/****************************************************************************
*����  : JVNC_TCPConnect
*����  : TCP��ʽ����ĳͨ���������
*����  : [IN] nLocalChannel ����ͨ���� >=1
         [IN] nChannel      ����ͨ���� >=1
		 [IN] pchServerIP   ��nYSTNO<0ʱ���ò���ָͨ������IP����nYSTNO>=0ʱ��Ч.
		 [IN] nServerPort   ��nYSTNO<0ʱ���ò���ָͨ������port����nYSTNO>=0ʱ��Ч.
		 [IN] pchPassName   �û���
		 [IN] pchPassWord   ����
		 [IN] nYSTNO        ����ͨ���룬��ʹ��ʱ��-1
		 [IN] chGroup       ����ţ�����"A" "AAAA" ʹ������ͨ����ʱ��Ч
		 [IN] bLocalTry     �Ƿ��������̽��
		 [IN] nConnectType  ���ӷ�ʽ��TYPE_PC_TCP/TYPE_MO_TCP
		 [IN] nTURNType     ת����������(����ת��\����ת��\����ת��)
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_TCPConnect(int nLocalChannel,int nChannel,
									char *pchServerIP,int nServerPort,
									char *pchPassName,char *pchPassWord,
									int nYSTNO,char chGroup[4],
									int bLocalTry,
									int nConnectType,
									int nTURNType);
#else
	JVCLIENT_API void __stdcall	JVNC_TCPConnect(int nLocalChannel,int nChannel,
												char *pchServerIP,int nServerPort,
												char *pchPassName,char *pchPassWord,
												int nYSTNO,char chGroup[4],
												BOOL bLocalTry,
												int nConnectType,
												int nTURNType);
#endif


/****************************************************************************
*����  : JVNC_GetPartnerInfo
*����  : ��ȡ���ڵ���Ϣ 
*����  : [IN] nLocalChannel   ����ͨ���� >=1
         [OUT] pMsg   ��Ϣ����
		              (�Ƿ�ಥ(1)+�����ܸ���(4)+����������(4)+[IP(16) + port(4)+����״̬(1)+�����ٶ�(4)+��������(4)+�ϴ�����(4)]
					                +[...]...)
		 [OUT] nSize  ��Ϣ�ܳ���
*����ֵ: ��
*����  : ����Ƶ���Ͻ�̫�ߣ������Ӱ����Ƶ�����ٶȣ�
         Ƶ���̶ȶȲ��ܵ���1�룬�����2�����ϻ����ʱ�䣬ʱ��Խ��Ӱ��ԽС��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_GetPartnerInfo(int nLocalChannel, char *pMsg, int *nSize);
#else
	JVCLIENT_API void __stdcall	JVNC_GetPartnerInfo(int nLocalChannel, char *pMsg, int &nSize);
#endif

#ifndef WIN32
	JVCLIENT_API void JVNC_RegisterRateCallBack(FUNC_CBUFRATE_CALLBACK BufRate);
#else
	JVCLIENT_API void __stdcall	JVNC_RegisterRateCallBack(FUNC_CBUFRATE_CALLBACK BufRate);
#endif

/****************************************************************************
*����  : JVNC_StartLANSerchServer
*����  : �����������������������ά�豸
*����  : [IN] nLPort      ���ط���˿ڣ�<0ʱΪĬ��9400
         [IN] nServerPort �豸�˷���˿ڣ�<=0ʱΪĬ��9103,����ͳһ��Ĭ��ֵ������ƥ��
		 [IN] LANSData    ��������ص�����
		 [IN] nType			0 ֻ���������� 1 ����ping ���Կ����� 2 ��������C��
*����ֵ: TRUE/FALSE
*����  : ��������������ſ��Խ��������������������ͨ��JVNC_LANSerchDevice�ӿ�ָ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_StartLANSerchServer(int nLPort, int nServerPort, FUNC_CLANSDATA_CALLBACK LANSData,int nType);
#else
	JVCLIENT_API bool __stdcall	JVNC_StartLANSerchServer(int nLPort, int nServerPort, FUNC_CLANSDATA_CALLBACK LANSData,int nType);
#endif

/****************************************************************************
*����  : JVNC_StopLANSerchServer
*����  : ֹͣ�������� 
*����  : ��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_StopLANSerchServer();
#else
	JVCLIENT_API void __stdcall	JVNC_StopLANSerchServer();
#endif

/****************************************************************************
*����  : JVNC_LANSerchDevice
*����  : ������������ά�豸 
*����  : [IN] chGroup     ����ţ������+nYSTNO��ȷ��Ψһ�豸
         [IN] nYSTNO      ��������ĳ����ͨ������豸��>0��Ч
         [IN] nCardType   ����ĳ�ͺŵ��豸��>0��Ч,��nYSTNO>0ʱ�ò�����Ч
		 [IN] chDeviceName����ĳ���������豸��strlen>0��Ч����nYSTNO>0ʱ��Ч
		 [IN] nVariety    ����ĳ�������豸��1�忨;2DVR;3IPC;>0��Ч,��nYSTNO>0ʱ�ò�����Ч
		 [IN] nTimeOut    ����������Чʱ�䣬��λ���롣������ʱ��Ľ������������
		                  ��ʱʱ�䵽���ص������н��õ���ʱ��ʾ��Ϊ����������־��
						  �������ʹ��SDK��ʱ���������Ϊ0����ʱ���ǿȫ�����ظ������ߡ�
						  
						  ͬ���ε��豸һ������<500��ʱ������������
						  �豸����������������2000��ȷ������������ȫ�棻
						  ���弴�������ɸ�����Ҫ����̣�Խ��Խ������©��ͬ���ε��豸��
*����ֵ: ��
*����  : ��������ͬʱΪ0ʱ����������������������ά�豸
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API bool JVNC_LANSerchDevice(char chGroup[4], int nYSTNO, int nCardType, int nVariety, char chDeviceName[100], int nTimeOut,unsigned int unFrequence);
#else
	JVCLIENT_API bool __stdcall	JVNC_LANSerchDevice(char chGroup[4], int nYSTNO, int nCardType, int nVariety, char chDeviceName[100], int nTimeOut,unsigned int unFrequence );
#endif

/****************************************************************************
*����  : JVNC_SetLocalFilePath
*����  : �Զ��屾���ļ��洢·����������־�����ɵ������ؼ��ļ��� 
*����  : [IN] chLocalPath  ·�� ���磺"C:\\jovision"  ����jovision���ļ���
*����ֵ: ��
*����  : ����ʹ���ڴ濽��ʱ��ע���ʼ�����ַ�������'\0'����
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_SetLocalFilePath(char chLocalPath[256]);
#else
	JVCLIENT_API bool __stdcall	JVNC_SetLocalFilePath(char chLocalPath[256]);
#endif

/****************************************************************************
*����  : JVNC_SetDomainName 
*����  : �����µ�������ϵͳ�������ȡ�������б�
*����  : [IN]  pchDomainName     ����
[IN]  pchPathName       �����µ��ļ�·���� ���磺"/down/YSTOEM/yst0.txt"
*����ֵ: TRUE  �ɹ�
FALSE ʧ��
*����  : ϵͳ��ʼ��(JVNS_InitSDK)�������
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_SetDomainName(char *pchDomainName,char *pchPathName);
#else
	JVCLIENT_API bool __stdcall	JVNC_SetDomainName(char *pchDomainName,char *pchPathName);
#endif

/****************************************************************************
*����  : JVNC_WANGetChannelCount
*����  : ͨ��������ȡĳ������ͨ���������е�ͨ������
*����  : [IN]  chGroup   �����
         [IN]  nYstNO    ����ͨ����
		 [IN]  nTimeOutS �ȴ���ʱʱ��(��)
*����ֵ: >0  �ɹ�,ͨ����
         -1 ʧ�ܣ�ԭ��δ֪
		 -2 ʧ�ܣ�����δ����
		 -3 ʧ�ܣ����ذ汾�Ͼɣ���֧�ָò�ѯ
*����  : ϵͳ��ʼ��(JVNS_InitSDK)��� �ɶ�������
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_WANGetChannelCount(char chGroup[4], int nYSTNO, int nTimeOutS);
#else
	JVCLIENT_API int __stdcall	JVNC_WANGetChannelCount(char chGroup[4], int nYSTNO, int nTimeOutS);
#endif

/****************************************************************************
*����  : JVNC_WANGetChannelCountByNickName
*����  : ͨ��������ȡĳ������ͨ���������е�ͨ������
*����  : [IN]  chNickName   ���� ֧��6-32�ֽ�UTF8�ַ�������ֹʹ�������ַ�����ʽ���ַ���,�ַ����б������һ�������ַ�������@ & * _
		 [IN]  nTimeOutS �ȴ���ʱʱ��(��)
*����ֵ: >0  �ɹ�,ͨ����
         0  ʧ�ܣ���������
		 -1 ʧ�ܣ�����δ����
		 -2 ʧ�ܣ����ذ汾�Ͼɣ���֧�ָò�ѯ
		 -3 ʧ�ܣ�����ԭ��
		 -4 ʧ�ܣ�����������
*����  : ϵͳ��ʼ��(JVN_InitSDK)��� �ɶ�������
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_WANGetChannelCountByNickName(char *chNickName, int nTimeOutS);
#else
	JVCLIENT_API int __stdcall	JVNC_WANGetChannelCountByNickName(char *chNickName, int nTimeOutS);
#endif

/****************************************************************************
*����  : JVNC_StartBroadcastServer
*����  : �����Զ���㲥���� 
*����  : [IN] nLPort      ���ط���˿ڣ�<0ʱΪĬ��9500
         [IN] nServerPort �豸�˷���˿ڣ�<=0ʱΪĬ��9106,����ͳһ��Ĭ��ֵ������ƥ��
		 [IN] BroadcastData  �㲥����ص�����
*����ֵ: TRUE/FALSE
*����  : �����˹㲥����ſ��Խ��չ㲥������㲥����ͨ��JVNC_BroadcastOnce�ӿ�ָ����
         �˿�������һ��ע����豸������ض˿������𣬷������ݽ��쳣��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_StartBroadcastServer(int nLPort, int nServerPort, FUNC_CBCDATA_CALLBACK BCData);
#else
	JVCLIENT_API bool __stdcall	JVNC_StartBroadcastServer(int nLPort, int nServerPort, FUNC_CBCDATA_CALLBACK BCData);
#endif

/****************************************************************************
*����  : JVNC_StopBroadcastServer
*����  : ֹͣ�Զ���㲥���� 
*����  : ��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_StopBroadcastServer();
#else
	JVCLIENT_API void __stdcall	JVNC_StopBroadcastServer();
#endif

/****************************************************************************
*����  : JVNC_BroadcastOnce
*����  : ���͹㲥��Ϣ 
*����  : [IN] nBCID       �㲥ID,�ɵ����߶���,�����ڻص�������ƥ�����ֱ��ι㲥
         [IN] pBuffer     �㲥��������,���ݲ�������10k,�����������ಿ��
         [IN] nSize       �㲥�������ݳ���
		 [IN] nTimeOut    ���ι㲥��Чʱ�䣬��λ���롣������ʱ��Ľ������������
		                  ��ʱʱ�䵽���ص������н��õ���ʱ��ʾ��Ϊ����������־��
						  �������ʹ��SDK��ʱ���������Ϊ0����ʱ���ǿȫ�����ظ������ߡ�
*����ֵ: ��
*����  : Ŀǰ�ù����ݲ�֧�ֲ����㲥������������ʱ���һ�ι㲥������֮ǰ�Ĺ㲥��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_BroadcastOnce(int nBCID, unsigned char *pBuffer, int nSize, int nTimeOut);
#else
	JVCLIENT_API BOOL __stdcall JVNC_BroadcastOnce(int nBCID, BYTE *pBuffer, int nSize, int nTimeOut);
#endif

/****************************************************************************
*����  : JVNC_ClearBuffer
*����  : ��ձ��ػ��� 
*����  : [IN] nLocalChannel ����ͨ���� >=1
*����ֵ: ��
*����  : ������ͨģʽ������Ч���ಥ���Ӳ�����ӱ������
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API void JVNC_ClearBuffer(int nLocalChannel);
#else
	JVCLIENT_API void __stdcall	JVNC_ClearBuffer(int nLocalChannel);
#endif 

/****************************************************************************
*����  : JVNC_SetLocalNetCard
*����  : ������һ������ eth0,eth1,... for linux or 0, 1, 2,...for win  
*����  : [IN] strCardName   ����
*����ֵ: �ɹ� TRUE ,ʧ�� FALSE
*����  : 2013 5
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_SetLocalNetCard(char* strCardName);
#else
	JVCLIENT_API BOOL __stdcall JVNC_SetLocalNetCard(char* strCardName);
#endif

/****************************************************************************
*����  : JVNC_EnableHelp
*����  : ����/ͣ�ÿ������ӷ���
*����  : [IN] bEnable TRUE����/FALSE�ر�
         [IN] nType  ��ǰʹ������˭����bEnableΪTRUEʱ��Ч
		             1 ��ǰʹ����������ͨС����(��������)
		             2 ��ǰʹ����������ͨ�ͻ��ˣ�֧�ֶ������̵�С����
		             3 ��ǰʹ����������ͨ�ͻ��ˣ���֧�ֶ������̵�С����
		[IN] nMaxLimit ���ӵ������
*����ֵ: ��
*����  : ���øù��ܺ�����SDK����趨�ĺ�������������ٵ��Ż���
		 ���øù��ܺ�����SDK��֧��С���ֺͿͻ���֮����н�����
		 ����ֿض�֧��С���ֽ��̣�����С���ֶ�ʹ��nType=1���ͻ���ʹ��nType=2���ɣ�
		 ����ͻ��˲�֧��С���ֽ��̣���ͻ���ʹ��nType=3���ɣ������ֻ��ͻ��ˣ�
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_EnableHelp(int bEnable, int nType,int nMaxLimit);
#else
	JVCLIENT_API BOOL __stdcall JVNC_EnableHelp(BOOL bEnable, int nType);
#endif

/****************************************************************************
*����  : JVNC_SetHelpYSTNO
*����  : ���ö�ĳЩ����ͨ����ĸ���֧��
*����  : [IN] pBuffer ����ͨ���뼯�ϣ���STBASEYSTNO�ṹ��ɣ���������������
                      STBASEYSTNO st1,STBASEYSTNO st1;
					  pBuffer�����ݾ���:
					  memcpy(bBuffer, &st1, sizeof(STBASEYSTNO));
					  memcpy(&bBuffer[sizeof(STBASEYSTNO)], &st2, sizeof(STBASEYSTNO));
         [IN] nSize   pBuffer��ʵ����Ч���ȣ����������������Ϊ��
		              2*sizeof(STBASEYSTNO);
					  
*����ֵ: ��
*����  : ����ͨС���ֶ�ʹ�ã�
         �ͻ��˲�֧��С����ʱ�ͻ���ʹ�ã�

         ��Ӻ�����SDK�����Щ����ͨ��������������ٵ��Ż���
		 ���ǳ�ʼ���ã����������пͻ���Ҳ����Щ�µĺ��룬
		 �ᶯ̬��ӵ��ڲ���
		 STBASEYSTNOS ����ͨ����,STYSTNO����ο�JVNSDKDef.h
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_SetHelpYSTNO(unsigned char *pBuffer, int nSize);
#else
	JVCLIENT_API BOOL __stdcall JVNC_SetHelpYSTNO(BYTE *pBuffer, int nSize);
#endif

/****************************************************************************
*����  : JVNC_GetHelpYSTNO
*����  : ��ȡ��ǰ��֪������ͨ�����嵥
*����  : [IN/OUT] pBuffer �ɵ����߿����ڴ棻
                          ��������ͨ���뼯�ϣ���STBASEYSTNO�ṹ��ɣ���������������
                          STBASEYSTNO st1,STBASEYSTNO st1;
                          pBuffer�����ݾ���:
                          memcpy(bBuffer, &st1, sizeof(STBASEYSTNO));
                          memcpy(&bBuffer[sizeof(STBASEYSTNO)], &st2, sizeof(STBASEYSTNO));
         [IN/OUT] nSize   ����ʱ�������pBuffer��ʵ�ʿ��ٳ��ȣ�
		                  ���ú󷵻ص���pBuffer��ʵ����Ч���ȣ����������������Ϊ��
                          2*sizeof(STBASEYSTNO);
*����ֵ: -1  ���󣬲�������pBufferΪ�ջ��Ǵ�С�����Դ洢�����
          0  ����δ����
          1  �ɹ�
*����  : ����ͨС���ֶ�ʹ�ã�
         �ͻ��˲�֧��С����ʱ�ͻ���ʹ�ã�

         ���ǳ�����������֪�����к��룬��С���ֻ����Щ������������Ż�֧�֣�
		 �ýӿڽ����ڲ�ѯ�������ڲ����Զ���ӣ���ѯ������᳤����Ч��
		 STBASEYSTNOS ����ͨ����,STYSTNO����ο�JVNSDKDef.h
*****************************************************************************/
#ifndef WIN32 
	JVCLIENT_API int JVNC_GetHelpYSTNO(unsigned char *pBuffer, int *nSize);
#else
	JVCLIENT_API int __stdcall JVNC_GetHelpYSTNO(BYTE *pBuffer, int &nSize);
#endif

/****************************************************************************
*����  : JVNC_GetYSTStatus
*����  : ��ȡĳ������ͨ���������״̬
*����  : [IN] chGroup  ����ͨ����ı���ţ�
         [IN] nYSTNO   ����ͨ����
		 [IN] nTimeOut ��ʱʱ��(��)������>=2��
*����ֵ: -1  ���󣬲�������chGroupΪ�ջ���nYSTNO<=0��
          0  ���ز�ѯ̫Ƶ�����Ժ�����
          1  ��������
		  2  ���벻����
		  3  ��ѯʧ�ܣ��������ж������Ƿ�����
*����  : 1.ע�⣬�ú���Ŀǰ���������ֻ�,pc���ݲ�����ʹ�ã�
         2.�ú�����ͬһ�����벻����Ƶ�����ã����>=10s;
		 3.�ú����Բ�ͬ���벻����Ƶ�����ã����>=1s;
*****************************************************************************/
#ifndef WIN32 
	JVCLIENT_API int JVNC_GetYSTStatus(char chGroup[4], int nYSTNO, int nTimeOut);
#else
	JVCLIENT_API int __stdcall JVNC_GetYSTStatus(char chGroup[4], int nYSTNO, int nTimeOut);
#endif

/****************************************************************************
*����  : JVNC_EnableLANTool
*����  : ������������������þ������е��豸 
*����  : [IN] nEnable     1���� 0�ر�
         [IN] nLPort      ���ط���˿ڣ�<0ʱΪĬ��9600
         [IN] nServerPort �豸�˷���˿ڣ�<=0ʱΪĬ��9104,����ͳһ��Ĭ��ֵ������ƥ��
		 [IN] LANTData    ��������ص�����
*����ֵ: 0ʧ��/1�ɹ�
*����  : ��������������ſ��Խ��������������������ͨ��JVNC_LANToolDevice�ӿ�ָ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_EnableLANTool(int nEnable, int nLPort, int nServerPort, FUNC_CLANTDATA_CALLBACK LANTData);
#else
	JVCLIENT_API int __stdcall	JVNC_EnableLANTool(int nEnable, int nLPort, int nServerPort, FUNC_CLANTDATA_CALLBACK LANTData);
#endif

/****************************************************************************
*����  : JVNC_LANToolDevice
*����  : �����������еĿ������豸 
*����  : [IN] chPName     �û���
		 [IN] chPWord     ���룬ʹ���û�����������IPC�İ�ȫ�ԣ�������Ҳ����ҪȨ�޵�
         [IN] nTimeOut    ����������Чʱ�䣬��λ���롣������ʱ��Ľ������������
		                  ��ʱʱ�䵽���ص������н��õ���ʱ��ʾ��Ϊ����������־��
						  �������ʹ��SDK��ʱ���������Ϊ0����ʱ���ǿȫ�����ظ������ߡ�
						  
						  ͬ���ε��豸һ������<500��ʱ������������
						  �豸����������������2000��ȷ������������ȫ�棻
						  ���弴�������ɸ�����Ҫ����̣�Խ��Խ������©��ͬ���ε��豸��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_LANToolDevice(char chPName[256], char chPWord[256], int nTimeOut);
#else
	JVCLIENT_API int __stdcall	JVNC_LANToolDevice(char chPName[256], char chPWord[256], int nTimeOut);
#endif

/****************************************************************************
*����  : JVNC_SendCMD
*����  : �����ض˷���һЩ�������� 
*����  : [IN] nLocalChannel   ����ͨ���� >=1
		 [IN] uchType         ��������
		 [IN] pBuffer         ������������
		 [IN] nSize           �������ݳ���
*����ֵ: 0  ����ʧ��
         1  ���ͳɹ�
		 2  �Է���֧�ָ�����
*����  : ������ͨģʽ������Ч��
         ��ǰ֧�ֵ���:ֻ���ؼ�֡����JVN_CMD_ONLYI
		              �ͻָ���֡����JVN_CMD_FULL
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_SendCMD(int nLocalChannel, unsigned char uchType, unsigned char  *pBuffer, int nSize);
#else
	JVCLIENT_API int __stdcall	JVNC_SendCMD(int nLocalChannel, unsigned char  uchType, unsigned char  *pBuffer, int nSize);
#endif



/****************************************************************************
*����  : JVC_AddFSIpSection
*����  : �����Զ���IP�Σ��Թ��������� ,��������ָ����IP�� first search
*����  : [IN] pStartIp		  IPSECTION�����ַ
		 [IN] nSize           IP����*sizeof(IPSECTION)
		 [IN] bEnablePing     ��ͣ������ ping�߳� 
*����ֵ: 0���ɹ� -1 ʧ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
 	JVCLIENT_API int JVNC_AddFSIpSection( const IPSECTION * pStartIp, int nSize ,int bEnablePing );
#else
 	JVCLIENT_API int __stdcall	JVNC_AddFSIpSection( const IPSECTION * pStartIp, int nSize ,BOOL bEnablePing );
 
#endif

/****************************************************************************
*����  : JVNC_MOLANSerchDevice
*����  : �ֻ�������������ά�豸
*����  : [IN] chGroup     ����ţ������+nYSTNO��ȷ��Ψһ�豸
         [IN] nYSTNO      ��������ĳ����ͨ������豸��>0��Ч
         [IN] nCardType   ����ĳ�ͺŵ��豸��>0��Ч,��nYSTNO>0ʱ�ò�����Ч
		 [IN] chDeviceName����ĳ���������豸��strlen>0��Ч����nYSTNO>0ʱ��Ч
		 [IN] nVariety    ����ĳ�������豸��1�忨;2DVR;3IPC;>0��Ч,��nYSTNO>0ʱ�ò�����Ч
		 [IN] nTimeOut    ����������Чʱ�䣬��λ���롣������ʱ��Ľ������������
		                  ��ʱʱ�䵽���ص������н��õ���ʱ��ʾ��Ϊ����������־��
						  �������ʹ��SDK��ʱ���������Ϊ0����ʱ���ǿȫ�����ظ������ߡ�

						  ͬ���ε��豸һ������<500��ʱ������������
						  �豸����������������2000��ȷ������������ȫ�棻
						  ���弴�������ɸ�����Ҫ����̣�Խ��Խ������©��ͬ���ε��豸��
		 [IN] unFrequence (��λΪs )ִ��ping ���ص�Ƶ�ʣ�Ĭ��������30s����һ�Σ�Ƕ��ʽ�豸�ɸ�����Ҫ����>20&&<24*3600��Ч.

*����ֵ: ��
*����  : ��������ͬʱΪ0ʱ����������������������ά�豸
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int  JVNC_MOLANSerchDevice(char chGroup[4], int nYSTNO, int nCardType, int nVariety, char chDeviceName[100], int nTimeOut,unsigned int unFrequence);
#else
	JVCLIENT_API bool __stdcall	JVNC_MOLANSerchDevice(char chGroup[4], int nYSTNO, int nCardType, int nVariety, char chDeviceName[100], int nTimeOut,unsigned int unFrequence);
#endif

/****************************************************************************
*����  : JVNC_RegisterCommonCallBack
*����  : ����ͨ����Ӧ�ò����ݽ��� �ص�ע��
*����  : �ص�����

*����ֵ: ��
*****************************************************************************/

#ifndef WIN32
	JVCLIENT_API void JVNC_RegisterCommonCallBack(FUNC_COMM_DATA_CALLBACK pfWriteReadDataCallBack);
#else
	JVCLIENT_API void __stdcall JVNC_RegisterCommonCallBack(FUNC_COMM_DATA_CALLBACK pfWriteReadDataCallBack);
#endif

/****************************************************************************
*����  : JVNC_SetNet3G
*����  : ���õ�ǰ������ģʽ�Ƿ���3Gģʽ
*����  : [IN]	bIs3GNet  TRUE 3G����(����������) FALSE ����������
*����ֵ: 0 ����δ��ʼ�� 1 �ɹ�
*****************************************************************************/

#ifndef WIN32
JVCLIENT_API int  JVNC_SetNet3G(int bIs3GNet);
#else
JVCLIENT_API int __stdcall	JVNC_SetNet3G(bool bIs3GNet);
#endif

/****************************************************************************
*����  : JVNC_GetDemo
*����  : ��ȡ��ʾ��
*����  : [OUT] pBuff		  ��Ų�ѯ�ĺ�����б�,�ڴ���Ӧ�ò㴴������ ���� : 4 BYTE ���� : 4 BYTE ͨ���� : 1 BYTE
         [IN] nBuffSize       �������ڴ��С

*����ֵ: ���� ��ʾ���������-2 ϵͳδ��ʼ�� -1 Ϊ�ڴ�̫С��0 ����������⻹û�л�ȡ��
*****************************************************************************/

#ifndef WIN32
JVCLIENT_API int JVNC_GetDemo(unsigned char* pBuff,int nBuffSize);
#else
JVCLIENT_API int __stdcall JVNC_GetDemo(BYTE* pBuff,int nBuffSize);
#endif

/****************************************************************************
*����  : JVNC_HelperRemove
*����  : ɾ�������ڵĺ��� 
*����  : [IN] chGroup     ����ţ������+nYSTNO��ȷ��Ψһ�豸
         [IN] nYSTNO      ��������ĳ����ͨ������豸��>0��Ч

*����ֵ: ��
*****************************************************************************/

#ifndef WIN32
JVCLIENT_API void JVNC_HelperRemove(char* pGroup,int nYST);
#else
JVCLIENT_API void __stdcall JVNC_HelperRemove(char* pGroup,int nYST);
#endif
/****************************************************************************
*����  : JVNC_HelpQuery
*����  : ��ѯ���ֵĺ�������״̬ 
*����  : [IN] chGroup     ����ţ������+nYSTNO��ȷ��Ψһ�豸
         [IN] nYSTNO      ��������ĳ����ͨ������豸��>0��Ч
		 [OUT] nCount     ���ֵ�����

*����ֵ: -1 δ��ʼ�� 0 δ���� 1 ���� ���� 2 ת������ 3 ���� ����
*****************************************************************************/

#ifndef WIN32
JVCLIENT_API int JVNC_HelpQuery(char* pGroup,int nYST,int &nCount);
#else
JVCLIENT_API int __stdcall JVNC_HelpQuery(char* pGroup,int nYST,int &nCount);
#endif


/****************************************************************************
*����  : JVNC_QueryDevice
*����  : ��ѯ�����Ƿ��Ѿ��������� 
*����  : [IN] chGroup     ����ţ������+nYSTNO��ȷ��Ψһ�豸
         [IN] nYSTNO      ��������ĳ����ͨ������豸��>0��Ч
         [IN] nTimeOut    ��ʱʱ�䵥λ����
		 [IN] callBack    �ص�����

*����ֵ: 0 ���� 1 �ɹ� �ȴ��ص�
*****************************************************************************/

#ifndef WIN32
JVCLIENT_API int JVNC_QueryDevice(char* pGroup,int nYST,int nTimeOut,FUNC_DEVICE_CALLBACK callBack);
#else
JVCLIENT_API int __stdcall JVNC_QueryDevice(char* pGroup,int nYST,int nTimeOut,FUNC_DEVICE_CALLBACK callBack);
#endif



/****************************************************************************
*����  : JVNC_QueryPosition
*����  : ��ѯ��ǰ�ĵ�ַ��� 
*����  : [IN] callBack     �ص���������ѯ���ɴ˺�������
 
*����ֵ: 0 ���� 1 �ɹ� �ȴ��ص�
*****************************************************************************/
#ifndef WIN32
JVCLIENT_API int JVNC_QueryPosition(FUNC_POSITION_CALLBACK callBack);
#else
JVCLIENT_API int __stdcall JVNC_QueryPosition(FUNC_POSITION_CALLBACK callBack);
#endif

/****************************************************************************
*����  : JVNC_GetExamItem
*����  : ��ȡ�����Ŀ
*����  : [IN,OUT]	pExamItem  ��Ҫ��ϵ���Ŀ�б�4BYTE ���� +�ı� [+ 4BYTE + �ı�...]
[IN]	nSize          ����ص�����		 
*����ֵ: int ���Լ�������Ŀ ==0 û�м���� <0 ��Ŀ�б���̫С
*****************************************************************************/

#ifndef WIN32
JVCLIENT_API int  JVNC_GetExamItem(char *pExamItem,int nSize);
#else
JVCLIENT_API int __stdcall	JVNC_GetExamItem(char *pExamItem,int nSize);
#endif


/****************************************************************************
*����  : JVNC_ExamItem
*����  : ���ĳһ��
*����  : [IN]	nExamType  ������� ��-1 ȫ����� �������ݷ��ص���֪�������
		 [IN]	pUserInfo          ���ʱ�û���д����Ϣ		 
		 [IN]	callBackExam          ����ص�����		 
*����ֵ: ��
*****************************************************************************/
#ifndef WIN32
JVCLIENT_API int  JVNC_ExamItem(int nExamType,char* pUserInfo,FUNC_EXAM_CALLBACK callBackExam);
#else
JVCLIENT_API int __stdcall	JVNC_ExamItem(int nExamType,char* pUserInfo,FUNC_EXAM_CALLBACK callBackExam);
#endif



/****************************************************************************
*����  : JVNC_SetPlayMode
*����  :  ���ò���ģʽ
*����  : [IN] nPlayMode //0,����������,ռ���ڴ��1��ʵʱ������,ռ���ڴ�С
*����ֵ:  0���ɹ� -1 ʧ��
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_SetPlayMode(int nPlayMode);
#else
	JVCLIENT_API int __stdcall	JVNC_SetPlayMode(int nPlayMode);
#endif




/****************************************************************************
*����  : JVNC_GetPositionID
*����  : ��ѯ��ǰ���ڵ�����
*����  : nGetType ��ѯ���� 1 ��ͨ����������ѯ 2��ͨ��afdvr��ѯ
*����ֵ: 0 ����  1 ���� -1 ����δ֪
*****************************************************************************/
#ifndef WIN32
	JVCLIENT_API int JVNC_GetPositionID(int nGetType);
#else
	JVCLIENT_API int __stdcall JVNC_GetPositionID(int nGetType);
#endif


#ifndef WIN32
	//#include "JVNSDKDef.h"
	#ifdef __cplusplus
		#define JVSERVER_API extern "C"
	#else
		#define JVSERVER_API
	#endif
#else
	#define JVSERVER_API extern "C" __declspec(dllexport)
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                     //
//                                      ���ض˽ӿ�                                                     //
//                                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/***************************************�ӿ��嵥********************************************************
JVNS_InitSDK -----------------01 ��ʼ��SDK��Դ
JVNS_ReleaseSDK---------------02 �ͷ�SDK��Դ
JVNS_RegisterCallBack --------03 �������ض˻ص�����
JVNS_ActiveYSTNO -------------04 ��������ͨ����
JVNS_InitYST -----------------05 ��ʼ������ͨ����
JVNS_StartChannel ------------06 ����ĳͨ���������
JVNS_StopChannel -------------07 ֹͣĳͨ�����з���
JVNS_SendData ----------------08 ��������(ͨ��Ⱥ��)
JVNS_SendDataTo --------------09 ��������(������)
JVNS_SendChatData ------------10 ����������Ϣ(����������ı�����)
JVNS_EnableLog ---------------11 ����д������־�Ƿ���Ч
JVNS_RegCard -----------------12 ע���Ʒ
JVNS_SetLanguage -------------13 ������־/��ʾ��Ϣ����(Ӣ��/����)
JVNS_GetLanguage -------------14 ��ȡ��־/��ʾ��Ϣ����(Ӣ��/����)
JVNS_SendAndRecvS ------------15 ��������������
JVNS_StartWebServer ----------16 ����web����
JVNS_StartSelfWebServer ------17 �����Զ���web����(OEM)
JVNS_StopWebServer -----------18 ֹͣweb����
JVNS_SetClientLimit ----------19 ���÷ֿ���Ŀ����
JVNS_GetClientLimit ----------20 ��ȡ�ֿ���Ŀ��������ֵ
JVNS_EnablePCTCPServer -------21 �����ر�PC�ͻ�TCP����(������δʹ��)
JVNS_EnableMOServer ----------22 �����ر�ĳͨ�����ֻ�����
JVNS_SendMOData --------------23 �����ֻ����ݣ���TYPE_MO_TCP/TYPE_MO_UDP������Ч
JVNS_Command -----------------24 �����ض�ָ�Ҫ��SDKִ���ض�����
JVNS_StartLANSerchServer -----25 ������������������
JVNS_StopLANSerchServer ------26 ֹͣ��������������
JVNS_SetLocalNetCard ---------27 ������һ������(IPC)
JVNS_SetDeviceName -----------28 ���ñ����豸����
JVNS_SetDomainName -----------29 �����µ�������ϵͳ�������ȡ�������б�
JVNS_SetLocalFilePath --------30 �Զ��屾���ļ��洢·����������־�����ɵ������ؼ��ļ���
JVNS_StartStreamService ------31 ������ý�����
JVNS_StopStreamService -------32 ֹͣ��ý�����
JVNS_GetStreamServiceStatus --33 ��ѯ��ý�����״̬
JVNS_StartBroadcastServer ----34 �����Զ���㲥����(IPC)
JVNS_StopBroadcastServer -----35 �ر��Զ���㲥����(IPC)
JVNS_BroadcastRSP ------------36 �����Զ���㲥Ӧ��(IPC)
JVNS_SendPlay-----------------37 ��ָ��Ŀ�귢��Զ�̻ط�����,������MP4�ļ�Զ�̻ط�
JVNS_EnableLANToolServer------38 �����رվ������������߷���
JVNS_RegDownLoadFileName------39 ע��ص����������ڵ��������⴦��Զ�������ļ���
JVNS_SetDeviceInfo------------40 �����豸��Ϣ
JVNS_GetDeviceInfo------------41 ��ȡ�豸��Ϣ
JVNS_SetIPCWANMode------------42 ����IPC�������⴦��ģʽ
JVNS_GetNetSpeedNow-----------43 ��ȡ��ǰ����״��
JVNS_ClearBuffer--------------44 ��շ��ͻ���
JVNS_SetLSPrivateInfo---------45 ���ñ����Զ�����Ϣ�������豸����
JVNS_SetWANClientLimit--------46 ��������������Ŀ����
JVNS_GetExamItem -------------47 ��ѯ���Լ�����Ŀ
JVNS_ExamItem ----------------48 �����Ŀ
JVNS_SendChannelInfo----------49 ����ÿһ��ͨ������
JVNS_SendJvnInfo--------------50 ����ÿһ��ͨ������
JVNS_RegNickName--------------51 ע�����
JVNS_DeleteNickName-----------52 ɾ������
JVNS_GetNickName--------------53 ��ȡ����
JVNS_RegClientMsgCallBack-----54 ע��ֿ���Ϣ�ص�
JVNS_GetPositionID------------55 ��ѯ����
*******************************************************************************************************/                                                                                                     //


/****************************************************************************
*����  : JVNS_InitSDK
*����  : ��ʼ��SDK��Դ�����뱻��һ������
*����  : [IN] nYSTPort    ����������ͨ����ͨ�ŵĶ˿�,0ʱĬ��9100
         [IN] nLocPort    �����ṩ���ط���ͨ�ŵĶ˿�,0ʱĬ��9101
		 [IN] nSPort      ����������ͨ����������(������룬ע���)�Ķ˿�,0ʱĬ��9102
		 [IN] nVersion    ���ذ汾�ţ���������ͨ��������֤
		 [IN] lRSBuffer   ���ض������շ���֡���ݵ���С���棬Ϊ0ʱĬ��150K��
		                  IPC�������ݵ�֡���ܴܺ󣬿ɸ������֡ȷ����ֵ�����������Ӧ�ֿض�Ҳ��Ҫ��Ӧ����.
						  �ò�����������IPC��
		 [IN] bLANSpeedup �Ƿ�����������Ż�����(IPC�������������������⴦��,������ͨ������Ʒ������ΪFALSE)
		 [IN] stDeviceType ��Ʒ���� ���JVNSDKDef.h �� STDeviceType
		                   ��ͨ�忨������stDeviceType.nType = 1;stDeviceType.nMemLimit = 1;
						   ��ͨIPC������ stDeviceType.nType = 3;stDeviceType.nMemLimit = 1;
						   �ڴ����ز���DVR������stDeviceType.nType = 2;stDeviceType.nMemLimit = 3;
		 [IN] nDSize       ������sizeof(STDeviceType),����У�鴫��ṹ�Ϸ���
*����ֵ: TRUE     �ɹ�
         FALSE    ʧ��
*����  : ���ض˳���ռ�������˿ڣ�һ������������ͨ������ͨ�ţ�һ��������ֿ�ͨ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_InitSDK(int nYSTPort, int nLocPort, int nSPort, int nVersion, long lRSBuffer, int bLANSpeedup, STDeviceType stDeviceType, int nDSize);
#else
	JVSERVER_API bool __stdcall	JVNS_InitSDK(int nYSTPort, int nLocPort, int nSPort, int nVersion, long lRSBuffer, BOOL bLANSpeedup, STDeviceType stDeviceType, int nDSize);
#endif

/****************************************************************************
*����  : JVNS_ReleaseSDK
*����  : �ͷ�SDK��Դ��������󱻵��� 
*����  : ��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_ReleaseSDK();
#else
	JVSERVER_API void __stdcall	JVNS_ReleaseSDK();
#endif

/****************************************************************************
*����  : JVNS_RegisterSCallBack
*����  : �������ض˻ص����� 
*����  : [IN] ConnectCallBack   �ֿ�����״���ص�����
         ...
*����ֵ: ��
*����  : ���ض˻ص�����������
             �ֿ������֤����            (�����֤)
             ������ͨ������ͨ��״̬������(����״̬)
		     ��ֿض�ͨ��״̬������      (����״̬)
		     ¼�����������              (¼���������)
			 Զ����̨���ƺ�����          (Զ����̨����)
			 ��������/�ı����캯��       (Զ���������ı�����)
			 �طſ���       (Ŀǰ�Ļطſ���mp4�ļ�)
			 ����ע�᷵����Ϣ
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_RegisterCallBack(FUNC_SCHECKPASS_CALLBACK CheckPassCallBack,
											FUNC_SONLINE_CALLBACK OnlineCallBack,
											FUNC_SCONNECT_CALLBACK ConnectCallBack,
											FUNC_SCHECKFILE_CALLBACK CheckFileCallBack,
											FUNC_SYTCTRL_CALLBACK YTCtrlCallBack,
											FUNC_SCHAT_CALLBACK ChatCallBack,
											FUNC_STEXT_CALLBACK TextCallBack,
											FUNC_SFPLAYCTRL_CALLBACK FPlayCtrlCallBack,
											FUNC_RECVSERVERMSG_CALLBACK FRecvMsgCallBack);
#else
	JVSERVER_API void __stdcall	JVNS_RegisterCallBack(FUNC_SCHECKPASS_CALLBACK CheckPassCallBack,
												  FUNC_SONLINE_CALLBACK OnlineCallBack,
												  FUNC_SCONNECT_CALLBACK ConnectCallBack,
												  FUNC_SCHECKFILE_CALLBACK CheckFileCallBack,
												  FUNC_SYTCTRL_CALLBACK YTCtrlCallBack,
												  FUNC_SCHAT_CALLBACK ChatCallBack,
												  FUNC_STEXT_CALLBACK TextCallBack,
												  FUNC_SFPLAYCTRL_CALLBACK FPlayCtrlCallBack,
												  FUNC_RECVSERVERMSG_CALLBACK FRecvMsgCallBack);
#endif

/****************************************************************************
*����  : JVNS_RegClientMsgCallBack
*����  : ���÷ֿ���Ϣ�ص���
*����  : [IN] FRecvMsgCallBack   �ֿ���Ϣ�ص���������Ƶ��ͣ����Ƶ�ָ�
*����ֵ: ��

*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_RegClientMsgCallBack(FUNC_RECVCLIENTMSG_CALLBACK FRecvMsgCallBack);
#else
	JVSERVER_API void __stdcall JVNS_RegClientMsgCallBack(FUNC_RECVCLIENTMSG_CALLBACK FRecvMsgCallBack);
#endif

/****************************************************************************
*����  : JVNS_ActiveYSTNO
*����  : ��������ͨ����
*����  : [IN]  pchPackGetNum  ����Ϣ(STGetNum�ṹ)
         [IN]  nLen           ��Ϣ����(sizeof(STGetNum))
         [OUT] nYSTNO         �ɹ����������ͨ����
*����ֵ: TRUE  �ɹ�
         FALSE ʧ��
*����  : ����ͨ��������ַ���ڲ���ȡ��
         ��������ʹ�ã�ֻ���ؼ����YST���룬�����ڲ����κμ�¼��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_ActiveYSTNO(char *pchPackGetNum, int nLen, int *nYSTNO);
#else
	JVSERVER_API bool __stdcall	JVNS_ActiveYSTNO(char *pchPackGetNum, int nLen, int &nYSTNO);
#endif

/****************************************************************************
*����  : JVNS_InitYST
*����  : ��ʼ������ͨ����
*����  : [IN] ����ͨ�������Ϣ(STOnline�ṹ)
         [IN] ��Ϣ����
*����ֵ: ��
*����  : �ú�����������ͨ������ͨ����ǰ���ã�����ͨ������ͨ��������ʧ�ܣ�
         
		 �ú���ֻ�����һ�Σ�����������ͨ����ֻҪ����Ҫ��������ͨ����ģ�
		 ����������ǰ����һ�θýӿڼ��ɣ�
         
		 �ú�����¼����ͨ���뼰����������ʱʹ����Щ������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_InitYST(char *pchPackOnline, int nLen);
#else
	JVSERVER_API void __stdcall	JVNS_InitYST(char *pchPackOnline, int nLen);
#endif

/****************************************************************************
*����  : JVNS_StartChannel
*����  : ����ĳͨ���������
*����  : [IN] nChannel  ����ͨ���� >=1  
                        �ر�:nChannel=-1ʱ����ͨ���������ڱܿ���Ƶͨ����������ͨ����

         [IN] nType     �����������ͣ�0����������������1ֻ��������������

		 [IN] bJVP2P    ������ά����ֱ�����ڴ治�������û��Ӳ��ʱ�ù��ܲ������ã�
		                ��ΪTRUEʱΪ�ಥ��ʽ��ΪFALSEʱΪ��ͳ��ʽ��
						������û�չ��ʱ��Ӧ������ѡ�����ģʽ(����ʱ)�ʹ�������ģʽ(С����ʱ)��
						Ĭ��Ϊ����ģʽ���ɣ�
						û��������Ҫ,�ɽ��ù�����ΪFALSE,����չ�ָ��û���

		 [IN] lBufLen   ͨ����Ƶ֡��������С����λ�ֽ�, 
		                ��ͨ��ʽʱ�����Сָ����֡����������(��>400*1024,Ӧ�������������)��
						JVP2P��ʽʱ������Ϊ>=8M����СΪ1024000��
						�����ֵ���ò��㣬���ܲ���ÿ��֡����ĩβ��֡��ʧ��ɿ��ٵ�����

		 [IN] chBufPath �����ļ�·������ʹ���ļ�����ʱ��Ϊ""; 

*����ֵ: TRUE  �ɹ�
         FALSE ʧ��
*����  : ÿ��ͨ������Ƶ֡�ߴ粻ͬ��������軺����Ҳ��ͬ����Ӧ�ò����ã�
         �ú������ظ����ã������б仯ʱ�Ž���ʵ�ʲ������ظ��ĵ��ûᱻ���ԣ�
		 Ӧ�ò��ڸ�����ĳЩ���ú󣬿����µ��øýӿ����÷���

         ��������jvp2p���������ַ�ʽ���л��棺�ڴ淽ʽ���ļ���ʽ
		 ��lbuflen �� chBufPath������һ������Ч�ģ����ͬʱ��Ч�����Ȳ����ڴ淽ʽ�����߶���Ч��ʧ��

		 ���飺1.�ڴ淽ʽʱÿ��ͨ������>=8M�ڴ棬Ч����ѣ��ڴ���������������ڴ淽ʽ��
		       2.DVR���ڴ�ǳ����ŵ��豸���԰�װӲ�̲��Ҳ����ļ��洢��ʽʹ��jvp2p��
			     DVR�ڴ�ϳ�����豸��������ÿ��ͨ������>=1M����Ƶ�����������򲻽���ʹ�ã�
				 DVR�ڴ�����豸�޷�ʹ��jvp2p������չ�ָ��û�����Ĭ���ṩ'����ģʽ'���ɣ�
			   3.ÿ��ͨ�������Ե�������jvp2p���ܣ�������Ӧ�ò����ļ���Լ���ͨ�����������ľ�����
			     ��������ͨ��ͳһ������رոù��ܣ�����ʹ��jvp2p��������ͨ����ʹ�ã����򶼲��ã�

         bJVP2P=TRUEʱ������"���������ͱ�֤����"��ģʽ���У��������ض�ֻҪ�ṩ�˱�Ҫ�Ļ����ϴ���������2M��
		 �������㼸ʮ�ϰ���ͬʱ���ӣ�����Ͽ�ͨ��άVIPת��������ȷ��������������ʵʱ���Բ
		 Զ�̻�����ʵ�ʻ��������ʱ2s-7s��
		 bJVP2P=FALSEʱ������"����������ʱ"��ģʽ���У�����������ȫȡ���ڴ�����豸��Դ����һ�ִ�ͳ���䷽ʽ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_StartChannel(int nChannel, int nType, int bJVP2P, long lBufLen, char chBufPath[256]);
#else
	JVSERVER_API bool __stdcall	JVNS_StartChannel(int nChannel, int nType, BOOL bJVP2P, long lBufLen, char chBufPath[MAX_PATH]);
#endif

/****************************************************************************
*����  : JVNS_StopChannel
*����  : ֹͣĳͨ�����з��� 
*����  : [IN] nChannel ����ͨ���� >=1
*����ֵ: ��
*����  : ֹͣĳ������Ҳ��ͨ���ظ�����JVNS_StartChannelʵ�֣�
         ����ֹͣ���з���ֻ��ͨ���ýӿ�ʵ�֡�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_StopChannel(int nChannel);
#else
	JVSERVER_API void __stdcall	JVNS_StopChannel(int nChannel);
#endif

/****************************************************************************
*����  : JVNS_SendData
*����  : �������� 
*����  : [IN] nChannel   ����ͨ���� >=1
         [IN] uchType    �������ͣ���ƵI;��ƵP;��ƵB;��ƵS;��Ƶ;�ߴ�;�Զ�������;֡����ʱ����
         [IN] pBuffer    ������������,��Ƶ/��Ƶ/�Զ�������ʱ��Ч
		 [IN] nSize      �������ݳ���,��Ƶ/��Ƶ/�Զ�������ʱ��Ч
		 [IN] nWidth     uchType=JVNS_DATA_Sʱ��ʾ֡��/uchType=JVNS_CMD_FRAMETIMEʱ��ʾ֡���(��λms)
		 [IN] nHeight    uchType=JVNS_DATA_Sʱ��ʾ֡��/uchType=JVNS_CMD_FRAMETIMEʱ��ʾ�ؼ�֡����
*����ֵ: ��
*����  : ��ͨ��Ϊ��λ����ͨ�����ӵ����зֿط�������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SendData(int nChannel,unsigned char uchType,unsigned char *pBuffer,int nSize,int nWidth,int nHeight);
#else
	JVSERVER_API void __stdcall	JVNS_SendData(int nChannel,unsigned char uchType,BYTE *pBuffer,int nSize,int nWidth,int nHeight);
#endif

/****************************************************************************
*����  : JVNS_SendDataTo
*����  : �������� 
*����  : [IN] nChannel   ����ͨ���� >=1
         [IN] uchType    �������ͣ�Ŀǰֻ���ڳߴ緢�ͳߴ�;�Ͽ�ĳ����;�Զ�������
         [IN] pBuffer    ������������
		 [IN] nSize      �������ݳ���
		 [IN] nWidth     uchType=JVNS_DATA_Sʱ��ʾ֡��/uchType=JVNS_CMD_FRAMETIMEʱ��ʾ֡���(��λms)
		 [IN] nHeight    uchType=JVNS_DATA_Sʱ��ʾ֡��/uchType=JVNS_CMD_FRAMETIMEʱ��ʾ�ؼ�֡����
*����ֵ: ��
*����  : ��ͨ�����ӵ�ĳ������ֿط�������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SendDataTo(int nClientID,unsigned char uchType,unsigned char *pBuffer,int nSize,int nWidth,int nHeight);
#else
	JVSERVER_API void __stdcall	JVNS_SendDataTo(int nClientID,unsigned char uchType,BYTE *pBuffer,int nSize,int nWidth,int nHeight);
#endif

/****************************************************************************
*����  : JVNS_SendChatData
*����  : ����������Ϣ(����������ı�����)
*����  : [IN] nChannel   ����ͨ���� >=1,�㲥ʽ����ʱ��Ч;
         [IN] nClientID  �ֿ�ID,��ָ���ֿط���,��ʱnChannel��Ч,���ȼ�����nChannel;
         [IN] uchType      �������ͣ���������;
		                             �ı�����;
		                             ͬ����������;
                                     ͬ���ı�����;
								     ��������;
								     �ı�����;
								     �����ر�;
								     �ı��ر�;
         [IN] pBuffer    ������������
         [IN] nSize      �������ݳ���
*����ֵ: true   �ɹ�
         false  ʧ��
*����  : �����߽��������ݷ��͸�������������ķֿض�;
         nChannel��nClientID����ͬʱ<=0,������ͬʱ��Ч;
		 nChannel��nClientIDͬʱ>0ʱ,nClientID���ȼ���,��ʱֻ��ָ���ֿط��͡�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_SendChatData(int nChannel,int nClientID,unsigned char uchType,unsigned char *pBuffer,int nSize);
#else
	JVSERVER_API bool __stdcall	JVNS_SendChatData(int nChannel,int nClientID,unsigned char uchType,BYTE *pBuffer,int nSize);
#endif

/****************************************************************************
*����  : JVNS_EnableLog
*����  : ����д������־�Ƿ���Ч 
*����  : [IN] bEnable  TRUE:����ʱд��־��FALSE:��д�κ���־
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_EnableLog(int bEnable);
#else
	JVSERVER_API void __stdcall	JVNS_EnableLog(bool bEnable);
#endif

/****************************************************************************
*����  : JVNS_SetLanguage
*����  : ������־/��ʾ��Ϣ����(Ӣ��/����) 
*����  : [IN] nLgType  JVNS_LANGUAGE_ENGLISH/JVNS_LANGUAGE_CHINESE
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SetLanguage(int nLgType);
#else
	JVSERVER_API void __stdcall	JVNS_SetLanguage(int nLgType);
#endif

/****************************************************************************
*����  : JVNS_GetLanguage
*����  : ��ȡ��־/��ʾ��Ϣ����(Ӣ��/����) 
*����  : ��
*����ֵ: JVNS_LANGUAGE_ENGLISH/JVNS_LANGUAGE_CHINESE
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_GetLanguage();
#else
	JVSERVER_API int __stdcall	JVNS_GetLanguage();
#endif

/****************************************************************************
*����  : JVNS_SetClientLimit
*����  : ���÷ֿ���Ŀ����
*����  : [IN] nChannel  ͨ����(>0;=0;<0)
         [IN] nMax      ��Ŀ����ֵ <0ʱ��ʾ������
		                nChannel<0 ʱ��ʾ�ֿ�����Ŀ����ΪnMax; 
						nChannel=0 ʱ��ʾ����ͨ��ʹ����ͬ��ͨ���ֿ���Ŀ����ΪnMax; 
						nChannel>0 ʱ��ʾ��ͨ���ֿ���Ŀ����ΪnMax
*����ֵ: ��
*����  : ���ظ�����,�����һ������Ϊ׼;
         �������޺͵�ͨ�����޿�ͬʱ������;

         ����ͨ��Ʒ�����ϸ�������������ֻʹ�øýӿھ��ܴﵽ����������Ŀ�ģ�
		 ������Ҫ�����������������Ĳ�Ʒ������ϵ���JVNS_SetWANClientLimit��
		 �޶���������������
		 ��
		 ���ͬʱʹ��JVNS_SetClientLimit��JVNS_SetWANClinetLimit,��
		             JVNS_SetClientLimit�޶����ǻ�����������
		             JVNS_SetWANClientLimit�����޶�����������������
		 ���ֻʹ��JVNS_SetClientLimit,�޶��ľ���(������������)������Ŀ��
		 ���ֻʹ��JVNS_SetWANClientLimit,�޶��ľ�������������Ŀ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SetClientLimit(int nChannel, int nMax);
#else
	JVSERVER_API void __stdcall	JVNS_SetClientLimit(int nChannel, int nMax);
#endif

/****************************************************************************
*����  : JVNS_SetWANClientLimit
*����  : ���������ֿ���Ŀ����
*����  : [IN] nWANMax   ��Ŀ����ֵ <0ʱ��ʾ������
		                >=0��ʾ�����ֿ�����Ŀ����ΪnWANMax; 
		 
*����ֵ: ��
*����  : ���ظ�����,�����һ������Ϊ׼;
         �������޺͵�ͨ�����޿�ͬʱ������;

		 ����ͨ��Ʒ�����ϸ�������������ֻʹ��JVNS_SetClientLimit�ӿھ��ܴﵽ����������Ŀ�ģ�
		 ������Ҫ�����������������Ĳ�Ʒ������ϵ���JVNS_SetWANClientLimit��
		 �޶���������������
		 ��
		 ���ͬʱʹ��JVNS_SetClientLimit��JVNS_SetWANClinetLimit,��
		 JVNS_SetClientLimit�޶����ǻ�����������
		 JVNS_SetWANClientLimit�޶�����������������

		 ���ֻʹ��JVNS_SetClientLimit,�޶��ľ���(������������)������Ŀ��
		 
		 ���ֻʹ��JVNS_SetWANClientLimit,�޶��ľ�������������Ŀ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SetWANClientLimit(int nWANMax);
#else
	JVSERVER_API void __stdcall	JVNS_SetWANClientLimit(int nWANMax);
#endif

/****************************************************************************
*����  : JVNS_GetClientLimit
*����  : ��ȡ�ֿ���Ŀ��������ֵ
*����  : [IN] nChannel  ͨ����(>0;<0)
		                nChannel<0 ʱ��ʾ��ȡ�ֿ�����Ŀ����; 
						nChannel>0 ʱ��ʾ��ȡ��ͨ���ֿ���Ŀ����;
*����ֵ: ��Ŀ����ֵ <=0��ʾ������
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_GetClientLimit(int nChannel);
#else
	JVSERVER_API int __stdcall	JVNS_GetClientLimit(int nChannel);
#endif

/****************************************************************************
*����  : JVNS_RegCard
*����  : ע���Ʒ
*����  : [IN] chGroup    ����ţ�����"A" "AAAA"
         [IN] pBuffer    ������������(SOCKET_DATA_TRAN�ṹ)
		 [IN] nSize      ���������ܳ���
*����ֵ: TRUE  �ɹ�
         FALSE ʧ��
*����  : ��������������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_RegCard(char chGroup[4], unsigned char *pBuffer,int nSize);
#else
	JVSERVER_API bool __stdcall	JVNS_RegCard(char chGroup[4], BYTE *pBuffer,int nSize);
#endif

/****************************************************************************
*����  : JVNS_SendAndRecvS
*����  : ��������������
*����  : [IN] chGroup       ����ţ�����"A" "AAAA"
         [IN] pBuffer       ������������
         [IN] nSize         ���������ܳ���
         [OUT] pRecvBuffer  �������ݻ��壬�ɵ����߷���
         [IN/OUT] &nRecvLen ������ջ��峤�ȣ�����ʵ�����ݳ���
         [IN] nTimeOut      ��ʱʱ��(��)
*����ֵ: TRUE  �ɹ�
FALSE ʧ��
*����  : ��������������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_SendAndRecvS(char chGroup[4],unsigned char *pBuffer,int nSize, 
		                               unsigned char *pRecvBuffer,int *nRecvLen,int nTimeOut);
#else
	JVSERVER_API bool __stdcall	JVNS_SendAndRecvS(char chGroup[4], BYTE *pBuffer,int nSize, 
		                                         BYTE *pRecvBuffer,int &nRecvLen,int nTimeOut);
#endif

/****************************************************************************
*����  : JVNS_StartWebServer
*����  : ����web����
*����  : [IN] chHomeDir   Ŀ���ļ����ڱ���·�� ��"D:\\test"
         [IN] chDefIndex  Ŀ���ļ���(����)
		 [IN] chLocalIP   ����ip
         [IN] nPort       web����˿�
*����ֵ: TRUE  �ɹ�
		 FALSE ʧ��
*����  : web�����ܼ�����Ŀ���ļ����ͻ���
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_StartWebServer(char chHomeDir[256], char chDefIndex[256], char chLocalIP[30], int nPort);
#else
	JVSERVER_API bool __stdcall JVNS_StartWebServer(char chHomeDir[256], char chDefIndex[256], char chLocalIP[30], int nPort);
#endif

/****************************************************************************
*����  : JVNS_StartSelfWebServer
*����  : �����Զ���web����(OEM)
*����  : [IN] chHomeDir   Ŀ���ļ����ڱ���·�� ��"D:\\test"
         [IN] chDefIndex  Ŀ���ļ���(����)
		 [IN] chLocalIP   ����ip
         [IN] nPort       web����˿�
		 [IN] chSelfWebPos   �Զ�����վ�ؼ�index�ļ�λ�� ��"www.afdvr.com/cloudsee"
		 [IN] bOnlyUseLocal  ��ʹ�ñ���web���񣬲�ʹ��������վ
*����ֵ: TRUE  �ɹ�
		 FALSE ʧ��
*����  : web�����ܼ�����Ŀ���ļ����ͻ���
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_StartSelfWebServer(char chHomeDir[256], char chDefIndex[256], 
		                                     char chLocalIP[30], int nPort,
											 char chSelfWebPos[500], int bOnlyUseLocal);
#else
	JVSERVER_API bool __stdcall JVNS_StartSelfWebServer(char chHomeDir[256], char chDefIndex[256], 
		                                               char chLocalIP[30], int nPort,
													   char chSelfWebPos[500], BOOL bOnlyUseLocal);
#endif

/****************************************************************************
*����  : JVNS_StopWebServer
*����  : ֹͣweb����
*����  : ��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_StopWebServer();
#else
	JVSERVER_API void __stdcall JVNS_StopWebServer();
#endif

/****************************************************************************
*����  : JVNS_Command
*����  : �����ض�ָ�Ҫ��SDKִ���ض�����
*����  : [IN] nChannel  ����ͨ�� ==0ʱ����������Ƶͨ����Ч(����������ͨ��)
         [IN] nCMD  ָ������
*����ֵ: ��
*����  : ֧�ֵ�ָ��ο����Ͷ���
         Ŀǰ��֧�֣�CMD_TYPE_CLEARBUFFER
		 ���ض˽�����ĳ�����������ϣ���ͻ������������µ���ǰ���µ����ݣ���ִ�и�ָ�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_Command(int nChannel, int nCMD);
#else
	JVSERVER_API void __stdcall JVNS_Command(int nChannel, int nCMD);
#endif
	
/****************************************************************************
*����  : JVNS_StartLANSerchServer
*����  : ������������������
*����  : [IN] nChannelCount ��ǰ�豸�ܵ�ͨ����
         [IN] nPort         ����˿ں�(<=0ʱΪĬ��9103,����ʹ��Ĭ��ֵ��ֿض�ͳһ)
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_StartLANSerchServer(int nPort);
#else
	JVSERVER_API bool __stdcall JVNS_StartLANSerchServer(int nPort);
#endif

/****************************************************************************
*����  : JVNS_StopLANSerchServer
*����  : ֹͣ��������������
*����  : ��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_StopLANSerchServer();
#else
	JVSERVER_API void __stdcall JVNS_StopLANSerchServer();
#endif
	
/****************************************************************************
*����  : JVNS_SetLocalNetCard
*����  : ������һ������ eth0,eth1,... for linux or 0, 1, 2,...for win  
*����  : [IN] strCardName   ����
*����ֵ: �ɹ� TRUE ,ʧ�� FALSE
*����  : 2012 5
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_SetLocalNetCard(char* strCardName);
#else
	JVSERVER_API BOOL __stdcall JVNS_SetLocalNetCard(char* strCardName);
#endif

/****************************************************************************
*����  : JVNS_EnablePCTCPServer
*����  : ������ر�PC�û���TCP����
*����  : [IN] bEnable ����/�ر�
*����ֵ: TRUE  �ɹ�
		 FALSE ʧ��
*����  : TCP�����ܽ��շֿ���TCP��ʽ���ӣ���TCP��ʽ��ֿط������ݣ�
         Ŀǰ��ά�ֿض�δʹ�ø�TCP����,û��������Ҫ�ɲ�ʹ�øù��ܣ�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_EnablePCTCPServer(int bEnable);
#else
	JVSERVER_API bool __stdcall JVNS_EnablePCTCPServer(BOOL bEnable);
#endif

/****************************************************************************
*����  : JVNS_EnableMOServer
*����  : ����/�ر�ĳͨ�����ֻ����� 
*����  : [IN] nChannel   ����ͨ���� >=1 ��=0ʱ������ر�����ͨ�����ֻ�����
         [IN] bEnable    TRUEΪ������FALSEΪ�ر�
		 [IN] nOpenType  ���������ͣ�����Ϊ0;bEnableΪTRUEʱ��Ч��
		 [IN] bSendVSelf  �Ƿ񵥶������ֻ���Ƶ���ݣ����ΪTRUE�����ֻ����ݺ�PC������ȫ���룬
		                 �ֻ����ݱ�����JVNS_SendMOData���ͣ������ֻ���Ƶ���ݽ�����Ҫ�������ͣ�
						 ������ֻ����ֿ��ã����ֻ��͸��ֿص�����ͬ��������bSendVSelf=FALSE���ɣ�
		 [IN] bProtocol  �Ƿ����Զ���Э��,��bSendVSelfʱ��Ч��
		                 TRUEʱ��JVNS_SendMOData�����ݴ����Ҫ�������ͷβ��ʹ�ֻ���������������ݣ�
						         �ɰ����ط��͵�JPG���ݺͱ�׼H264���ݾ������ַ��ͷ�ʽ��
						 FALSEʱ��JVNS_SendMOData�����ݴ����ʽ�ͷֿ�����һ�£���ֿ����ݵ�����������������ݣ�
						         ������ֻ����ֿ��ã������ֻ��������ǵ���������������ʹ�ø÷�ʽ��
								 
*����ֵ: ��
*����  : �ú���ֻ��JVNS_StartChannel�����˵�ͨ�������ã�JVNS_StopChannel֮����Ҫ���������ֻ�����
         û������ͨ�������ܽ����ֻ����ӣ�
         �ظ����ý������һ�ε���Ϊ׼��
		 ���ھɰ�ֿ�Э�鲻ͬ������ȫ��Ϊ�ֿ�ʹ�ã��ù��ܲ��ܽ������ֺͽ��ã�
		 ʹ�øð�����ʱ��˾��Ʒ�ѿ�����ȫ֧��h264���������ݺͷֿ���ͬ������֧��JGP���ݣ�
		 �����ֻ����������ɣ�
		 <*****ʹ�ý���*****>��
		 1.������ֿص����ݺ͸��ֻ���������ȫ��ͬ��������ʽΪJVNS_EnableMOServer(0, TRUE, 0, FALSE, FALSE);
		 2.������ֿص����ݺ͸��ֻ������ݸ�ʽ��ͬ������һ��������������������ʽΪJVNS_EnableMOServer(0, TRUE, 0, TRUE, FALSE);
		 3.������ֿص����ݺ͸��ֻ������ݸ�ʽ��ͬ����Ҫ���ֻ��˵�������������ʽΪJVNS_EnableMOServer(0, TRUE, 0, TRUE, TRUE);
		 �����ϸ��ֻ���������ֿ����ݷֿ�������С֡��С�������õ�2�ַ�ʽЧ����ѣ�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_EnableMOServer(int nChannel, int bEnable, int nOpenType, int bSendVSelf, int bProtocol);
#else
	JVSERVER_API BOOL __stdcall	JVNS_EnableMOServer(int nChannel, BOOL bEnable, int nOpenType, BOOL bSendVSelf, BOOL bProtocol);
#endif

/****************************************************************************
*����  : JVNS_SendMOData
*����  : �����ֻ����ݣ���TYPE_MO_TCP/TYPE_MO_UDP������Ч 
*����  : [IN] nChannel   ����ͨ���� >=1
         [IN] uchType    �������ͣ���Ƶ:�Զ�������;
         [IN] pBuffer    ������������,��Ƶ/�Զ�������ʱ��Ч
		 [IN] nSize      �������ݳ���,��Ƶ/�Զ�������ʱ��Ч
*����ֵ: ��
*����  : ��ͨ��Ϊ��λ����ͨ��TYPE_MO_TCP/TYPE_MO_UDP���ӵ������ֻ�����һЩ�Զ������ݣ�
         ����JGP���ݵ���̭���ֻ����ݺ�PC�ֿ���������ȫ��ͬ���ýӿڲ�֧��JPG���ݣ�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SendMOData(int nChannel,unsigned char uchType,unsigned char *pBuffer,int nSize);
#else
	JVSERVER_API void __stdcall	JVNS_SendMOData(int nChannel,unsigned char uchType,BYTE *pBuffer,int nSize);
#endif

/****************************************************************************
*����  : JVNS_StartStreamService
*����  : ������ý�����
*����  : [IN] nChannel   ����ͨ���� >=1
         [IN] pSServerIP    ��ý�������IP;
         [IN] nPort   ��ý��������˿�
	     [IN] bAutoConnect ��������ʧ���Ƿ��Զ�����
*����ֵ: �ɹ�
         ʧ��
*����  : ��ͨ������ͨ��ʽ����ʱ����ý���������Ч��
         ��ͨ������ά����ֱ����ʽ����ʱ����ý���������Ч��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_StartStreamService(int nChannel,char *pSServerIP,int nPort,int bAutoConnect);
#else
	JVSERVER_API BOOL __stdcall JVNS_StartStreamService(int nChannel,char *pSServerIP,int nPort,BOOL bAutoConnect);
#endif

/****************************************************************************
*����  : JVNS_StopStreamService
*����  : ֹͣ��ý�����
*����  : [IN] nChannel   ����ͨ���� >=1
*����ֵ: ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_StopStreamService(int nChannel);
#else
	JVSERVER_API void __stdcall JVNS_StopStreamService(int nChannel);
#endif

/****************************************************************************
*����  : JVNS_GetStreamServiceStatus
*����  : ��ѯ��ý�����״̬
*����  : [IN] nChannel   ����ͨ���� >=1
         [OUT] pSServerIP    ��ý�������IP;
         [OUT] nPort   ��ý��������˿�
		 [OUT] bAutoConnect ��ý������Ƿ������Զ�����
*����ֵ: ��ý������Ƿ�ɹ�����
*����  : 2012 2
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_GetStreamServiceStatus(int nChannel,char *pSServerIP,int *nPort,int *bAutoConnect);
#else
	JVSERVER_API BOOL __stdcall JVNS_GetStreamServiceStatus(int nChannel,char *pSServerIP,int *nPort,BOOL *bAutoConnect);
#endif

/****************************************************************************
*����  : JVNS_SetDomainName 
*����  : �����µ�������ϵͳ�������ȡ�������б�
*����  : [IN]  pchDomainName     ����
         [IN]  pchPathName       �����µ��ļ�·���� ���磺"/down/YSTOEM/yst0.txt"
*����ֵ: TRUE  �ɹ�
         FALSE ʧ��
*����  : ϵͳ��ʼ��(JVNS_InitSDK)�������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_SetDomainName(char *pchDomainName,char *pchPathName);
#else
	JVSERVER_API BOOL __stdcall	JVNS_SetDomainName(char *pchDomainName,char *pchPathName);
#endif

/****************************************************************************
*����  : JVNS_SetDeviceName
*����  : ���ñ����豸���� 
*����  : [IN] chDeviceName   �豸����
*����ֵ: ��
*����  : Ϊ�豸��һ���������������豸�����п�����������ʾʹ�ã�
         �ظ����������һ�ε���Ϊ��Ч��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SetDeviceName(char chDeviceName[100]);
#else
	JVSERVER_API void __stdcall	JVNS_SetDeviceName(char chDeviceName[100]);
#endif

/****************************************************************************
*����  : JVNS_SetLocalFilePath
*����  : �Զ��屾���ļ��洢·����������־�����ɵ������ؼ��ļ��� 
*����  : [IN] chLocalPath  ·�� ���磺"C:\\jovision"  ����jovision���ļ���
*����ֵ: ��
*����  : ����ʹ���ڴ濽��ʱ��ע���ʼ�����ַ�������'\0'����
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_SetLocalFilePath(char chLocalPath[256]);
#else
	JVSERVER_API BOOL __stdcall	JVNS_SetLocalFilePath(char chLocalPath[256]);
#endif

/****************************************************************************
*����  : JVNS_StartBroadcastServer
*����  : �����������㲥����
*����  : [IN] nPort    ����˿ں�(<=0ʱΪĬ��9106,����ʹ��Ĭ��ֵ��ֿض�ͳһ)
         [IN] BCData   �㲥���ݻص�����
*����ֵ: �ɹ�/ʧ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_StartBroadcastServer(int nPort, FUNC_SBCDATA_CALLBACK BCData);
#else
	JVSERVER_API BOOL __stdcall JVNS_StartBroadcastServer(int nPort, FUNC_SBCDATA_CALLBACK BCData);
#endif

/****************************************************************************
*����  : JVNS_StopBroadcastServer
*����  : ֹͣ�������㲥����
*����  : ��
*����ֵ: ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_StopBroadcastServer();
#else
	JVSERVER_API void __stdcall JVNS_StopBroadcastServer();
#endif

/****************************************************************************
*����  : JVNS_BroadcastRSP
*����  : �������㲥��Ӧ
*����  : [IN] nBCID  �㲥��ʶ��ȡ�Իص�����
         [IN] pBuffer �㲥��������
		 [IN] nSize   �㲥�������ݳ���
		 [IN] nDesPort �㲥Ŀ��˿ڣ�ȡ�Իص�������������ֿ�Լ���̶�
*����ֵ: �ɹ�/ʧ��
*����  : ��
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_BroadcastRSP(int nBCID, unsigned char *pBuffer, int nSize, int nDesPort);
#else
	JVSERVER_API BOOL __stdcall JVNS_BroadcastRSP(int nBCID, BYTE *pBuffer, int nSize, int nDesPort);
#endif

/****************************************************************************
*����  : JVNS_SendPlay
*����  : ���ͻط�MP4���� 
*����  : [IN] nClientID   ���Ӻ�
         [IN] uchType     ����
		 [IN] nConnectionType     ��������
		 [IN] ucFrameType    ֡����	JVNS_DATA_I JVNS_DATA_S...
         [IN] pBuffer    ������������,����
		 [IN] nSize      �������ݳ���,����
         [IN] nWidth    ���
		 [IN] nHeight      �߶�
		 [IN] nTotalFram      ��֡��
*����ֵ: ��
*����  : ��ͨ�����ӵ�ĳ������ֿط�������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SendPlay(int nClientID,unsigned char uchType,int nConnectionType,unsigned char ucFrameType,unsigned char *pBuffer,int nSize,int nWidth,int nHeight,int nTotalFram);
#else
	JVSERVER_API void __stdcall	JVNS_SendPlay(int nClientID,BYTE uchType,int nConnectionType,BYTE ucFrameType,BYTE *pBuffer,int nSize,int nWidth,int nHeight,int nTotalFram);
#endif

/****************************************************************************
*����  : JVNS_EnableLANToolServer
*����  : ������رվ������������߷���
*����  : [IN] bEnable         ����/�ر�
         [IN] nPort           ����ʹ�õĶ˿ڣ�=0ʱĬ��Ϊ9104
         [IN] LanToolCallBack ���߻ص�����
*����ֵ: TRUE  �ɹ�
		 FALSE ʧ��
*����  : �������������߻��򱾵�ѯ�ʺ�����Ϣ�����ҷ���������صĸ�����Ϣ
         ��Ϣ��ϸ˵����ο��ص�����˵����
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_EnableLANToolServer(int bEnable, int nPort, FUNC_LANTOOL_CALLBACK LanToolCallBack);
#else
	JVSERVER_API bool __stdcall JVNS_EnableLANToolServer(BOOL bEnable, int nPort, FUNC_LANTOOL_CALLBACK LanToolCallBack);
#endif

/****************************************************************************
*����  : JVNS_RegDownLoadFileName
*����  : ע��ص����������ڵ��������⴦��Զ�������ļ���
*����  : [IN] DLFNameCallBack Զ�������ļ�������ص�����
*����ֵ: ��
*����  : ��ͨ��Ʒ����ʹ�ã�������Ҫ��ĿɶԿͻ��˵������ļ��������δ���
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_RegDownLoadFileName(FUNC_DLFNAME_CALLBACK DLFNameCallBack);
#else
	JVSERVER_API bool __stdcall JVNS_RegDownLoadFileName(FUNC_DLFNAME_CALLBACK DLFNameCallBack);
#endif

/****************************************************************************
*����  : JVNS_SetIPCWANMode
*����  : ����IPC�������⴦��ģʽ
*����  : ��
*����ֵ: ��
*����  : ��ͨ��Ʒ����ʹ�ã�������Ҫ��Ĵ�������Ʒ����ʹ�ã�
         ���ú��������佫�����ر��������ٶ��������ӵĸ��ţ�
		 ��JVNS_InitSDK��JVNS_StartChannelǰ���ü��ɣ�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SetIPCWANMode();
#else
	JVSERVER_API void __stdcall JVNS_SetIPCWANMode();
#endif

/****************************************************************************
*����  : JVNS_SetDeviceInfo
*����  : �����豸��Ϣ
*����  : [IN] pstInfo �豸��Ϣ�ṹ��
      	 [IN] nSize   �豸��Ϣ�ṹ���С,����ǰ�����
	     [IN] nflag   ����ѡ���־ 
*����ֵ: �ɹ�����0��ʧ�ܷ���-1
*����  : �������豸֧�ֵ�����ģʽΪ����+wifi����ǰ����ʹ�õ���wifi���������: 
		 nflag = DEV_SET_NET;//�����豸֧�ֵ�����ģʽ
		 pstInfo->nNetMod= NET_MOD_WIFI | NET_MOD_WIRED;
         pstInfo->nNetMod= NET_MOD_WIFI;//�豸��ǰʹ�õ���wifi
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_SetDeviceInfo(STDEVINFO *pstInfo, int nSize,int nflag);
#else
	JVSERVER_API int JVNS_SetDeviceInfo(STDEVINFO *pstInfo, int nSize,int nflag);
#endif
	
/****************************************************************************
*����  : JVNS_GetDeviceInfo
*����  : ��ȡ�豸��Ϣ
*����  : [OUT] pstInfo �豸��Ϣ�ṹ��
	     [IN]  nSize   �豸��Ϣ�ṹ���С,����ǰ�����
*����ֵ: �ɹ�����0��ʧ�ܷ���-1
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_GetDeviceInfo(STDEVINFO *pstInfo,int nSize);
#else
	JVSERVER_API int JVNS_GetDeviceInfo(STDEVINFO *pstInfo,int nSize);
#endif

/****************************************************************************
*����  : JVNS_GetNetSpeedNow
*����  : ��ȡ��ǰ����״��
*����  : [IN] nChannel	ͨ����
		 [IN] nClientID ���Ӻ�
		 [IN] nInterval	������, �ò���ȱʡʱΪĬ��ʱ����16��
		 [OUT] pSpeed ���ص�ǰ����״������λB/s
		 [OUT] pSendOK TRUE��ʾ��������,FALSE��ʾ�з���ʧ�ܣ�ͨ������Ϊ������
*����ֵ: �ɹ�����ֵ>0��ʧ�ܷ���-1
*����  : ���ص�ǰ����״��ֵ��ʧ��ʱԭ����Ҫ����Ƶ����û�п��������߲�������
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_GetNetSpeedNow(int nChannel, int nClientID, int nInterval, int* pSpeed, int* pSendOK, unsigned long *pdwFrameDelay);
#else
	JVSERVER_API int __stdcall JVNS_GetNetSpeedNow(int nChannel, int nClientID, int nInterval, int* pSpeed, BOOL* pSendOK, DWORD *pdwFrameDelay);
#endif

/****************************************************************************
*����  : JVNS_SetLSPrivateInfo
*����  : ���ñ����Զ�����Ϣ�������豸����
*����  : [IN]	chPrivateInfo  �Զ�����Ϣ
		 [IN]	nSize          �Զ�����Ϣ����		 
*����ֵ: ��
*����  : ���ظ����ã������һ�ε���Ϊ׼��֮ǰ�����ݻᱻ���ǣ�
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SetLSPrivateInfo(char chPrivateInfo[500], int nSize);
#else
	JVSERVER_API void __stdcall JVNS_SetLSPrivateInfo(char chPrivateInfo[500], int nSize);
#endif

/****************************************************************************
*����  : JVNS_RegNickName
*����  : ע�����
*����  : [IN]	chNickName  ������֧��6-32�ֽ�UTF8�ַ�������ֹʹ�������ַ�����ʽ���ַ���,�ַ����б������һ�������ַ�������@ & * _
*����ֵ: ����ע�������0��ʼ����ע��; -1������Ч; -2δ����; -3����ע����
*����  : ע�᷵�ؽ�����ص�����FUNC_RECVSERVERMSG_CALLBACK ����Ϊ0
*****************************************************************************/

#ifndef WIN32
	JVSERVER_API int JVNS_RegNickName(char chNickName[36]);
#else
	JVSERVER_API int __stdcall JVNS_RegNickName(char chNickName[36]);
#endif

/****************************************************************************
*����  : JVNS_DeleteNickName
*����  : ɾ������
*����  : [IN]	chNickName  ������֧��6-32�ֽ�UTF8�ַ�������ֹʹ�������ַ�����ʽ���ַ���,�ַ����б������һ�������ַ�������@ & * _
*����ֵ: ����ɾ�������0��ʼ����ɾ��; -1������Ч; -2δ����; -3����ɾ����
*����  : ɾ���Ƿ�ɹ����ص�����FUNC_RECVSERVERMSG_CALLBACK ����Ϊ2
*****************************************************************************/

#ifndef WIN32
	JVSERVER_API int JVNS_DeleteNickName(char chNickName[36]);
#else
	JVSERVER_API int __stdcall JVNS_DeleteNickName(char chNickName[36]);
#endif

/****************************************************************************
*����  : JVNS_SetNickName
*����  : �����ǳ� 
*����  : [IN] chDeviceName   �豸�ǳ�
*����ֵ: ��
*����  : 
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SetNickName(char chNickName[32]);
#else
	JVSERVER_API void __stdcall	JVNS_SetNickName(char chNickName[32]);
#endif

/****************************************************************************
*����  : JVNS_GetNickName
*����  : ��ȡ����
*����  : ��
*����ֵ: ���ػ�ȡ�����0��ʼ���л�ȡ; -1������Ч;-2���ڻ�ȡ�У��Ժ�����
*����  : ��ȡ������ص�����FUNC_RECVSERVERMSG_CALLBACK ����Ϊ3
*****************************************************************************/

#ifndef WIN32
	JVSERVER_API int JVNS_GetNickName();
#else
	JVSERVER_API int __stdcall JVNS_GetNickName();
#endif


/****************************************************************************
*����  : SendJvnInfo
*����  : ����ÿһ��ͨ������
*����  : [IN]	chnn_info	ͨ������
		 [IN]	svrAddr		��������ַ��ͨ���ص�����FUNC_RECVSERVERMSG_CALLBACK��ȡ		 
*����ֵ: ��
*����  : д���������Ϣ���յ��ص�������ٽ��в�����Ϣ�ķ���
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SendJvnInfo(JVSERVER_INFO *jvsvr_info, SOCKADDR_IN *svrAddr);
#else
	JVSERVER_API void __stdcall JVNS_SendJvnInfo(JVSERVER_INFO *jvsvr_info, SOCKADDR_IN *svrAddr);
#endif

/****************************************************************************
*����  : SendChannelInfo
*����  : ����ÿһ��ͨ������
*����  : [IN]	nMsgLen		��Ϣ����
		 [IN]	chChnInfo	ͨ����ϢCHANNEL_INFO(���), 	
		 [IN]	nConnCount  ÿһ�������Ӧһ������������int��ʾ����2�ֽڱ�ʾp2p�����������1�ֽڱ�ʾת�����������θ�1�ֽڱ�ʾ�ֻ�������
*����ֵ: ��
*����  : �״�����ʱ����ͨ������Ϣ���Ժ�CHANNEL_INFO�еĲ��������仯ʱ�ٴε���
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API void JVNS_SendChannelInfo(int nMsgLen, char *chChnInfo, int nConnCount);
#else
	JVSERVER_API void __stdcall	JVNS_SendChannelInfo(int nMsgLen, char *chChnInfo, int nConnCount);
#endif


/****************************************************************************
*����  : JVNS_GetExamItem
*����  : ��ȡ�����Ŀ
*����  : [IN,OUT]	pExamItem  ��Ҫ��ϵ���Ŀ�б�4BYTE ���� +�ı� [+ 4BYTE + �ı�...]
[IN]	nSize          ����ص�����		 
*����ֵ: int ���Լ�������Ŀ ==0 û�м���� <0 ��Ŀ�б���̫С
	*****************************************************************************/
	
#ifndef WIN32
	JVSERVER_API int  JVNS_GetExamItem(char *pExamItem,int nSize);
#else
		JVSERVER_API int __stdcall	JVNS_GetExamItem(char *pExamItem,int nSize);
#endif
	
/****************************************************************************
*����  : JVNS_ExamItem
*����  : ���ĳһ��
*����  : [IN]	nExamType  ������� ��-1 ȫ����� �������ݷ��ص���֪�������
[IN]	pUserInfo          ���ʱ�û���д����Ϣ		 
[IN]	callBackExam          ����ص�����		 
*����ֵ: ��
*****************************************************************************/
	
#ifndef WIN32
	JVSERVER_API int  JVNS_ExamItem(int nExamType,char* pUserInfo,FUNC_EXAM_CALLBACK callBackExam);
#else
	JVSERVER_API int __stdcall	JVNS_ExamItem(int nExamType,char* pUserInfo,FUNC_EXAM_CALLBACK callBackExam);
#endif


/****************************************************************************
*����  : JVNS_GetPositionID
*����  : ��ѯ��ǰ���ڵ�����
*����  : nGetType ��ѯ���� 1 ��ͨ����������ѯ 2��ͨ��afdvr��ѯ
*����ֵ: 0 ����  1 ���� -1 ����δ֪
*****************************************************************************/
#ifndef WIN32
	JVSERVER_API int JVNS_GetPositionID(int nGetType);
#else
	JVSERVER_API int __stdcall JVNS_GetPositionID(int nGetType);
#endif


#endif
