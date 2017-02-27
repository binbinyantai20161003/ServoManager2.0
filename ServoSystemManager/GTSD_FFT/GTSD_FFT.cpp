// GTSD_FFT.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "basetype_def.h"
#include "GTSD_FFT.h"
#include <queue>
using namespace std;

// Private function prototypes
static int32	reverse_bits(int32 x, Uint32 n);
static void		*memdup(void *src, size_t n);
static double	IFatanCal(double xq, double xd);
static int32	reverse_bits1(int32 x, Uint32 levels);

#define			SIZE_MAX	((size_t)-1)

//*********************************************************************************************************
//*											FFT TRANSFORM MODULE
//*
//* Description: Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
//*				 The vector can have any length. This is a wrapper function.
//*              
//* Arguments  : real		is a array to storage real part of data
//*				 imag		is a array to storage imag part of data
//*				 n			length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform(double real[], double imag[], size_t n)
{
	if (n == 0)
		return 1;
	else if ((n & (n - 1)) == 0)															// Is power of 2
		return transform_radix2(real, imag, n);
	else																					// More complicated algorithm for aribtrary sizes
		return transform_bluestein(real, imag, n);
}

//*********************************************************************************************************
//*											INVERSE  DFT MODULE
//*
//* Description: Computes the inverse discrete Fourier transform (IDFT) of the given complex vector, storing the result back into the vector.
//*				 The vector can have any length. This is a wrapper function. This transform does not perform scaling,
//*				 so the inverse is not a true inverse.
//*              
//* Arguments  : real		is a array to storage real part of data
//*				 imag		is a array to storage imag part of data
//*				 n			length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int inverse_transform(double real[], double imag[], size_t n)
{
	return transform(imag, real, n);
}

//*********************************************************************************************************
//*                                  Cooley-Tukey decimation-in-time algorithm
//*
//* Description: Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
//*				 The vector's length must be a power of 2. Uses the Cooley-Tukey decimation-in-time radix-2 algorithm.
//*              
//* Arguments  : real		is a array to storage real part of data
//*				 imag		is a array to storage imag part of data
//*				 n			length of array
//*
//* Returns    : 0(false)/ otherwise (n is not a power of 2, or out of memory), 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform_radix2(double real[], double imag[], size_t n)
{
	// Variables
	unsigned int	levels;
	double			*cos_table, *sin_table;
	size_t			size;
	size_t			i;

	size_t temp = n;
	levels = 0;
	while (temp > 1)
	{
		levels++;
		temp >>= 1;
	}
	if (1 << levels != n)
		return 0;																			// n is not a power of 2
	// Trignometric tables
	if (SIZE_MAX / sizeof(double) < n / 2)
		return 0;
	size = (n / 2) * sizeof(double);
	cos_table = (double *)(malloc(size));

	if (cos_table == NULL)
		return 0;

	sin_table = (double *)(malloc(size));
	if (sin_table == NULL)
	{
		free(cos_table);
		return 0;
	}
	for (i = 0; i < n / 2; i++)
	{
		cos_table[i] = cos(2 * M_PI * i / n);
		sin_table[i] = sin(2 * M_PI * i / n);
	}

	// Bit-reversed addressing permutation
	for (i = 0; i < n; i++)
	{
		size_t j = reverse_bits(i, levels);
		if (j > i)
		{
			double temp = real[i];
			real[i] = real[j];
			real[j] = temp;
			temp = imag[i];
			imag[i] = imag[j];
			imag[j] = temp;
		}
	}

	// Cooley-Tukey decimation-in-time radix-2 FFT
	for (size = 2; size <= n; size *= 2)
	{
		size_t halfsize = size / 2;
		size_t tablestep = n / size;
		for (i = 0; i < n; i += size)
		{
			size_t j;
			size_t k;
			for (j = i, k = 0; j < i + halfsize; j++, k += tablestep)
			{
				double tpre = real[j + halfsize] * cos_table[k] + imag[j + halfsize] * sin_table[k];
				double tpim = -real[j + halfsize] * sin_table[k] + imag[j + halfsize] * cos_table[k];
				real[j + halfsize] = real[j] - tpre;
				imag[j + halfsize] = imag[j] - tpim;
				real[j] += tpre;
				imag[j] += tpim;
			}
		}
		if (size == n)																		// Prevent overflow in 'size *= 2'
			break;
	}
	free(cos_table);
	free(sin_table);
	return 1;
}

//*********************************************************************************************************
//*									Bluestein's chirp z-transform algorithm 
//*
//* Description: Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
//*				 The vector can have any length. This requires the convolution function, which in turn requires the radix-2 FFT function.
//*              
//* Arguments  : real		is a array to storage real part of data
//*				 imag		is a array to storage imag part of data
//*				 n			length of array
//*
//* Returns    : 0(false)/ otherwise (out of memory), 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform_bluestein(double real[], double imag[], size_t n)
{
	// Variables
	int status = 0;
	double *cos_table, *sin_table;
	double *areal, *aimag;
	double *breal, *bimag;
	double *creal, *cimag;
	size_t m;
	size_t size_n, size_m;
	size_t i;

	// Find a power-of-2 convolution length m such that m >= n * 2 + 1
	size_t target;
	if (n > (SIZE_MAX - 1) / 2)
		return 0;
	target = n * 2 + 1;
	for (m = 1; m < target; m *= 2)
	{
		if (SIZE_MAX / 2 < m)
			return 0;
	}
	// Allocate memory
	if (SIZE_MAX / sizeof(double) < n || SIZE_MAX / sizeof(double) < m)
		return 0;
	size_n = n * sizeof(double);
	size_m = m * sizeof(double);
	cos_table = (double *)(malloc(size_n));         if (cos_table == NULL) goto cleanup0;
	sin_table = (double *)(malloc(size_n));         if (sin_table == NULL) goto cleanup1;
	areal = (double *)(calloc(m, sizeof(double)));  if (areal == NULL) goto cleanup2;
	aimag = (double *)(calloc(m, sizeof(double)));  if (aimag == NULL) goto cleanup3;
	breal = (double *)(calloc(m, sizeof(double)));  if (breal == NULL) goto cleanup4;
	bimag = (double *)(calloc(m, sizeof(double)));  if (bimag == NULL) goto cleanup5;
	creal = (double *)(malloc(size_m));             if (creal == NULL) goto cleanup6;
	cimag = (double *)(malloc(size_m));             if (cimag == NULL) goto cleanup7;

	// Trignometric tables
	for (i = 0; i < n; i++)
	{
		double temp = M_PI * (size_t)((unsigned long long)i * i % ((unsigned long long)n * 2)) / n;
		// Less accurate version if long long is unavailable: double temp = M_PI * i * i / n;
		cos_table[i] = cos(temp);
		sin_table[i] = sin(temp);
	}

	// Temporary vectors and preprocessing
	for (i = 0; i < n; i++)
	{
		areal[i] = real[i] * cos_table[i] + imag[i] * sin_table[i];
		aimag[i] = -real[i] * sin_table[i] + imag[i] * cos_table[i];
	}
	breal[0] = cos_table[0];
	bimag[0] = sin_table[0];
	for (i = 1; i < n; i++)
	{
		breal[i] = breal[m - i] = cos_table[i];
		bimag[i] = bimag[m - i] = sin_table[i];
	}

	// Convolution
	status = convolve_complex(areal, aimag, breal, bimag, creal, cimag, m);

	// Postprocessing
	for (i = 0; i < n; i++)
	{
		real[i] = creal[i] * cos_table[i] + cimag[i] * sin_table[i];
		imag[i] = -creal[i] * sin_table[i] + cimag[i] * cos_table[i];
	}

	// Clean-up
	free(cimag);
cleanup7:
	free(creal);
cleanup6:
	free(bimag);
cleanup5:
	free(breal);
cleanup4:
	free(aimag);
cleanup3:
	free(areal);
cleanup2:
	free(sin_table);
cleanup1:
	free(cos_table);
cleanup0:
	return status;
}

