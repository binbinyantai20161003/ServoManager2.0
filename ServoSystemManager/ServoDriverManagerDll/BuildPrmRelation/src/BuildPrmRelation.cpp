// GetPrmTreeListMessage.cpp : 定义 DLL 应用程序的导出函数。
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

#include "BuildVarRelation.h"
#include "ParseFile.h"
#include "StringHandler.h"
#include "BuildPrmRelation.h"
#include "PrtyCompare.h"
#include "PrmCompare.h"
#include "xml.h"

CBuildPrmRelation* g_buildPrmRelation = NULL;
//////////////////////////////////////////////////////////////////////////

bool PRMPRTY::operator==(const PrmPrty& pty)
{
	if (memberName == pty.memberName)
	{
		return true;
	}
	return false;
}

CBuildPrmRelation::CBuildPrmRelation()
{
	PrmStList			 = new list < VARST > ;
	PrmStListParent		 = new list < VARST > ;
	PrmStListAll		 = new list < VARST > ;
	PrmPrtyList			 = new list < PRMPRTY > ;  //和参数list不同，他存储的是属性，这些属性用于功能模块
	
	PrmStListChildModule = new list < VARST > ;//用于存储child模块,模块用于分割FRAM的地址


}

CBuildPrmRelation::~CBuildPrmRelation()
{
	delete		PrmStList;							PrmStList		= NULL;
	delete      PrmStListParent;					PrmStListParent = NULL;
	delete		PrmStListAll;						PrmStListAll	= NULL;
	delete		PrmPrtyList;						PrmPrtyList		= NULL;
	delete		PrmStListChildModule;				PrmStListChildModule = NULL;
	delete[]	PrmStListAllAxis;					PrmStListAllAxis = NULL;
	delete[]    PrmStLevelList;						PrmStLevelList = NULL;
	//////////////////////////////////////////////////////////////////////////
	//先删除一级
	for (int16 i = 1; i < g_parseHfile->AxisNumDefine; i++)
	{
		delete[] PrmStLevelListAxis[i - 1];			PrmStLevelListAxis[i - 1] = NULL;
		
	}
	//再删除二级
	delete[] PrmStLevelListAxis;					PrmStLevelListAxis = NULL;
	//////////////////////////////////////////////////////////////////////////

	delete[]    PrmStLevelListPrty;					PrmStLevelListPrty = NULL;
	delete[]	PrmFuncList;						PrmFuncList = NULL;
}

void CBuildPrmRelation::setRootProperty()
{
	//只是参数
	rootProperty.axisNum			= 0;
	rootProperty.memberName			= L"gSevDrv";
	rootProperty.memberType			= L"SERVO_DRV";
	rootProperty.parent				= L"SevDrvRoot";
	rootProperty.unit				= L"NULL";
	rootProperty.introduction		= L"伺服根元素";
	rootProperty.uplimit			= 0;
	rootProperty.downlimit			= 0;
	rootProperty.value				= 0;
	rootProperty.framAddr			= 0;
}

void CBuildPrmRelation::setAuxRootProperty(void)
{
	//只是参数
	auxrootProperty.axisNum			= 0;
	auxrootProperty.memberName		= L"gAuxFunc";
	auxrootProperty.memberType		= L"AUX_FUNC";
	auxrootProperty.parent			= L"SevDrvRoot";
	auxrootProperty.unit			= L"NULL";
	auxrootProperty.introduction	= L"伺服辅助根元素";
	auxrootProperty.uplimit			= 0;
	auxrootProperty.downlimit		= 0;
	auxrootProperty.value			= 0;
	auxrootProperty.framAddr		= 0;
}

void CBuildPrmRelation::setConstRootProperty(void)
{
	//只是参数
	constRootProperty.axisNum		= 0;
	constRootProperty.memberName	= L"SevDrvRoot";
	constRootProperty.memberType	= L"int16";
	constRootProperty.parent		= L"SevDrvRoot";
	constRootProperty.unit			= L"NULL";
	constRootProperty.introduction	= L"伺服驱动root元素";
	constRootProperty.uplimit		= 0;
	constRootProperty.downlimit		= 0;
	constRootProperty.value			= 0;
	constRootProperty.framAddr		= 0;
}

void CBuildPrmRelation::initPrm(void)
{
	PrmStListAllAxis = new list<VARST>[g_parseHfile->AxisNumDefine - 1];
}

