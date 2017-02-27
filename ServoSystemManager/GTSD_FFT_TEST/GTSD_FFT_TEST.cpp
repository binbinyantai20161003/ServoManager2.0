// GTSD_FFT_TEST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "basetype_def.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "GTSD_FFT.h"


//---------------------------------------------------------------------------------------------------------
const	double			TS = 0.000125;       //仿真采样时间
const	double	 		TF = 20;			 //仿真结束时间

const	double	 		f_begin = 1.0;		 //开始频率
const	double	 		f_end = 2000.0;		 //结束频率
const	unsigned long	NUM_SP = TF / TS;    //点数
//---------------------------------------------------------------------------------------------------------
const	double			TF_LPF = 0.005;     //低通滤波时间常数 
const	double			KF_LPF = (TS / (TS + TF_LPF));	//低通滤波系数

double	FstLpf(double m_in);
double	SecondOrderNotchFilter(double u_s, double k1, double k2, double k3);


int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	double dtmp, dtmp2;

	double *u = new double[NUM_SP];
	double *xr = new double[NUM_SP];
	double *xr_out = new double[NUM_SP];

	double *dbb = new double[NUM_SP];
	double *phh = new double[NUM_SP];
	double			FRE_NF = 200.0;

	double			WC = 2.0*M_PI*FRE_NF;
	double			WN = (2.0 / TS)*tan((WC*TS) / 2);

	double			ZETA1 = 0.0;
	double			ZETA2 = 0.5;
	double			H_F = 2.0 / TS;

	double			B0_F = H_F*H_F + 2.0*ZETA2*WN*H_F + WN*WN;
	double			B1_F = 2.0*(H_F*H_F - WN*WN);
	double			B2_F = H_F*H_F - 2.0*ZETA2*WN*H_F + WN*WN;
	double			C0_F = 2.0*(ZETA2 - ZETA1)*WN*H_F;

	double			K1_F = B1_F / B0_F;
	double			K2_F = B2_F / B0_F;
	double			K3_F = C0_F / B0_F;
	//---------------------------------------------------------------------------------------------------------
	double			coef = 2 * M_PI;
	double			delt_fre = (f_end - f_begin) / NUM_SP;
	double			wm_begin = coef * 	f_begin;
	double			wm_step = coef *  delt_fre;
	double			wm = wm_begin;

	// test function execute time
	LARGE_INTEGER	m_timeStartClock;
	LARGE_INTEGER	m_timeFreq;
	LARGE_INTEGER	m_timeNowClock;
	double			m_fDelayTime;
	QueryPerformanceFrequency(&m_timeFreq);


	//FILE		*pPara, *pdpf;

	//int			wt_per, wt_per_lat;
	//wt_per = wt_per_lat = 0;

	//fopen_s(&pPara,".\\para.txt", "w+");
	//fopen_s(&pdpf,".\\dpf.txt", "w+");


	//for (int i = 0; i < NUM_SP; ++i)
	//{
	//	u[i] = cos(wm * TS * (double)(i));

	//	xr[i] = u[i];

	//	//	xr_out[i]	=	FstLpf(u[i]);
	//	xr_out[i] = SecondOrderNotchFilter(u[i], K1_F, K2_F, K3_F);

	//	wm = wm + wm_step;
	//}

	//printf("FFT for input & output data...");

	//QueryPerformanceCounter(&m_timeStartClock);

	//RespAnalysisInFreDomain(xr, xr_out, dbb, phh, NUM_SP);

	//QueryPerformanceCounter(&m_timeNowClock);
	//
	//m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
	//
	//printf("\nRespAnalysisInFreDomain time is %f",m_fDelayTime);


	//printf("\nwriting data to files...");
	//printf("\nwrite progress: ");

	//for (int i = 0; i < NUM_SP; i++)
	//{
	//	wt_per = (((i + 1)*100.0) / NUM_SP);

	//	fprintf(pdpf, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);

	//	if (wt_per != wt_per_lat)
	//	{
	//		printf("%3d%c\n", wt_per, '%');
	//	}

	//	wt_per_lat = wt_per;

	//}

	//fprintf(pPara, "%-12.6f \n", TS);


	//fclose(pPara);
	//fclose(pdpf);