//*********************************************************************************************************
//*											circular convolution	
//*
//* Description: Computes the circular convolution of the given real vectors. Each vector's length must be the same.
//*              
//* Arguments  : x			data x vector input for real convolution computes
//*				 y			data y vector input for real convolution computes
//*				 n			length of array
//*
//* Returns    : 0(false)/ otherwise (out of memory), 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int convolve_real(double x[], double y[], double out[], size_t n)
{
	double *ximag, *yimag, *zimag;
	int status = 0;
	ximag = (double *)(calloc(n, sizeof(double)));  if (ximag == NULL) goto cleanup0;
	yimag = (double *)(calloc(n, sizeof(double)));  if (yimag == NULL) goto cleanup1;
	zimag = (double *)(calloc(n, sizeof(double)));  if (zimag == NULL) goto cleanup2;

	status = convolve_complex(x, ximag, y, yimag, out, zimag, n);
	free(zimag);
cleanup2:
	free(yimag);
cleanup1:
	free(ximag);
cleanup0:
	return status;
}

//*********************************************************************************************************
//*											circular convolution	
//*
//* Description: Computes the circular convolution of the given complex vectors. Each vector's length must be the same.
//*              
//* Arguments  : xreal			real data x vector input for complex convolution computes
//*				 ximag			imag data x vector input for complex convolution computes
//*				 yreal			real data y vector input for complex convolution computes
//*				 yimag			imag data y vector input for complex convolution computes
//*				 n				length of array
//*
//* Returns    : 0(false)/ otherwise (out of memory), 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int convolve_complex(double xreal[], double ximag[], double yreal[], double yimag[], double outreal[], double outimag[], size_t n)
{
	int status = 0;
	size_t size;
	size_t i;
	if (SIZE_MAX / sizeof(double) < n)
		return 0;
	size = n * sizeof(double);
	xreal = (double *)(memdup(xreal, size));  if (xreal == NULL) goto cleanup0;
	ximag = (double *)(memdup(ximag, size));  if (ximag == NULL) goto cleanup1;
	yreal = (double *)(memdup(yreal, size));  if (yreal == NULL) goto cleanup2;
	yimag = (double *)(memdup(yimag, size));  if (yimag == NULL) goto cleanup3;

	if (!transform(xreal, ximag, n))
		goto cleanup4;
	if (!transform(yreal, yimag, n))
		goto cleanup4;
	for (i = 0; i < n; i++)
	{
		double temp = xreal[i] * yreal[i] - ximag[i] * yimag[i];
		ximag[i] = ximag[i] * yreal[i] + xreal[i] * yimag[i];
		xreal[i] = temp;
	}
	if (!inverse_transform(xreal, ximag, n))
		goto cleanup4;
	for (i = 0; i < n; i++)
	{																							// Scaling (because this FFT implementation omits it)
		outreal[i] = xreal[i] / n;
		outimag[i] = ximag[i] / n;
	}
	status = 1;

cleanup4:
	free(yimag);
cleanup3:
	free(yreal);
cleanup2:
	free(ximag);
cleanup1:
	free(xreal);
cleanup0:
	return status;
}

/************************************************************************/
/* 循环level次，一个个取出最低位，然后左移                              */
/************************************************************************/
static int32 reverse_bits(int32 x, Uint32 n)
{
	size_t result = 0;
	unsigned int i;
	for (i = 0; i < n; i++, x >>= 1)
		result = (result << 1) | (x & 1);
	return result;
}
/************************************************************************/
/* for example 001----100 反转位数，    循环change次。 较小一倍 ，交换对应位上的值                                                               */
/************************************************************************/
static int32 reverse_bits1(int32 x, Uint32 levels)
{
	int32	result = 0;
	Uint32	i, j;
	//交换的次数，根据阶数来确定，levels = 2--交换1次（10）， levels = 3交换一次（001-100），levels = 4交换两次（0001--1000），levels = 5也是交换两次
	//从上述规律可以得到如下交换次数
	Uint32  change = 0;
	change = levels >> 1;
	//假如为奇数时保持中间的值
	Uint32  mid = 0;

	for (i = 0; i < change; i++)
	{
		//假如level是奇数，取中间不需要交换的值
		if (levels % 2 != 0)
		{
			mid = (1 << (levels >> 1))&x;
		}
		else
		{
			mid = 0;
		}
		j = levels - 1 - i;
		result |= (mid | ((x&(1 << j)) >> j) | ((x & 1) << j));
	}
	return result;
}

static void *memdup(void *src, size_t n)
{
	void *dest = malloc(n);
	if (dest != NULL)
		memcpy(dest, src, n);
	return dest;
}

//********************************************************************************
//	Function:		IFatanCal
//	Description:	calculate the phase of synthetic vector
//	input:			xd/value of d axis, xq/value of q axis					
//	output:			none
//	return:			phase between 0 to 2pi(0----2pi)

