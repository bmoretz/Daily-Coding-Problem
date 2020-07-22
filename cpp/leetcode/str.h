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
}