#pragma once

#include "point.hpp"
#include "object.hpp"

namespace graphics
{
	// deseneaza punctul in terminal prin mutarea cursorului terminal
	// iar dupa scriem text in acel spot
	void draw(const graphics::point& point);
	void draw(const graphics::object& object);

	// apeleaza draw pe un object dat daca are .draw() functie
	template <class T>
	void draw(const T& x)
	{
		x.draw();
	}

	// scrie un spatiu la punctul dat pentru a sterge punctul
	void erase(const graphics::point& point, int amount = 1);
	void erase(const graphics::object& object);

	void update();
	void clear();
}
