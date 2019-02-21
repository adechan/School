#pragma once

#include "../graphics/screen.hpp"
#include "../graphics/object.hpp"
#include "../graphics/draw.hpp"
#include "disc_stack.hpp"

#include <vector>

namespace connect4
{
	class board
	{
	public:
		explicit board();

		// Pune discul intr-un stack dat
		void place_disc(int stack, connect4::color color = connect4::color::yellow);
		bool check_disc_place(int stack);
		
		void player_turn();
		std::string player_input();

		// seteaza status mesaj pe tabla
		void set_status(const std::string& message);

		// seteaza mesaj pentru debugging
		void debug_message(const std::string& message);

		// deseneaza tabla
		void draw() const;

		static constexpr int width = 7;
		static constexpr int height = 6;

	private:
		// fiecare coloana de discuri
		std::vector<disc_stack> stacks_;

		// status text desenat pe tabla pentru info despre joc
		graphics::object status_text_;
		graphics::object input_text_;
		graphics::object debug_text_;
	};
}
