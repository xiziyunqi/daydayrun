// testcreatefileandloadlibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <psapi.h>
#include <windows.h> 
typedef void *HANDLE;

int _tmain(int argc, _TCHAR* argv[])
{

	//#"dlltest.dll"文件放在cpp源文件下和debug的exe文件下都可以。
	HMODULE hShell = LoadLibrary(L"dlltest.dll");
	_asm int 3;
	//#loadlibrary之后，OD M显示加载了 dlltest，可以看出两者不同了。
	if (hShell == NULL)
	{
		MessageBox(NULL, _T("加载Shell.dll模块失败，请确保程序的完整性！"), _T("提示"), MB_OK);
		//释放资源

		return FALSE;
	}
	_asm int 3;
	//MODULEINFO modinfo = { 0 };
	//GetModuleInformation(GetCurrentProcess(), hShell, &modinfo, sizeof(MODULEINFO));
	HANDLE	m_hFile = CreateFile(L"dlltest.dll",
		GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	int a = GetFileSize(m_hFile, NULL);
	_asm int 3;
	//#文件大小为3400字节，确实是文件大小
	CloseHandle(m_hFile);
	return 0;
}

