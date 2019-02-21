#include "game.hpp"
#include "../../terminal.hpp"

#include <thread>

static bool is_number(const std::string& text)
{
	return text.find_first_not_of("0123456789") == std::string::npos;
}

namespace connect4
{
	game::game(server_session&& server)
		: server_(std::move(server))
		, you_({ "You", connect4::color::yellow })
		, opponent_({ "Opponent", connect4::color::red })
		, state_(state::lobby)
		, current_player_(&you_)
	{}

	void game::update_player_status(const player& player)
	{
		// daca player este 'you' -> status text pe tabla = 'Your turn' 
		if (&player == &you_)
			board_.set_status(
				terminal::format_color("Your", to_terminal_color(you_.color))
				+ " turn"
			);

		// daca player este 'opponent' -> status text pe tabla = 'Opponent's turn' 
		else
			board_.set_status(
				terminal::format_color(opponent_.name, to_terminal_color(opponent_.color))
				+ "'s turn"
			);
	}
	
	void game::on_quit()
	{
		// spune serverului ca plecam
		server_.send_command(server_session::command::quit);

		// clear terminal 
		terminal::cursor::next_line();
		terminal::cursor::next_line();
		graphics::update();
	}

	void game::process_input(const std::string& input)
	{
		int column = -1; 
		// user vrea sa plece
		if (input == "quit")
			this->set_state(state::quit);

		// altfel adauga o coloana pentru a plasa discul
		else if (is_number(input))
		{
			try { column = std::stoi(input); }
			catch (std::out_of_range& e) {}
			
			if (board_.check_disc_place(column))
			{
				server_.send_command(server_session::command::place_disc, input);
				this->set_state(state::wait_server);
			}
		}
	}

	void game::place_disc(int column, const player& player)
	{
		board_.place_disc(column, player.color);
	}

	void game::process_server_state()
	{
		if (!server_.has_data(std::chrono::milliseconds(10)))
			return;

		// ia comanda serverului
		board_.debug_message("get next state");
		const auto command = server_.next_state();

		switch (command)
		{
		case server_session::state::win:
			this->set_state(state::win);
			break;

		case server_session::state::lose:
			this->set_state(state::lose);
			break;

		case server_session::state::lobby:
			board_.debug_message("process_server_state: lobby");
			this->set_state(state::lobby);
			break;

		case server_session::state::opponent_moved:
			// cat timp are loc animatia discului suntem ocupati
			server_.send_command(server_session::command::busy);
			this->place_disc(std::stoi(server_.parameter()), opponent_);
			server_.send_command(server_session::command::ready);
			this->set_state(state::wait_server);
			break;

		case server_session::state::you_moved:
			board_.debug_message("process_server_state: you_moved");

			// cat timp are loc animatia discului suntem ocupati
			server_.send_command(server_session::command::busy);
			this->place_disc(std::stoi(server_.parameter()), you_);
			server_.send_command(server_session::command::ready);

			this->set_state(state::wait_server);
			break;

		case server_session::state::bad_placement:
			board_.debug_message("process_server_state: bad_placement");

			// daca nu poti plasa discul in locul respectiv, 
			// serverul intreaba userul sa plaseze iar
			this->set_state(state::your_turn);
			board_.set_status("Bad disc placement!");

			// suntem ocupati cat timp asteptam pentru user input
			server_.send_command(server_session::command::busy);
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		case server_session::state::your_turn:
			board_.debug_message("process_server_state: your_turn");
			this->set_state(state::your_turn);
			current_player_ = &you_;
			break;

		case server_session::state::opponent_turn:
			board_.debug_message("process_server_state: opponent_turn");
			this->set_state(state::opponent_turn);
			current_player_ = &opponent_;
			break;

		case server_session::state::opponent_quit:
			board_.debug_message("process_server_state: opponent_quit");
			board_.set_status("Opponent quit! You win!");
			this->set_state(state::quit);
			break;
		}
	}

	void game::loop()
	{
		while (true)
		{
			switch (state_)
			{
			case state::lobby:
				board_.debug_message("state: lobby");
				board_.set_status("Waiting for other player to join...");
				server_.send_command(server_session::command::ready);

				// spune serverului ca suntem gata
				this->set_state(state::wait_server);
				break;

			case state::wait_server:
				board_.debug_message("state: wait_server");
				this->process_server_state();

				// spune serverului ca suntem gata
				server_.send_command(server_session::command::ready);
				break;

			case state::your_turn:
				board_.debug_message("state: your_turn");
				// spune serverului ca suntem ocupati
				server_.send_command(server_session::command::busy);

				// updateaza player status si ia user input
				this->update_player_status(you_);
				this->process_input(board_.player_input());
				break;

			case state::opponent_turn:
				board_.debug_message("state: opponent_turn");
				// cat timp updatam statusul sunt ocupati
				server_.send_command(server_session::command::busy);
				this->update_player_status(opponent_);
				server_.send_command(server_session::command::ready);

				// acum putem lua noi comenzi de la server
				this->set_state(state::wait_server);
				break;

			case state::win:
				board_.set_status("You win!");
				board_.debug_message("state: win");
				std::this_thread::sleep_for(std::chrono::seconds(5));
				return;
				break;

			case state::lose:
				board_.set_status("You lose!");
				board_.debug_message("state: lose");
				std::this_thread::sleep_for(std::chrono::seconds(5));
				return;
				break;

			case state::quit:
				board_.debug_message("state: quit");
				this->on_quit();
				return;
				break;
			}
		}
	}

	void game::start()
	{
		this->loop();
	}

	void game::set_state(game::state s)
	{
		state_ = s;
	}

}
