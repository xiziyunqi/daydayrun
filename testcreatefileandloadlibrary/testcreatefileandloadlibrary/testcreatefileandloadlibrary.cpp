// testcreatefileandloadlibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <psapi.h>
#include <windows.h> 
typedef void *HANDLE;

int _tmain(int argc, _TCHAR* argv[])
{

	//#"dlltest.dll"�ļ�����cppԴ�ļ��º�debug��exe�ļ��¶����ԡ�
	HMODULE hShell = LoadLibrary(L"dlltest.dll");
	_asm int 3;
	//#loadlibrary֮��OD M��ʾ������ dlltest�����Կ������߲�ͬ�ˡ�
	if (hShell == NULL)
	{
		MessageBox(NULL, _T("����Shell.dllģ��ʧ�ܣ���ȷ������������ԣ�"), _T("��ʾ"), MB_OK);
		//�ͷ���Դ

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
	//#�ļ���СΪ3400�ֽڣ�ȷʵ���ļ���С
	CloseHandle(m_hFile);
	return 0;
}

