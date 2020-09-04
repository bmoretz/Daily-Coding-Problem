#include <bits/stdc++.h>
#include <array>

/* 368. Largest Divisible Subset.

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class no_zero_integers
{
	
public:

	static std::vector<int> largestDivisibleSubset( std::vector<int>& numbers )
	{
		if( numbers.empty() ) return { };

		std::sort( numbers.begin(), numbers.end() );

		auto dp = std::vector<int>( numbers.size(), 1 );
		auto prev = std::vector<int>( numbers.size(), -1 );

		auto max_index = 0;

		for( auto index = 1; index < numbers.size(); ++index )
		{
			for( auto sub = 0; sub < index; ++sub )
			{
				if( numbers.at( index ) % numbers.at( sub ) == 0
					&& dp[ index ] < dp[ sub ] + 1 )
				{
					dp[ index ] = dp[ sub ] + 1;
					prev[ index ] = sub;
				}
			}

			if( dp[ index ] > dp[ max_index ] )
			{
				max_index = index;
			}
		}

		auto result = std::vector<int>();

		auto index = max_index;
		while( index >= 0 )
		{
			result.push_back( numbers.at( index ) );
			index = prev[ index ];
		}

		return result;
	}
};

auto main() -> int
{
	auto input1 = std::vector<int>{ 1, 2, 3 };
	const auto input2 = 11;
	const auto input3 = 10000;
	const auto input4 = 69;
	
	const auto result = no_zero_integers::largestDivisibleSubset( input1 );
	
	return 0;
}