//////////////////////////////////////////////////////////////////////////
	////以另一种方式测试是否正确,并对比时间
	//
	//COMPLEX *xrc		= new COMPLEX[NUM_SP];
	//COMPLEX *xrc_out	= new COMPLEX[NUM_SP];

	//fopen_s(&pdpf, ".\\dpf1.txt", "w+");
	//for (int i = 0; i < NUM_SP; ++i)
	//{
	//	xrc[i].real = u[i];

	//	//	xr_out[i]	=	FstLpf(u[i]);
	//	xrc_out[i].real = SecondOrderNotchFilter(xrc[i].real, K1_F, K2_F, K3_F);
	//}

	//QueryPerformanceCounter(&m_timeStartClock);

	//RespAnalysisInFreDomain_x(xrc, xrc_out, dbb, phh, NUM_SP);

	//QueryPerformanceCounter(&m_timeNowClock);

	//m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);

	//printf("\nRespAnalysisInFreDomain_x time is %f", m_fDelayTime);

	//printf("\nwriting data to files...");
	//printf("\nwrite progress: ");

	//for (int i = 0; i < NUM_SP; i++)
	//{
	//	wt_per = (((i + 1)*100.0) / NUM_SP);

	//	fprintf(pdpf, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);

	//	if (wt_per != wt_per_lat)
	//	{
	//		printf("%3d%c\n", wt_per, '%');
	//	}

	//	wt_per_lat = wt_per;

	//}

	//fclose(pdpf);
//////////////////////////////////////////////////////////////////////////
	////FFT测试，分别测试输入信号的FFT和经过低通滤波的FFT

	//FILE		*pFFTin, *pFFTlpfout;
	//fopen_s(&pFFTin, ".\\FFTin.txt", "w+");
	//fopen_s(&pFFTlpfout, ".\\FFTlpfout.txt", "w+");
	//printf("FFT for input...\n");

	//QueryPerformanceCounter(&m_timeStartClock);

	//SignalAnalysisFFT(xr, dbb, phh, NUM_SP);
	//
	//QueryPerformanceCounter(&m_timeNowClock);
	//m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
	//printf("SignalAnalysisFFT time is %f ...\n", m_fDelayTime);
	//
	//printf("FFT for input finish...\n");

	//for (int i = 0; i < NUM_SP; i++)
	//{
	//	fprintf(pFFTin, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);
	//}
	//printf("FFT for output...\n");

	//QueryPerformanceCounter(&m_timeStartClock);

	//SignalAnalysisFFT(xr_out, dbb, phh, NUM_SP);

	//QueryPerformanceCounter(&m_timeNowClock);
	//m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
	//printf("SignalAnalysisFFT time is %f ...\n", m_fDelayTime);

	//printf("FFT for output finish...\n");

	//for (int i = 0; i < NUM_SP; i++)
	//{
	//	fprintf(pFFTlpfout, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);
	//}

	//fclose(pFFTin);
	//fclose(pFFTlpfout);
