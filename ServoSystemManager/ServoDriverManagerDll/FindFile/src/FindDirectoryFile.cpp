//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	find file from directory		 							//
//	file				:	FindDirectoryFile.cpp										//
//	Description			:	use for find file from directory							//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "FindDirectoryFile.h"

static const wchar_t c_pathSeparator = L'\\';
static const wstring s_pathSeparator = L"\\";

ffsco* g_sco = NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
ffsco::ffsco()
	: _limit(def_limit), _dirs(0)
{

}

ffsco::~ffsco()
{

}

//////////////////////////////////////////////////////////////////////
wstring ffsco::_uppercase_(wstring s)
{
	const wchar_t aazz = 'z' - 'Z';
	wstring rs;
	for (wstring::iterator it = s.begin();
		s.end() != it; it++)
	{
		if ('a' <= *it && *it <= 'z') rs.append(1, *it - aazz);
		else rs.append(1, *it);
	}
	return rs;
}
//////////////////////////////////////////////////////////////////////

int ffsco::match(wstring fext_, wstring file_)
{
	wstring fext = _uppercase_(fext_);
	wstring file = _uppercase_(file_);

	int pos = file.find_last_of('.');
	if (wstring::npos != pos) file = file.substr(pos);

	return (wstring::npos != fext.find(file));
}

void ffsco::limit(int limit_)
{
	if (limit_ < 1) _limit = def_limit;
	if (limit_ < max_limit) _limit = limit_;
}

int ffsco::dir(wstring s)
{
	return (FILE_ATTRIBUTE_DIRECTORY == GetFileAttributes(s.c_str()));
}

int ffsco::find(wstring path_, wstring fext_)
{
	wstring path = path_;
	if (path.size() > 0 && c_pathSeparator != path[path.size() - 1])
		path.append(s_pathSeparator);

	_co_dir.push_back(path);

	wstring fext = fext_;
	if (0 == fext.compare(L"*")
		|| 0 == fext.compare(L"*.*")
		) fext = L"";

	//string file = fext;
	wstring file = L"*";

	wstring s = path + file;

	WIN32_FIND_DATA fileinfo = { 0 };
	HANDLE handle = FindFirstFile(s.c_str(), &fileinfo);

	if (NULL != handle && INVALID_HANDLE_VALUE != handle)
	{

		do {

			if (_limit_()) break;	//--limit test

			if ('.' != fileinfo.cFileName[0])	//--skip./..
				if ((FILE_ATTRIBUTE_DIRECTORY & fileinfo.dwFileAttributes)
					== FILE_ATTRIBUTE_DIRECTORY)	//--
				{
					if (!_limit_()	//--limit test
						//&& 0 == fext.size()
						) _co_dir.push_back(path + fileinfo.cFileName + s_pathSeparator);

					if (0 != dirs())
					{
						ffsco o;
						o.dirs(dirs());
						o.find(path + fileinfo.cFileName, fext);
						/**/
						//--dir
						typeT o_dir = o.co_dir();
						for (typeT::iterator it_dir = o_dir.begin();
							o_dir.end() != it_dir && !_limit_();	//--limit test
							it_dir++) _co_dir.push_back(*it_dir);

						//--file
						typeT o_file = o.co_file();
						for (typeT::iterator it_file = o_file.begin();
							o_file.end() != it_file && !_limit_();	//--limit test
							it_file++) _co_file.push_back(*it_file);
					}
				}
				else
				{
					if (!_limit_()	//--limit test
						&& (0 == fext.size() || match(fext, fileinfo.cFileName))
						) _co_file.push_back(path + fileinfo.cFileName);
				}

		} while (FindNextFile(handle, &fileinfo));

		FindClose(handle);
	}

	//--dir
	for (typeT::iterator it_dir = _co_dir.begin();
		_co_dir.end() != it_dir;
		it_dir++) _co.push_back(*it_dir);
	//--file
	for (typeT::iterator it_file = _co_file.begin();
		_co_file.end() != it_file;
		it_file++) _co.push_back(*it_file);

	return count();
}
//////////////////////////////////////////////////////////////////////////
//找到所有的头文件
//////////////////////////////////////////////////////////////////////////
void ffsco::findHeaderfile(ffsco* sco,wstring& filePath, vector<wstring>& filename)
{
	//ffsco* sco = new ffsco;

	//add for different scan path
	wstring fpth0 = L"\\platform\\assistant\\";
	wstring fpth1 = L"\\Servo Control\\";

	fpth0 = filePath + fpth0;
	fpth1 = filePath + fpth1;

	_co_file.clear();
	_co_dir.clear();
	_co.clear();

	sco->dirs(1);															//--查找子目录
	sco->limit(1000);														//--最多查找1000个
	int32 count = sco->find(fpth0, L"*.h");								//--开始查找，返回找到个数
	count += sco->find(fpth1, L"*.h");									//--开始查找，返回找到个数

	ffsco::typeT coo;
	//coo = sco->co();														//--文件目录混合 
	//coo = sco->co_dir();													//--全部目录 
	coo = sco->co_file();													//--全部文件
	filename = coo;
	//delete sco;
}
void ffsco::eraseHeaderfile(wstring& fileName, vector<wstring>& fileArray)
{
	wstring tmp;
	wstring gap = L"\\";
	int32 pos;
	for (vector<wstring>::iterator it_file = fileArray.begin(); fileArray.end() != it_file; it_file++)
	{
		tmp = *it_file;
		pos = tmp.find_last_of(gap);
		tmp = tmp.erase(0, pos + 1);
		//找到要清除的头文件
		if (tmp == fileName)
		{
			fileArray.erase(it_file);
			break;
		}
	}
}
