#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// split the file into string numbers
std::vector<std::string> splitFile(std::string string, std::string delimiter)
{
	size_t pos_start = 0;
	size_t pos_end;
	size_t delim_leng = delimiter.length();
	std::string token;
	std::vector<std::string> result;

	while ((pos_end = string.find(delimiter, pos_start)) != std::string::npos)
	{
		token = string.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_leng;
		result.push_back(token);
	}

	result.push_back(string.substr(pos_start));
	return result;
}

int main()
{
	std::string readFile;
	std::ifstream file("words.txt");

	file >> readFile;
	std::string delimiterPhrases = " .!?";

	std::vector<std::string> stringsVector = splitFile(readFile, delimiterPhrases);


	// Read strings from vector
	std::cout << "Read numbers from file: " << std::endl;
	for (auto i = 0; i != stringsVector.size(); i++)
		std::cout << stringsVector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;


	std::cin.get();
	return 0;
}