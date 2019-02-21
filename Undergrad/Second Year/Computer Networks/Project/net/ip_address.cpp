#include "ip_address.hpp"

#include <iostream>
#include <string>
#include <cstring>

namespace net
{
	std::ostream& operator<<(std::ostream& stream, ip_address ip)
	{
		stream << ip.presentation_;
		return stream;
	}

	ip_address::ip_address()
		: ip_address("0.0.0.0")
	{}

	ip_address::ip_address(const std::string& address, const in_addr& network_format)
		: presentation_(address)
		, network_format_(network_format)
	{}

	ip_address::ip_address(const std::string& address)
		: presentation_(address)
	{
		// convert presentation in network format 
		// pentru cand trimitem data prin network
		if (::inet_pton(AF_INET, address.c_str(), &network_format_) <= 0)
			throw std::invalid_argument("[net::ip_address] Invalid IPv4 format");
	}

	address_family ip_address::family() const
	{
		return address_family::af_inet;
	}

	// Convert string in ipv4 address
	ip_address to_ip(const std::string& s)
	{
		return ip_address(s);
	}

	ip_address to_ip(const char* s)
	{
		return to_ip(std::string(s));
	}

	ip_address to_ip(const sockaddr_in& socket_address)
	{
		return to_ip(socket_address.sin_addr);
	}

	ip_address to_ip(const in_addr& s)
	{
		std::array<char, INET_ADDRSTRLEN> buffer;

		if (::inet_ntop(AF_INET, &(s.s_addr), buffer.data(), buffer.size()) <= 0)
			throw std::invalid_argument("[net::to_ip] Invalid IPv4 format");

		return ip_address(std::string(buffer.data()), s);
	}
}
