#include "player.hpp"

namespace connect4
{
	terminal::color to_terminal_color(connect4::color color)
	{
		switch (color)
		{
			case connect4::color::red:	return terminal::color::red;
			case connect4::color::yellow: return terminal::color::yellow;
		}

		return terminal::color::white;
	}
}