
#pragma once

typedef char				int8_t; 
typedef unsigned char		uint8_t; 
typedef short				int16_t; 
typedef unsigned short		uint16_t; 
typedef int					int32_t; 
typedef unsigned			uint32_t; 

//StartCode-------------------------------------------------
#define JVSC900_STARTCODE	0x0453564A
#define DVR8004_STARTCODE	0x0553564A
#define JVSC950_STARTCODE	0x0653564A
#define JVSC951_STARTCODE	0x0753564A
#define JVSC920_STARTCODE	0x0953564A
#define JVSDEC05_STARTCODE	0x0A53564A

#define IPC3507_STARTCODE	0x1053564A
#define IPC_DEC_STARTCODE	0x1153564A //1080

#define JVSNVR_STARTCODE	0x2053564A

//�豸����
#define JVS_DEVICETYPE_CARD	0x0001
#define JVS_DEVICETYPE_DVR	0x0002
#define JVS_DEVICETYPE_IPC	0x0003
#define JVS_DEVICETYPE_NVR	0x0004
#define JVS_DEVICETYPE_JNVR	0x0005

//��������
#define JVS_VIDEOCODECTYPE_JENC04	0x0000	//04�������
#define JVS_VIDEOCODECTYPE_H264		0x0001	//��׼h264

#define JVS_AUDIOCODECTYPE_PCM			0x0000	//PCMԭʼ����
#define JVS_AUDIOCODECTYPE_AMR			0x0001
#define JVS_AUDIOCODECTYPE_G711_alaw	0x0002
#define JVS_AUDIOCODECTYPE_G711_ulaw	0x0003

//��Ƶ��������
#define JVS_VIDEODATATYPE_VIDEO			0x0000
#define JVS_VIDEODATATYPE_VIDEOANDAUDIO	0x0001

//��Ƶģʽ
#define JVS_VIDEOFORMAT_PAL				0x0000
#define JVS_VIDEOFORMAT_NTSC			0x0001

//¼������
#define JVS_RECFILETYPE_SV4				0x0000
#define JVS_RECFILETYPE_SV5				0x0001
#define JVS_RECFILETYPE_SV6				0x0002
#define JVS_RECFILETYPE_MP4				0x0003

typedef struct _JVS_FILE_HEADER
{
	uint32_t	dwFLAGS;			//��ά¼���ļ�ͷ��־�ֶ�
	uint32_t	dwFrameWidth;		//֡��
	uint32_t	dwFrameHeight;		//֡��
	uint32_t	dwTotalFrames;		//��֡��
	uint32_t	dwVideoFormat;		//Դ��Ƶ��ʽ��0��ʾPAL��1��ʾNTSC
	uint32_t	bThrowFrame;		//�Ƿ��֡��0��ʾ����֡��1��ʾ��֡��������ģʽ��
	uint32_t	dwSubFLAGS;			//���ļ�ͷ���(NVR��)
	uint32_t	dwReserved2;		//�����ֶ�
} JVS_FILE_HEADER, *PJVS_FILE_HEADER;

typedef struct _JVS_FILE_HEADER_EX
{
	//���ļ�ͷ��Ϊ������ǰ�汾�ֿأ���֤��������Ԥ��
#if 0
	uint8_t			ucOldHeader[32];//JVS_FILE_HEADER	oldHeader; //�˴����岻��ֱ�Ӷ���ΪJVS_FILE_HEADER���ͣ�������нṹ���Ա��������
#else
	uint32_t	dwFLAGS;			//��ά¼���ļ�ͷ��־�ֶ�
	uint32_t	dwFrameWidth;		//֡��
	uint32_t	dwFrameHeight;		//֡��
	uint32_t	dwTotalFrames;		//��֡��
	uint32_t	dwVideoFormat;		//Դ��Ƶ��ʽ��0��ʾPAL��1��ʾNTSC
	uint32_t	bThrowFrame;		//�Ƿ��֡��0��ʾ����֡��1��ʾ��֡��������ģʽ��
	uint32_t	dwReserved1;		//�����ֶ�
	uint32_t	dwReserved2;		//�����ֶ�
#endif

	//�ṹ����Ϣ
	uint8_t			ucHeader[3];		//�ṹ��ʶ���룬����Ϊ��J','F','H'
	uint8_t			ucVersion;			//�ṹ��汾�ţ���ǰ�汾Ϊ1

	//�豸���
	uint16_t		wDeviceType;		//�豸����

	//��Ƶ����
	uint16_t		wVideoCodecID;		//��Ƶ��������
	uint16_t		wVideoDataType;		//��������
	uint16_t		wVideoFormat;		//��Ƶģʽ
	uint16_t		wVideoWidth;		//��Ƶ��
	uint16_t		wVideoHeight;		//��Ƶ��
	uint16_t		wFrameRateNum;		//֡�ʷ���
	uint16_t		wFrameRateDen;		//֡�ʷ�ĸ

	//��Ƶ����
	uint16_t		wAudioCodecID;		//��Ƶ�����ʽ
	uint16_t		wAudioSampleRate;	//��Ƶ������
	uint16_t		wAudioChannels;		//��Ƶ������
	uint16_t		wAudioBits;			//��Ƶ����λ��

	//¼�����
	uint32_t		dwRecFileTotalFrames;	//¼����֡��
	uint16_t		wRecFileType;		//¼������

	//����λ
	uint8_t			ucReserved[30];		//��ȫ����0

} JVS_FILE_HEADER_EX, *PJVS_FILE_HEADER_EX;

inline BOOL IsFILE_HEADER_EX(void *pBuffer, uint32_t dwSize)
{
	uint8_t *pacBuffer = (uint8_t*)pBuffer;

	if(pBuffer == NULL || dwSize < sizeof(JVS_FILE_HEADER_EX))
	{
		return FALSE;
	}

	return pacBuffer[32] == 'J' && pacBuffer[33] == 'F' && pacBuffer[34] == 'H';
}
