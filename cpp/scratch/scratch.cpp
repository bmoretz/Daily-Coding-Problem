#include <bits/stdc++.h>
#include <array>

/* 724. Find Pivot Index.

Given an array of integers nums, write a method that returns the
"pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers
to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot
indexes, you should return the left-most pivot index.

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Constraints:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
*/

class pivot_index
{

public:

	static int find_pivot( const std::vector<int>& numbers )
	{
		if( numbers.empty() ) return -1;
		if( numbers.size() == 1 ) return 0;
		
		auto left_sum = 0, right_sum = std::accumulate( numbers.begin(), numbers.end(), 0 );
		
		for( auto index = 0ULL; index < numbers.size(); ++index )
		{
			const auto current = numbers.at( index );
			
			right_sum -= current;

			if( left_sum == right_sum )
				return index;

			left_sum += current;
		}
		
		return -1;
	}
};

auto main() -> int
{
	auto input1 = std::vector<int>{ 1, 7, 3, 6, 5, 6 };
	auto input2 = std::vector<int>{ 1, 7, 3, 6, 5, 6, 3, 4, 11, 1, 3, 2 };
	auto input3 = std::vector<int>{ 1, 7, 3, 6, 5, 6, 3, 4, 11, 1, 3, 2, 3, 1, 3, 5, 7, 8, 9 };
	auto input4 = std::vector<int>{ 1, 2 };
	auto input5 = std::vector<int>{ -1, -1, -1, -1, -1, -1 };
	
	const auto result = pivot_index::find_pivot( input4 );

	return 0;
}
