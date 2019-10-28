#include "Player.h"

Player::Player(std::string name, std::string mark)
	: name_(name)
	, mark_(mark)
{}

std::string Player::name() const
{
	return name_;
}

std::string Player::mark() const
{
	return mark_;
}