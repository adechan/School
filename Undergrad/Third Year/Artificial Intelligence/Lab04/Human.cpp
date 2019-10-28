#include "Human.h"

#include "Game.h"

Human:: Human(std::string name, std::string mark)	
	: Player(name, mark)
{}

void Human::playTurn(Game& game) const
{
	while (true)
	{
		std::string move;
		std::cin >> move;
		if (move == "quit" || move == "exit")
		{
			game.quit();
			return;
		}

		// Look for , in "2,6"
		const auto comma = move.find_first_of(",");
		if (comma == std::string::npos)
		{
			game.setStatus("Select a cell to mark; ex: 1,2\nType quit to stop the game.");
			game.draw();
			continue; // go back to start of the loop
		}

		// Substring before comma
		const auto x_str = move.substr(0, comma);

		// Substring after comma
		const auto y_str = move.substr(comma + 1);

		if (x_str.empty() || y_str.empty())
		{
			game.setStatus("Select a cell to mark; ex: 1,2\nType quit to stop the game.");
			game.draw();
			continue; // go back to start of the loop
		}

		if (!game.markCell(std::stoi(x_str), std::stoi(y_str), *this))
		{
			game.setStatus("Select a cell to mark; ex: 1,2\nType quit to stop the game.");
			game.draw();
			continue; // go back to start of the loop
		}

		break;
	}
}