//	Author:			liu.g
//	date:			2014/03/19
//********************************************************************************
static double	IFatanCal(double xq, double xd)
{
	double	phs_temp, abs_xq, abs_xd;
	double	dtmp;

	if (xd != 0.0)
	{
		abs_xq = abs(xq);
		abs_xd = abs(xd);

		dtmp = abs_xq / abs_xd;
		phs_temp = atan(dtmp);

		if (xd < 0.0)
		{
			phs_temp = M_PI - phs_temp;
		}
	}
	else
	{
		phs_temp = M_PI / 2.0;
	}

	if (xq < 0.0)
	{
		phs_temp = M_PI*2.0 - phs_temp;
	}

	return	phs_temp;

}


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
GTSD_FFT_API int	RespAnalysisInFreDomain(double * r_in, double * r_out, double * dbb, double * phh, unsigned int n)
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
GTSD_FFT_API int SignalAnalysisFFT(double * r_in, double * dbb, double * phh, unsigned int n)
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


//////////////////////////////////////////////////////////////////////////
// complex input type 
//////////////////////////////////////////////////////////////////////////
//*********************************************************************************************************
//*											FFT TRANSFORM MODULE
//*
//* Description: Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
//*				 The vector can have any length. This is a wrapper function.
//*              
//* Arguments  : x			is a array to storage data
//*				 n			length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform_x(COMPLEX* x ,size_t n)
{
	if (n == 0)
		return 1;
	else if ((n & (n - 1)) == 0)															// Is power of 2
		return transform_radix2_x(x, n);
	else																					// More complicated algorithm for aribtrary sizes
		return transform_bluestein_x(x, n);
}

//*********************************************************************************************************
//*											INVERSE  DFT MODULE
//*
//* Description: Computes the inverse discrete Fourier transform (IDFT) of the given complex vector, storing the result back into the vector.
//*				 The vector can have any length. This is a wrapper function. This transform does not perform scaling,
//*				 so the inverse is not a true inverse.
//*              
//* Arguments  : x			is a array to storage data
//*				 n			length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int inverse_transform_x(COMPLEX* x, size_t n)
{
	double tmp;
	int32 i;
	int32 rtn;
	// exchange the real part and imag part
	for (i = 0; i < n;++i)
	{
		tmp			= x[i].real;
		x[i].real	= x[i].imag;
		x[i].imag	= tmp;
	}
	//do the dft
	rtn =  transform_x(x, n);

	// exchange the real part and imag part
	for (i = 0; i < n; ++i)
	{
		tmp = x[i].real;
		x[i].real = x[i].imag;
		x[i].imag = tmp;
	}

	return rtn;
	
}

//*********************************************************************************************************
//*                                  Cooley-Tukey decimation-in-time algorithm
//*
//* Description: Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
//*				 The vector's length must be a power of 2. Uses the Cooley-Tukey decimation-in-time radix-2 algorithm.
//*              
//* Arguments  : x			is a array to storage  data
//*				 n			length of array
//*
//* Returns    : 0(false)/ otherwise (n is not a power of 2, or out of memory), 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform_radix2_x(COMPLEX* x, size_t n)
{
	// Variables
	unsigned int	levels;
	double			*cos_table, *sin_table;
	size_t			size;
	size_t			i;

	size_t temp = n;
	levels = 0;
	while (temp > 1)
	{
		levels++;
		temp >>= 1;
	}
	if (1 << levels != n)
		return 0;																			// n is not a power of 2
	// Trignometric tables
	if (SIZE_MAX / sizeof(double) < n / 2)
		return 0;
	size = (n / 2) * sizeof(double);
	cos_table = (double *)(malloc(size));

	if (cos_table == NULL)
		return 0;

	sin_table = (double *)(malloc(size));
	if (sin_table == NULL)
	{
		free(cos_table);
		return 0;
	}
	for (i = 0; i < n / 2; i++)
	{
		cos_table[i] = cos(2 * M_PI * i / n);
		sin_table[i] = sin(2 * M_PI * i / n);
	}

	// Bit-reversed addressing permutation
	for (i = 0; i < n; i++)
	{
		size_t j = reverse_bits(i, levels);
		if (j > i)
		{
			double temp = x[i].real;
			x[i].real	= x[j].real;
			x[j].real	= temp;
			temp		= x[i].imag;
			x[i].imag	= x[j].imag;
			x[j].imag	= temp;
		}
	}

	// Cooley-Tukey decimation-in-time radix-2 FFT
	for (size = 2; size <= n; size *= 2)
	{
		size_t halfsize = size / 2;
		size_t tablestep = n / size;
		for (i = 0; i < n; i += size)
		{
			size_t j;
			size_t k;
			for (j = i, k = 0; j < i + halfsize; j++, k += tablestep)
			{
				double tpre = x[j + halfsize].real * cos_table[k] + x[j + halfsize].imag * sin_table[k];
				double tpim = -x[j + halfsize].real * sin_table[k] + x[j + halfsize].imag * cos_table[k];
				x[j + halfsize].real = x[j].real - tpre;
				x[j + halfsize].imag = x[j].imag - tpim;
				x[j].real += tpre;
				x[j].imag += tpim;
			}
		}
		if (size == n)																		// Prevent overflow in 'size *= 2'
			break;
	}
	free(cos_table);
	free(sin_table);
	return 1;
}

