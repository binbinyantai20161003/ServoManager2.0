//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	FFT Aanlysis 												//
//	file				:	GTSD_FFT.h													//
//	Description			:	change the file write by liu.g to lib						//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/9/27	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef		__GTSD_FFT_H__
#define		__GTSD_FFT_H__

#define  M_PI				3.14159265358979323846


typedef struct complex
{
	double real;
	double imag;
}COMPLEX;

//////////////////////////////////////////////////////////////////////////
//function  declaration

int transform(double real[], double imag[], size_t n);

int inverse_transform(double real[], double imag[], size_t n);

int transform_radix2(double real[], double imag[], size_t n);

int transform_bluestein(double real[], double imag[], size_t n);

int convolve_real(double x[], double y[], double out[], size_t n);

int convolve_complex(double xreal[], double ximag[], double yreal[], double yimag[], double outreal[], double outimag[], size_t n);

double	IFatanCal(double xq, double xd);

// Private function prototypes
static int32	reverse_bits(int32 x, Uint32 n);
static void		*memdup(void *src, size_t n);
static int32	reverse_bits1(int32 x, Uint32 levels);

//////////////////////////////////////////////////////////////////////////
//new function 

int transform_x(COMPLEX* x, size_t n);

int inverse_transform_x(COMPLEX* x, size_t n);

int transform_radix2_x(COMPLEX* x, size_t n);

int transform_bluestein_x(COMPLEX* x, size_t n);

int transform2D(COMPLEX* X1, COMPLEX* X2, size_t N);

int inverse_transform2D(COMPLEX* X1, COMPLEX* X2, size_t N);

int transform1(COMPLEX* X, size_t N);

int inverse_transform1(COMPLEX* X, size_t N);


//////////////////////////////////////////////////////////////////////////
int goertzel(int32 N, double *input, double theta, double *Qr, double *Qi);


//////////////////////////////////////////////////////////////////////////

#define					SDFT_HANNING_K_NUM			3

#define					SDFT_OUTPUT_COPY_TIMES		1



//////////////////////////////////////////////////////////////////////////

extern double*					SDFT_df;			/* frequency step size */
extern double*					SDFT_theta;			/* theta = 2*Pi*f/fs */
extern double*					SDFT_dtheta;		/* theta step size */
extern double*					SDFT_dfmin;			/* the min delta of the */
extern double*					SDFT_N1;
extern COMPLEX**				SDFT_Sk;			/*output*/
extern COMPLEX**				SDFT_Sk_1;			/*last output*/
extern COMPLEX**				SDFT_Sk_2;			/*last last output*/
extern double*					SDFT_stableSet;		/*stable value 1,临界稳定，接近1，可以调整极点到单位圆内*/
extern double**					SDFT_WindowData;	/*window data pointer*/
extern bool						SDFT_ReadFlag;
extern queue<double>*			SDFT_InputData;		/*input data queue*/
extern double**					SDFT_TmpData;		/*tmp data*/

//定义关键区，用于在不同的线程中都去操作数据个数
extern CRITICAL_SECTION			SDFT_queue;

extern double**					SDFT_dbb_out;
extern double**					SDFT_phh_out;
extern double**					SDFT_dbb_out_cpy;
extern double**					SDFT_phh_out_cpy;

extern int32					SDFT_Times;
extern Uint64*					SDFT_index;
extern bool*					SDFT_ValidFlag;

//Hanning window
extern double*					SDFT_HanningWk;
extern int32*					SDFT_WindowType; //0:不加窗。1：hanning窗



int SlidingDftGetData(int32 LineNum, int32* Num, double*** dat);

int SlidingDft(int32 Lineid, int32 FreqId, int32 Nw, double *input, double theta, double *Qr, double *Qi, bool* valid);


//////////////////////////////////////////////////////////////////////////

#define				SGDFT_HANNING_K_NUM			3

#define				SGDFT_OUTPUT_COPY_TIMES		1


//////////////////////////////////////////////////////////////////////////

extern double*				SGDFT_df;			/* frequency step size */
extern double*				SGDFT_theta;		/* theta = 2*Pi*f/fs */
extern double*				SGDFT_dtheta;		/* theta step size */
extern double*				SGDFT_dfmin;		/* the min delta of the */
extern double*				SGDFT_N1;
extern COMPLEX**			SGDFT_Sk;			/*output*/
extern COMPLEX**			SGDFT_Sk_1;			/*last output*/
extern COMPLEX**			SGDFT_Sk_2;			/*last last output*/

extern double**				SGDFT_Vk;			/*中间值*/
extern double**				SGDFT_Vk_1;			/*last 中间值*/
extern double**				SGDFT_Vk_2;			/*last last 中间值*/

extern double*				SGDFT_stableSet;	/*stable value 1,临界稳定，接近1，可以调整极点到单位圆内*/
extern double**				SGDFT_WindowData;   /*window data pointer*/
extern bool					SGDFT_ReadFlag;
extern queue<double>*		SGDFT_InputData;	/*input data queue*/
extern double**				SGDFT_TmpData;		/*tmp data*/

//定义关键区，用于在不同的线程中都去操作数据个数
extern CRITICAL_SECTION		SGDFT_queue;

extern double**				SGDFT_dbb_out;
extern double**				SGDFT_phh_out;
extern double**				SGDFT_dbb_out_cpy;
extern double**				SGDFT_phh_out_cpy;

extern int32				SGDFT_Times;
extern Uint64*				SGDFT_index;
extern bool*				SGDFT_ValidFlag;

//Hanning window
extern double*				SGDFT_HanningWk;
extern int32*				SGDFT_WindowType; //0:不加窗。1：hanning窗


int SlidingGoertzelGetData(int32 LineNum, int32* Num, double*** dat);

int SlidingGoertzel(int32 Lineid, int32 FreqId, int32 Nw, double *input, double theta, double *Qr, double *Qi, bool* valid);

#endif