int16 CBuildPrmRelation::BuildPrmList(CBuildVarRelation* var, wstring& FPGAfilename, wstring& Auxfilename)
{
	if (var == NULL)
	{
		return -1;
	}
	//设置特性根结点
	setRootProperty();
	setAuxRootProperty();

	wstring sr = L"prm";
	wstring sr1 = L".mot.";
	PRMPRTY tmp;
	for (list<VARST>::iterator itt = var->VarStList->begin(); var->VarStList->end() != itt; itt++)
	{
		//从整个list中找到prm相关的部分，放入prm的list中
		if ((hasChildStr((*itt).memberName, sr)) || (hasChildStr((*itt).memberName, sr1)))
		{
			PrmStList->push_back((*itt));
			tmp.axisNum			= (*itt).axisNum;
			tmp.memberType		= (*itt).memberType;
			tmp.memberName		= (*itt).memberName;
			tmp.parent			= (*itt).parent;
			tmp.unit			= L"NULL";
			tmp.introduction	= L"NULL";
			tmp.uplimit			= 0;
			tmp.downlimit		= 0;
			tmp.value			= 0;
			tmp.framAddr		= 0;
			PrmPrtyList->push_back(tmp);
		}
		else
		{
			//do nothing
		}
	}

	//根据找到的prmlist，从中查找其父，如果在prmlist中找到什么也不做，否则一直找到parent是root的值，如果有多个根，该方法也适用
	//找的过程中会找到重复的，那么只保留一份。
	bool find_flag = false;
	bool find_same = false;
	list<VARST>::iterator it;
	for (it = PrmStList->begin(); PrmStList->end() != it; it++)
	{
		for (list<VARST>::iterator it1 = PrmStList->begin(); PrmStList->end() != it1; it1++)
		{
			//假如在prmlist中找到了其父
			if ((*it).parent == (*it1).memberName)
			{
				find_flag = true;
				break;
				//do nothing
			}
		}
		//假如没找到，到VarStList中找
		if (!find_flag)
		{
			list<VARST>::iterator it2;
			wstring name;
			name = (*it).parent;
			wstring juststr;
			do
			{
				for (it2 = var->VarStList->begin(); var->VarStList->end() != it2; it2++)
				{
					//到VarStList中找，添加到PrmStListParent中，
					if (name == (*it2).memberName)
					{
						//检查list中是否有重复的值，如果有重复的就不添加
						if (PrmStListParent->size() != 0)
						{
							for (list<VARST>::iterator it3 = PrmStListParent->begin(); PrmStListParent->end() != it3; it3++)
							{
								if ((*it3).memberName == (*it2).memberName)
								{
									find_same = true;
									break;
								}
							}
							if (!find_same)
							{
								PrmStListParent->push_back(*it2);
							}
						}
						else
						{
							PrmStListParent->push_back(*it2);
						}
						break; //跳出for循环
					}
				}
				juststr = (*it2).parent;
				name = (*it2).parent;

				//假如在这一层找到相同的，那么其上面应该也已经找到了。跳出do while循环
				if (find_same)
				{
					find_same = false;
					break;
				}
			} while (juststr != L"SevDrvRoot");
		}
		find_flag = false;
	}
	//因为splice会将原来的list清空，所以这里设置两个暂态变量
	list<VARST> tmplist;
	for (list<VARST>::iterator iter = PrmStList->begin(); PrmStList->end() != iter; iter++)
	{
		tmplist.push_back((*iter));
	}
	//合并两个链表,
	list<VARST>::iterator mit;
	mit = PrmStListAll->begin();
	(*PrmStListAll).splice(mit, (tmplist));

	tmplist.clear();
	for (list<VARST>::iterator iter1 = PrmStListParent->begin(); PrmStListParent->end() != iter1; iter1++)
	{
		tmplist.push_back((*iter1));
	}
	mit = PrmStListAll->end();
	(*PrmStListAll).splice(mit, (tmplist));

	//将FPGA需要配置的部分放入所有参数list中。这部分需要分配fram地址
	tmplist.clear();
	g_xml->loadFpgaConfig(FPGAfilename, &tmplist);

	mit = PrmStListAll->end();
	(*PrmStListAll).splice(mit, (tmplist));

	if (Auxfilename != L"")
	{
		//将AUX辅助功能配置的部分放入所有参数list中。这部分需要分配fram地址
		tmplist.clear();
		g_xml->loadFpgaConfig(Auxfilename, &tmplist);
		mit = PrmStListAll->end();
		(*PrmStListAll).splice(mit, (tmplist));
	}

	return 0;
}

