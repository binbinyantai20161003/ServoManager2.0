//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	build var relationship accoring to the parsed file message	//
//	file				:	BuildVarRelation.cpp										//
//	Description			:	use for build var relationship								//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
using namespace std;

#include "BuildVarRelation.h"
#include "ParseFile.h"
#include "StringHandler.h"
//////////////////////////////////////////////////////////////////////////
CBuildVarRelation* g_buildVarRelation = NULL;

CBuildVarRelation::CBuildVarRelation()
{
	VarStList = new list<VARST>;
	
}

CBuildVarRelation::~CBuildVarRelation()
{
	delete		VarStList;								VarStList = NULL;
	delete[]	axis_ofst;								axis_ofst = NULL;
	delete[]	VarStListAxis;							VarStListAxis = NULL;
	delete[]    VarStLevelList;							VarStLevelList = NULL;
	//先删除一级
	for (int16 i = 1; i < g_parseHfile->AxisNumDefine; i++)
	{
		delete[] VarStLevelListAxis[i - 1];
		VarStLevelListAxis[i - 1] = NULL;
	}
	//再删除二级
	delete[] VarStLevelListAxis;
	VarStLevelListAxis = NULL;


}

void CBuildVarRelation::BuildVarList(void)
{
	SetRoot();										//设置根元素
	FindChildNode(root, root.childNum);				//迭代找到子节点
	VarStList->push_back(root);

	//另一个根
	SetRootAux();
	FindChildNode(root_aux, root_aux.childNum);		//迭代找到子节点
	VarStList->push_back(root_aux);
}

void CBuildVarRelation::initVar(void)
{
	axis_ofst		= new AXIS_ADDR_OFST[g_parseHfile->AxisNumDefine - 1];
	VarStListAxis	= new list<VARST>[g_parseHfile->AxisNumDefine - 1];
}

void CBuildVarRelation::SetRoot(void)
{
	root.axisNum		= 0;
	root.memberType		= L"SERVO_DRV";
	root.memberName		= L"gSevDrv";
	root.parent			= L"SevDrvRoot";
	root.addressOffset	= -1;
	root.hasChild		= true;
	root.childNum		= 3;
	root.isBits			= false;
	root.bitWidth		= -1;	
	root.bitStart		= -1;
	root.value			= L"NULL";
}

void CBuildVarRelation::SetRootAux(void)
{
	root_aux.axisNum		= 0;
	root_aux.memberType		= L"AUX_FUNC";
	root_aux.memberName		= L"gAuxFunc";
	root_aux.parent			= L"SevDrvRoot";
	root_aux.addressOffset	= -1;
	root_aux.hasChild		= true;
	root_aux.childNum		= 2;
	root_aux.isBits			= false;
	root_aux.bitWidth		= -1;
	root_aux.bitStart		= -1;
	root_aux.value			= L"NULL";
}

void CBuildVarRelation::SetConstRoot(void)
{
	constRoot.axisNum = 0;
	constRoot.memberType = L"int16";
	constRoot.memberName = L"SevDrvRoot";
	constRoot.parent = L"SevDrvRoot";
	constRoot.addressOffset = -1;
	constRoot.hasChild = true;
	constRoot.childNum = 2;
	constRoot.isBits = false;
	constRoot.bitWidth = -1;
	constRoot.bitStart = -1;
	constRoot.value = L"NULL";
}

