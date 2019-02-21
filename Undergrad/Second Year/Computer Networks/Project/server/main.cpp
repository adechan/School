#include <iostream>
#include <thread>
#include <queue>
#include <unordered_map>

#include <signal.h>

#include "../net/connection.hpp"
#include "../net/server.hpp"
#include "../net/io.hpp"

#include "lobby.hpp"

static bool fork_is_child(int pid)
{
	return pid == 0;
}

void on_start_game(game_session&& session)
{
	std::cout << "Game started between: "
		<< session.player1().ip_address() << ":" << session.player1().port()
		<< " and "
		<< session.player2().ip_address() << ":" << session.player2().port()
		<< '\n';

	// cream copil pentru a se ocupa de joc (game session)
	int pid = fork();

	if (fork_is_child(pid))
	{
		try
		{
			session.start();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void collect_clients(net::server& server)
{
	// Creaza un lobby gol
	lobby game_lobby;

	while (true)
	{
		try
		{
			// Accepta client nou cu timeout small
			auto client = server.accept_client();
			client.set_timeout(std::chrono::seconds(1));

			std::cout << "New client " << client.ip_address() << ":" << client.port() << '\n';

			// daca primul mesaj al clientului nu este 'connect4' atunci ii respinge
			if (net::read(client) == "connect4")
			{
				// spune clientului ca am acceptat cererea acestuia de a juca
				net::write(client, "accept");

				// ia clientul si il pune in lobby
				game_lobby.new_client(std::move(client));

				std::cout << "Client added to game lobby\n";

				// daca sunt 2 clienti in lobby atunci incepe jocul
				if (game_lobby.is_ready())
					on_start_game(game_lobby.start_game());
			}
		}
		catch  (net::connection_closed_unexpectedly& e)
		{
			std::cout << "Connection closed unexpectedly " << e.what() << '\n';
		}
		catch (net::io_error& e)
		{
			std::cout << "Client I/O error " << e.what() << '\n';
		}
	}
}

int main()
{
	try
	{
		// random seed ( ca rand() sa nu fie la fel mereu)
		std::srand(std::chrono::steady_clock{}.now().time_since_epoch().count());

		// creaza server cu portul 447
		net::server server = net::make_server(net::port(447));
		std::cout << "Game server listening on port " << server.port() << '\n';

		// asteapta clientii
		collect_clients(server);
	}
	catch (net::io_error& e)
	{
		std::cout << "Client I/O error " << e.what() << '\n';
	}
	catch (net::api_error& e)
	{
		std::cout << "API error " << e.what() << '\n';
	}

	return 0;
}
