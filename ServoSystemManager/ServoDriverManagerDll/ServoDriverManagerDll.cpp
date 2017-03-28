// ServoDriverManagerDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;

#include "FindDirectoryFile.h"
#include "BuildVarRelation.h"
#include "ParseFile.h"
#include "StringHandler.h"
#include "BuildPrmRelation.h"
#include "PrtyCompare.h"
#include "PrmCompare.h"
#include "xml.h"
#include "ServoDriverManagerDll.h"
#include "IniFileHandler.h"
HANDLE g_cur_console;

SERVODRIVERMANAGERDLL_API int16 SDM_CreateObject()
{	
	g_cur_console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetStdHandle(STD_OUTPUT_HANDLE, g_cur_console);

	if (g_sco == NULL)
	{
		g_sco = new ffsco();
	}
	if (g_parseHfile == NULL)
	{
		g_parseHfile = new CParseHfile();
	}
	if (g_buildVarRelation == NULL)
	{
		g_buildVarRelation = new CBuildVarRelation();
	}
	if (g_buildPrmRelation == NULL)
	{
		g_buildPrmRelation = new CBuildPrmRelation();
	}
	if (g_xml == NULL)
	{
		g_xml = new GTSD_XML();
	}
	if (g_prty_tree == NULL)
	{
		g_prty_tree = new Cprty_tree();
	}
	if (g_prm_tree == NULL)
	{
		g_prm_tree = new Cprm_tree();
	}

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_DeleteObject()
{
	if (g_sco != NULL)
	{
		delete g_sco;		g_sco = NULL;
	}

	if (g_buildVarRelation != NULL)
	{
		delete g_buildVarRelation; g_buildVarRelation = NULL;
	}
	if (g_buildPrmRelation != NULL)
	{
		delete g_buildPrmRelation; g_buildPrmRelation = NULL;
	}
	if (g_xml != NULL)
	{
		delete g_xml; g_xml = NULL;
	}
	if (g_prty_tree != NULL)
	{
		delete g_prty_tree; g_prty_tree = NULL;
	}
	if (g_prm_tree != NULL)
	{
		delete g_prm_tree; g_prm_tree = NULL;
	}
	if (g_parseHfile != NULL)
	{
		delete g_parseHfile;  g_parseHfile = NULL;
	}
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_VS2IAR(wstring& Scanfilepath)
{
	vector<wstring> filename;
	filename.clear();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始搜索头文件...."));

	//从该路径的目录下找到所有的头文件
	g_sco->findHeaderfile(g_sco,Scanfilepath, filename);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("搜索头文件完成...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始删除不需要扫描的文件...."));

	//删除一些不需要扫描的文件提高效率
	g_sco->eraseHeaderfile((wstring)(L"DspCpu.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"FunLutTbl.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"VirFloatMath.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"ServoApp.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"Kernel.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"HalResource.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"BackGround.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"SevAuxTaskSched.h"), filename);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("删除不需要扫描的文件结束...."));


	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始扫描头文件结构...."));

	//读取头文件中的信息放入对应的结构中
	g_parseHfile->ParseAllHFile(filename);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("扫描头文件结构完成...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始将扫描的结构建立父子关系...."));

	g_buildVarRelation->initVar();
	//层层迭代建立var list结构
	g_buildVarRelation->BuildVarList();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("将扫描的结构建立父子关系结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始写信息到GetAddress.c文件中...."));

	//写成IAR能够识别的文件，然后输出给IAR数用
	g_buildVarRelation->WriteFileForIarVarAddress(*(g_buildVarRelation->VarStList));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("写信息到GetAddress.c文件中结束...."));

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_IAR2VS(wstring& Addrfilepath, wstring& xmlfilepath, int16& devAxisNum)
{
	//////////////////////////////////////////////////////////////////////////
	
	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始根据Addr.txt文件更新ram地址...."));
	
	//读取经过IAR编译并且打印出的地址偏移文件，根据该文件更新地址偏移
	g_buildVarRelation->UpdateVarAddrOfst(Addrfilepath, *(g_buildVarRelation->VarStList),g_parseHfile->AxisNumDefine);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("根据Addr.txt文件更新ram地址结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始更新其它轴的ram地址...."));

	//计算其它轴的偏移地址，并更新其它轴的地址偏移
	g_buildVarRelation->UpdateVarAddrOfstAxis(g_parseHfile->AxisNumDefine);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("更新其它轴的ram地址结束...."));

	//////////////////////////////////////////////////////////////////////////
	g_buildPrmRelation->initPrm();
	wstring fpgaName = L".\\XmlFiles\\FpgaConfig.xml";
	wstring fpgaPath = fpgaName;

	wstring AuxName = L".\\XmlFiles\\GlobalConfig.xml";
	wstring AuxPath = AuxName;
	//wstring AuxPath = L"";

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始从ram中提取参数表信息并提取属性表信息...."));

	//建立参数的list，并建立了具有属性的参数list 用于功能模块
	g_buildPrmRelation->BuildPrmList(g_buildVarRelation, fpgaPath, AuxPath);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("从ram中提取参数表信息并提取属性表信息结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始从参数信息中提取模块信息...."));

	//得到参数的子module
	g_buildPrmRelation->GetPrmChildModule();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("从参数信息中提取模块信息结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("更新参数表中的offset为铁电中分配的偏移...."));

	//更新参数all里面的ofst为铁电的ofst
	g_buildPrmRelation->UpdatePrmFramAddrOfst();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("更新参数表中的offset结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("更新其它轴参数表中的offset为铁电中分配的偏移...."));

	//计算另一个轴的铁电中的ofst
	g_buildPrmRelation->UpdatePrmFramAddrOfstAxis(g_parseHfile->AxisNumDefine);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("更新其它轴参数表中的offset结束...."));


	//////////////////////////////////////////////////////////////////////////
	//获取用户曲线
	//_tcprintf_s(_T("%s \r\n\r\n"), _T("获取用户显示的曲线...."));

	//_tcprintf_s(_T("%s \r\n\r\n"), _T("获取用户显示的曲线结束...."));
	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("将ram信息进行分级,方便打印...."));

	//获取所有变量的等级，包括所有轴
	int16 level = g_buildVarRelation->FindVarLevelNum(g_parseHfile->AxisNumDefine);
	//将所有变量分开等级，包括各个轴
	g_buildVarRelation->SplitVarLevel(level, g_parseHfile->AxisNumDefine);
	g_buildVarRelation->VarLevelNum = level;

	_tcprintf_s(_T("%s \r\n\r\n"), _T("将ram信息进行分级结束...."));

	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("将参数信息进行分级,方便打印...."));

	//获取参数等级
	int16  levelprm = g_buildPrmRelation->FindPrmLevelNum(g_parseHfile->AxisNumDefine);
	//将所有参数分开等级，包括各个轴
	g_buildPrmRelation->SplitPrmLevel(levelprm,g_buildVarRelation,g_parseHfile->AxisNumDefine);
	g_buildPrmRelation->PrmLevelNum = levelprm;
	g_prty_tree->initVar(g_buildPrmRelation->PrmLevelNum);
	g_prm_tree->initVar(g_buildPrmRelation->PrmLevelNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("将参数信息进行分级结束...."));

	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始根据后缀获取功能模块...."));

	//得到各个功能模块，根据名称的后缀和总的等级
	g_buildPrmRelation->GetPrmFuncList(g_parseHfile->funcModuleNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("根据后缀获取功能模块结束...."));

	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出参数初始化宏定义文件...."));

	wstring macrofilename = L"\\PrmMacroDef.h";
	wstring macrofilepath = xmlfilepath + macrofilename;
	g_buildPrmRelation->PrintPrmMacroDefine(macrofilepath);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出参数初始化宏定义文件完成...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出设备整体参数文件...."));

	wstring filePath,fileName;
	wstring templateFileName = L".\\XmlFiles\\template.xml";
	wstring templateFilePath = templateFileName;
	//生成fram中使用的参数文件，四轴对应一个参数文件
	fileName = L"\\FlashPrm_AllAxis.xml";
	filePath = xmlfilepath + fileName;
	g_xml->saveFramPrmTree(templateFilePath, filePath, g_buildPrmRelation->PrmStLevelList, g_buildPrmRelation->PrmStLevelListAxis, levelprm,g_parseHfile->AxisNumDefine, devAxisNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出设备整体参数文件结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出程序结构变量文件...."));

	//树状结构的程序结构xml文件
	fileName = L"\\PrmRAMAxis0.xml";
	filePath = xmlfilepath + fileName;
	g_xml->saveTree(templateFilePath,filePath, g_buildVarRelation->VarStLevelList, level);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出程序结构变量文件结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出程序参数文件...."));

	//树状结构的参数xml文件
	fileName = L"\\PrmFlashAxis0.xml";
	filePath = xmlfilepath + fileName;
	g_xml->saveTree(templateFilePath, filePath, g_buildPrmRelation->PrmStLevelList, levelprm);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出程序参数文件结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出其它轴的程序结构文件 和 参数文件...."));

	//其它轴的树状结构xml文件，程序结构和参数
	for (int16 i = 1; i < g_parseHfile->AxisNumDefine; i++)
	{
		wstring tmp;
		wstringstream ss;
		ss << i;
		ss >> tmp;
		filePath = (xmlfilepath) + L"\\PrmRAMAxis" + tmp + L".xml";
		g_xml->saveTree(templateFilePath, filePath, (g_buildVarRelation->VarStLevelListAxis[i - 1]), level);

		filePath = (xmlfilepath) + L"\\PrmFlashAxis" + tmp + L".xml";
		g_xml->saveTree(templateFilePath, filePath, (g_buildPrmRelation->PrmStLevelListAxis[i - 1]), levelprm);
	}
	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出其它轴的程序结构文件 和 参数文件 结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出辅助参数表格...."));

	//建立辅助表格，只有参数，其中只包含属性等，树状结构xml
	filePath = (xmlfilepath) + L"\\PrmPrtyTree.xml";
	g_xml->savePrtyTree(templateFilePath, filePath, g_buildPrmRelation->PrmStLevelListPrty, levelprm);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出辅助参数表格结束...."));


	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出各个功能模块文件...."));

	//功能模块xml文件
	for (int16 i = 1; i <= g_parseHfile->funcModuleNum; i++)
	{
		wstring tmp;
		switch (i)
		{
		case 1:{tmp = L"Motor";			break; }
		case 2:{tmp = L"Power";			break; }
		case 3:{tmp = L"Encoder";		break; }
		case 4:{tmp = L"Currentloop";	break; }
		case 5:{tmp = L"Speedloop";		break; }
		case 6:{tmp = L"Positionloop";	break; }
		default:{break; }
		}
		filePath = (xmlfilepath) + L"\\PrmFunc" + tmp + L".xml";
		g_xml->saveFuncPrty(templateFilePath,filePath, &(g_buildPrmRelation->PrmFuncList[i - 1]));
	}

	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出各个功能模块文件结束...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始输出ram合成文件用于曲线选择...."));

	//将几个轴的ram合成为一个文件
	fileName = L"\\RamPrm_AllAxis.xml";
	filePath = xmlfilepath + fileName;
	g_xml->savePlotRamTree(templateFilePath, filePath, g_buildVarRelation->VarStLevelList, g_buildVarRelation->VarStLevelListAxis, level, g_parseHfile->AxisNumDefine, devAxisNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("输出ram合成文件用于曲线选择结束...."));

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_RUNBAT(wstring& prjwstr, wstring& installwstr)
{
	string prjstr = ws2s(prjwstr);
	string installstr = ws2s(installwstr);

	string cmd = "call .\\batch\\getaddr.bat ";
	string cmdall = cmd + "\"" + prjstr + "\"" + " " + "\"" + installstr + "\"";

	system(cmdall.c_str());
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrtyXml(wstring& xmlfilepath)
{
	g_xml->loadPrtyTree(xmlfilepath, &(g_prty_tree->node));
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrtyOldXml(wstring& xmlfilepath)
{
	g_xml->loadPrtyTree(xmlfilepath, &(g_prty_tree->old_node));
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_PrtyCompareUpdate()
{
	g_prty_tree->UpdateNewTree();
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_WritePrtyXml(wstring& filepathT, wstring& xmlfilepath)
{
	wstring templateFileName = L"\\template.xml";
	wstring templateFilePath = filepathT + templateFileName;
	g_prty_tree->splitTreeNode2Level(g_buildPrmRelation->PrmLevelNum);
	g_xml->savePrtyTree(templateFilePath, xmlfilepath, g_prty_tree->ptryTreeList, g_buildPrmRelation->PrmLevelNum);
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_WriteOldPrtyXml(wstring& filepathT, wstring& xmlfilepath)
{
	wstring templateFileName = L"\\template.xml";
	wstring templateFilePath = filepathT + templateFileName;
	//因为更新后的node在下一次的时候就会变成旧的，所以这里新的和旧的文件都是写的新更新的node
	g_xml->savePrtyTree(templateFilePath, xmlfilepath, g_prty_tree->ptryTreeList, g_buildPrmRelation->PrmLevelNum);
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_FindPrtyTreeElement(wstring& element_name, void** element_addr)
{
	Cprty_tree_node** elementaddr = (Cprty_tree_node**)element_addr;
	//首先根据名字来获取要搜索的路径
	vector<wstring> vec;
	splitDotStr(element_name, vec);
	vector<wstring> vec_out;
	combineVecStr(vec, vec_out);
	if (vec_out.size() < 1)
	{
		element_addr = NULL;
		return -1;
	}
	else
	{
		g_prty_tree->findTreeElement(vec_out, 0, g_prty_tree->node, elementaddr);
	}
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_SetPrtyTreeElmACTaddr(void** elementaddr, void* prty_in)
{
	Cprty_tree_node** element_addr			= (Cprty_tree_node**)elementaddr;
	PRMPRTY* prty							= (PRMPRTY*)prty_in;
	(*element_addr)->prty.memberType		= prty->memberType;
	(*element_addr)->prty.memberName		= prty->memberName;
	(*element_addr)->prty.parent			= prty->parent;
	(*element_addr)->prty.unit				= prty->unit;
	(*element_addr)->prty.introduction		= prty->introduction;
	(*element_addr)->prty.uplimit			= prty->uplimit;
	(*element_addr)->prty.downlimit			= prty->downlimit;
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_SetPrtyTreeElmACTname(wstring& element_name, void* prty_in)
{
	//首先查找到该地址
	PRMPRTY* prty = (PRMPRTY*)prty_in;
	Cprty_tree_node* element_addr = NULL;
	SDM_FindPrtyTreeElement(element_name, (void**)(&element_addr));
	
	(element_addr)->prty.memberType			= prty->memberType;
	(element_addr)->prty.memberName			= prty->memberName;
	(element_addr)->prty.parent				= prty->parent;
	(element_addr)->prty.unit				= prty->unit;
	(element_addr)->prty.introduction		= prty->introduction;
	(element_addr)->prty.uplimit			= prty->uplimit;
	(element_addr)->prty.downlimit			= prty->downlimit;

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_GetPrtyTreeElmACTaddr(void** elementaddr, void* prty_in)
{
	Cprty_tree_node** element_addr = (Cprty_tree_node**)elementaddr;
	PRMPRTY*prty = (PRMPRTY*)prty_in;

	prty->memberType						= (*element_addr)->prty.memberType;
	prty->memberName						= (*element_addr)->prty.memberName;
	prty->parent							= (*element_addr)->prty.parent;
	prty->unit								= (*element_addr)->prty.unit;
	prty->introduction						= (*element_addr)->prty.introduction;
	prty->uplimit							= (*element_addr)->prty.uplimit;
	prty->downlimit							= (*element_addr)->prty.downlimit;

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_GetPrtyTreeElmACTname(wstring& element_name, void* prty_in)
{
	//首先查找到该地址
	PRMPRTY* prty = (PRMPRTY*)prty_in;
	Cprty_tree_node* element_addr = NULL;
	SDM_FindPrtyTreeElement(element_name, (void**)(&element_addr));

	prty->memberType						= (element_addr)->prty.memberType;
	prty->memberName						= (element_addr)->prty.memberName;
	prty->parent							= (element_addr)->prty.parent;
	prty->unit								= (element_addr)->prty.unit;
	prty->introduction						= (element_addr)->prty.introduction;
	prty->uplimit							= (element_addr)->prty.uplimit;
	prty->downlimit							= (element_addr)->prty.downlimit;

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_ReadPrmXml(wstring& xmlfilepath)
{
	g_xml->loadPrmTree(xmlfilepath,&(g_prm_tree->prmFile_node));
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_ReadOldPrmXml(wstring& xmlfilepath)
{
	g_xml->loadPrmTree(xmlfilepath, &(g_prm_tree->prmFile_old_node));
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_PrmCompareUpdate()
{
	g_prm_tree->UpdateNewPrmFileTree();
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_WritePrmXml(wstring& filepathT, wstring& xmlfilepath)
{
	wstring templateFileName = L"\\template.xml";
	wstring templateFilePath = filepathT + templateFileName;
	g_prm_tree->splitPrmFileTreeNode2Level(g_buildPrmRelation->PrmLevelNum+1);
	g_xml->saveFramPrmTreeAll(templateFilePath, xmlfilepath, g_prm_tree->prmFile_TreeList, &(g_prm_tree->prmFile_node), g_parseHfile->AxisNumDefine);

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_WriteOldPrmXml(wstring& filepathT, wstring& xmlfilepath)
{
	wstring templateFileName = L"\\template.xml";
	wstring templateFilePath = filepathT + templateFileName;
	//因为更新后的node在下一次的时候就会变成旧的，所以这里新的和旧的文件都是写的新更新的node
	g_xml->saveFramPrmTreeAll(templateFilePath, xmlfilepath, g_prm_tree->prmFile_TreeList, &(g_prm_tree->prmFile_node), g_parseHfile->AxisNumDefine);
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_GetXmlDirName(wstring& xmlDirName)
{
	g_parseHfile->GetVersionString(xmlDirName);
	CreateDirectory((xmlDirName.c_str()), NULL);
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_WriteDirectoryIniFile(wstring& fileName, inputDirectory& dir)
{
	int16 rtn;
	rtn = WriteIniDirectoryFile(fileName, dir);
	return rtn;
}

SERVODRIVERMANAGERDLL_API int16 SDM_ReadDirectoryIniFile(wstring& fileName, inputDirectory* dir)
{
	int16 rtn;
	rtn = ReadIniDirectoryFile(fileName, dir);
	return rtn;
}
