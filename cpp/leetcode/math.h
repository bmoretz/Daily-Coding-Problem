#pragma once

#include <algorithm>
#include <set>
#include <string>
#include <vector>

namespace leetcode::math
{
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
