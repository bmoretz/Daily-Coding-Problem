#include <bits/stdc++.h>

/* 3. Longest Substring Without Repeating Characters.

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"

Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class longest_without_repeats
{
	static auto longest_forward_substring( const std::string& str )
	{
		std::set<char> seen;
		auto longest = 0UL, current = 0UL;

		for( auto it = str.begin(); it != str.end(); ++it )
		{
			if( seen.find( *it ) == std::end( seen ) )
			{
				seen.insert( *it );
				++current;
			}
			else
			{
				longest = std::max( longest, current );
				current = 1UL;
			}
		}

		return std::max( longest, current );
	}

	static auto longest_reverse_substring( const std::string& str )
	{
		std::set<char> seen;
		auto longest = 0UL, current = 0UL;

		for( auto it = str.rbegin(); it != str.rend(); ++it )
		{
			if( seen.find( *it ) == std::end( seen ) )
			{
				seen.insert( *it );
				++current;
			}
			else
			{
				longest = std::max( longest, current );
				current = 1UL;
			}
		}

		return std::max( longest, current );
	}

public:
	
	static int length_of_longest_substring( const std::string& str )
	{
		const auto fwd = longest_forward_substring( str );
		const auto rev = longest_reverse_substring( str );

		return std::max( fwd, rev );
	}
};

auto main() -> int
{
	const auto input1 = "abcabcbb";
    const auto actual = longest_without_repeats::length_of_longest_substring( input1 );
	
    const auto expected = 3;
	
	return 0;
}
