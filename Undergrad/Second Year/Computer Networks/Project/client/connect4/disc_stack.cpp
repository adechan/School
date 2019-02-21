#include "disc_stack.hpp"

#include "../../terminal.hpp"
#include "../graphics/draw.hpp"
#include "../graphics/animate.hpp"

namespace connect4
{
	disc_stack::disc_stack(int x, int height)
		: height_(height)
		, x_(x)
	{
		// coloana text = "|"
		// extinde coloana in jos
		const std::string value = terminal::format_color("|", terminal::color::green);

		for (int y = 1; y <= height; ++y)
			graphics_data_.push_back({x, y, value });
	}

	void disc_stack::place_disc(connect4::color color)
	{
		// cream un disc nou la topul disc stack curent
		// x_ + 2 = spatiul dintre coloane "| O |"
		connect4::disc disc(x_ + 2, height_ - stack_.size(), color);
		stack_.push(disc);

		// incepe sa cada la inceputul tablei
		graphics::point source = { disc.point().x, 1, disc.point().value };

		// muta discul in jos pana cand loveste top of the stack
		graphics::lerp(source, disc.point(), std::chrono::milliseconds(500));
	}

	void disc_stack::clear()
	{
		while (!stack_.empty())
			stack_.pop();
	}

	void disc_stack::draw() const
	{
		std::stack<connect4::disc> copy = stack_;

		graphics::draw(graphics_data_);
		while (!copy.empty())
		{
			graphics::draw(copy.top());
			copy.pop();
		}
	}

		
	int disc_stack::size() const
	{
		return stack_.size();
	}
}
