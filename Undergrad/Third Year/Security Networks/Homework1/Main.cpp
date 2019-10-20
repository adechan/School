#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <numeric>
#include <algorithm>

namespace fs = std::filesystem;

// TO DO
// function that has as parameters plaintext, cryptotext, list_of_keys
// cryptotext = plaintext encrypted with one of the keys from list_of_keys in HEX
// read from file list_of_keys and transform every word from there in HEX of length 16
// if the key is smaller than 16.. use "\x20" at the end till of length 16
// try to decrypt the cryptotext using words from the list_of_keys 
// check if the decrypted file is same as plaintext.. if not continue 
// find the key
// print key in HEX, print the key in english word, and number of tries till he found the key


std::string hex_of(const std::string& str)
{
	std::string hex;

	for (const char c : str)
	{
		std::stringstream ss;
		ss << std::hex << static_cast<int>(c);
		hex += ss.str();
	}

	return hex;
}

std::string string_of_hex(const std::string& hex)
{
	//std::stringstream ss;
	//ss << "0x" << std::hex << hex;
	//return ss.str();
	int len = hex.size();
	std::string newString;
	for (int i = 0; i < len; i += 2)
	{
		std::string byte = hex.substr(i, 2);
		char chr = (char)(int)strtol(byte.c_str(), nullptr, 16);
		newString.push_back(chr);
	}

	return newString;
}

std::string padto16(const std::string& string)
{
	std::string keyHex = hex_of(string);
	int sizeOfKey = keyHex.size();

	for (int i = 0; i < 16 - sizeOfKey; i++)
		keyHex += "\x20";

	return keyHex;
}


void encryptFile(std::string plaintext, std::string key)
{
	std::string keyHex = padto16(key);
	std::cout << "Hex representation: " << keyHex << '\n';

	std::string cryptotext = "~/Desktop/cryptotext";

	std::cout << "Key length: " << keyHex.size() << '\n';

	const std::string cmd = "openssl enc -e -aes-256-ecb -a -salt -md md5 -in " + plaintext + " -out " + cryptotext + " -K " + keyHex;

	std::system(cmd.c_str());
}


