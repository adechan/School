#pragma once

#include <string>
#include <array>
#include <chrono> // std::chrono::milliseconds/seconds

#include "connection.hpp"
#include "exceptions.hpp"

// Input/output for connections
namespace net
{
	// Scrie un mesaj dat la sfarsitul conexiunii
	void write(connection& c, const std::string& message);

	// Scrie un mesaj dat la sfarsitul conexiunii
	void write(connection& c, const char* message);

	// Verifica daca conexiunea are data valabila (blocks pentru timeout milisecunde)
	// nonblock = return imediat
	// block = va rula pana cand este gata, sau pana cand timeout milisecunde au trecut
	bool has_data(connection& c, std::chrono::milliseconds timeout = std::chrono::milliseconds(1));

	std::string read(connection& c);

}
