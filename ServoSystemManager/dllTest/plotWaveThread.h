#ifndef		_GTSD_PLOT_WAVE_TEST_THREAD_
#define		_GTSD_PLOT_WAVE_TEST_THREAD_

#include "./../ServoDriverManagerDll/Basetype_def.h"

void createPlotWaveTestThread(void);
unsigned __stdcall PlotWaveTestThread(void *para);


#define	LINE_NUMBER				8
#define TIME_SCALE				1
#define	MY_WAVE_MAX_LENTH		200000


extern WAVE_BUF_PRM waveA;
extern WAVE_BUF_PRM waveB;

extern double mylinearrayA[LINE_NUMBER][MY_WAVE_MAX_LENTH+1000];
extern double* mydataA;
extern int32  mynumberA;
extern int32 mylinearrarindexA;

extern double mylinearrayB[LINE_NUMBER][MY_WAVE_MAX_LENTH+1000];
extern double* mydataB;
extern int32  mynumberB;
extern int32 mylinearrarindexB;

#endif