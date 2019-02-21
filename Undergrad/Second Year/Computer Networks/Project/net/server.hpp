#pragma once

#include "port.hpp"
#include "socket.hpp"

namespace net
{
	class connection;

	// Pentru a putea folosi bind pe un port si accepta clienti noi cu care putem interactiona
	class server
	{
	public:
		server();

		// 
		explicit server(net::socket&& socket, net::port port, unsigned int backlog_size = 5);

		// Inchide server
		void close();
		
		// Ia portul pe care avem serverul host
		net::port port() const;

		// Accepta client nou (blocks pana cand un client vine)
		net::connection accept_client();

	private:
		net::socket socket_;
		net::port port_;
		unsigned int backlog_size_;
	};

	// Binds pe un port dat si cu backlog size dat
	// Backlog size = cat de muti clienti noi putem astepta sa fie acceptati 
	// daca suntem ocupati
	server make_server(net::port port, unsigned int backlog_size = 5);

}