int16 CBuildPrmRelation::GetPrmChildModule(void)
{
	vector<wstring> vec;
	vector<wstring> vec1;
	wstring brace = L"[";
	wstring keyword = L"int";

	//记录迭代器的位置
	int16 it_cur_prm = 0;
	int16 it_cur_prm_index = 0;

	for (list<VARST>::iterator it = PrmStListAll->begin(); PrmStListAll->end() != it; it++)
	{
		vec.clear();
		splitDotStr((*it).memberName, vec);
		vec1.clear();
		splitDotStr((*it).parent, vec1);

		if (vec.size()<2)
		{
			continue;
		}

		//首先查找prm
		if ((vec[vec.size() - 1] == L"prm"))
		{
			PrmStListChildModule->push_back((*it));

			//记录迭代器增加
			it_cur_prm++;

			//记录cur.prm的位置，用于将mot插入到其后面，这样才能保证和程序顺序一致。
			if ((vec[vec.size() - 2] == L"cur"))
			{
				it_cur_prm_index = it_cur_prm;
			}
		}//然后查找mot
		else if ((vec[vec.size() - 1] == L"mot"))
		{
			list<VARST>::iterator j = PrmStListChildModule->begin();
			for (int16 i = 0; (i < it_cur_prm_index) && (j != PrmStListChildModule->end()); ++i)
			{
				++j;
			}

			PrmStListChildModule->insert(j, (*it));
		}//倒数第二是prm，并且倒数第一中含有括号，并且括号的类型还不能是int等类型,并且其父最后不能是prm 时才作为module ，因为数组使用的完全表达方式
		else if ((vec[vec.size() - 2] == L"prm") && (hasChildStr(vec[vec.size() - 1], brace)) && (!hasChildStr((*it).memberType, keyword)) && (vec1[vec1.size() - 1] != L"prm"))
		{
			PrmStListChildModule->push_back((*it));

			//通过查找父，得到该数组size
			int16 value_limit = 0;
			value_limit = getBraceValue(vec1[vec1.size() - 1]);
			//通过查找当前值，判断是否已经到该数组的size了
			int16 value_now = 0;
			value_now = getBraceValue(vec[vec.size() - 1]);

			if ((value_limit - value_now) == 1)
			{
				//生成预留个数为10的其它的数组元素，用于预留地址。
				while (value_limit < MODULE_CASCADE_FILTER_MAX)
				{
					//将数值转化为字符串
					wstringstream ss;
					wstring tmp;
					ss << value_limit;	//输入int
					ss >> tmp;			//int -> wstring

					//得到要更新的最后部分的字符串
					wstring newvalue = L"[" + tmp + L"]";

					//找到最后一个.的位置，去掉后面的值，加上新的值
					int16 pos_last_point;
					wstring point = L"[";
					pos_last_point = (*it).memberName.find_last_of(point.c_str());
					wstring str = (*it).memberName.substr(0, pos_last_point);
					newvalue = str + newvalue;

					//将新的名字的数组元素写入list
					VARST tmpvar;
					tmpvar = (*it);
					tmpvar.memberName = newvalue;
					PrmStListChildModule->push_back(tmpvar);
					value_limit++;
				}
			}
		}
		else if ((vec[vec.size() - 2] == L"gAuxFunc") && (vec[vec.size() - 1] == L"aux_prm")) //辅助功能特殊处理
		{
			PrmStListChildModule->push_back((*it));
		}
		else
		{

		}
	}
	return 0;
}

