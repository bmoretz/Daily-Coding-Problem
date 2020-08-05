#include <bits/stdc++.h>

/* 1005. Maximize Sum Of Array After K Negations.

Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we
repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way. 

Example 1:
Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].

Example 2:
Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].

Example 3:
Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
 

Note:

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
*/

struct k_negations
{
	/// <summary>
	/// max sum after k negations
	///
	/// the strategy here is to us a heap to take the k minimum elements one by one,
	/// push the negated version back into the array using heap push, then take the next
	/// until we have negated k values.
	/// </summary>
	/// <param name="arr">array of values</param>
	/// <param name="k">number of negations allowed</param>
	/// <returns>max sum</returns>
	static int largest_sum_after_k_negations( std::vector<int>& arr, int k )
	{
		if( arr.empty() ) return 0;
		if( k == 0 ) return std::accumulate( arr.begin(), arr.end(), 0 );
		
		std::make_heap( arr.begin(), arr.end(), std::greater<>() );
		
		while( k > 0 )
		{
			const auto min_value = arr.front();
			
			std::pop_heap( arr.begin(), arr.end(), std::greater<>() );
			arr.pop_back();
			
			arr.push_back( -min_value );
			std::push_heap( arr.begin(), arr.end(), std::greater<>() );
			
			--k;
		}

		return std::accumulate( arr.begin(), arr.end(), 0 );
	}
};


auto main() -> int
{
	auto input1 = std::vector<int> { 4, 2, 3 };
	auto input2 = std::vector<int>{ 2, -3, -1, 5, -4 };
	auto input3 = std::vector<int>{ 3, -1, 0, 2 };
	auto input4 = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4 };
	auto input5 = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4, 12, 4, 13, 1, 0, 1, 143 };
	
	const auto result = k_negations::largest_sum_after_k_negations( input3, 3 );

	std::cout << result;
	
	return 0;
}