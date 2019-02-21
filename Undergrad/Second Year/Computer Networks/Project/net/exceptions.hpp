#pragma once

#include <stdexcept>

#define NET_MAKE_ERROR(error_name)\
class error_name : public api_error\
{\
public:\
	explicit error_name(const std::string& message)\
		: error_name(message.c_str())\
	{}\
\
	explicit error_name(const char* message)\
		: api_error(message)\
	{}\
}

namespace net
{
	// UNIX API error (exemplu daca socket() esueaza)
	class api_error : public std::runtime_error
	{
	public:
		explicit api_error(const std::string& message)  : api_error(message.c_str())  {}
		explicit api_error(const char* message)			: std::runtime_error(message) {}
	};

	// daca read/write esueaza
	NET_MAKE_ERROR(io_error);

	// daca vrem sa facem o operatie pe un socket invalid
	NET_MAKE_ERROR(invalid_socket);
	
	// daca conexiunea se inchide cand o folosim
	NET_MAKE_ERROR(connection_closed_unexpectedly);
}
