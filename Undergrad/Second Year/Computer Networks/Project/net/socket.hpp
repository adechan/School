#pragma once

#include "ip_address.hpp"

namespace net
{
	class socket
	{
	public:
		// Creaza un socket invalid
		socket();

		// Creaza un socket cu descriptor dat
		explicit socket(int descriptor);

		// Steal the other socket
		socket(socket&& other);

		// pentru a nu putea copia socketuri
		socket(const socket&) = delete;

		// Steal the other socket
		socket& operator=(socket&&);

		// pentru a nu putea copia socketuri
		socket& operator=(const socket&) = delete;

		~socket();

		bool is_valid() const;

		// Apeleaza close() pe FD si seteaza descriptor_ = -1
		void close();

		// recupereaza FD asociat cu socketul
		int descriptor();

	private:
		int descriptor_;
	};

	// Creaza socket nou
	socket make_socket();
}
