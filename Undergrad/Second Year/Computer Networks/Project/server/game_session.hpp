#pragma once

#include "game_board.hpp"
#include "player.hpp"

#include <queue>
#include <tuple>

struct player_command
{
	::player* player;
	std::string text;
};

class game_session
{
public:
	// Lista starilor posibile in sesiunea de joc
	enum class state
	{
		start, player1_turn, player2_turn, wait_players,
		place_disc, check_win,
		player1_win, player2_win
	};
	
	// Comenzile pe care le putem trimite unui jucator
	enum class command
	{
		you_win, you_lose, your_turn, you_moved, 
		opponent_quit, opponent_turn, opponent_moved, exit,
		bad_placement,
	};

public:
	// Incepe sesiunea de joc intre 2 jucatori
	explicit game_session(net::connection&& player1, net::connection&& player2);

	// Incepe jocul
	void start();

	const net::connection& player1() const;
	const net::connection& player2() const;

private:
	// Alegem random cine sa mute primul
	void choose_first_player();

	// Seteaza starea jocului
	void set_state(game_session::state s);
	
	// Verifica ce comanda jocatorul ne-a trimis
	void process_player_command(player& current, player& other);

	// Queue comanda pentru a o trimite, daca jucatorul este ocupat
	void queue_command(player& player, game_session::command command, const std::string& parameter = "");

	// Trimite comanda data jucatorului cu parametru optional
	void send_command(player& player, game_session::command command, const std::string& parameter = "");

	// Verifica daca ambii jucatori pentru a vedea daca au trimit comenzi noi 
	void poll_players();

private:
	player player1_;
	player player2_;
	game_session::state state_;


	game_board board_;
};
