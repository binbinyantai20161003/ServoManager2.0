// ServoDriverAlgorithmDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Basetype_def.h"
#include <math.h>
#include <stdlib.h>
#include "GTSD_FFT.h"
#include "ServoDriverAlgorithmDll.h"

//////////////////////////////////////////////////////////////////////////
//fft analysis
//////////////////////////////////////////////////////////////////////////

//*********************************************************************************************************
//*									Response analysis in frequency domain
//*
//* Description: Computes the frequency response from output to input.
//*              
//* Arguments  : r_in		input real data of system
//*				 r_out		output real data of system
//*				 dbb		amplitude frequency gain of system	
//*				 phh		phase frequency characteristic of system
//*
//* Returns    : 0(false), 1(true)/successful
//*********************************************************************************************************
SERVODRIVERALGORITHMDLL_API int	RespAnalysisInFreDomain(double * r_in, double * r_out, double * dbb, double * phh, unsigned int n)
{
	double *i_in, *i_out, *gin, *gout, *angin, *angout;

	double dtmp;

	i_in = (double *)(calloc(n, sizeof(double)));
	i_out = (double *)(calloc(n, sizeof(double)));
	gin = (double *)(calloc(n, sizeof(double)));
	gout = (double *)(calloc(n, sizeof(double)));
	angin = (double *)(calloc(n, sizeof(double)));
	angout = (double *)(calloc(n, sizeof(double)));

	for (int i = 0; i < n; i++)
	{
		i_in[i] = 0;
		i_out[i] = 0;
	}

	transform(r_in, i_in, n);
	transform(r_out, i_out, n);

	for (int i = 0; i < n; i++)
	{
		gin[i] = (sqrt(r_in[i] * r_in[i] + i_in[i] * i_in[i]) * 2.0) / n;
		gout[i] = (sqrt(r_out[i] * r_out[i] + i_out[i] * i_out[i]) * 2.0) / n;
		dbb[i] = 20 * log10(gout[i] / gin[i]);

		angin[i] = IFatanCal(i_in[i], r_in[i]);
		angout[i] = IFatanCal(i_out[i], r_out[i]);

		dtmp = angout[i] - angin[i];

		while ((dtmp < -M_PI) || (dtmp > M_PI))
		{
			if (dtmp > M_PI)
			{
				dtmp = dtmp - 2 * M_PI;
			}
			else
			{
				dtmp = dtmp + 2 * M_PI;
			}
		}

		phh[i] = dtmp;

	}

	free(i_in);
	free(i_out);
	free(gin);
	free(gout);
	free(angin);
	free(angout);

	return	1;
}

//*********************************************************************************************************
//*									signal analysis in frequency domain
//*
//* Description: Computes the fft for time domain  .
//*              
//* Arguments  : 
//*				 r_in		input real data of system
//*				 dbb		amplitude frequency gain of system	
//*				 phh		phase frequency characteristic of system hz
//*				 samplerate		sample rate
//*				 n			signal point number
//* Returns    : 0(false), 1(true)/successful
//*********************************************************************************************************
SERVODRIVERALGORITHMDLL_API int SignalAnalysisFFT(double * r_in, double * dbb, double * phh, unsigned int n)
{
	double *i_in, *gin, *angin;

	double dtmp;

	i_in = (double *)(calloc(n, sizeof(double))); //虚部
	gin = (double *)(calloc(n, sizeof(double))); //模
	angin = (double *)(calloc(n, sizeof(double)));//相位


	for (int i = 0; i < n; i++)
	{
		i_in[i] = 0;
	}

	transform(r_in, i_in, n);

	for (int i = 0; i < n; i++)
	{
		gin[i] = (sqrt(r_in[i] * r_in[i] + i_in[i] * i_in[i]) * 2.0) / n;
		dbb[i] = 20 * log10(gin[i]);

		angin[i] = IFatanCal(i_in[i], r_in[i]);

		dtmp = angin[i];

		while ((dtmp < -M_PI) || (dtmp > M_PI))
		{
			if (dtmp > M_PI)
			{
				dtmp = dtmp - 2 * M_PI;
			}
			else
			{
				dtmp = dtmp + 2 * M_PI;
			}
		}

		phh[i] = dtmp; //单位rad

	}

	free(i_in);
	free(gin);
	free(angin);

	return	1;
}

