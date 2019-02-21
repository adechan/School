#include "player.hpp"

#include "../net/io.hpp"

player::player(net::connection&& connection, const std::string& name)
	: connection(std::move(connection))
	, ready_(true)
	, name(name)
{}

bool player::is_busy() const { return !ready_; }
bool player::is_ready() const { return ready_; }

void player::set_busy() { ready_ = false; }
void player::set_ready() { ready_ = true; }

void player::send_next_command()
{
	// nu sunt comenzi 
	if (command_queue.empty()) return;

	// trimite comanda
	net::write(connection, command_queue.front());

	// sterge comanda din queue
	command_queue.pop();

	// suntem ocupati sa procesam comanda
	this->set_busy();
}

bool operator==(const player& lhs, const player& rhs)
{
	return &lhs == &rhs;
}
