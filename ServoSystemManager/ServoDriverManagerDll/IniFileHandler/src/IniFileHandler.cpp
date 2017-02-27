// ini_operator.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include	"stdafx.h"
#include	<tchar.h>
#include	"shlwapi.h"
#include	"FindDirectoryFile.h"
#include	"BuildVarRelation.h"
#include	"ParseFile.h"
#include	"StringHandler.h"
#include	"BuildPrmRelation.h"
#include	"PrtyCompare.h"
#include	"PrmCompare.h"
#include	"xml.h"
#include	"ServoDriverManagerDll.h"
#include	"IniFileHandler.h"

int16 GetExeFilePath(wstring* exePath)
{
	// get the exe file path  
	TCHAR tcExePath[65536] = {0};  
	::GetModuleFileName(NULL, tcExePath, 65536);

	//_tcsrchr() inverse searsh the last location of '\\' in the path ,return the pointer of the location
	//_tcsrchr() need the #include <tchar.h>
	TCHAR *pFind = _tcsrchr(tcExePath, '\\');  
	if (pFind == NULL)  
	{  
		return -1;  
	}  
	// set the end of the char array
	*pFind = '\0';  

	//The path 
	*exePath = tcExePath;  
 
	return 0;
}

int16 WriteIniDirectoryFile(wstring& filename, inputDirectory& dir)
{
	int16 rtn;
	wstring szIniPath;
	GetExeFilePath(&szIniPath);
	szIniPath = szIniPath +_T("\\") + filename;
	//--------------------------------------------------------  
	//BOOL WritePrivateProfileString(  
	//                              LPCTSTR lpAppName,      //section name ��a string end with "\0"  
	//                              LPCTSTR lpKeyName,      //key name��a string end with "\0"��if it is NULL��then delete the whole section  
	//                              LPCTSTR lpString,       //key value��a string end with "\0"��if it is NULL��then delete the corresponding key   
	//                              LPCTSTR lpFileName      //the file name ��if the ini file is in the same directory with the exe,you can use the relative path
	//                              )                        or you need give the absolute path  

	//if the ini file does not exist��it will create the file in the path and then write it. 
	//you can set same key in the different section.                              
	rtn = ::WritePrivateProfileString(TEXT("File Directory"), TEXT("IAR_SERVO"), (dir.IAR_Servo.c_str()), szIniPath.c_str());
	if (rtn == 0)
	{
		return -1;
	}
	rtn = ::WritePrivateProfileString(TEXT("File Directory"), TEXT("IAR_ADDR"), (dir.IAR_Addr.c_str()), szIniPath.c_str());
	if (rtn == 0)
	{
		return -1;
	}
	rtn = ::WritePrivateProfileString(TEXT("File Directory"), TEXT("IAR_BIN"), (dir.IAR_Bin.c_str()), szIniPath.c_str());
	if (rtn == 0)
	{
		return -1;
	}
	rtn = ::WritePrivateProfileString(TEXT("File Directory"), TEXT("DEV_AXIS_NUM"), (dir.DEV_AXIS_NUM.c_str()), szIniPath.c_str());
	if (rtn == 0)
	{
		return -1;
	}
	
	return 0;
}

int16 ReadIniDirectoryFile(wstring& filename, inputDirectory* dir)
{
	
	wstring szIniPath;
	GetExeFilePath(&szIniPath);
	szIniPath = szIniPath + _T("\\") + filename;

	//PathFileExists need the header file #include	"shlwapi.h" and need add the lib shlwapi.lib to the system
	if (!::PathFileExists(szIniPath.c_str()))  
	{  
		return -1;  
	}  



	//--------------------------------------------------------  
	//DWORD GetPrivateProfileString(  
	//                              LPCTSTR lpAppName,            // ����  
	//                              LPCTSTR lpKeyName,            // ��������ȡ�ü���ֵ  
	//                              LPCTSTR lpDefault,            // ��ָ���ļ������ڣ���ֵ��Ϊ��ȡ��Ĭ��ֵ  
	//                              LPTSTR lpReturnedString,      // һ��ָ�򻺳�����ָ�룬���ն�ȡ���ַ���  
	//                              DWORD nSize,                  // ָ��lpReturnedStringָ��Ļ������Ĵ�С  
	//                              LPCTSTR lpFileName            // ��ȡ��Ϣ���ļ���������ini�ļ��������ͬһ��Ŀ¼�£�  
	//                                                                Ҳ��ʹ�����·��,������Ҫ��������·��  
	//UINT GetPrivateProfileInt(  
	//                              LPCTSTR lpAppName,            // ����  
	//                              LPCTSTR lpKeyName,            // ��������ȡ�ü���ֵ  
	//                              INT nDefault,                 // ��ָ���ļ��������ڣ���ֵ��Ϊ��ȡ��Ĭ��ֵ  
	//                              LPCTSTR lpFileName            // ͬ��  
	//  
	//--------------------------------------------------------  
	TCHAR tmp[65536];
	::GetPrivateProfileString(TEXT("File Directory"), TEXT("IAR_SERVO"), NULL, tmp, 65536, szIniPath.c_str());
	dir->IAR_Servo = tmp;
	::GetPrivateProfileString(TEXT("File Directory"), TEXT("IAR_ADDR"), NULL, tmp, 65536, szIniPath.c_str());
	dir->IAR_Addr = tmp;
	::GetPrivateProfileString(TEXT("File Directory"), TEXT("IAR_BIN"), NULL, tmp, 65536, szIniPath.c_str());
	dir->IAR_Bin = tmp;
	::GetPrivateProfileString(TEXT("File Directory"), TEXT("DEV_AXIS_NUM"), NULL, tmp,65536, szIniPath.c_str());
	dir->DEV_AXIS_NUM = tmp;

	return 0;
}
