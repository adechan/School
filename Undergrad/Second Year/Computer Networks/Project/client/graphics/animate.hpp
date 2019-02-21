#pragma once

#include "point.hpp"
#include "../../terminal.hpp"

#include <chrono>

namespace graphics
{
	// deseneaza incepand cu p1 si muta p1 pana cand intalneste p2 in 'ms' milisecunde
	// (linear interpolate)
	void lerp(const graphics::point& p1, const graphics::point& p2, std::chrono::milliseconds ms);

}
