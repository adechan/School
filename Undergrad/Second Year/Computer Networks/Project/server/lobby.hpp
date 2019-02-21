#pragma once

#include <vector>

#include "../net/connection.hpp"
#include "game_session.hpp"

// Lobby unde ii permite serverului sa adauge clienti
// si sa inceapa un joc nou atunci cand sunt 2 clienti in lobby
class lobby
{
public:
	// adauga client in queue
	void new_client(net::connection&& client);

	// gata de meci daca sunt >= 2 clients
	bool is_ready();

	// incepe meciul cu primii 2 clienti
	game_session start_game();

	int size() const;

private:
	// sterge clientii ce si-au inchis conexiunea si au plecat
	void remove_inactive_clients();
	void remove_client(int i);

private:
	std::vector<net::connection> clients_;
};

