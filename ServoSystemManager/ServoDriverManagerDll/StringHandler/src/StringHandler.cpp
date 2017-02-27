//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	string handler		 										//
//	file				:	StringHandler.h												//
//	Description			:	use for deal with string for our wanted						//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StringHandler.h"

//////////////////////////////////////////////////////////////////////////
//判断字符串st1中是否含有关键字st2
//////////////////////////////////////////////////////////////////////////
bool hasChildStr(wstring& st1, wstring& st2)
{
	if (st1.find(st2) < st1.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}
//////////////////////////////////////////////////////////////////////////
//获取中括号中的数值，使用字符串类型 abc[3]
//没有找到任意一半中括号就返回-1
//////////////////////////////////////////////////////////////////////////
int16 getBraceValue(wstring& st)
{
	//找到括号位置
	int16 pos_start;
	int16 pos_end;
	int16 value;
	wstring tmp;
	wstring brace_start		= L"[";
	wstring brace_end		= L"]";
	pos_start				= st.find(brace_start.c_str());
	pos_end					= st.find(brace_end.c_str());
	//没找到括号
	if ((pos_start == -1) || (pos_end == -1))
	{
		return -1;
	}
	else
	{
		tmp = st.substr(pos_start + 1, pos_end - pos_start - 1);
	}

	wstringstream ss;
	ss << tmp;		//输入字符串
	ss >> value;	//string -> int

	return value;
}
//////////////////////////////////////////////////////////////////////////
//分割以空格为间隔的字符串
//////////////////////////////////////////////////////////////////////////
int16 splitStr(wstring& st, vector<wstring>& vec)
{
	wstringstream ss(st);  // 字符流ss 
	wstring buf;
	while (ss >> buf)
		vec.push_back(buf);
	return 0;
}
//////////////////////////////////////////////////////////////////////////
//去掉字符串前或后或两者的空格
//////////////////////////////////////////////////////////////////////////
wstring& trimstart(wstring& st)
{
	if (st.empty())
	{
		return st;
	}
	st.erase(0, st.find_first_not_of(L" "));
	return st;
}

wstring& trimend(wstring& st)
{
	if (st.empty())
	{
		return st;
	}
	st.erase(st.find_last_not_of(L" ") + 1);
	return st;
}
//////////////////////////////////////////////////////////////////////////
//wstring和string转化
//////////////////////////////////////////////////////////////////////////
wstring& trim(wstring& st)
{
	if (st.empty())
	{
		return st;
	}
	st.erase(0, st.find_first_not_of(L" "));
	st.erase(st.find_last_not_of(L" ") + 1);
	return st;
}
string ws2s(const wstring& ws)
{
	const wchar_t* _Source = ws.c_str();
	size_t _Dsize = 2 * ws.size() + 1;
	size_t retnum;
	char *_Dest = new char[_Dsize];
	memset(_Dest, 0, _Dsize);
	setlocale(LC_ALL, "chs");
	wcstombs_s(&retnum, _Dest, _Dsize, _Source, _Dsize);
	std::string result = _Dest;
	delete[] _Dest;
	return result;
}
wstring s2ws(const string& s)
{
	const char* _Source = s.c_str();
	size_t retnum;
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	setlocale(LC_ALL, "chs");
	mbstowcs_s(&retnum, _Dest, _Dsize, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[] _Dest;
	return result;
}
//////////////////////////////////////////////////////////////////////////
//分割以点为间隔的字符串
//////////////////////////////////////////////////////////////////////////
int16 splitDotStr(wstring& st, vector<wstring>& vec)
{
	string buf;
	buf = ws2s(st);

	const char* delim = ".";
	char* pnext = NULL;
	char* str = (char*)(buf.c_str());
	char* result = strtok_s(str, delim, &pnext);
	wstring rst;
	buf = result;
	rst = s2ws(buf);
	vec.push_back(rst);
	while (result != NULL)
	{
		result = strtok_s(NULL, delim, &pnext);
		if (result != NULL)
		{
			buf = result;
			rst = s2ws(buf);
			vec.push_back(rst);
		}
	}

	return 0;
}
//////////////////////////////////////////////////////////////////////////
//合成阶梯字符串
//////////////////////////////////////////////////////////////////////////
int16 combineVecStr(vector<wstring>& vec_in, vector<wstring>& vec_out)
{
	//该函数将vec中的分割的字符串组合成分级的字符串，例如原来vec中存储 gSevDrv ，sev_task，prm，vol_mode
	//现在vec_out输出为gSevDrv，gSevDrv.sev_task,gSevDrv.sev_task.prm,gSevDrv.sev_task.prm.vol_mode
	if (vec_in.size() < 1)
	{
		return -1;
	}
	wstring tmp = L"";
	for (vector<wstring>::iterator itlevel = vec_in.begin(); vec_in.end() != itlevel; itlevel++)
	{
		tmp += (*itlevel);
		vec_out.push_back(tmp);
		tmp += L".";
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////
//将字符串中的点转化为下划线，并且去掉字符串中的括号，获取括号中的值，该值通过下划线和其它部分连接
//////////////////////////////////////////////////////////////////////////
wstring NameDot2Line(wstring& str)
{
	vector<wstring> vec;
	splitDotStr(str, vec);
	wstring tmp = L"";

	//从第二个元素开始遍历
	vector<wstring>::iterator it = vec.begin();
	it++;
	int16 value;
	for (; vec.end() != it; it++)
	{
		//如果是括号就去掉括号
		int16 brace = (*it).find(L"[");
		wstring nobrace;
		if (brace != -1)
		{
			nobrace = (*it).substr(0, brace);
			value = getBraceValue((*it));
			wstringstream wss;
			wss << (value);
			wss >> (*it);
			(*it) = nobrace + L"_" + (*it);
		}
		else
		{
			nobrace = L"";
		}

		//转化为大写
		transform((*it).begin(), (*it).end(), (*it).begin(), toupper);
		//连接字符串
		tmp = tmp + (*it) + L"_";
	}
	//去掉最后的"_"
	int16 index;
	index = tmp.find_last_of(L"_");
	wstring tmp1;
	tmp1 = tmp.substr(0, index);

	return tmp1;
}

int32 String2Int(string& st)
{
	int32 tmp;
	stringstream ss;
	ss << st;
	ss >> tmp;
	return tmp;
}

string Int2String(int32 i)
{
	stringstream ss;
	string st;
	ss << i;
	ss >> st;
	return st;
}

string double2String(double i)
{
	stringstream ss;
	string st;
	ss << i;
	ss >> st;
	return st;
}

// MBSToUTF8: string convert functions, convert MBS string to UTF8 string.  
// @param utf8: utf8 string converted to.  
// @param size: the size of utf8 buffer passed.  
// @param mbs: mbs string that need to be converted.  
// @return: the length of result string.  
int MBSToUTF8(char * utf8, int size, const char* mbs)
{
	if (!utf8 || !mbs)
		return NULL;

	UINT nACP = GetACP();

	int dwNum = MultiByteToWideChar(nACP, 0, mbs, -1, NULL, 0);       // CP_ACP  
	if (dwNum <= 0)
		return NULL;

	wchar_t* pwText = NULL;
	pwText = new wchar_t[dwNum + 1];
	if (!pwText)
	{
		delete[] pwText;
		return NULL;
	}
	memset(pwText, 0, dwNum * 2 + 2);
	if (MultiByteToWideChar(nACP, 0, mbs, -1, pwText, dwNum) == 0)   // CP_ACP  
	{
		delete[] pwText;
		return NULL;
	}

	int dwCount = WideCharToMultiByte(CP_UTF8, 0, pwText, -1, NULL, 0, NULL, NULL);
	if (dwCount <= 0)
	{
		delete[] pwText;
		return NULL;
	}

	if (size < dwCount + 1)
	{
		delete[] pwText;
		return NULL;
	}
	memset(utf8, 0, dwCount + 1);
	if (WideCharToMultiByte(CP_UTF8, 0, pwText, -1, utf8, dwCount, NULL, NULL) == 0)
	{
		delete[] pwText;
		return NULL;
	}

	delete[] pwText;

	return dwCount;
}
// UTF8ToMBS: string convert functions, convert UTF8 string to MBS string.  
// @param mbs: mbs string converted to.  
// @param size: the size of mbs buffer passed.  
// @param utf8: utf8 string that need to be converted.  
// @return: the length of result string.  
int UTF8ToMBS(char * mbs, int size, const char* utf8)
{
	if (!utf8 || !mbs)
		return NULL;

	int dwNum = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	if (dwNum <= 0)
		return NULL;

	wchar_t* pwText = NULL;
	pwText = new wchar_t[dwNum + 1];
	if (!pwText)
	{
		delete[] pwText;
		return NULL;
	}
	memset(pwText, 0, dwNum * 2 + 2);
	if (MultiByteToWideChar(CP_UTF8, 0, utf8, -1, pwText, dwNum) == 0)
	{
		delete[] pwText;
		return NULL;
	}

	UINT nACP = GetACP();

	int dwCount = WideCharToMultiByte(nACP, 0, pwText, -1, NULL, 0, NULL, NULL);  // CP_ACP  
	if (dwCount <= 0)
	{
		delete[] pwText;
		return NULL;
	}

	if (size < dwCount + 1)
	{
		delete[] pwText;
		return NULL;
	}
	memset(mbs, 0, dwCount + 1);
	if (WideCharToMultiByte(nACP, 0, pwText, -1, mbs, dwCount, NULL, NULL) == 0) // CP_ACP  
	{
		delete[] pwText;
		return NULL;
	}

	delete[] pwText;

	return dwCount;
}