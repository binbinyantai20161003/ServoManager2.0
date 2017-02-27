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

#ifndef  __GTSD_STRING_HANDLER__
#define  __GTSD_STRING_HANDLER__

#include "Basetype_def.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//判断字符串st1中是否含有关键字st2
bool hasChildStr(wstring& st1, wstring& st2);

//获取中括号中的数值
int16 getBraceValue(wstring& st);

//分割字符串（根据空格）
int16 splitStr(wstring& st, vector<wstring>& vec);

//去掉字符串前或后或两者的空格
wstring& trimstart(wstring& st);
wstring& trimend(wstring& st);
wstring& trim(wstring& st);

//wstring和string转化
string ws2s(const wstring& ws);
wstring s2ws(const string& s);

//分割以点为间隔的字符串
int16 splitDotStr(wstring& st, vector<wstring>& vec);

//合成阶梯字符串
int16 combineVecStr(vector<wstring>& vec_in, vector<wstring>& vec_out);

//将字符串中的点转化为下划线，并且去掉字符串中的括号，获取括号中的值，该值通过下划线和其它部分连接
wstring NameDot2Line(wstring& str);

int32 String2Int(string& st);

string Int2String(int32 i);

string double2String(double i);

int MBSToUTF8(char * utf8, int size, const char* mbs);

int UTF8ToMBS(char * mbs, int size, const char* utf8);

#endif