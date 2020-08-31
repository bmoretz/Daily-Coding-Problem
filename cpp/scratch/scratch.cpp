#include <bits/stdc++.h>
#include <array>

/*628. Maximum Product of Three Numbers.

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 
Example 2:

Input: [1,2,3,4]
Output: 24

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

class max_prod
{
public:

	static int maximumProduct( const std::vector<int>& numbers,
		const int k = 3)
	{
		if( numbers.empty() ) return 0;

		// two heaps, one min / one max
		auto max = std::priority_queue<int, std::vector<int>, std::less<>>();
		auto min = std::priority_queue<int, std::vector<int>, std::greater<>>();

		// put all the numbers in the heap
		for( auto num : numbers )
		{
			max.push( num );
			min.push( num );
		}

		// the solution must contain the largest number,
		// so include it in both.
		const auto maximum = max.top();
		
		auto max_result = maximum;
		auto min_result = maximum;

		max.pop();

		// max result = largest number * the two next largest numbers.
		for( auto index = 0; index < k - 1; ++index )
		{
			max_result *= max.top();
			max.pop();
		}

		// min result = max number * the two smallest (negative) numbers.
		for( auto index = 0; index < k - 1; ++index )
		{
			min_result *= min.top();
			min.pop();
		}

		// one of these must be the solution.
		return max_result > min_result ? max_result : min_result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<int>
	{
		1, 2, 3
	};

	const auto input2 = std::vector<int>
	{
		1, 2, 3, 4
	};
	
	const auto result = max_prod::maximumProduct( input2, 4 );
	
	return 0;
}