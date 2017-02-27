//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	parse file to get useful info		 						//
//	file				:	ParseFile.cpp												//
//	Description			:	use for parse file to get useful info						//
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

#include "Basetype_def.h"
#include "StringHandler.h"
#include "ParseFile.h"
//////////////////////////////////////////////////////////////////////////

CParseHfile* g_parseHfile = NULL;

////////////////////////////////////////////////////////////////////////////////////////
CParseHfile::CParseHfile()
{
	
}

CParseHfile::~CParseHfile()
{

}

int16 CParseHfile::ParseAllHFile(vector<wstring>& filename)
{
	if (filename.size()<1)
	{
		return -1;
	}
	else
	{
		//初始化解析所需要的值
		InitParseFile();

		//依次循环文件
		for (vector<wstring>::iterator it_file = filename.begin(); filename.end() != it_file; it_file++)
		{
			readHeaderFile(*it_file);
		}
	}
	return 0;
}

int16 CParseHfile::GetVersionString(wstring& strVer)
{
	string verName;
	verName = Int2String(softWareVersion);
	verName = "Xml_V" + verName;
	strVer = s2ws(verName);
	return 0;
}

int16 CParseHfile::InitParseFile()
{
	ScanKeyWord.clear();
	ScanKeyWordFlag.clear();
	MacroDefine.clear();

	ScanKeyWord.push_back(L"typedef");
	ScanKeyWord.push_back(L"struct");
	ScanKeyWord.push_back(L"union");
	ScanKeyWord.push_back(L"enum");
	ScanKeyWord.push_back(L"#define"); //增加#define查找功能，可以根据此找到数组的宏定义个数

	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);

	//如果以后有需要扫描的#define，在这里添加
	MacroDefine.insert(make_pair(L"TQR_FIT_LEVELS", 0));
	MacroDefine.insert(make_pair(L"VELR_FIT_LEVELS", 0));
	MacroDefine.insert(make_pair(L"PCMD_FIT_LEVELS", 0));
	MacroDefine.insert(make_pair(L"PCMD_BUF_NUM", 0));
	MacroDefine.insert(make_pair(L"VEL_CMD_SET_NUM", 0));
	MacroDefine.insert(make_pair(L"SERVO_DRV_SOFTWARE_VERSION", 0));
	MacroDefine.insert(make_pair(L"SERVO_AXIS_NUM", 0));
	MacroDefine.insert(make_pair(L"SERVO_DRV_PRM_FUNC_MODULE_NUM", 0));
	MacroDefine.insert(make_pair(L"LOG_REN_ALM_MAX", 0));
	MacroDefine.insert(make_pair(L"LOG_ALARM_KINDS_NUMNER", 0));
	return 0;
}

int16 CParseHfile::readHeaderFile(wstring& filename)
{
	wfstream file;
	file.open(filename.c_str());
	if (!file)
	{
		return SCAN_READ_OPENFILE_ERR;
	}
	wstring sr;
	wstring rt = L"";
	while (getline(file, sr))
	{
		int16 rtn;
		//解析一行字符串,其中rt为返回的字符串
		rtn = parseOneLine(sr, rt);

		switch (rtn)
		{
			//找到结构体
		case SCAN_PARSE_FINDTYPEDEFSTRUCT:
			GetStructMember(file);
			break;
			//找到联合体
		case SCAN_PARSE_FINDTYPEDEFUNION:
			GetUnionMember(file);
			break;
			//找到枚举
		case SCAN_PARSE_FINDTYPEDEFENUM:
			GetEnumMember(file);
			break;
			//找到宏定义
		case SCAN_PARSE_FINDKEYWORDDEFINE:
			GetMacroDefine(rt);
			break;
			//其他情况
		case SCAN_PARSE_SPACELINE:
		case SCAN_PARSE_COMMENTLINE:
		case SCAN_PARSE_NOTFINDKEYWORD:
		case SCAN_PARSE_FINDKEYWORDERROR:
			break;
		default:
			break;
		}
	}
	file.close();

	return 0;
}

