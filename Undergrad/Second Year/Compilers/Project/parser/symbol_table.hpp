#pragma once

#include <unordered_map>

#include "symbol.hpp"

namespace parser
{
	class symbol_table
	{
	public:
		explicit symbol_table();
		
	private:
		std::unordered_map<std::string, parser::symbol> table_;
	};
}