#include "animate.hpp"
#include "draw.hpp"

#include <thread>
#include <iostream>

namespace graphics
{
	void lerp(const graphics::point& p1, const graphics::point& p2, std::chrono::milliseconds ms)
	{
		using std::chrono::milliseconds;
		using std::this_thread::sleep_for;

		auto elapsed = milliseconds(0);

		// cat de mult timp va trece pentru fiecare loop
		const auto time_step = milliseconds(100);

		float t = 0;
		graphics::point mid = p1;

		// cat timp inca exista timp pentru a muta
		while (elapsed <= ms)
		{
			// t = cat de departe (0 la 1) intre p1 si p2 este 'mid'
			t = (static_cast<float>(elapsed.count()) / static_cast<float>(ms.count()));

			// stergem vechiul desen
			graphics::erase(mid);
			// muta p1 catre p2 de 't' ori
			mid.x = p1.x + t * (p2.x - p1.x);
			mid.y = p1.y + t * (p2.y - p1.y);

			// deseneaza noua versiune de mid
			graphics::draw(mid);

			// sleep pentru a simula trecerea timpului
			sleep_for(time_step);
			elapsed += time_step;


			// update ecranul
			graphics::update();
		}
	}
}
