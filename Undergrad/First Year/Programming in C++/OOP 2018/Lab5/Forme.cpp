#include "Forme.h"

Forme::Forme()
{

}


void Forme::Paint() const
{
	for (auto it = forms.begin(); it != forms.end(); it++)
	{
		auto& forma = *it;
		forma->Paint();
	}
}

void Forme::Add(Forma* form)
{
	forms.push_back(form);
}
