//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	xml process													//
//	file				:	xml.cpp														//
//	Description			:	use for read and write xml file								//
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
#include <stack>
#include <algorithm>
using namespace std;

#include "BuildVarRelation.h"
#include "StringHandler.h"
#include "ParseFile.h"
#include "BuildPrmRelation.h"
#include "PrtyCompare.h"
#include "PrmCompare.h"
#include "xml.h"

GTSD_XML* g_xml = NULL;

GTSD_XML::GTSD_XML()
{
}

GTSD_XML::~GTSD_XML(void)
{
}

TiXmlElement* GTSD_XML::loadTemplate(wstring& filePath, TiXmlDocument* myDoc)
{
	bool loadOk = myDoc->LoadFile(ws2s(filePath).c_str());
	if (!loadOk)
	{
		return NULL;
	}
	//��ø�Ԫ��
	TiXmlElement *RootElement = myDoc->RootElement();
	findTemplateChild(RootElement);
	return templateEle;
}

void GTSD_XML::findTemplateChild(TiXmlElement* parentnode)
{
	string it = "widget";
	string attr = "QTreeWidget";
	static bool find_flag = false;

	TiXmlAttribute *Attribute;
	for (TiXmlElement* item = parentnode->FirstChildElement(); item;item = item->NextSiblingElement())
	{
		if (item->Value() == it)
		{
			Attribute = item->FirstAttribute();//��ȡԪ�ص�����
			if (Attribute->Value() == attr)
			{
				templateEle = item;
				find_flag = true;
				break;
			}
		}
		if (!item->NoChildren())
		{
			findTemplateChild(item); 
		}	
	}
}

void GTSD_XML::loadFpgaConfig(wstring& filePath, list<VARST>* fpgaList)
{
	//����һ��XML���ĵ�����
	TiXmlDocument *myDoc = new TiXmlDocument(ws2s(filePath).c_str());
	bool loadOk = myDoc->LoadFile();
	if (!loadOk)
	{
		return;
	}
	//��ø�Ԫ��
	TiXmlElement *RootElement	= myDoc->RootElement();
	findFpgaChild(RootElement, fpgaList);
}

void GTSD_XML::findFpgaChild(TiXmlElement* parentnode, list<VARST>* fpgaList)
{
	for (TiXmlElement* item = parentnode->FirstChildElement("item"); item;
		item = item->NextSiblingElement("item"))
	{
		VARST tmp;
		TiXmlElement* node;
		string  Text;
		int32 tmp32;
		bool  tmpbool;

		node				= item->FirstChildElement();
		Text				= node->GetText();
		tmp.axisNum			= (int16)String2Int((string)Text);

		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp.memberType		= s2ws(Text);

		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp.memberName		= s2ws(Text);

		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp.addressOffset	= String2Int((string)Text);

		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp.parent			= s2ws(Text);
		//////////////////////////////////////////////////////////////////////////
		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp32				= String2Int((string)Text);
		if (tmp32 != 0)
		{
			tmpbool = true;
		}
		else
		{
			tmpbool = false;
		}
		tmp.hasChild		= tmpbool;
		//////////////////////////////////////////////////////////////////////////
		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp.childNum		= (int16)String2Int((string)Text);
		//////////////////////////////////////////////////////////////////////////
		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp32				= String2Int((string)Text);
		if (tmp32 != 0)
		{
			tmpbool = true;
		}
		else
		{
			tmpbool = false;
		}
		tmp.isBits			= tmpbool;
		//////////////////////////////////////////////////////////////////////////
		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp.bitStart		= (int16)String2Int((string)Text);

		node				= node->NextSiblingElement();
		Text				= node->GetText();
		tmp.bitWidth		= (int16)String2Int((string)Text);

		fpgaList->push_back(tmp);

		if (tmp.hasChild)
		{
			findFpgaChild(item, fpgaList);
		}
	}
}

void GTSD_XML::writeColumn(TiXmlElement* elet, string st)
{
	string stt = "text";
	TiXmlElement* col = new TiXmlElement("column");
	elet->LinkEndChild(col);
	TiXmlElement* prty = new TiXmlElement("property");
	col->LinkEndChild(prty);
	prty->SetAttribute("name", stt);
	TiXmlElement* str = new TiXmlElement("string");
	prty->LinkEndChild(str);
	TiXmlText *Name = new TiXmlText(st);
	str->LinkEndChild(Name);
}

void GTSD_XML::writeblock(TiXmlElement* elet, string st)
{
	string stt = "text";
	
	TiXmlElement* prty = new TiXmlElement("property");
	elet->LinkEndChild(prty);
	prty->SetAttribute("name", stt);
	TiXmlElement* str = new TiXmlElement("string");
	prty->LinkEndChild(str);
	TiXmlText *Name = new TiXmlText(st);
	str->LinkEndChild(Name);
}

