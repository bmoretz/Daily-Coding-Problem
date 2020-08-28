#pragma once

#include <array>
#include <map>
#include <numeric>
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

	/* 918. Maximum Sum Circular Subarray.

	Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

	Here, a circular array means the end of the array connects to the beginning of the array.  (Formally,
	C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

	Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally,
	for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

	Example 1:

	Input: [1,-2,3,-2]
	Output: 3
	Explanation: Subarray [3] has maximum sum 3
	Example 2:

	Input: [5,-3,5]
	Output: 10
	Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
	Example 3:

	Input: [3,-1,2,-1]
	Output: 4
	Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
	Example 4:

	Input: [3,-2,2,-3]
	Output: 3
	Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
	Example 5:

	Input: [-2,-3,-1]
	Output: -1
	Explanation: Subarray [-1] has maximum sum -1


	Note:

	-30000 <= A[i] <= 30000
	1 <= A.length <= 30000
	*/

	class maximum_circular_sum
	{
	public:

		static int max_subarray_sum_circular( const std::vector<int>& arr )
		{
			if( arr.empty() ) return 0;

			auto len = arr.size();

			auto total = 0,
				maximum = arr[ 0 ], prev_max = 0,
				minimum = arr[ 0 ], prev_min = 0;

			for( auto current : arr )
			{
				total += current;

				maximum = std::max( maximum,
					prev_max = current + std::max( 0, prev_max ) );

				minimum = std::min( minimum,
					prev_min = current + std::min( 0, prev_min ) );
			}

			return maximum < 0 ?
				maximum : std::max( maximum, total - minimum );
		}
	};

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

	/* 567. Permutation in String.

	Given two strings s1 and s2, write a function to return true if s2 contains the
	permutation of s1. In other words, one of the first string's permutations is the
	substring of the second string.

	Example 1:

	Input: s1 = "ab" s2 = "eidbaooo"
	Output: True
	Explanation: s2 contains one permutation of s1 ("ba").

	Example 2:

	Input:s1= "ab" s2 = "eidboaoo"
	Output: False

	 Constraints:

	The input strings only contain lower case letters.
	The length of both given strings is in range [1, 10,000].
	*/

	class permutation_in_string
	{
		/// <summary>
		/// get character frequency
		///
		/// gets a char frequency array where the index is the letter and the value
		/// at that position is the number of those characters in the string.
		/// </summary>
		/// <param name="str">string to map</param>
		/// <returns>char map as char array</returns>
		static std::array<unsigned short, 26> get_char_freq( const std::string& str )
		{
			std::array<unsigned short, 26> freq{};

			const int offset = 'a';

			for( int chr : str )
			{
				const auto value = chr - offset;
				freq[ value ]++;
			}

			return freq;
		}

	public:

		/// <summary>
		/// check inclusion
		///
		/// using a sliding window to determine if there is an anagram of s1 inside s2.
		/// </summary>
		/// <param name="s1">string 1</param>
		/// <param name="s2">string 2</param>
		/// <returns>true if there is a permutation (anagram) of s1 inside s2.</returns>
		static bool checkInclusion( const std::string& s1, const std::string& s2 )
		{
			// no solution possible
			if( s1.length() > s2.length() ) return false;

			const std::size_t offset = 'a';

			// create maps of s1 and the first n (len of s1) chars of s2
			const auto s1_map = get_char_freq( s1 );
			auto s2_map = get_char_freq( s2.substr( 0, s1.size() ) );

			// if these equal we stop
			if( s1_map == s2_map )
				return true;

			// otherwise, for each index starting at s1 size
			for( auto index = s1.size(); index < s2.length(); ++index )
			{
				// remove the previous character which is offset by the size of s1 in s2	
				--s2_map[ s2[ index - s1.size() ] - offset ];
				// increment the current character of s2
				++s2_map[ s2[ index ] - offset ];

				// compare maps
				if( s1_map == s2_map )
					return true;
			}

			// no match
			return false;
		}
	};

	/*78. Subsets.

	Given a set of distinct integers, nums, return all possible subsets (the power set).

	Note: The solution set must not contain duplicate subsets.

	Example:

	Input: nums = [1,2,3]
	Output:
	[
	  [3],
	  [1],
	  [2],
	  [1,2,3],
	  [1,3],
	  [2,3],
	  [1,2],
	  []
	]
	*/

	class subsets
	{
	public:

		static std::vector<std::vector<int>> generate( const std::vector<int>& numbers )
		{
			std::vector<std::vector<int>> perms;

			if( numbers.empty() )
				return perms;

			auto temp = std::vector<int>{ };

			perms.push_back( temp );

			for( auto number : numbers )
			{
				const auto len = perms.size();

				for( auto inner = 0ULL; inner < len; ++inner )
				{
					temp = perms[ inner ];
					temp.push_back( number );
					perms.push_back( temp );
				}
			}

			return perms;
		}
	};

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

			auto left_sum = 0,
				right_sum = std::accumulate( numbers.begin(), numbers.end(), 0 );

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
}
