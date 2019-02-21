#pragma once

#include "../net/connection.hpp"

#include <queue>

class player
{
public:
	explicit player(net::connection&& connection, const std::string& name);

	bool is_busy() const;
	bool is_ready() const;

	void set_busy();
	void set_ready();

	// trimite comanda urmatoare in queue daca exista
	void send_next_command();

public:
	net::connection connection;

	// pastreaza comanda urmatoare pentru a fi trimis jucatorului
	std::queue<std::string> command_queue;

	// numele jucatorului
	std::string name;

private:
	bool ready_;
};

bool operator==(const player& lhs, const player& rhs);