int16 CBuildPrmRelation::UpdatePrmFramAddrOfst(void)
{
	int32 tmp_cur_ofst_base		= MODULE_CUR_START_ADDR;
	int32 tmp_spd_ofst_base		= MODULE_SPD_START_ADDR;
	int32 tmp_pos_ofst_base		= MODULE_POS_START_ADDR;
	int32 tmp_aux_ofst_base		= MODULE_AUX_START_ADDR;
	int32 tmp_other_ofst_base	= MODULE_OTHER_START_ADDR;
	int32 tmp_fpga_ofst_base	= MODULE_FPGA_START_ADDR;
	int32 tmp_common_ofst_base  = MODULE_COMMON_START_ADDR; //公用区域，如果第一个轴的用完，接着使用第二个轴的。

	int32 tmp_cur_ofst			= tmp_cur_ofst_base;
	int32 tmp_spd_ofst			= tmp_spd_ofst_base;
	int32 tmp_pos_ofst			= tmp_pos_ofst_base;
	int32 tmp_aux_ofst			= tmp_aux_ofst_base;
	int32 tmp_other_ofst		= tmp_other_ofst_base;
	int32 tmp_fpga_ofst			= tmp_fpga_ofst_base;
	int32 tmp_common_ofst		= tmp_common_ofst_base;
	

	int16 tmp_cur_index			= 0;
	int16 tmp_spd_index			= 0;
	int16 tmp_pos_index			= 0;
	int16 tmp_fpga_index		= 0;
	int16 tmp_aux_index			= 0;
	int16 tmp_other_index		= 0;
	int16 tmp_common_index		= 0;

	int16 tmp_cur_flag			= 0;
	int16 tmp_spd_flag			= 0;
	int16 tmp_pos_flag			= 0;
	int16 tmp_fpga_flag			= 0;
	int16 tmp_aux_flag			= 0;
	int16 tmp_other_flag		= 0;
	int16 tmp_common_flag		= 0;

	int16 tmp_cur_enter_flag	= 0;
	int16 tmp_spd_enter_flag	= 0;
	int16 tmp_pos_enter_flag	= 0;
	int16 tmp_fpga_enter_flag	= 0;
	int16 tmp_aux_enter_flag	= 0;
	int16 tmp_other_enter_flag	= 0;
	int16 tmp_common_enter_flag = 0;

	wstring str_cur				= L".cur.";
	wstring str_spd				= L".vel.";
	wstring str_pos				= L".pos.";
	wstring str_fpga			= L"FPGA";
	wstring str_aux				= L"gAuxFunc";
	wstring str_common			= L"Global";

	int16 tmp_inc_fpga			= 0;
	int16 tmp_inc_common		= 0;
	//int16 tmp_inc_aux			= 0;

	vector<wstring> vec;
	wstring brace = L"[";

	vector<wstring> vec1;

	//外层为module，从all中找到parent是module的就计算ofst
	for (list<VARST>::iterator it = PrmStListChildModule->begin(); PrmStListChildModule->end() != it; it++)
	{
		//用于判断数组module
		vec.clear();
		splitDotStr((*it).memberName, vec);

		for (list<VARST>::iterator it_a = PrmStListAll->begin(); PrmStListAll->end() != it_a; it_a++)
		{
			//用于区分数组和正常值
			vec1.clear();
			splitDotStr((*it_a).memberName, vec1);
			if (vec1.size() < 2)
			{
				continue;
			}

			if (hasChildStr((*it).memberName, str_cur))
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是cur大类的

				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						if (tmp_cur_flag == 0)
						{
							tmp_cur_index++;
							tmp_cur_flag = 1;
						}
						(*it_a).addressOffset = tmp_cur_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//用于预留模块地址增加
						if (tmp_cur_flag == 0)
						{
							tmp_cur_index++;
							tmp_cur_flag = 1;
						}
					}
				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是cur大类的

					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						if (tmp_cur_flag == 0)
						{
							tmp_cur_index++;
							tmp_cur_flag = 1;
						}
						(*it_a).addressOffset = tmp_cur_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//do nothing
					}
				}
			}
			else if (hasChildStr((*it).memberName, str_spd))
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是spd大类的
				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						if (tmp_spd_flag == 0)
						{
							tmp_spd_index++;
							tmp_spd_flag = 1;
						}
						(*it_a).addressOffset = tmp_spd_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//用于预留模块地址增加
						if (tmp_spd_flag == 0)
						{
							tmp_spd_index++;
							tmp_spd_flag = 1;
						}
					}
				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是spd大类的
					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						if (tmp_spd_flag == 0)
						{
							tmp_spd_index++;
							tmp_spd_flag = 1;
						}
						(*it_a).addressOffset = tmp_spd_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//do nothing
					}
				}
			}
			else if (hasChildStr((*it).memberName, str_pos))
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是pos大类的

				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						if (tmp_pos_flag == 0)
						{
							tmp_pos_index++;
							tmp_pos_flag = 1;
						}
						(*it_a).addressOffset = tmp_pos_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//用于预留模块地址增加
						if (tmp_pos_flag == 0)
						{
							tmp_pos_index++;
							tmp_pos_flag = 1;
						}
					}
				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是pos大类的

					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						if (tmp_pos_flag == 0)
						{
							tmp_pos_index++;
							tmp_pos_flag = 1;
						}
						(*it_a).addressOffset = tmp_pos_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//do nothing
					}
				}
			}
			else if (hasChildStr((*it).memberName, str_fpga))
			{
				//FPGA部分不考虑数组的条件
				if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
				{
					if (tmp_fpga_flag == 0)
					{
						tmp_fpga_index++;
						tmp_fpga_flag = 1;
					}
					(*it_a).addressOffset = tmp_fpga_ofst + tmp_inc_fpga;
					tmp_inc_fpga++;
				}
				else
				{
					//do nothing
				}
				
			}
			else if (hasChildStr((*it).memberName, str_common))
			{
				//不考虑数组的条件
				if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
				{
					if (tmp_common_flag == 0)
					{
						tmp_common_index++;
						tmp_common_flag = 1;
					}
					(*it_a).addressOffset = tmp_common_ofst + tmp_inc_common;
					tmp_inc_common++;
				}
				else
				{
					//do nothing
				}

			}
			else if (hasChildStr((*it).memberName, str_aux))
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是aux大类的

				//不考虑数组的条件,参数名字包含这个父模块，并且本身没有子节点
				if (hasChildStr((*it_a).memberName, (*it).memberName) && ((*it_a).hasChild == false) && ((*it_a).isBits == false) && (!(hasChildStr(vec1[vec1.size() - 1], brace))))
				{
					if (tmp_aux_flag == 0)
					{
						tmp_aux_index++;
						tmp_aux_flag = 1;
					}
					(*it_a).addressOffset = tmp_aux_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);// tmp_inc_aux;
					//tmp_inc_aux++;
				}
				else if (hasChildStr((*it_a).memberName, (*it).memberName) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))
				{
					//针对没有child但是最后是数组的，因为数组和上面是联合体，所以，参数只需要定义一份
					(*it_a).addressOffset = -1;
				}
				else
				{
					//do nothing
				}
			}
			else
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是other大类的

				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						if (tmp_other_flag == 0)
						{
							tmp_other_index++;
							tmp_other_flag = 1;
						}
						(*it_a).addressOffset = tmp_other_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//用于预留模块地址增加
						if (tmp_other_flag == 0)
						{
							tmp_other_index++;
							tmp_other_flag = 1;
						}
					}
				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是other大类的

					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						if (tmp_other_flag == 0)
						{
							tmp_other_index++;
							tmp_other_flag = 1;
						}
						(*it_a).addressOffset = tmp_other_ofst + (((*it_a).addressOffset - (*it).addressOffset) >> 1);
					}
					else
					{
						//do nothing
					}
				}
			}
		}
		//复位，因为aux中有至少两个模块，所以新的模块开始的时候需要复位该变量。
		//tmp_inc_aux		= 0;

		//清空标志
		tmp_cur_flag	= 0;
		tmp_spd_flag	= 0;
		tmp_pos_flag	= 0;
		tmp_fpga_flag	= 0;
		tmp_aux_flag	= 0;
		tmp_other_flag	= 0;
		tmp_common_flag = 0;

		tmp_cur_ofst	= tmp_cur_ofst_base + (MODULE_CUR_STEP*tmp_cur_index);
		tmp_spd_ofst	= tmp_spd_ofst_base + (MODULE_SPD_STEP*tmp_spd_index);
		tmp_pos_ofst	= tmp_pos_ofst_base + (MODULE_POS_STEP*tmp_pos_index);
		tmp_fpga_ofst	= tmp_fpga_ofst_base + (MODULE_FPGA_STEP*tmp_fpga_index);
		tmp_aux_ofst	= tmp_aux_ofst_base + (MODULE_AUX_STEP*tmp_aux_index);
		tmp_other_ofst	= tmp_other_ofst_base + (MODULE_OTHER_STEP*tmp_other_index);
		tmp_common_ofst = tmp_common_ofst_base + (MODULE_COMMOM_STEP*tmp_common_index);
	}

	//将其它的偏移地址设置为-1，条件1：有child，条件2：没有child但是是bit位

	for (list<VARST>::iterator it_all = PrmStListAll->begin(); PrmStListAll->end() != it_all; it_all++)
	{
		if (((*it_all).hasChild == true) || (((*it_all).hasChild == false) && ((*it_all).isBits == true)))
		{
			(*it_all).addressOffset = -1;
			(*it_all).value = L"NULL";
		}
	}

	//将ram中的某些值的偏移改为-1
	for (list<VARST>::iterator it = g_buildVarRelation->VarStList->begin(); g_buildVarRelation->VarStList->end() != it; it++)
	{
		if (((*it).hasChild == true))
		{
			(*it).addressOffset = -1;
			(*it).value = L"NULL";
		}
	}
	for (list<VARST>::iterator it = g_buildVarRelation->VarStListAxis->begin(); g_buildVarRelation->VarStListAxis->end() != it; it++)
	{
		if (((*it).hasChild == true))
		{
			(*it).addressOffset = -1;
			(*it).value = L"NULL";
		}
	}

	return 0;
}

