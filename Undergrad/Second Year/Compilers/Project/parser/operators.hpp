#pragma once

namespace parser 
{ 
	namespace binary_operators 
	{
		template <class Result, class Left, class Right>
		Result add(Left left, Right right)
		{
			return static_cast<Result>(left + right);
		}

		template <class Result, class Left, class Right>
		Result subtract(Left left, Right right)
		{
			return static_cast<Result>(left - right);
		}

		template <class Result, class Left, class Right>
		Result multiply(Left left, Right right)
		{
			return static_cast<Result>(left * right);
		}

		template <class Result, class Left, class Right>
		Result divide(Left left, Right right)
		{
			return static_cast<Result>(left / right);
		}

		template <class Result, class Left, class Right>
		Result boolean_and(Left left, Right right)
		{
			return static_cast<Result>(left && right);
		}

		template <class Result, class Left, class Right>
		Result boolean_or(Left left, Right right)
		{
			return static_cast<Result>(left || right);
		}

	}

	namespace unary_operators
	{
	}
}