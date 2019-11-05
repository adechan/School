#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>
#include <TlHelp32.h>
#include <vector>
#include <string>
 
/* To do:
Creaza un fisier mapat in memorie:
1. CreateFileMapping(): aloca in memorie si pentru a mapa obiectul in memoria fizica
Pentru a gasi si lucra cu obiectul, foloseste OpenFileMapping (obtine handle catre obiect)

2. MapViewofFile(): piecare proces trebuie sa-l aduca in memoria virtuala
Returneaza pointer catre zona de memorie virtuala in care a fost mapat fisierul

Enumereaza procese: CreateToolhelp32Snapshot: Process32First / Process32Next
*/

struct InfoProcess
{
	DWORD pid;
	DWORD ppid;
	char exeName[256];
};

int main()
{
	// cer un snapshot la procese
	HANDLE handle_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (handle_snapshot == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot failed.err = %d \n", GetLastError());
		return -1;
	}

	std::vector<InfoProcess> processes;

	// struct that fills up with the next process when we call Process32First
	PROCESSENTRY32 process_entry32;

	// trebuie setat dwSize la sizeof(PROCESSENTRY32), altfel functia Process32First nu merge
	process_entry32.dwSize = sizeof(PROCESSENTRY32);

	// informatii despre primul process 
	if (!Process32First(handle_snapshot, &process_entry32))
	{
		printf("Process32First failed. err = %d\n", GetLastError());
		return -1;
	}
		
	do
	{
		InfoProcess proc;
		// when you dont initialize InfoProcess it just has garbage inside
		// since it's a struct
		// clears the garbage values so we can put in normal ones
		std::memset(&proc, 0, sizeof(proc));

		proc.pid = process_entry32.th32ProcessID;
		proc.ppid = process_entry32.th32ParentProcessID;

		// Copy each character from .szExeFile to .exeName
		std::copy(
			process_entry32.szExeFile,
			process_entry32.szExeFile + std::strlen(process_entry32.szExeFile),
			proc.exeName
		);

		processes.push_back(proc);

	} while (Process32Next(handle_snapshot, &process_entry32));		// trec la urmatorul proces

	CloseHandle(handle_snapshot);

	// create block of memory
	// handle to an object that knows where our memory is
	HANDLE mapping = CreateFileMapping(

		// invalid handle: means make a block of memory
		INVALID_HANDLE_VALUE,
		nullptr, 
		PAGE_READWRITE,
		0,
		sizeof(InfoProcess) * processes.size(),
		nullptr
	);

	if (mapping == NULL)
	{
		std::printf("Unable to create file mapping\n");
		return 0;
	}

	// returns a pointer to the start of our memory
	// give the mapping and permisions 
	InfoProcess* mappingData = (InfoProcess*)MapViewOfFile(
		mapping,
		FILE_MAP_READ | FILE_MAP_WRITE,
		0, 
		0, 
		0
	);

	// Copy processes vector -> mappingData
	// std::vector<InfoProcess> -> InfoProcess[]
	// copy into memory so everyone who shares that memory can see it too
	std::copy(processes.begin(), processes.end(), mappingData);

	for (int i = 0; i < processes.size(); i++)
		std::printf("%d %d %s\n",
			mappingData[i].pid,
			mappingData[i].ppid,
			mappingData[i].exeName
		);

	UnmapViewOfFile(mapping);
	return 0;

}
