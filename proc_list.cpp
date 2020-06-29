#include<Windows.h>
#include<tlhelp32.h>
#include<iostream>
using namespace std;


DWORD GetProclist(void)
{
	PROCESSENTRY32 pe32;
	HANDLE snapshot = NULL;
	BOOL success;
	BOOL retvalue;
	const char* exename;
	DWORD pid = 0;
	snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pe32.dwSize = sizeof(PROCESSENTRY32);
	success = Process32First(snapshot, &pe32);
	do{
		exename = pe32.szExeFile;
		pid = pe32.th32ProcessID;
		cout<<exename;
		printf("\t\t");
		cout << pid << endl;
		success = Process32Next(snapshot, &pe32);
	} while (success>0);

	retvalue = CloseHandle(snapshot);
	return retvalue;
}

int main()
{
	GetProclist();
	return 0;
}
