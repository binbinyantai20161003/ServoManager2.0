//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	find file from directory		 							//
//	file				:	FindDirectoryFile.h											//
//	Description			:	use for find file from directory							//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef  __GTSD_FIND_DIRECTORY_FILE__
#define  __GTSD_FIND_DIRECTORY_FILE__

#ifndef	WIN32
#error now only for WIN32(platform).
#endif
//////////////////////////////////////////////////////////////////////////
#include "Basetype_def.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#pragma warning(disable:4786)
//////////////////////////////////////////////////////////////////////////

// 此类是从 FindDirectoryFile.dll 导出的
//--find files collectio
class ffsco
{
public:
	static const int32 max_limit = 0x100000;	//--1048576
	static const int32 def_limit = 0x10000;		//--65536

	typedef vector<wstring>	typeT;
	virtual int match(wstring fext_, wstring file_);	//--文件匹配检测

public:
	int find(wstring path_, wstring fext_ = L"");
	wstring get(int i = 0) { return _co.at(i); }
	int count() { return _co_dir.size() + _co_file.size(); }
	//int count() { return _co.size(); }
	typeT co() { return _co; }
	typeT co_dir() { return _co_dir; }
	typeT co_file() { return _co_file; }
	int limit() { return _limit; }
	//void limit(int limit_) { _limit = limit_; }
	void limit(int limit_);	//--设置结果文件数目上限
	int dirs() { return _dirs; }	//get
	void dirs(int dirs) { _dirs = dirs; }	//--set
	int dir(wstring s);	//--判断s是否为目录

private:
	int _limit;	//--limit
	int _dirs;	//--dirs-是否查找子目录(默认0-不查找)
	typeT _co_file;
	typeT _co_dir;
	typeT _co;

public:
	ffsco();
	virtual ~ffsco();
	void findHeaderfile(ffsco* sco, wstring& filePath, vector<wstring>& filename);
	void eraseHeaderfile(wstring& fileName, vector<wstring>& fileArray);

private:
	inline int _limit_() { return count() == limit(); }	//--limit test
	inline wstring _uppercase_(wstring s);	//--转换s到大写字母
};

extern ffsco* g_sco;
#endif