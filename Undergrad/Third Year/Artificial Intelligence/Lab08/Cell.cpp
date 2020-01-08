#include "Cell.h"
#include "Structure.h"

Cell::Cell(int row, int column, std::string mark, bool block, const Structure& structure)
	: row_(row)
	, column_(column)
	, mark_(mark)
	, owner_(&structure)
{}

Cell::Cell(int row, int col, bool block)
	: row_(row), column_(col)
	, mark_(".")
	, block_(block)
	, owner_(nullptr)
{}

Cell::Cell()
	: Cell(0, 0)
{}


int Cell::row() const
{
	return row_;
}

int Cell::column() const
{
	return column_;
}

bool Cell::hasOwner() const
{
	return owner_ != nullptr;
}

bool Cell::isEmpty() const
{
	return (mark_ == ".") && !this->hasOwner();
}