void GTSD_XML::saveTree(wstring& filepathT, wstring& filepath, list<VARST>* vlist, int16 treelevel)
{
	//����ڵ�
	VVectorTreeElement = new vector < vector<TiXmlElement*>* > ; //���������
	VecTreeElement = new vector<TiXmlElement*>[treelevel]; //�ڵ������
	for (int32 j = 0; j < treelevel; j++)
	{
		VVectorTreeElement->push_back(&VecTreeElement[j]);
	}
	//����һ��XML���ĵ�����
	TiXmlDocument* myDoc = new TiXmlDocument();
	TiXmlElement* node = NULL;

	//���ȶ�ȡģ��xml�ļ��������в����µ�����
	node = loadTemplate(filepathT, myDoc);

	//�����֦�Ľṹ
	for (int16 i = 0; i < treelevel; i++)
	{
		(*(VVectorTreeElement->at(i))).clear();
	}
	
	//д��column
	string strName = "memberName";
	writeColumn(node, strName);	
	strName = "value";
	writeColumn(node, strName);
	strName = "memberType";
	writeColumn(node, strName);
	strName = "addressOffset";
	writeColumn(node, strName);
	strName = "isBits";
	writeColumn(node, strName);
	strName = "bitStart";
	writeColumn(node, strName);
	strName = "bitWidth";
	writeColumn(node, strName);
	strName = "axisNum";
	writeColumn(node, strName);
	strName = "hasChild";
	writeColumn(node, strName);
	strName = "childNum";
	writeColumn(node, strName);
	strName = "parent";
	writeColumn(node, strName);

	//������̬�ڵ�
	TiXmlElement* tmp = NULL;
	
	for (list<VARST>::iterator itr = vlist[0].begin(); vlist[0].end() != itr; itr++)
	{
		tmp = createElement(node, "item",itr);
		(*(VVectorTreeElement->at(0))).push_back(tmp);
	}

	int32 index = 0;
	for (int16 i = 0; i < treelevel-1;i++)
	{
		for (list<VARST>::iterator it = vlist[i].begin(); vlist[i].end() != it; it++)
		{
			//��list��i+1�����ҵ�parent��list��i����ֵ��Ȼ������Ϊ��Ԫ�أ�д�븸Ԫ����
			for (list<VARST>::iterator it1 = vlist[i + 1].begin(); vlist[i + 1].end() != it1; it1++)
			{
				if ((*it1).parent == (*it).memberName)
				{
					string name = "item";
					tmp = createElement((*(VVectorTreeElement->at(i))).at(index), name,it1);
					(*(VVectorTreeElement->at(i+1))).push_back(tmp);
				}
			}
			index++;
		}
		index = 0;

	}
	myDoc->SaveFile((ws2s(filepath)).c_str());

	delete[]    VecTreeElement;							VecTreeElement = NULL;
	delete      VVectorTreeElement;						VVectorTreeElement = NULL;
}

TiXmlElement* GTSD_XML::createElement(TiXmlElement* parentelement, string elename, list<VARST>::iterator it)
{
	//����Ԫ��
	TiXmlElement* element = new TiXmlElement(elename);
	parentelement->LinkEndChild(element);
	int16 tmp;

	writeblock(element, (ws2s((*it).memberName)));	
	writeblock(element, (ws2s((*it).value)));
	writeblock(element, (ws2s((*it).memberType)));
	writeblock(element, Int2String((*it).addressOffset));
	if ((*it).isBits == true)
	{
		tmp = 1;
	}
	else
	{
		tmp = 0;
	}
	writeblock(element, Int2String(tmp));
	writeblock(element, Int2String((*it).bitStart));
	writeblock(element, Int2String((*it).bitWidth));
	writeblock(element, Int2String((*it).axisNum));
	if ((*it).hasChild == true)
	{
		tmp = 1;
	}
	else
	{
		tmp = 0;
	}
	writeblock(element, Int2String(tmp));
	writeblock(element, Int2String((*it).childNum));
	writeblock(element, (ws2s((*it).parent)));
	
	
	
	
	

	return element;
}

