//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	parse file to get useful info		 						//
//	file				:	ParseFile.h													//
//	Description			:	use for parse file to get useful info						//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef  __GTSD_PARSE_FILE__
#define  __GTSD_PARSE_FILE__


//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//ɨ��Ľṹ���Ա����
//////////////////////////////////////////////////////////////////////////
typedef struct structMem
{
	wstring memberType;
	wstring memberName;
	int16 bitStart;
	int16 bitWidth;
}STRUCTMEM;
//////////////////////////////////////////////////////////////////////////
//ɨ��������е�����Ա����
//////////////////////////////////////////////////////////////////////////
typedef struct ArrayMem
{
	wstring memberType;
	wstring memberName;
}ARRAYMEM;
//////////////////////////////////////////////////////////////////////////
//ɨ������������
//////////////////////////////////////////////////////////////////////////
typedef struct Arraylist
{
	int32			arrayLength;
	list<ARRAYMEM>	alist;
}ARRAYLIST;
//////////////////////////////////////////////////////////////////////////
//ɨ���ö�ٳ�Ա����
//////////////////////////////////////////////////////////////////////////
typedef struct EnumMem
{
	wstring memberName;
	int32	memberValue;
}ENUMMEM;
//////////////////////////////////////////////////////////////////////////
//ɨ����������Ա����
//////////////////////////////////////////////////////////////////////////
typedef struct UnionMem
{
	wstring memberType;
	wstring memberName;
}UNIONMEM;

class CParseHfile
{
public:
	CParseHfile();
	~CParseHfile();

	//�洢�ؼ��ֺ͹ؼ��ֱ�־
	vector<wstring>						ScanKeyWord;
	vector<bool>						ScanKeyWordFlag;

	//�洢�����ĸ��ֽṹ
	map<wstring, list<STRUCTMEM>>		Structmap;
	map<wstring, list<UNIONMEM>>		Unionmap;
	map<wstring, list<ENUMMEM>>			Enummap;
	map<wstring, ARRAYLIST>				Arraymap;
	map<wstring, int32>					MacroDefine;
	//////////////////////////////////////////////////////////////////////////

	//�õ��ؼ��ֶ�Ӧ����Ϣ���ṹ�壬ö�٣��������
	int16 GetStructMember(wfstream& file);
	int16 GetUnionMember(wfstream& file);
	int16 GetEnumMember(wfstream& file);
	int16 GetMacroDefine(wstring& rt);

	//��ȡһ��ͷ�ļ�
	int16 readHeaderFile(wstring& filename);

	//����һ���ַ���
	int16 parseOneLine(wstring& st, wstring& rst);

	int16 InitParseFile(void);
	
	int16 ParseAllHFile(vector<wstring>& filename);

	int16 GetVersionString(wstring& strVer);

	int16 AxisNumDefine;  //��������
	int32 softWareVersion; //����汾
	int16 funcModuleNum; //����ģ����

	//////////////////////////////////////////////////////////////////////////
	static const int16		SCAN_SUCCESS					= 0;
	static const int16		SCAN_PARSE_SPACELINE			= -1;
	static const int16		SCAN_PARSE_COMMENTLINE			= -2;
	static const int16		SCAN_PARSE_NOTFINDKEYWORD		= -3;

	static const int16		SCAN_PARSE_FINDTYPEDEFSTRUCT	= -4;
	static const int16		SCAN_PARSE_FINDTYPEDEFUNION		= -5;
	static const int16		SCAN_PARSE_FINDTYPEDEFENUM		= -6;
	static const int16		SCAN_PARSE_FINDKEYWORDERROR		= -7;
	static const int16		SCAN_PARSE_FINDKEYWORDDEFINE	= -11;  //���Ӻ궨��

	static const int16		SCAN_READ_OPENFILE_ERR			= -8;
	static const int16		SCAN_READ_WRONGFILE				= -9;
	static const int16		SCAN_READ_OFST_ERR				= -10;
};
extern CParseHfile* g_parseHfile;
#endif