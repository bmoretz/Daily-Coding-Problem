#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include <map>

/* Longest Substring Without Repeating Characters.
 
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
			 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

struct Solution
{
	/// <summary>
	/// length of longest substring, sliding window
	/// </summary>
	/// <param name="str">input string</param>
	/// <complexity>
	///		<run-time>O(n)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <returns>length of the longest substring.</returns>
	static int lengthOfLongestSubstring2( const std::string& str )
	{
		auto n = str.length();

		std::set<char> seen;

		auto longest = 0UL, start = 0UL, stop = 0UL;

		while( start < n && stop < n )
		{
			if( seen.find( str.at( stop ) ) == std::end( seen ) )
			{
				seen.insert( str.at( stop++ ) );
				longest = std::max( longest, stop - start );
			}
			else
			{
				seen.erase( str.at( start++ ) );
			}
		}

		return longest;
	}

	/// <summary>
	/// length of longest substring, brute force approach
	/// </summary>
	/// <complexity>
	///		<run-time>O(n^2)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="str">input string</param>
	/// <returns>length of the longest substring.</returns>
	static int lengthOfLongestSubstring1( const std::string& str )
	{
		if( str.length() == 1 ) return 1;
		
		auto longest = 0ULL;

		for( auto start = 0UL; start < str.length() - 1; ++start )
		{
			for( auto stop = start + 1; stop < str.length(); ++stop )
			{
				const auto sub = str.substr( start, stop );
				const auto unique = std::set<char>( std::begin( sub ), std::end( sub ) );
				
				if( sub.length() == unique.size() )
				{
					longest = std::max( longest, sub.length() ) ;
				}
			}
		}

		return longest;
	}
};

auto main() -> int
{
	const auto s1 = "ccabcdef";
	const auto s2 = "a";
	const auto s3 = "ababcbac";
	const auto s4 = "pwwkew";
	const auto s5 = "ohomm";
	const auto s6 = "asjrgapa";
	
	const auto result = Solution::lengthOfLongestSubstring2( s1 );

	std::cout << "Result: " << result;
	
	return 0;
}