int16 CParseHfile::parseOneLine(wstring& st, wstring& rst)
{
	//如果是空行直接返回
	if (st.length() == 0)
	{
		rst = L"";
		return SCAN_PARSE_SPACELINE;
	}
	wstring		eraseStartSpace;
	//去掉字符串之前的空格
	eraseStartSpace = trimstart(st);

	int16		indexNumber;
	//找到注释的索引值
	indexNumber = eraseStartSpace.find(L"//", 0);
	if (indexNumber == 0)
	{
		//如果在开头就是注释，直接返回
		rst = L"";
		return SCAN_PARSE_COMMENTLINE;
	}
	else
	{
		wstring eraseCommandLine;
		if (indexNumber == -1)
		{
			//没有找到注释，直接去掉后面的空格
			eraseCommandLine = trimend(eraseStartSpace);
		}
		else
		{
			//找到注释的先去掉注释获得子串，然后去掉后面的空格
			eraseCommandLine = eraseStartSpace.substr(0, indexNumber);
			eraseCommandLine = trimend(eraseStartSpace);
		}

		//查找关键字  typedef struct enum union....
		int16 i = 0;
		for (vector<wstring>::iterator it = ScanKeyWord.begin(); ScanKeyWord.end() != it; it++)
		{
			ScanKeyWordFlag[i] = hasChildStr(eraseCommandLine, *it);
			i++;
		}
		if (!(ScanKeyWordFlag[0] || ScanKeyWordFlag[1] || ScanKeyWordFlag[2] || ScanKeyWordFlag[3] || ScanKeyWordFlag[4]))
		{
			//没找到关键字
			rst = L"";
			return SCAN_PARSE_NOTFINDKEYWORD;
		}
		else if (ScanKeyWordFlag[0] && ScanKeyWordFlag[1])
		{
			//找到typedef struct
			rst = eraseCommandLine;
			return SCAN_PARSE_FINDTYPEDEFSTRUCT;
		}
		else if (ScanKeyWordFlag[0] && ScanKeyWordFlag[2])
		{
			//找到typedef union
			rst = eraseCommandLine;
			return SCAN_PARSE_FINDTYPEDEFUNION;
		}
		else if (ScanKeyWordFlag[0] && ScanKeyWordFlag[3])
		{
			//找到typedef enum
			rst = eraseCommandLine;
			return SCAN_PARSE_FINDTYPEDEFENUM;
		}
		else if (ScanKeyWordFlag[4])
		{
			rst = eraseCommandLine;
			return SCAN_PARSE_FINDKEYWORDDEFINE;
		}
		else
		{
			//找到的关键字错误
			rst = L"";
			return SCAN_PARSE_FINDKEYWORDERROR;
		}
	}
}

