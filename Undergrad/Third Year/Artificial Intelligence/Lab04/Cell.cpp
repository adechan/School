#include "Cell.h"
#include "Player.h"

Cell::Cell(std::string mark, const Player& player)
	: mark_(mark)
	, owner_(&player)
{}

Cell::Cell()
	: mark_("_")
	, owner_(nullptr)
{}

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