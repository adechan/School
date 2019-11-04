#pragma once

#include <string>

class Game;

// A player represents a player in the game.
// It has a name and a mark, which visually distinguishes the player.
class Player
{
protected: 
	std::string name_;
	std::string mark_;
	
public:
	Player() {}
	virtual ~Player() {}

	explicit Player(std::string name, std::string mark);

	virtual void playTurn(Game& game) const = 0;

	std::string name() const;
	std::string mark() const;
};

bool operator==(const Player& lhs, const Player& rhs);