#include "server_session.hpp"

#include "../../net/io.hpp"

namespace connect4
{
	server_session::server_session(net::ip_address ip, net::port port)
		: connection_(net::connect(ip, port))
	{
		// incepe prin cererea connect4 de la server
		this->send_command(command::connect4);

		// daca serverul nu trimite accept, atunci este connect4 server invalid
		if (this->next_state() != state::accept)
			throw net::api_error("[server_session::{ctor}] Invalid server");
	}

	// bazat pe comanda, trimite textul corespunzator cu parametru optional
	void server_session::send_command(server_session::command command, const std::string& parameter)
	{
		switch (command)
		{
		case command::connect4:
			net::write(connection_, "connect4");
			break;

		case command::place_disc:
			net::write(connection_, "place_disc:" + parameter);
			break;

		case command::ready:
			net::write(connection_, "ready");
			break;

		case command::busy:
			net::write(connection_, "busy");
			break;

		case command::quit:
			net::write(connection_, "quit");
			break;
		}
	}

	static bool string_contains(const std::string& string, const std::string& contains)
	{
		return string.find(contains) != std::string::npos;
	}

	server_session::state server_session::next_state()
	{
		// citeste string de la server
		server_response_ = net::read(connection_);

		// daca serverul raspunde cu o comanda data, atunci return starea corespunzatoare 
		if (server_response_ == "opponent_quit")
			return state::opponent_quit;

		else if (server_response_ == "opponent_turn")
			return state::opponent_turn;

		else if (server_response_ == "your_turn")
			return state::your_turn;

		else if (string_contains(server_response_, "opponent_moved"))
			return state::opponent_moved;

		else if (string_contains(server_response_, "you_moved"))
			return state::you_moved;

		else if (server_response_ == "bad_placement")
			return state::bad_placement;

		else if (server_response_ == "win")
			return state::win;

		else if (server_response_ == "lose")
			return state::lose;

		else if (server_response_ == "lobby")
			return state::lobby;

		else if (server_response_ == "accept")
			return state::accept;

		return state::exit;
	}

	bool server_session::has_data(std::chrono::milliseconds timeout)
	{
		return net::has_data(connection_, timeout);
	}

	const std::string& server_session::response() const
	{
		return server_response_;
	}

	std::string server_session::parameter() const
	{
		// uita-te dupa parametrul optional in raspunsul serverului
		const auto it = server_response_.find_first_of(':');
		if (it == std::string::npos)
			return "";

		// returneaza parametrul dupa ':' in raspunsul serverului
		return server_response_.substr(it + 1);
	}
}
