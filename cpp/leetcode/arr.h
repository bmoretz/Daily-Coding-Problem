#pragma once

#include <map>
#include <vector>

namespace leetcode::arr
{
	/* Two Sum.

	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	Example:

	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
	 */

	struct target_two_sum
	{
		/// <summary>
		/// two sum 1
		/// </summary>
		/// <param name="numbers">vector of numbers</param>
		/// <param name="target">target sum</param>
		/// <returns>the indices of the two numbers in the array that sum to the target.</returns>
		static std::vector<int> two_sum1( const std::vector<int>& numbers, const int target )
		{
			auto lookup = to_lookup( numbers );

			for( auto index = 0ULL; index < numbers.size(); ++index )
			{
				const auto match = target - numbers.at( index );
				const auto key = lookup.find( match );

				if( key != lookup.end() && key->second != index )
				{
					return std::vector<int>
					{
						static_cast<int>( index ),
						static_cast<int>( key->second )
					};
				}
			}

			return std::vector<int>();
		}

		static std::map<int, std::size_t> to_lookup( const std::vector<int>& numbers )
		{
			std::map<int, std::size_t> lookup;

			for( auto index = 0; index < numbers.size(); ++index )
			{
				lookup.insert( std::make_pair( numbers.at( index ), index ) );
			}

			return lookup;
		}
	};

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
		static int max_product1( std::vector<int>& numbers )
		{
			std::make_heap( numbers.begin(), numbers.end() );

			const auto first = numbers.front();

			std::pop_heap( numbers.begin(), numbers.end() );

			const auto second = numbers.front();

			return ( first - 1 ) * ( second - 1 );
		}
	};
}
