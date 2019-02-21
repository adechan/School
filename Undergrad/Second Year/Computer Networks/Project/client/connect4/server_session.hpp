#pragma once

#include "../../net/connection.hpp"

#include <chrono>

namespace connect4
{
	// manevreaza comunicarea cu serverul
	class server_session
	{
	public:
		// lista cu starile serverul pe care le putem primi
		enum class state
		{ 
			lobby, accept,
			opponent_quit,
			exit,

			bad_placement,

			opponent_turn,
			your_turn,

			opponent_moved,
			you_moved,

			win, lose,
		};


		// lista cu comenzile pe care le putem trimite serverului
		enum class command
		{
			connect4,
			place_disc,
			quit,
			ready, busy
		};

	public:
		explicit server_session(net::ip_address, net::port);

		void send_command(server_session::command, const std::string& parameter = "");

		// get the server's next state
		state next_state();


		// verifica daca serverul are data 
		bool has_data(std::chrono::milliseconds timeout);

		// ia ultimul mesaj de la server
		const std::string& response() const;

		// daca ultimul mesaj a avut parametru, returneaza parametrul
		std::string parameter() const;

	private:
		net::connection connection_;
		std::string server_response_;
	};
}
