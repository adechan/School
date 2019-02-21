#include "terminal.hpp"

#include <iostream>

namespace terminal
{
	namespace cursor
	{
		// inceputul liniei
		void to_line_start()
		{
			cursor::backward(1000);
		}

		// top stanga
		void to_home()
		{
			std::cout << escape_code << "[H";
		}

		// dreapta 'amount' locuri
		void forward(int amount)
		{
			std::cout << escape_code << '[' << amount << 'C';
		}

		// tanga 'amount' locuri
		void backward(int amount)
		{
			std::cout << escape_code << '[' << amount << 'D';
		}

		// in sus o linie 
		void up(int amount)
		{
			std::cout << escape_code << '[' << amount << 'A';
		}

		// in jos o linie 
		void down(int amount)
		{
			std::cout << escape_code << '[' << amount << 'B';
		}

		// linia urmatoare
		void next_line()
		{
			std::cout << '\n';
		}

		// la coordonatele date (x, y)
		void set(int x, int y)
		{
			std::cout << escape_code << '[' << y << ';' << x << 'f';
		}


		void save()
		{
			std::cout << escape_code << "[s";
		}

		void restore()
		{
			std::cout << escape_code << "8";
		}
	}

	void erase_line()
	{
		std::cout << escape_code << "[2K";
	}

	void erase_to_start()
	{
		std::cout << escape_code << "[1K";
	}

	void erase_to_end()
	{
		std::cout << escape_code << "[K";
	}

	void clear()
	{
		std::cout << escape_code << "[2J";
		cursor::to_home();
	}

	void reset()
	{
		std::cout << escape_code << "c";
	}

	static std::string to_escape_sequence(terminal::color color)
	{
		switch (color)
		{	// culori
			case color::reset:	return "\033[0m";
			case color::red:	return "\033[31m";
			case color::green:	return "\033[32m";
			case color::yellow: 	return "\033[33m";
			case color::blue:	return "\033[34m";
			case color::magenta:	return "\033[35m";
			case color::cyan:	return "\033[36m";
			case color::white:	return "\033[37m";
		}

		return "";
	}

	void set_color(terminal::color color)
	{
		std::cout << to_escape_sequence(color);
	}

	std::string format_color(const std::string& text, terminal::color color)
	{
		return to_escape_sequence(color) + text + to_escape_sequence(color::reset);
	}

}
