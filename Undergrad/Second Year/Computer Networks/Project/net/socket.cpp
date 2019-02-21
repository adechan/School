#include "socket.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

#include "exceptions.hpp"

namespace net
{
	socket::socket()
		: socket(-1)
	{}

	socket::socket(int descriptor)
		: descriptor_(descriptor)
	{}

	socket::socket(socket&& other)
		: descriptor_(other.descriptor_)
	{
		other.descriptor_ = -1;
	}

	socket& socket::operator=(socket&& other)
	{
		descriptor_ = other.descriptor_;
		other.descriptor_ = -1;
		return *this;
	}

	int socket::descriptor()
	{
		return descriptor_;
	}

	bool socket::is_valid() const
	{
		return descriptor_ != -1;
	}

	socket::~socket()
	{
		this->close();
	}

	void socket::close()
	{
		// Call UNIX close() pe FD-ul socketului
		::close(descriptor_);
		descriptor_ = -1;
	}

	socket make_socket()
	{
		// Ia FD unui socket nou din U socket()
		int fd = ::socket(AF_INET, SOCK_STREAM, 0);
		if (fd == -1)
			throw net::api_error(
				std::string("[socket::{ctor}] socket() failed ") + ::strerror(errno)
			);

		return socket(fd);
	}

}