void GTSD_XML::savePlotRamTree(wstring& filepathT, wstring& filepath, list<VARST>* vlist, list<VARST>** vlistaxis, int16 treelevel, int16 DspAxisNum, int16 devAxisNum)
{
	//����ڵ�
	VVectorTreeElement = new vector < vector<TiXmlElement*>* > ; //���������
	VecTreeElement = new vector<TiXmlElement*>[treelevel]; //�ڵ������
	for (int32 j = 0; j < treelevel; j++)
	{
		VVectorTreeElement->push_back(&VecTreeElement[j]);
	}
	//����һ��XML���ĵ�����
	TiXmlDocument* myDoc = new TiXmlDocument();
	TiXmlElement* node = NULL;

	//���ȶ�ȡģ��xml�ļ��������в����µ�����
	node = loadTemplate(filepathT, myDoc);

	//�����֦�Ľṹ
	for (int16 i = 0; i < treelevel; i++)
	{
		(*(VVectorTreeElement->at(i))).clear();
	}

	//д��column
	string strName = "memberName";
	writeColumn(node, strName);
	strName = "value";
	writeColumn(node, strName);
	strName = "memberType";
	writeColumn(node, strName);
	strName = "addressOffset";
	writeColumn(node, strName);
	strName = "isBits";
	writeColumn(node, strName);
	strName = "bitStart";
	writeColumn(node, strName);
	strName = "bitWidth";
	writeColumn(node, strName);
	strName = "axisNum";
	writeColumn(node, strName);
	strName = "hasChild";
	writeColumn(node, strName);
	strName = "childNum";
	writeColumn(node, strName);
	strName = "parent";
	writeColumn(node, strName);

	int16 axisIndex = 0;
	wstring strAxisIndex = L"";
	wstring backUpName = L"";


	for (int16 axis = 0; axis < (devAxisNum>>1); ++axis)
	{
		//�����֦�Ľṹ
		for (int16 i = 0; i < treelevel; i++)
		{
			(*(VVectorTreeElement->at(i))).clear();
		}
		//������̬�ڵ�
		TiXmlElement* tmp = NULL;
		string axisname = "item";
		for (list<VARST>::iterator itr = vlist[0].begin(); vlist[0].end() != itr; itr++)
		{
			backUpName = itr->memberName;
			strAxisIndex = L"";
			wstringstream ss;
			ss << axisIndex;
			ss >> strAxisIndex;
			itr->memberName = itr->memberName + strAxisIndex;
			tmp = createElement(node, axisname, itr);
			(*(VVectorTreeElement->at(0))).push_back(tmp);
			itr->memberName = backUpName;
		}
		//��index����
		axisIndex++;
		int32 index = 0;
		for (int16 i = 0; i < treelevel - 1; i++)
		{
			for (list<VARST>::iterator it = vlist[i].begin(); vlist[i].end() != it; it++)
			{
				//��list��i+1�����ҵ�parent��list��i����ֵ��Ȼ������Ϊ��Ԫ�أ�д�븸Ԫ����
				for (list<VARST>::iterator it1 = vlist[i + 1].begin(); vlist[i + 1].end() != it1; it1++)
				{
					if ((*it1).parent == (*it).memberName)
					{
						string name = "item";
						tmp = createElement((*(VVectorTreeElement->at(i))).at(index), name, it1);
						(*(VVectorTreeElement->at(i + 1))).push_back(tmp);
					}
				}
				index++;
			}
			index = 0;

		}

		//////////////////////////////////////////////////////////////////////////

		for (int16 axis = 1; axis < DspAxisNum; ++axis)
		{
			//�����֦�Ľṹ
			for (int16 i = 0; i < treelevel; i++)
			{
				(*(VVectorTreeElement->at(i))).clear();
			}

			//������̬�ڵ�
			TiXmlElement* tmp1 = NULL;
			for (list<VARST>::iterator itr = vlistaxis[axis - 1][0].begin(); vlistaxis[axis - 1][0].end() != itr; itr++)
			{
				backUpName = itr->memberName;
				strAxisIndex = L"";
				wstringstream ss;
				ss << axisIndex;
				ss >> strAxisIndex;
				itr->memberName = itr->memberName + strAxisIndex;
				tmp1 = createElement(node, axisname, itr);
				(*(VVectorTreeElement->at(0))).push_back(tmp1);
				itr->memberName = backUpName;
			}
			axisIndex++;
			index = 0;
			for (int16 i = 0; i < treelevel - 1; i++)
			{
				for (list<VARST>::iterator it = vlistaxis[axis - 1][i].begin(); vlistaxis[axis - 1][i].end() != it; it++)
				{
					//��list��i+1�����ҵ�parent��list��i����ֵ��Ȼ������Ϊ��Ԫ�أ�д�븸Ԫ����
					for (list<VARST>::iterator it1 = vlistaxis[axis - 1][i + 1].begin(); vlistaxis[axis - 1][i + 1].end() != it1; it1++)
					{
						if ((*it1).parent == (*it).memberName)
						{
							string name = "item";
							tmp1 = createElement((*(VVectorTreeElement->at(i))).at(index), name, it1);
							(*(VVectorTreeElement->at(i + 1))).push_back(tmp1);
						}
					}
					index++;
				}
				index = 0;

			}
		}
	}

	myDoc->SaveFile((ws2s(filepath)).c_str());

	delete[]    VecTreeElement;							VecTreeElement = NULL;
	delete      VVectorTreeElement;						VVectorTreeElement = NULL;
}