int16 CParseHfile::GetStructMember(wfstream& file)
{
	STRUCTMEM tmp;
	list<STRUCTMEM> structlist;
	ARRAYMEM  arraymemtmp;
	list<ARRAYMEM>  arraymemlisttmp;
	ARRAYLIST arraylisttmp;

	int16 bitSum = 0;

	wstring leftbig = L"{";
	wstring rightbig = L"}";
	wstring leftnormal = L"[";
	wstring rightnormal = L"]";

	wstring abnormal1 = L"(*";
	wstring abnormal2 = L");";
	wstring abnormal3 = L"VoidPt";
	wstring abnormal4 = L");";

	wstring sr;
	bool flag_embrace = false;
	while (!flag_embrace)
	{
		//step1: check {
		getline(file, sr);
		flag_embrace = hasChildStr(sr, (leftbig));
	}
	//假如找到大括号
	if (flag_embrace)
	{
		bool end = false;
		while (!end)
		{
			getline(file, sr);
			end = hasChildStr(sr, (rightbig));
			if (!end)
			{
				//如果是空行
				if (sr.length() == 0)
				{
					//空行，do nothing
				}
				wstring		eraseStartSpace;
				//去掉字符串之前的空格
				eraseStartSpace = trimstart(sr);

				int16		indexNumber;
				//找到注释的索引值
				indexNumber = eraseStartSpace.find(L"//", 0);
				if (indexNumber == 0)
				{
					//如果注释索引在开头，那么这一行都是注释 do nothing 
				}
				else
				{
					//如果没有注释或者注释不在开头

					//首先查询是否有"(*"，找到就查询");",查询是否有函数指针VoidPt
					bool flag_sembrace = false;
					bool flag_sembrace1 = false;
					bool flag_ptr = false;
					flag_sembrace = hasChildStr(eraseStartSpace, abnormal1);
					flag_sembrace1 = hasChildStr(eraseStartSpace, abnormal2);
					flag_ptr = hasChildStr(eraseStartSpace, abnormal3);
					if (flag_sembrace)
					{
						if (flag_sembrace1)
						{
							//假如在一行中找到");"，那就退出
						}
						else
						{
							//不在一行，接着读取，直到读取");"
							bool s_end = false;
							while (!s_end)
							{
								getline(file, sr);
								s_end = hasChildStr(sr, abnormal4);
							}
						}
					}
					else if (flag_ptr) //假如有函数指针，函数指针不是我们关心的
					{
						//如果有函数指针，那么也退出。
					}
					else
					{
						//没有找到"(*"
						//find ";"
						int16 indexNumber1;
						indexNumber1 = eraseStartSpace.find(L";", 0);
						if (indexNumber1 == -1)
						{
							//missing ; at the end of line
						}
						else
						{
							//获取去掉注释和;后面的值
							wstring eraseCommandLine;
							eraseCommandLine = eraseStartSpace.substr(0, indexNumber1);

							//去掉两边的空格
							wstring erasetrim;
							erasetrim = trim(eraseCommandLine);

							//按照空格将字符串分割
							vector<wstring> vec;
							splitStr(erasetrim, vec);

							//如果是bit的结构体
							if (vec.size() == 4)
							{
								int32 bittmp;
								tmp.memberType = vec[0];
								tmp.memberName = vec[1];
								wstringstream ss;
								ss << vec[3];
								ss >> bittmp;
								tmp.bitWidth   = (int16)bittmp;
								bitSum		   += (int16)bittmp;
								tmp.bitStart   = bitSum - (int16)bittmp;
							}
							//非bit的结构体
							else if (vec.size() == 2)
							{
								tmp.bitWidth = -1;
								tmp.bitStart = -1;
							}
							else
							{
								//do nothing
							}

							//假如不是位操作结构体，那么需要查看是否有数组,从vec[1]中找
							if (tmp.bitWidth == -1)
							{
								//首先查看是否有数组
								bool hasBraceLeft	= false;
								bool hasBraceRight	= false;
								hasBraceLeft		= hasChildStr(vec[1], leftnormal);
								hasBraceRight		= hasChildStr(vec[1], rightnormal);

								if (hasBraceLeft && hasBraceRight)
								{
									//去掉数组，提取数组的长度
									int16 indexNumber2;
									int32 arraylenth;
									wstring arraytmp;
									wstring vectmp;
									vectmp = vec[1];

									indexNumber2	= vec[1].find(L"[", 0);
									arraytmp		= vec[1].erase(0, indexNumber2 + 1);

									indexNumber2	= arraytmp.find(L"]", 0);
									arraytmp		= arraytmp.substr(0, indexNumber2);


									map<wstring, int32>::iterator it;
									//如果有增加的数组长度宏定义，需要在这里增加,当数组的个数是宏定义的时候
									if (L"SERVO_AXIS_NUM" == arraytmp)
									{
										arraylenth = 0;//为了让这些宏定义的数组不当成数组使用
									}
									else if (MacroDefine.find(arraytmp) != MacroDefine.end())
									{
										it = (MacroDefine.find(arraytmp));
										arraylenth = it->second;
									}
									else
									{
										wstringstream ss;
										ss << arraytmp;		//输入字符串
										ss >> arraylenth;	//string -> int
									}

									//获取名字
									indexNumber2 = vectmp.find(L"[", 0);
									arraytmp = vectmp.substr(0, indexNumber2);

									//获取完整的名字，包含中括号括号
									tmp.memberType = vec[0];
									if (arraylenth == 0)
									{
										//假如是SERVO_AXIS_NUM的数组，那么就用去掉括号的
										tmp.memberName = arraytmp;
									}
									else
									{
										tmp.memberName = vectmp;
									}

									//只有数组长度大于零的时候才写入
									if (arraylenth > 0)
									{
										//循环数组的长度
										for (int i = 0; i < arraylenth; i++)
										{
											wstring strtmp;
											wstringstream ss;
											ss << i;
											ss >> strtmp;
											arraymemtmp.memberType = vec[0];
											arraymemtmp.memberName = arraytmp + L"[" + strtmp + L"]";
											arraymemlisttmp.push_back(arraymemtmp);
										}
										arraylisttmp.arrayLength = arraylenth;
										arraylisttmp.alist = arraymemlisttmp;
										Arraymap.insert(make_pair(vectmp, arraylisttmp));
										//为了在一个模块中的多个数组，需要清空
										arraymemlisttmp.clear();
									}
								}
								else
								{
									//假如没有找到括号，说明不是数组
									tmp.memberType = vec[0];
									tmp.memberName = vec[1];
								}

							}
							structlist.push_back(tmp);
						}

					}

				}
			}
			else
			{
				//读取到最后，获取结构体的名字
				int16 indexNumber3;
				int16 indexNumber4;
				indexNumber3 = sr.find(L"}", 0);
				indexNumber4 = sr.find(L";", 0);
				wstring structName;
				structName = sr.substr(indexNumber3 + 1, indexNumber4 - 1);
				Structmap.insert(make_pair(structName, structlist));
			}
		}
	}
	return 0;
}

