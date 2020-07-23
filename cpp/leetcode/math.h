#pragma once

#include <algorithm>
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
}
