#include "Structure.h"

Structure::Structure(std::string mark)
	: mark_(mark)
{}

std::string Structure::mark() const
{
	return mark_;
}

bool operator==(const Structure& lhs, const Structure& rhs)
{
	return lhs.mark() == rhs.mark();
}