#include <bits/stdc++.h>

/* Length of Last Word.
 
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of
last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5

*/

struct Solution
{
	static std::size_t rtrim( std::string& str )
	{
		auto trimmed = std::size_t();

		for( auto index = str.length();
			index > 0 && str.at( index - 1 ) == ' '; --index, ++trimmed )
		{
			str.erase( index - 1 );
		}

		return trimmed;
	}
	
	std::size_t lengthOfLastWord( std::string& str )
	{
		if( str.empty() ) return 0;

		const auto len = str.length();
		const auto trimmed = rtrim( str );
		const auto last_space = str.rfind( ' ' );

		return len - trimmed - last_space - 1;
	}
};

auto main() -> int
{
	Solution sln;

	std::string input1 = "Hello World";
	std::string input2 = "NoWords";
	std::string input3 = "this has many words";
	std::string input4 = "            many        spaces              ";
	std::string input5 = "    noprefix";
	std::string input6 = " fda fdsafdsa  FDSAfFDS ";
	
	const auto result = sln.lengthOfLastWord( input4 );

	std::cout << "Result: " << result;
	
	return 0;
}
