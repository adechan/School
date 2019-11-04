#include "BetterComputer.h"
#include <array>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>

#include "Computer.h"
#include "Game.h"
#include "Board.h"

BetterComputer::BetterComputer(std::string name, std::string mark)
	: Player(name, mark)
{}

void BetterComputer::playTurn(Game& game) const
{
	// Minimax : find the best move
	// game, state, BetterComputer object = AI
	const auto bestMove = this->minimax(game, game.board(), *this);

	// mark our cell 
	game.markCell(bestMove.row, bestMove.col, *this);
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


// Simulate playing the game for a few moves to anaylze our best
// options
BetterComputer::move 
	BetterComputer::minimax(Game& game, const Board& nodeBoard, const Player& player, int currentDepth) const
{
	if (nodeBoard.isFull() || currentDepth >= 6)
		return {Computer::evaluateBoard(nodeBoard, player.mark()), 0, 0};

	BetterComputer::move bestMove;

	// we are the maximizer
	if (player == *this)
	{
		// set the "best" score to be the worst 
		// -infty
		bestMove.score = std::numeric_limits<int>::min();

		// Find all cells that we can move to
		for (const Cell& cell : nodeBoard.cells())
		{
			if (!cell.isEmpty())
				continue; // skip

			// Switch players
			const Player& nextPlayer = game.otherPlayer(player);

			// Consider what would happen if the player marked
			// the current cell
			// Simulate playing the game for one turn
			Board nextBoard = nodeBoard.newBoardWithMark(cell.row(), cell.column(), nextPlayer);

			// Find the best move for this new board
			const auto minimaxMove = minimax(game, nextBoard, nextPlayer, currentDepth + 1);
			
			// See if it's better than what we have so far
			if (minimaxMove.score >= bestMove.score)
			{
				bestMove = minimaxMove;
				bestMove.row = cell.row();
				bestMove.col = cell.column();
			}
		}
	}
	else // 
	{
		bestMove.score = std::numeric_limits<int>::max();
		for (const Cell& cell : nodeBoard.cells())
		{
			if (!cell.isEmpty())
				continue; // skip

			const Player& nextPlayer = game.otherPlayer(player);
			Board nextBoard = nodeBoard.newBoardWithMark(cell.row(), cell.column(), nextPlayer);

			const auto minimaxMove = minimax(game, nextBoard, nextPlayer, currentDepth + 1);

			// Take the worst score
			if (minimaxMove.score <= bestMove.score)
			{
				bestMove = minimaxMove;
				bestMove.row = cell.row();
				bestMove.col = cell.column();
			}
		}
	}

	return bestMove;
	// it ends up returning the first move
	// because we pass the current best move to the previous 
	// minimax call, then that stack frame returns their best move, and so on
} // go to the previous move