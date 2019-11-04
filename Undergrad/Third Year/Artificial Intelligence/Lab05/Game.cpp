#include "Game.h"

#include <iostream>
#include <memory>

#include "Human.h"
#include "BetterComputer.h"

static std::string playerTurnStatus(const Player& player)
{
	return "[+] " + player.name() + " player's turn:";
}

Game::Game()
	: activePlayer_(new Human("Human", "O"))
	//activePlayer_ = new Computer("Ai2", "O");
	//activePlayer_ = new Computer("Ai2", "O");
	//, inactivePlayer_(new Computer("Ai", "X"))
	, inactivePlayer_(new BetterComputer("Ai", "X"))
	, running_(false)
{
	turnStatus_ = playerTurnStatus(*activePlayer_);
}

bool Game::won() const
{
	return !running_;
}

Board Game::board() const
{
	return board_;
}

const Player& Game::activePlayer() const
{
	return *activePlayer_;
}

const Player& Game::inactivePlayer() const
{
	return *inactivePlayer_;
}

const Player& Game::otherPlayer(const Player& player) const
{
	if (player == this->activePlayer())
		return this->inactivePlayer();

	return this->activePlayer();
}


bool Game::checkColumns(const Board& board, std::string mark)
{
	// 3 active_player Marks on Columns
	for (int j = 0; j < board.size(); j++)
	{
		if (mark == board(0, j).mark() &&
			mark == board(1, j).mark() &&
			mark == board(2, j).mark())
			return true;
	}

	return false;
}

bool Game::checkRows(const Board& board, std::string mark)
{
	// 3 active_player Marks on Rows
	for (int i = 0; i < board.size(); i++)
	{
		if (mark == board(i, 0).mark() &&
			mark == board(i, 1).mark() &&
			mark == board(i, 2).mark())
			return true;
	}

	return false;
}

bool Game::checkDiagonals(const Board& board, std::string mark)
{
	// 3 active_player Marks on Diagonals
	if (mark == board(0, 0).mark() &&
		mark == board(1, 1).mark() &&
		mark == board(2, 2).mark())
		return true;

	if (mark == board(0, 2).mark() &&
		mark == board(1, 1).mark() &&
		mark == board(2, 0).mark())
		return true;

	return false;
}

// Final State Validation 
// X won/ O won/ Tie
bool Game::checkWin(const Board& board, std::string mark)
{
	return Game::checkRows(board, mark) || Game::checkColumns(board, mark) || Game::checkDiagonals(board, mark);
}

bool Game::checkTie(const Board& board)
{
	return board.numEmptyCells() == 0 && !Game::checkWin(board, "X");
}

void Game::handleWinState()
{
	if (Game::checkWin(board_, activePlayer_->mark()))
	{
		this->setStatus(activePlayer_->name() + " wins!");
		this->draw();
		running_ = false;
		return;
	}

	if (Game::checkTie(board_))
	{
		this->setStatus("Tie");
		this->draw();
		running_ = false;
	}
}

void Game::start()
{
	running_ = true;

	while (!this->won())
	{
		this->draw();					// draw the game

		activePlayer_->playTurn(*this); // player goes

		this->handleWinState();			// check to see if he won

		this->nextTurn();				// switch players
	}
}

void Game::quit()
{
	running_ = false;
}

bool Game::markCell(int row, int col, const Player& player)
{
	return board_.markCell(row, col, player);
}

void Game::setStatus(std::string status)
{
	otherStatus_ = status;
}

void Game::nextTurn()
{
	std::swap(activePlayer_, inactivePlayer_);
	turnStatus_ = playerTurnStatus(*activePlayer_);
	otherStatus_.clear();
}

void Game::draw()
{
	std::cout << std::endl;
	board_.draw();

	std::cout << std::endl;
	std::cout << turnStatus_ << '\n';

	if (!otherStatus_.empty())
		std::cout << otherStatus_ << '\n';

	std::cout << std::endl;
	std::cout << ">";
}
