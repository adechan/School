#pragma once

#include "Player.h"

#include <string>

class Human : public Player
{
public:
	Human() {};
	explicit Human(std::string name, std::string mark);

public:
	void playTurn(Game& game) const override;
};