//*********************************************************************************************************
//*									Response analysis in frequency domain
//*
//* Description: Computes the frequency response from output to input.
//*              
//* Arguments  : in			input  data of system
//*				 out		output data of system
//*				 dbb		amplitude frequency gain of system	
//*				 phh		phase frequency characteristic of system
//*
//* Returns    : 0(false), 1(true)/successful
//*********************************************************************************************************
SERVODRIVERALGORITHMDLL_API int RespAnalysisInFreDomain_x(COMPLEX* input, COMPLEX* output, double * dbb, double * phh, unsigned int n)
{
	double  *gin, *gout, *angin, *angout;

	double dtmp;

	gin = (double *)(calloc(n, sizeof(double)));
	gout = (double *)(calloc(n, sizeof(double)));
	angin = (double *)(calloc(n, sizeof(double)));
	angout = (double *)(calloc(n, sizeof(double)));

	// calculate the fft
	transform2D(input, output, n);

	for (int i = 0; i < n; i++)
	{
		gin[i] = (sqrt(input[i].real * input[i].real + input[i].imag * input[i].imag) * 2.0) / n;
		gout[i] = (sqrt(output[i].real * output[i].real + output[i].imag * output[i].imag) * 2.0) / n;
		dbb[i] = 20 * log10(gout[i] / gin[i]);

		angin[i] = IFatanCal(input[i].imag, input[i].real);
		angout[i] = IFatanCal(output[i].imag, output[i].real);

		dtmp = angout[i] - angin[i];

		while ((dtmp < -M_PI) || (dtmp > M_PI))
		{
			if (dtmp > M_PI)
			{
				dtmp = dtmp - 2 * M_PI;
			}
			else
			{
				dtmp = dtmp + 2 * M_PI;
			}
		}

		phh[i] = dtmp;

	}
	free(gin);
	free(gout);
	free(angin);
	free(angout);

	return	1;
}

