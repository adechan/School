#pragma once

#include "../graphics/object.hpp"

#include "player.hpp"

namespace connect4
{
	class disc
	{
	public:
		explicit disc(int x, int y, connect4::color color);

		// ia point data al discului
		graphics::point point() const;

		void draw() const;

	private:
		graphics::object graphics_data_;
	};
}
