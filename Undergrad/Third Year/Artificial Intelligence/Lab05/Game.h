#pragma once

#include <memory>
#include "Board.h"

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
	
	const Player& otherPlayer(const Player& player) const;

	void start();
	void quit();

	bool markCell(int row, int col, const Player& player);

	void setStatus(std::string status);
	void draw();

	static bool checkWin(const Board& board, std::string mark);
	static bool checkTie(const Board& board);

	static bool checkRows(const Board& board, std::string mark);
	static bool checkColumns(const Board& board, std::string mark);
	static bool checkDiagonals(const Board& board, std::string mark);

private:
	void nextTurn();
	void handleWinState();

private:
	Board board_;
	std::string turnStatus_;
	std::string otherStatus_;
	Player* activePlayer_;
	Player* inactivePlayer_;
	bool running_;
};