//*********************************************************************************************************
//*									Bluestein's chirp z-transform algorithm 
//*
//* Description: Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
//*				 The vector can have any length. This requires the convolution function, which in turn requires the radix-2 FFT function.
//*              
//* Arguments  : x			is a array to storage data
//*				 n			length of array
//*
//* Returns    : 0(false)/ otherwise (out of memory), 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform_bluestein_x(COMPLEX* x, size_t n)
{
	// Variables
	int status = 0;
	double *cos_table, *sin_table;
	double *areal, *aimag;
	double *breal, *bimag;
	double *creal, *cimag;
	size_t m;
	size_t size_n, size_m;
	size_t i;

	// Find a power-of-2 convolution length m such that m >= n * 2 + 1
	size_t target;
	if (n > (SIZE_MAX - 1) / 2)
		return 0;
	target = n * 2 + 1;
	for (m = 1; m < target; m *= 2)
	{
		if (SIZE_MAX / 2 < m)
			return 0;
	}
	// Allocate memory
	if (SIZE_MAX / sizeof(double) < n || SIZE_MAX / sizeof(double) < m)
		return 0;
	size_n = n * sizeof(double);
	size_m = m * sizeof(double);
	cos_table = (double *)(malloc(size_n));         if (cos_table == NULL) goto cleanup0;
	sin_table = (double *)(malloc(size_n));         if (sin_table == NULL) goto cleanup1;
	areal = (double *)(calloc(m, sizeof(double)));  if (areal == NULL) goto cleanup2;
	aimag = (double *)(calloc(m, sizeof(double)));  if (aimag == NULL) goto cleanup3;
	breal = (double *)(calloc(m, sizeof(double)));  if (breal == NULL) goto cleanup4;
	bimag = (double *)(calloc(m, sizeof(double)));  if (bimag == NULL) goto cleanup5;
	creal = (double *)(malloc(size_m));             if (creal == NULL) goto cleanup6;
	cimag = (double *)(malloc(size_m));             if (cimag == NULL) goto cleanup7;

	// Trignometric tables
	for (i = 0; i < n; i++)
	{
		double temp = M_PI * (size_t)((unsigned long long)i * i % ((unsigned long long)n * 2)) / n;
		// Less accurate version if long long is unavailable: double temp = M_PI * i * i / n;
		cos_table[i] = cos(temp);
		sin_table[i] = sin(temp);
	}

	// Temporary vectors and preprocessing
	for (i = 0; i < n; i++)
	{
		areal[i] = x[i].real * cos_table[i] + x[i].imag * sin_table[i];
		aimag[i] = -x[i].real * sin_table[i] + x[i].imag * cos_table[i];
	}
	breal[0] = cos_table[0];
	bimag[0] = sin_table[0];
	for (i = 1; i < n; i++)
	{
		breal[i] = breal[m - i] = cos_table[i];
		bimag[i] = bimag[m - i] = sin_table[i];
	}

	// Convolution
	status = convolve_complex(areal, aimag, breal, bimag, creal, cimag, m);

	// Postprocessing
	for (i = 0; i < n; i++)
	{
		x[i].real = creal[i] * cos_table[i] + cimag[i] * sin_table[i];
		x[i].imag = -creal[i] * sin_table[i] + cimag[i] * cos_table[i];
	}

	// Clean-up
	free(cimag);
cleanup7:
	free(creal);
cleanup6:
	free(bimag);
cleanup5:
	free(breal);
cleanup4:
	free(aimag);
cleanup3:
	free(areal);
cleanup2:
	free(sin_table);
cleanup1:
	free(cos_table);
cleanup0:
	return status;
}

//*********************************************************************************************************
//*											FFT 2D TRANSFORM MODULE
//*
//* Description: Computes the discrete Fourier transform (DFT) of the two n number given complex vector, 
//*				 but just compute one n number FFT and some addtion option, and storing the result back into the two vectors.
//*				 this function just used for real input.
//*				 The vector can have any length. This is a wrapper function.
//*              
//* Arguments  : X1		is a array to storage first real part of data
//*				 X2		is a array to storage second real part of data
//*				 N		length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform2D(COMPLEX* X1, COMPLEX* X2, size_t N)
{
	int32 i;

	//define n lenth space for fft input and result
	COMPLEX* X = new COMPLEX[N];
	
	/* Forward DFT */
	/* From the two N-point real sequences, x1(n) and x2(n), form the N-point complex
	sequence, x(n) = x1(n) + jx2(n) */
	for (i = 0; i < N; ++i)
	{
		X[i].real = X1[i].real;
		X[i].imag = X2[i].real;
	}
	/* Compute the DFT of x(n), X(k) = DFT{x(n)} */
	int32 rtn = transform_x(X, N);
	if (rtn == 0)
	{
		// return 1 success
		return 0;
	}
	/* The split function performs the additional computations required to get X1(k) and X2(k) from X(k). */
	int32 k;
	X1[0].real = X[0].real;
	X1[0].imag = 0;
	X2[0].real = X[0].imag;
	X2[0].imag = 0;
	X1[N / 2].real = X[N / 2].real;
	X1[N / 2].imag = 0;
	X2[N / 2].real = X[N / 2].imag;
	X2[N / 2].imag = 0;
	for (k = 1; k < N / 2; k++)
	{
		X1[k].real = (X[k].real + X[N-k].real) / 2;
		X1[k].imag = (X[k].imag - X[N-k].imag) / 2;
		X2[k].real = (X[k].imag + X[N-k].imag) / 2;
		X2[k].imag = (X[N-k].real - X[k].real) / 2;
		X1[N-k].real = X1[k].real;
		X1[N-k].imag = -(X1[k].imag);
		X2[N-k].real = X2[k].real;
		X2[(N-k)].imag = -(X2[k].imag);
	}

	delete[] X;
	return 1;
}
//*********************************************************************************************************
//*											inverse FFT 2D TRANSFORM MODULE
//*
//* Description: Computes the discrete Fourier transform (IDFT) of the two n number given complex vector, 
//*				 but just compute one n number FFT and some addtion option, and storing the result back into the two vectors.
//*				 this function just used for real input.
//*				 The vector can have any length. This is a wrapper function.
//*              
//* Arguments  : X1		is a array to storage first fft data
//*				 X2		is a array to storage second fft data
//*				 N		length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int inverse_transform2D(COMPLEX* X1, COMPLEX* X2, size_t N)
{
	int32 k;
	//use complex to store the fft result
	COMPLEX* x = new COMPLEX[N];
	if (x == NULL)
	{
		return 0;
	}
	/* Inverse DFT – We now want to get back x1(n) and x2(n) from X1(k) and X2(k) using
	one complex DFT */
	/* Recall that x(n) = x1(n) + jx2(n). Since the DFT operator is linear,
	X(k) = X1(k) + jX2(k). Thus we can express X(k) in terms of X1(k) and X2(k). */
	for (k = 0; k < N; k++)
	{
		x[k].real = X1[k].real - X2[k].imag;
		x[k].imag = X1[k].imag + X2[k].real;
	}

	inverse_transform_x(x, N);

	/* x1(n) is the real part of x(n), and x2(n) is the imaginary part of x(n). */
	for (k = 0; k < N; k++)
	{
		X1[k].real = x[k].real;
		X2[k].real = x[k].imag;
	}

	delete[] x;
	return 1;
}


