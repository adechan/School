#include "readFile.h"	

#include <iostream>
#include <fstream>

FileReader::FileReader(std::string fileName)
{
	this->fileName = fileName;
}

std::vector<int> FileReader::read()
{
	std::vector<int> numbers;
	std::string line;

	std::ifstream textFile(fileName);

	// error checking here

	while (std::getline(textFile, line))
		numbers.push_back(std::stoi(line));

	// destructor of std::ifstream closes the file here
	//textFile.close();
	return numbers;
}