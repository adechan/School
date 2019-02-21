#pragma once

#include <iostream>
#include <array>

#include <arpa/inet.h>

namespace net
{
	class connection;
	class port;

	enum class address_family 
	{ 
		af_inet = AF_INET, 
		af_inet6 = AF_INET6
	};

	// reprezinta o address ip
	class ip_address
	{
	public:
		ip_address();

		explicit ip_address(const std::string& address);

		explicit ip_address(const std::string& address, const in_addr& network_order);

		// Ia family type (ipv4 or ipv6)
		address_family family() const;
		
		friend std::ostream& operator<<(std::ostream& stream, ip_address ip);

	private:
		friend connection connect(net::ip_address ip, net::port p);

		std::string presentation_;
		in_addr network_format_;
	};

	// Converteste un string dat intr-un numar ipaddress
	// arunca o exceptie daca stringul nu reprezinta o adresa ip
	ip_address to_ip(const std::string& s);
	ip_address to_ip(const char* s);
	ip_address to_ip(const sockaddr_in& s);
	ip_address to_ip(const in_addr& s);
}