int16 CBuildPrmRelation::UpdatePrmFramAddrOfstAxis( int16 sAxisNum )
{
	//在其他轴中去掉全局部分，
	wstring tmp = L"Global";

	for (int16 i = 1; i < sAxisNum; i++)
	{
		//将第一个轴的数据赋值给新的轴
		PrmStListAllAxis[i - 1] = *PrmStListAll;
		for (list<VARST>::iterator it = PrmStListAllAxis[i - 1].begin(); PrmStListAllAxis[i - 1].end() != it; )
		{
			//更新轴号
			(*it).axisNum = (int16)i;

			if (hasChildStr((*it).memberName,tmp))
			{
				it = PrmStListAllAxis[i - 1].erase(it);
			}
			else
			{
				//更新ofst
				if ((*it).addressOffset != -1)
				{
					(*it).addressOffset = (*it).addressOffset + MODULE_AXIS_OFFSET;
				}
				else
				{
					(*it).addressOffset = (*it).addressOffset;
				}
				it++;
			}		
		}
	}
	return 0;
}

int16 CBuildPrmRelation::FindPrmLevelNum( int16 sAxisNum )
{
	vector<wstring> vec;
	int16 level = 0;
	for (list<VARST>::iterator it = PrmStListAll->begin(); PrmStListAll->end() != it; it++)
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

	//因为每个轴都只能有一个根，所以我增加的根节点相当于在第二层，第一层永远不会动
	level = level + 1;

	//存储树状结构的所有参数
	PrmStLevelList = new list<VARST>[level];

	//存储其它轴的树状结构参数指针，[AllAxisNum - 1]个指针
	PrmStLevelListAxis = new list<VARST>*[sAxisNum - 1];
	for (int16 j = 0; j < sAxisNum - 1; j++)
	{
		//每个指针里面分level层
		PrmStLevelListAxis[j] = new list<VARST>[level];
	}
	
	//存储特性的树状结构
	PrmStLevelListPrty = new list<PRMPRTY>[level];

	setConstRootProperty();

	return level;
}

