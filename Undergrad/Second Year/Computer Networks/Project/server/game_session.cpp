#include "game_session.hpp"
#include "../net/io.hpp"

#include <random>
#include <chrono>
#include <thread>

// Ia parametrul ce face parte din 'command' (forma "<command>:<parameter>")
static std::string parameter(const std::string& command)
{
	return command.substr(command.find(':') + 1);
}

// Determina daca 'contains' este substring a lui 'string'
static bool string_contains(const std::string& string, const std::string& contains)
{
	return string.find(contains) != std::string::npos;
}

// Data comanda si parametrul optional, formateaza stringul pentru a fi trimis catre jucator
static std::string format_command(game_session::command command, const std::string& parameter = "")
{
	switch (command)
	{
	case game_session::command::exit:
		return "exit";
		break;

	case game_session::command::your_turn:
		return "your_turn";
		break;

	case game_session::command::you_moved:
		return "you_moved:" + parameter;
		break;

	case game_session::command::opponent_quit:
		return "opponent_quit";
		break;

	case game_session::command::opponent_turn:
		return "opponent_turn";
		break;

	case game_session::command::opponent_moved:
		return "opponent_moved:" + parameter;
		break;
	}

	return "";
}

void game_session::send_command(player& player, game_session::command command, const std::string& parameter)
{
	// Daca jucatorul este ocupat atunci queue comanda pentru a fi trimisa cand sunt liberi
	if (player.is_busy())
	{
		player.set_busy();
		player.command_queue.push(format_command(command, parameter));
	}

	// Altfel trimit imediat comanda
	else
		net::write(player.connection, format_command(command, parameter));
}

void game_session::process_player_command(player& current, player& other)
{
	// citeste string de la jucatorul curent
	const auto command = net::read(current.connection);

	// daca jucatorul este ocupat atunci vom trimite comanda cand acesta este gata
	if (string_contains(command, "busy"))
		current.set_busy();

	// daca jucatorul este gata, putem trimite comanda
	else if (string_contains(command, "ready"))
		current.set_ready();

	// jucatorul vrea sa plaseze un disc
	else if (string_contains(command, "place_disc"))
	{
		// converteaza parametrul in integer
		int column = std::stoi(parameter(command));

		// verifica daca discul poate fi plasat acolo unde doreste jucatorul
		if (board_.place_disc(column, current.name))
		{
			// spune jucatorului ca discul a fost plasat
			// clientul updateaza tabla de joc (animatie pentru disc)
			send_command(current, command::you_moved, std::to_string(column));

			// spune celuilalt jucator ca jucatorul curent si-a terminat mutarea
			send_command(other, command::opponent_moved, std::to_string(column));

			// verifica daca cineva a castigat
			if (board_.check_win("player1"))
			{
				this->set_state(state::player1_win);
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				std::cerr << "player1 won!\n";
			}

			else if (board_.check_win("player2"))
			{
				this->set_state(state::player2_win);
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				std::cerr << "player2 won!\n";
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));

				// daca nu a castigat nimeni, 
				// urmeaza celalalt jucator sa faca o mutare
				send_command(other, command::your_turn);
				send_command(current, command::opponent_turn);
				this->set_state(state::wait_players);
			}
		}
		else
		{
			// nu se poate muta discul in zona respectiva
			send_command(current, command::bad_placement);
			this->set_state(game_session::state::wait_players);
		}
	}

	else if (string_contains(command, "quit"))
		send_command(other, command::opponent_quit);
}

void game_session::poll_players()
{
	// daca player1 este gata atunci trimite comanda
	if (player1_.is_ready())
		player1_.send_next_command();

	if (player2_.is_ready())
		player2_.send_next_command();

	// daca jucatorii au trimis o comanda noua, atunci verifica ce au trimis
	if (net::has_data(player1_.connection))
		this->process_player_command(player1_, player2_);

	else if (net::has_data(player2_.connection))
		this->process_player_command(player2_, player1_);
}

void game_session::start()
{
	while (true)
	{
		switch (state_)
		{
		case game_session::state::start:
			// alege random
			this->choose_first_player();
			break;

		case state::player1_win:
			std::cerr << "state::player1_win\n";
			// spune player1 ca a castigat, and player2 ca a pierdut
			send_command(player1_, command::you_win);
			send_command(player2_, command::you_lose);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			this->set_state(state::wait_players);
			break;

		case state::player2_win:
			std::cerr << "state::player1_win\n";
			// spune player2 ca a castigat, and player1 ca a pierdut
			send_command(player2_, command::you_win);
			send_command(player1_, command::you_lose);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			this->set_state(state::wait_players);
			break;

		case game_session::state::wait_players:
			// verifica daca jucatorii au trimis comenzi
			this->poll_players();
			break;

		case game_session::state::player1_turn:
			// spune player1 ca e randul sau
			send_command(player1_, command::your_turn);

			// spune player2 ca e randul oponentului sau
			send_command(player2_, command::opponent_turn);
			this->set_state(game_session::state::wait_players);
			break;

		case game_session::state::player2_turn:
			// spune player2 ca e randul sau
			send_command(player2_, command::your_turn);

			// spune player1 ca e randul oponentului sau
			send_command(player1_, command::opponent_turn);
			this->set_state(game_session::state::wait_players);
			break;
		}
	}
}

// alegem random cine sa inceapa jocul
void game_session::choose_first_player()
{
	if (std::rand() % 2 == 0)
		this->set_state(game_session::state::player1_turn);
	else
		this->set_state(game_session::state::player2_turn);
}

void game_session::set_state(game_session::state s)
{
	state_ = s;
}

const net::connection& game_session::player1() const
{ return player1_.connection; }

const net::connection& game_session::player2() const
{ return player2_.connection; }

game_session::game_session(net::connection&& player1, net::connection&& player2)
	: player1_(std::move(player1), "player1")
	, player2_(std::move(player2), "player2")
	, state_(game_session::state::start)
{}
