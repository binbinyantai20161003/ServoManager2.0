// GetPrmTreeListMessage.cpp : ���� DLL Ӧ�ó���ĵ���������
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
	PrmPrtyList			 = new list < PRMPRTY > ;  //�Ͳ���list��ͬ�����洢�������ԣ���Щ�������ڹ���ģ��
	
	PrmStListChildModule = new list < VARST > ;//���ڴ洢childģ��,ģ�����ڷָ�FRAM�ĵ�ַ


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
	//��ɾ��һ��
	for (int16 i = 1; i < g_parseHfile->AxisNumDefine; i++)
	{
		delete[] PrmStLevelListAxis[i - 1];			PrmStLevelListAxis[i - 1] = NULL;
		
	}
	//��ɾ������
	delete[] PrmStLevelListAxis;					PrmStLevelListAxis = NULL;
	//////////////////////////////////////////////////////////////////////////

	delete[]    PrmStLevelListPrty;					PrmStLevelListPrty = NULL;
	delete[]	PrmFuncList;						PrmFuncList = NULL;
}

void CBuildPrmRelation::setRootProperty()
{
	//ֻ�ǲ���
	rootProperty.axisNum			= 0;
	rootProperty.memberName			= L"gSevDrv";
	rootProperty.memberType			= L"SERVO_DRV";
	rootProperty.parent				= L"SevDrvRoot";
	rootProperty.unit				= L"NULL";
	rootProperty.introduction		= L"�ŷ���Ԫ��";
	rootProperty.uplimit			= 0;
	rootProperty.downlimit			= 0;
	rootProperty.value				= 0;
	rootProperty.framAddr			= 0;
}

void CBuildPrmRelation::setAuxRootProperty(void)
{
	//ֻ�ǲ���
	auxrootProperty.axisNum			= 0;
	auxrootProperty.memberName		= L"gAuxFunc";
	auxrootProperty.memberType		= L"AUX_FUNC";
	auxrootProperty.parent			= L"SevDrvRoot";
	auxrootProperty.unit			= L"NULL";
	auxrootProperty.introduction	= L"�ŷ�������Ԫ��";
	auxrootProperty.uplimit			= 0;
	auxrootProperty.downlimit		= 0;
	auxrootProperty.value			= 0;
	auxrootProperty.framAddr		= 0;
}

