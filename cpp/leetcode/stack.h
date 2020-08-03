#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
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
}
