#include "game_board.hpp"

#include <iostream>

game_board::game_board()
{
	for (auto& row : board_)
		for (auto& disc : row)
			disc = disc_state::empty;
}

game_board::disc_state game_board::to_disc_state(const std::string& name)
{
	if (name == "player1")
		return game_board::disc_state::player1;

	else if (name == "player2")
		return game_board::disc_state::player2;

	return game_board::disc_state::empty;
}

std::string game_board::to_string(game_board::disc_state disc)
{
	switch (disc)
	{
		case disc_state::empty: return "empty";
		case disc_state::player1: return "player1";
		case disc_state::player2: return "player2";
	}

	return "";
}

bool game_board::check_horizontal(int start_x, int y, disc_state state)
{
	if (game_board::width - start_x < 4) return false;
	int count = 0;

	for (int x = start_x; x < game_board::width && count < 4; ++x)
	{
		if (board_[x][y] != state)
			return false;

		count++;
	}

	return count == 4;
}

bool game_board::check_vertical(int x, int start_y, disc_state state)
{
	if (game_board::height - start_y < 4) return false;
	int count = 0;

	for (int y = start_y; y < game_board::height && count < 4; ++y)
	{
		if (board_[x][y] != state)
			return false;

		count++;
	}

	return count == 4;
}

bool game_board::check_horizontals(disc_state state)
{
	for (int x = 0; x < game_board::width; x++)
		for (int y = 0; y < game_board::height; y++)
			if (this->check_horizontal(x, y, state))
				return true;

	return false;
}

bool game_board::check_verticals(disc_state state)
{
	for (int x = 0; x < game_board::width; x++)
		for (int y = 0; y < game_board::height; y++)
			if (this->check_vertical(x, y, state))
				return true;

	return false;
}

bool game_board::check_left_diagonal(int start_x, int start_y, disc_state state)
{
	int count = 0;

	for (
		int x = start_x, y = start_y;
		y < game_board::height && x < game_board::width && count < 4;
		x--, y++
	)
	{
		if (board_[x][y] != state)
			return false;

		count++;
	}

	return count == 4;
}

/*
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |
*/

bool game_board::check_right_diagonal(int start_x, int start_y, disc_state state)
{
	int count = 0;

	for (
		int x = start_x, y = start_y; 
		 x < game_board::width && y < game_board::height && count < 4;
		x++, y++
	)
	{
		if (board_[x][y] != state)
			return false;

		count++;
	}

	return count == 4;
}

bool game_board::check_diagonals(disc_state state)
{
	for (int x = 0; x < game_board::width; x++)
		for (int y = 0; y < game_board::height; y++)
			if (this->check_left_diagonal(x, y, state) || this->check_right_diagonal(x, y, state))
				return true;

	return false;
}

bool game_board::check_win(const std::string& player_name)
{
	disc_state disc = to_disc_state(player_name);
	return this->check_horizontals(disc) || this->check_verticals(disc) || this->check_diagonals(disc);
}

void game_board::print()
{
	for (const auto& row : board_)
	{
		for (const auto& disc : row)
			std::cerr << to_string(disc) << ' ';

		std::cerr << '\n';
	}
}

bool game_board::place_disc(int column, const std::string& player_name)
{
	if (column > game_board::width) return false;

	std::cerr << player_name << '\n';
	for (int i = game_board::height - 1; i >= 0; --i)
	{
		if (board_[column - 1][i] == disc_state::empty)
		{
			board_[column - 1][i] = to_disc_state(player_name);
			return true;
		}
	}

	return true;
}