void CBuildVarRelation::FindChildNode(VARST& parent, int16& rt_childNum)
{
	wstring		fcst;
	int32		fcindex;
	int32       fcindexbrace;
	VARST   parent_tmp = parent;
	fcindexbrace = parent_tmp.memberName.find_last_of(L"[");
	//fcindexbrace1	= parent_tmp.memberName.find_last_of(L"]");
	fcindex = parent_tmp.memberName.find_last_of(L".");
	if (fcindex == -1)
	{
		fcst = L"";
	}
	else
	{
		fcst = parent_tmp.memberName.erase(0, fcindex + 1);
	}
	map<wstring, list<STRUCTMEM>>::iterator it_s	= g_parseHfile->Structmap.find(parent.memberType);
	map<wstring, list<UNIONMEM>>::iterator it_u		= g_parseHfile->Unionmap.find(parent.memberType);
	map<wstring, ARRAYLIST>	::iterator it_a			= g_parseHfile->Arraymap.find(fcst);

	//假如又是结构体又是数组
	if ((it_s != g_parseHfile->Structmap.end()) && (it_a != g_parseHfile->Arraymap.end()))
	{
		wstring number;
		//先取数组中一个元素，因为该元素为结构体，所以再进行一次结构体
		int16 i = 0;
		for (list<ARRAYMEM>::iterator it_list = g_parseHfile->Arraymap[fcst].alist.begin(); g_parseHfile->Arraymap[fcst].alist.end() != it_list; it_list++)
		{
			wstring strtmp;
			wstringstream ss;
			ss << i;
			ss >> strtmp;
			VARST tmp;
			tmp.axisNum = 0;
			tmp.memberType = (*it_list).memberType;

			//组合成员的名字
			tmp.memberName = parent.memberName.substr(0, fcindexbrace) + L"[" + strtmp + L"]";
			//tmp.memberName		= parent.memberName + L"[" + strtmp + L"]";
			//查找数组中的带有宏定义的数组，如果有宏定义，需要将其中的宏换成数字
			map<wstring, int32>::iterator it;
			int32 fcindexbrace1, fcindexbrace2;
			wstring macro;
			fcindexbrace1 = parent_tmp.memberName.find_last_of(L"[");
			fcindexbrace2 = parent_tmp.memberName.find_last_of(L"]");
			macro = parent_tmp.memberName.substr(fcindexbrace1 + 1, fcindexbrace2 - fcindexbrace1 - 1);
			it = g_parseHfile->MacroDefine.find(macro);

			if (it != g_parseHfile->MacroDefine.end())
			{
				wstringstream wss;
				wss << it->second;
				wss >> number;
				tmp.parent = parent.memberName.substr(0, fcindexbrace) + L"[" + number + L"]";
			}
			else
			{
				tmp.parent = parent.memberName;
			}

			//因为结构体数组暂时没有bit。这里暂时不做处理。
			tmp.addressOffset	= 0;
			tmp.isBits			= false;
			tmp.bitWidth		= -1;
			tmp.bitStart		= -1;
			tmp.hasChild		= true; //因为本身是结构体，所以一定有child

			//数组元素是结构体，所以这里要再进入结构体
			for (list<STRUCTMEM>::iterator it_list = g_parseHfile->Structmap[parent.memberType].begin(); g_parseHfile->Structmap[parent.memberType].end() != it_list; it_list++)
			{
				VARST tmpst;
				tmpst.axisNum		  = 0;
				tmpst.memberType	  = (*it_list).memberType;
				tmpst.memberName    = parent.memberName.substr(0, fcindexbrace) + L"[" + strtmp + L"]" + L"." + (*it_list).memberName;
				tmpst.parent        = parent.memberName.substr(0, fcindexbrace) + L"[" + strtmp + L"]";
				tmpst.addressOffset = 0;
				tmpst.isBits		  = false;
				tmpst.bitWidth	  = (*it_list).bitWidth;
				tmpst.bitStart	  = (*it_list).bitStart;
				tmpst.value		  = L"0";
				if ((*it_list).bitWidth != -1)
				{
					tmpst.isBits = true;
				}
				tmpst.hasChild = false;
				tmpst.hasChild = CheckNode(tmpst);
				//if the mode has child then find the child,else add the node to the list DataMember
				if (tmpst.hasChild)
				{
					FindChildNode(tmpst, tmpst.childNum);
					VarStList->push_back(tmpst);
				}
				else
				{
					tmpst.childNum = 0;
					VarStList->push_back(tmpst);
				}
			}
			tmp.childNum = g_parseHfile->Structmap[parent.memberType].size();
			tmp.value = L"0";
			VarStList->push_back(tmp);
			i++;
		}
		parent.memberName = parent.memberName.substr(0, fcindexbrace) + L"[" + number + L"]";
		rt_childNum = i;
	}
	else if (it_s != g_parseHfile->Structmap.end())
	{
		for (list<STRUCTMEM>::iterator it_list = g_parseHfile->Structmap[parent.memberType].begin(); g_parseHfile->Structmap[parent.memberType].end() != it_list; it_list++)
		{
			VARST tmp;
			tmp.axisNum			= 0;
			tmp.memberType		= (*it_list).memberType;
			tmp.memberName		= parent.memberName + L"." + (*it_list).memberName;
			tmp.parent			= parent.memberName;
			tmp.addressOffset	= 0;
			tmp.isBits			= false;
			tmp.bitWidth		= (*it_list).bitWidth;
			tmp.bitStart		= (*it_list).bitStart;
			tmp.value			= L"0";
			if ((*it_list).bitWidth != -1)
			{
				tmp.isBits		= true;
			}
			tmp.hasChild = false;
			tmp.hasChild = CheckNode(tmp);
			//if the mode has child then find the child,else add the node to the list DataMember
			if (tmp.hasChild)
			{
				FindChildNode(tmp, tmp.childNum);
				VarStList->push_back(tmp);
			}
			else
			{
				tmp.childNum = 0;
				VarStList->push_back(tmp);
			}
		}
		rt_childNum = g_parseHfile->Structmap[parent.memberType].size();
	}
	else if (it_u != g_parseHfile->Unionmap.end())
	{
		for (list<UNIONMEM>::iterator it_list = g_parseHfile->Unionmap[parent.memberType].begin(); g_parseHfile->Unionmap[parent.memberType].end() != it_list; it_list++)
		{
			VARST tmp;
			tmp.axisNum			= 0;
			tmp.memberType		= (*it_list).memberType;
			tmp.memberName		= parent.memberName + L"." + (*it_list).memberName;
			tmp.parent			= parent.memberName;
			tmp.addressOffset	= 0;
			tmp.isBits			= false;
			tmp.bitWidth		= -1;//union里面也没有bit，暂不处理
			tmp.bitStart		= -1;
			tmp.hasChild		= false;
			tmp.hasChild		= CheckNode(tmp);
			tmp.value			= L"0";
			//if the mode has child then find the child,else add the node to the list DataMember
			if (tmp.hasChild)
			{
				FindChildNode(tmp, tmp.childNum);
				VarStList->push_back(tmp);
			}
			else
			{
				tmp.childNum = 0;
				VarStList->push_back(tmp);
			}
		}
		rt_childNum = g_parseHfile->Unionmap[parent.memberType].size();
	}
	else if (it_a != g_parseHfile->Arraymap.end())
	{
		wstring number;
		int16 i = 0;
		for (list<ARRAYMEM>::iterator it_list = g_parseHfile->Arraymap[fcst].alist.begin(); g_parseHfile->Arraymap[fcst].alist.end() != it_list; it_list++)
		{
			wstring strtmp;
			wstringstream ss;
			ss << i;
			ss >> strtmp;
			VARST tmp;
			tmp.axisNum			= 0;
			tmp.memberType		= (*it_list).memberType;	
			tmp.memberName		= parent.memberName.substr(0, fcindexbrace) + L"[" + strtmp + L"]";	//组合成员的名字
			//tmp.memberName		= parent.memberName + L"[" + strtmp + L"]";
			//查找数组中的带有宏定义的数组，如果有宏定义，需要将其中的宏换成数字
			map<wstring, int32>::iterator it;
			int32 fcindexbrace1, fcindexbrace2;
			wstring macro;
			fcindexbrace1		= parent_tmp.memberName.find_last_of(L"[");
			fcindexbrace2		= parent_tmp.memberName.find_last_of(L"]");
			macro				= parent_tmp.memberName.substr(fcindexbrace1 + 1, fcindexbrace2 - fcindexbrace1 - 1);
			it					= g_parseHfile->MacroDefine.find(macro);

			if (it != g_parseHfile->MacroDefine.end())
			{
				wstringstream wss;
				wss << it->second;
				wss >> number;
				tmp.parent			= parent.memberName.substr(0, fcindexbrace) + L"[" + number + L"]";
				parent.memberName	= parent.memberName.substr(0, fcindexbrace) + L"[" + number + L"]";
			}
			else
			{
				tmp.parent			= parent.memberName;
			}

			tmp.addressOffset		= 0;
			tmp.isBits				= false;
			tmp.bitWidth			= -1;//数组中也没有bit，暂时不处理
			tmp.bitStart			= -1;
			tmp.hasChild			= false;//除了结构体数组，其它数组中的元素也都没有child ，暂不处理
			tmp.childNum			= 0;
			tmp.value				= L"0";
			VarStList->push_back(tmp);
			i++;
		}
		rt_childNum					= i; //数组返回子元素个数
	}

}

