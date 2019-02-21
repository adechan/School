#include "io.hpp"

#include "connection.hpp"

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <array>

namespace net
{
	void write(connection& c, const std::string& message)
	{
		if (message.size() == 0) return;

		// Conexiunea trebuie sa fie activa
		if (c.is_closed())
			throw net::connection_closed_unexpectedly(
				std::string("[net::write] connection was closed")
			);


		// Throw any errors from UNIX write()
		if (::write(c.socket().descriptor(), message.c_str(), message.size()) <= 0)
			throw net::io_error(
				std::string("[net::write] write() failed: ") + ::strerror(errno)
			);
	}

	void write(connection& c, const char* message)
	{
		write(c, std::string(message));
	}

	bool has_data(connection& c, std::chrono::milliseconds timeout)
	{
		int fd = c.socket().descriptor();

		fd_set fds;
		timeval tv;

		// Urmareste conexiunea socketului pentru a vedea cand are un input
		FD_ZERO(&fds);
		FD_SET(fd, &fds);

		// Seteaza timeout
		tv.tv_sec = timeout.count() / 1000;

		// timeval foloseste seconds sau microseconds, deci trebuie sa convertim milliseconds in microseconds
		// 1 millisecond is 10000 microseconds
		tv.tv_usec = (timeout.count() % 1000) * 10000;

		// Apeleaza select pentru un FD dat si un timeout dat
		int result = ::select(fd + 1, &fds, NULL, NULL, &tv);

		if (result == -1)
			throw api_error(
				std::string("[net::has_data] select() failed")
			);

		// returneaza daca un FD are data sau nu
		return FD_ISSET(fd, &fds);
	}

	std::string read(connection& c)
	{
		// Conexiunea trebuie sa fie activa
		if (c.is_closed())
			throw net::connection_closed_unexpectedly(
				std::string("[net::read] connection was closed")
			);

		// Daca avem ce citi, punem in buffer
		std::array<char, 256> buffer;

		// Full string dupa ce citim tot
		std::string result;

		int bytes_read = 0;

		do
		{
			// Citeste din socket in buffer
			bytes_read = ::read(c.socket().descriptor(), buffer.data(), buffer.size());

			// Arunca i/o errors 
			if (bytes_read < 0)
				throw net::io_error(
					std::string("[net::read] read() failed: ") + ::strerror(errno)
				);

			// Construieste stringul
			result += std::string(buffer.data(), bytes_read);
			
			// cat timp buffer a fost umplut complet, construieste stringul
			// daca buffer nu a fost umplut, atunci nu mai avem data sa citim
		} while (bytes_read == buffer.size());

		return result;
	}
}
