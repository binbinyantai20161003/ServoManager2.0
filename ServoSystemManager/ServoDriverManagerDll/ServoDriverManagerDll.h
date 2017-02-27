//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	scan file and print xml										//
//	file				:	Scan.h														//
//	Description			:	use for scan message and print xml							//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef		__GTSD_DRIVER_MANAGER__
#define		__GTSD_DRIVER_MANAGER__

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SERVODRIVERMANAGERDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SERVODRIVERMANAGERDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SERVODRIVERMANAGERDLL_EXPORTS
#define SERVODRIVERMANAGERDLL_API __declspec(dllexport)
#else
#define SERVODRIVERMANAGERDLL_API __declspec(dllimport)
#endif

/************************************************************************/
/* ʹ�÷���
1����������
2��vs�����ļ���IAR����
3��IAR������ɵõ����ļ���VS������Ϣ
4: ���ٶ���
*/
/************************************************************************/

//��������
SERVODRIVERMANAGERDLL_API int16 SDM_CreateObject();
//���ٶ���
SERVODRIVERMANAGERDLL_API int16 SDM_DeleteObject();

//VS �����ļ���IAR����
SERVODRIVERMANAGERDLL_API int16 SDM_VS2IAR(wstring& Scanfilepath);

//IAR������ɵõ����ļ���VS������Ϣ
SERVODRIVERMANAGERDLL_API int16 SDM_IAR2VS(wstring& Addrfilepath, wstring& xmlfilepath, int16& devAxisNum);

//ִ���������ļ�
SERVODRIVERMANAGERDLL_API int16 SDM_RUNBAT(wstring& prjwstr, wstring& installwstr);

//��ȡ���ɵ�xml�ļ�����
SERVODRIVERMANAGERDLL_API int16 SDM_GetXmlDirName(wstring& xmlDirName);

//��ȡ����prtyTree xml��Ҳ�������Ա�

SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrtyXml(wstring& xmlfilepath);
SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrtyOldXml(wstring& xmlfilepath);

//�Ƚ������ļ����þɵĳ�ʼ���µġ�
SERVODRIVERMANAGERDLL_API int16 SDM_PrtyCompareUpdate();

//��prtyTree���ṹ�и��������ҵ��ڵ㣬���ؽڵ�ĵ�ַ��
SERVODRIVERMANAGERDLL_API int16 SDM_FindPrtyTreeElement(wstring& element_name, void** element_addr);

//�����µĸ�����д��prtyTree xml�������´�ʹ�á�
SERVODRIVERMANAGERDLL_API int16 SDM_WritePrtyXml(wstring& filepathT, wstring& xmlfilepath);
SERVODRIVERMANAGERDLL_API int16 SDM_WriteOldPrtyXml(wstring& filepathT, wstring& xmlfilepath);

//�޸�prtyTreeĳ�ڵ������(���ݵ�ַ)
SERVODRIVERMANAGERDLL_API int16 SDM_SetPrtyTreeElmACTaddr(void** elementaddr, void* prty_in);
//�޸�prtyTreeĳ�ڵ������(��������)
SERVODRIVERMANAGERDLL_API int16 SDM_SetPrtyTreeElmACTname(wstring& element_name, void* prty_in);

//��ȡprtyTreeĳ�ڵ�����ԣ����ݵ�ַ��
SERVODRIVERMANAGERDLL_API int16 SDM_GetPrtyTreeElmACTaddr(void** elementaddr, void* prty_in);
//��ȡprtyTreeĳ�ڵ�����ԣ��������֣�
SERVODRIVERMANAGERDLL_API int16 SDM_GetPrtyTreeElmACTname(wstring& element_name, void* prty_in);

//�����ļ��Ƚ�
SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrmXml(wstring& xmlfilepath);
SERVODRIVERMANAGERDLL_API int16 SDM_ReadOldPrmXml(wstring& xmlfilepath);

//�Ƚ������ļ����þɵĳ�ʼ���µġ�
SERVODRIVERMANAGERDLL_API int16 SDM_PrmCompareUpdate();

//�����µĵ��������д��xml�������´�ʹ�á�
SERVODRIVERMANAGERDLL_API int16 SDM_WritePrmXml(wstring& filepathT, wstring& xmlfilepath);
SERVODRIVERMANAGERDLL_API int16 SDM_WriteOldPrmXml(wstring& filepathT, wstring& xmlfilepath);


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//ini file

typedef struct INPUTDIRECTORY
{
	wstring IAR_Servo;
	wstring IAR_Addr;
	wstring IAR_Bin;
	wstring DEV_AXIS_NUM;
}inputDirectory;

SERVODRIVERMANAGERDLL_API int16 SDM_WriteDirectoryIniFile(wstring& fileName, inputDirectory& dir);
SERVODRIVERMANAGERDLL_API int16 SDM_ReadDirectoryIniFile(wstring& fileName, inputDirectory* dir);

#endif