bool CBuildVarRelation::CheckNode(VARST& node)
{
	//for array start
	wstring cnst;
	VARST   node_tmp = node;

	int cnindex;
	cnindex = node_tmp.memberName.find_last_of(L".");
	if (cnindex == -1)
	{
		cnst = L"";
	}
	else
	{
		cnst = node_tmp.memberName.erase(0, cnindex + 1);
	}
	//for array end

	map<wstring, list<STRUCTMEM>>::iterator it_s = g_parseHfile->Structmap.find(node.memberType);
	map<wstring, list<UNIONMEM>>::iterator it_u = g_parseHfile->Unionmap.find(node.memberType);
	map<wstring, ARRAYLIST>	::iterator it_a = g_parseHfile->Arraymap.find(cnst);
	if (it_s != g_parseHfile->Structmap.end())
	{
		node.hasChild = true;
	}
	else if (it_u != g_parseHfile->Unionmap.end())
	{
		node.hasChild = true;
	}
	else if (it_a != g_parseHfile->Arraymap.end())
	{
		node.hasChild = true;
	}
	else
	{
		node.hasChild = false;
	}
	return node.hasChild;
}

int16 CBuildVarRelation::WriteFileForIarVarAddress(list<VARST>& member)
{
	list<VARST> tmpMem = member;
	ChangeFormat(tmpMem);
	wstring key0 = L"gSevDrv";
	wstring key1 = L"gAuxFunc";
	wstring filepath = L"GetAddress.c";
	wfstream file;
	file.open(filepath.c_str(), ios::in | ios::out | ios::trunc);
	if (!file)
	{
		return -1;
	}
	file << L"#include \"SevObjMang.h\"" << endl;
	file << L"#include \"SevTaskSched.h\"" << endl;
	file << L"#include \"SevAuxFunc.h\"" << endl;
	file << L"#include <stdio.h>" << endl;
	file << L"#include <stdlib.h>" << endl;
	file << L"" << endl;
	file << L"#define VNAME(name) (#name)" << endl;
	file << L"" << endl;
	file << L"int writeAddressFile()" << endl;
	file << L"{" << endl;
	file << L"  unsigned int tmp;" << endl;
	file << L"  unsigned int i;" << endl;

	file << L"  FILE *fp;" << endl;
	file << L"  fp = fopen(\"Addr.txt\", \"w+\");" << endl;
	file << L"  if (NULL == fp)" << endl;
	file << L"  {" << endl;
	file << L"      return -1;" << endl;
	file << L"  }" << endl;
	for (list<VARST>::iterator it = tmpMem.begin(); tmpMem.end() != it; it++)
	{
		if ((*it).isBits)
		{
			//do nothing 
		}
		else
		{
			if (hasChildStr((*it).memberName, key0))
			{
				file << L"" << endl;
				file << L"  tmp = (((unsigned int)(&(" << (*it).memberName << L"))) & 0xffffffff) - ((unsigned int)(&gSevDrv) & 0xffffffff); " << endl;
				file << L"  fprintf(fp,\"0x%0 8x %6d    %s \\t\\n\",tmp,tmp,VNAME(" << (*it).memberName << L"));" << endl;
			}
			else if (hasChildStr((*it).memberName, key1))
			{
				file << L"" << endl;
				file << L"  tmp = (((unsigned int)(&(" << (*it).memberName << L"))) & 0xffffffff) - ((unsigned int)(&gAuxFunc) & 0xffffffff); " << endl;
				file << L"  fprintf(fp,\"0x%0 8x %6d    %s \\t\\n\",tmp,tmp,VNAME(" << (*it).memberName << L"));" << endl;
			}
			else
			{ }
		}
	}
	//设置轴的偏置，为了给第二轴做偏置
	file << L"" << endl;
	file << L"  //axis offset" << endl;
	file << L"	  fprintf(fp,\"%s \\t\\n\",\"axis offset start\");" << endl;

	//这里根据实际的轴数，来打印各个轴的偏置，首先找到基于第一个轴的偏置，然后在这个偏置基础上再加上第一轴的偏置
	//如果轴数有变化，只需要更改宏定义即可
	file << L"  for (i = 1; i < SERVO_AXIS_NUM; i++)" << endl;
	file << L"  {" << endl;
	file << L"  fprintf(fp,\"%s%d \\t\\n\",\"axis\",i);" << endl;
	//计算两个模块之间的差值
	file << L"" << endl;
	file << L"	  tmp = ((unsigned int)(&(gSevDrv.sev_chd[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_chd[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gSevDrv.sev_chd[),i,\"]\",VNAME(gSevDrv.sev_chd[0]));" << endl;
	file << L"	  tmp = ((unsigned int)(&(gSevDrv.sev_task[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_task[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gSevDrv.sev_task[),i,\"]\",VNAME(gSevDrv.sev_task[0]));" << endl;
	file << L"	  tmp = ((unsigned int)(&(gSevDrv.sev_obj[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_obj[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gSevDrv.sev_obj[),i,\"]\",VNAME(gSevDrv.sev_obj[0]));" << endl;
	//当增加新的根全局变量需要扫描的时候，在此增加
	file << L"	  tmp = ((unsigned int)(&(gAuxFunc.aux_prm[i])) & 0xffffffff) - ((unsigned int)(&(gAuxFunc.aux_prm[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gAuxFunc.aux_prm[),i,\"]\",VNAME(gAuxFunc.aux_prm[0]));" << endl;
	file << L"	  tmp = ((unsigned int)(&(gAuxFunc.aux_log[i])) & 0xffffffff) - ((unsigned int)(&(gAuxFunc.aux_log[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gAuxFunc.aux_log[),i,\"]\",VNAME(gAuxFunc.aux_log[0]));" << endl;
	file << L"" << endl;
	file << L"  }" << endl;
	file << L"  fprintf(fp,\"%s \\t\\n\",\"axis offset end\");" << endl;

	file << L"" << endl;
	file << L"  fclose(fp);" << endl;
	file << L"" << endl;
	file << L"  return 0;" << endl;
	file << L"}" << endl;
	file.close();
	return 0;
}

