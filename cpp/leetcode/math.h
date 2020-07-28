#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace leetcode::math
{
	/* Minimum Moves to Equal Array Elements II.

	Given a non-empty integer array, find the minimum number of moves required to make all array elements equal,
	where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

	You may assume the array's length is at most 10,000.

	Example:

	Input: [1,2,3]
	Output: 2

	Explanation:
	Only two moves are needed (remember each move increments or decrements one element):

	[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
	*/

	struct min_moves
	{
		/// <summary>
		/// min moves
		/// </summary>
		/// <complexity>
		///		<run-time>O(n log n)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="numbers"></param>
		/// <returns>the minimum number of moves to make all the array elements equal</returns>
		static int min_moves2( std::vector<int>& numbers )
		{
			auto result = 0;

			if( !numbers.empty() )
			{
				std::sort( std::begin( numbers ), std::end( numbers ) );

				const auto mid = numbers.at( ( numbers.size() - 1 ) / 2 );

				for( auto num : numbers )
				{
					result += std::abs( mid - num );
				}
			}

			return result;
		}
	};

	/* 1513. Number of Substrings With Only 1s.

	Given a binary string s (a string consisting only of '0' and '1's).
	Return the number of substrings with all characters 1's.

	Since the answer may be too large, return it modulo 10^9 + 7.

	Example 1:

	Input: s = "0110111"
	Output: 9
	Explanation: There are 9 substring in total with only 1's characters.

	"1" -> 5 times.
	"11" -> 3 times.
	"111" -> 1 time.

	Example 2:

	Input: s = "101"
	Output: 2
	Explanation: Substring "1" is shown 2 times in s.

	Example 3:

	Input: s = "111111"
	Output: 21
	Explanation: Each substring contains only 1's characters.
	Example 4:

	Input: s = "000"
	Output: 0
	*/

	struct number_of_1s_substrings
	{
		static std::unordered_map<std::size_t, std::size_t> get_ones_counts( const std::string& input )
		{
			std::unordered_map<std::size_t, std::size_t> groups;

			auto current_len = std::size_t();

			for( auto chr : input )
			{
				if( chr == '1' )
				{
					++current_len;
				}
				else if( current_len > 0 )
				{
					groups[ current_len ]++;
					current_len = std::size_t();
				}
			}

			if( current_len > 0 )
				groups[ current_len ]++;

			return groups;
		}

		/// <summary>
		/// number of subgroups
		/// </summary>
		/// <param name="str">input string</param>
		/// <returns>number of ways to choose subgroups of 1's</returns>
		static int number_of_subgroups( const std::string& str )
		{
			auto group_counts = get_ones_counts( str );
			auto perms = 0;
			const unsigned long long mod_op = std::pow( 10, 9 ) + 7;

			for( const auto& group : group_counts )
			{
				const auto intermediate = group.second * ( group.first * ( group.first + 1 ) / 2 );
				perms = ( static_cast< std::size_t >( perms ) + intermediate ) % mod_op;
			}

			return perms;
		}
	};
}
