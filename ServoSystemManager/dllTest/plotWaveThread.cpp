#include "stdafx.h"
#include "./../ServoDriverManagerDll/Basetype_def.h"
#include <process.h>
#include "./../ServoDriverComDll/ServoDriverComDll.h"
#include "plotWaveThread.h"

HANDLE g_hThread = NULL;

WAVE_BUF_PRM waveA;
WAVE_BUF_PRM waveB;

double mylinearrayA[LINE_NUMBER][MY_WAVE_MAX_LENTH+1000];
double* mydataA;
int32  mynumberA;
int32 mylinearrarindexA = 0;

double mylinearrayB[LINE_NUMBER][MY_WAVE_MAX_LENTH+1000];
double* mydataB;
int32  mynumberB;
int32 mylinearrarindexB = 0;

void createPlotWaveTestThread()
{
	mylinearrarindexA = 0;
	mylinearrarindexB = 0;
	g_hThread = (HANDLE)_beginthreadex(NULL, 0, &PlotWaveTestThread, NULL, 0, NULL);
	//SetThreadPriority(g_hThread, THREAD_PRIORITY_TIME_CRITICAL);
}

unsigned __stdcall PlotWaveTestThread(void *para)
{
	int16 axis;
	int16 stationId = 0xf0;
	//Sleep(500);
	while ((waveA.cmd.bit.ENP == 1) || (waveB.cmd.bit.ENP == 1))
	{
		axis = 0;

		GTSD_CMD_PcGetWaveData(axis, &mydataA, mynumberA, GTSD_COM_TYPE_RNNET, stationId);			//从ARM获取数据

		if (mynumberA != 0)
		{		
			for (int16 i = 0; i < LINE_NUMBER; ++i)
			{
				memcpy_s(&mylinearrayA[i][mylinearrarindexA], mynumberA*sizeof(double), (mydataA + 10000*i), mynumberA*sizeof(double));
			}
			mylinearrarindexA += mynumberA;
		}
		if (mylinearrarindexA >= MY_WAVE_MAX_LENTH)
		{
			mylinearrarindexA = 0;
		}
		axis = 2;

		GTSD_CMD_PcGetWaveData(axis, &mydataB, mynumberB, GTSD_COM_TYPE_RNNET, stationId);			//从ARM获取数据

		if (mynumberB != 0)
		{
			for (int16 i = 0; i < LINE_NUMBER; ++i)
			{
				memcpy_s(&mylinearrayB[i][mylinearrarindexB], mynumberB*sizeof(double), (mydataB + i*10000), mynumberB*sizeof(double));
			}
			mylinearrarindexB += mynumberB;
		}
		if (mylinearrarindexB >= MY_WAVE_MAX_LENTH)
		{
			mylinearrarindexB = 0;
		}
	}

	return 0;
}