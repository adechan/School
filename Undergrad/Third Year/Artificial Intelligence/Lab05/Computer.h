#pragma once
#include "Player.h"

class Board;

class Computer : public Player
{
public:
	void playTurn(Game& game) const override;

	Computer() {};
	explicit Computer(std::string name, std::string mark);

public:
	static int evaluateBoard(const Board& gameBoard, std::string mark);
};
