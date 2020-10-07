#pragma once

#include <array>
#include <map>
#include <numeric>
#include <unordered_map>
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
						static_cast< int >( index ),
							static_cast< int >( key->second )
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
		/// <param name="arr">the array</param>
		/// <param name="target_sum">target sum</param>
		/// <returns>number of ways to reach target with subarrays</returns>
		static int num_subarrays_with_sum2( const std::vector<int>& arr,
			int target_sum )
		{
			auto result = 0;

			for( auto index = 0, left = 0, prefix = 0; index < arr.size(); ++index )
			{
				if( arr[ index ] == 1 )
				{
					--target_sum;
				}

				while( left < index && target_sum < 0 )
				{
					if( arr[ left++ ] == 1 )
					{
						prefix = 0;
						target_sum++;
					}
				}

				while( left < index && arr[ left ] == 0 )
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

	/* 165. Compare Version Numbers.

	Given two version numbers, version1 and version2, compare them.

	Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits
	and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from
	left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For
	example 2.5.33 and 0.1 are valid version numbers.

	To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value
	ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a
	revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision
	0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

	Return the following:

	If version1 < version2, return -1.
	If version1 > version2, return 1.

	Otherwise, return 0.

	Example 1:

	Input: version1 = "1.01", version2 = "1.001"
	Output: 0
	Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

	Example 2:

	Input: version1 = "1.0", version2 = "1.0.0"
	Output: 0
	Explanation: version1 does not specify revision 2, which means it is treated as "0".

	Example 3:

	Input: version1 = "0.1", version2 = "1.1"
	Output: -1
	Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.

	Example 4:

	Input: version1 = "1.0.1", version2 = "1"
	Output: 1

	Example 5:

	Input: version1 = "7.5.2.4", version2 = "7.5.3"
	Output: -1


	Constraints:

	1 <= version1.length, version2.length <= 500
	version1 and version2 only contain digits and '.'.
	version1 and version2 are valid version numbers.
	All the given revisions in version1 and version2 can be stored in a 32-bit integer.
	*/

	class compare_versions
	{
		static std::vector<int> to_vector( const std::string& input )
		{
			std::istringstream iss( input );
			std::string token;
			std::vector<int> result;

			while( std::getline( iss, token, '.' ) )
			{
				if( !token.empty() )
					result.push_back( std::stoi( token ) );
			}

			return result;
		}

	public:

		/// <summary>
		/// 
		/// </summary>
		/// <param name="version1"></param>
		/// <param name="version2"></param>
		/// <complexity>
		///		<runtime>O(max(p, q))</runtime>
		///		<space>O(max(p, q))</runtime>
		/// </complexity>
		/// <returns></returns>
		static int compare_version( const std::string& version1, const std::string& version2 )
		{
			auto left = to_vector( version1 ), right = to_vector( version2 );

			for( auto index = 0ULL;
				index < std::max( left.size(), right.size() );
				++index )
			{
				const auto l_val = index < left.size() ? left[ index ] : 0;
				const auto r_val = index < right.size() ? right[ index ] : 0;

				if( l_val > r_val )
				{
					return 1;
				}

				if( r_val > l_val )
				{
					return -1;
				}
			}

			return 0;
		}
	};

	/* 238. Product of Array Except Self.

	Given an array nums of n integers where n > 1,  return an array output such
	that output[i] is equal to the product of all the elements of nums except nums[i].

	Example:

	Input:  [1,2,3,4]
	Output: [24,12,8,6]
	Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

	Note: Please solve it without division and in O(n).

	Follow up:
	Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
	*/

	class prod_except_self
	{
	public:

		static std::vector<int> product_except_self( const std::vector<int>& numbers )
		{
			const int N = numbers.size();

			auto left = std::vector<int>( N );
			left[ 0 ] = 1;

			for( auto index = 1; index < N; ++index )
			{
				left[ index ] = numbers[ index - 1 ] * left[ index - 1 ];
			}

			auto right = std::vector<int>( N );
			right[ N - 1 ] = 1;

			for( auto index = N - 2; index >= 0; --index )
			{
				right[ index ] = numbers[ index + 1 ] * right[ index + 1 ];
			}

			auto result = std::vector<int>( N );

			for( auto index = 0; index < N; ++index )
			{
				result[ index ] = left[ index ] * right[ index ];
			}

			return result;
		}
	};

	/* 3. Longest Substring Without Repeating Characters.

	Given a string s, find the length of the longest substring without repeating characters.

	Example 1:

	Input: s = "abcabcbb"
	Output: 3
	Explanation: The answer is "abc", with the length of 3.

	Example 2:

	Input: s = "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.
	Example 3:

	Input: s = "pwwkew"

	Output: 3
	Explanation: The answer is "wke", with the length of 3.
	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
	Example 4:

	Input: s = ""
	Output: 0


	Constraints:

	0 <= s.length <= 5 * 104
	s consists of English letters, digits, symbols and spaces.
	*/

	class longest_without_repeats
	{
		static auto longest_forward_substring( const std::string& str )
		{
			std::set<char> seen;
			auto longest = 0UL, current = 0UL;

			for( auto it = str.begin(); it != str.end(); ++it )
			{
				if( seen.find( *it ) == std::end( seen ) )
				{
					seen.insert( *it );
					++current;
				}
				else
				{
					longest = std::max( longest, current );
					current = 1UL;
				}
			}

			return std::max( longest, current );
		}

		static auto longest_reverse_substring( const std::string& str )
		{
			std::set<char> seen;
			auto longest = 0UL, current = 0UL;

			for( auto it = str.rbegin(); it != str.rend(); ++it )
			{
				if( seen.find( *it ) == std::end( seen ) )
				{
					seen.insert( *it );
					++current;
				}
				else
				{
					longest = std::max( longest, current );
					current = 1UL;
				}
			}

			return std::max( longest, current );
		}

	public:

		static int length_of_longest_substring( const std::string& str )
		{
			const auto fwd = longest_forward_substring( str );
			const auto rev = longest_reverse_substring( str );

			return std::max( fwd, rev );
		}
	};

	/* 42. Trapping Rain Water.

	Given n non-negative integers representing an elevation map where the width of each bar is 1,
	compute how much water it is able to trap after raining.

	The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
	(blue section) are being trapped. Thanks Marcos for contributing this image!

	Example:

	Input: [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6
	*/

	class trapping_rain_water
	{
		static std::vector<int> get_left_max( const std::vector<int>& numbers )
		{
			auto vec = std::vector<int>( numbers.size() );
			vec[ 0 ] = numbers[ 0 ];

			for( auto index = 1; index < numbers.size(); ++index )
			{
				vec[ index ] = std::max( numbers[ index ], vec[ index - 1 ] );
			}

			return vec;
		}

		static std::vector<int> get_right_max( const std::vector<int>& numbers )
		{
			auto vec = std::vector<int>( numbers.size() );
			vec[ numbers.size() - 1 ] = numbers[ numbers.size() - 1 ];

			for( int index = numbers.size() - 2; index >= 0; --index )
			{
				vec[ index ] = std::max( numbers[ index ], vec[ index + 1 ] );
			}

			return vec;
		}

	public:

		static int trap( const std::vector<int>& height )
		{
			if( height.empty() ) return 0;

			auto left = get_left_max( height );
			auto right = get_right_max( height );

			auto result = 0;

			for( auto index = 1; index < height.size() - 1; ++index )
			{
				result += std::min( left[ index ], right[ index ] ) - height[ index ];
			}

			return result;
		}
	};

	/* 16. 3Sum Closest.

	Given an array nums of n integers and an integer target, find three integers in nums such that the sum
	is closest to target. Return the sum of the three integers. You may assume
	that each input would have exactly one solution.

	Example 1:

	Input: nums = [-1,2,1,-4], target = 1
	Output: 2
	Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

	Constraints:

	3 <= nums.length <= 10^3
	-10^3 <= nums[i] <= 10^3
	-10^4 <= target <= 10^4
	*/

	class tree_sum_closest_sw
	{

	public:

		static int three_sum_closest( std::vector<int>& numbers,
			const int target )
		{
			int diff = std::numeric_limits<int>::max(), N = numbers.size();

			std::sort( numbers.begin(), numbers.end() );

			for( auto index = 0; index < N && diff != 0; ++index )
			{
				auto low = index + 1, high = N - 1;

				while( low < high )
				{
					const auto sum = numbers[ index ] + numbers[ low ] + numbers[ high ];

					if( abs( target - sum ) < abs( diff ) )
					{
						diff = target - sum;
					}

					if( sum < target )
					{
						++low;
					}
					else
					{
						--high;
					}
				}
			}

			return target - diff;
		}
	};
}