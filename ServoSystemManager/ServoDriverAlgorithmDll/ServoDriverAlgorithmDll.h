//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	algorithm dll 												//
//	file				:	ServoDriverAlgorithmDll.h									//
//	Description			:	algorithm function											//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/9/27	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//

// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 SERVODRIVERALGORITHMDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// SERVODRIVERALGORITHMDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef SERVODRIVERALGORITHMDLL_EXPORTS
#define SERVODRIVERALGORITHMDLL_API __declspec(dllexport)
#else
#define SERVODRIVERALGORITHMDLL_API __declspec(dllimport)
#endif

//////////////////////////////////////////////////////////////////////////
//fft analysis

SERVODRIVERALGORITHMDLL_API int RespAnalysisInFreDomain(double * r_in, double * r_out, double * dbb, double * phh, unsigned int n);

SERVODRIVERALGORITHMDLL_API int SignalAnalysisFFT(double * r_in, double * dbb, double * phh, unsigned int n);

//new fft can speed up 

SERVODRIVERALGORITHMDLL_API int RespAnalysisInFreDomain_x(COMPLEX* input, COMPLEX* output, double * dbb, double * phh, unsigned int n);

SERVODRIVERALGORITHMDLL_API int SignalAnalysisFFT_x(COMPLEX* input, double * dbb, double * phh, unsigned int n);

//////////////////////////////////////////////////////////////////////////
SERVODRIVERALGORITHMDLL_API int SignalAnalysisGoertzel(double f1, double f2, int32 N, int32 Nf, double fs, double* dat_in, double * dbb, double * phh, int32 mode);


//////////////////////////////////////////////////////////////////////////
//sdft
SERVODRIVERALGORITHMDLL_API int OpenSlidingDft(int32 LineNum, int32* N, int32* Nf);

SERVODRIVERALGORITHMDLL_API int CloseSlidingDft(int32 LineNum);

SERVODRIVERALGORITHMDLL_API int SetSlidingDftParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs, int32 mode, double* stable, int32* WinType);

SERVODRIVERALGORITHMDLL_API int SlidingDftAddData(int32 LineNum, int32 Num, double** dat);

SERVODRIVERALGORITHMDLL_API int SignalAnalysisSlidingDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf);


//////////////////////////////////////////////////////////////////////////

//sliding goertzel

SERVODRIVERALGORITHMDLL_API int OpenSlidingGoertzel(int32 LineNum, int32* N, int32* Nf);

SERVODRIVERALGORITHMDLL_API int CloseSlidingGoertzel(int32 LineNum);

SERVODRIVERALGORITHMDLL_API int SetSlidingGoertzelParam(int32 LineNum, double* f1, double* f2, int32* N, int32* Nf, double fs, int32 mode, int32* WinType);

SERVODRIVERALGORITHMDLL_API int SlidingGoertzelAddData(int32 LineNum, int32 Num, double** dat);

SERVODRIVERALGORITHMDLL_API int SignalAnalysisSlidingGoertzelDft(int32 LineNum, int32* N, double*** dbb, double*** phh, int32* Nf);


