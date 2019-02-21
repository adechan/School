#pragma once

#include <string>

namespace net
{
	// forward declare connection
	class server;
	class connection;
	class ip_address;

	// reprezinta tcp port numar
	class port
	{
	public:
		port();
		explicit port(unsigned short p);

		friend std::ostream& operator<<(std::ostream& stream, port p);

	private:
		friend connection connect(net::ip_address ip, net::port p);
		friend server make_server(net::port port, unsigned int);

		// ip adress -- good looking version --
		unsigned short presentation_;

		// cum ar trebui numarul sa arate ca sa fie folosit
		unsigned short network_format_;
	};
	
	// converteaza un string dat intr-un port numar
	// arunca exceptie daca stringul nu e port numar
	port to_port(std::string s);
	port to_port(const char* s);
}
