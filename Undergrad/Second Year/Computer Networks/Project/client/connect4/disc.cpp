#include "disc.hpp"

#include "../../terminal.hpp"
#include "../graphics/draw.hpp"

#include <string>
#include <iostream>

namespace connect4
{

	disc::disc(int x, int y, connect4::color color)
	{
		// coordonatele discului si textul colorat
		graphics_data_.push_back({
			x, y,
			terminal::format_color("O", to_terminal_color(color))
		});
	}

	graphics::point disc::point() const
	{
		return graphics_data_[0];
	}


	void disc::draw() const
	{
		// deseneaza discul
		graphics::draw(graphics_data_);
	}
}
