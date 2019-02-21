#pragma once

#include <string>

namespace lexer
{
	template <class T>
	T to_(const std::string& text)
	{
		return T(text);
	}
	
	template <>
	inline int to_<int>(const std::string& text)
	{
		return std::stoi(text.c_str());
	}
	
	template <>
	inline char to_<char>(const std::string& text)
	{
		return text[0];
	}
	
	template <>
	inline float to_<float>(const std::string& text)
	{
		return std::stof(text.c_str());
	}
	
	template <class T>
	std::string to_string(T t)
	{
		return std::to_string(t);
	}
	
	template <>
	inline std::string to_string<std::string>(std::string string)
	{ return string; }
	
	template <>
	inline std::string to_string<const char*>(const char* string)
	{ return std::string(string); }
	
	template <>
	inline std::string to_string<char>(char c)
	{ std::string temp = " "; temp[0] = c; return temp; }
}