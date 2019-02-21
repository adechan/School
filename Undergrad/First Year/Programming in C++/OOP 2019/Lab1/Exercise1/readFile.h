#pragma once
#include <string>
#include <vector>

class FileReader
{
private:
	std::string fileName;

public:
	FileReader(std::string fileName);
	std::vector<int> read();
};