//////////////////////////////////////////////////////////////////////////
	////用另一种方式测试输出，并对比时间
	//fopen_s(&pFFTin, ".\\FFTin1.txt", "w+");
	//fopen_s(&pFFTlpfout, ".\\FFTlpfout1.txt", "w+");
	//printf("FFT for input...\n");

	//QueryPerformanceCounter(&m_timeStartClock);

	//SignalAnalysisFFT_x(xrc, dbb, phh, NUM_SP);

	//QueryPerformanceCounter(&m_timeNowClock);
	//m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
	//printf("SignalAnalysisFFT_x time is %f ...\n", m_fDelayTime);

	//printf("FFT for input finish...\n");

	//for (int i = 0; i < NUM_SP; i++)
	//{
	//	fprintf(pFFTin, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);
	//}
	//printf("FFT for output...\n");

	//QueryPerformanceCounter(&m_timeStartClock);

	//SignalAnalysisFFT_x(xrc_out, dbb, phh, NUM_SP);

	//QueryPerformanceCounter(&m_timeNowClock);
	//m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
	//printf("SignalAnalysisFFT_x time is %f ...\n", m_fDelayTime);

	//printf("FFT for output finish...\n");

	//for (int i = 0; i < NUM_SP; i++)
	//{
	//	fprintf(pFFTlpfout, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);
	//}

	//fclose(pFFTin);
	//fclose(pFFTlpfout);

