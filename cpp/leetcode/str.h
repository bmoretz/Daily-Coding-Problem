#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace leetcode::str
{
	struct len_longest_substring
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
		static int length_of_longest_substring2( const std::string& str )
		{
			const auto n = str.length();

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
		static int length_of_longest_substring1( const std::string& str )
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
						longest = std::max( longest, sub.length() );
					}
				}
			}

			return longest;
		}
	};

	/* Length of Last Word.

	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of
	last word (last word means the last appearing word if we loop from left to right) in the string.

	If the last word does not exist, return 0.

	Note: A word is defined as a maximal substring consisting of non-space characters only.

	Example:

	Input: "Hello World"
	Output: 5

	*/

	struct length_of_last_word
	{
		/// <summary>
		/// trims the trailing spaces from a given input and returns the number
		/// of characters trimmed.
		/// </summary>
		/// <param name="str"></param>
		/// <returns></returns>
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

		/// <summary>
		/// returns the length of the last word
		/// </summary>
		/// <complexity>
		///		<run-time>O(n)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="str">the input string</param>
		/// <returns>length of last word</returns>
		static std::size_t len_last_word( std::string& str )
		{
			if( str.empty() ) return 0;

			const auto len = str.length();
			const auto trimmed = rtrim( str );
			const auto last_space = str.rfind( ' ' );

			return len - trimmed - last_space - 1;
		}
	};
}