int16 CBuildPrmRelation::SplitPrmLevel(int16 level, CBuildVarRelation* var, int16 sAxisNum)
{
	if (var == NULL)
	{
		return -1;
	}
	PRMPRTY tmp;
	for (int32 j = 0; j < level; j++)
	{
		PrmStLevelList[j].clear();
	}

	PrmStLevelList[0].push_back(var->constRoot);

	PrmStLevelList[1].push_back(var->root);
	PrmStLevelList[1].push_back(var->root_aux);

	PrmStLevelListPrty[0].push_back(constRootProperty);

	PrmStLevelListPrty[1].push_back(rootProperty);
	PrmStLevelListPrty[1].push_back(auxrootProperty);

	for (int32 i = 1; i < (level - 1); i++)
	{
		for (list<VARST>::iterator itlevel = PrmStLevelList[i].begin(); PrmStLevelList[i].end() != itlevel; itlevel++)
		{
			for (list<VARST>::iterator it = PrmStListAll->begin(); PrmStListAll->end() != it; it++)
			{
				if ((*it).parent == (*itlevel).memberName)
				{
					PrmStLevelList[i + 1].push_back((*it));
					tmp.axisNum				= (*it).axisNum;
					tmp.memberType			= (*it).memberType;
					tmp.memberName			= (*it).memberName;
					tmp.parent				= (*it).parent;
					tmp.value				= 0;
					tmp.unit				= L"NULL";
					tmp.introduction		= L"NULL";
					tmp.uplimit				= 0;
					tmp.downlimit			= 0;
					tmp.framAddr			= 0;
					PrmStLevelListPrty[i + 1].push_back(tmp);
				}
			}
		}
	}

	//判断是否把所有变量都找全。
	int32 Prmnumber = 0;
	int32 PrtyNumber = 0;
	for (int32 j = 0; j < level; j++)
	{
		Prmnumber += PrmStLevelList[j].size();
		PrtyNumber += PrmStLevelListPrty[j].size();
	}
	//加1是因为增加了不动根。
	if ((Prmnumber != (PrmStListAll->size()+1)) || (PrtyNumber != (PrmStListAll->size()+1)))
	{
		return 1;
	}

	//计算其它轴的树状结构

	for (int32 j = 1; j < sAxisNum; j++)
	{
		for (int32 k = 0; k < level; k++)
		{
			PrmStLevelListAxis[j - 1][k].clear();
		}
		//设置轴号
		var->constRoot.axisNum	= (int16)j;
		PrmStLevelListAxis[j - 1][0].push_back(var->constRoot);
		//设置轴号
		var->root.axisNum		= (int16)j;
		PrmStLevelListAxis[j - 1][1].push_back(var->root);
		//设置轴号
		var->root_aux.axisNum	= (int16)j;
		PrmStLevelListAxis[j - 1][1].push_back(var->root_aux);
		
		//恢复轴号
		var->constRoot.axisNum	= 0;
		var->root.axisNum		= 0;
		var->root_aux.axisNum	= 0;

		for (int32 i = 1; i < (level - 1); i++)
		{
			for (list<VARST>::iterator itlevel = PrmStLevelListAxis[j - 1][i].begin(); PrmStLevelListAxis[j - 1][i].end() != itlevel; itlevel++)
			{
				for (list<VARST>::iterator it = PrmStListAllAxis[j - 1].begin(); PrmStListAllAxis[j - 1].end() != it; it++)
				{
					if ((*it).parent == (*itlevel).memberName)
					{
						PrmStLevelListAxis[j - 1][i + 1].push_back((*it));
					}
				}
			}
		}
	}

	return 0;
}

