#pragma once

#include <string>

// Namespace ofera o posibilitate de a desena in terminal folosind cursorul
namespace terminal
{
	// Toate comenzile folosite sunt special escape_sequences care incep cu caracterul \033
	// Codurile escape de aici: http://www.termsys.demon.co.uk/vtansi.htm

	constexpr char escape_code = '\033';

	// Culorile textului
	enum class color
	{
		reset, red, green, yellow, blue, magenta, cyan, white
	};

	// Functii pentru a muta cursorul
	namespace cursor
	{
		// Muta cursorul la inceputul liniei
		void to_line_start();

		// Muta cursorul la top stanga terminalului
		void to_home();

		// Muta cursorul la dreapta 'amount' locuri
		void forward(int amount = 1);

		// Muta cursorul la stanga 'amount' locuri
		void backward(int amount = 1);

		// Muta cursorul in sus o linie 
		void up(int amount = 1);

		// Muta cursorul mai jos o linie
		void down(int amount = 1);

		// Muta cursorul la linia urmatoare ( \n )
		void next_line();

		// Seteaza cursorul la coordonatele date (x, y)
		void set(int x, int y);

		// Salveaza pozitia curenta a cursorului pentru a il folosi mai tarziu 
		void save();

		// Restabileste locatia cursorului la pozitia salvata anterior
		void restore();
	}
	
	// Sterge linia curenta pe care este cursorul
	void erase_line();

	// Sterge inceputul liniei de la cursorul curent 
	void erase_to_start();
	
	// Sterge sfarsitul liniei de la cursorul curent
	void erase_to_end();

	// Curata terminalul
	void clear();

	// Reseteaza terminalul
	void reset();

	// Seteaza culoarea la cursor
	void set_color(terminal::color);

	std::string format_color(const std::string& text, terminal::color);
}
