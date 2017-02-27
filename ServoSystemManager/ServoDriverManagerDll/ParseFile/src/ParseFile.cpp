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
		//��ʼ����������Ҫ��ֵ
		InitParseFile();

		//����ѭ���ļ�
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
	ScanKeyWord.push_back(L"#define"); //����#define���ҹ��ܣ����Ը��ݴ��ҵ�����ĺ궨�����

	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);
	ScanKeyWordFlag.push_back(false);

	//����Ժ�����Ҫɨ���#define�����������
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
		//����һ���ַ���,����rtΪ���ص��ַ���
		rtn = parseOneLine(sr, rt);

		switch (rtn)
		{
			//�ҵ��ṹ��
		case SCAN_PARSE_FINDTYPEDEFSTRUCT:
			GetStructMember(file);
			break;
			//�ҵ�������
		case SCAN_PARSE_FINDTYPEDEFUNION:
			GetUnionMember(file);
			break;
			//�ҵ�ö��
		case SCAN_PARSE_FINDTYPEDEFENUM:
			GetEnumMember(file);
			break;
			//�ҵ��궨��
		case SCAN_PARSE_FINDKEYWORDDEFINE:
			GetMacroDefine(rt);
			break;
			//�������
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
	//����ǿ���ֱ�ӷ���
	if (st.length() == 0)
	{
		rst = L"";
		return SCAN_PARSE_SPACELINE;
	}
	wstring		eraseStartSpace;
	//ȥ���ַ���֮ǰ�Ŀո�
	eraseStartSpace = trimstart(st);

	int16		indexNumber;
	//�ҵ�ע�͵�����ֵ
	indexNumber = eraseStartSpace.find(L"//", 0);
	if (indexNumber == 0)
	{
		//����ڿ�ͷ����ע�ͣ�ֱ�ӷ���
		rst = L"";
		return SCAN_PARSE_COMMENTLINE;
	}
	else
	{
		wstring eraseCommandLine;
		if (indexNumber == -1)
		{
			//û���ҵ�ע�ͣ�ֱ��ȥ������Ŀո�
			eraseCommandLine = trimend(eraseStartSpace);
		}
		else
		{
			//�ҵ�ע�͵���ȥ��ע�ͻ���Ӵ���Ȼ��ȥ������Ŀո�
			eraseCommandLine = eraseStartSpace.substr(0, indexNumber);
			eraseCommandLine = trimend(eraseStartSpace);
		}

		//���ҹؼ���  typedef struct enum union....
		int16 i = 0;
		for (vector<wstring>::iterator it = ScanKeyWord.begin(); ScanKeyWord.end() != it; it++)
		{
			ScanKeyWordFlag[i] = hasChildStr(eraseCommandLine, *it);
			i++;
		}
		if (!(ScanKeyWordFlag[0] || ScanKeyWordFlag[1] || ScanKeyWordFlag[2] || ScanKeyWordFlag[3] || ScanKeyWordFlag[4]))
		{
			//û�ҵ��ؼ���
			rst = L"";
			return SCAN_PARSE_NOTFINDKEYWORD;
		}
		else if (ScanKeyWordFlag[0] && ScanKeyWordFlag[1])
		{
			//�ҵ�typedef struct
			rst = eraseCommandLine;
			return SCAN_PARSE_FINDTYPEDEFSTRUCT;
		}
		else if (ScanKeyWordFlag[0] && ScanKeyWordFlag[2])
		{
			//�ҵ�typedef union
			rst = eraseCommandLine;
			return SCAN_PARSE_FINDTYPEDEFUNION;
		}
		else if (ScanKeyWordFlag[0] && ScanKeyWordFlag[3])
		{
			//�ҵ�typedef enum
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
			//�ҵ��Ĺؼ��ִ���
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
	//�����ҵ�������
	if (flag_embrace)
	{
		bool end = false;
		while (!end)
		{
			getline(file, sr);
			end = hasChildStr(sr, (rightbig));
			if (!end)
			{
				//����ǿ���
				if (sr.length() == 0)
				{
					//���У�do nothing
				}
				wstring		eraseStartSpace;
				//ȥ���ַ���֮ǰ�Ŀո�
				eraseStartSpace = trimstart(sr);

				int16		indexNumber;
				//�ҵ�ע�͵�����ֵ
				indexNumber = eraseStartSpace.find(L"//", 0);
				if (indexNumber == 0)
				{
					//���ע�������ڿ�ͷ����ô��һ�ж���ע�� do nothing 
				}
				else
				{
					//���û��ע�ͻ���ע�Ͳ��ڿ�ͷ

					//���Ȳ�ѯ�Ƿ���"(*"���ҵ��Ͳ�ѯ");",��ѯ�Ƿ��к���ָ��VoidPt
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
							//������һ�����ҵ�");"���Ǿ��˳�
						}
						else
						{
							//����һ�У����Ŷ�ȡ��ֱ����ȡ");"
							bool s_end = false;
							while (!s_end)
							{
								getline(file, sr);
								s_end = hasChildStr(sr, abnormal4);
							}
						}
					}
					else if (flag_ptr) //�����к���ָ�룬����ָ�벻�����ǹ��ĵ�
					{
						//����к���ָ�룬��ôҲ�˳���
					}
					else
					{
						//û���ҵ�"(*"
						//find ";"
						int16 indexNumber1;
						indexNumber1 = eraseStartSpace.find(L";", 0);
						if (indexNumber1 == -1)
						{
							//missing ; at the end of line
						}
						else
						{
							//��ȡȥ��ע�ͺ�;�����ֵ
							wstring eraseCommandLine;
							eraseCommandLine = eraseStartSpace.substr(0, indexNumber1);

							//ȥ�����ߵĿո�
							wstring erasetrim;
							erasetrim = trim(eraseCommandLine);

							//���տո��ַ����ָ�
							vector<wstring> vec;
							splitStr(erasetrim, vec);

							//�����bit�Ľṹ��
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
							//��bit�Ľṹ��
							else if (vec.size() == 2)
							{
								tmp.bitWidth = -1;
								tmp.bitStart = -1;
							}
							else
							{
								//do nothing
							}

							//���粻��λ�����ṹ�壬��ô��Ҫ�鿴�Ƿ�������,��vec[1]����
							if (tmp.bitWidth == -1)
							{
								//���Ȳ鿴�Ƿ�������
								bool hasBraceLeft	= false;
								bool hasBraceRight	= false;
								hasBraceLeft		= hasChildStr(vec[1], leftnormal);
								hasBraceRight		= hasChildStr(vec[1], rightnormal);

								if (hasBraceLeft && hasBraceRight)
								{
									//ȥ�����飬��ȡ����ĳ���
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
									//��������ӵ����鳤�Ⱥ궨�壬��Ҫ����������,������ĸ����Ǻ궨���ʱ��
									if (L"SERVO_AXIS_NUM" == arraytmp)
									{
										arraylenth = 0;//Ϊ������Щ�궨������鲻��������ʹ��
									}
									else if (MacroDefine.find(arraytmp) != MacroDefine.end())
									{
										it = (MacroDefine.find(arraytmp));
										arraylenth = it->second;
									}
									else
									{
										wstringstream ss;
										ss << arraytmp;		//�����ַ���
										ss >> arraylenth;	//string -> int
									}

									//��ȡ����
									indexNumber2 = vectmp.find(L"[", 0);
									arraytmp = vectmp.substr(0, indexNumber2);

									//��ȡ���������֣���������������
									tmp.memberType = vec[0];
									if (arraylenth == 0)
									{
										//������SERVO_AXIS_NUM�����飬��ô����ȥ�����ŵ�
										tmp.memberName = arraytmp;
									}
									else
									{
										tmp.memberName = vectmp;
									}

									//ֻ�����鳤�ȴ������ʱ���д��
									if (arraylenth > 0)
									{
										//ѭ������ĳ���
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
										//Ϊ����һ��ģ���еĶ�����飬��Ҫ���
										arraymemlisttmp.clear();
									}
								}
								else
								{
									//����û���ҵ����ţ�˵����������
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
				//��ȡ����󣬻�ȡ�ṹ�������
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
	//�����ҵ�������
	if (flag_embrace)
	{
		bool end = false;
		while (!end)
		{
			getline(file, sr);
			end = hasChildStr(sr, (rightbig));
			if (!end)
			{
				//����ǿ���
				if (sr.length() == 0)
				{
					//���У�do nothing
				}
				wstring		eraseStartSpace;
				//ȥ���ַ���֮ǰ�Ŀո�
				eraseStartSpace = trimstart(sr);

				int16		indexNumber;
				//�ҵ�ע�͵�����ֵ
				indexNumber = eraseStartSpace.find(L"//", 0);
				if (indexNumber == 0)
				{
					//���ע�������ڿ�ͷ����ô��һ�ж���ע�� do nothing 
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
						//��ȡȥ��ע�ͺ�;�����ֵ
						wstring eraseCommandLine;
						eraseCommandLine = eraseStartSpace.substr(0, indexNumber1);

						//ȥ�����ߵĿո�
						wstring erasetrim;
						erasetrim = trim(eraseCommandLine);

						//���տո��ַ����ָ�
						vector<wstring> vec;
						splitStr(erasetrim, vec);

						tmp.memberType = vec[0];
						tmp.memberName = vec[1];

					
						//���Ȳ鿴�Ƿ�������
						bool hasBraceLeft = false;
						bool hasBraceRight = false;
						hasBraceLeft = hasChildStr(vec[1], leftnormal);
						hasBraceRight = hasChildStr(vec[1], rightnormal);

						if (hasBraceLeft && hasBraceRight)
						{
							//ȥ�����飬��ȡ����ĳ���
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
							//��������ӵ����鳤�Ⱥ궨�壬��Ҫ����������,������ĸ����Ǻ궨���ʱ��
							if (L"SERVO_AXIS_NUM" == arraytmp)
							{
								arraylenth = 0;//Ϊ������Щ�궨������鲻��������ʹ��
							}
							else if (MacroDefine.find(arraytmp) != MacroDefine.end())
							{
								it = (MacroDefine.find(arraytmp));
								arraylenth = it->second;
							}
							else
							{
								wstringstream ss;
								ss << arraytmp;		//�����ַ���
								ss >> arraylenth;	//string -> int
							}

							//��ȡ����
							indexNumber2 = vectmp.find(L"[", 0);
							arraytmp = vectmp.substr(0, indexNumber2);

							//��ȡ���������֣���������������
							tmp.memberType = vec[0];
							if (arraylenth == 0)
							{
								//������SERVO_AXIS_NUM�����飬��ô����ȥ�����ŵ�
								tmp.memberName = arraytmp;
							}
							else
							{
								tmp.memberName = vectmp;
							}

							//ֻ�����鳤�ȴ������ʱ���д��
							if (arraylenth > 0)
							{
								//ѭ������ĳ���
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
								//Ϊ����һ��ģ���еĶ�����飬��Ҫ���
								arraymemlisttmp.clear();
							}
						}
						else
						{
							//����û���ҵ����ţ�˵����������
							tmp.memberType = vec[0];
							tmp.memberName = vec[1];
						}
						unionlisttmp.push_back(tmp);
					}
				}
			}
			else
			{
				//��ȡ����󣬻�ȡ�����������
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
	//�����ҵ�������
	if (flag_embrace)
	{
		bool end = false;
		while (!end)
		{
			getline(file, sr);
			end = hasChildStr(sr, (rightbig));
			if (!end)
			{
				//����ǿ���
				if (sr.length() == 0)
				{
					//���У�do nothing
				}
				wstring		eraseStartSpace;
				//ȥ���ַ���֮ǰ�Ŀո�
				eraseStartSpace = trimstart(sr);

				int16		indexNumber;
				//�ҵ�ע�͵�����ֵ
				indexNumber = eraseStartSpace.find(L"//", 0);
				if (indexNumber == 0)
				{
					//���ע�������ڿ�ͷ����ô��һ�ж���ע�� do nothing 
				}
				else
				{
					wstring eraseCommandLine;
					if (indexNumber == -1)
					{
						//û��ע��
						eraseCommandLine = eraseStartSpace;
					}
					else
					{
						//ȥ��ע��		
						eraseCommandLine = eraseStartSpace.substr(0, indexNumber);
					}

					//ȥ�����ߵĿո�
					wstring erasetrim;
					erasetrim = trim(eraseCommandLine);

					//���տո��ַ����ָ�
					vector<wstring> vec;
					splitStr(erasetrim, vec);
					//ת��Ϊ����
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
				//��ȡ����󣬻�ȡö�ٵ�����
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

//�궨��Ҫ�����鶨��֮ǰ���ļ�����ſɡ�
int16 CParseHfile::GetMacroDefine(wstring& rt)
{
	vector<wstring> vec;
	int32 tmp;
	splitStr(rt, vec);

	//�����궨��ؼ���
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

