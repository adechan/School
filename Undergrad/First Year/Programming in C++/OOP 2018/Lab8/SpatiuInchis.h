#pragma once

class SpatiuInchis
{
private:

public:
	SpatiuInchis();
	// virtual AddSpatiu not const because 
	// im modifying the atributes in Camera
	virtual void AddSpatiu(SpatiuInchis*) = 0;
	virtual void PrintInfo() const = 0;
};