int16 CBuildPrmRelation::GetPrmFuncList(int16 level)
{
	if (level <= 0)
	{
		return -1;
	}

	//根据level获取需要查询的关键字，例如_1,_2等
	int16 i;

	for (i = 1; i <= level; i++)
	{
		wstring tmp = L"";
		wstringstream wss;
		wss << i;
		wss >> tmp;
		tmp = L"_" + tmp;
		ScanPrmFuncWord.push_back(tmp);
	}
	//为参数功能分配空间
	PrmFuncList = new list < PRMPRTY >[level];
	wstring  func = L"gSevDrv";

	//双层循环，从参数中找到含有后缀_1等的值，并将其分类
	for (list<PRMPRTY>::iterator it = PrmPrtyList->begin(); PrmPrtyList->end() != it; it++)
	{
		i = 1;
		for (vector<wstring>::iterator it_v = ScanPrmFuncWord.begin(); ScanPrmFuncWord.end() != it_v; it_v++, i++)
		{
			if (hasChildStr((*it).memberName, (*it_v)) && hasChildStr((*it).memberName, func))
			{
				PrmFuncList[i - 1].push_back(*it);
			}
		}
	}
	//将之前更新的fram地址更新到功能列表中。因为这个文件到时要给上层，上层操作功能列表时要完成读写fram操作
	for (int16 i = 0; i < level;++i)
	{
		for (list<PRMPRTY>::iterator it = PrmFuncList[i].begin(); PrmFuncList[i].end() != it; it++)
		{
			for (list<VARST>::iterator it_a = PrmStListAll->begin(); PrmStListAll->end() != it_a; it_a++)
			{
				if ((*it_a).memberName == (*it).memberName)
				{
					(*it).framAddr = (*it_a).addressOffset;
				}
			}

		}
	}
	

	return 0;
}

