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

	/* 509. Fibonacci Number

	The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is
	the sum of the two preceding ones, starting from 0 and 1. That is,

	F(0) = 0,   F(1) = 1
	F(N) = F(N - 1) + F(N - 2), for N > 1.
	Given N, calculate F(N).

	Example 1:

	Input: 2
	Output: 1
	Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

	Example 2:

	Input: 3
	Output: 2
	Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

	Example 3:

	Input: 4
	Output: 3
	Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
	*/

	struct fibonacci_number
	{
		static int fib1( const int n )
		{
			std::unordered_map<unsigned long, unsigned long> lookup{ { 0, 0 }, { 1, 1 } };

			return fib( n, lookup );
		}

		static int fib( const int n, std::unordered_map<unsigned long, unsigned long>& lookup )
		{
			if( lookup.find( n ) == lookup.end() )
			{
				lookup[ n ] = fib( n - 1, lookup ) + fib( n - 2, lookup );
			}

			return lookup[ n ];
		}
	};

	/* 754. Reach a Number.

	You are standing at position 0 on an infinite number line. There is a goal at position target.

	On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

	Return the minimum number of steps required to reach the destination.

	Example 1:
	Input: target = 3
	Output: 2
	Explanation:
	On the first move we step from 0 to 1.
	On the second step we step from 1 to 3.
	
	Example 2:
	Input: target = 2
	Output: 3
	Explanation:
	On the first move we step from 0 to 1.
	On the second move we step  from 1 to -1.
	On the third move we step from -1 to 2.
	
	Note:
	target will be a non-zero integer in the range [-10^9, 10^9].
	*/

	class reach_a_number
	{
	public:
		static int reach_number( int target )
		{
			target = std::abs( target );
			auto k = 0;

			while( target > 0 )
				target -= ++k;

			return target % 2 == 0 ?
				k :
				k + 1 + k % 2;
		}
	};
}