////////////////////////////////////////////////////////////////////////////
//	//测试正弦波的FFT
//	FILE		*pFFT100hz;
//	fopen_s(&pFFT100hz, ".\\FFT100hz.txt", "w+");
//	//100hz
//	for (int i = 0; i < NUM_SP; ++i)
//	{
//		u[i] = cos(coef * 100 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
//	}
//	printf("100hz cos FFT...\n");
//
//	QueryPerformanceCounter(&m_timeStartClock);
//
//	SignalAnalysisFFT(u, dbb, phh, NUM_SP);
//
//	QueryPerformanceCounter(&m_timeNowClock);
//	m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
//	printf("SignalAnalysisFFT 100hz time is %f ...\n", m_fDelayTime);
//
//	printf("100hz cos FFT finish...\n");
//
//	for (int i = 0; i < NUM_SP; i++)
//	{
//		fprintf(pFFT100hz, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);
//	}
//	fclose(pFFT100hz);
//
//
////////////////////////////////////////////////////////////////////////////
//	//另一种方式计算，并比较时间
//	FILE		*pFFT100hz1;
//	COMPLEX *uc = new COMPLEX[NUM_SP];
//
//
//	fopen_s(&pFFT100hz1, ".\\FFT100hz1.txt", "w+");
//	//100hz
//	for (int i = 0; i < NUM_SP; ++i)
//	{
//		u[i] = cos(coef * 100 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
//		uc[i].real = u[i];
//	}
//	printf("100hz cos FFT...\n");
//
//	QueryPerformanceCounter(&m_timeStartClock);
//
//	SignalAnalysisFFT_x(uc, dbb, phh, NUM_SP);
//
//	QueryPerformanceCounter(&m_timeNowClock);
//	m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
//	printf("SignalAnalysisFFT_x 100hz time is %f ...\n", m_fDelayTime);
//
//	printf("100hz cos FFT finish...\n");
//
//	for (int i = 0; i < NUM_SP; i++)
//	{
//		fprintf(pFFT100hz1, "%-8d %-12.6f %-12.6f\n", i, dbb[i], phh[i]);
//	}
//
//	fclose(pFFT100hz1);
////////////////////////////////////////////////////////////////////////////
//	//test SignalAnalysisGoertzel method
//	double f1, f2, Nf;
//	f1	= 1;
//	f2	= 200;
//	Nf	= 1800;
//	double *dbbNf = new double[Nf];
//	double *phhNf = new double[Nf];
//
//	FILE		*pFFT100and30hz;
//	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz.txt", "w+");
//	//100hz
//	for (int i = 0; i < NUM_SP; ++i)
//	{
//		u[i] = cos(coef * 100 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
//	}
//	printf("100hz and 30hz cos FFT...\n");
//
//	QueryPerformanceCounter(&m_timeStartClock);
//
//	SignalAnalysisGoertzel(f1, f2, NUM_SP, Nf, 1 / TS, u, dbbNf, phhNf,0);
//
//
//	QueryPerformanceCounter(&m_timeNowClock);
//	m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
//	printf("SignalAnalysisGoertzel 100hz and 30  time is %f \n", m_fDelayTime);
//
//	printf("100hz and 30hz  cos FFT finish...\n");
//
//	for (int i = 0; i < Nf; i++)
//	{
//		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbNf[i], phhNf[i]);
//	}
//	fclose(pFFT100and30hz);
//
//	delete[] dbbNf;
//	delete[] phhNf;
////////////////////////////////////////////////////////////////////////////
//	//use anothor mode to test SignalAnalysisGoertzel method 
//
//	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_1.txt", "w+");
//	//100hz
//	for (int i = 0; i < NUM_SP; ++i)
//	{
//		u[i] = cos(coef * 100 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
//	}
//	printf("100hz and 30hz cos FFT...\n");
//
//
//	Nf = (int32)(NUM_SP*TS*f2) - (int32)(NUM_SP*TS*f1)+1;
//
//	dbbNf = new double[Nf];
//	phhNf = new double[Nf];	
//	
//	QueryPerformanceCounter(&m_timeStartClock);
//
//	SignalAnalysisGoertzel(f1, f2, NUM_SP, Nf, 1 / TS, u, dbbNf, phhNf, 1);
//
//
//	QueryPerformanceCounter(&m_timeNowClock);
//	m_fDelayTime = (double)(m_timeNowClock.QuadPart - m_timeStartClock.QuadPart) * 1000 / (double)(m_timeFreq.QuadPart);
//	printf("SignalAnalysisGoertzel_1 100hz and 30hz  time is %f ...\n", m_fDelayTime);
//
//	printf("100hz and 30hz  cos FFT finish...\n");
//
//	for (int i = 0; i < Nf; i++)
//	{
//		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbNf[i], phhNf[i]);
//	}
//	fclose(pFFT100and30hz);
//	delete[] dbbNf;
//	delete[] phhNf;
////////////////////////////////////////////////////////////////////////////
//	//test sliding dft
//	const int32 LineNum			= 2;
//	int32 Nw[LineNum]			= { 16000, 32000 };
//	int32 Nspecial[LineNum]		= { 100, 200 };
//	double fstart[LineNum]		= { 1, 1 };
//	double fend[LineNum]		= { 100, 200 };
//	double stableValue[LineNum] = { 1, 1 };
//	int32  wintype[LineNum]		= { 0, 0 };
//	//fist open the dft 
//	OpenSlidingDft(LineNum, Nw, Nspecial);
//	//second set param
//	SetSlidingDftParam(LineNum, fstart, fend, Nw, Nspecial, 1 / TS, 0, stableValue,wintype);
//
//	//visual data 
//	
//	double** queue_in;
//	queue_in = new double*[LineNum];			/*window data space*/
//	for (int32 i = 0; i < LineNum; ++i)
//	{
//		queue_in[i] = new double[NUM_SP];
//	}
//
//	for (int i = 0; i < NUM_SP; ++i)
//	{
//		queue_in[0][i] = cos(coef * 70 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
//		queue_in[1][i] = cos(coef * 120 * TS * (double)(i)) + cos(coef * 150 * TS * (double)(i));
//	}
//	
//	//add data to queue
//	SdftAddData(LineNum, NUM_SP, &(queue_in[0]));
//
//	for (int32 i = 0; i < LineNum; ++i)
//	{
//		delete[] queue_in[i];
//		queue_in[i] = NULL;
//	}
//	delete[] queue_in;
//	queue_in = NULL;
//
//	//start analysis
//	double **dbbsdft = NULL;
//	double **phhsdft = NULL;
//	SignalAnalysisSlidingDft(LineNum, Nw, &dbbsdft, &phhsdft, Nspecial);
//	
//	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slid1.txt", "w+");
//	for (int i = 0; i < Nspecial[0]; i++)
//	{
//		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[0][i], phhsdft[0][i]);
//	}
//	fclose(pFFT100and30hz);
//
//	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slid2.txt", "w+");
//	for (int i = 0; i < Nspecial[1]; i++)
//	{
//		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[1][i], phhsdft[1][i]);
//	}
//	fclose(pFFT100and30hz);
//
//	CloseSlidingDft(LineNum);
//
////////////////////////////////////////////////////////////////////////////
//	//another mode to calc sdft
//	for (int32 i = 0; i < LineNum; ++i)
//	{
//		Nspecial[i] = (int32)(Nw[i] * TS*fend[i]) - (int32)(Nw[i] * TS*fstart[i]) + 1;
//	}
//	//fist open the dft 
//	OpenSlidingDft(LineNum, Nw, Nspecial);
//	//second set param
//	SetSlidingDftParam(LineNum, fstart, fend, Nw, Nspecial, 1 / TS, 1,stableValue,wintype);
//
//
//	//visual data 
//
//	queue_in = new double*[LineNum];			/*window data space*/
//	for (int32 i = 0; i < LineNum; ++i)
//	{
//		queue_in[i] = new double[NUM_SP];
//	}
//
//	for (int i = 0; i < NUM_SP; ++i)
//	{
//		queue_in[0][i] = cos(coef * 70 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
//		queue_in[1][i] = cos(coef * 120 * TS * (double)(i)) + cos(coef * 150 * TS * (double)(i));
//	}
//
//	//add data to queue
//	SdftAddData(LineNum, NUM_SP, &(queue_in[0]));
//
//	for (int32 i = 0; i < LineNum; ++i)
//	{
//		delete[] queue_in[i];
//		queue_in[i] = NULL;
//	}
//	delete[] queue_in;
//	queue_in = NULL;
//
//
//	dbbsdft = NULL;
//	phhsdft = NULL;
//	SignalAnalysisSlidingDft(LineNum, Nw, &dbbsdft, &phhsdft, Nspecial);
//
//	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slid1_1.txt", "w+");
//	for (int i = 0; i < Nspecial[0]; i++)
//	{
//		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[0][i], phhsdft[0][i]);
//	}
//	fclose(pFFT100and30hz);
//
//	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slid2_1.txt", "w+");
//	for (int i = 0; i < Nspecial[1]; i++)
//	{
//		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[1][i], phhsdft[1][i]);
//	}
//	fclose(pFFT100and30hz);
//
//	CloseSlidingDft(LineNum);
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
	//test sliding dft
	const int32 LineNum			= 2;
	int32 Nw[LineNum]			= { 16000, 32000 };
	int32 Nspecial[LineNum]		= { 100, 200 };
	double fstart[LineNum]		= { 1, 1 };
	double fend[LineNum]		= { 100, 200 };
	int32  wintype[LineNum]		= { 0, 0 };
	//fist open the dft 
	OpenSlidingGoertzel(LineNum, Nw, Nspecial);
	//second set param
	SetSlidingGoertzelParam(LineNum, fstart, fend, Nw, Nspecial, 1 / TS, 0,wintype);

	//visual data 
	
	double** queue_in;
	queue_in = new double*[LineNum];			/*window data space*/
	for (int32 i = 0; i < LineNum; ++i)
	{
		queue_in[i] = new double[NUM_SP];
	}

	for (int i = 0; i < NUM_SP; ++i)
	{
		queue_in[0][i] = cos(coef * 70 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
		queue_in[1][i] = cos(coef * 120 * TS * (double)(i)) + cos(coef * 150 * TS * (double)(i));
	}
	
	//add data to queue
	SlidingGoertzelAddData(LineNum, NUM_SP, &(queue_in[0]));

	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] queue_in[i];
		queue_in[i] = NULL;
	}
	delete[] queue_in;
	queue_in = NULL;

	//start analysis
	double **dbbsdft = NULL;
	double **phhsdft = NULL;
	SignalAnalysisSlidingGoertzelDft(LineNum, Nw, &dbbsdft, &phhsdft, Nspecial);
	FILE		*pFFT100and30hz;
	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slidg1.txt", "w+");
	for (int i = 0; i < Nspecial[0]; i++)
	{
		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[0][i], phhsdft[0][i]);
	}
	fclose(pFFT100and30hz);

	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slidg2.txt", "w+");
	for (int i = 0; i < Nspecial[1]; i++)
	{
		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[1][i], phhsdft[1][i]);
	}
	fclose(pFFT100and30hz);

	CloseSlidingGoertzel(LineNum);

