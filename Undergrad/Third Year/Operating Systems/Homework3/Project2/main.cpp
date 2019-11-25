#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

/*
citeste numerele din fisierul mapat
verifica daca b == 2 * a
afiseaza mesajul "incorect" sau "corect"
*/

int main()
{
	HANDLE mapping = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		false,
		"ademeow" // OPENS
	);

	if (mapping == nullptr)
	{
		std::printf("Unable to open file mapping\n");
		return 0;
	}

	int* mappingData = (int*)MapViewOfFile(
		mapping,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		// map 8 bytes
		8
	);

	if (mappingData == nullptr)
	{
		std::printf("Unable to make view of file mapping\n");
		return 0;
	}

	HANDLE eventCorrect = OpenEvent(
		EVENT_ALL_ACCESS,
		TRUE,
		"EventCorrect"
	);

	HANDLE eventIncorrect = OpenEvent(
		EVENT_ALL_ACCESS,
		TRUE,
		"EventIncorrect"
	);

	// todo: error check event handles

	int a = mappingData[0];
	int b = mappingData[1];

	int to_check = 2 * a;

	if (b == to_check)
	{
		// signal the "correct" event
		SetEvent(eventCorrect);
		printf("Correct");
	}
	else
	{
		// signal the "incorrect" event
		SetEvent(eventIncorrect);
		printf("Incorrect");
	}


	CloseHandle(eventCorrect);
	CloseHandle(eventIncorrect);
	return 0;
}