// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 GTSD_FFT_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// GTSD_FFT_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef GTSD_FFT_EXPORTS
#define GTSD_FFT_API __declspec(dllexport)
#else
#define GTSD_FFT_API __declspec(dllimport)
#endif

#ifndef		__AMLFFT_H__
#define		__AMLFFT_H__

#define  M_PI				3.14159265358979323846


typedef struct complex
{
	double real;
	double imag;
}COMPLEX;

GTSD_FFT_API int transform(double real[], double imag[], size_t n);

GTSD_FFT_API int inverse_transform(double real[], double imag[], size_t n);

GTSD_FFT_API int transform_radix2(double real[], double imag[], size_t n);

GTSD_FFT_API int transform_bluestein(double real[], double imag[], size_t n);

GTSD_FFT_API int convolve_real(double x[], double y[], double out[], size_t n);

GTSD_FFT_API int convolve_complex(double xreal[], double ximag[], double yreal[], double yimag[], double outreal[], double outimag[], size_t n);

GTSD_FFT_API int RespAnalysisInFreDomain(double * r_in, double * r_out, double * dbb, double * phh, unsigned int n);

GTSD_FFT_API int SignalAnalysisFFT(double * r_in, double * dbb, double * phh, unsigned int n);

//add wang.bin
GTSD_FFT_API int transform_x(COMPLEX* x, size_t n);

GTSD_FFT_API int inverse_transform_x(COMPLEX* x, size_t n);

GTSD_FFT_API int transform_radix2_x(COMPLEX* x, size_t n);

GTSD_FFT_API int transform_bluestein_x(COMPLEX* x, size_t n);

GTSD_FFT_API int transform2D(COMPLEX* X1,COMPLEX* X2, size_t N);

GTSD_FFT_API int inverse_transform2D(COMPLEX* X1, COMPLEX* X2,size_t N);

GTSD_FFT_API int transform1(COMPLEX* X,size_t N);

GTSD_FFT_API int inverse_transform1(COMPLEX* X, size_t N);

GTSD_FFT_API int RespAnalysisInFreDomain_x(COMPLEX* input, COMPLEX* output, double * dbb, double * phh, unsigned int n);

GTSD_FFT_API int SignalAnalysisFFT_x(COMPLEX* input, double * dbb, double * phh, unsigned int n);

//////////////////////////////////////////////////////////////////////////

GTSD_FFT_API int goertzel(int32 N, double *input, double theta, double *Qr, double *Qi);

GTSD_FFT_API int SignalAnalysisGoertzel(double f1, double f2, int32 N, int32 Nf, double fs, double* dat_in, double * dbb, double * phh,int32 mode);


//sdft
GTSD_FFT_API int OpenSlidingDft(int32 LineNum, int32* N, int32* Nf);

GTSD_FFT_API int CloseSlidingDft(int32 LineNum);

GTSD_FFT_API int SetSlidingDftParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs,int32 mode, double* stable, int32* WinType);

GTSD_FFT_API int SlidingDftAddData(int32 LineNum, int32 Num, double** dat);

GTSD_FFT_API int SlidingDftGetData(int32 LineNum, int32* Num, double*** dat);

GTSD_FFT_API int SlidingDft(int32 Lineid, int32 FreqId, int32 Nw, double *input, double theta, double *Qr, double *Qi, bool* valid);

GTSD_FFT_API int SignalAnalysisSlidingDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf);


//sliding goertzel

GTSD_FFT_API int OpenSlidingGoertzel(int32 LineNum, int32* N, int32* Nf);

GTSD_FFT_API int CloseSlidingGoertzel(int32 LineNum);

GTSD_FFT_API int SetSlidingGoertzelParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs, int32 mode, int32* WinType);

GTSD_FFT_API int SlidingGoertzelAddData(int32 LineNum, int32 Num, double** dat);

GTSD_FFT_API int SlidingGoertzelGetData(int32 LineNum, int32* Num, double*** dat);

GTSD_FFT_API int SlidingGoertzel(int32 Lineid, int32 FreqId, int32 Nw, double *input, double theta, double *Qr, double *Qi, bool* valid);

GTSD_FFT_API int SignalAnalysisSlidingGoertzelDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf);


#endif