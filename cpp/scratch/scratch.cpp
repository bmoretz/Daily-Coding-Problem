#include <bits/stdc++.h>

/* 525. Contiguous Array.

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

struct contiguous_array
{
	static int find_max_length( const std::vector<int>& numbers )
	{
		std::map<int, int> map { { 0, -1 } };
		auto longest = 0, count = 0;

		for( auto index = 0; index < numbers.size(); ++index )
		{
			count = count + ( numbers[ index ] == 0 ? -1 : 1 );

			if( map.find( count ) != std::end( map ) )
			{
				longest = std::max( longest, index - map[ count ] );
			}
			else
			{
				map.insert( std::make_pair( count, index ) );
			}
		}

		return longest;
	}
};

auto main() -> int
{
    const auto input1 = std::vector<int>{ 0, 1 }; // 2
    const auto input2 = std::vector<int>{ 0, 1, 0 }; // 2
	const auto input3 = std::vector<int>{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 }; // 26
	const auto input4 = std::vector<int>{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 }; // 22
	const auto input5 = std::vector<int>{ 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 }; // 20
	const auto input6 = std::vector<int>{ 0, 1, 1, 0, 1, 1 }; // 4
	
	const auto result = contiguous_array::find_max_length( input6 );

	std::cout << result;
	
	return 0;
}
