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
			std::map<int, int> map{ { 0, -1 } };
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

	/* 53. Maximum Subarray.

	Given an integer array numbers, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

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

			std::map<int, int> previous_sums = { { 0, numbers.at( 0 ) } };

			auto max_sum = previous_sums[ 0 ];
			
			for( auto stop = 1UL; stop < numbers.size(); ++stop )
			{
				auto current = numbers.at( stop );

				previous_sums[ stop ] = std::max( previous_sums[ stop - 1 ] + current, current );

				max_sum = std::max( previous_sums[ stop ], max_sum );
			}

			return max_sum;
		}
	};

	/* 121. Best Time to Buy and Sell Stock.

	Say you have an array for which the ith element is the price of a given stock on day i.

	If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

	Note that you cannot sell a stock before you buy one.

	Example 1:
	Input: [7,1,5,3,6,4]
	Output: 5
	Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
				 Not 7-1 = 6, as selling price needs to be larger than buying price.

	Example 2:
	Input: [7,6,4,3,1]
	Output: 0
	Explanation: In this case, no transaction is done, i.e. max profit = 0.
	*/

	struct buy_and_sell_stock
	{
		static int max_profit( const std::vector<int>& prices )
		{
			if( prices.empty() ) return 0;

			auto max_profit = 0;
			auto buy_price = prices.at( 0 ), sell_price = -1;

			for( auto index = 1ULL; index < prices.size(); ++index )
			{
				if( prices.at( index ) < buy_price )
				{
					buy_price = prices.at( index );
					sell_price = -1;
				}
				else if( prices.at( index ) > sell_price )
				{
					sell_price = prices.at( index );
				}

				max_profit = std::max( max_profit, sell_price - buy_price );
			}

			return max_profit;
		}
	};
}
