#pragma once
#include <array>

#include "Cell.h"

// We represent the game state as a board.
class Board
{
protected:
	// 3x3 matrix 
	std::array<std::array<Cell, 3>, 3> board_;

public:
	Board();

	void draw();
	bool markCell(int x, int y, const Player& owner);

	Board newBoardWithMark(int x, int y, const Player& owner) const;

	int size() const;
	int numEmptyCells() const;

	Cell operator()(int x, int y) const;
	std::array<std::array<Cell, 3>, 3> rows() const;
	std::array<std::array<Cell, 3>, 3> columns() const;
	std::array<std::array<Cell, 3>, 2> diagonals() const;

private:

	// Initial State
	std::array<std::array<Cell, 3>, 3> initializeBoard()
	{
		std::array<std::array<Cell, 3>, 3> board;
		for (unsigned int row = 0; row < board.size(); row++)
			for (unsigned int column = 0; column < board.size(); column++)
				board[row][column] = Cell{};

		return board;
	}

	// Print the matrix
	void printMatrix(std::array<std::array<Cell, 3>, 3> board);
};