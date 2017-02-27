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

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SERVODRIVERALGORITHMDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SERVODRIVERALGORITHMDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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


