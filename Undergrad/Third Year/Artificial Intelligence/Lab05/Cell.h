#pragma once
#include <string>
#include <iostream>

class Player;

// Represents a cell in the game
// Cell has a mark which is the "X" or "O" value.
// It also has an owner which allows us to keep track of who 
// placed the mark.
class Cell
{
protected:
	int row_, column_;
	std::string mark_;
	const Player* owner_;

public:
	Cell(int row, int column, std::string mark, const Player& player);
	Cell(int row, int column);
	Cell();
	// Todo: remove, for debugging
	//Cell() = delete;

public:
	int row() const;
	int column() const;

	bool hasOwner() const;
	bool isEmpty() const;

	const Player& player() const;

	std::string mark() const;
	void setMark(std::string value);
};

bool operator==(Cell lhs, Cell rhs);
bool operator!=(Cell lhs, Cell rhs);
std::ostream& operator<<(std::ostream& stream, Cell cell);