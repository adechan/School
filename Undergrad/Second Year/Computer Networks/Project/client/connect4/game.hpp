#pragma once

#include "board.hpp"
#include "player.hpp"
#include "server_session.hpp"

#include "../../net/connection.hpp"

#include <chrono>

namespace connect4
{
	class game
	{
		// lista cu starile jocului
		enum class state
		{
			lobby, your_turn, opponent_turn, win, lose, quit, wait_server
		};

	public:
		void start();

		explicit game(server_session&& server);

	private:
		// input de la user
		void process_input(const std::string& command);

		// comenzi de la server
		void process_server_state();

		// game loop
		void loop();

		// update status text ('Your turn' , 'Opponent's turn')
		void update_player_status(const player& player);

		// incearca sa plaseze disc in coloana pentru un player dat
		void place_disc(int column, const player& player);

		// parasim jocul daca quit
		void on_quit();

		// seteaza game state curent
		void set_state(state s);

	private:
		server_session server_;
		board board_; state state_;
		player you_, opponent_;
		player* current_player_;

	};
}
