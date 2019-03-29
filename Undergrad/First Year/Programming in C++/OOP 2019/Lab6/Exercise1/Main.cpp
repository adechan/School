#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

// split the file into string numbers
std::vector<std::string> splitFile(std::string string, std::string delimiter)
{
	size_t pos_start = 0;
	size_t pos_end;
	size_t delim_leng = delimiter.length();
	std::string token;
	std::vector<std::string> result;

	// npos = "until the end of the string"
	while ((pos_end = string.find(delimiter, pos_start)) != std::string::npos) 
	{
		token = string.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_leng;
		result.push_back(token);
	}

	// so we do not miss the last token when pos_start is the last found 
	result.push_back(string.substr(pos_start));
	return result;
}


int getInt(std::string arrayStrings)
{
	int number;

	// input stream which operates on strings
	// iss >> T : takes a type T element from iss if the conversion is possible

	std::istringstream iss(arrayStrings);
	iss >> number;

	return number;
}

int main()
{
	std::string readFile;
	std::ifstream file("numere.txt");

	file >> readFile;

	std::string delimiter = ",";

	std::vector<std::string> stringsVector = splitFile(readFile, delimiter);

	// Read strings from vector
	std::cout << "Read numbers from file: " << std::endl;
	for (auto i = 0; i != stringsVector.size(); i++)
		std::cout << stringsVector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	// Read ints from vector
	std::cout << "Read numbers from vector: " << std::endl;
	for (auto i = 0; i != stringsVector.size(); i++)
		std::cout << getInt(stringsVector[i]) << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	// Make sortedVector a vector of ints
	std::vector<int> sortedVector;
	for (auto i = 0; i != stringsVector.size(); i++)
		sortedVector.push_back(getInt(stringsVector[i]));
	

	// Sort the sortedVector
	std::cout << "Sorted vector: " << std::endl;
	std::sort(sortedVector.begin(), sortedVector.end());

	for (auto i = 0; i != sortedVector.size(); i++)
		std::cout << sortedVector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	// Delete duplicates
	std::cout << "Delete duplicates: " << std::endl;
	// It moves numbers around so that the unique numbers are at the begining, and 
	// after the unique numbers are done, the duplicates will be next 
	// last: gives you the index of the first duplicate number so you can delete it
	auto last = std::unique(sortedVector.begin(), sortedVector.end());
	sortedVector.erase(last, sortedVector.end());

	for (auto i = 0; i != sortedVector.size(); i++)
		std::cout << sortedVector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;


	// Use set to sort
	std::set<int> sortedSet;
	for (auto i = 0; i != stringsVector.size(); i++)
		sortedSet.insert(getInt(stringsVector[i]));

	std::cout << "Sorted Set: " << std::endl;
	for (auto i = sortedSet.begin(); i != sortedSet.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << std::endl;


	std::cin.get();
	return 0;
}