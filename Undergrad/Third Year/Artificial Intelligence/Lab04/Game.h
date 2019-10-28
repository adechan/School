#pragma once

#include <memory>
#include "Board.h"
//#include "Player.h"

class Player;

class Game
{
public:
	Game();

public:
	bool won() const;
	Board board() const;

	const Player& activePlayer() const;
	const Player& inactivePlayer() const;

	void start();
	void quit();

	bool markCell(int row, int col, const Player& player);

	void setStatus(std::string status);
	void draw();

private:
	void checkWinState();
	void nextTurn();
	bool checkRows() const;
	bool checkColumns() const;
	bool checkDiagonals() const;

private:
	Board board_;
	std::string turnStatus_;
	std::string otherStatus_;
	Player* activePlayer_;
	Player* inactivePlayer_;
	bool running_;
};
