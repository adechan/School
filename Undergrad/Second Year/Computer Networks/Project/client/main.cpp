#include <iostream>
#include <string>
#include <thread>

#include "../net/connection.hpp"
#include "../net/ip_address.hpp"
#include "../net/io.hpp"

#include "../terminal.hpp"

#include "connect4/server_session.hpp"
#include "connect4/game.hpp"

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "Invalid parameters\n";
		std::cout << "Usage: " << argv[0] << " <server ip> <server port>\n";
		return 0;
	}

	std::cout.sync_with_stdio(false);

	try
	{
		// converteaza argumentii la ip adress si port
		// arunca exceptie daca sunt formatati corect
		net::ip_address server_ip = net::to_ip(argv[1]);
		net::port server_port = net::to_port(argv[2]);

		std::cout << "Welcome to Client/Server Connect4!\n";
		std::cout << "Connecting to game server at " << server_ip << ":" << server_port << "...\n";

		// incepe o sesiune cu serverul, cu ip si portul dat
		// daca serverul nu este connect4 server atunci se arunca o exceptie
		auto server = connect4::server_session(server_ip, server_port);

		// cream un joc
		auto game = connect4::game(std::move(server));

		// incepem jocul
		game.start();
	}
	catch (net::connection_closed_unexpectedly& e)
	{
		std::cout << "Connection closed unexpectedly " << e.what() << '\n';
	}
	catch (net::io_error& e)
	{
		std::cout << "Client I/O error " << e.what() << '\n';
	}
	catch (net::api_error& e)
	{
		std::cout << "API error " << e.what() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}

	return 0;
}