int16 CBuildVarRelation::ChangeFormat(list<VARST>& list_c)
{
	wstring tmp;
	int16 index, index1;
	wstring chg = L"->";
	for (list<VARST>::iterator it_v = list_c.begin(); list_c.end() != it_v; it_v++)
	{
		index = (*it_v).memberName.find_first_of(L".");
		//假如没有找到，那么就退出该轮。
		if (index == -1)
		{
			continue;
		}
		tmp = (*it_v).memberName.substr(index + 1);
		index1 = tmp.find_first_of(L".");
		//假如没有找到，那么就退出该轮。
		if (index1 == -1)
		{
			continue;
		}
		index += index1;
		(*it_v).memberName.replace(index + 1, 1, chg);
	}
	return 0;
}

int16 CBuildVarRelation::UpdateVarAddrOfst(wstring& filepath, list<VARST>& member, int16 sAxisNum)
{
	wfstream file;
	file.open(filepath.c_str(), ios::in);
	if (!file)
	{
		return -1;
	}
	int32 index = 0;
	wstring sr;
	for (list<VARST>::iterator it = member.begin(); it != member.end(); it++)
	{
		if ((*it).isBits)
		{
			//假如是bit位，那么跳过
			(*it).addressOffset = -1;
		}
		else
		{
			//否则txt文件和列表应该是一一对应的。
			getline(file, sr);
			vector<wstring> vec;
			splitStr(sr, vec);
			int32 ofst;
			wstringstream ss;
			ss << vec[1];
			ss >> ofst;
			(*it).addressOffset = ofst;
			index++;
			////假如有子节点，那么设置该地址偏移为-1
			//if ((*it).hasChild)
			//{
			//	(*it).addressOffset = -1;
			//}
		}
	}
	getline(file, sr);
	int16 changeline;
	changeline = sr.find_first_of(L"\t");
	wstring cl;
	cl = sr.substr(0, changeline);
	cl = trim(cl);
	if (cl == L"axis offset start")
	{
		for (int i = 1; i < sAxisNum; i++)
		{
			//得到是哪个轴的
			getline(file, sr);
			int16 index1;
			wstring tmp;
			index1 = sr.find(L"axis");
			tmp = sr.erase(0, index1 + 4);
			int16 axis;
			wstringstream ss;
			ss << tmp;
			ss >> axis;
			axis_ofst[i - 1].axis = axis;

			getline(file, sr);
			vector<wstring> vec1;
			splitStr(sr, vec1);
			int32 ofst;
			wstringstream ss1;
			ss1 << vec1[1];
			ss1 >> ofst;
			axis_ofst[i - 1].sev_chd_ofst = ofst;

			getline(file, sr);
			vector<wstring> vec2;
			splitStr(sr, vec2);
			wstringstream ss2;
			ss2 << vec2[1];
			ss2 >> ofst;
			axis_ofst[i - 1].sev_task_ofst = ofst;

			getline(file, sr);
			vector<wstring> vec3;
			splitStr(sr, vec3);
			wstringstream ss3;
			ss3 << vec3[1];
			ss3 >> ofst;
			axis_ofst[i - 1].sev_obj_ofst = ofst;

			getline(file, sr);
			vector<wstring> vec4;
			splitStr(sr, vec4);
			wstringstream ss4;
			ss4 << vec4[1];
			ss4 >> ofst;
			axis_ofst[i - 1].aux_prm = ofst;

			getline(file, sr);
			vector<wstring> vec5;
			splitStr(sr, vec5);
			wstringstream ss5;
			ss5 << vec5[1];
			ss5 >> ofst;
			axis_ofst[i - 1].aux_log = ofst;
		}
	}
	else
	{
		return -2;
	}

	getline(file, sr);
	changeline = sr.find_first_of(L"\t");
	cl = sr.substr(0, changeline);
	cl = trim(cl);
	if (cl != L"axis offset end")
	{
		return -3;
	}

	return 0;
}
//////////////////////////////////////////////////////////////////////////
int16 CBuildVarRelation::UpdateVarAddrOfstAxis(int16 sAxisNum)
{
	for (int32 i = 1; i < sAxisNum; i++)
	{
		//将第一个轴的数据赋值给新的轴
		VarStListAxis[i - 1] = *VarStList;
		for (list<VARST>::iterator it = VarStListAxis[i - 1].begin(); VarStListAxis[i - 1].end() != it; it++)
		{
			//更新轴号
			(*it).axisNum = (int16)i;
			if (((*it).isBits) /*|| ((*it).hasChild)*/)
			{
				//假如是bit，不需要计算offset
			}
			else if (hasChildStr((*it).memberName, (wstring)(L"sev_chd")))
			{
				(*it).addressOffset = (*it).addressOffset + axis_ofst[i - 1].sev_chd_ofst;
			}
			else if (hasChildStr((*it).memberName, (wstring)(L"sev_task")))
			{
				(*it).addressOffset = (*it).addressOffset + axis_ofst[i - 1].sev_task_ofst;
			}
			else if (hasChildStr((*it).memberName, (wstring)(L"sev_obj")))
			{
				(*it).addressOffset = (*it).addressOffset + axis_ofst[i - 1].sev_obj_ofst;
			}
			else if (hasChildStr((*it).memberName, (wstring)(L"aux_prm")))
			{
				(*it).addressOffset = (*it).addressOffset + axis_ofst[i - 1].aux_prm;
			}
			else if (hasChildStr((*it).memberName, (wstring)(L"aux_log")))
			{
				(*it).addressOffset = (*it).addressOffset + axis_ofst[i - 1].aux_log;
			}
			else if ((*it).memberName == L"gSevDrv")
			{
				//只有这一个不需要处理
			}
			else if ((*it).memberName == L"gAuxFunc")
			{
			}
			else
			{
				return -1;
			}
		}
	}
	return 0;
}

