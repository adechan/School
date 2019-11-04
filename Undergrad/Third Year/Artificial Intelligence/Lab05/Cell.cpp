#include "Cell.h"
#include "Player.h"

Cell::Cell(int row, int column, std::string mark, const Player& player)
	: row_(row), column_(column)
	, mark_(mark)
	, owner_(&player)
{}

Cell::Cell(int row, int col)
	: row_(row), column_(col)
	, mark_("_")
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
	return (mark_ == "_") && !this->hasOwner();
}

const Player& Cell::player() const
{
	return *owner_;
}

std::string Cell::mark() const
{
	return mark_;
}

void Cell::setMark(std::string mark)
{
	mark_ = mark;
}

bool operator==(Cell lhs, Cell rhs)
{
	return lhs.mark() == rhs.mark();
}

bool operator!=(Cell lhs, Cell rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& stream, Cell cell)
{
	stream << cell.mark();
	return stream;
}