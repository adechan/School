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

				std::cout << "Possible state: \n";
				possibleMove.draw();

				// And choose the maximum score.
				int score = this->evaluateBoard(possibleMove);

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
int Computer::evaluateBoard(const Board& gameBoard) const
{
	int score = 0;

	// add row, column, diagonals in ROWS
	std::vector<std::array<Cell, 3>> rows;
	for (auto row : gameBoard.rows())
		rows.push_back(row);

	for (auto row : gameBoard.columns())
		rows.push_back(row);

	for (auto row : gameBoard.diagonals())
		rows.push_back(row);

	// get our mark
	std::string mark = this->mark();

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

		// initial:
		// _ _ _
		// 0 X o
		// _ _ _

		// 1st consideration:
		// O O X
		// _ X _
		// O _ _

		// O O X 
		// X X _ 
		// O _ _ 

		// Make sure other player does not win
		if (numOtherMarks == 0)
			score -= std::pow(10, numOurMarks);

		else if (numOurMarks == 0)
			score += std::pow(10, numOtherMarks);
	}

	return score;

	// Evaluate Board: heuristic function
	/*
		X X X : +100
		O O O : -100
		X X _ : +50
		O O _ : -50
		X _ _ : +10
		O _ _ : -10
		_ _ _ : 0
		X O _ : 0
	*/

	// Computer or Player wins on row: 
	// X = AI ; O = player
	//for (int row = 0; row < 3; row++)
	//{
	//	if (board[row][0].value() != "_" && board[row][1].value() != "_" && board[row][2].value() != "_")
	//	{
	//		if (board[row][0].value() == board[row][1].value() &&
	//			board[row][1].value() == board[row][2].value())
	//		{
	//			if (board[row][0].value().compare("X"))
	//				return +100;
	//			else if (board[row][0].value().compare("O"))
	//				return -100;
	//		}
	//	}
	//}

	//// Computer or Player wins on column:
	//for (int column = 0; column < 3; column++)
	//{
	//	if (board[0][column].value() != "_" && board[1][column].value() != "_" && board[2][column].value() != "_")
	//	{
	//		if (board[0][column].value() == board[1][column].value() &&
	//			board[1][column].value() == board[2][column].value())
	//		{
	//			if (board[0][column].value().compare("X"))
	//				return +100;
	//			else if (board[0][column].value().compare("O"))
	//				return -100;
	//		}
	//	}

	//}

	//// Computer or Player wins on diagonal \:
	//if (board[0][0].value() == board[1][1].value() && board[1][1].value() == board[2][2].value() &&
	//	board[0][0].value() != "_" && board[1][1].value() != "_" && board[2][2].value() != "_")
	//{

	//	if (board[0][0].value().compare("X"))
	//		return +100;
	//	else if (board[0][0].value().compare("O"))
	//		return -100;
	//}

	//// Computer or Player wins on diagonal /:
	//if (board[0][2].value() == board[1][1].value() && board[1][1].value() == board[2][0].value() &&
	//	board[0][2].value() != "_" && board[1][1].value() != "_" && board[2][0].value() != "_")
	//{
	//	if (board[0][0].value().compare("X"))
	//		return +100;
	//	else if (board[0][0].value().compare("O"))
	//		return -100;
	//}

	//// 		X X _ : +50 || X _ X || _ X X
	////		O O _ : -50 || O _ O || _ O O
	//for (int row = 0; row < 3; row++)
	//{
	//	if (board[row][0].value() == board[row][1].value() && board[row][2].value().compare("_") ||
	//		board[row][0].value() == board[row][2].value() && board[row][1].value().compare("_") ||
	//		board[row][0].value().compare("_") && board[row][1].value() == board[row][2].value())
	//	{
	//		if (board[row][0].value().compare("X"))
	//			return +50;
	//		else if (board[row][0].value().compare("O"))
	//			return -50;
	//	}
	//}

	//for (int column = 0; column < 3; column++)
	//{
	//	if (board[0][column].value() == board[1][column].value() && board[2][column].value().compare("_") ||
	//		board[0][column].value() == board[2][column].value() && board[1][column].value().compare("_") ||
	//		board[0][column].value().compare("_") && board[1][column].value() == board[2][column].value())
	//	{
	//		if (board[0][column].value().compare("X"))
	//			return +50;
	//		else if (board[0][column].value().compare("O"))
	//			return -50;
	//	}
	//}

	//// Diagonals 
	//// 		X X _ : +50 || X _ X || _ X X
	////		O O _ : -50 || O _ O || _ O O
	//if (board[0][0].value().compare("X") && board[1][1].value().compare("X") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("X") && board[1][1].value().compare("_") && board[2][2].value().compare("X") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("X") && board[2][2].value().compare("X"))
	//	return +50;

	//if (board[0][0].value().compare("O") && board[1][1].value().compare("O") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("O") && board[1][1].value().compare("_") && board[2][2].value().compare("O") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("O") && board[2][2].value().compare("O"))
	//	return -50;

	//if (board[0][2].value().compare("X") && board[1][1].value().compare("X") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("X") && board[1][1].value().compare("_") && board[2][0].value().compare("X") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("X") && board[2][0].value().compare("X"))
	//	return +50;

	//if (board[0][2].value().compare("O") && board[1][1].value().compare("O") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("O") && board[1][1].value().compare("_") && board[2][0].value().compare("O") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("O") && board[2][0].value().compare("O"))
	//	return -50;




	//// X _ _ : +10 || _ X _ || _ _ X
	//// O _ _ : -10 || _ O _ || _ _ O
	//for (int row = 0; row < 3; row++)
	//{
	//	if (board[row][0].value().compare("X") && board[row][1].value().compare("_") && board[row][2].value().compare("_") ||
	//		board[row][0].value().compare("_") && board[row][1].value().compare("X") && board[row][2].value().compare("_") ||
	//		board[row][0].value().compare("_") && board[row][1].value().compare("_") && board[row][2].value().compare("X"))
	//		return +10;
	//}

	//for (int row = 0; row < 3; row++)
	//{
	//	if (board[row][0].value().compare("O") && board[row][1].value().compare("_") && board[row][2].value().compare("_") ||
	//		board[row][0].value().compare("_") && board[row][1].value().compare("O") && board[row][2].value().compare("_") ||
	//		board[row][0].value().compare("_") && board[row][1].value().compare("_") && board[row][2].value().compare("O"))
	//		return -10;
	//}

	//for (int column = 0; column < 3; column++)
	//{
	//	if (board[0][column].value().compare("X") && board[1][column].value().compare("_") && board[2][column].value().compare("_") ||
	//		board[0][column].value().compare("_") && board[1][column].value().compare("X") && board[2][column].value().compare("_") ||
	//		board[0][column].value().compare("_") && board[1][column].value().compare("_") && board[2][column].value().compare("X"))
	//		return +10;
	//}

	//for (int column = 0; column < 3; column++)
	//{
	//	if (board[0][column].value().compare("O") && board[1][column].value().compare("_") && board[2][column].value().compare("_") ||
	//		board[0][column].value().compare("_") && board[1][column].value().compare("O") && board[2][column].value().compare("_") ||
	//		board[0][column].value().compare("_") && board[1][column].value().compare("_") && board[2][column].value().compare("O"))
	//		return -10;
	//}

	//// Diagonals 
	//// X _ _ : +10 || _ X _ || _ _ X
	//// O _ _ : -10 || _ O _ || _ _ O
	//if (board[0][0].value().compare("X") && board[1][1].value().compare("_") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("X") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("_") && board[2][2].value().compare("X"))
	//	return +10;

	//if (board[0][0].value().compare("O") && board[1][1].value().compare("_") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("O") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("_") && board[2][2].value().compare("O"))
	//	return -10;

	//if (board[0][2].value().compare("X") && board[1][1].value().compare("_") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("X") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("_") && board[2][0].value().compare("X"))
	//	return +10;

	//if (board[0][2].value().compare("O") && board[1][1].value().compare("_") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("O") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("_") && board[2][0].value().compare("O"))
	//	return -10;

	//// _ _ _ : 0
	//for (int row = 0; row < 3; row++)
	//{
	//	if (board[row][0].value().compare("_") && board[row][1].value().compare("_") && board[row][2].value().compare("_"))
	//		return +0;
	//}

	//for (int column = 0; column < 3; column++)
	//{
	//	if (board[0][column].value().compare("_") && board[1][column].value().compare("_") && board[2][column].value().compare("_"))
	//		return +0;
	//}

	//// X O _ : 0 || O X _ || X _ O || O _ X || _ O X || _ X O
	//for (int row = 0; row < 3; row++)
	//{
	//	if (board[row][0].value().compare("X") && board[row][1].value().compare("O") && board[row][2].value().compare("_") ||
	//		board[row][0].value().compare("O") && board[row][1].value().compare("X") && board[row][2].value().compare("_") ||
	//		board[row][0].value().compare("_") && board[row][1].value().compare("X") && board[row][2].value().compare("O") ||
	//		board[row][0].value().compare("_") && board[row][1].value().compare("O") && board[row][2].value().compare("X") ||
	//		board[row][0].value().compare("X") && board[row][1].value().compare("_") && board[row][2].value().compare("O") ||
	//		board[row][0].value().compare("O") && board[row][1].value().compare("_") && board[row][2].value().compare("X"))
	//		return +0;
	//}

	//for (int column = 0; column < 3; column++)
	//{
	//	if (board[0][column].value().compare("X") && board[1][column].value().compare("O") && board[2][column].value().compare("_") ||
	//		board[0][column].value().compare("O") && board[1][column].value().compare("X") && board[2][column].value().compare("_") ||
	//		board[0][column].value().compare("_") && board[1][column].value().compare("X") && board[2][column].value().compare("O") ||
	//		board[0][column].value().compare("_") && board[1][column].value().compare("O") && board[2][column].value().compare("X") ||
	//		board[0][column].value().compare("X") && board[1][column].value().compare("_") && board[2][column].value().compare("O") ||
	//		board[0][column].value().compare("O") && board[1][column].value().compare("_") && board[2][column].value().compare("X"))
	//		return +0;
	//}

	//// X O _ : 0 || O X _ || X _ O || O _ X || _ O X || _ X O
	//if (board[0][0].value().compare("X") && board[1][1].value().compare("O") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("O") && board[1][1].value().compare("X") && board[2][2].value().compare("_") ||
	//	board[0][0].value().compare("X") && board[1][1].value().compare("_") && board[2][2].value().compare("O") ||
	//	board[0][0].value().compare("O") && board[1][1].value().compare("_") && board[2][2].value().compare("X") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("O") && board[2][2].value().compare("X") ||
	//	board[0][0].value().compare("_") && board[1][1].value().compare("X") && board[2][2].value().compare("O"))
	//	return +0;


	//if (board[0][2].value().compare("X") && board[1][1].value().compare("O") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("O") && board[1][1].value().compare("X") && board[2][0].value().compare("_") ||
	//	board[0][2].value().compare("X") && board[1][1].value().compare("_") && board[2][0].value().compare("O") ||
	//	board[0][2].value().compare("O") && board[1][1].value().compare("_") && board[2][0].value().compare("X") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("O") && board[2][0].value().compare("X") ||
	//	board[0][2].value().compare("_") && board[1][1].value().compare("X") && board[2][0].value().compare("O"))
	//	return +0;

	return 0;
}