int16 CBuildVarRelation::FindVarLevelNum( int16 sAxisNum )
{
	vector<wstring> vec;
	int16 level = 0;
	for (list<VARST>::iterator it = VarStList->begin(); VarStList->end() != it; it++)
	{
		vec.clear();
		//找到其中“.”的个数
		splitDotStr((*it).memberName, vec);

		//假如vec中的长度大于level，那么就赋值给level
		if (vec.size() > (Uint16)level)
		{
			level = vec.size();
		}
	}

	//level,因为数组的写法是xxxxx.dpos_buf[8],xxxxx.dpos_buf[0]...虽然xxxxx.dpos_buf[8]和xxxxx.dpos_buf[0]是一级的，但是确是父子关系。所以当最后有括号时，需要加一
	level = level + 1;

	//因为每个轴只有一个主根，所以我添加的主根实际上是第二层，第一层永远不动
	level = level + 1;

	//存储树状结构的所有变量
	VarStLevelList = new list<VARST>[level];

	//存储其它轴的树状结构所有变量指针，[AllAxisNum - 1]个指针
	VarStLevelListAxis = new list<VARST>*[sAxisNum - 1];
	for (int32 j = 0; j < sAxisNum - 1; j++)
	{
		//每个指针里面分level层
		VarStLevelListAxis[j] = new list<VARST>[level];
	}

	SetConstRoot();

	return level;
}

