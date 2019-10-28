#pragma once
#include "Player.h"

class Board;

class Computer : public Player
{
public:
	void playTurn(Game& game) const override;

	Computer() {};
	explicit Computer(std::string name, std::string mark);

private:
	int evaluateBoard(const Board& gameBoard) const;
};
