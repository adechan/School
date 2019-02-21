#include "draw.hpp"
#include "screen.hpp"

#include "../../terminal.hpp"

#include <iostream>
#include <vector>

namespace graphics
{
	void draw(const graphics::point& point)
	{
		// seteeaza cursorul terminal la coordonatele punctului si apoi scrie valoarea sa
		terminal::cursor::set(point.x, point.y);
		std::cout << point.value;

		// dupa, restabileste cursorul unde a fost inainte de desenare
		terminal::cursor::restore();
	}

	void draw(const graphics::object& object)
	{
		// deseneaza fiecare punct in graphics object
		for (const auto& point : object)
			draw(point);
	}

	void erase(const graphics::point& point, int amount)
	{
		// seteaza cursorul terminal la coordonatele punctului si apoi sterge valoarea sa
		terminal::cursor::set(point.x, point.y);

		for (int i = 0; i < amount; ++i)
			std::cout << ' ';

		// dupa, restabileste cursorul unde a fost inainte de desenare
		terminal::cursor::restore();
	}

	void erase(const graphics::object& object)
	{
		// sterge fiecare punct din graphics object
		for (const auto& point : object)
			erase(point);
	}

	void update()
	{
		// data este scrisa in terminal imediat
		std::cout.flush();
	}

	void clear()
	{
		// sterge textul din terminal
		terminal::clear();
	}
}