int16 CBuildVarRelation::SplitVarLevel(int16 level, int16 sAxisNum)
{
	for (int32 j = 0; j < level; j++)
	{
		VarStLevelList[j].clear();
	}

	VarStLevelList[0].push_back(constRoot);

	VarStLevelList[1].push_back(root);
	VarStLevelList[1].push_back(root_aux);

	for (int32 i = 1; i < (level - 1); i++)
	{
		for (list<VARST>::iterator itlevel = VarStLevelList[i].begin(); VarStLevelList[i].end() != itlevel; itlevel++)
		{
			for (list<VARST>::iterator it = VarStList->begin(); VarStList->end() != it; it++)
			{
				if ((*it).parent == (*itlevel).memberName)
				{
					VarStLevelList[i + 1].push_back((*it));
				}
			}
		}
	}
	
	//判断是否把所有变量都找全。
	int32 varnumber = 0;
	for (int32 j = 0; j < level; j++)
	{
		varnumber += VarStLevelList[j].size();
	}

	if (varnumber != (VarStList->size()+1))
	{
		return 1;
	}

	//计算其它轴的树状结构

	for (int32 j = 1; j < sAxisNum; j++)
	{
		for (int32 k = 0; k < level; k++)
		{
			VarStLevelListAxis[j - 1][k].clear();
		}
		//设置轴号
		constRoot.axisNum = (int16)j;
		VarStLevelListAxis[j - 1][0].push_back(constRoot);

		//设置轴号
		root.axisNum = (int16)j;
		VarStLevelListAxis[j - 1][1].push_back(root);

		//增加另一个根节点
		root_aux.axisNum = (int16)j;
		VarStLevelListAxis[j - 1][1].push_back(root_aux);

		//恢复轴号
		constRoot.axisNum	= 0;
		root.axisNum		= 0;
		root_aux.axisNum	= 0;

		for (int32 i = 1; i < (level - 1); i++)
		{
			for (list<VARST>::iterator itlevel = VarStLevelListAxis[j - 1][i].begin(); VarStLevelListAxis[j - 1][i].end() != itlevel; itlevel++)
			{
				for (list<VARST>::iterator it = VarStListAxis[j - 1].begin(); VarStListAxis[j - 1].end() != it; it++)
				{
					if ((*it).parent == (*itlevel).memberName)
					{
						VarStLevelListAxis[j - 1][i + 1].push_back((*it));
					}
				}
			}
		}
	}


	return 0;
}

int16 CBuildVarRelation::GetUserWave(list<VARST>* var, list<VARST>* varAxis)
{
	//bool isfind = false;
	//USER_WAVE tmp;
	//tmp.chineseName =
	//tmp.englishName =
	//userWaveMap.insert(make_pair(isfind, tmp));
	return 0;
}
