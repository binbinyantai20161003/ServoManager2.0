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
//扫描的结构体成员类型
//////////////////////////////////////////////////////////////////////////
typedef struct structMem
{
	wstring memberType;
	wstring memberName;
	int16 bitStart;
	int16 bitWidth;
}STRUCTMEM;
//////////////////////////////////////////////////////////////////////////
//扫描的数组中单个成员类型
//////////////////////////////////////////////////////////////////////////
typedef struct ArrayMem
{
	wstring memberType;
	wstring memberName;
}ARRAYMEM;
//////////////////////////////////////////////////////////////////////////
//扫描的数组的类型
//////////////////////////////////////////////////////////////////////////
typedef struct Arraylist
{
	int32			arrayLength;
	list<ARRAYMEM>	alist;
}ARRAYLIST;
//////////////////////////////////////////////////////////////////////////
//扫描的枚举成员类型
//////////////////////////////////////////////////////////////////////////
typedef struct EnumMem
{
	wstring memberName;
	int32	memberValue;
}ENUMMEM;
//////////////////////////////////////////////////////////////////////////
//扫描的联合体成员类型
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

	//存储关键字和关键字标志
	vector<wstring>						ScanKeyWord;
	vector<bool>						ScanKeyWordFlag;

	//存储解析的各种结构
	map<wstring, list<STRUCTMEM>>		Structmap;
	map<wstring, list<UNIONMEM>>		Unionmap;
	map<wstring, list<ENUMMEM>>			Enummap;
	map<wstring, ARRAYLIST>				Arraymap;
	map<wstring, int32>					MacroDefine;
	//////////////////////////////////////////////////////////////////////////

	//得到关键字对应的信息，结构体，枚举，联合体等
	int16 GetStructMember(wfstream& file);
	int16 GetUnionMember(wfstream& file);
	int16 GetEnumMember(wfstream& file);
	int16 GetMacroDefine(wstring& rt);

	//读取一个头文件
	int16 readHeaderFile(wstring& filename);

	//解析一行字符串
	int16 parseOneLine(wstring& st, wstring& rst);

	int16 InitParseFile(void);
	
	int16 ParseAllHFile(vector<wstring>& filename);

	int16 GetVersionString(wstring& strVer);

	int16 AxisNumDefine;  //轴数定义
	int32 softWareVersion; //软件版本
	int16 funcModuleNum; //功能模块数

	//////////////////////////////////////////////////////////////////////////
	static const int16		SCAN_SUCCESS					= 0;
	static const int16		SCAN_PARSE_SPACELINE			= -1;
	static const int16		SCAN_PARSE_COMMENTLINE			= -2;
	static const int16		SCAN_PARSE_NOTFINDKEYWORD		= -3;

	static const int16		SCAN_PARSE_FINDTYPEDEFSTRUCT	= -4;
	static const int16		SCAN_PARSE_FINDTYPEDEFUNION		= -5;
	static const int16		SCAN_PARSE_FINDTYPEDEFENUM		= -6;
	static const int16		SCAN_PARSE_FINDKEYWORDERROR		= -7;
	static const int16		SCAN_PARSE_FINDKEYWORDDEFINE	= -11;  //增加宏定义

	static const int16		SCAN_READ_OPENFILE_ERR			= -8;
	static const int16		SCAN_READ_WRONGFILE				= -9;
	static const int16		SCAN_READ_OFST_ERR				= -10;
};
extern CParseHfile* g_parseHfile;
#endif