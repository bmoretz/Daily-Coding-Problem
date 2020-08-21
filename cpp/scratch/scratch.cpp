#include <bits/stdc++.h>

/* 713. Subarray Product Less Than K.

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:

Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

*/

class subarray_product
{
public:

	/// <summary>
	/// number of subarray products less than k
	///
	/// approach: sliding window
	/// we need 4 variables: cumulative, left, right, result
	///
	/// for each right, multiply it by cumulative and then while cumulative is greater
	/// than or equal to k (we need gte because it must be strictly less than k), divide by
	/// the number at index left and increment left. Increment the result by the number of items
	/// in the range right - left (inclusive +1).
	/// </summary>
	/// <param name="numbers">array</param>
	/// <param name="k">upper bound</param>
	/// <returns>number of subarrays less than k</returns>
	static int num_subarray_product_less_than_k( const std::vector<int>& numbers, const int k )
	{
		if( k <= 1 ) return 0;
		
		auto cumulative = 1, result = 0;
		auto left = 0ULL;

		for( auto right = 0ULL; right < numbers.size(); ++right )
		{
			cumulative *= numbers[ right ];
			
			while( cumulative >= k )
			{
				cumulative /= numbers[ left++ ];
			}

			result += right - left + 1;
		}

		return result;
	}
};

auto main() -> int
{
    const auto input1 = std::vector<int>{ 10, 5, 2, 6 };
	const auto input2 = std::vector<int>{ 1, 2, 3 };
	const auto input3 = std::vector<int>{ 1, 1, 1 };
	
    const auto actual = subarray_product::num_subarray_product_less_than_k( input3, 2 );
	
    return 0;
}