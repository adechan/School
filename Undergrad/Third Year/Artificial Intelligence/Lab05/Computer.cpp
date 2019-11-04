#include "Computer.h"
#include <array>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include "Game.h"
#include "Board.h"

Computer::Computer(std::string name, std::string mark)
	: Player(name, mark)
{}

struct move
{
	int score;
	int row;
	int col;
};

void Computer::playTurn(Game& game) const
{
	// score, row, col
	move bestMove;
	bestMove.score = -99999999;

	const auto& board = game.board();

	// All possible moves
	for (int row = 0; row < board.size(); row++)
	{
		for (int col = 0; col < board.size(); col++)
		{
			if (board(row, col).isEmpty())
			{
				// Consider what would happen if the other player chose to mark row, col.
				Board possibleMove = board.newBoardWithMark(row, col, game.inactivePlayer());

				//std::cout << "Possible state: \n";
				//possibleMove.draw();

				// And choose the maximum score.
				int score = Computer::evaluateBoard(possibleMove, this->mark());

				if (score > bestMove.score)
				{
					bestMove.score = score;
					bestMove.row = row;
					bestMove.col = col;
				}
			}
		}
	}

	// mark the cell as X
	game.markCell(bestMove.row, bestMove.col, *this);
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

// Heuristics function
int Computer::evaluateBoard(const Board& gameBoard, std::string mark)
{
	// add the score for all diagonals, rows and columns
	int score = 0;

	// add row, column, diagonals in ROWS
	std::vector<std::array<Cell, 3>> rows;
	for (auto row : gameBoard.rows())
		rows.push_back(row);

	for (auto row : gameBoard.columns())
		rows.push_back(row);

	for (auto row : gameBoard.diagonals())
		rows.push_back(row);

	// calculates for each row the score
	for (auto row : rows)
	{
		// computer = X
		int numOurMarks = 0;
		for (int i = 0; i < row.size(); i++)
			if (!row[i].isEmpty() && row[i].player().mark() == mark)
				numOurMarks++;

		// human = O
		int numOtherMarks = 0;
		for (int i = 0; i < row.size(); i++)
			if (!row[i].isEmpty() && row[i].player().mark() != mark)
				numOtherMarks++;

		// Make sure other player does not win
		if (numOtherMarks == 0)
			score -= std::pow(10, numOurMarks);

		else if (numOurMarks == 0)
			score += std::pow(10, numOtherMarks);

		else if (numOurMarks >= 2)
			score += std::pow(10, 2 - numOtherMarks);
	}

	// score of the board
	return score;
}
