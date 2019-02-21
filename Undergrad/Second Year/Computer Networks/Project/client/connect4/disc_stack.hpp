#pragma once

#include <stack>

#include "disc.hpp"
#include "../graphics/draw.hpp"

namespace connect4
{
	class disc_stack
	{
	public:
		disc_stack() = default;
		explicit disc_stack(int x, int height);

		// plaseaza discul in disc stack curent pentru culoarea data
		void place_disc(connect4::color color);

		// deseneaza disc stack curent
		void draw() const;

		void clear();
		
		int size() const;

	private:
		int x_, height_;

		// stack of discs
		std::stack<disc> stack_;
		graphics::object graphics_data_;
	};
}