void GTSD_XML::saveFramPrmTree(wstring& filepathT, wstring& filepath, list<VARST>* vlist, list<VARST>** vlistaxis, int16 treelevel, int16 DspAxisNum, int16 devAxisNum)
{
	//����ڵ�
	VVectorTreeElement = new vector < vector<TiXmlElement*>* > ; //���������
	VecTreeElement = new vector<TiXmlElement*>[treelevel]; //�ڵ������
	for (int32 j = 0; j < treelevel; j++)
	{
		VVectorTreeElement->push_back(&VecTreeElement[j]);
	}
	//����һ��XML���ĵ�����
	TiXmlDocument* myDoc = new TiXmlDocument();
	TiXmlElement* node = NULL;

	//���ȶ�ȡģ��xml�ļ��������в����µ�����
	node = loadTemplate(filepathT, myDoc);

	//�����֦�Ľṹ
	for (int16 i = 0; i < treelevel; i++)
	{
		(*(VVectorTreeElement->at(i))).clear();
	}

	//д��column
	string strName = "memberName";
	writeColumn(node, strName);
	strName = "value";
	writeColumn(node, strName);
	strName = "memberType";
	writeColumn(node, strName);
	strName = "addressOffset";
	writeColumn(node, strName);

	int16 axisIndex = 0;
	wstring strAxisIndex = L"";
	wstring backUpName = L"";
	

	for (int16 axis = 0; axis < (devAxisNum>>1); ++axis)
	{
		//�����֦�Ľṹ
		for (int16 i = 0; i < treelevel; i++)
		{
			(*(VVectorTreeElement->at(i))).clear();
		}
		//������̬�ڵ�
		TiXmlElement* tmp = NULL;
		string axisname = "item";

		for (list<VARST>::iterator itr = vlist[0].begin(); vlist[0].end() != itr; itr++)
		{
			backUpName = itr->memberName;
			strAxisIndex = L"";
			wstringstream ss;
			ss << axisIndex;		
			ss >> strAxisIndex;	
			itr->memberName = itr->memberName + strAxisIndex;
			tmp = createFramPrmElement(node, axisname, itr);
			(*(VVectorTreeElement->at(0))).push_back(tmp);
			itr->memberName = backUpName;
		}
		//��index����
		axisIndex++;

		int32 index = 0;
		for (int16 i = 0; i < treelevel - 1; i++)
		{
			for (list<VARST>::iterator it = vlist[i].begin(); vlist[i].end() != it; it++)
			{
				//��list��i+1�����ҵ�parent��list��i����ֵ��Ȼ������Ϊ��Ԫ�أ�д�븸Ԫ����
				for (list<VARST>::iterator it1 = vlist[i + 1].begin(); vlist[i + 1].end() != it1; it1++)
				{
					if ((*it1).parent == (*it).memberName)
					{
						string name = "item";
						tmp = createFramPrmElement((*(VVectorTreeElement->at(i))).at(index), name, it1);
						(*(VVectorTreeElement->at(i + 1))).push_back(tmp);
					}
				}
				index++;
			}
			index = 0;

		}

		//////////////////////////////////////////////////////////////////////////

		for (int16 axis = 1; axis < DspAxisNum; ++axis)
		{
			//�����֦�Ľṹ
			for (int16 i = 0; i < treelevel; i++)
			{
				(*(VVectorTreeElement->at(i))).clear();
			}

			//������̬�ڵ�
			TiXmlElement* tmp1 = NULL;
			for (list<VARST>::iterator itr = vlistaxis[axis - 1][0].begin(); vlistaxis[axis - 1][0].end() != itr; itr++)
			{
				backUpName = itr->memberName;
				strAxisIndex = L"";
				wstringstream ss;
				ss << axisIndex;
				ss >> strAxisIndex;
				itr->memberName = itr->memberName + strAxisIndex;
				tmp1 = createFramPrmElement(node, axisname, itr);
				(*(VVectorTreeElement->at(0))).push_back(tmp1);
				itr->memberName = backUpName;
			}
			axisIndex++;
			index = 0;
			for (int16 i = 0; i < treelevel - 1; i++)
			{
				for (list<VARST>::iterator it = vlistaxis[axis-1][i].begin(); vlistaxis[axis-1][i].end() != it; it++)
				{
					//��list��i+1�����ҵ�parent��list��i����ֵ��Ȼ������Ϊ��Ԫ�أ�д�븸Ԫ����
					for (list<VARST>::iterator it1 = vlistaxis[axis-1][i + 1].begin(); vlistaxis[axis-1][i + 1].end() != it1; it1++)
					{
						if ((*it1).parent == (*it).memberName)
						{
							string name = "item";
							tmp1 = createFramPrmElement((*(VVectorTreeElement->at(i))).at(index), name, it1);
							(*(VVectorTreeElement->at(i + 1))).push_back(tmp1);
						}
					}
					index++;
				}
				index = 0;

			}
		}
		
	}
	
	myDoc->SaveFile((ws2s(filepath)).c_str());

	delete[]    VecTreeElement;							VecTreeElement = NULL;
	delete      VVectorTreeElement;						VVectorTreeElement = NULL;
}

