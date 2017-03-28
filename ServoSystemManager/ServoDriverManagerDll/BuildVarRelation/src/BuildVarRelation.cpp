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
	//��ɾ��һ��
	for (int16 i = 1; i < g_parseHfile->AxisNumDefine; i++)
	{
		delete[] VarStLevelListAxis[i - 1];
		VarStLevelListAxis[i - 1] = NULL;
	}
	//��ɾ������
	delete[] VarStLevelListAxis;
	VarStLevelListAxis = NULL;


}

void CBuildVarRelation::BuildVarList(void)
{
	SetRoot();										//���ø�Ԫ��
	FindChildNode(root, root.childNum);				//�����ҵ��ӽڵ�
	VarStList->push_back(root);

	//��һ����
	SetRootAux();
	FindChildNode(root_aux, root_aux.childNum);		//�����ҵ��ӽڵ�
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

	//�������ǽṹ����������
	if ((it_s != g_parseHfile->Structmap.end()) && (it_a != g_parseHfile->Arraymap.end()))
	{
		wstring number;
		//��ȡ������һ��Ԫ�أ���Ϊ��Ԫ��Ϊ�ṹ�壬�����ٽ���һ�νṹ��
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

			//��ϳ�Ա������
			tmp.memberName = parent.memberName.substr(0, fcindexbrace) + L"[" + strtmp + L"]";
			//tmp.memberName		= parent.memberName + L"[" + strtmp + L"]";
			//���������еĴ��к궨������飬����к궨�壬��Ҫ�����еĺ껻������
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

			//��Ϊ�ṹ��������ʱû��bit��������ʱ��������
			tmp.addressOffset	= 0;
			tmp.isBits			= false;
			tmp.bitWidth		= -1;
			tmp.bitStart		= -1;
			tmp.hasChild		= true; //��Ϊ�����ǽṹ�壬����һ����child

			//����Ԫ���ǽṹ�壬��������Ҫ�ٽ���ṹ��
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
			tmp.bitWidth		= -1;//union����Ҳû��bit���ݲ�����
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
			tmp.memberName		= parent.memberName.substr(0, fcindexbrace) + L"[" + strtmp + L"]";	//��ϳ�Ա������
			//tmp.memberName		= parent.memberName + L"[" + strtmp + L"]";
			//���������еĴ��к궨������飬����к궨�壬��Ҫ�����еĺ껻������
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
			tmp.bitWidth			= -1;//������Ҳû��bit����ʱ������
			tmp.bitStart			= -1;
			tmp.hasChild			= false;//���˽ṹ�����飬���������е�Ԫ��Ҳ��û��child ���ݲ�����
			tmp.childNum			= 0;
			tmp.value				= L"0";
			VarStList->push_back(tmp);
			i++;
		}
		rt_childNum					= i; //���鷵����Ԫ�ظ���
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
	//�������ƫ�ã�Ϊ�˸��ڶ�����ƫ��
	file << L"" << endl;
	file << L"  //axis offset" << endl;
	file << L"	  fprintf(fp,\"%s \\t\\n\",\"axis offset start\");" << endl;

	//�������ʵ�ʵ�����������ӡ�������ƫ�ã������ҵ����ڵ�һ�����ƫ�ã�Ȼ�������ƫ�û������ټ��ϵ�һ���ƫ��
	//��������б仯��ֻ��Ҫ���ĺ궨�弴��
	file << L"  for (i = 1; i < SERVO_AXIS_NUM; i++)" << endl;
	file << L"  {" << endl;
	file << L"  fprintf(fp,\"%s%d \\t\\n\",\"axis\",i);" << endl;
	//��������ģ��֮��Ĳ�ֵ
	file << L"" << endl;
	file << L"	  tmp = ((unsigned int)(&(gSevDrv.sev_chd[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_chd[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gSevDrv.sev_chd[),i,\"]\",VNAME(gSevDrv.sev_chd[0]));" << endl;
	file << L"	  tmp = ((unsigned int)(&(gSevDrv.sev_task[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_task[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gSevDrv.sev_task[),i,\"]\",VNAME(gSevDrv.sev_task[0]));" << endl;
	file << L"	  tmp = ((unsigned int)(&(gSevDrv.sev_obj[i])) & 0xffffffff) - ((unsigned int)(&(gSevDrv.sev_obj[0])) & 0xffffffff); " << endl;
	file << L"	  fprintf(fp,\"0x%0 8x %6d    %s%d%s-%s \\t\\n\",tmp,tmp,VNAME(gSevDrv.sev_obj[),i,\"]\",VNAME(gSevDrv.sev_obj[0]));" << endl;
	//�������µĸ�ȫ�ֱ�����Ҫɨ���ʱ���ڴ�����
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
		//����û���ҵ�����ô���˳����֡�
		if (index == -1)
		{
			continue;
		}
		tmp = (*it_v).memberName.substr(index + 1);
		index1 = tmp.find_first_of(L".");
		//����û���ҵ�����ô���˳����֡�
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
			//������bitλ����ô����
			(*it).addressOffset = -1;
		}
		else
		{
			//����txt�ļ����б�Ӧ����һһ��Ӧ�ġ�
			getline(file, sr);
			vector<wstring> vec;
			splitStr(sr, vec);
			int32 ofst;
			wstringstream ss;
			ss << vec[1];
			ss >> ofst;
			(*it).addressOffset = ofst;
			index++;
			////�������ӽڵ㣬��ô���øõ�ַƫ��Ϊ-1
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
			//�õ����ĸ����
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
		//����һ��������ݸ�ֵ���µ���
		VarStListAxis[i - 1] = *VarStList;
		for (list<VARST>::iterator it = VarStListAxis[i - 1].begin(); VarStListAxis[i - 1].end() != it; it++)
		{
			//�������
			(*it).axisNum = (int16)i;
			if (((*it).isBits) /*|| ((*it).hasChild)*/)
			{
				//������bit������Ҫ����offset
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
				//ֻ����һ������Ҫ����
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
		//�ҵ����С�.���ĸ���
		splitDotStr((*it).memberName, vec);

		//����vec�еĳ��ȴ���level����ô�͸�ֵ��level
		if (vec.size() > (Uint16)level)
		{
			level = vec.size();
		}
	}

	//level,��Ϊ�����д����xxxxx.dpos_buf[8],xxxxx.dpos_buf[0]...��Ȼxxxxx.dpos_buf[8]��xxxxx.dpos_buf[0]��һ���ģ�����ȷ�Ǹ��ӹ�ϵ�����Ե����������ʱ����Ҫ��һ
	level = level + 1;

	//��Ϊÿ����ֻ��һ����������������ӵ�����ʵ�����ǵڶ��㣬��һ����Զ����
	level = level + 1;

	//�洢��״�ṹ�����б���
	VarStLevelList = new list<VARST>[level];

	//�洢���������״�ṹ���б���ָ�룬[AllAxisNum - 1]��ָ��
	VarStLevelListAxis = new list<VARST>*[sAxisNum - 1];
	for (int32 j = 0; j < sAxisNum - 1; j++)
	{
		//ÿ��ָ�������level��
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
	
	//�ж��Ƿ�����б�������ȫ��
	int32 varnumber = 0;
	for (int32 j = 0; j < level; j++)
	{
		varnumber += VarStLevelList[j].size();
	}

	if (varnumber != (VarStList->size()+1))
	{
		return 1;
	}

	//�������������״�ṹ

	for (int32 j = 1; j < sAxisNum; j++)
	{
		for (int32 k = 0; k < level; k++)
		{
			VarStLevelListAxis[j - 1][k].clear();
		}
		//�������
		constRoot.axisNum = (int16)j;
		VarStLevelListAxis[j - 1][0].push_back(constRoot);

		//�������
		root.axisNum = (int16)j;
		VarStLevelListAxis[j - 1][1].push_back(root);

		//������һ�����ڵ�
		root_aux.axisNum = (int16)j;
		VarStLevelListAxis[j - 1][1].push_back(root_aux);

		//�ָ����
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
