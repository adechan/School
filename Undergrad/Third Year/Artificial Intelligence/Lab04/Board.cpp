#include "Board.h"
#include <iostream>
#include "Player.h"

Board::Board()
	: board_(this->initializeBoard())
{}

void Board::draw()
{
	this->printMatrix(board_);
}

bool Board::markCell(int x, int y, const Player& owner)
{
	// Make sure row and column are inside the board
	if ((x > 2 || x < 0) || (y > 2 || y < 0))
		return false;

	// If there is something already there, then say we can't do it
	if (!board_[x][y].isEmpty())
		return false;

	// Otherwise, set the cell to have the mark and owner
	board_[x][y] = Cell{owner.mark(), owner};
	return true;
}

Board Board::newBoardWithMark(int x, int y, const Player& owner) const
{
	Board board = *this;
	board.markCell(x, y, owner);
	return board;
}

int Board::size() const
{
	return board_.size();
}

std::array<std::array<Cell, 3>, 3> Board::rows() const
{
	return board_;
}

// so we get the columns
std::array<std::array<Cell, 3>, 3> Board::columns() const
{
	auto transposedBoard = board_;
	for (int i = 0; i < size(); i++)
		for (int j = 0; j < size(); j++)
			transposedBoard[i][j] = board_[j][i];

	return transposedBoard;
}

std::array<std::array<Cell, 3>, 2> Board::diagonals() const
{
	std::array<Cell, 3> mainDiagonal;
	std::array<Cell, 3> otherDiagonal;

	mainDiagonal[0] = board_[0][0];
	mainDiagonal[1] = board_[1][1];
	mainDiagonal[2] = board_[2][2];

	otherDiagonal[0] = board_[0][2];
	otherDiagonal[1] = board_[1][1];
	otherDiagonal[2] = board_[2][0];

	return {mainDiagonal, otherDiagonal};
}

// Print the matrix
void Board::printMatrix(std::array<std::array<Cell, 3>, 3> board)
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			std::cout << board[row][column] << " ";
		}

		std::cout << std::endl;
	}
}

int Board::numEmptyCells() const
{
	int count = 0;
	for (int i = 0; i < size(); i++)
		for (int j = 0; j < size(); j++)
			if (board_[i][j].isEmpty())
				count++;

	return count;
}


Cell Board::operator()(int x, int y) const
{
	return board_[x][y];
}
