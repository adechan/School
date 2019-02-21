#include "connection.hpp"
#include "io.hpp"

#include <sys/socket.h>
#include <cstring>

namespace net
{
	connection::connection(net::socket&& socket, net::ip_address ip, net::port p)
		: ip_(ip), port_(p)
		, socket_(std::move(socket))
	{}

	connection::connection(connection&& other)
		: ip_(std::move(other.ip_))
		, port_(other.port_)
		, socket_(std::move(other.socket_))
	{}

	connection& connection::operator=(connection&& other)
	{
		ip_ = std::move(other.ip_);
		port_ = std::move(other.port_);
		socket_ = std::move(other.socket_);
		return *this;
	}

	bool connection::is_closed() const
	{
		char buffer[1];
		// Daca socket este empty/closed atunci conexiunea este inchisa
		// Daca vrem sa facem apel recv cu nonblocking si peek set, atunci ar trebui sa nu returneze 0
		// daca conexiunea este inca activa
		return !socket_.is_valid() || recv(socket_.descriptor(), buffer, sizeof(buffer), MSG_PEEK | MSG_DONTWAIT) == 0;
	}

	bool connection::is_alive() const
	{
		return !this->is_closed();
	}

	void connection::close()
	{ 
		// Inchide socket
		socket_.close();
	}

	// Returneaza ip adress tinta al conexiunii
	net::ip_address connection::ip_address() const
	{
		return ip_;
	}

	// Returneaza port tinta al conexiunii
	net::port connection::port() const
	{
		return port_;
	}

	// Apeleaza setsockopt cu timeout dat si file descriptor pentru a seta the recieve si send timeout
	// Daca dureaza mai mult decat 'timeout' pentru a primi si trimite, apelul catre read/write va arunca o exceptie
	static void fd_set_timeout(int fd, timeval& timeout)
	{
		if (setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char *>(&timeout), sizeof(timeval)) < 0)
			throw net::api_error("[connection::set_timeout] setsockopt() receive failed");

		if (setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, reinterpret_cast<char *>(&timeout), sizeof(timeval)) < 0)
			throw net::api_error("[connection::set_timeout] setsockopt() send failed");
	}

	void connection::set_timeout(std::chrono::seconds time)
	{
		// Seteaza timeout in secunde
		timeval timeout;
		timeout.tv_sec = time.count();
		timeout.tv_usec = 0;

		fd_set_timeout(socket_.descriptor(), timeout);
	}

	void connection::set_timeout(std::chrono::milliseconds time)
	{
		timeval timeout;

		timeout.tv_sec = 0;
		// convert milisecunde la microsecunde
		// deoarece tv_usec needs microseconds
		timeout.tv_usec = (time.count() % 1000) * 10000;

		fd_set_timeout(socket_.descriptor(), timeout);
	}

	// Returneaza socketul conexiunii (ce are file descriptor)
	socket& connection::socket()
	{
		return socket_;
	}

	// Creeaza un socket nou ce va fi folosit cu (ip, port) si dupa va incerca sa se conecteaze
	// la acea adresa cu socketul 
	// Daca conexiunea nu poate fi facuta se arunca o exceptie
	connection connect(net::ip_address ip, net::port p)
	{
		sockaddr_in address;
		
		// connect() are nevoie de sockaddr, deci pune ip si port in structura pe care o vrea
		address.sin_family = static_cast<int>(ip.family());
		address.sin_addr = ip.network_format_;
		address.sin_port = p.network_format_;

		// Creaza socket nou
		auto socket = net::make_socket();

		// call UNIX connect with given sockaddress
		if (connect(socket.descriptor(), reinterpret_cast<const sockaddr*>(&address), sizeof(sockaddr)) == -1)
			throw net::api_error(
				std::string("[net::connect] connect() failed: ") + ::strerror(errno)
			);

		return connection(std::move(socket), ip, p);
	}
}
