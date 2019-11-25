#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <ctime>

/* 
genereaza un numar aleator a
calculeaza b = 2*a 
_ le scrie in fisierul mapat in memorie 
_ le afiseaza la consola
*/

int main()
{
	// std::time() : returns the current universal time
	// nullptr is for if you want a certain time zone 
	// srand(time): the seed is "time" so the random number
	// will be the "time"th number in the random array generator
	std::srand(std::time(nullptr));
	int a = std::rand();
	int b = 2 * a;

	
	auto vector = std::vector<int>();
	vector.push_back(a);
	vector.push_back(b);

	HANDLE mapping = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		nullptr,
		PAGE_READWRITE,
		0,
		sizeof(int) * 2, // 8
		"ademeow" // CREATES
	);

	if (mapping == NULL) 
	{
		std::printf("Unable to create file mapping\n");
		return 0;
	}

	int* mappingData = (int*)MapViewOfFile(
		mapping,
		FILE_MAP_READ | FILE_MAP_WRITE,
		0,
		0,
		0
	);

	std::copy(vector.begin(), vector.end(), mappingData);

	for (int i = 0; i < vector.size(); i++)
	{
		std::printf("Read from vector: %d\n", vector[i]);
	}


	HANDLE eventCorrect = CreateEvent(
		NULL,	// default security attributes
		TRUE,	// manual-reset event
		FALSE,	// initial state is nonsignaled
		"EventCorrect"
	);

	HANDLE eventIncorrect = CreateEvent(
		NULL,
		TRUE,
		FALSE,
		"EventIncorrect"
	);

	std::vector<HANDLE> handleEvents = std::vector<HANDLE>();
	handleEvents.push_back(eventCorrect);
	handleEvents.push_back(eventIncorrect);

	// returns a FLAG which tells you which event was set
	DWORD flag = WaitForMultipleObjects(
		2, // number of objects we wait for (eventC, eventI)
		handleEvents.data(),
		false, // at least one object is set
		INFINITE
		);
	
	switch (flag)
	{
	case WAIT_OBJECT_0 + 0:
		printf("Correct");
		break;

	case WAIT_OBJECT_0 + 1:
		printf("Incorrect");
		break;
	}


	int dont_close;
	std::cin >> dont_close;

	CloseHandle(eventCorrect);
	CloseHandle(eventIncorrect);

	return 0;
}