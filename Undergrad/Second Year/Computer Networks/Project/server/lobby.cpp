#include "lobby.hpp"

#include <sys/types.h>
#include <unistd.h>

void lobby::new_client(net::connection&& client)
{
	this->remove_inactive_clients();
	clients_.push_back(std::move(client));
}

bool lobby::is_ready()
{
	this->remove_inactive_clients();
	return this->size() >= 2;
}

game_session lobby::start_game()
{
	// ia 2 conexiuni de la inceputul queue-ului
	auto player1 = std::move(clients_[0]);
	auto player2 = std::move(clients_[1]);

	// obiectele 'connection' : player1, player2
	// sterge conexiunile goale din queue 
	this->remove_client(0);
	this->remove_client(1);

	// returneaza jocul nou intre 2 jucatori
	return game_session(std::move(player1), std::move(player2));
}

int lobby::size() const
{
	return clients_.size();
}

void lobby::remove_inactive_clients()
{
	for (int i = 0; i < clients_.size(); ++i)
	{
		// daca clientii nu sunt activi, atunci ii eliminam din queue
		if (clients_[i].is_closed())
		{
			clients_[i].close();
			this->remove_client(i);
		}
	}
}

void lobby::remove_client(int i)
{
	clients_.erase(clients_.begin() + i);
}
