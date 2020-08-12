#pragma once

#include <memory>
#include <string>
#include <stack>

namespace leetcode::stack
{
	/* 678. Valid Parenthesis String.

	Given a string containing only three types of characters: '(', ')' and '*', write a function to check
	whether this string is valid. We define the validity of a string by these rules:

	Any left parenthesis '(' must have a corresponding right parenthesis ')'.
	Any right parenthesis ')' must have a corresponding left parenthesis '('.
	Left parenthesis '(' must go before the corresponding right parenthesis ')'.
	'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.

	An empty string is also valid.

	Example 1:
	Input: "()"
	Output: True

	Example 2:
	Input: "(*)"
	Output: True

	Example 3:
	Input: "(*))"
	Output: True
	Note:

	The string size will be in the range [1, 100].
	*/

	struct valid_parenthesis
	{
		static bool check_valid_string( const std::string& input )
		{
			if( input.empty() ) return true;

			auto parens = std::stack<char>();
			auto wildcards = 0;

			for( auto chr : input )
			{
				if( chr == '(' )
				{
					parens.push( chr );
				}
				else if( chr == ')' )
				{
					if( !parens.empty() )
					{
						parens.pop();
					}
					else if( wildcards > 0 )
					{
						wildcards--;
					}
					else
					{
						return false;
					}
				}
				else
				{
					wildcards++;

					if( !parens.empty() )
					{
						parens.pop();
						wildcards++;
					}
				}
			}

			return parens.empty();
		}
	};

	/* 227. Basic Calculator II.

	Implement a basic calculator to evaluate a simple expression string.

	The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

	Example 1:

	Input: "3+2*2"
	Output: 7
	Example 2:

	Input: " 3/2 "
	Output: 1
	Example 3:

	Input: " 3+5 / 2 "
	Output: 5
	Note:

	You may assume that the given expression is always valid.
	Do not use the eval built-in library function.

	*/

	class basic_calculator_ii
	{
	public:

		/// <summary>
		/// calculates the numeric value of the passed in mathematical string expression.
		/// </summary>
		/// <param name="expr">the expression to evaluate</param>
		/// <returns>numerical value of the evaluated expression</returns>
		static int calculate( const std::string& expr )
		{
			if( expr.empty() ) return 0;

			auto ops = std::stack<int>();
			auto pos = std::size_t();

			ops.push( parse_next_operand( expr, pos ) );

			while( pos < expr.size() )
			{
				const auto op = parse_next_op( expr, pos );

				switch( op )
				{

				case '+':
				case '-':
				{
					ops.push( parse_next_operand( expr, pos ) );
				} break;

				case '*':
				case '/':
				{
					const auto left = ops.top();
					ops.pop();
					const auto right = parse_next_operand( expr, pos );

					ops.push( op == '*' ? left * right : left / right );
				} break;

				default:break;
				}
			}

			auto result = 0;

			while( !ops.empty() )
			{
				result += ops.top();
				ops.pop();
			}

			return result;
		}

		/// <summary>
		/// trim spaces
		///
		/// advances the location pointer while we have a space.
		/// </summary>
		/// <param name="input">expression to evaluate</param>
		/// <param name="pos">current location</param>
		static void trim_space( const std::string& input, std::size_t& pos )
		{
			while( std::isspace( input[ pos ] ) )
				pos++;
		}

		/// <summary>
		/// parses the next operand
		/// </summary>
		/// <param name="input">the expression to evaluate</param>
		/// <param name="pos">current position</param>
		/// <returns>operand</returns>
		static int parse_next_operand( const std::string& input, std::size_t& pos )
		{
			trim_space( input, pos );

			std::string result;

			auto sign = 1;

			if( input.at( pos ) == '-' )
			{
				sign = -1;
				++pos;
			}

			trim_space( input, pos );

			while( std::isdigit( input[ pos ] ) )
			{
				result += input[ pos++ ];
			}

			return std::stoi( result ) * sign;
		}

		/// <summary>
		/// parse the next operator
		///
		/// read the next operator and increments the position place holder unless it's
		/// subtraction, then we just return the op and the current index so the number
		/// parser routine picks up the negative in the number.
		/// </summary>
		/// <param name="input">the expression</param>
		/// <param name="pos">current index to evaluate</param>
		/// <returns>the operand to execute</returns>
		static char parse_next_op( const std::string& input, std::size_t& pos )
		{
			trim_space( input, pos );

			return pos == input.size() ? ' ' :
				input.at( pos ) == '-' ?
				input.at( pos ) : input.at( pos++ );
		}
	};
}