TiXmlElement* GTSD_XML::createFramPrmElement(TiXmlElement* parentelement, string elename, list<VARST>::iterator it)
{
	//����Ԫ��
	TiXmlElement* element = new TiXmlElement(elename);
	parentelement->LinkEndChild(element);
	writeblock(element, (ws2s((*it).memberName)));
	writeblock(element, Int2String(0));
	writeblock(element, (ws2s((*it).memberType)));
	writeblock(element, Int2String((*it).addressOffset));

	return element;
}

void GTSD_XML::savePrtyTree(wstring& filepathT, wstring& filepath, list<PRMPRTY>* vlist, int16 treelevel)
{
	//����ڵ�
	VVectorTreeElement = new vector < vector<TiXmlElement*>* > ; //���������
	VecTreeElement = new vector<TiXmlElement*>[treelevel]; //�ڵ������
	for (int32 j = 0; j < treelevel; j++)
	{
		VVectorTreeElement->push_back(&VecTreeElement[j]);
	}
	//����һ��XML���ĵ�����
	TiXmlDocument* myDoc = new TiXmlDocument();
	TiXmlElement* node = NULL;

	//���ȶ�ȡģ��xml�ļ��������в����µ�����
	node = loadTemplate(filepathT, myDoc);

	//�����֦�Ľṹ
	for (int16 i = 0; i < treelevel; i++)
	{
		(*(VVectorTreeElement->at(i))).clear();
	}

	//д��column
	string strName = "memberType";
	writeColumn(node, strName);
	strName = "memberName";
	writeColumn(node, strName);
	strName = "parent";
	writeColumn(node, strName);
	strName = "unit";
	writeColumn(node, strName);
	strName = "introduction";
	writeColumn(node, strName);
	strName = "uplimit";
	writeColumn(node, strName);
	strName = "downlimit";
	writeColumn(node, strName);


	//������̬�ڵ�
	TiXmlElement* tmp = NULL;
	for (list<PRMPRTY>::iterator itr = vlist[0].begin(); vlist[0].end() != itr; itr++)
	{
		tmp = createPrtyElement(node, "item", itr);
		(*(VVectorTreeElement->at(0))).push_back(tmp);
	}
	

	int32 index = 0;
	for (int16 i = 0; i < treelevel - 1; i++)
	{
		for (list<PRMPRTY>::iterator it = vlist[i].begin(); vlist[i].end() != it; it++)
		{
			//��list��i+1�����ҵ�parent��list��i����ֵ��Ȼ������Ϊ��Ԫ�أ�д�븸Ԫ����
			for (list<PRMPRTY>::iterator it1 = vlist[i + 1].begin(); vlist[i + 1].end() != it1; it1++)
			{
				if ((*it1).parent == (*it).memberName)
				{
					string name = "item";
					tmp = createPrtyElement((*(VVectorTreeElement->at(i))).at(index), name, it1);
					(*(VVectorTreeElement->at(i + 1))).push_back(tmp);
				}
			}
			index++;
		}
		index = 0;

	}
	myDoc->SaveFile((ws2s(filepath)).c_str());

	delete[]    VecTreeElement;							VecTreeElement = NULL;
	delete      VVectorTreeElement;						VVectorTreeElement = NULL;
}

TiXmlElement* GTSD_XML::createPrtyElement(TiXmlElement* parentelement, string elename, list<PRMPRTY>::iterator it)
{
	//����Ԫ��
	TiXmlElement* element = new TiXmlElement(elename);
	parentelement->LinkEndChild(element);

	writeblock(element, (ws2s((*it).memberType)));
	writeblock(element, (ws2s((*it).memberName)));
	writeblock(element, (ws2s((*it).parent)));
	writeblock(element, (ws2s((*it).unit)));
	writeblock(element, (ws2s((*it).introduction)));
	writeblock(element, double2String((*it).uplimit));
	writeblock(element, double2String((*it).downlimit));

	return element;
}

