#include "server.hpp"

#include "connection.hpp"
#include "exceptions.hpp"

namespace net
{
	server::server()
		: server(net::socket{}, net::port{}, 0)
	{}

	server::server(net::socket&& socket, net::port port, unsigned int backlog_size)
		: socket_(std::move(socket))
		, port_(port)
		, backlog_size_(backlog_size)
	{}

	void server::close()
	{
		socket_.close();
	}

	net::port server::port() const
	{
		return port_;
	}

	net::connection server::accept_client()
	{
		// socketul trebuie sa fie valid
		if (!socket_.is_valid())
			throw net::invalid_socket("[server::accept_client] invalid socket.");

		// sockaddr_in = adresa sock a clientului nou pe care l-am acceptat
		sockaddr_in client_sockaddr;
		socklen_t address_size = sizeof(client_sockaddr);

		// Ia FD al socketul clientului nou
		int fd = ::accept(socket_.descriptor(), reinterpret_cast<sockaddr*>(&client_sockaddr), &address_size);

		if (fd == -1)
			throw net::api_error(
				std::string("[server::accept_client] accept() failed: ") + ::strerror(errno)
			);

		// Face conexiune cu socket descriptor al clientului, ip si port 	
		return net::connection(
			net::socket(fd),
			net::to_ip(client_sockaddr.sin_addr),
			net::port(::ntohs(client_sockaddr.sin_port)) // ntohs is network to presentation format
		);
	}

	server make_server(net::port port, unsigned int backlog_size)
	{
		net::socket socket = net::make_socket();

		// Make the socket rebind faster for when we need to restart the server
		// Otherwise we need to wait for the system to timeout the previous bind
		int reuse = 1;
		setsockopt(socket.descriptor(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

		sockaddr_in address;

		address.sin_family = static_cast<int>(AF_INET);
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = port.network_format_;

		if (::bind(socket.descriptor(), reinterpret_cast<const sockaddr*>(&address), sizeof(sockaddr)) == -1)
			throw std::runtime_error(
				std::string("[net::make_server] bind() failed: ") + ::strerror(errno)
			);

		if (::listen(socket.descriptor(), backlog_size) == -1)
			throw std::runtime_error(
				std::string("[net::make_server] listen() failed: ") + ::strerror(errno)
			);

		return server(std::move(socket), port, backlog_size);
	}
}
