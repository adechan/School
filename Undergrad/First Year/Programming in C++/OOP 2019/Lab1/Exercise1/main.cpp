#include <stdio.h>
#include <iostream>

#include "readFile.h"
#include "sortArray.h"

	
void displayVector(std::vector<int> numbers)
{

	for (int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

}

int main()
{

	FileReader file("filetext.txt");

	std::vector<int> numbers = file.read();

	displayVector(numbers);
	std::cout << std::endl;

	bubbleSort(numbers);

	displayVector(numbers);
	std::cout << std::endl;

	std::cin.get();
	return 0;
}