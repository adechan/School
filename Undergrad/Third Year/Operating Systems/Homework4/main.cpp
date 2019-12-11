#include <Windows.h>
#include <Wininet.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string trim(std::string string)
{
	std::string trimmed = string;
	int i = 0;
	while (i < trimmed.size() && std::isspace(trimmed[i]))
	{
		trimmed.erase(i);
		i++;
	}

	i = trimmed.size() - 1;
	while (i > 0 && std::isspace(trimmed[i]))
	{
		trimmed.erase(i);
		i--;
	}

	return trimmed;
}

std::string get_name(std::string path)
{
	std::string result;
	int it = path.find_last_of('\\');
	result = path.substr(it + 1);

	return result;
}

int main()
{
	// initializare librarie wininet prin apelul functiei
	// InternetOpen
	HINTERNET handle_internet = InternetOpen(
		// from http headers
		"AdeBrowser",
		INTERNET_OPEN_TYPE_PRECONFIG,
		// no proxy server
		nullptr,
		nullptr,
		0
	);

	if (handle_internet == nullptr)
	{
		printf("InternetOpen failed.err = %d \n", GetLastError());
		return -1;
	}

	// HTTP
	// conectarea la server si specificarea protocolului
	HINTERNET handle_open_url = InternetOpenUrl(
		handle_internet,
		"https://pastebin.com/raw/3GBX7CvJ",
		nullptr,
		0,
		INTERNET_FLAG_SECURE,
		0
	);

	if (handle_open_url == nullptr)
	{
		printf("InternetOpenUrl failed.err = %d \n", GetLastError());
		/*char buffer[256];
		DWORD length = 256;
		DWORD ec;
		if (!InternetGetLastResponseInfo(&ec, buffer, &length))
			std::cout << "The error errored\n";
		printf("WHY failed.err = %d: %s \n", ec, buffer);*/
		return -1;
	}

	const char* accepted_types[] = {
		"*/*",
		nullptr
	};

	// the answer we get
	std::stringstream file;

	char buffer[256];
	for (int i = 0; i < 256; i++)
	{
		buffer[i] = 0;
	}

	DWORD bytes_read = 1;

	while (bytes_read > 0)
	{
		// HTTP: citire raspuns
		/*
		puts how many bytes he read into bytes_read variable
		and after he's read everything he will put a 0
		*/
		bool read_response = InternetReadFile(
			handle_open_url,
			buffer,
			256,
			&bytes_read
		);

		if (bytes_read > 0)
			file << buffer;
	}

	std::cout << buffer;

	// parse the answer
	int number_commands = 0;
	file >> number_commands;

	std::string ftp_server_address = "";
	file >> ftp_server_address;

	std::string username = "";
	file >> username;

	std::string password = "";
	file >> password;

	std::vector<std::string> commands = std::vector<std::string>();
	for (int i = 0; i <= number_commands; i++)
	{
		std::string command;

		file >> std::ws; // skip whitespace
		std::getline(file, command);

		if (command.empty())
			continue;

		commands.push_back(trim(command));
	}

	std::cout << "number_commands: " << number_commands << "\n";
	std::cout << "ftp_server_address: " << ftp_server_address << "\n";
	std::cout << "username: " << username << "\n";
	std::cout << "password: " << password << "\n";

	std::cout << std::endl;
	std::cout << "Commands:\n";
	for (int i = 0; i < commands.size(); i++)
	{
		std::cout << commands[i] << "\n";
	}

	//get rid of the 0 from last command
	std::string& last_command = commands[commands.size() - 1];
	last_command = last_command.substr(0, last_command.size() - 1);

	//std::cout << std::endl;
	//std::cout << "Commands:\n";
	//for (int i = 0; i < commands.size(); i++)
	//{
	//	//auto space_it = commands[i].find_first_of(' ');
	//	std::cout << commands[i] <<  "\n\n";
	//}

	std::vector<std::string> put_args = std::vector<std::string>();
	for (int i = 0; i < commands.size(); i++)
	{
		int space_it = commands[i].find_first_of(' ');

		// name: commands[i].substr(0, space_it);
		// args: commands[i].substr(space_it + 1);

		std::string name = commands[i].substr(0, space_it);
		std::string args = commands[i].substr(space_it + 1);

		//std::cout << "args=" << args << "\r\n";

		if (name == "PUT") 
		{
			put_args.push_back(args);
		}
	}

	std::cout << std::endl;
	std::cout << "Paths:\n";
	for (int i = 0; i < put_args.size(); i++)
	{
		std::cout << put_args[i] << " ";
	}


	InternetCloseHandle(handle_open_url);
	InternetCloseHandle(handle_internet);


	handle_internet = InternetOpen(
		// from http headers
		"AdeBrowser",
		INTERNET_OPEN_TYPE_DIRECT,
		// no proxy server
		nullptr,
		nullptr,
		0
	);

	if (handle_internet == nullptr)
	{
		printf("InternetOpen failed.err = %d \n", GetLastError());
		return -1;
	}

	HINTERNET handle_internet_connect = InternetConnect(
		handle_internet,
		ftp_server_address.c_str(),
		INTERNET_DEFAULT_FTP_PORT,
		username.c_str(),
		password.c_str(),
		INTERNET_SERVICE_FTP,
		INTERNET_FLAG_PASSIVE,
		0
	);

	if (handle_internet_connect == nullptr)
	{
		printf("InternetConnect failed.err = %d \n", GetLastError());
		return -1;
	}


	for (int i = 0; i < put_args.size(); i++)
	{
		// PUT
		bool copy_file = FtpPutFile(
			handle_internet_connect,
			put_args[i].c_str(),
			get_name(put_args[i]).c_str(),
			FTP_TRANSFER_TYPE_BINARY,
			0
		);

		std::string path = "C:\\Users\\Andreea Rindasu\\Desktop\\ftp-folder\\" + get_name(put_args[i]);

		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		ZeroMemory(&pi, sizeof(pi));
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);

		// RUN
		bool run_file = CreateProcess(
			path.c_str(),
			nullptr, 
			nullptr,
			false,
			0, 
			0,
			nullptr,
			nullptr,
			&si,
			&pi
		);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}



	return 0;
}