int16 CParseHfile::GetUnionMember(wfstream& file)
{
	UNIONMEM  tmp;
	wstring sr;
	list<UNIONMEM> unionlisttmp;

	ARRAYMEM  arraymemtmp;
	list<ARRAYMEM>  arraymemlisttmp;
	ARRAYLIST arraylisttmp;

	wstring leftbig = L"{";
	wstring rightbig = L"}";
	wstring leftnormal = L"[";
	wstring rightnormal = L"]";


	bool flag_embrace = false;
	while (!flag_embrace)
	{
		//step1: check {
		getline(file, sr);
		flag_embrace = hasChildStr(sr, (leftbig));
	}
	//假如找到大括号
	if (flag_embrace)
	{
		bool end = false;
		while (!end)
		{
			getline(file, sr);
			end = hasChildStr(sr, (rightbig));
			if (!end)
			{
				//如果是空行
				if (sr.length() == 0)
				{
					//空行，do nothing
				}
				wstring		eraseStartSpace;
				//去掉字符串之前的空格
				eraseStartSpace = trimstart(sr);

				int16		indexNumber;
				//找到注释的索引值
				indexNumber = eraseStartSpace.find(L"//", 0);
				if (indexNumber == 0)
				{
					//如果注释索引在开头，那么这一行都是注释 do nothing 
				}
				else
				{
					//find ";"
					int16 indexNumber1;
					indexNumber1 = eraseStartSpace.find(L";", 0);
					if (indexNumber1 == -1)
					{
						//missing ; at the end of line
					}
					else
					{
						//获取去掉注释和;后面的值
						wstring eraseCommandLine;
						eraseCommandLine = eraseStartSpace.substr(0, indexNumber1);

						//去掉两边的空格
						wstring erasetrim;
						erasetrim = trim(eraseCommandLine);

						//按照空格将字符串分割
						vector<wstring> vec;
						splitStr(erasetrim, vec);

						tmp.memberType = vec[0];
						tmp.memberName = vec[1];

					
						//首先查看是否有数组
						bool hasBraceLeft = false;
						bool hasBraceRight = false;
						hasBraceLeft = hasChildStr(vec[1], leftnormal);
						hasBraceRight = hasChildStr(vec[1], rightnormal);

						if (hasBraceLeft && hasBraceRight)
						{
							//去掉数组，提取数组的长度
							int16 indexNumber2;
							int32 arraylenth;
							wstring arraytmp;
							wstring vectmp;
							vectmp = vec[1];

							indexNumber2 = vec[1].find(L"[", 0);
							arraytmp = vec[1].erase(0, indexNumber2 + 1);

							indexNumber2 = arraytmp.find(L"]", 0);
							arraytmp = arraytmp.substr(0, indexNumber2);


							map<wstring, int32>::iterator it;
							//如果有增加的数组长度宏定义，需要在这里增加,当数组的个数是宏定义的时候
							if (L"SERVO_AXIS_NUM" == arraytmp)
							{
								arraylenth = 0;//为了让这些宏定义的数组不当成数组使用
							}
							else if (MacroDefine.find(arraytmp) != MacroDefine.end())
							{
								it = (MacroDefine.find(arraytmp));
								arraylenth = it->second;
							}
							else
							{
								wstringstream ss;
								ss << arraytmp;		//输入字符串
								ss >> arraylenth;	//string -> int
							}

							//获取名字
							indexNumber2 = vectmp.find(L"[", 0);
							arraytmp = vectmp.substr(0, indexNumber2);

							//获取完整的名字，包含中括号括号
							tmp.memberType = vec[0];
							if (arraylenth == 0)
							{
								//假如是SERVO_AXIS_NUM的数组，那么就用去掉括号的
								tmp.memberName = arraytmp;
							}
							else
							{
								tmp.memberName = vectmp;
							}

							//只有数组长度大于零的时候才写入
							if (arraylenth > 0)
							{
								//循环数组的长度
								for (int i = 0; i < arraylenth; i++)
								{
									wstring strtmp;
									wstringstream ss;
									ss << i;
									ss >> strtmp;
									arraymemtmp.memberType = vec[0];
									arraymemtmp.memberName = arraytmp + L"[" + strtmp + L"]";
									arraymemlisttmp.push_back(arraymemtmp);
								}
								arraylisttmp.arrayLength = arraylenth;
								arraylisttmp.alist = arraymemlisttmp;
								Arraymap.insert(make_pair(vectmp, arraylisttmp));
								//为了在一个模块中的多个数组，需要清空
								arraymemlisttmp.clear();
							}
						}
						else
						{
							//假如没有找到括号，说明不是数组
							tmp.memberType = vec[0];
							tmp.memberName = vec[1];
						}
						unionlisttmp.push_back(tmp);
					}
				}
			}
			else
			{
				//读取到最后，获取联合体的名字
				int16 indexNumber1;
				int16 indexNumber2;
				indexNumber1 = sr.find(L"}", 0);
				indexNumber2 = sr.find(L";", 0);
				wstring unionName;
				unionName = sr.substr(indexNumber1 + 1, indexNumber2 - 1);
				Unionmap.insert(make_pair(unionName, unionlisttmp));
			}
		}
	}
	return 0;
}