void decryptFileFindKey(std::string plaintext, std::string cryptotext, std::string englishWords)
{
	int countTries = 0;
	std::cout << "Decryption function" << '\n';
	// Get the words from the file and put them into a vector
	std::ifstream file;
	file.open(englishWords);

	if (!file)
	{
		std::cout << "Unable to open file\n";
		return;
	}

	std::string line;
	std::vector<std::string> words;

	std::cout << "Reading from file..." << '\n';
	// We read every word from file and put it into a vector
	while (file.good())
	{
		file >> line;
		// move moves line into vector and line 
		// becomes empty if we dont change it
		words.push_back(std::move(line));
		// std::cout << words[words.size() - 1] << " ";
	}

	// Get Hex representation for each word in vector
	std::vector<std::string> vectorWords;
	for (const std::string& word : words)
	{
		std::string wordHex = padto16(word);
		vectorWords.push_back(wordHex);
	}


	/*
	// for every word in the Hex'd words which acts as keys
	for (const std::string& key : vectorWords)
	{
		if (key.empty() || key.find(" ") != std::string::npos)
			continue;

		// try to decrypt cryptotext using the key
		std::cout << "Trying to decrypt the file with the key " << key;

		// DECRYPT
		const std::string cmd = "openssl enc -d -aes-256-ecb -a -salt -md md5 -in " + cryptotext + " -out " + decrypted + " -K " + key;
		std::cout << "\nDecryption done!";

		std::system(cmd.c_str());


		std::cout << "\nReading from plaintext..." << '\n';

		// read from plaintext file
		while (_plaintext.good())
		{
			_plaintext >> plaintextLine;
			plaintextVector.push_back(std::move(plaintextLine));
		}

		std::ifstream _decrypted;
		_decrypted.open(decrypted);

		std::cout << "\nReading from decrypted text..." << '\n';

		// read from decrypted file
		while (_decrypted.good())
		{
			_decrypted >> decryptedLine;
			decryptedVector.push_back(std::move(decryptedLine));
		}

		std::cout << "Plaintext: ";
		for (const auto& txt : plaintextVector)
			std::cout << txt << " ";
		std::cout << '\n';

		std::cout << "Decrypted: ";
		for (const auto& txt : decryptedVector)
			std::cout << txt << " ";
		std::cout << '\n';

		std::cout << "Plaintext size: " << plaintextVector.size() << '\n';
		std::cout << "Decrypted size: " << decryptedVector.size() << '\n';

		if (plaintextVector.empty() || decryptedVector.empty())
			return;

		const auto key_found = std::equal(plaintextVector.begin(), plaintextVector.end(), 				decryptedVector.begin());

		if (key_found)
		{
			std::cout << "You found the key! The key is: " << key << '\n';
			return;
		}
	}

	return;*/

	/*std::cout << "Key to test: " << vectorWords[0];
	const std::string cmd = "openssl enc -d -aes-256-ecb -a -salt -md md5 -in " + cryptotext + " -out " + decrypted + " -K " + vectorWords[2];
	std::cout << "\nDecryption done!";

	std::system(cmd.c_str());*/

	// for every key try to decrypt the text
	for (const auto& key : vectorWords)
	{
		// if the decrypted text is same as the plaintext

		std::string decrypted = "decrypted";

		std::ifstream _plaintext;
		_plaintext.open(plaintext);

		std::ifstream _decrypted;
		_decrypted.open(decrypted);

		std::cout << "Trying to decrypt the file with the key " << key << '\n';

		const std::string cmd = "openssl enc -d -aes-256-ecb -a -salt -md md5 -in " + cryptotext + " -out " + decrypted + " -K " + key;
		std::system(cmd.c_str());
		countTries++;

		std::string plaintextLine;
		std::vector<std::string> plaintextVector;

		std::string decryptedLine;
		std::vector<std::string> decryptedVector;

		// read from plaintext file
		std::cout << "Plaintext: \n";
		while (_plaintext.good())
		{

			_plaintext >> plaintextLine;
			std::cout << plaintextLine;
			plaintextVector.push_back(plaintextLine);
			std::cout << plaintextVector[plaintextVector.size() - 1];
		}

		// read from decrypted file
		std::cout << "Decrypted: \n";
		while (_decrypted.good())
		{

			_decrypted >> decryptedLine;
			std::cout << decryptedLine;
			decryptedVector.push_back(decryptedLine);
			std::cout << decryptedVector[decryptedVector.size() - 1];
		}

		const auto plaintext = std::accumulate(plaintextVector.begin(), plaintextVector.end(), std::string{});

		const auto decrypted_s = std::accumulate(decryptedVector.begin(), decryptedVector.end(), std::string{});


		std::cout << "\nplaintext (" << plaintext.size() << "): " << plaintext << '\n';
		std::cout << "\ndecrypted (" << decrypted_s.size() << "): " << decrypted_s << '\n';

		std::cout << "First difference:\n";

		const auto is_same = [&] {
			for (int i = 0; i < plaintext.size(); i++)
				if (plaintext[i] != decrypted_s[i])
					return false;

			return true;
		};

		if (is_same())
		{
			std::cout << "Key found: " << key << '\n';
			std::cout << "Number of tries is " << countTries << '\n';
			std::cout << "Key in english word is: " << string_of_hex(key) << '\n';
			return;
		}

		/*std::cout << "\nS T O P";
		if (plaintext == decrypted)
		{
			std::cout << '\n';
			std::cout << "Key found: " << key << '\n';
			std::cout << "Number of tries is " << countTries << '\n';
			std::cout << "Key in english word is: " << string_of_hex(key) << '\n';
			return;
		}*/
	}


}


int main(void)
{
	//std::cout << "\x63\x69\x70" << '\n';
	encryptFile("~/Desktop/plaintext", "eye");

	decryptFileFindKey("plaintext", "cryptotext", "englishWords");

	return 0;
}