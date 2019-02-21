#pragma once

#include "socket.hpp"
#include "ip_address.hpp"
#include "port.hpp"

#include <cstring>
#include <chrono>
#include <unistd.h>

namespace net
{
	// o conexiune reprezinta starea curenta a conexiunii dintre local computer si pereche (ip adress, port)	
	class connection
	{
	public:
		// returneaza daca conexiunea este inchisa sau nu
		bool is_closed() const;
		bool is_alive() const;

		// inchide conexiunea
		void close();

		// obtine ip-ul si portul tintei
		net::ip_address ip_address() const;
		net::port port() const;

		net::socket& socket();

		// daca tinta nu raspunde intr-un anumit timp (timeout), atunci inchide conexiunea
		void set_timeout(std::chrono::seconds time);
		void set_timeout(std::chrono::milliseconds time);

		// creaza o conexiune intre local computer si ip adress si port date
		explicit connection(net::socket&& socket, net::ip_address ip, net::port p);

		// muta alta conexiune in cea curenta
		connection(connection&& other);

		connection& operator=(connection&& other);

	private:
		net::ip_address ip_;
		net::port port_;

		mutable net::socket socket_;
	};

	// pentru a se conecta la o pereche (ip adress, port) data 
	// returneaza o conexiune
	connection connect(ip_address ip, port p);
}
