#pragma once

#include <array>
#include <string>

class game_board
{
public:


public:
	static constexpr int height = 6;
	static constexpr int width = 6;

	explicit game_board();
	
	// Printeaza tabla de joc
	void print();

	// Verifica daca discul poate fi plasat in coloana data, si il plaseaza daca poate fi
	bool place_disc(int column, const std::string& player_name);

	// Verifica daca playerul dat a castigat jocul
	bool check_win(const std::string& player_name);

private:
	enum class disc_state
	{ empty, player1, player2, };

	disc_state to_disc_state(const std::string& name);
	std::string to_string(game_board::disc_state disc);

	bool check_horizontals(disc_state state);
	bool check_horizontal(int start_x, int y, disc_state state);

	bool check_verticals(disc_state state);
	bool check_vertical(int x, int start_y, disc_state state);

	bool check_diagonals(disc_state state);
	bool check_left_diagonal(int start_x, int start_y, disc_state state);
	bool check_right_diagonal(int start_x, int start_y, disc_state state);

private:
	std::array<std::array<disc_state, game_board::width>, game_board::height> board_;
};
