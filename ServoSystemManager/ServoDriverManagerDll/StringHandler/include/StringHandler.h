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

//�ж��ַ���st1���Ƿ��йؼ���st2
bool hasChildStr(wstring& st1, wstring& st2);

//��ȡ�������е���ֵ
int16 getBraceValue(wstring& st);

//�ָ��ַ��������ݿո�
int16 splitStr(wstring& st, vector<wstring>& vec);

//ȥ���ַ���ǰ�������ߵĿո�
wstring& trimstart(wstring& st);
wstring& trimend(wstring& st);
wstring& trim(wstring& st);

//wstring��stringת��
string ws2s(const wstring& ws);
wstring s2ws(const string& s);

//�ָ��Ե�Ϊ������ַ���
int16 splitDotStr(wstring& st, vector<wstring>& vec);

//�ϳɽ����ַ���
int16 combineVecStr(vector<wstring>& vec_in, vector<wstring>& vec_out);

//���ַ����еĵ�ת��Ϊ�»��ߣ�����ȥ���ַ����е����ţ���ȡ�����е�ֵ����ֵͨ���»��ߺ�������������
wstring NameDot2Line(wstring& str);

int32 String2Int(string& st);

string Int2String(int32 i);

string double2String(double i);

int MBSToUTF8(char * utf8, int size, const char* mbs);

int UTF8ToMBS(char * mbs, int size, const char* utf8);

#endif