void GTSD_XML::saveFuncPrty(wstring& filepathT, wstring& filepath, list<PRMPRTY>* vlist)
{
	//����һ��XML���ĵ�����
	TiXmlDocument* myDoc = new TiXmlDocument();
	TiXmlElement* node = NULL;

	//���ȶ�ȡģ��xml�ļ��������в����µ�����
	node = loadTemplate(filepathT, myDoc);

	//д��column
	string strName = "memberName";
	writeColumn(node, strName);
	strName = "value";
	writeColumn(node, strName);
	strName = "memberType";
	writeColumn(node, strName);
	strName = "unit";
	writeColumn(node, strName);
	strName = "downlimit";
	writeColumn(node, strName);
	strName = "uplimit";
	writeColumn(node, strName);
	strName = "introduction";
	writeColumn(node, strName);
	strName = "framAddr";
	writeColumn(node, strName);

	string name = "item";
	for (list<PRMPRTY>::iterator it = vlist->begin(); vlist->end() != it; it++)
	{
		createFuncPrtyElement(node, name, it);
	}

	myDoc->SaveFile((ws2s(filepath)).c_str());
}

TiXmlElement* GTSD_XML::createFuncPrtyElement(TiXmlElement* parentelement, string elename, list<PRMPRTY>::iterator it)
{
	//����Ԫ��
	TiXmlElement* element = new TiXmlElement(elename);
	parentelement->LinkEndChild(element);
	writeblock(element, (ws2s((*it).memberName)));
	writeblock(element, (double2String((*it).value)));
	writeblock(element, (ws2s((*it).memberType)));
	writeblock(element, (ws2s((*it).unit)));
	writeblock(element, double2String((*it).downlimit));
	writeblock(element, double2String((*it).uplimit));
	writeblock(element, (ws2s((*it).introduction)));
	writeblock(element, Int2String((*it).framAddr));

	return element;
}


void GTSD_XML::loadPrtyTree(wstring& filePath, Cprty_tree_node** node)
{
	//����һ��XML���ĵ�����
	TiXmlDocument *myDoc = new TiXmlDocument(ws2s(filePath).c_str());
	bool loadOk = myDoc->LoadFile();
	if (!loadOk)
	{
		return;
	}
	//��ø�Ԫ��
	TiXmlElement *RootElement = myDoc->RootElement();
	//�����ҵ�item��ʼ�ĵط�
	findTemplateChild(RootElement);
	int16 levelnumber = 1;

	findPrtyTreeChild(templateEle, levelnumber, node);
}

void GTSD_XML::findPrtyTreeChild(TiXmlElement* parentnode, int16 levelNum, Cprty_tree_node** tree_node/*=NULL */)
{
	//child����
	int16   childnumber = 0;

	for (TiXmlElement* item = parentnode->FirstChildElement("item"); item;item = item->NextSiblingElement("item"))
	{	
		//׼����״�ṹ����̬node
		Cprty_tree_node* pnode_tmp = new Cprty_tree_node();

		PRMPRTY tmp;
		TiXmlElement* node;//�������nod
		TiXmlElement* node_internal;
		string  Text;

		node = item->FirstChildElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.memberType = s2ws(Text);

		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.memberName = s2ws(Text);

		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.parent = s2ws(Text);

		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.unit = s2ws(Text);

		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.introduction = s2ws(Text);
	
		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.uplimit = (int16)String2Int((string)Text);
		
		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.downlimit = (int16)String2Int((string)Text);

		pnode_tmp->prty = tmp;
		pnode_tmp->treelevel = (levelNum - 1);
		pnode_tmp->parent = NULL;

		node = node->NextSiblingElement();
		if ((node!=NULL) && (((string)(node->Value())) == "item"))
		{
			//������ӽڵ㣬��ô�Ƚ����ڵ�ѹ��ջ�С�
			pnode_tmp->hasChildren = 1;
			pnode_tmp->childNumber = 0;
			g_prty_tree->stack_prty_tree->push(pnode_tmp);
			
			//�����ӽڵ�
			findPrtyTreeChild(item, levelNum+1);
	
		}
		else
		{
			//���û���ӽڵ㣬��ôֱ��ѹ��ջ�С�
			pnode_tmp->hasChildren	= 0;
			pnode_tmp->childNumber	= 0;
			g_prty_tree->stack_prty_tree->push(pnode_tmp);
		}
	}
	//����ͬ��ɨ�����
	Cprty_tree_node* node_top = NULL;
	if (levelNum != 1)
	{
		
		//�����ж��Ƿ�stackΪ��
		if ((g_prty_tree->stack_prty_tree->empty()))
		{
			return;
		}
		//��ȡstack���һ��ֵ
		node_top = g_prty_tree->stack_prty_tree->top();

		while (node_top->treelevel == (levelNum - 1))
		{
			//�Ƚ��ӽڵ㱣��
			g_prty_tree->vector_prty_tree_node->push_back(node_top);
			g_prty_tree->stack_prty_tree->pop();
			childnumber++;
			//�����ж��Ƿ�stackΪ��
			if ((g_prty_tree->stack_prty_tree->empty()))
			{
				return;
			}
			else
			{
				node_top = g_prty_tree->stack_prty_tree->top();
			}
		}

		for (int16 i = 0; i < childnumber; i++)
		{
			((Cprty_tree_node*)((*(g_prty_tree->vector_prty_tree_node))[i]))->parent = node_top;
			node_top->children.push_back(((Cprty_tree_node*)((*(g_prty_tree->vector_prty_tree_node))[childnumber - 1 - i])));
		}
		node_top->childNumber = childnumber;
	}
	else
	{
		//��ȡstack���һ��ֵ
		node_top = g_prty_tree->stack_prty_tree->top();
		//�����Ǹ�Ԫ�أ���ô�丸�ڵ���������
		if (((string)(parentnode->Value())) == "widget")
		{
			node_top->parent = node_top;
			*tree_node = node_top;
			g_prty_tree->stack_prty_tree->pop();
		}
	}
	//����ӽڵ����������´�ʹ��
	g_prty_tree->vector_prty_tree_node->clear();
}