//////////////////////////////////////////////////////////////////////////
	//another mode to calc sdft
	for (int32 i = 0; i < LineNum; ++i)
	{
		Nspecial[i] = (int32)(Nw[i] * TS*fend[i]) - (int32)(Nw[i] * TS*fstart[i]) + 1;
	}
	//fist open the dft 
	OpenSlidingGoertzel(LineNum, Nw, Nspecial);
	//second set param
	SetSlidingGoertzelParam(LineNum, fstart, fend, Nw, Nspecial, 1 / TS, 1,wintype);


	//visual data 

	queue_in = new double*[LineNum];			/*window data space*/
	for (int32 i = 0; i < LineNum; ++i)
	{
		queue_in[i] = new double[NUM_SP];
	}

	for (int i = 0; i < NUM_SP; ++i)
	{
		queue_in[0][i] = cos(coef * 70 * TS * (double)(i)) + cos(coef * 30 * TS * (double)(i));
		queue_in[1][i] = cos(coef * 120 * TS * (double)(i)) + cos(coef * 150 * TS * (double)(i));
	}

	//add data to queue
	SlidingGoertzelAddData(LineNum, NUM_SP, &(queue_in[0]));

	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] queue_in[i];
		queue_in[i] = NULL;
	}
	delete[] queue_in;
	queue_in = NULL;


	dbbsdft = NULL;
	phhsdft = NULL;
	SignalAnalysisSlidingGoertzelDft(LineNum, Nw, &dbbsdft, &phhsdft, Nspecial);

	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slidg1_1.txt", "w+");
	for (int i = 0; i < Nspecial[0]; i++)
	{
		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[0][i], phhsdft[0][i]);
	}
	fclose(pFFT100and30hz);

	fopen_s(&pFFT100and30hz, ".\\FFT100and30hz_slidg2_1.txt", "w+");
	for (int i = 0; i < Nspecial[1]; i++)
	{
		fprintf(pFFT100and30hz, "%-8d %-12.6f %-12.6f\n", i, dbbsdft[1][i], phhsdft[1][i]);
	}
	fclose(pFFT100and30hz);

	CloseSlidingGoertzel(LineNum);
////////////////////////////////////////////////////////////////////////



	delete[] u;

	delete[] xr;
	delete[] xr_out;

	delete[] dbb;
	delete[] phh;

	//delete[] uc;
	//delete[] xrc;
	//delete[] xrc_out;

	

	printf("\n");
	printf("simulation finished!\n");
	scanf_s("%c", &ch);
	return 0;
}

//*********************************************************************************************************
// low pass filter transform test
//*********************************************************************************************************
double	FstLpf(double m_in)
{
	static double xout;

	xout = xout + (m_in - xout) * KF_LPF;
	return	xout;
}

//*********************************************************************************************************
// low pass filter transform test
//*********************************************************************************************************
double	SecondOrderNotchFilter(double u_s, double k1, double k2, double k3)
{
	static	double	y_last1, y_last2;
	static	double	x_last1, x_last2;
	double	y, r_v;

	y = k1*(y_last1)-k2*(y_last2)+k3*(u_s - x_last2);
	y_last2 = y_last1;
	y_last1 = y;
	x_last2 = x_last1;
	x_last1 = u_s;
	r_v = u_s - y;
	return	 r_v;
}
