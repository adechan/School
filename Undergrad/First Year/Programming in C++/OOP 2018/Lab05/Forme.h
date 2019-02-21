#pragma once
#include "Forma.h"
#include <vector>

class Forme : public Forma
{
private:
	
public:
	std::vector<Forma*> forms;
	Forme();
	void Paint() const override;
	void Add(Forma* form);
};