void GTSD_XML::loadPrmTree(wstring& filePath, Cprm_tree_node** node)
{
	//����һ��XML���ĵ�����
	TiXmlDocument *myDoc = new TiXmlDocument(ws2s(filePath).c_str());
	bool loadOk = myDoc->LoadFile();
	if (!loadOk)
	{
		return;
	}
	//��ø�Ԫ��
	TiXmlElement *RootElement = myDoc->RootElement();
	//�����ҵ�item��ʼ�ĵط�
	findTemplateChild(RootElement);
	int16 levelnumber = 1;

	findPrmTreeChild(templateEle, levelnumber, node);
}

void GTSD_XML::findPrmTreeChild(TiXmlElement* parentnode, int16 levelNum, Cprm_tree_node** tree_node /*= NULL*/)
{
	//child����
	int16   childnumber = 0;

	for (TiXmlElement* item = parentnode->FirstChildElement("item"); item; item = item->NextSiblingElement("item"))
	{
		//׼����״�ṹ����̬node
		Cprm_tree_node* pnode_tmp = new Cprm_tree_node();

		PRM_FILE tmp;
		TiXmlElement* node;//�������nod
		TiXmlElement* node_internal;
		string  Text;

		node = item->FirstChildElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.memberType = s2ws(Text);

		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.memberName = s2ws(Text);

		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.value = s2ws(Text);

		node = node->NextSiblingElement();
		node_internal = node->FirstChildElement();
		Text = node_internal->GetText();
		tmp.addressOffset = (int32)String2Int((string)Text);

		pnode_tmp->prmFile = tmp;
		pnode_tmp->treelevel = (levelNum - 1);
		pnode_tmp->parent = NULL;

		node = node->NextSiblingElement();
		if ((node != NULL) && (((string)(node->Value())) == "item"))
		{
			//������ӽڵ㣬��ô�Ƚ����ڵ�ѹ��ջ�С�
			pnode_tmp->hasChildren = 1;
			pnode_tmp->childNumber = 0;
			g_prm_tree->stack_prmFile_tree->push(pnode_tmp);

			//�����ӽڵ�
			findPrmTreeChild(item, levelNum + 1);

		}
		else
		{
			//���û���ӽڵ㣬��ôֱ��ѹ��ջ�С�
			pnode_tmp->hasChildren = 0;
			pnode_tmp->childNumber = 0;
			g_prm_tree->stack_prmFile_tree->push(pnode_tmp);
		}
	}
	//����ͬ��ɨ�����
	Cprm_tree_node* node_top = NULL;
	if (levelNum != 1)
	{

		//�����ж��Ƿ�stackΪ��
		if ((g_prm_tree->stack_prmFile_tree->empty()))
		{
			return;
		}
		//��ȡstack���һ��ֵ
		node_top = g_prm_tree->stack_prmFile_tree->top();

		while (node_top->treelevel == (levelNum - 1))
		{
			//�Ƚ��ӽڵ㱣��
			g_prm_tree->vector_prmFile_tree_node->push_back(node_top);
			g_prm_tree->stack_prmFile_tree->pop();
			childnumber++;
			//�����ж��Ƿ�stackΪ��
			if ((g_prm_tree->stack_prmFile_tree->empty()))
			{
				return;
			}
			else
			{
				node_top = g_prm_tree->stack_prmFile_tree->top();
			}
		}

		for (int16 i = 0; i < childnumber; i++)
		{
			((Cprm_tree_node*)((*(g_prm_tree->vector_prmFile_tree_node))[i]))->parent = node_top;
			node_top->children.push_back(((Cprm_tree_node*)((*(g_prm_tree->vector_prmFile_tree_node))[childnumber - 1 - i])));
		}
		node_top->childNumber = childnumber;
	}
	else
	{
		//��ȡstackֵ
		node_top = g_prm_tree->stack_prmFile_tree->top();

		while (node_top->treelevel == (levelNum - 1))
		{
			//�Ƚ��ӽڵ㱣��
			g_prm_tree->vector_prmFile_tree_node->push_back(node_top);
			g_prm_tree->stack_prmFile_tree->pop();
			childnumber++;
			//�����ж��Ƿ�stackΪ��
			if ((g_prm_tree->stack_prmFile_tree->empty()))
			{
				//�������
				break;
			}
			else
			{
				node_top = g_prm_tree->stack_prmFile_tree->top();
			}
		}

		Cprm_tree_node* node_top_inter = new Cprm_tree_node();
		node_top_inter->prmFile.memberType = L"void";
		node_top_inter->prmFile.memberName = L"AllAxisPrm";
		node_top_inter->prmFile.value = L"0";
		node_top_inter->prmFile.addressOffset = -1;

		for (int16 i = 0; i < childnumber; i++)
		{
			((Cprm_tree_node*)((*(g_prm_tree->vector_prmFile_tree_node))[i]))->parent = node_top_inter;
			node_top_inter->children.push_back(((Cprm_tree_node*)((*(g_prm_tree->vector_prmFile_tree_node))[childnumber - 1 - i])));
		}
		node_top_inter->childNumber = childnumber;

		//�����Ǹ�Ԫ�أ���ô�丸�ڵ���������
		if (((string)(parentnode->Value())) == "widget")
		{
			node_top_inter->hasChildren = 1;
			node_top_inter->parent = NULL;
			node_top_inter->treelevel = -1;
			*tree_node = node_top_inter;
		}
	}
	//����ӽڵ����������´�ʹ��
	g_prm_tree->vector_prmFile_tree_node->clear();
}



