#pragma once
#include <iostream>
#include <string>

class Structure;

class Cell
{
protected:
	int row_, column_;
	std::string mark_;
	bool block_;
	const Structure* owner_;

public:
	Cell(int row, int column, std::string mark, bool block, const Structure& structure);
	Cell(int row, int column, bool block);
	Cell();

public:
	int row() const;
	int column() const;

	bool hasOwner() const;
	bool isEmpty() const;

	const Structure& Structure() const;
	std::string mark() const;
	void setMark(std::string value);
};

bool operator==(Cell lhs, Cell rhs);
bool operator!=(Cell lhs, Cell rhs);
std::ostream& operator<<(std::ostream& stream, Cell cell);
