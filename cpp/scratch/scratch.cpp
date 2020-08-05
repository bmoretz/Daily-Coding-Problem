#include <bits/stdc++.h>

/* 53. Maximum Subarray.

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

struct max_sub_array
{
	/// <summary>
	/// max sub array
	///
	/// straight forward sliding window technique using a hash map to store the max value at each previous index.
	/// </summary>
	/// <param name="numbers">the numbers</param>
	/// <returns>max value of any contiguous subarray</returns>
	static int max_sub_array1( const std::vector<int>& numbers )
	{
		if( numbers.empty() ) return 0;
		if( numbers.size() == 1 ) return numbers.at( 0 );
		
		std::map<int, int> previous_sums = { { 0, numbers.at(0 ) } };

		auto max_sum = previous_sums[ 0 ];
		auto start = 0UL;
		
		for( auto stop = 1UL; stop < numbers.size(); ++stop )
		{
			auto current = numbers.at( stop );
			
			previous_sums[ stop ] = std::max( previous_sums[ stop - 1 ] + current, current );

			max_sum = std::max( previous_sums[ stop ], max_sum );
		}

		return max_sum;
	}
};


auto main() -> int
{
	const auto input1 = std::vector<int>{ -2, 1, -3, 4, -1, 2, 1, -5, 4 }; // 6
	const auto input2 = std::vector<int>{ 1, 0, -1, 0, 0, 0, -1, 0, 1 }; // 1
	const auto input3 = std::vector<int>{ 3, -1, 0, 2 }; // 4
	const auto input4 = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4 }; // 30
	const auto input5 = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4, 12, 4, 13, 1, 0, 1, 143 }; // 200
	
	const auto result = max_sub_array::max_sub_array1( input1 );

	std::cout << result;
	
	return 0;
}