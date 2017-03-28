// dllTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "./../ServoDriverManagerDll/Basetype_def.h"
#include "./../ServoDriverManagerDll/ServoDriverManagerDll.h"
#include "./../ServoDriverComDll/ServoDriverComDll.h"
#include "plotWaveThread.h"

//////////////////////////////////////////////////////////////////////////

#define DRIVER_CMD			0
#define DRIVER_MANAGER		1
#define DRIVER_CMD_RN		2


//#define  CURRENT_TEST   DRIVER_CMD_RN
#define  CURRENT_TEST   DRIVER_CMD
//#define  CURRENT_TEST   DRIVER_MANAGER
	GENERALFUNCTION func;
//////////////////////////////////////////////////////////////////////////
void UpdataProgressPt(void* pt, int16* progress)
{

}
void* ptr = NULL;

int _tmain(int argc, _TCHAR* argv[])
{
#if(CURRENT_TEST == DRIVER_MANAGER)
	SDM_CreateObject();

	//wstring filepath = L"E:\\googoltech_program\\ARM_program\\CM408\\IAR_SERVO(V116_0822)\\IAR_SERVO\\Servo Control";
	//wstring filepath = L"E:\\googoltech_program\\ARM_program\\CM408\\IAR_SERVO(V117_0902)\\IAR_SERVO\\Servo Control";
	//wstring filepath = L"E:\\googoltech_program\\ARM_program\\CM408\\IAR_SERVO(V119_0922)\\IAR_SERVO\\Servo Control";
	wstring filepath = L"E:\\googoltech_program\\ARM_program\\CM408\\IAR_SERVO(V121_0105)\\IAR_SERVO";

	SDM_VS2IAR(filepath);
	
	//这里需要输入路径，根据不同的机器安装路径和工程路径的不同
	wstring filepathGetAddr = L"E:\\googoltech_program\\ARM_program\\CM408\\IAR_SERVO(V121_0105)\\IAR_SERVO\\GetAddr";
	wstring installpath		= L"D:\\IAR\\common\\bin";
	SDM_RUNBAT(filepathGetAddr, installpath);
	/**/
	wstring Addrfilepath = L"Addr.txt";
	wstring xmlfilepath;
	SDM_GetXmlDirName(xmlfilepath);
	xmlfilepath = L".\\" + xmlfilepath;

	SDM_IAR2VS(Addrfilepath, xmlfilepath);

	wstring readxmlpath = L".\\XmlFiles\\PrmPrtyTree.xml";
	SDM_ReadPrtyXml(readxmlpath);

	//test xml file
	readxmlpath = L".\\XmlFiles\\PrmPrtyTree_Old.xml";
	SDM_ReadPrtyOldXml(readxmlpath);

	SDM_PrtyCompareUpdate();

	//将更新后的数据重新写入xml
	wstring writexmlpath = L".\\XmlFiles\\PrmPrtyTree.xml";
	SDM_WritePrtyXml(xmlfilepath,writexmlpath);
	writexmlpath = L".\\XmlFiles\\PrmPrtyTree_Old.xml";
	SDM_WritePrtyXml(xmlfilepath,writexmlpath);

	//////////////////////////////////////////////////////////////////////////

	wstring readPrmXmlPath = L".\\XmlFiles\\FramPrm_4Axis.xml";
	SDM_ReadPrmXml(readPrmXmlPath);

	readPrmXmlPath = L".\\XmlFiles\\FramPrm_4Axis_old.xml";
	SDM_ReadOldPrmXml(readPrmXmlPath);

	SDM_PrmCompareUpdate();

	//将更新后的数据重新写入xml
	wstring writePrmXmlPath = L".\\XmlFiles\\FramPrm_4Axis.xml";
	SDM_WritePrmXml(xmlfilepath,writePrmXmlPath);
	writePrmXmlPath = L".\\XmlFiles\\FramPrm_4Axis_old.xml";
	SDM_WriteOldPrmXml(xmlfilepath, writePrmXmlPath);

	

	//////////////////////////////////////////////////////////////////////////



	SDM_DeleteObject();
#endif

#if(CURRENT_TEST == DRIVER_CMD)
	int16 rtn;
	rtn = GTSD_CMD_Open(UpdataProgressPt, ptr, GTSD_COM_TYPE_NET);
	if (rtn != 0)
	{
		return -1;
	}
	 /**/
	
	//测试网卡信息
	GTSD_CMD_GetNetCardMsg();
	/*
	//测试复位
	string filepath = ".\\Servo.hex";
	GTSD_CMD_SetServoOn(0);
	GTSD_CMD_ProcessorFlashHandler(0, filepath);
	GTSD_CMD_ResetSystem(0);
	bool flag = false;
	while (flag == false)
	{
		GTSD_CMD_CheckResetFinish(0, flag);
	}
	*/
	//测试hex2ldr
	/*string LdrFile;
	string HexFile = ".\\hex2ldr_test\\Servo.out";
	LdrFile = ".\\hex2ldr_test\\Servo.ldr";
	GTSD_CMD_Hex2Ldr(HexFile,LdrFile);*/

	//////////////////////////////////////////////////////////////////////////
	/*
	wstring LdrFile;
	wstring HexFile = L".\\中文路径测试\\Servo.out";
	LdrFile = L".\\中文路径测试\\Servo.ldr";
	GTSD_CMD_Hex2Ldr(HexFile, LdrFile);*/
	//////////////////////////////////////////////////////////////////////////
	/*
	//测试uart boot
	int16 axis = 0;
	int32 baudRate = 115200;
	int16 cmd = UARTBOOT::UART_ERASE;	
	string inputKey = "a5e4b8a4d71d04d2f89d8318fec19283";//"a4b8e4a5d2041dd718839df88392c1fe";a5e4b8a4d71d04d2f89d8318fec19283
	//GTSD_CMD_ProcessorUartBootHandler(axis, LdrFile, baudRate, cmd, inputKey, UpdataProgressPt, ptr);
	//测试ADI 的ldr文件
	//LdrFile = ".\\hex2ldr_test\\Button_LED_GPIO_CM408F.ldr";
	//LdrFile = ".\\hex2ldr_test\\ADSP-CM40x-FlashProgrammer.ldr";
	LdrFile = ".\\hex2ldr_test\\Servo.ldr";
	cmd = UARTBOOT::UART_PROGRAM;
	GTSD_CMD_ProcessorUartBootHandler(axis, LdrFile, baudRate, cmd, inputKey, UpdataProgressPt,ptr);


	//另一个CM408boot 测试
	axis = 2;
	baudRate = 115200;
	GTSD_CMD_ProcessorUartBootHandler(axis, LdrFile, baudRate, cmd, inputKey, UpdataProgressPt, ptr);

	//////////////////////////////////////////////////////////////////////////
	rtn = GTSD_CMD_Close();
	if (rtn != 0)
	{
		return -1;
	}*/
#endif


//////////////////////////////////////////////////////////////////////////
#if(CURRENT_TEST == DRIVER_CMD_RN)
	int16 rtn;
	rtn = GTSD_CMD_Open(UpdataProgressPt, ptr, GTSD_COM_TYPE_RNNET);
	if (rtn != 0)
	{
		return -1;
	}
	////测试等环网fpga读写
	//int16 com_addr = (0xe);
	//int16 valueFPGA;
	//GTSD_CMD_Get16bitFPGAByAddr(0, com_addr, &valueFPGA, GTSD_COM_TYPE_RNNET, 0xf0);

	//com_addr = (0xc*2);
	//valueFPGA = 1;
	//GTSD_CMD_Set16bitFPGAByAddr(0, com_addr, valueFPGA, GTSD_COM_TYPE_RNNET, 0xf0);
	//int16 valueFPGArtn = 0;;
	//GTSD_CMD_Get16bitFPGAByAddr(0, com_addr, &valueFPGArtn, GTSD_COM_TYPE_RNNET, 0xf0);


	int16 axis = 2;
	int16 stationId = 0xf0;

	Uint32 alarmCode[32];
	Uint16  alarmTimes[64];
	Uint16 lenth0,lenth1;
	lenth0 = 10;
	lenth1 = 32;
	for (int32 k = 0; k < 10; k++)
	{
		GTSD_CMD_ReadLogAlarmCode(axis, alarmCode, lenth0,GTSD_COM_TYPE_RNNET,stationId);

		GTSD_CMD_ReadLogAlarmTimes(axis, alarmTimes, lenth1, GTSD_COM_TYPE_RNNET, stationId);
	}
	rtn = GTSD_CMD_Close(GTSD_COM_TYPE_RNNET);
	if (rtn != 0)
	{
		return -1;
	}
/*	

	func.cmd = 41;
	func.data = new int16[16];
	func.data[3] = 27;
	func.mode = 1;
	func.dataLenth = 10;
	for (int32 k = 0; k < 10000;k++)
	{
		rtn = GTSD_CMD_SetServoOn(axis, GTSD_COM_TYPE_RNNET, stationId); 
		if (rtn != 0)
		{
			return -1;
		}
		rtn = GTSD_CMD_ProcessorGeneralFunc(axis, &func, GTSD_COM_TYPE_RNNET, stationId);
		if (rtn != 0)
		{
			return -1;
		}
	}
*/	

	////关闭重新打开通信测试
	//rtn = GTSD_CMD_Close(GTSD_COM_TYPE_RNNET);
	//if (rtn != 0)
	//{
	//	return -1;
	//}
	//rtn = GTSD_CMD_Open(GTSD_COM_TYPE_RNNET);
	//if (rtn != 0)
	//{
	//	return -1;
	//}
	//rtn = GTSD_CMD_SetServoOn(axis, GTSD_COM_TYPE_RNNET, stationId);
	//if (rtn != 0)
	//{
	//	return -1;
	//}

	////关闭重新打开通信测试
	//rtn = GTSD_CMD_Close(GTSD_COM_TYPE_RNNET);
	//if (rtn != 0)
	//{
	//	return -1;
	//}
	//////////////////////////////////////////////////////////////////////////


	
	double id_ref = 3.0;
	rtn = GTSD_CMD_SetIdRef(axis,id_ref,GTSD_COM_TYPE_RNNET,stationId);
	ID_STATE my_id_ref;
	rtn = GTSD_CMD_GetIdRef(axis, &my_id_ref, GTSD_COM_TYPE_RNNET,stationId);

	//测试另一个轴
	axis = 2;
	rtn = GTSD_CMD_SetServoOn(axis, GTSD_COM_TYPE_RNNET, stationId);
	if (rtn != 0)
	{
		return -1;
	}
	double id_ref_2 = 5.0;
	rtn = GTSD_CMD_SetIdRef(axis, id_ref_2, GTSD_COM_TYPE_RNNET, stationId);
	ID_STATE my_id_ref_2;
	rtn = GTSD_CMD_GetIdRef(axis, &my_id_ref_2, GTSD_COM_TYPE_RNNET, stationId);

	int16 ofst = 100;
	int16 value = 0;
	rtn = GTSD_CMD_Fram_Read16BitByAdr(axis, ofst, &value, GTSD_COM_TYPE_RNNET, stationId);
	value = 100;
	rtn = GTSD_CMD_Fram_Write16BitByAdr(axis, ofst, value, GTSD_COM_TYPE_RNNET, stationId);
	value = 300;
	rtn = GTSD_CMD_Fram_Read16BitByAdr(axis, ofst, &value, GTSD_COM_TYPE_RNNET, stationId);

	//测试曲线功能
	//////////////////////////////////////////////////////////////////////////
	//20条曲线测试
	waveA.cmd.bit.TIM = TIME_SCALE;
	waveA.cmd.bit.NUM = LINE_NUMBER;
	waveA.cmd.bit.ENP = 1;

	waveA.inf[0].bytes = 2; waveA.inf[0].ofst = 0;
	waveA.inf[1].bytes = 2; waveA.inf[1].ofst = 0;
	waveA.inf[2].bytes = 4; waveA.inf[2].ofst = 0;
	waveA.inf[3].bytes = 8; waveA.inf[3].ofst = 0;
	waveA.inf[4].bytes = 2; waveA.inf[4].ofst = 0;
	waveA.inf[5].bytes = 2; waveA.inf[5].ofst = 0;
	waveA.inf[6].bytes = 4; waveA.inf[6].ofst = 0;
	waveA.inf[7].bytes = 8; waveA.inf[7].ofst = 0;
	waveA.inf[8].bytes = 2; waveA.inf[8].ofst = 0;
	waveA.inf[9].bytes = 2; waveA.inf[9].ofst = 0;
	waveA.inf[10].bytes = 4; waveA.inf[10].ofst = 0;
	waveA.inf[11].bytes = 8; waveA.inf[11].ofst = 0;
	waveA.inf[12].bytes = 2; waveA.inf[12].ofst = 0;
	waveA.inf[13].bytes = 2; waveA.inf[13].ofst = 0;
	waveA.inf[14].bytes = 4; waveA.inf[14].ofst = 0;
	waveA.inf[15].bytes = 8; waveA.inf[15].ofst = 0;
	waveA.inf[16].bytes = 2; waveA.inf[16].ofst = 0;
	waveA.inf[17].bytes = 2; waveA.inf[17].ofst = 0;
	waveA.inf[18].bytes = 4; waveA.inf[18].ofst = 0;
	waveA.inf[19].bytes = 8; waveA.inf[19].ofst = 0;


	waveB.cmd.bit.TIM = TIME_SCALE;
	waveB.cmd.bit.NUM = LINE_NUMBER;
	waveB.cmd.bit.ENP = 1;

	waveB.inf[0].bytes = 2; waveB.inf[0].ofst = 0;
	waveB.inf[1].bytes = 2; waveB.inf[1].ofst = 0;
	waveB.inf[2].bytes = 4; waveB.inf[2].ofst = 0;
	waveB.inf[3].bytes = 8; waveB.inf[3].ofst = 0;
	waveB.inf[4].bytes = 2; waveB.inf[4].ofst = 0;
	waveB.inf[5].bytes = 2; waveB.inf[5].ofst = 0;
	waveB.inf[6].bytes = 4; waveB.inf[6].ofst = 0;
	waveB.inf[7].bytes = 8; waveB.inf[7].ofst = 0;
	waveB.inf[8].bytes = 2; waveB.inf[8].ofst = 0;
	waveB.inf[9].bytes = 2; waveB.inf[9].ofst = 0;
	waveB.inf[10].bytes = 4; waveB.inf[10].ofst = 0;
	waveB.inf[11].bytes = 8; waveB.inf[11].ofst = 0;
	waveB.inf[12].bytes = 2; waveB.inf[12].ofst = 0;
	waveB.inf[13].bytes = 2; waveB.inf[13].ofst = 0;
	waveB.inf[14].bytes = 4; waveB.inf[14].ofst = 0;
	waveB.inf[15].bytes = 8; waveB.inf[15].ofst = 0;
	waveB.inf[16].bytes = 2; waveB.inf[16].ofst = 0;
	waveB.inf[17].bytes = 2; waveB.inf[17].ofst = 0;
	waveB.inf[18].bytes = 4; waveB.inf[18].ofst = 0;
	waveB.inf[19].bytes = 8; waveB.inf[19].ofst = 0;

	

	axis = 0;
	rtn = GTSD_CMD_StartPlot(axis, waveA, GTSD_COM_TYPE_RNNET, stationId);						//启动ARM画图
	axis = 2;
	rtn = GTSD_CMD_StartPlot(axis, waveB, GTSD_COM_TYPE_RNNET, stationId);						//启动ARM画图
	//创建上位机线程
	createPlotWaveTestThread();

	//主程序默认睡眠
	Sleep(100000);

	axis = 0;
	rtn = GTSD_CMD_StopPlot(axis, waveA, GTSD_COM_TYPE_RNNET, stationId);							//停止ARM画图
	axis = 2;
	rtn = GTSD_CMD_StopPlot(axis, waveB, GTSD_COM_TYPE_RNNET, stationId);							//停止ARM画图


	//////////////////////////////////////////////////////////////////////////
	//测试重新启动

	//重新创建上位机线程，因为之前的线程退出了
	waveA.cmd.bit.ENP = 1;
	waveB.cmd.bit.ENP = 1;
	

	axis = 0;
	rtn = GTSD_CMD_StartPlot(axis, waveA, GTSD_COM_TYPE_RNNET, stationId);						//启动ARM画图
	axis = 2;
	rtn = GTSD_CMD_StartPlot(axis, waveB, GTSD_COM_TYPE_RNNET, stationId);						//启动ARM画图
	createPlotWaveTestThread();

	//主程序默认睡眠
	Sleep(100000);

	axis = 0;
	rtn = GTSD_CMD_StopPlot(axis, waveA, GTSD_COM_TYPE_RNNET, stationId);							//停止ARM画图
	axis = 2;
	rtn = GTSD_CMD_StopPlot(axis, waveB, GTSD_COM_TYPE_RNNET, stationId);							//停止ARM画图

	rtn = GTSD_CMD_Close();
	if (rtn != 0)
	{
		return -1;
	}
#endif



//////////////////////////////////////////////////////////////////////////

	
	return 0;
}

