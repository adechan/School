#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream>

void displayVector(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
}


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int numbers[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				swap(&numbers[j], &numbers[j + 1]);
			}
		}
	}
}

int main()
{
	int numbers[1000];
	char buffer[256];
	int size = 0;

	FILE* newFile;
	newFile = fopen("filetext.txt", "r");

	if (newFile == NULL)
	{
		std::cout << "Can't read from the file.";
	}

	while (fgets(buffer, 1000, newFile) != NULL)
	{
		numbers[size] = atoi(buffer);
		size++;
	}

	displayVector(numbers, size);

	bubbleSort(numbers, size);
	std::cout << std::endl;

	displayVector(numbers, size);

	std::cin.get();
	return 0;
}