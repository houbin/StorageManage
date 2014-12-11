ͨ��Э�飺
����JSON-RPC 2.0(http://www.jsonrpc.org/specification)�޸Ķ�����
��ͬ��
1.ȡ����"jsonrpc"��Ա��id����ʡ�ԣ���֧��֪ͨ����
2.����������ֻ����"code"��Ա��"message"�Ǳ���
3.��֧����������

���ͣ�
		{
			"method":	"method",	//���õķ���������
			"params":				//��������Ĳ���,���޿�ʡ�ԡ�
		}
��Ӧ��
		{
			"result":				//���ý���������óɹ�ʱ���ó�Ա�Ǳ���ģ�������÷������ִ���ʱ�����벻�����ó�Ա���ó�Ա��ֵ�ɷ������ϵ��õķ���������
			"error":	{
				"code":	-32700,		//�����÷�������ʱ���ó�Ա�Ǳ���ġ��ڵ����ڼ����û�д�����������벻�����ó�Ա���������ֵ-32768��-32000Ϊ����ֵ����ΪԤ�������
				"message":	"Parse error. Invalid JSON was received by the server."		//�ṩ��̴����������ַ��������˸ı䣬���ǵ�Э�����ʡ�Ըó�Ա
			}
		}
		
jsonrpc�⣺https://github.com/hmng/jsonrpc-c


1.NVS_Cmd_Connect
��ȡ�豸��Ϣ������4����Ƕ��ʽ����������4���豸��ÿ���豸����һ����
eg.
	send:
		{
			"method":	"NVS_Cmd_Connect",
			"params":	{
				"username":	"abc",
				"passwd":	"123"
			}
		}
	response:
{
	"result":	[{
			"nVersion":	10,
			"acModel":	"VM9000-4HD",
			"acSwVersion":	"V1.0.1.3240",
			"acReleaseTime":	"Nov  5 2014 18:35:26",
			"nSN":	411806,
			"acGroup":	"B",
			"nYSTNO":	0,
			"acDevIP":	"199.196.199.1",
			"nChCount":	16,
			"nDeviceID":	0,
			"nDeviceCount":	4
		}, {
			"nVersion":	10,
			"acModel":	"VM9000-4HD",
			"acSwVersion":	"V1.0.1.3240",
			"acReleaseTime":	"Nov  5 2014 18:35:26",
			"nSN":	7661,
			"acGroup":	"B",
			"nYSTNO":	0,
			"acDevIP":	"199.196.199.2",
			"nChCount":	4,
			"nDeviceID":	1,
			"nDeviceCount":	4
		}, {
			"nVersion":	10,
			"acModel":	"VM9000-4HD",
			"acSwVersion":	"V1.0.1.3240",
			"acReleaseTime":	"Nov  5 2014 18:35:26",
			"nSN":	7661,
			"acGroup":	"B",
			"nYSTNO":	0,
			"acDevIP":	"199.196.199.3",
			"nChCount":	4,
			"nDeviceID":	2,
			"nDeviceCount":	4
		}, {
			"nVersion":	10,
			"acModel":	"VM9000-4HD",
			"acSwVersion":	"V1.0.1.3240",
			"acReleaseTime":	"Nov  5 2014 18:35:26",
			"nSN":	7661,
			"acGroup":	"B",
			"nYSTNO":	0,
			"acDevIP":	"199.196.199.4",
			"nChCount":	4,
			"nDeviceID":	3,
			"nDeviceCount":	4
		}]
}

		
2.NVS_Cmd_Disconnect
�Ͽ�����
eg.
	send:
		{
			"method":	"NVS_Cmd_Disconnect"
		}
	response:
		{
			"result":	0
		}

3.NVS_Cmd_GetDecoder
��ȡ����ͨ�����ã�nDevIDΪ-1��ʾ��ȡ�����豸�����н���ͨ��
eg.
	send:
		{
			"method":	"NVS_Cmd_GetDecoder",
			"params":	{
				"nDevID":	0,
				"nCh":		-1
			}
		}
	response:
		{
			"result":	[{
					"nDevID":	0,
					"nCh":	0,
					"stVs":	{
						"acGroup":	"A",
						"nYSTNO":	219329020,
						"acDevIP":	"192.168.6.223",
						"nPort":	9101,
						"nChannel":	1,
						"acID":	"abc",
						"acPW":	"123",
						"nIpcType":	0,
						"acServiceAddr":	""
					}
				}]
		}

4.NVS_Cmd_SetDecoder
���ý���ͨ����nYSTNOΪ0��ʾɾ�����������
eg.
	send:
		{
			"method":	"NVS_Cmd_SetDecoder",
			"params":	{
					"nDevID":       0,
					"nCh":  0,
					"stVs": {
									"acGroup":	"A",
									"nYSTNO":	219329020,
									"acDevIP":	"192.168.6.223",
									"nPort":	9101,
									"nChannel":	0,
									"acID":	"abc",
									"acPW":	"123",
									"nIpcType":	0,
									"acServiceAddr":	""
					}
			}
		}


		{
			"method":	"NVS_Cmd_SetDecoder",
			"params":	{
					"nDevID":       0,
					"nCh":  0,
					"stVs": {
									"acGroup":	"A",
									"nYSTNO":	2526293556,
									"acDevIP":	"192.168.6.105",
									"nPort":	9101,
									"nChannel":	0,
									"acID":	"abc",
									"acPW":	"123",
									"nIpcType":	0,
									"acServiceAddr":	""
					}
			}
		}
{
			"method":	"NVS_Cmd_SetDecoder",
			"params":	{
					"nDevID":       0,
					"nCh":  0,
					"stVs": {
									"acGroup":	"A",
									"nYSTNO":	506968066,
									"acDevIP":	"192.168.6.162",
									"nPort":	9101,
									"nChannel":	0,
									"acID":	"abc",
									"acPW":	"123",
									"nIpcType":	0,
									"acServiceAddr":	""
					}
			}
		}
	response:
		{
			"result":	0
		}
	

6.NVS_Cmd_GetDisplay
��ȡ������ʾģʽ
eg.
	send:
	{
		"method":	"NVS_Cmd_GetDisplay",
		"params":	{
			"nDevID":	0,
			"nCh":		-1
		}
	}
	response:
	{
		"result":	{
			"nViewMode":	16,
			"nViewWindow":	16,
			"nSelected":	0,
			"nStartPos":	0,
			"nModeList":	[1, 4, 8, 9, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		}
	}

7.NVS_Cmd_SetDisplay
���û�����ʾģʽ
eg.
	send:
	{
		"method":	"NVS_Cmd_SetDisplay",
		"params":	{
	        "nDevID":       0,
	        "stDisplay":    {
	                "nViewMode":    8,
	                "nViewWindow":  8,
	                "nSelected":    1,
	                "nStartPos":    0
	        }
		}
	}
	response:
	{
		"result":	0
	}
	
8.NVS_Cmd_GetTour
��ȡ������Ϣ
eg.
	send:
		{
	        "method":       "NVS_Cmd_GetTour",
	        "params":       {
	                "nDevID":       1,
	                "nCh":  -1
	        }
		}
	response:
		{
		        "result":       {
		                "bTour":        1,
		                "secInterval":  5
		        }
		}	
	
8.NVS_Cmd_SetTour
��ȡ������Ϣ
eg.
	send:
		{
		    "method":       "NVS_Cmd_SetTour",
		    "params":       {
		        "nDevID":       1,
		        "stTour":       {
		            "bTour":        0,
		            "secInterval":  5
		        }
		    }
		}
	response:
		{
		    "result":       0
		}

9.NVS_Cmd_GetDecoderStatus
��ȡ����״̬
eg.
	send:
{
        "method":       "NVS_Cmd_GetDecoderStatus",
        "params":       {
                "nDevID":       0,
                "nCh":  1
        }
}
	response:
{
        "result":       [{
                        "nDevID":       1,
                        "nCh":  0,
                        "nStatus":      3
                }, {
                        "nDevID":       1,
                        "nCh":  1,
                        "nStatus":      3
                }, {
                        "nDevID":       1,
                        "nCh":  2,
                        "nStatus":      3
                }, {
                        "nDevID":       1,
                        "nCh":  3,
                        "nStatus":      3
                }]
}

10.NVS_Cmd_GetScreen
��ȡ��ʾ����Ƶ���ڲ���
eg.
	send:
{
        "method":       "NVS_Cmd_GetScreen",
        "params":       {
                "nDevID":       0,
                "nCh":  -1
        }
}
	response:
{
        "result":       {
                "nBright":      30,
                "nContrast":    35,
                "nSaturation":  45,
                "stResolution": {
                        "nW":   1280,
                        "nH":   1024
                },
                "stList":       [{
                                "nW":   1024,
                                "nH":   768
                        }, {
                                "nW":   1280,
                                "nH":   800
                        }, {
                                "nW":   1280,
                                "nH":   1024
                        }, {
                                "nW":   1440,
                                "nH":   900
                        }, {
                                "nW":   1920,
                                "nH":   1080
                        }, {
                                "nW":   0,
                                "nH":   0
                        }, {
                                "nW":   0,
                                "nH":   0
                        }, {
                                "nW":   0,
                                "nH":   0
                        }]
        }
}

11.NVS_Cmd_SetScreen
��ȡ��ʾ����Ƶ���ڲ���
eg.
	send:
{
        "method":       "NVS_Cmd_SetScreen",
        "params":       {
                "nDevID":       0,
                "stScreen":     {
                        "nBright":      50,
                        "nContrast":    55,
                        "nSaturation":  55,
                        "stResolution": {
                                "nW":   1280,
                                "nH":   1024
                        },
                        "stList":       [{
                                        "nW":   1024,
                                        "nH":   768
                                }, {
                                        "nW":   1280,
                                        "nH":   800
                                }, {
                                        "nW":   1280,
                                        "nH":   1024
                                }, {
                                        "nW":   1440,
                                        "nH":   900
                                }, {
                                        "nW":   1920,
                                        "nH":   1080
                                }, {
                                        "nW":   0,
                                        "nH":   0
                                }, {
                                        "nW":   0,
                                        "nH":   0
                                }, {
                                        "nW":   0,
                                        "nH":   0
                                }]
                }
        }
}
	response:
{
        "result":       0
}


12.NVS_Cmd_SetReboot
�豸�������߻ָ����ã�nDevID��-1��ʾ�����豸
eg.
	send:
{
        "method":       "NVS_Cmd_SetReboot",
        "params":       {
                "nDevID":       1,
                "stReboot":     {
                        "bReboot":      1,
                        "bResetCfg":    1,
                        "bResetNetCfg": 1,
                        "bResetUser":   1,
                        "bResetYstNO":  1,
                        "bResetLanguage":       1,
                        "bResetLog":    1
                }
        }
}
	response:
{
        "result":       0
}


13.NVS_Cmd_SysCmd
ִ��ϵͳ����
eg.
	send:
{
        "method":       "NVS_Cmd_SysCmd",
        "params":       {
                "nDevID":       1,
                "stCmd":        {
                        "buf":  "df"
                }
        }
}
	response:
{
        "result":       {
                "buf":  "Filesystem           1K-blocks      Used Available Use% Mounted on\n/dev/root                38733     29662      7071  81% /\ntmpfs                   256436         4    256432   0% /dev\n/dev/mtdblock3            2048       244      1804  12% /etc/conf.d\n192.168.6.53:/home/zwq/nfs\n                      19737280  14455808   4278880  77% /progs\n"
        }
}

14.NVS_Cmd_Update
ϵͳ������nDevID��������
eg.
	send:
{
        "method":       "NVS_Cmd_Update",
        "params":       {
                "nDevID":       1,
                "stUpdate":        {
                        "addr":  "usb"
                }
        }
}
{
        "method":       "NVS_Cmd_Update",
        "params":       {
                "nDevID":       1,
                "stUpdate":        {
                        "addr":  "ftp://192.168.8.118"
                }
        }
}
{
        "method":       "NVS_Cmd_Update",
        "params":       {
                "nDevID":       1,
                "stUpdate":        {
                        "addr":  "http://www.jovetech.com"
                }
        }
}
	response:
{
        "result":       {
                "buf":  "Filesystem           1K-blocks      Used Available Use% Mounted on\n/dev/root                38733     29662      7071  81% /\ntmpfs                   256436         4    256432   0% /dev\n/dev/mtdblock3            2048       244      1804  12% /etc/conf.d\n192.168.6.53:/home/zwq/nfs\n                      19737280  14455808   4278880  77% /progs\n"
        }
}

15.NVS_Cmd_GetNetwork
��ȡ���������nDevID��������
�᷵����������ӿڵ����á�
eg.
	send:
{
        "method":       "NVS_Cmd_GetNetwork",
        "params":       {
                "nDevID":       -1,
                "nCh":  -1
        }
}
	response:

{
	"result":	[{
			"devName":	"eth1",
			"bDhcp":	0,
			"ip":	"192.168.6.122",
			"mask":	"255.255.255.0",
			"gw":	"192.168.6.1",
			"dns":	"192.168.6.1"
		}]
}

16.NVS_Cmd_SetNetwork
�������������nDevID��������
�᷵����������ӿڵ����á�
eg.
	send:
{
        "method":       "NVS_Cmd_SetNetwork",
        "params":       {
                "nDevID":       1,
                "stNetwork":        {
						"devName":	"eth1",
						"bDhcp":	0,
						"ip":	"192.168.6.122",
						"mask":	"255.255.255.0",
						"gw":	"192.168.6.1",
						"dns":	"192.168.6.1"
                }
		}
}
	response:
һ���ղ����ظ�
{
        "result":       0
}


17.NVS_Cmd_GetUser
��ȡ�û����ã�nDevID��������
�᷵��ȫ�����û����á�
eg.
	send:
{
        "method":       "NVS_Cmd_GetUser",
        "params":       {
                "nDevID":       -1,
                "nCh":  -1
        }
}
	response:
{
	"result":	[{
			"username":	"abc",
			"passwd":	"",
			"bLocal":	1,
			"pwRecord":	1,
			"pwSnap":	1,
			"pwNet":	1,
			"pwSys":	1,
			"pwPTZ":	1,
			"pwVideo":	1,
			"pwQuit":	1,
			"pwOther":	1,
			"pwVsMgr":	1,
			"pwView":	1
		}, {
			"username":	"abc",
			"passwd":	"123",
			"bLocal":	0,
			"pwRecord":	1,
			"pwSnap":	0,
			"pwNet":	0,
			"pwSys":	1,
			"pwPTZ":	1,
			"pwVideo":	0,
			"pwQuit":	0,
			"pwOther":	1,
			"pwVsMgr":	0,
			"pwView":	1
		}]
}

17.NVS_Cmd_SetUser
�����û����ã�nDevID�������塣
����û��Ѵ��ھ��޸ģ����������ӡ�
{
        "method":       "NVS_Cmd_SetUser",
        "params":       {
                "nDevID":       1,
                "stUser":        {
									"username":	"abc",
									"passwd":	"123",
									"bLocal":	1,
									"pwRecord":	1,
									"pwSnap":	0,
									"pwNet":	0,
									"pwSys":	1,
									"pwPTZ":	1,
									"pwVideo":	0,
									"pwQuit":	0,
									"pwOther":	1,
									"pwVsMgr":	0,
									"pwView":	1
								}
		}
}
	response:
{
	"result":	0
}

