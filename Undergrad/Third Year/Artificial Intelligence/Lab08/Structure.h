#pragma once
#include <string>

class Structure
{
protected:
	std::string mark_;

public:
	Structure();
	virtual ~Structure(){}

	explicit Structure(std::string mark);

	std::string mark() const;
};

bool operator==(const Structure& lhs, const Structure& rhs);