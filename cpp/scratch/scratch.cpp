#include <bits/stdc++.h>
#include <array>

/* 930. Binary Subarrays With Sum.

In an array A of 0s and 1s, how many non-empty subarrays have sum S?

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 

The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.
*/

class binary_strings_sum
{
public:

	/// <summary>
	/// sliding window solution
	/// </summary>
	/// <complexity>
	///		<runtime>O(n)</runtime>
	///		<space>O(1)</runtime>
	/// </complexity>
	/// <param name="arr"></param>
	/// <param name="target_sum"></param>
	/// <returns></returns>
	static int num_subarrays_with_sum2( const std::vector<int>& arr,
		int target_sum )
	{
		auto result = 0;

		for( auto index = 0, left = 0, prefix = 0; index < arr.size(); ++index )
		{
			if( arr[index] == 1 )
			{
				--target_sum;
			}

			while( left < index && target_sum < 0 )
			{
				if( arr[left++] == 1 )
				{
					prefix = 0;
					target_sum++;
				}
			}

			while( left < index && arr[left] == 0 )
			{
				left++;
				prefix++;
			}

			if( target_sum == 0 )
			{
				result += prefix + 1;
			}
		}

		return result;
	}
	
	/// <summary>
	/// prefix sum solution
	/// </summary>
	/// <param name="arr">array of 0/1's</param>
	/// <param name="target_sum">the target</param>
	/// <complexity>
	///		<runtime>O(n)</runtime>
	///		<space>O(N)</runtime>
	/// </complexity>
	/// <returns>number of ways to reach the target</returns>
	static int num_subarrays_with_sum1( const std::vector<int>& arr, const int target_sum )
	{
		auto result = 0;

		std::unordered_map<int, int> counts = { { 0, 1 } };
		auto cumulative = 0; // keep a running total for all the values
		
		for( auto num : arr )
		{
			cumulative += num; // increment cumulative

			// the result at each step will be the current running total - the target sum
			result += counts[ cumulative - target_sum ];

			// update the ways to reach the current total
			++counts[ cumulative ];
		}
		
		return result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<int>
	{
		1, 0, 1, 0, 1
	};

	const auto input2 = std::vector<int>
	{
		0, 0, 0, 0, 0
	};

	const auto input3 = std::vector<int>
	{
		1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0
	};
	
	const auto result = binary_strings_sum::num_subarrays_with_sum2( input1, 2 );
	
	return 0;
}