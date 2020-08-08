#pragma once

#include <vector>

namespace leetcode::backtrack
{
	/* 254. Factor Combinations.

	Numbers can be regarded as product of its factors. For example,

	8 = 2 x 2 x 2;
	  = 2 x 4.

	Write a function that takes an integer n and return all possible combinations of its factors.

	Note:

	You may assume that n is always positive.
	Factors should be greater than 1 and less than n.

	Example 1:
	Input: 1
	Output: []

	Example 2:
	Input: 37
	Output:[]

	Example 3:
	Input: 12
	Output:
	[
	  [2, 6],
	  [2, 2, 3],
	  [3, 4]
	]

	Example 4:
	Input: 32
	Output:
	[
	  [2, 16],
	  [2, 2, 8],
	  [2, 2, 2, 4],
	  [2, 2, 2, 2, 2],
	  [2, 4, 4],
	  [4, 8]
	]
	*/

	struct factor_combinations
	{
		static std::vector<std::vector<int>> get_factors( const int n )
		{
			std::vector<std::vector<int>> results;
			auto cur = std::vector<int>{ };

			factor( results, cur, n, 2 );

			return results;
		}

		static void factor( std::vector<std::vector<int>>& results, std::vector<int>& cur,
			const int n, const int start )
		{
			if( n <= 1 )
			{
				if( cur.size() > 1 )
				{
					results.emplace_back( std::vector<int>( cur ) );
				}

				return;
			}

			for( auto divisor = start; divisor <= n; ++divisor )
			{
				if( n % divisor == 0 )
				{
					cur.emplace_back( divisor );
					factor( results, cur, n / divisor, divisor );
					cur.erase( cur.end() - 1 );
				}
			}
		}
	};
}