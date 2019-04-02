#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "invalid arguments!\n";
		return 0;
	}
	
	auto input = std::ifstream{argv[1]};
	auto output = std::ofstream{argv[2]};
	
	std::string line;
	std::vector<std::string> words;
	
	while (std::getline(input, line))
	{
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		words.push_back(line);
	}
	
	std::cout << "There are " << words.size() << " words\n";
	
	std::sort(words.begin(), words.end());
	const auto last = std::unique(words.begin(), words.end());
	words.erase(last, words.end());
	
	std::cout << "There are " << words.size() << " unique words\n";
	
	for (const auto& word : words)
		output << word << "\n";
	
	return 0;
}