int16 CParseHfile::GetEnumMember(wfstream& file)
{
	list<ENUMMEM>	enumlisttmp;
	ENUMMEM  tmp;
	wstring leftbig = L"{";
	wstring rightbig = L"}";
	wstring sr;
	bool flag_embrace = false;
	while (!flag_embrace)
	{
		//step1: check {
		getline(file, sr);
		flag_embrace = hasChildStr(sr, (leftbig));
	}
	//假如找到大括号
	if (flag_embrace)
	{
		bool end = false;
		while (!end)
		{
			getline(file, sr);
			end = hasChildStr(sr, (rightbig));
			if (!end)
			{
				//如果是空行
				if (sr.length() == 0)
				{
					//空行，do nothing
				}
				wstring		eraseStartSpace;
				//去掉字符串之前的空格
				eraseStartSpace = trimstart(sr);

				int16		indexNumber;
				//找到注释的索引值
				indexNumber = eraseStartSpace.find(L"//", 0);
				if (indexNumber == 0)
				{
					//如果注释索引在开头，那么这一行都是注释 do nothing 
				}
				else
				{
					wstring eraseCommandLine;
					if (indexNumber == -1)
					{
						//没有注释
						eraseCommandLine = eraseStartSpace;
					}
					else
					{
						//去掉注释		
						eraseCommandLine = eraseStartSpace.substr(0, indexNumber);
					}

					//去掉两边的空格
					wstring erasetrim;
					erasetrim = trim(eraseCommandLine);

					//按照空格将字符串分割
					vector<wstring> vec;
					splitStr(erasetrim, vec);
					//转化为整形
					int32 inttmp;
					wstringstream ss;
					ss << vec[2];
					ss >> inttmp;
					tmp.memberName = vec[0];
					tmp.memberValue = inttmp;
					enumlisttmp.push_back(tmp);
				}
			}
			else
			{
				//读取到最后，获取枚举的名字
				int16 indexNumber1;
				int16 indexNumber2;
				indexNumber1 = sr.find(L"}", 0);
				indexNumber2 = sr.find(L";", 0);
				wstring enumName;
				enumName = sr.substr(indexNumber1 + 1, indexNumber2 - 1);
				Enummap.insert(make_pair(enumName, enumlisttmp));
			}
		}
	}
	return 0;
}

//宏定义要在数组定义之前的文件定义才可。
int16 CParseHfile::GetMacroDefine(wstring& rt)
{
	vector<wstring> vec;
	int32 tmp;
	splitStr(rt, vec);

	//遍历宏定义关键字
	for (map<wstring, int32>::iterator it = MacroDefine.begin(); MacroDefine.end() != it; it++)
	{
		if ((*it).first == vec[1])
		{
			wstringstream wss;
			wss << vec[2];
			wss >> tmp;
			(*it).second = (tmp);

			if (vec[1] == L"SERVO_AXIS_NUM")
			{
				AxisNumDefine = (int16)tmp;
			}
			else if (vec[1] == L"SERVO_DRV_SOFTWARE_VERSION")
			{
				softWareVersion = (int16)tmp;
			}
			else if (vec[1] == L"SERVO_DRV_PRM_FUNC_MODULE_NUM")
			{
				funcModuleNum = (int16)tmp;
			}
			else 
			{ }
			
		}
	}
	return 0;

}

