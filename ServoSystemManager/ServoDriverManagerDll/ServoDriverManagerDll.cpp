// ServoDriverManagerDll.cpp : ���� DLL Ӧ�ó���ĵ���������
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

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ����ͷ�ļ�...."));

	//�Ӹ�·����Ŀ¼���ҵ����е�ͷ�ļ�
	g_sco->findHeaderfile(g_sco,Scanfilepath, filename);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("����ͷ�ļ����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼɾ������Ҫɨ����ļ�...."));

	//ɾ��һЩ����Ҫɨ����ļ����Ч��
	g_sco->eraseHeaderfile((wstring)(L"DspCpu.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"FunLutTbl.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"VirFloatMath.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"ServoApp.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"Kernel.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"HalResource.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"BackGround.h"), filename);
	g_sco->eraseHeaderfile((wstring)(L"SevAuxTaskSched.h"), filename);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("ɾ������Ҫɨ����ļ�����...."));


	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼɨ��ͷ�ļ��ṹ...."));

	//��ȡͷ�ļ��е���Ϣ�����Ӧ�Ľṹ��
	g_parseHfile->ParseAllHFile(filename);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("ɨ��ͷ�ļ��ṹ���...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ��ɨ��Ľṹ�������ӹ�ϵ...."));

	g_buildVarRelation->initVar();
	//����������var list�ṹ
	g_buildVarRelation->BuildVarList();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ɨ��Ľṹ�������ӹ�ϵ����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼд��Ϣ��GetAddress.c�ļ���...."));

	//д��IAR�ܹ�ʶ����ļ���Ȼ�������IAR����
	g_buildVarRelation->WriteFileForIarVarAddress(*(g_buildVarRelation->VarStList));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("д��Ϣ��GetAddress.c�ļ��н���...."));

	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_IAR2VS(wstring& Addrfilepath, wstring& xmlfilepath, int16& devAxisNum)
{
	//////////////////////////////////////////////////////////////////////////
	
	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ����Addr.txt�ļ�����ram��ַ...."));
	
	//��ȡ����IAR���벢�Ҵ�ӡ���ĵ�ַƫ���ļ������ݸ��ļ����µ�ַƫ��
	g_buildVarRelation->UpdateVarAddrOfst(Addrfilepath, *(g_buildVarRelation->VarStList),g_parseHfile->AxisNumDefine);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("����Addr.txt�ļ�����ram��ַ����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ�����������ram��ַ...."));

	//�����������ƫ�Ƶ�ַ��������������ĵ�ַƫ��
	g_buildVarRelation->UpdateVarAddrOfstAxis(g_parseHfile->AxisNumDefine);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("�����������ram��ַ����...."));

	//////////////////////////////////////////////////////////////////////////
	g_buildPrmRelation->initPrm();
	wstring fpgaName = L".\\XmlFiles\\FpgaConfig.xml";
	wstring fpgaPath = fpgaName;

	wstring AuxName = L".\\XmlFiles\\GlobalConfig.xml";
	wstring AuxPath = AuxName;
	//wstring AuxPath = L"";

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ��ram����ȡ��������Ϣ����ȡ���Ա���Ϣ...."));

	//����������list���������˾������ԵĲ���list ���ڹ���ģ��
	g_buildPrmRelation->BuildPrmList(g_buildVarRelation, fpgaPath, AuxPath);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ram����ȡ��������Ϣ����ȡ���Ա���Ϣ����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ�Ӳ�����Ϣ����ȡģ����Ϣ...."));

	//�õ���������module
	g_buildPrmRelation->GetPrmChildModule();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("�Ӳ�����Ϣ����ȡģ����Ϣ����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("���²������е�offsetΪ�����з����ƫ��...."));

	//���²���all�����ofstΪ�����ofst
	g_buildPrmRelation->UpdatePrmFramAddrOfst();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("���²������е�offset����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("����������������е�offsetΪ�����з����ƫ��...."));

	//������һ����������е�ofst
	g_buildPrmRelation->UpdatePrmFramAddrOfstAxis(g_parseHfile->AxisNumDefine);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("����������������е�offset����...."));


	//////////////////////////////////////////////////////////////////////////
	//��ȡ�û�����
	//_tcprintf_s(_T("%s \r\n\r\n"), _T("��ȡ�û���ʾ������...."));

	//_tcprintf_s(_T("%s \r\n\r\n"), _T("��ȡ�û���ʾ�����߽���...."));
	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ram��Ϣ���зּ�,�����ӡ...."));

	//��ȡ���б����ĵȼ�������������
	int16 level = g_buildVarRelation->FindVarLevelNum(g_parseHfile->AxisNumDefine);
	//�����б����ֿ��ȼ�������������
	g_buildVarRelation->SplitVarLevel(level, g_parseHfile->AxisNumDefine);
	g_buildVarRelation->VarLevelNum = level;

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ram��Ϣ���зּ�����...."));

	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��������Ϣ���зּ�,�����ӡ...."));

	//��ȡ�����ȼ�
	int16  levelprm = g_buildPrmRelation->FindPrmLevelNum(g_parseHfile->AxisNumDefine);
	//�����в����ֿ��ȼ�������������
	g_buildPrmRelation->SplitPrmLevel(levelprm,g_buildVarRelation,g_parseHfile->AxisNumDefine);
	g_buildPrmRelation->PrmLevelNum = levelprm;
	g_prty_tree->initVar(g_buildPrmRelation->PrmLevelNum);
	g_prm_tree->initVar(g_buildPrmRelation->PrmLevelNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��������Ϣ���зּ�����...."));

	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ���ݺ�׺��ȡ����ģ��...."));

	//�õ���������ģ�飬�������Ƶĺ�׺���ܵĵȼ�
	g_buildPrmRelation->GetPrmFuncList(g_parseHfile->funcModuleNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("���ݺ�׺��ȡ����ģ�����...."));

	//////////////////////////////////////////////////////////////////////////

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ���������ʼ���궨���ļ�...."));

	wstring macrofilename = L"\\PrmMacroDef.h";
	wstring macrofilepath = xmlfilepath + macrofilename;
	g_buildPrmRelation->PrintPrmMacroDefine(macrofilepath);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("���������ʼ���궨���ļ����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ����豸��������ļ�...."));

	wstring filePath,fileName;
	wstring templateFileName = L".\\XmlFiles\\template.xml";
	wstring templateFilePath = templateFileName;
	//����fram��ʹ�õĲ����ļ��������Ӧһ�������ļ�
	fileName = L"\\FlashPrm_AllAxis.xml";
	filePath = xmlfilepath + fileName;
	g_xml->saveFramPrmTree(templateFilePath, filePath, g_buildPrmRelation->PrmStLevelList, g_buildPrmRelation->PrmStLevelListAxis, levelprm,g_parseHfile->AxisNumDefine, devAxisNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("����豸��������ļ�����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ�������ṹ�����ļ�...."));

	//��״�ṹ�ĳ���ṹxml�ļ�
	fileName = L"\\PrmRAMAxis0.xml";
	filePath = xmlfilepath + fileName;
	g_xml->saveTree(templateFilePath,filePath, g_buildVarRelation->VarStLevelList, level);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("�������ṹ�����ļ�����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ�����������ļ�...."));

	//��״�ṹ�Ĳ���xml�ļ�
	fileName = L"\\PrmFlashAxis0.xml";
	filePath = xmlfilepath + fileName;
	g_xml->saveTree(templateFilePath, filePath, g_buildPrmRelation->PrmStLevelList, levelprm);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("�����������ļ�����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ���������ĳ���ṹ�ļ� �� �����ļ�...."));

	//���������״�ṹxml�ļ�������ṹ�Ͳ���
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
	_tcprintf_s(_T("%s \r\n\r\n"), _T("���������ĳ���ṹ�ļ� �� �����ļ� ����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ��������������...."));

	//�����������ֻ�в���������ֻ�������Եȣ���״�ṹxml
	filePath = (xmlfilepath) + L"\\PrmPrtyTree.xml";
	g_xml->savePrtyTree(templateFilePath, filePath, g_buildPrmRelation->PrmStLevelListPrty, levelprm);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("�����������������...."));


	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ�����������ģ���ļ�...."));

	//����ģ��xml�ļ�
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

	_tcprintf_s(_T("%s \r\n\r\n"), _T("�����������ģ���ļ�����...."));

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ���ram�ϳ��ļ���������ѡ��...."));

	//���������ram�ϳ�Ϊһ���ļ�
	fileName = L"\\RamPrm_AllAxis.xml";
	filePath = xmlfilepath + fileName;
	g_xml->savePlotRamTree(templateFilePath, filePath, g_buildVarRelation->VarStLevelList, g_buildVarRelation->VarStLevelListAxis, level, g_parseHfile->AxisNumDefine, devAxisNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("���ram�ϳ��ļ���������ѡ�����...."));

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
	//��Ϊ���º��node����һ�ε�ʱ��ͻ��ɾɵģ����������µĺ;ɵ��ļ�����д���¸��µ�node
	g_xml->savePrtyTree(templateFilePath, xmlfilepath, g_prty_tree->ptryTreeList, g_buildPrmRelation->PrmLevelNum);
	return 0;
}

SERVODRIVERMANAGERDLL_API int16 SDM_FindPrtyTreeElement(wstring& element_name, void** element_addr)
{
	Cprty_tree_node** elementaddr = (Cprty_tree_node**)element_addr;
	//���ȸ�����������ȡҪ������·��
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
	//���Ȳ��ҵ��õ�ַ
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
	//���Ȳ��ҵ��õ�ַ
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
	//��Ϊ���º��node����һ�ε�ʱ��ͻ��ɾɵģ����������µĺ;ɵ��ļ�����д���¸��µ�node
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
