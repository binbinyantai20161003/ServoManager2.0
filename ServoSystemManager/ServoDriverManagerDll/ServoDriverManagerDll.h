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

// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 SERVODRIVERMANAGERDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// SERVODRIVERMANAGERDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef SERVODRIVERMANAGERDLL_EXPORTS
#define SERVODRIVERMANAGERDLL_API __declspec(dllexport)
#else
#define SERVODRIVERMANAGERDLL_API __declspec(dllimport)
#endif

/************************************************************************/
/* 使用方法
1：创建对象
2：vs生成文件给IAR编译
3：IAR编译完成得到的文件给VS完善信息
4: 销毁对象
*/
/************************************************************************/

//创建对象
SERVODRIVERMANAGERDLL_API int16 SDM_CreateObject();
//销毁对象
SERVODRIVERMANAGERDLL_API int16 SDM_DeleteObject();

//VS 生成文件给IAR编译
SERVODRIVERMANAGERDLL_API int16 SDM_VS2IAR(wstring& Scanfilepath);

//IAR编译完成得到的文件给VS完善信息
SERVODRIVERMANAGERDLL_API int16 SDM_IAR2VS(wstring& Addrfilepath, wstring& xmlfilepath, int16& devAxisNum);

//执行批处理文件
SERVODRIVERMANAGERDLL_API int16 SDM_RUNBAT(wstring& prjwstr, wstring& installwstr);

//获取生成的xml文件夹名
SERVODRIVERMANAGERDLL_API int16 SDM_GetXmlDirName(wstring& xmlDirName);

//读取辅助prtyTree xml，也就是特性表

SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrtyXml(wstring& xmlfilepath);
SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrtyOldXml(wstring& xmlfilepath);

//比较两个文件并用旧的初始化新的。
SERVODRIVERMANAGERDLL_API int16 SDM_PrtyCompareUpdate();

//从prtyTree树结构中根据名字找到节点，返回节点的地址。
SERVODRIVERMANAGERDLL_API int16 SDM_FindPrtyTreeElement(wstring& element_name, void** element_addr);

//将更新的辅助表写入prtyTree xml，用于下次使用。
SERVODRIVERMANAGERDLL_API int16 SDM_WritePrtyXml(wstring& filepathT, wstring& xmlfilepath);
SERVODRIVERMANAGERDLL_API int16 SDM_WriteOldPrtyXml(wstring& filepathT, wstring& xmlfilepath);

//修改prtyTree某节点的属性(根据地址)
SERVODRIVERMANAGERDLL_API int16 SDM_SetPrtyTreeElmACTaddr(void** elementaddr, void* prty_in);
//修改prtyTree某节点的属性(根据名字)
SERVODRIVERMANAGERDLL_API int16 SDM_SetPrtyTreeElmACTname(wstring& element_name, void* prty_in);

//读取prtyTree某节点的属性（根据地址）
SERVODRIVERMANAGERDLL_API int16 SDM_GetPrtyTreeElmACTaddr(void** elementaddr, void* prty_in);
//读取prtyTree某节点的属性（根据名字）
SERVODRIVERMANAGERDLL_API int16 SDM_GetPrtyTreeElmACTname(wstring& element_name, void* prty_in);

//参数文件比较
SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrmXml(wstring& xmlfilepath);
SERVODRIVERMANAGERDLL_API int16 SDM_ReadOldPrmXml(wstring& xmlfilepath);

//比较两个文件并用旧的初始化新的。
SERVODRIVERMANAGERDLL_API int16 SDM_PrmCompareUpdate();

//将更新的电机参数表写入xml，用于下次使用。
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