//*********************************************************************************************************
//*											FFT 2n TRANSFORM MODULE
//*
//* Description: Computes the discrete Fourier transform (DFT) of the N = 2n number given complex vector, 
//*				 but just compute once n number FFT and some addtion, and storing the result back into the vector.
//*				 this function just used for real input and N must be even.
//*				 This is a wrapper function.
//*              
//* Arguments  : X		is a array to storage real part of data
//*				 N		length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int transform1(COMPLEX* X, size_t N)
{
	//if ((N % 2) != 0)
	//{
	//	//return 0;
	//}
	int32 DFT_N = N / 2; // dft number
	int32 n, k;
	COMPLEX* x = new COMPLEX[DFT_N]; /* array of complex DFT data */
	COMPLEX* A = new COMPLEX[DFT_N]; /* array of complex A coefficients */
	COMPLEX* B = new COMPLEX[DFT_N]; /* array of complex B coefficients */

	for (k = 0; k < DFT_N; k++)
	{
		A[k].real = 0.5*(1.0 - sin(2 * M_PI / (double)(N)*(double)k));
		A[k].imag = 0.5*(-cos(2 * M_PI / (double)(N)*(double)k));
		B[k].real = 0.5*(1.0 + sin(2 * M_PI / (double)(N)*(double)k));
		B[k].imag = 0.5*(cos(2 * M_PI / (double)(N)*(double)k));
	}

	/* Forward DFT */
	/* From the 2N point real sequence, X(n), for the N-point complex sequence, x(n) */
	for (n = 0; n < DFT_N; n++)
	{		
		x[n].real = X[2 * n].real; /* x1(n) = X(2n) */
		x[n].imag = X[(2 * n) + 1].real; /* x2(n) = X(2n + 1) */
	}
	/* Compute the DFT of x(n), X(k) = DFT{x(n)} */
	int32 rtn = transform_x(x, DFT_N);
	if (rtn == 0)
	{
		// return 1 success
		return 0;
	}

	for (k = 0; k < DFT_N; k++)
	{
		X[k].real = (x[k].real * A[k].real) - (x[k].imag * A[k].imag) +(x[DFT_N - k].real * B[k].real) + (x[DFT_N - k].imag * B[k].imag);
		X[k].imag = (x[k].imag * A[k].real) + (x[k].real * A[k].imag) + (x[DFT_N - k].real * B[k].imag) - (x[DFT_N - k].imag * B[k].real);
	}

	/* Use complex conjugate symmetry properties to get the rest of G(k) */
	X[DFT_N].real = (x[0].real - x[0].imag);
	X[DFT_N].imag = 0;

	for (k = 1; k < DFT_N; k++)
	{
		X[(2 * DFT_N) -k].real = X[k].real;
		X[(2 * DFT_N) -k].imag = (-X[k].imag);
	}

	delete[] x;
	delete[] A;
	delete[] B;

	return 1;
}
//*********************************************************************************************************
//*											Inverse FFT 2n TRANSFORM MODULE
//*
//* Description: Computes the discrete Fourier transform (IDFT) of the N = 2n number given complex vector, 
//*				 but just compute one n number IFFT and some addtion, and storing the result back into the vector.
//*				 this function just used for real input and N must be even.
//*				 This is a wrapper function.
//*              
//* Arguments  : X		is a array to storage real part of data
//*				 N		length of array
//*
//* Returns    : 0(false)/out of memory, 1(true)/successful
//*********************************************************************************************************
GTSD_FFT_API int inverse_transform1(COMPLEX* X, size_t N)
{
	//if ((N % 2) != 0)
	//{
	//	//return 0;
	//}
	int32 DFT_N = N / 2; // dft number
	int32 i, k;
	COMPLEX* x = new COMPLEX[DFT_N]; /* array of complex DFT data */
	COMPLEX* A = new COMPLEX[DFT_N]; /* array of complex A coefficients */
	COMPLEX* B = new COMPLEX[DFT_N]; /* array of complex B coefficients */
	COMPLEX* IA = new COMPLEX[DFT_N]; /* array of complex A* coefficients */
	COMPLEX* IB = new COMPLEX[DFT_N]; /* array of complex B* coefficients */

	for (k = 0; k < DFT_N; k++)
	{
		A[k].real = 0.5*(1.0 - sin(2 * M_PI / (double)(N)*(double)k));
		A[k].imag = 0.5*(-cos(2 * M_PI / (double)(N)*(double)k));
		B[k].real = 0.5*(1.0 + sin(2 * M_PI / (double)(N)*(double)k));
		B[k].imag = 0.5*(cos(2 * M_PI / (double)(N)*(double)k));
		IA[k].imag = -A[k].imag;
		IA[k].real = A[k].real;
		IB[k].imag = -B[k].imag;
		IB[k].real = B[k].real;
	}
	/* The split function performs the additional computations required to get
	x(k) from X(k). */
	for (k = 0; k < DFT_N; k++)
	{
		x[k].real = X[k].real * A[k].real - X[k].imag * A[k].imag +
			X[DFT_N - k].real * B[k].real + X[DFT_N - k].imag * B[k].imag;
		x[k].imag = X[k].imag * A[k].real + X[k].real * A[k].imag +
			X[DFT_N - k].real * B[k].imag - X[DFT_N - k].imag * B[k].real;
	}

	
	/* Compute the inverse DFT of x(n), X(k) = IDFT{x(n)} */
	int32 rtn = inverse_transform_x(x, DFT_N);
	if (rtn == 0)
	{
		// return 1 success
		return 0;
	}

	for (i = 0; i < DFT_N; ++i)
	{
		X[2*i].real		= x[i].real;
		X[2*i+1].real	= x[i].imag;
	}
	delete[] x;
	delete[] A;
	delete[] B;
	delete[] IA;
	delete[] IB;

	return 1;
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
GTSD_FFT_API int RespAnalysisInFreDomain_x(COMPLEX* input,COMPLEX* output, double * dbb, double * phh, unsigned int n)
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
GTSD_FFT_API int	SignalAnalysisFFT_x(COMPLEX* input, double * dbb, double * phh, unsigned int n)
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
//Goertzel algorithm
//N = sample number
// theta = 2*pi*k/N = 2*pi *(special frequency)/samplerate
GTSD_FFT_API int goertzel(int32 N, double *input, double theta, double *Qr, double *Qi)
{
	int n;
	double u0, u1, u2; /* variable of the difference eq: u(k) = f(k) + 2cos(theta)u(k-1) - u(k-2) */
	double C0, S0; /* cos(theta) & sin(theta) */
	double C02; /* 2*cos(theta) */
	double yr, yi; /* real and imaginary parts of yN */

	C0 = cos(theta);
	C02 = 2.0*C0;
	S0 = sin(theta);
	u0 = 0.0;
	u1 = 0.0;

	for (n = 0; n < N; ++n)
	{
		u2 = input[n] + C02*u1 - u0;
		u0 = u1;
		u1 = u2;
	} /* end for n */

	/* Calculate yN = yr + iyi */
	yr = u2 - C0*u0;
	yi = S0*u0;

	*Qr = yr;
	*Qi = yi;
	return 0;
} /* end function goertzel */

//////////////////////////////////////////////////////////////////////////
//Calculates the Fourier transform, by use of the Goertzel algorithm, over Nf points from frequency f1 to frequency f2,
//of N (N>1) samples of a signal.
// Nf = number of frequency  points to calculate FT
// N = number of samples 
// fs = sample rate
// dat_in = input data ,the number is N
// dbb phh = output data 
// mode = 0 : use f1,f2,Nf to calc the delta  . mode = 1:use f1,f2 to calc every point in the section,when mode == 1 you need to calc Nf when you call this function
GTSD_FFT_API int SignalAnalysisGoertzel(double f1, double f2, int32 N, int32 Nf, double fs, double* dat_in, double * dbb, double * phh,int32 mode)
{
	// judge the input parameter
	if ((N<2)||(Nf<2))
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
	if (df<dfmin)
	{
		return -4;
	}

	//calc  correspond N according the f
	int32 N1 = (int32)(N/fs*f1);
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

double*					SDFT_df;			/* frequency step size */
double*					SDFT_theta;			/* theta = 2*Pi*f/fs */
double*					SDFT_dtheta;		/* theta step size */
double*					SDFT_dfmin;			/* the min delta of the */
double*					SDFT_N1;
COMPLEX**				SDFT_Sk;			/*output*/
COMPLEX**				SDFT_Sk_1;			/*last output*/
COMPLEX**				SDFT_Sk_2;			/*last last output*/
double*					SDFT_stableSet;		/*stable value 1,临界稳定，接近1，可以调整极点到单位圆内*/
double**				SDFT_WindowData;	/*window data pointer*/
bool					SDFT_ReadFlag = false;
queue<double>*			SDFT_InputData;		/*input data queue*/
double**				SDFT_TmpData;		/*tmp data*/
//定义关键区，用于在不同的线程中都去操作数据个数
CRITICAL_SECTION		SDFT_queue;
double**				SDFT_dbb_out;
double**				SDFT_phh_out;
double**				SDFT_dbb_out_cpy;
double**				SDFT_phh_out_cpy;

int32					SDFT_Times = 0;
#define					SDFT_OUTPUT_COPY_TIMES  1
Uint64*					SDFT_index;
bool*					SDFT_ValidFlag;

//Hanning window
#define					SDFT_HANNING_K_NUM	3
double*					SDFT_HanningWk; 
int32*					SDFT_WindowType; //0:不加窗。1：hanning窗

//////////////////////////////////////////////////////////////////////////
//locat space for slding Dft
//LineNum = sliding dft curve allnumber 
//N = Window width
//Nf = frequency number need to be calc
//N and Nf are array for different Curve
//this function should be call when start sliding DFT.
GTSD_FFT_API int OpenSlidingDft(int32 LineNum, int32* N, int32* Nf)
{
	//set ready flag to false
	SDFT_ReadFlag = false;

	if (LineNum <1)
	{
		return -1;
	}
	if ((N == NULL) || (Nf == NULL))
	{
		return -2;
	}
	SDFT_df			= new double[LineNum];			/* frequency step size */
	if (SDFT_df == NULL)
	{
		return -3;
	}
	SDFT_theta		= new double[LineNum];			/* theta = 2*Pi*f/fs */
	if (SDFT_theta == NULL)
	{
		return -3;
	}
	SDFT_dtheta		= new double[LineNum];			/* theta step size */
	if (SDFT_dtheta == NULL)
	{
		return -3;
	}
	SDFT_dfmin		= new double[LineNum];			/* MIN	theta step size */
	if (SDFT_dfmin == NULL)
	{
		return -3;
	}
	SDFT_WindowData	= new double*[LineNum];			/*window data space*/
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
	for (int32 j = 0; j < LineNum;++j)
	{
		for (int32 i = 0; i < N[j]; ++i)
		{
			SDFT_WindowData[j][i] = 0;
		}
	}
	
	SDFT_Sk		= new COMPLEX*[LineNum];	if (SDFT_Sk	 == NULL){return -3;}
	SDFT_Sk_1	= new COMPLEX*[LineNum];	if (SDFT_Sk_1 == NULL){return -3;}
	SDFT_Sk_2	= new COMPLEX*[LineNum];	if (SDFT_Sk_2 == NULL){return -3;}

	for (int32 i = 0; i < LineNum;++i)
	{
		SDFT_Sk[i]	= new COMPLEX[(Nf[i])];	if (SDFT_Sk[i]	== NULL){return -3;}
		SDFT_Sk_1[i] = new COMPLEX[(Nf[i])];	if (SDFT_Sk_1[i] == NULL){return -3;}
		SDFT_Sk_2[i] = new COMPLEX[(Nf[i])]; if (SDFT_Sk_2[i] == NULL){return -3;}
	}

	//clear Sk and Sk_1
	for (int32 j = 0; j < LineNum; ++j)
	{
		for (int32 i = 0; i < Nf[j]; ++i)
		{
			SDFT_Sk[j][i].real	= 0;
			SDFT_Sk[j][i].imag	= 0;

			SDFT_Sk_1[j][i].real	= 0;
			SDFT_Sk_1[j][i].imag	= 0;

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

	SDFT_index		= new Uint64[LineNum];
	if (SDFT_index == NULL)
	{
		return -3;
	}
	SDFT_ValidFlag	= new bool[LineNum];
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
	SDFT_HanningWk = new double[SDFT_HANNING_K_NUM];	if (SDFT_HanningWk == NULL){return -3;}

	SDFT_HanningWk[0] = -1;//-0.25;
	SDFT_HanningWk[1] = 2;// 0.5;
	SDFT_HanningWk[2] = -1;// -0.25;

	
	
	return 0;
}
//clear all the located space
//LineNum = sliding dft curve allnumber 
GTSD_FFT_API int CloseSlidingDft(int32 LineNum)
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
	delete[] SDFT_Sk;	SDFT_Sk		= NULL;
	delete[] SDFT_Sk_1;	SDFT_Sk_1	= NULL;
	delete[] SDFT_Sk_2;	SDFT_Sk_2	= NULL;
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

	delete[] SDFT_index;			SDFT_index		= NULL;
	delete[] SDFT_ValidFlag;		SDFT_ValidFlag	= NULL;

	delete[] SDFT_WindowType;			SDFT_WindowType		= NULL;
	delete[] SDFT_HanningWk;				SDFT_HanningWk		= NULL;

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
GTSD_FFT_API int SetSlidingDftParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs,int32 mode, double* stable, int32* WinType)
{
	if (LineNum < 1)
	{
		return -1;
	}
	if ((f1 == NULL)||(f2==NULL)||(N == NULL)||(Nf == NULL))
	{
		return -2;
	}


	for (int16 i = 0; i < LineNum;++i)
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
		if (stable[i]>1)
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
		SDFT_theta[i]		= 2.0 * M_PI * N1 / N[i];
		SDFT_dtheta[i]		= 2.0 * M_PI * deltaN / N[i];

		//set stable value
		SDFT_stableSet[i]	= stable[i];
		SDFT_WindowType[i]	= WinType[i];

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
GTSD_FFT_API int SlidingDftAddData(int32 LineNum, int32 Num, double** dat)
{
	if (LineNum < 1)
	{
		return -1;
	}
	//add data to different line 
	for (int32 j = 0; j < LineNum;++j)
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
//get data from the queue
// LineNum = the 1D number
// Num = the 2D number
// dat = 3D array pointer
GTSD_FFT_API int SlidingDftGetData(int32 LineNum, int32* Num, double*** dat)
{
	if (LineNum < 1)
	{
		return -1;
	}
	int32 tmp;
	
	//if the size of the queue is zero ,then return zero number
	EnterCriticalSection(&SDFT_queue);
	tmp = SDFT_InputData[0].size();
	LeaveCriticalSection(&SDFT_queue);
	if (tmp == 0)
	{
		*Num = tmp;
		*dat = SDFT_TmpData;
		return 0;
	}

	// read size and locate space for different curve
	for (int32 j = 0; j < LineNum; ++j)
	{
		//locate space
		SDFT_TmpData[j]	= new double[tmp];

		//pop the value
		for (int32 i = 0; i < tmp; ++i)
		{
			EnterCriticalSection(&SDFT_queue);
			SDFT_TmpData[j][i] = SDFT_InputData[j].front();
			SDFT_InputData[j].pop();
			LeaveCriticalSection(&SDFT_queue);
		}
	}
	*dat = SDFT_TmpData;
	*Num = tmp;
	return 0;
}
//////////////////////////////////////////////////////////////////////////
//sliding dft
//Lineid = Line Id
//FreqId = special freq id
//Nw = dft window number
//input = one data 
//theta = the special frequency 
GTSD_FFT_API int SlidingDft(int32 Lineid, int32 FreqId, int32 Nw, double *input, double theta, double *Qr, double *Qi, bool* valid)
{
	double C0, S0; /* cos(theta) & sin(theta) */
	double err_r, err_i; /* real and imaginary parts of err */
	double oldest; /* the value need to be erased */

	C0 = cos(theta);
	S0 = sin(theta);

	//calc the oldest value which is needed to be erase
	if (SDFT_ValidFlag[Lineid] == true)
	{
		oldest = SDFT_WindowData[Lineid][SDFT_index[Lineid]];
	}
	else
	{
		oldest = 0;
	}

	SDFT_WindowData[Lineid][SDFT_index[Lineid]] = (*input);

	if (SDFT_stableSet[Lineid] == 1)
	{
		// Calculate err 
		err_r = SDFT_Sk_1[Lineid][FreqId].real + SDFT_WindowData[Lineid][SDFT_index[Lineid]] - oldest;
		err_i = SDFT_Sk_1[Lineid][FreqId].imag;
	}
	else
	{
		// Calculate err 
		err_r = SDFT_Sk_1[Lineid][FreqId].real*SDFT_stableSet[Lineid] + SDFT_WindowData[Lineid][SDFT_index[Lineid]] - oldest*pow(SDFT_stableSet[Lineid],Nw);
		err_i = SDFT_Sk_1[Lineid][FreqId].imag*SDFT_stableSet[Lineid];
	}


	//save sk
	SDFT_Sk[Lineid][FreqId].real = err_r*C0 - err_i*S0;
	SDFT_Sk[Lineid][FreqId].imag = err_r*S0 + err_i*C0;

	//不加窗
	if (SDFT_WindowType[Lineid] == 0)
	{
		*Qr = SDFT_Sk[Lineid][FreqId].real;
		*Qi = SDFT_Sk[Lineid][FreqId].imag;
	}
	//hanning window
	else if (SDFT_WindowType[Lineid] == 1)
	{
		*Qr = SDFT_Sk_2[Lineid][FreqId].real*SDFT_HanningWk[0] + SDFT_Sk_1[Lineid][FreqId].real*SDFT_HanningWk[1] + SDFT_Sk[Lineid][FreqId].real*SDFT_HanningWk[2];
		*Qi = SDFT_Sk_2[Lineid][FreqId].imag*SDFT_HanningWk[0] + SDFT_Sk_1[Lineid][FreqId].imag*SDFT_HanningWk[1] + SDFT_Sk[Lineid][FreqId].imag*SDFT_HanningWk[2];
	}
	else
	{
		*Qr = SDFT_Sk[Lineid][FreqId].real;
		*Qi = SDFT_Sk[Lineid][FreqId].imag;
	}

	//加窗需要sk_2 = sk_1
	SDFT_Sk_2[Lineid][FreqId].real = SDFT_Sk_1[Lineid][FreqId].real;
	SDFT_Sk_2[Lineid][FreqId].imag = SDFT_Sk_1[Lineid][FreqId].imag;	

	//let sk_1  == sk
	SDFT_Sk_1[Lineid][FreqId].real = SDFT_Sk[Lineid][FreqId].real;
	SDFT_Sk_1[Lineid][FreqId].imag = SDFT_Sk[Lineid][FreqId].imag;


	*valid = SDFT_ValidFlag[Lineid];

	return 0;
}
// LineNum = curve number
// dbb phh = output data
// Nf = output freq number
// N = window width
GTSD_FFT_API int SignalAnalysisSlidingDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf)
{
	if (LineNum<1)
	{
		return -1;
	}
	//if ((dbb == NULL) || (phh == NULL))
	//{
	//	//dat pointer must has value
	//	return -2;
	//}
	if ((N== NULL)||(Nf == NULL))
	{
		return -3;
	}
	for (int16 i = 0; i < LineNum;++i)
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
		for (int32 k = 0; k < Num;++k)
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

double*				SGDFT_df;			/* frequency step size */
double*				SGDFT_theta;		/* theta = 2*Pi*f/fs */
double*				SGDFT_dtheta;		/* theta step size */
double*				SGDFT_dfmin;		/* the min delta of the */
double*				SGDFT_N1;
COMPLEX**			SGDFT_Sk;			/*output*/
COMPLEX**			SGDFT_Sk_1;			/*last output*/
COMPLEX**			SGDFT_Sk_2;			/*last last output*/
	
double**            SGDFT_Vk;			/*中间值*/
double**            SGDFT_Vk_1;			/*last 中间值*/
double**            SGDFT_Vk_2;			/*last last 中间值*/

double*				SGDFT_stableSet;	/*stable value 1,临界稳定，接近1，可以调整极点到单位圆内*/
double**			SGDFT_WindowData;   /*window data pointer*/
bool				SGDFT_ReadFlag = false;
queue<double>*		SGDFT_InputData;	/*input data queue*/
double**			SGDFT_TmpData;		/*tmp data*/
//定义关键区，用于在不同的线程中都去操作数据个数
CRITICAL_SECTION	SGDFT_queue;
double**			SGDFT_dbb_out;
double**			SGDFT_phh_out;
double**			SGDFT_dbb_out_cpy;
double**			SGDFT_phh_out_cpy;

int32				SGDFT_Times = 0;
#define				SGDFT_OUTPUT_COPY_TIMES		1
Uint64*				SGDFT_index;
bool*				SGDFT_ValidFlag;

//Hanning window
#define				SGDFT_HANNING_K_NUM		3
double*				SGDFT_HanningWk;
int32*				SGDFT_WindowType; //0:不加窗。1：hanning窗


//////////////////////////////////////////////////////////////////////////
//locat space for slding Goertzel Dft
//LineNum = sliding Goertzel dft curve allnumber 
//N = Window width
//Nf = frequency number need to be calc
//N and Nf are array for different Curve
//this function should be call when start sliding Goertzel DFT.
GTSD_FFT_API int OpenSlidingGoertzel(int32 LineNum, int32* N, int32* Nf)
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
GTSD_FFT_API int CloseSlidingGoertzel(int32 LineNum)
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
GTSD_FFT_API int SetSlidingGoertzelParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs, int32 mode, int32* WinType)
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
GTSD_FFT_API int SlidingGoertzelAddData(int32 LineNum, int32 Num, double** dat)
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
//get data from the queue
// LineNum = the 1D number
// Num = the 2D number
// dat = 3D array pointer
GTSD_FFT_API int SlidingGoertzelGetData(int32 LineNum, int32* Num, double*** dat)
{
	if (LineNum < 1)
	{
		return -1;
	}
	int32 tmp;

	//if the size of the queue is zero ,then return zero number
	EnterCriticalSection(&SGDFT_queue);
	tmp = SGDFT_InputData[0].size();
	LeaveCriticalSection(&SGDFT_queue);
	if (tmp == 0)
	{
		*Num = tmp;
		*dat = SGDFT_TmpData;
		return 0;
	}

	// read size and locate space for different curve
	for (int32 j = 0; j < LineNum; ++j)
	{
		//locate space
		SGDFT_TmpData[j] = new double[tmp];

		//pop the value
		for (int32 i = 0; i < tmp; ++i)
		{
			EnterCriticalSection(&SGDFT_queue);
			SGDFT_TmpData[j][i] = SGDFT_InputData[j].front();
			SGDFT_InputData[j].pop();
			LeaveCriticalSection(&SGDFT_queue);
		}
	}
	*dat = SGDFT_TmpData;
	*Num = tmp;
	return 0;
}
//////////////////////////////////////////////////////////////////////////
//sliding Goertzel dft
//Lineid = Line Id
//FreqId = special freq id
//Nw = dft window number
//input = one data 
//theta = the special frequency 
GTSD_FFT_API int SlidingGoertzel(int32 Lineid, int32 FreqId, int32 Nw, double *input, double theta, double *Qr, double *Qi, bool* valid)
{
	double C0, S0; /* cos(theta) & sin(theta) */
	double oldest; /* the value need to be erased */

	C0 = cos(theta);
	S0 = sin(theta);

	//calc the oldest value which is needed to be erase
	if (SGDFT_ValidFlag[Lineid] == true)
	{
		oldest = SGDFT_WindowData[Lineid][SGDFT_index[Lineid]];
	}
	else
	{
		oldest = 0;
	}

	SGDFT_WindowData[Lineid][SGDFT_index[Lineid]] = (*input);

	// Calculate V
	SGDFT_Vk[Lineid][FreqId] = 2 * C0*SGDFT_Vk_1[Lineid][FreqId] - SGDFT_Vk_2[Lineid][FreqId] + SGDFT_WindowData[Lineid][SGDFT_index[Lineid]] - oldest;

	//Calculate sk
	SGDFT_Sk[Lineid][FreqId].real = SGDFT_Vk[Lineid][FreqId] - C0*SGDFT_Vk_1[Lineid][FreqId];
	SGDFT_Sk[Lineid][FreqId].imag = -S0*SGDFT_Vk_1[Lineid][FreqId];

	//不加窗
	if (SGDFT_WindowType[Lineid] == 0)
	{
		*Qr = SGDFT_Sk[Lineid][FreqId].real;
		*Qi = SGDFT_Sk[Lineid][FreqId].imag;
	}
	//hanning window
	else if (SGDFT_WindowType[Lineid] == 1)
	{
		*Qr = SGDFT_Sk_2[Lineid][FreqId].real*SGDFT_HanningWk[0] + SGDFT_Sk_1[Lineid][FreqId].real*SGDFT_HanningWk[1] + SGDFT_Sk[Lineid][FreqId].real*SGDFT_HanningWk[2];
		*Qi = SGDFT_Sk_2[Lineid][FreqId].imag*SGDFT_HanningWk[0] + SGDFT_Sk_1[Lineid][FreqId].imag*SGDFT_HanningWk[1] + SGDFT_Sk[Lineid][FreqId].imag*SGDFT_HanningWk[2];
	}
	else
	{
		*Qr = SGDFT_Sk[Lineid][FreqId].real;
		*Qi = SGDFT_Sk[Lineid][FreqId].imag;
	}

	//加窗需要sk_2 = sk_1
	SGDFT_Sk_2[Lineid][FreqId].real = SGDFT_Sk_1[Lineid][FreqId].real;
	SGDFT_Sk_2[Lineid][FreqId].imag = SGDFT_Sk_1[Lineid][FreqId].imag;

	//let sk_1  == sk
	SGDFT_Sk_1[Lineid][FreqId].real = SGDFT_Sk[Lineid][FreqId].real;
	SGDFT_Sk_1[Lineid][FreqId].imag = SGDFT_Sk[Lineid][FreqId].imag;


	SGDFT_Vk_2[Lineid][FreqId]		= SGDFT_Vk_1[Lineid][FreqId];
	SGDFT_Vk_1[Lineid][FreqId]		= SGDFT_Vk[Lineid][FreqId];

	*valid = SGDFT_ValidFlag[Lineid];

	return 0;
}
// LineNum = curve number
// dbb phh = output data
// Nf = output freq number
// N = window width
GTSD_FFT_API int SignalAnalysisSlidingGoertzelDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf)
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
