#pragma once

#include <string>

#include "../../terminal.hpp"

namespace connect4
{
	enum class color
	{
		yellow, red
	};

	struct player
	{
		std::string name;
		connect4::color color;
	};


	terminal::color to_terminal_color(connect4::color color);
}
