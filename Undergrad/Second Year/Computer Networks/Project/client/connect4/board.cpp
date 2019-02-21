#include "board.hpp"

#include "../graphics/screen.hpp"
#include "../graphics/draw.hpp"
#include "../../terminal.hpp"

#include <iostream>
#include <chrono>
#include <thread>

namespace connect4
{
	board::board()
	{
		// pune coloane pe tabla
		for (int i = 1; i <= board::width; ++i)
			stacks_.push_back(disc_stack(graphics::screen::origin_x + 4 * i - 3 , board::height));

		// creaza status text object
		status_text_.push_back({
			graphics::screen::origin_x, graphics::screen::origin_y + board::height + 1, "[*]:"
		});

		// creaza input text object
		input_text_.push_back({
			graphics::screen::origin_x, graphics::screen::origin_y + board::height + 2, "Column: "
		});

		// creaza debug text object
		debug_text_.push_back({
			graphics::screen::origin_x, graphics::screen::origin_y + board::height + 3, ""
		});

		// clear the terminal pentru a desena
		terminal::clear();

		// seteaza cursorul la inputul text ( "column: _")
		terminal::cursor::set(input_text_[0].x + input_text_[0].value.size(), input_text_[0].y);

		// salveaza cursorul pentru ca pozitia sa fie restaurata dupa fiecare apel ::draw
		terminal::cursor::save();
		graphics::draw(*this);

		// update grafica
		graphics::update();
	}

	void board::set_status(const std::string& message)
	{
		// muta cursorul unde textul ar trebui sa fie
		terminal::cursor::set(status_text_[0].x, status_text_[0].y);

		// sterge textul anterior
		terminal::erase_line();

		// seteaza textul cu formatted color
		status_text_[0].value = std::string("[") + terminal::format_color("*", terminal::color::cyan) + "]: " + message;

		// deseneaza si updateaza
		graphics::draw(status_text_);
		graphics::update();
	};

	void board::debug_message(const std::string& message)
	{
		//return;
		terminal::cursor::set(debug_text_[0].x, debug_text_[0].y);
		terminal::erase_line();

		debug_text_[0].value = message;
		graphics::draw(debug_text_);
		graphics::update();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	std::string board::player_input()
	{
		// muta cursorul la sfarsitul inputului 
		terminal::cursor::set(input_text_[0].x + input_text_[0].value.size(), input_text_[0].y);

		std::string text;

		// get user input
		std::cin >> text;

		// muta cursorul inapoi la input position, si apoi sterge linia
		terminal::cursor::set(input_text_[0].x + input_text_[0].value.size(), input_text_[0].y);
		terminal::erase_line();

		// deseneaza text object
		graphics::draw(input_text_);
		return text;
	}

	// deseneaza toate objects pe tabla
	void board::draw() const
	{
		for (const auto& stack : stacks_)
			graphics::draw(stack);

		graphics::draw(input_text_);
		graphics::draw(status_text_);
	}

	void board::place_disc(int stack, connect4::color color)
	{
		stacks_[stack - 1].place_disc(color);
	}
	
	bool board::check_disc_place(int stack)
	{
		// pentru a plasa in interiorul tablei
		return (1 <= stack && stack < board::width)
			&& (stacks_[stack - 1].size() < board::height);
	}
}
