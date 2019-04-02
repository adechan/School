#include <iostream>
#include <fstream>
#include <regex>
#include <cctype>

bool is_noun(const std::string& line)
{
	const auto pos = line.find_last_of('\\');

	if (pos == std::string::npos)
		return false;

	const auto classifier = line.substr(pos + 1);

	if (classifier[0] == 'N')
		return true;

	return false;
}

bool is_adjective(const std::string& line)
{
	const auto pos = line.find_last_of('\\');

	if (pos == std::string::npos)
		return false;

	const auto classifier = line.substr(pos + 1);

	if (classifier[0] == 'A')
		return true;

	return false;
}

std::string remove_classifier(const std::string& line)
{
	const auto pos = line.find_last_of('\\');
	if (pos != std::string::npos)
		return line.substr(0, pos);

	return line;
}

bool is_alpha_ws(const std::string word)
{
	for (const auto c : word)
		if (!std::isalpha(c) || (c != ' '))
			return false;

	return true;
}

bool is_weird(const std::string& word)
{
	if (word.size() < 4)
		return true;

	//if (!is_alpha_ws(word))
		//return true;

	return false;
}

int main()
{
	auto moby = std::ifstream{"mobypos.txt"};
	
	auto noun_stream = std::ofstream{ "nouns.txt" };
	auto adjectives_stream = std::ofstream{ "adjectives.txt" };

	std::string classified_word;

	while (std::getline(moby, classified_word))
	{
		const auto word = remove_classifier(classified_word);
		if (is_weird(word))
			continue;

		if (is_noun(classified_word))
			noun_stream << word << "\n";

		else if (is_adjective(classified_word))
			adjectives_stream << word << "\n";
	}

	return 0;
}