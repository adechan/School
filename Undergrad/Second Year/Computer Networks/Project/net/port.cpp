#include "port.hpp"

#include <arpa/inet.h>
#include <iostream>

namespace net
{
	port::port()
		: port(0)
	{}

	port::port(unsigned short p) 
		: presentation_(p)
		, network_format_(::htons(p))
	{}

	std::ostream& operator<<(std::ostream& stream, port p)
	{
		stream << p.presentation_;
		return stream;
	}

	port to_port(std::string s)
	{
		return port(std::stoi(s));
	}

	port to_port(const char* s)
	{
		return to_port(std::string(s));
	}
}