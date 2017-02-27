//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	INI file handler	 										//
//	file				:	IniFileHandler.h											//
//	Description			:	use for read and write ini file 							//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/9/23	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef  __GTSD_INI_FILE_HANDLER__
#define  __GTSD_INI_FILE_HANDLER__

#include "Basetype_def.h"
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////

int16 GetExeFilePath(wstring* exePath);
int16 WriteIniDirectoryFile(wstring& filename,inputDirectory& dir);
int16 ReadIniDirectoryFile(wstring& filename,inputDirectory* dir);

#endif