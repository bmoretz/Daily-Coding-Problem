#include <bits/stdc++.h>

/* 1464. Maximum Product of Two Elements in an Array.
 
Given the array of integers nums, you will choose two different indices i and j of that
array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

Example 1:
Input: nums = [3,4,5,2]
Output: 12

Example 2:
Input: nums = [1,5,4,5]
Output: 16

Example 3:
Input: nums = [3,7]
Output: 12
*/

struct maximum_two_prod
{
	int maxProduct( std::vector<int>& numbers ) const
	{
		std::make_heap( numbers.begin(), numbers.end() );

		const auto first = numbers.front();
		
		std::pop_heap( numbers.begin(), numbers.end() );

		const auto second = numbers.front();

		return ( first - 1 ) * ( second - 1 );
	}
};

auto main() -> int
{
	auto input1 = std::vector<int>{ 3, 4, 5, 2 };
	auto input2 = std::vector<int>{ 1, 5, 4, 5 };
	auto input3 = std::vector<int>{ 3, 7 };
	auto input4 = std::vector<int>{ 1, 1 };
	auto input5 = std::vector<int>{ 9, 8, 7, 6 };

	const maximum_two_prod sln;
	
	const auto result = sln.maxProduct( input1 );

	std::cout << "Result: " << result << std::endl;
	
	return 0;
}
