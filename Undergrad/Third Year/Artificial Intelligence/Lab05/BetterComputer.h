#pragma once
#include "Player.h"

class Board;
class Game;

class BetterComputer : public Player
{
public:
	void playTurn(Game& game) const override;

	BetterComputer() {};
	explicit BetterComputer(std::string name, std::string mark);

private:
	struct move
	{
		int score;
		int row;
		int col;
	};

private:
	move minimax(Game& game, const Board& nodeBoard, const Player& player, int currentDeph = 0) const;
};