void GTSD_XML::saveFramPrmTreeAll(wstring& filepathT, wstring& filepath, list<PRM_FILE>* vlist, Cprm_tree_node** tree_node, int16 axisNum)
{
	//����һ��XML���ĵ�����
	TiXmlDocument* myDoc = new TiXmlDocument();
	TiXmlElement* node = NULL;

	//���ȶ�ȡģ��xml�ļ��������в����µ�����
	node = loadTemplate(filepathT, myDoc);

	//д��column
	string strName = "memberType";
	writeColumn(node, strName);
	strName = "memberName";
	writeColumn(node, strName);
	strName = "value";
	writeColumn(node, strName);
	strName = "addressOffset";
	writeColumn(node, strName);

	list<PRM_FILE>::iterator itaxis = vlist[1].begin();
	for (int16 axis = 0; axis < (2*axisNum); ++axis)
	{
		//������̬�ڵ�
		TiXmlElement* tmp = NULL;
		string axisname = "item";
		//�������ڵ�
		tmp = createFramPrmAllElement(node, axisname, (*itaxis));
		WritePrmChild((*tree_node)->children[axis], tmp);
		itaxis++;
	}

	myDoc->SaveFile((ws2s(filepath)).c_str());
}

void GTSD_XML::WritePrmChild(Cprm_tree_node* node, TiXmlElement* parent)
{
	//�������ӽڵ�
	if (node->hasChildren)
	{
		//�����ӽڵ�
		for (vector<Cprm_tree_node*>::iterator it = node->children.begin(); node->children.end() != it; it++)
		{
			if ((*it)->hasChildren)
			{
				string name = "item";
				TiXmlElement* tmp;
				tmp = createFramPrmAllElement(parent, name, (*it)->prmFile);
				WritePrmChild((*it), tmp);
			}
			else
			{
				string name = "item";
				TiXmlElement* tmp;
				tmp = createFramPrmAllElement(parent, name, (*it)->prmFile);
			}
		}
	}
}

TiXmlElement* GTSD_XML::createFramPrmAllElement(TiXmlElement* parentelement, string elename, PRM_FILE& it)
{
	//����Ԫ��
	TiXmlElement* element = new TiXmlElement(elename);
	parentelement->LinkEndChild(element);

	writeblock(element, (ws2s((it).memberType)));
	writeblock(element, (ws2s((it).memberName)));
	writeblock(element, (ws2s((it).value)));
	writeblock(element, Int2String((it).addressOffset));

	return element;
}
