#pragma once
#include "Masina.h"

class SUV : public Masina
{
private:

public:
	SUV();
	virtual int getConsum() const = 0;
	std::string getName() const override;
};