int16 CBuildPrmRelation::PrintPrmMacroDefine(wstring& fileName)
{
	Uint16 macro_ofst = (Uint16)MODULE_AXIS_OFFSET;
	wstring macro_ofst_str = L"";
	wstringstream wss;
	wss << macro_ofst;
	wss >> macro_ofst_str;

	wstring filepath = fileName;
	wfstream file;
	file.open(filepath.c_str(), ios::in | ios::out | ios::trunc); //擦除之前所有数据
	if (!file)
	{
		return -1;
	}
	file << L"#ifndef  _PRM_MACRO_DEFINE_" << endl;
	file << L"#define  _PRM_MACRO_DEFINE_" << endl;
	file << L"" << endl;
	file << L"" << endl;
	file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
	file << L"//this file using macro to define the parameter address" << endl;
	file << L"" << endl;
	file << L"// all the module name list:";
	file << L"" << endl;
	for (list<VARST>::iterator itr = PrmStListChildModule->begin(); PrmStListChildModule->end() != itr; itr++)
	{
		file << L"//" << (*itr).memberName << endl;
		file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
	}
	file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
	file << L"" << endl;
	file << L"" << endl;
	file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	file.setf(ios::left, ios::adjustfield);
	file.width(20);
	file << L"#define";
	file.setf(ios::left, ios::adjustfield);
	file.width(60);
	file << L"PRM_MACRO_DEFINE_AXIS_OFST";
	file.setf(ios::left, ios::adjustfield);
	file.width(20);
	file << macro_ofst_str << endl;
	file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	file << L"" << endl;
	file << L"" << endl;
	file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
	file << L"//classified according to the module" << endl;
	file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
	file << L"" << endl;
	file << L"" << endl;

	wstring str_cur = L".cur.";
	wstring str_spd = L".vel.";
	wstring str_pos = L".pos.";
	wstring str_fpga = L"FPGA";
	wstring str_aux = L"gAuxFunc";

	vector<wstring> vec;
	wstring brace = L"[";

	vector<wstring> vec1;

	//外层为module，从all中找到parent是module的就写入该module的宏定义区域
	for (list<VARST>::iterator it = PrmStListChildModule->begin(); PrmStListChildModule->end() != it; it++)
	{
		//用于判断数组module
		vec.clear();
		splitDotStr((*it).memberName, vec);

		file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
		file << L"//module name				" << (*it).memberName << endl;
		file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
		file << L"" << endl;
		for (list<VARST>::iterator it_a = PrmStListAll->begin(); PrmStListAll->end() != it_a; it_a++)
		{
			//用于区分数组和正常值
			vec1.clear();
			splitDotStr((*it_a).memberName, vec1);
			if (vec1.size() < 2)
			{
				continue;
			}

			if (hasChildStr((*it).memberName, str_cur))
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是cur大类的

				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}
				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是cur大类的

					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}
				}
			}
			else if (hasChildStr((*it).memberName, str_spd))
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是spd大类的
				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}

				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是spd大类的
					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}

				}
			}
			else if (hasChildStr((*it).memberName, str_pos))
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是pos大类的

				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}

				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是pos大类的

					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}

				}
			}
			else if (hasChildStr((*it).memberName, str_fpga))
			{
				//FPGA部分
				if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
				{
					wstring tmp;
					tmp = NameDot2Line((*it_a).memberName);
					wstring ofst_str = L"";
					wstringstream wss;
					wss << ((*it_a).addressOffset);
					wss >> ofst_str;
					file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
					file.setf(ios::left, ios::adjustfield);
					file.width(20);
					file << L"#define";
					file.setf(ios::left, ios::adjustfield);
					file.width(60);
					file << tmp;
					file.setf(ios::left, ios::adjustfield);
					file.width(20);
					file << ofst_str << endl;
					file << L"" << endl;
				}
			}
			else if (hasChildStr((*it).memberName, str_aux))
			{
				//aux部分
				if (hasChildStr((*it_a).memberName, (*it).memberName) && ((*it_a).hasChild == false) && ((*it_a).isBits == false) && (!(hasChildStr(vec1[vec1.size() - 1], brace))))
				{
					wstring tmp;
					tmp = NameDot2Line((*it_a).memberName);
					wstring ofst_str = L"";
					wstringstream wss;
					wss << ((*it_a).addressOffset);
					wss >> ofst_str;
					file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
					file.setf(ios::left, ios::adjustfield);
					file.width(20);
					file << L"#define";
					file.setf(ios::left, ios::adjustfield);
					file.width(60);
					file << tmp;
					file.setf(ios::left, ios::adjustfield);
					file.width(20);
					file << ofst_str << endl;
					file << L"" << endl;
				}
			}
			else
			{
				//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是other大类的

				//首先判断是否是数组的父module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//满足父子关系，说明是该模块中的值。//条件是名字中包含父的名字并且没有孩子（这部分主要用来处理子模块内部又有数组的）
					if ((((*it_a).parent == (*it).memberName) || (hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}

				}
				else
				{
					//每次只循环一个模块，如果进入这里，那么就说明这次循环的模块是other大类的

					//满足父子关系，说明是该模块中的值。
					if (((((*it_a).parent == (*it).memberName) && ((*it_a).hasChild == false)) || (((hasChildStr((*it_a).memberName, (*it).memberName))) && ((*it_a).hasChild == false) && ((*it_a).isBits == false))) && (!(hasChildStr(vec1[vec1.size() - 2], brace))))
					{
						wstring tmp;
						tmp = NameDot2Line((*it_a).memberName);
						wstring ofst_str = L"";
						wstringstream wss;
						wss << ((*it_a).addressOffset);
						wss >> ofst_str;
						file << L"///////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << L"#define";
						file.setf(ios::left, ios::adjustfield);
						file.width(60);
						file << tmp;
						file.setf(ios::left, ios::adjustfield);
						file.width(20);
						file << ofst_str << endl;
						file << L"" << endl;
					}

				}
			}
		}


	}
	file << L"#endif" << endl;
	file.close();
	return 0;
}