//*********************************************************************************************************
//*									signal analysis in frequency domain
//*
//* Description: Computes the fft for time domain  .
//*              
//* Arguments  : 
//*				 input		input real data of system
//*				 dbb		amplitude frequency gain of system	
//*				 phh		phase frequency characteristic of system hz
//*				 n			signal point number
//* Returns    : 0(false), 1(true)/successful
//*********************************************************************************************************
SERVODRIVERALGORITHMDLL_API int	SignalAnalysisFFT_x(COMPLEX* input, double * dbb, double * phh, unsigned int n)
{
	double *gin, *angin;

	double dtmp;

	gin = (double *)(calloc(n, sizeof(double))); //模
	angin = (double *)(calloc(n, sizeof(double)));//相位

	transform1(input, n);

	for (int i = 0; i < n; i++)
	{
		gin[i] = (sqrt((input[i].real * input[i].real) + (input[i].imag * input[i].imag)) * 2.0) / n;
		dbb[i] = 20 * log10(gin[i]);

		angin[i] = IFatanCal(input[i].imag, input[i].real);

		dtmp = angin[i];

		while ((dtmp < -M_PI) || (dtmp > M_PI))
		{
			if (dtmp > M_PI)
			{
				dtmp = dtmp - 2 * M_PI;
			}
			else
			{
				dtmp = dtmp + 2 * M_PI;
			}
		}

		phh[i] = dtmp; //单位rad

	}

	free(gin);
	free(angin);

	return	1;
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//Calculates the Fourier transform, by use of the Goertzel algorithm, over Nf points from frequency f1 to frequency f2,
//of N (N>1) samples of a signal.
// Nf = number of frequency  points to calculate FT
// N = number of samples 
// fs = sample rate
// dat_in = input data ,the number is N
// dbb phh = output data 
// mode = 0 : use f1,f2,Nf to calc the delta  . mode = 1:use f1,f2 to calc every point in the section,when mode == 1 you need to calc Nf when you call this function
SERVODRIVERALGORITHMDLL_API int SignalAnalysisGoertzel(double f1, double f2, int32 N, int32 Nf, double fs, double* dat_in, double * dbb, double * phh, int32 mode)
{
	// judge the input parameter
	if ((N < 2) || (Nf < 2))
	{
		// N must be greater than 1
		return -1;
	}
	if ((dat_in == NULL) || (dbb == NULL) || (phh == NULL))
	{
		//dat pointer must has value
		return -2;
	}
	if (f2 <= f1)
	{
		//f2 must be greater than f1
		return -3;
	}

	double df; /* frequency step size */
	df = (f2 - f1) / ((double)(Nf - 1));

	double dfmin;
	//dfmin = (fs / 2) / (N / 2);
	dfmin = (fs / N);

	//if the frequency section delta < dfmin
	if (df < dfmin)
	{
		return -4;
	}

	//calc  correspond N according the f
	int32 N1 = (int32)(N / fs*f1);
	int32 deltaN;
	if (mode == 0)
	{
		deltaN = (int32)((df / dfmin) + 0.5);
	}
	else if (mode == 1)
	{
		deltaN = 1;
	}
	else
	{
		deltaN = (int32)((df / dfmin) + 0.5);
	}

	//calculate the angle 
	double theta; /* theta = 2*Pi*f/fs */
	double dtheta; /* theta step size */
	theta = 2.0 * M_PI * N1 / N;
	dtheta = 2.0 * M_PI * deltaN / N;

	int32 i;
	double Qr, Qi; /* real & imaginary parts of FT */

	//calculate the magnitude and phase
	double gin, angin;
	double dtmp;

	for (i = 0; i < Nf; ++i)
	{
		goertzel(N, dat_in, theta, &Qr, &Qi);

		gin = (sqrt((Qr * Qr) + (Qi * Qi)) * 2.0) / N;
		dbb[i] = 20 * log10(gin);

		angin = IFatanCal(Qi, Qr);

		dtmp = angin;

		while ((dtmp < -M_PI) || (dtmp > M_PI))
		{
			if (dtmp > M_PI)
			{
				dtmp = dtmp - 2 * M_PI;
			}
			else
			{
				dtmp = dtmp + 2 * M_PI;
			}
		}

		phh[i] = dtmp; //单位rad
		theta += dtheta;
	} /* end for i */

	return 0;
}


//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//locat space for slding Dft
//LineNum = sliding dft curve allnumber 
//N = Window width
//Nf = frequency number need to be calc
//N and Nf are array for different Curve
//this function should be call when start sliding DFT.
SERVODRIVERALGORITHMDLL_API int OpenSlidingDft(int32 LineNum, int32* N, int32* Nf)
{
	//set ready flag to false
	SDFT_ReadFlag = false;

	if (LineNum < 1)
	{
		return -1;
	}
	if ((N == NULL) || (Nf == NULL))
	{
		return -2;
	}
	SDFT_df = new double[LineNum];			/* frequency step size */
	if (SDFT_df == NULL)
	{
		return -3;
	}
	SDFT_theta = new double[LineNum];			/* theta = 2*Pi*f/fs */
	if (SDFT_theta == NULL)
	{
		return -3;
	}
	SDFT_dtheta = new double[LineNum];			/* theta step size */
	if (SDFT_dtheta == NULL)
	{
		return -3;
	}
	SDFT_dfmin = new double[LineNum];			/* MIN	theta step size */
	if (SDFT_dfmin == NULL)
	{
		return -3;
	}
	SDFT_WindowData = new double*[LineNum];			/*window data space*/
	if (SDFT_WindowData == NULL)
	{
		return -3;
	}

	for (int32 i = 0; i < LineNum; ++i)
	{
		SDFT_WindowData[i] = new double[(N[i])];
		if (SDFT_WindowData[i] == NULL)
		{
			return -3;
		}
	}
	//clear window data buffer
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < N[j]; ++i)
		{
			SDFT_WindowData[j][i] = 0;
		}
	}

	SDFT_Sk = new COMPLEX*[LineNum];	if (SDFT_Sk == NULL){ return -3; }
	SDFT_Sk_1 = new COMPLEX*[LineNum];	if (SDFT_Sk_1 == NULL){ return -3; }
	SDFT_Sk_2 = new COMPLEX*[LineNum];	if (SDFT_Sk_2 == NULL){ return -3; }

	for (int32 i = 0; i < LineNum; ++i)
	{
		SDFT_Sk[i] = new COMPLEX[(Nf[i])];	if (SDFT_Sk[i] == NULL){ return -3; }
		SDFT_Sk_1[i] = new COMPLEX[(Nf[i])];	if (SDFT_Sk_1[i] == NULL){ return -3; }
		SDFT_Sk_2[i] = new COMPLEX[(Nf[i])]; if (SDFT_Sk_2[i] == NULL){ return -3; }
	}

	//clear Sk and Sk_1
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < Nf[j]; ++i)
		{
			SDFT_Sk[j][i].real = 0;
			SDFT_Sk[j][i].imag = 0;

			SDFT_Sk_1[j][i].real = 0;
			SDFT_Sk_1[j][i].imag = 0;

			SDFT_Sk_2[j][i].real = 0;
			SDFT_Sk_2[j][i].imag = 0;
		}
	}
	SDFT_stableSet = new double[LineNum];
	if (SDFT_stableSet == NULL)
	{
		return -3;
	}
	//input data queue space
	SDFT_InputData = new queue<double>[LineNum];
	if (SDFT_InputData == NULL)
	{
		return -3;
	}
	// when get data we need a tmp data space 
	SDFT_TmpData = new double*[LineNum];
	if (SDFT_TmpData == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SDFT_TmpData[i] = NULL;
	}

	InitializeCriticalSection(&SDFT_queue);


	SDFT_dbb_out = new double*[LineNum];
	if (SDFT_dbb_out == NULL)
	{
		return -3;
	}
	SDFT_phh_out = new double*[LineNum];
	if (SDFT_phh_out == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SDFT_dbb_out[i] = new double[Nf[i]];
		if (SDFT_dbb_out[i] == NULL)
		{
			return -3;
		}
		SDFT_phh_out[i] = new double[Nf[i]];
		if (SDFT_phh_out[i] == NULL)
		{
			return -3;
		}
	}

	SDFT_dbb_out_cpy = new double*[LineNum];
	if (SDFT_dbb_out_cpy == NULL)
	{
		return -3;
	}
	SDFT_phh_out_cpy = new double*[LineNum];
	if (SDFT_phh_out_cpy == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SDFT_dbb_out_cpy[i] = new double[Nf[i]];
		if (SDFT_dbb_out_cpy[i] == NULL)
		{
			return -3;
		}
		SDFT_phh_out_cpy[i] = new double[Nf[i]];
		if (SDFT_phh_out_cpy[i] == NULL)
		{
			return -3;
		}
	}

	SDFT_index = new Uint64[LineNum];
	if (SDFT_index == NULL)
	{
		return -3;
	}
	SDFT_ValidFlag = new bool[LineNum];
	if (SDFT_ValidFlag == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SDFT_index[i] = 0;
		SDFT_ValidFlag[i] = false;
	}

	// window type
	SDFT_WindowType = new int32[LineNum];		if (SDFT_WindowType == NULL){ return -3; }
	for (int32 i = 0; i < LineNum; ++i)
	{
		SDFT_WindowType[i] = 0;
	}

	//hannning window
	SDFT_HanningWk = new double[SDFT_HANNING_K_NUM];	if (SDFT_HanningWk == NULL){ return -3; }

	SDFT_HanningWk[0] = -1;//-0.25;
	SDFT_HanningWk[1] = 2;// 0.5;
	SDFT_HanningWk[2] = -1;// -0.25;



	return 0;
}
//clear all the located space
//LineNum = sliding dft curve allnumber 
SERVODRIVERALGORITHMDLL_API int CloseSlidingDft(int32 LineNum)
{
	delete[] SDFT_df;
	delete[] SDFT_theta;
	delete[] SDFT_dtheta;
	delete[] SDFT_dfmin;

	if (LineNum < 1)
	{
		return -1;
	}

	//clear window data buffer
	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] SDFT_WindowData[i];
		SDFT_WindowData[i] = NULL;
	}
	delete[] SDFT_WindowData;
	SDFT_WindowData = NULL;

	//clear tmp value
	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] SDFT_Sk[i];		SDFT_Sk[i] = NULL;
		delete[] SDFT_Sk_1[i];	SDFT_Sk_1[i] = NULL;
		delete[] SDFT_Sk_2[i];	SDFT_Sk_2[i] = NULL;
	}
	delete[] SDFT_Sk;	SDFT_Sk = NULL;
	delete[] SDFT_Sk_1;	SDFT_Sk_1 = NULL;
	delete[] SDFT_Sk_2;	SDFT_Sk_2 = NULL;
	//stable
	delete[] SDFT_stableSet;

	//input data queue 
	delete[] SDFT_InputData;
	SDFT_InputData = NULL;

	delete[] SDFT_TmpData;
	SDFT_TmpData = NULL;

	DeleteCriticalSection(&SDFT_queue);

	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] SDFT_dbb_out[i];
		SDFT_dbb_out[i] = NULL;
		delete[] SDFT_phh_out[i];
		SDFT_phh_out[i] = NULL;
		delete[] SDFT_dbb_out_cpy[i];
		SDFT_dbb_out_cpy[i] = NULL;
		delete[] SDFT_phh_out_cpy[i];
		SDFT_phh_out_cpy[i] = NULL;
	}
	delete[] SDFT_dbb_out;
	SDFT_dbb_out = NULL;
	delete[] SDFT_phh_out;
	SDFT_phh_out = NULL;
	delete[] SDFT_dbb_out_cpy;
	SDFT_dbb_out_cpy = NULL;
	delete[] SDFT_phh_out_cpy;
	SDFT_phh_out_cpy = NULL;

	delete[] SDFT_index;			SDFT_index = NULL;
	delete[] SDFT_ValidFlag;		SDFT_ValidFlag = NULL;

	delete[] SDFT_WindowType;			SDFT_WindowType = NULL;
	delete[] SDFT_HanningWk;				SDFT_HanningWk = NULL;

	//set ready flag to false
	SDFT_ReadFlag = false;

	return 0;
}
//////////////////////////////////////////////////////////////////////////
//LineNum = sliding dft curve number.   
//different curve can set different parameter,
//so you need call this func for set all curve  param after call OpenSlidingDft
// Nf = number of frequency  points to calculate sliding DFT
// N = number of samples point ,Nwindow sliding 
// fs = sample rate
// [f1,f2] is the frequency section 
// the PC need to save the array for f1,f2,N,Nf and so on
// pc also need a flag to start put data into the buffer
SERVODRIVERALGORITHMDLL_API int SetSlidingDftParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs, int32 mode, double* stable, int32* WinType)
{
	if (LineNum < 1)
	{
		return -1;
	}
	if ((f1 == NULL) || (f2 == NULL) || (N == NULL) || (Nf == NULL))
	{
		return -2;
	}


	for (int16 i = 0; i < LineNum; ++i)
	{
		// judge the input parameter
		if ((N[i] < 2) || (Nf[i] < 2))
		{
			// N must be greater than 1
			return -1;
		}

		if (f2[i] <= f1[i])
		{
			//f2 must be greater than f1
			return -3;
		}
		if (stable[i] > 1)
		{
			return -4;
		}
		//calculate the delta frequency
		SDFT_df[i] = (f2[i] - f1[i]) / ((double)(Nf[i] - 1));

		//dfmin = (fs / 2) / (N / 2);
		SDFT_dfmin[i] = (fs / N[i]);

		//if the frequency section delta < dfmin
		if (SDFT_df[i] < SDFT_dfmin[i])
		{
			return -5;
		}

		//calc  correspond N according the f
		int32 N1 = (int32)(N[i] / fs*f1[i]);
		int32 deltaN;
		if (mode == 0)
		{
			deltaN = (int32)((SDFT_df[i] / SDFT_dfmin[i]) + 0.5);
		}
		else if (mode == 1)
		{
			deltaN = 1;
		}
		else
		{
			deltaN = (int32)((SDFT_df[i] / SDFT_dfmin[i]) + 0.5);
		}

		//calculate the angle 
		SDFT_theta[i] = 2.0 * M_PI * N1 / N[i];
		SDFT_dtheta[i] = 2.0 * M_PI * deltaN / N[i];

		//set stable value
		SDFT_stableSet[i] = stable[i];
		SDFT_WindowType[i] = WinType[i];

	}
	//set ready flag to true
	SDFT_ReadFlag = true;

	return 0;
}
//add data to the queue
// LineNum = the 1D number
// Num = the 2D number
// dat = 2D array pointer
// the dat space is located by pc
SERVODRIVERALGORITHMDLL_API int SlidingDftAddData(int32 LineNum, int32 Num, double** dat)
{
	if (LineNum < 1)
	{
		return -1;
	}
	//add data to different line 
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < Num; ++i)
		{
			EnterCriticalSection(&SDFT_queue);
			SDFT_InputData[j].push(dat[j][i]);
			LeaveCriticalSection(&SDFT_queue);
		}
	}

	return 0;
}
// LineNum = curve number
// dbb phh = output data
// Nf = output freq number
// N = window width
SERVODRIVERALGORITHMDLL_API int SignalAnalysisSlidingDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf)
{
	if (LineNum < 1)
	{
		return -1;
	}
	//if ((dbb == NULL) || (phh == NULL))
	//{
	//	//dat pointer must has value
	//	return -2;
	//}
	if ((N == NULL) || (Nf == NULL))
	{
		return -3;
	}
	for (int16 i = 0; i < LineNum; ++i)
	{
		if ((Nf[i] < 2) || (N[i] < 2))
		{
			return -4;
		}
	}


	//get data from queue
	int32 Num;
	double** dat = NULL;
	SlidingDftGetData(LineNum, &Num, &dat);

	//calculate the magnitude and phase
	double gin;			/*output gain calc*/
	double angin;		/*output angle calc*/
	double dtmp;
	double Qr, Qi;		/* real & imaginary parts of FT */
	double thetaSt;		//start freq tmp var
	bool valid = false;
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 k = 0; k < Num; ++k)
		{
			thetaSt = SDFT_theta[j];
			//every dat need to cal Nf number
			for (int32 i = 0; i < Nf[j]; ++i)
			{
				//call one input sdft
				SlidingDft(j, i, N[j], &(dat[j][k]), thetaSt, &Qr, &Qi, &valid);

				if (valid == true)
				{
					gin = (sqrt((Qr * Qr) + (Qi * Qi)) * 2.0) / N[j];
					SDFT_dbb_out[j][i] = 20 * log10(gin);

					angin = IFatanCal(Qi, Qr);

					dtmp = angin;

					while ((dtmp < -M_PI) || (dtmp > M_PI))
					{
						if (dtmp > M_PI)
						{
							dtmp = dtmp - 2 * M_PI;
						}
						else
						{
							dtmp = dtmp + 2 * M_PI;
						}
					}

					SDFT_phh_out[j][i] = dtmp; //单位rad
				}

				thetaSt += SDFT_dtheta[j];
			}
			SDFT_index[j]++;
			if (SDFT_index[j] >= N[j])
			{
				SDFT_index[j] = 0;
				SDFT_ValidFlag[j] = true;
			}
		}
	}

	//delete tmp var
	for (int32 j = 0; j < LineNum; ++j)
	{
		delete[] SDFT_TmpData[j];
		SDFT_TmpData[j] = NULL;
	}


	//copy times
	SDFT_Times++;

	if ((SDFT_Times >= SDFT_OUTPUT_COPY_TIMES) && (valid == true))
	{
		SDFT_Times = 0;
		for (int32 j = 0; j < LineNum; ++j)
		{
			memcpy_s(SDFT_dbb_out_cpy[j], Nf[j] * sizeof(double), SDFT_dbb_out[j], Nf[j] * sizeof(double));
			memcpy_s(SDFT_phh_out_cpy[j], Nf[j] * sizeof(double), SDFT_phh_out[j], Nf[j] * sizeof(double));
		}
	}
	//output
	*dbb = SDFT_dbb_out_cpy;
	*phh = SDFT_phh_out_cpy;

	return 0;
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//locat space for slding Goertzel Dft
//LineNum = sliding Goertzel dft curve allnumber 
//N = Window width
//Nf = frequency number need to be calc
//N and Nf are array for different Curve
//this function should be call when start sliding Goertzel DFT.
SERVODRIVERALGORITHMDLL_API int OpenSlidingGoertzel(int32 LineNum, int32* N, int32* Nf)
{
	//set ready flag to false
	SGDFT_ReadFlag = false;

	if (LineNum < 1)
	{
		return -1;
	}
	if ((N == NULL) || (Nf == NULL))
	{
		return -2;
	}
	SGDFT_df = new double[LineNum];			/* frequency step size */
	if (SGDFT_df == NULL)
	{
		return -3;
	}
	SGDFT_theta = new double[LineNum];			/* theta = 2*Pi*f/fs */
	if (SGDFT_theta == NULL)
	{
		return -3;
	}
	SGDFT_dtheta = new double[LineNum];			/* theta step size */
	if (SGDFT_dtheta == NULL)
	{
		return -3;
	}
	SGDFT_dfmin = new double[LineNum];			/* MIN	theta step size */
	if (SGDFT_dfmin == NULL)
	{
		return -3;
	}
	SGDFT_WindowData = new double*[LineNum];			/*window data space*/
	if (SGDFT_WindowData == NULL)
	{
		return -3;
	}

	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_WindowData[i] = new double[(N[i])];
		if (SGDFT_WindowData[i] == NULL)
		{
			return -3;
		}
	}
	//clear window data buffer
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < N[j]; ++i)
		{
			SGDFT_WindowData[j][i] = 0;
		}
	}

	SGDFT_Sk = new COMPLEX*[LineNum];	if (SGDFT_Sk == NULL){ return -3; }
	SGDFT_Sk_1 = new COMPLEX*[LineNum];	if (SGDFT_Sk_1 == NULL){ return -3; }
	SGDFT_Sk_2 = new COMPLEX*[LineNum];	if (SGDFT_Sk_2 == NULL){ return -3; }

	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_Sk[i] = new COMPLEX[(Nf[i])];	if (SGDFT_Sk[i] == NULL){ return -3; }
		SGDFT_Sk_1[i] = new COMPLEX[(Nf[i])];	if (SGDFT_Sk_1[i] == NULL){ return -3; }
		SGDFT_Sk_2[i] = new COMPLEX[(Nf[i])]; if (SGDFT_Sk_2[i] == NULL){ return -3; }
	}

	//clear Sk and Sk_1
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < Nf[j]; ++i)
		{
			SGDFT_Sk[j][i].real = 0;
			SGDFT_Sk[j][i].imag = 0;

			SGDFT_Sk_1[j][i].real = 0;
			SGDFT_Sk_1[j][i].imag = 0;

			SGDFT_Sk_2[j][i].real = 0;
			SGDFT_Sk_2[j][i].imag = 0;
		}
	}


	SGDFT_Vk = new double*[LineNum];	if (SGDFT_Vk == NULL){ return -3; }
	SGDFT_Vk_1 = new double*[LineNum];	if (SGDFT_Vk_1 == NULL){ return -3; }
	SGDFT_Vk_2 = new double*[LineNum];	if (SGDFT_Vk_2 == NULL){ return -3; }

	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_Vk[i] = new double[(Nf[i])];	if (SGDFT_Vk[i] == NULL){ return -3; }
		SGDFT_Vk_1[i] = new double[(Nf[i])];	if (SGDFT_Vk_1[i] == NULL){ return -3; }
		SGDFT_Vk_2[i] = new double[(Nf[i])]; if (SGDFT_Vk_2[i] == NULL){ return -3; }
	}

	//clear Sk and Sk_1
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < Nf[j]; ++i)
		{
			SGDFT_Vk[j][i] = 0;
			SGDFT_Vk[j][i] = 0;

			SGDFT_Vk_1[j][i] = 0;
			SGDFT_Vk_1[j][i] = 0;

			SGDFT_Vk_2[j][i] = 0;
			SGDFT_Vk_2[j][i] = 0;
		}
	}

	//input data queue space
	SGDFT_InputData = new queue<double>[LineNum];
	if (SGDFT_InputData == NULL)
	{
		return -3;
	}
	// when get data we need a tmp data space 
	SGDFT_TmpData = new double*[LineNum];
	if (SGDFT_TmpData == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_TmpData[i] = NULL;
	}

	InitializeCriticalSection(&SGDFT_queue);


	SGDFT_dbb_out = new double*[LineNum];
	if (SGDFT_dbb_out == NULL)
	{
		return -3;
	}
	SGDFT_phh_out = new double*[LineNum];
	if (SGDFT_phh_out == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_dbb_out[i] = new double[Nf[i]];
		if (SGDFT_dbb_out[i] == NULL)
		{
			return -3;
		}
		SGDFT_phh_out[i] = new double[Nf[i]];
		if (SGDFT_phh_out[i] == NULL)
		{
			return -3;
		}
	}

	SGDFT_dbb_out_cpy = new double*[LineNum];
	if (SGDFT_dbb_out_cpy == NULL)
	{
		return -3;
	}
	SGDFT_phh_out_cpy = new double*[LineNum];
	if (SGDFT_phh_out_cpy == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_dbb_out_cpy[i] = new double[Nf[i]];
		if (SGDFT_dbb_out_cpy[i] == NULL)
		{
			return -3;
		}
		SGDFT_phh_out_cpy[i] = new double[Nf[i]];
		if (SGDFT_phh_out_cpy[i] == NULL)
		{
			return -3;
		}
	}

	SGDFT_index = new Uint64[LineNum];
	if (SGDFT_index == NULL)
	{
		return -3;
	}
	SGDFT_ValidFlag = new bool[LineNum];
	if (SGDFT_ValidFlag == NULL)
	{
		return -3;
	}
	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_index[i] = 0;
		SGDFT_ValidFlag[i] = false;
	}

	// window type
	SGDFT_WindowType = new int32[LineNum];		if (SGDFT_WindowType == NULL){ return -3; }
	for (int32 i = 0; i < LineNum; ++i)
	{
		SGDFT_WindowType[i] = 0;
	}

	//hannning window
	SGDFT_HanningWk = new double[SGDFT_HANNING_K_NUM];	if (SGDFT_HanningWk == NULL){ return -3; }

	SGDFT_HanningWk[0] = -1;//-0.25;
	SGDFT_HanningWk[1] = 2;// 0.5;
	SGDFT_HanningWk[2] = -1;// -0.25;



	return 0;
}
//clear all the located space
//LineNum = sliding dft curve allnumber 
SERVODRIVERALGORITHMDLL_API int CloseSlidingGoertzel(int32 LineNum)
{
	delete[] SGDFT_df;
	delete[] SGDFT_theta;
	delete[] SGDFT_dtheta;
	delete[] SGDFT_dfmin;

	if (LineNum < 1)
	{
		return -1;
	}

	//clear window data buffer
	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] SGDFT_WindowData[i];
		SGDFT_WindowData[i] = NULL;
	}
	delete[] SGDFT_WindowData;
	SGDFT_WindowData = NULL;

	//clear tmp value
	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] SGDFT_Sk[i];		SGDFT_Sk[i] = NULL;
		delete[] SGDFT_Sk_1[i];	SGDFT_Sk_1[i] = NULL;
		delete[] SGDFT_Sk_2[i];	SGDFT_Sk_2[i] = NULL;
	}
	delete[] SGDFT_Sk;	SGDFT_Sk = NULL;
	delete[] SGDFT_Sk_1;	SGDFT_Sk_1 = NULL;
	delete[] SGDFT_Sk_2;	SGDFT_Sk_2 = NULL;

	//clear tmp value
	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] SGDFT_Vk[i];		SGDFT_Vk[i] = NULL;
		delete[] SGDFT_Vk_1[i];	SGDFT_Vk_1[i] = NULL;
		delete[] SGDFT_Vk_2[i];	SGDFT_Vk_2[i] = NULL;
	}
	delete[] SGDFT_Vk;	SGDFT_Vk = NULL;
	delete[] SGDFT_Vk_1;	SGDFT_Vk_1 = NULL;
	delete[] SGDFT_Vk_2;	SGDFT_Vk_2 = NULL;

	//input data queue 
	delete[] SGDFT_InputData;
	SGDFT_InputData = NULL;

	delete[] SGDFT_TmpData;
	SGDFT_TmpData = NULL;

	DeleteCriticalSection(&SGDFT_queue);

	for (int32 i = 0; i < LineNum; ++i)
	{
		delete[] SGDFT_dbb_out[i];
		SGDFT_dbb_out[i] = NULL;
		delete[] SGDFT_phh_out[i];
		SGDFT_phh_out[i] = NULL;
		delete[] SGDFT_dbb_out_cpy[i];
		SGDFT_dbb_out_cpy[i] = NULL;
		delete[] SGDFT_phh_out_cpy[i];
		SGDFT_phh_out_cpy[i] = NULL;
	}
	delete[] SGDFT_dbb_out;
	SGDFT_dbb_out = NULL;
	delete[] SGDFT_phh_out;
	SGDFT_phh_out = NULL;
	delete[] SGDFT_dbb_out_cpy;
	SGDFT_dbb_out_cpy = NULL;
	delete[] SGDFT_phh_out_cpy;
	SGDFT_phh_out_cpy = NULL;

	delete[] SGDFT_index;			SGDFT_index = NULL;
	delete[] SGDFT_ValidFlag;		SGDFT_ValidFlag = NULL;

	delete[] SGDFT_WindowType;			SGDFT_WindowType = NULL;
	delete[] SGDFT_HanningWk;				SGDFT_HanningWk = NULL;

	//set ready flag to false
	SGDFT_ReadFlag = false;

	return 0;
}
//////////////////////////////////////////////////////////////////////////
//LineNum = sliding dft curve number.   
//different curve can set different parameter,
//so you need call this func for set all curve  param after call OpenSlidingDft
// Nf = number of frequency  points to calculate sliding DFT
// N = number of samples point ,Nwindow sliding 
// fs = sample rate
// [f1,f2] is the frequency section 
// the PC need to save the array for f1,f2,N,Nf and so on
// pc also need a flag to start put data into the buffer
SERVODRIVERALGORITHMDLL_API int SetSlidingGoertzelParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs, int32 mode, int32* WinType)
{
	if (LineNum < 1)
	{
		return -1;
	}
	if ((f1 == NULL) || (f2 == NULL) || (N == NULL) || (Nf == NULL))
	{
		return -2;
	}


	for (int16 i = 0; i < LineNum; ++i)
	{
		// judge the input parameter
		if ((N[i] < 2) || (Nf[i] < 2))
		{
			// N must be greater than 1
			return -1;
		}

		if (f2[i] <= f1[i])
		{
			//f2 must be greater than f1
			return -3;
		}

		//calculate the delta frequency
		SGDFT_df[i] = (f2[i] - f1[i]) / ((double)(Nf[i] - 1));

		//dfmin = (fs / 2) / (N / 2);
		SGDFT_dfmin[i] = (fs / N[i]);

		//if the frequency section delta < dfmin
		if (SGDFT_df[i] < SGDFT_dfmin[i])
		{
			return -5;
		}

		//calc  correspond N according the f
		int32 N1 = (int32)(N[i] / fs*f1[i]);
		int32 deltaN;
		if (mode == 0)
		{
			deltaN = (int32)((SGDFT_df[i] / SGDFT_dfmin[i]) + 0.5);
		}
		else if (mode == 1)
		{
			deltaN = 1;
		}
		else
		{
			deltaN = (int32)((SGDFT_df[i] / SGDFT_dfmin[i]) + 0.5);
		}

		//calculate the angle 
		SGDFT_theta[i] = 2.0 * M_PI * N1 / N[i];
		SGDFT_dtheta[i] = 2.0 * M_PI * deltaN / N[i];

		//set stable value
		//SGDFT_stableSet[i] = stable[i];
		SGDFT_WindowType[i] = WinType[i];

	}
	//set ready flag to true
	SGDFT_ReadFlag = true;

	return 0;
}
//add data to the queue
// LineNum = the 1D number
// Num = the 2D number
// dat = 2D array pointer
// the dat space is located by pc
SERVODRIVERALGORITHMDLL_API int SlidingGoertzelAddData(int32 LineNum, int32 Num, double** dat)
{
	if (LineNum < 1)
	{
		return -1;
	}
	//add data to different line 
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < Num; ++i)
		{
			EnterCriticalSection(&SGDFT_queue);
			SGDFT_InputData[j].push(dat[j][i]);
			LeaveCriticalSection(&SGDFT_queue);
		}
	}

	return 0;
}
// LineNum = curve number
// dbb phh = output data
// Nf = output freq number
// N = window width
SERVODRIVERALGORITHMDLL_API int SignalAnalysisSlidingGoertzelDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf)
{
	if (LineNum < 1)
	{
		return -1;
	}
	//if ((dbb == NULL) || (phh == NULL))
	//{
	//	//dat pointer must has value
	//	return -2;
	//}
	if ((N == NULL) || (Nf == NULL))
	{
		return -3;
	}
	for (int16 i = 0; i < LineNum; ++i)
	{
		if ((Nf[i] < 2) || (N[i] < 2))
		{
			return -4;
		}
	}


	//get data from queue
	int32 Num;
	double** dat = NULL;
	SlidingGoertzelGetData(LineNum, &Num, &dat);

	//calculate the magnitude and phase
	double gin;			/*output gain calc*/
	double angin;		/*output angle calc*/
	double dtmp;
	double Qr, Qi;		/* real & imaginary parts of FT */
	double thetaSt;		//start freq tmp var
	bool valid = false;
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 k = 0; k < Num; ++k)
		{
			thetaSt = SGDFT_theta[j];
			//every dat need to cal Nf number
			for (int32 i = 0; i < Nf[j]; ++i)
			{
				//call one input sdft
				SlidingGoertzel(j, i, N[j], &(dat[j][k]), thetaSt, &Qr, &Qi, &valid);

				if (valid == true)
				{
					gin = (sqrt((Qr * Qr) + (Qi * Qi)) * 2.0) / N[j];
					SGDFT_dbb_out[j][i] = 20 * log10(gin);

					angin = IFatanCal(Qi, Qr);

					dtmp = angin;

					while ((dtmp < -M_PI) || (dtmp > M_PI))
					{
						if (dtmp > M_PI)
						{
							dtmp = dtmp - 2 * M_PI;
						}
						else
						{
							dtmp = dtmp + 2 * M_PI;
						}
					}

					SGDFT_phh_out[j][i] = dtmp; //单位rad
				}

				thetaSt += SGDFT_dtheta[j];
			}
			SGDFT_index[j]++;
			if (SGDFT_index[j] >= N[j])
			{
				SGDFT_index[j] = 0;
				SGDFT_ValidFlag[j] = true;
			}
		}
	}

	//delete tmp var
	for (int32 j = 0; j < LineNum; ++j)
	{
		delete[] SGDFT_TmpData[j];
		SGDFT_TmpData[j] = NULL;
	}


	//copy times
	SGDFT_Times++;

	if ((SGDFT_Times >= SGDFT_OUTPUT_COPY_TIMES) && (valid == true))
	{
		SGDFT_Times = 0;
		for (int32 j = 0; j < LineNum; ++j)
		{
			memcpy_s(SGDFT_dbb_out_cpy[j], Nf[j] * sizeof(double), SGDFT_dbb_out[j], Nf[j] * sizeof(double));
			memcpy_s(SGDFT_phh_out_cpy[j], Nf[j] * sizeof(double), SGDFT_phh_out[j], Nf[j] * sizeof(double));
		}
	}
	//output
	*dbb = SGDFT_dbb_out_cpy;
	*phh = SGDFT_phh_out_cpy;

	return 0;
}

