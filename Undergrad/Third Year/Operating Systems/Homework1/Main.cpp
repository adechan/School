// look at current directory
// for each folder
// make a key at the current level 
// then for each file make a value 
// then call same function that we are in except one of the folders inside our directory
// just a test


// DWORD : integer (unsigned)
// LPCSTR: const char*
// LPSTR: char*

// LP = POINTER 

// file != folder (folder contains files)

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <array>


int myFunction(int x) {
  return 5 + x;
}



HANDLE open_file(std::string file_name) 
{
	return CreateFile(
		// string file_name to const char* (pointer catre numele fisierului)
		file_name.c_str(),

		// tip de acces catre fisier
		GENERIC_READ | GENERIC_WRITE,

		// previne celelalte procese sa deschisa un fisier daca
		// doresc sa faca request pentru delete, read, write access
		0,

		// drepturi de securitate specific, daca se doresc
		nullptr,

		// exista deja fisierul sau trebuie creat
		OPEN_EXISTING,

		// atribute pentru noul fisier
		FILE_FLAG_BACKUP_SEMANTICS,

		// in caz ca se doreste utilizarea unui template pentru 
		// a seta atributele fisierului
		INVALID_HANDLE_VALUE);
}

// deschide o cheie particula care e sub alta cheie
HKEY open_key(HKEY key, std::string subkey)
{
	HKEY result = nullptr;

	// deschide o cheie specifica
	if (RegOpenKeyEx(
		// handle pentru a deschide o cheie
		key,
		// numele registry subkey pentru a fi deschisa 
		subkey.c_str(),
		0,
		KEY_ALL_ACCESS,
		// pointer la o variabila care primeste un handle catre cheia deschisa
		&result) != ERROR_SUCCESS)
		return nullptr;

	return result;
}

// 
bool set_value(HKEY key, std::string value_name, int value)
{
	return RegSetValueEx(
		// handle catre o cheie deschisa
		key,
		// pointer spre un string care contine numele valoarei pentru a fi setata
		value_name.c_str(),
		0,
		REG_DWORD,
		(const BYTE*)(&value),
		sizeof(DWORD)
	) == ERROR_SUCCESS;
}

HKEY create_key(HKEY key, std::string name)
{
	HKEY result = nullptr;
	RegCreateKeyA(key, name.c_str(), &result);
	return result;
}

bool is_directory(const WIN32_FIND_DATA& find_data)
{
	// file is a directory or not: info stored in a bit
	// in order to access this bit we say it looks like this FILE_ATTRIBUTE_DIRECTORY
	// file F.. if bit at position 0x10 set : file is a directory
	return (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY;
}

bool is_file(const WIN32_FIND_DATA& find_data)
{
	return !is_directory(find_data);
}

std::string extract_filename(std::string path)
{
	const auto it = path.find_last_of('\\');

	return path.substr(path.find_last_of('\\') + 1);
}

// all files in directory
void archive_directory_impl(std::string path, HKEY key)
{
	if (key == nullptr)
	{
		std::cerr << "Unable to open registry key\n";
		return;
	}

	std::array<char, 256> old_cwd = {};					
	GetCurrentDirectory(256, old_cwd.data());			
	SetCurrentDirectory(path.c_str());					

	WIN32_FIND_DATA find_data;

	// returns handle to a search instance
	// that represents the current state of the directory
	HANDLE file_finder = FindFirstFile("*", &find_data);

	do
	{
		const std::string filename = find_data.cFileName;

		if (is_file(find_data))
		// make registry value
		{
			if (!set_value(key, filename, find_data.nFileSizeLow))
			{
				std::cerr << "Unable to set registry value\n";
				return;
			}

			std::cout << "Filename: " << filename << '\n';
		}

		else if (!(filename == "." || filename == ".."))
		{
			const HKEY new_key = create_key(key, filename);

			archive_directory_impl(path + "\\" + filename, new_key);
		}

	} while (FindNextFile(file_finder, &find_data));

	SetCurrentDirectory(old_cwd.data());
	FindClose(file_finder);
	RegCloseKey(key);
}

void archive_directory(std::string path)
{
	const HKEY hkcu = open_key(HKEY_CURRENT_USER, "SOFTWARE\\CSSO");
	const HKEY key = create_key(hkcu, extract_filename(path));
	return archive_directory_impl(path, key);
}

// for each file/ folder in the directory we check to see if its a folder or a file
// if folder : make key => and then call the same function on that folder 
// if file : make value with data being the file's size 

int main()
{
	archive_directory("C:\\Users\\Andreea Rindasu\\source\\repos\\CSSOHomework1\\CSSOHomework1\\tema1");
	return 0;
}