void CBuildPrmRelation::setConstRootProperty(void)
{
	//ֻ�ǲ���
	constRootProperty.axisNum		= 0;
	constRootProperty.memberName	= L"SevDrvRoot";
	constRootProperty.memberType	= L"int16";
	constRootProperty.parent		= L"SevDrvRoot";
	constRootProperty.unit			= L"NULL";
	constRootProperty.introduction	= L"�ŷ�����rootԪ��";
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
	//�������Ը����
	setRootProperty();
	setAuxRootProperty();

	wstring sr = L"prm";
	wstring sr1 = L".mot.";
	PRMPRTY tmp;
	for (list<VARST>::iterator itt = var->VarStList->begin(); var->VarStList->end() != itt; itt++)
	{
		//������list���ҵ�prm��صĲ��֣�����prm��list��
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

	//�����ҵ���prmlist�����в����丸�������prmlist���ҵ�ʲôҲ����������һֱ�ҵ�parent��root��ֵ������ж�������÷���Ҳ����
	//�ҵĹ����л��ҵ��ظ��ģ���ôֻ����һ�ݡ�
	bool find_flag = false;
	bool find_same = false;
	list<VARST>::iterator it;
	for (it = PrmStList->begin(); PrmStList->end() != it; it++)
	{
		for (list<VARST>::iterator it1 = PrmStList->begin(); PrmStList->end() != it1; it1++)
		{
			//������prmlist���ҵ����丸
			if ((*it).parent == (*it1).memberName)
			{
				find_flag = true;
				break;
				//do nothing
			}
		}
		//����û�ҵ�����VarStList����
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
					//��VarStList���ң���ӵ�PrmStListParent�У�
					if (name == (*it2).memberName)
					{
						//���list���Ƿ����ظ���ֵ��������ظ��ľͲ����
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
						break; //����forѭ��
					}
				}
				juststr = (*it2).parent;
				name = (*it2).parent;

				//��������һ���ҵ���ͬ�ģ���ô������Ӧ��Ҳ�Ѿ��ҵ��ˡ�����do whileѭ��
				if (find_same)
				{
					find_same = false;
					break;
				}
			} while (juststr != L"SevDrvRoot");
		}
		find_flag = false;
	}
	//��Ϊsplice�Ὣԭ����list��գ�������������������̬����
	list<VARST> tmplist;
	for (list<VARST>::iterator iter = PrmStList->begin(); PrmStList->end() != iter; iter++)
	{
		tmplist.push_back((*iter));
	}
	//�ϲ���������,
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

	//��FPGA��Ҫ���õĲ��ַ������в���list�С��ⲿ����Ҫ����fram��ַ
	tmplist.clear();
	g_xml->loadFpgaConfig(FPGAfilename, &tmplist);

	mit = PrmStListAll->end();
	(*PrmStListAll).splice(mit, (tmplist));

	if (Auxfilename != L"")
	{
		//��AUX�����������õĲ��ַ������в���list�С��ⲿ����Ҫ����fram��ַ
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

	//��¼��������λ��
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

		//���Ȳ���prm
		if ((vec[vec.size() - 1] == L"prm"))
		{
			PrmStListChildModule->push_back((*it));

			//��¼����������
			it_cur_prm++;

			//��¼cur.prm��λ�ã����ڽ�mot���뵽����棬�������ܱ�֤�ͳ���˳��һ�¡�
			if ((vec[vec.size() - 2] == L"cur"))
			{
				it_cur_prm_index = it_cur_prm;
			}
		}//Ȼ�����mot
		else if ((vec[vec.size() - 1] == L"mot"))
		{
			list<VARST>::iterator j = PrmStListChildModule->begin();
			for (int16 i = 0; (i < it_cur_prm_index) && (j != PrmStListChildModule->end()); ++i)
			{
				++j;
			}

			PrmStListChildModule->insert(j, (*it));
		}//�����ڶ���prm�����ҵ�����һ�к������ţ��������ŵ����ͻ�������int������,�����丸�������prm ʱ����Ϊmodule ����Ϊ����ʹ�õ���ȫ��﷽ʽ
		else if ((vec[vec.size() - 2] == L"prm") && (hasChildStr(vec[vec.size() - 1], brace)) && (!hasChildStr((*it).memberType, keyword)) && (vec1[vec1.size() - 1] != L"prm"))
		{
			PrmStListChildModule->push_back((*it));

			//ͨ�����Ҹ����õ�������size
			int16 value_limit = 0;
			value_limit = getBraceValue(vec1[vec1.size() - 1]);
			//ͨ�����ҵ�ǰֵ���ж��Ƿ��Ѿ����������size��
			int16 value_now = 0;
			value_now = getBraceValue(vec[vec.size() - 1]);

			if ((value_limit - value_now) == 1)
			{
				//����Ԥ������Ϊ10������������Ԫ�أ�����Ԥ����ַ��
				while (value_limit < MODULE_CASCADE_FILTER_MAX)
				{
					//����ֵת��Ϊ�ַ���
					wstringstream ss;
					wstring tmp;
					ss << value_limit;	//����int
					ss >> tmp;			//int -> wstring

					//�õ�Ҫ���µ���󲿷ֵ��ַ���
					wstring newvalue = L"[" + tmp + L"]";

					//�ҵ����һ��.��λ�ã�ȥ�������ֵ�������µ�ֵ
					int16 pos_last_point;
					wstring point = L"[";
					pos_last_point = (*it).memberName.find_last_of(point.c_str());
					wstring str = (*it).memberName.substr(0, pos_last_point);
					newvalue = str + newvalue;

					//���µ����ֵ�����Ԫ��д��list
					VARST tmpvar;
					tmpvar = (*it);
					tmpvar.memberName = newvalue;
					PrmStListChildModule->push_back(tmpvar);
					value_limit++;
				}
			}
		}
		else if ((vec[vec.size() - 2] == L"gAuxFunc") && (vec[vec.size() - 1] == L"aux_prm")) //�����������⴦��
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
	int32 tmp_common_ofst_base  = MODULE_COMMON_START_ADDR; //�������������һ��������꣬����ʹ�õڶ�����ġ�

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

	//���Ϊmodule����all���ҵ�parent��module�ľͼ���ofst
	for (list<VARST>::iterator it = PrmStListChildModule->begin(); PrmStListChildModule->end() != it; it++)
	{
		//�����ж�����module
		vec.clear();
		splitDotStr((*it).memberName, vec);

		for (list<VARST>::iterator it_a = PrmStListAll->begin(); PrmStListAll->end() != it_a; it_a++)
		{
			//�����������������ֵ
			vec1.clear();
			splitDotStr((*it_a).memberName, vec1);
			if (vec1.size() < 2)
			{
				continue;
			}

			if (hasChildStr((*it).memberName, str_cur))
			{
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����cur�����

				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
						//����Ԥ��ģ���ַ����
						if (tmp_cur_flag == 0)
						{
							tmp_cur_index++;
							tmp_cur_flag = 1;
						}
					}
				}
				else
				{
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����cur�����

					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����spd�����
				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
						//����Ԥ��ģ���ַ����
						if (tmp_spd_flag == 0)
						{
							tmp_spd_index++;
							tmp_spd_flag = 1;
						}
					}
				}
				else
				{
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����spd�����
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����pos�����

				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
						//����Ԥ��ģ���ַ����
						if (tmp_pos_flag == 0)
						{
							tmp_pos_index++;
							tmp_pos_flag = 1;
						}
					}
				}
				else
				{
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����pos�����

					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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
				//FPGA���ֲ��������������
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
				//���������������
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
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����aux�����

				//���������������,�������ְ��������ģ�飬���ұ���û���ӽڵ�
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
					//���û��child�������������ģ���Ϊ����������������壬���ԣ�����ֻ��Ҫ����һ��
					(*it_a).addressOffset = -1;
				}
				else
				{
					//do nothing
				}
			}
			else
			{
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����other�����

				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
						//����Ԥ��ģ���ַ����
						if (tmp_other_flag == 0)
						{
							tmp_other_index++;
							tmp_other_flag = 1;
						}
					}
				}
				else
				{
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����other�����

					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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
		//��λ����Ϊaux������������ģ�飬�����µ�ģ�鿪ʼ��ʱ����Ҫ��λ�ñ�����
		//tmp_inc_aux		= 0;

		//��ձ�־
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

	//��������ƫ�Ƶ�ַ����Ϊ-1������1����child������2��û��child������bitλ

	for (list<VARST>::iterator it_all = PrmStListAll->begin(); PrmStListAll->end() != it_all; it_all++)
	{
		if (((*it_all).hasChild == true) || (((*it_all).hasChild == false) && ((*it_all).isBits == true)))
		{
			(*it_all).addressOffset = -1;
			(*it_all).value = L"NULL";
		}
	}

	//��ram�е�ĳЩֵ��ƫ�Ƹ�Ϊ-1
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
	//����������ȥ��ȫ�ֲ��֣�
	wstring tmp = L"Global";

	for (int16 i = 1; i < sAxisNum; i++)
	{
		//����һ��������ݸ�ֵ���µ���
		PrmStListAllAxis[i - 1] = *PrmStListAll;
		for (list<VARST>::iterator it = PrmStListAllAxis[i - 1].begin(); PrmStListAllAxis[i - 1].end() != it; )
		{
			//�������
			(*it).axisNum = (int16)i;

			if (hasChildStr((*it).memberName,tmp))
			{
				it = PrmStListAllAxis[i - 1].erase(it);
			}
			else
			{
				//����ofst
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

	//��Ϊÿ���ᶼֻ����һ���������������ӵĸ��ڵ��൱���ڵڶ��㣬��һ����Զ���ᶯ
	level = level + 1;

	//�洢��״�ṹ�����в���
	PrmStLevelList = new list<VARST>[level];

	//�洢���������״�ṹ����ָ�룬[AllAxisNum - 1]��ָ��
	PrmStLevelListAxis = new list<VARST>*[sAxisNum - 1];
	for (int16 j = 0; j < sAxisNum - 1; j++)
	{
		//ÿ��ָ�������level��
		PrmStLevelListAxis[j] = new list<VARST>[level];
	}
	
	//�洢���Ե���״�ṹ
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

	//�ж��Ƿ�����б�������ȫ��
	int32 Prmnumber = 0;
	int32 PrtyNumber = 0;
	for (int32 j = 0; j < level; j++)
	{
		Prmnumber += PrmStLevelList[j].size();
		PrtyNumber += PrmStLevelListPrty[j].size();
	}
	//��1����Ϊ�����˲�������
	if ((Prmnumber != (PrmStListAll->size()+1)) || (PrtyNumber != (PrmStListAll->size()+1)))
	{
		return 1;
	}

	//�������������״�ṹ

	for (int32 j = 1; j < sAxisNum; j++)
	{
		for (int32 k = 0; k < level; k++)
		{
			PrmStLevelListAxis[j - 1][k].clear();
		}
		//�������
		var->constRoot.axisNum	= (int16)j;
		PrmStLevelListAxis[j - 1][0].push_back(var->constRoot);
		//�������
		var->root.axisNum		= (int16)j;
		PrmStLevelListAxis[j - 1][1].push_back(var->root);
		//�������
		var->root_aux.axisNum	= (int16)j;
		PrmStLevelListAxis[j - 1][1].push_back(var->root_aux);
		
		//�ָ����
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

	//����level��ȡ��Ҫ��ѯ�Ĺؼ��֣�����_1,_2��
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
	//Ϊ�������ܷ���ռ�
	PrmFuncList = new list < PRMPRTY >[level];
	wstring  func = L"gSevDrv";

	//˫��ѭ�����Ӳ������ҵ����к�׺_1�ȵ�ֵ�����������
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
	//��֮ǰ���µ�fram��ַ���µ������б��С���Ϊ����ļ���ʱҪ���ϲ㣬�ϲ���������б�ʱҪ��ɶ�дfram����
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
	file.open(filepath.c_str(), ios::in | ios::out | ios::trunc); //����֮ǰ��������
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

	//���Ϊmodule����all���ҵ�parent��module�ľ�д���module�ĺ궨������
	for (list<VARST>::iterator it = PrmStListChildModule->begin(); PrmStListChildModule->end() != it; it++)
	{
		//�����ж�����module
		vec.clear();
		splitDotStr((*it).memberName, vec);

		file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
		file << L"//module name				" << (*it).memberName << endl;
		file << L"//_________________________________________________________________________________________________________________________________________________________" << endl;
		file << L"" << endl;
		for (list<VARST>::iterator it_a = PrmStListAll->begin(); PrmStListAll->end() != it_a; it_a++)
		{
			//�����������������ֵ
			vec1.clear();
			splitDotStr((*it_a).memberName, vec1);
			if (vec1.size() < 2)
			{
				continue;
			}

			if (hasChildStr((*it).memberName, str_cur))
			{
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����cur�����

				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����cur�����

					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����spd�����
				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����spd�����
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����pos�����

				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����pos�����

					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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
				//FPGA����
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
				//aux����
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
				//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����other�����

				//�����ж��Ƿ�������ĸ�module
				if ((hasChildStr(vec[vec.size() - 1], brace)))
				{
					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��//�����������а����������ֲ���û�к��ӣ��ⲿ����Ҫ����������ģ���ڲ���������ģ�
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
					//ÿ��ֻѭ��һ��ģ�飬������������ô��˵�����ѭ����ģ����other�����

					//���㸸�ӹ�ϵ��˵���Ǹ�ģ���е�ֵ��
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

