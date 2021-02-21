#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::hashtable
{
	/* 1287. Element Appearing More Than 25% In Sorted Array.

	Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

	Return that integer.

	Example 1:

	Input: arr = [1,2,2,6,6,6,6,7,10]
	Output: 6

	Constraints:

	1 <= arr.length <= 10^4
	0 <= arr[i] <= 10^5
	*/

	struct element_with_most_appearances
	{
		static int find_special_integer( const std::vector<int>& arr )
		{
			std::unordered_map<int, int> counts;
			auto max_freq = -1;

			for( auto cur : arr )
			{
				counts[ cur ]++;

				if( max_freq == -1 || counts[ cur ] > counts[ max_freq ] )
				{
					max_freq = cur;
				}
			}

			return max_freq;
		}
	};


	/* 1152. Analyze User Website Visit Pattern.

	We are given some website visits: the user with name username[i]
	visited the website website[i] at time timestamp[i].

	A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of
	their visits.  (The websites in a 3-sequence are not necessarily distinct.)

	Find the 3-sequence visited by the largest number of users. If there is more than
	one solution, return the lexicographically smallest such 3-sequence.

	Example 1:

	Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"],
	timestamp = [1,2,3,4,5,6,7,8,9,10],
	website = ["home","about","career","home","cart","maps","home","home","about","career"]

	Output: ["home","about","career"]

	Explanation:

	The tuples in this example are:

	["joe", 1, "home"]
	["joe", 2, "about"]
	["joe", 3, "career"]
	["james", 4, "home"]
	["james", 5, "cart"]
	["james", 6, "maps"]
	["james", 7, "home"]
	["mary", 8, "home"]
	["mary", 9, "about"]
	["mary", 10, "career"]
	The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
	The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
	The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
	The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
	The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.

	Note:

	3 <= N = username.length = timestamp.length = website.length <= 50
	1 <= username[i].length <= 10
	0 <= timestamp[i] <= 10^9
	1 <= website[i].length <= 10
	Both username[i] and website[i] contain only lowercase characters.
	It is guaranteed that there is at least one user who visited at least 3 websites.
	No user visits two websites at the same time.
	*/

	class visitor_patterns
	{
		static std::unordered_map<std::basic_string<char>, std::vector<std::pair<int, std::basic_string<char>>>>
			build_user_map( const std::vector<std::string>& username, const std::vector<int>& timestamp, const std::vector<std::string>& website )
		{
			auto map = std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>();

			// generate keys of users to timestamp/website
			for( auto index = 0ULL; index < username.size(); ++index )
			{
				const auto value = std::make_pair( timestamp[ index ], website[ index ] );
				map[ username[ index ] ].push_back( value );
			}

			return map;
		}

	public:

		static std::vector<std::string> most_visited_pattern(
			const std::vector<std::string>& username,
			const std::vector<int>& timestamp,
			const std::vector<std::string>& website )
		{
			auto sequences = std::set<std::vector<std::string>>();
			auto counts = std::map<std::vector<std::string>, int>();

			const auto map = build_user_map( username, timestamp, website );

			for( const auto& iter : map )
			{
				auto visits = iter.second;

				// order by timestamp
				std::sort( visits.begin(), visits.end(),
					[]( const std::pair<int, std::string>& left, const std::pair<int, std::string>& right )
					{
						return left.first < right.first;
					} );

				sequences.clear();

				// all possible sequences of websites for each user
				for( auto i = 0ULL; i < visits.size(); ++i )
				{
					for( auto j = 0ULL; j < i; j++ )
					{
						for( auto k = 0ULL; k < j; k++ )
						{
							sequences.insert( {
								visits[ k ].second,
								visits[ j ].second,
								visits[ i ].second
							} );
						}
					}
				}

				// increment the counter
				for( const auto& seq : sequences )
					counts[ seq ]++;
			}

			return std::max_element( counts.begin(), counts.end(), []( auto& p1, auto& p2 )
				{
					return ( ( p1.second == p2.second ) ?
						( p1.first > p2.first ) :
						( p1.second < p2.second ) );
				} )->first;
		}
	};

	/*1207. Unique Number of Occurrences.

	Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

	Example 1:

	Input: arr = [1,2,2,1,1,3]
	Output: true
	Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
	Example 2:

	Input: arr = [1,2]
	Output: false
	Example 3:

	Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
	Output: true

	Constraints:

	1 <= arr.length <= 1000
	-1000 <= arr[i] <= 1000
	*/

	class unique_occurrences
	{
		static std::unordered_map<int, int> to_map( const std::vector<int>& values )
		{
			std::unordered_map<int, int> map;

			for( auto val : values )
			{
				++map[ val ];
			}

			return map;
		}

	public:
		
		static bool unique( const std::vector<int>& values )
		{
			const auto map = to_map( values );

			auto unique = std::set<int>();

			for( auto& [key, value] : map )
			{
				unique.insert( value );
			}

			return unique.size() == map.size();
		}
	};

	/*1002. Find Common Characters.

	Given an array A of strings made only from lowercase letters, return a list of all characters that
	show up in all strings within the list (including duplicates).  For example, if a character occurs 3
	times in all strings but not 4 times, you need to include that character three times in the final answer.

	You may return the answer in any order.

	Example 1:

	Input: ["bella","label","roller"]
	Output: ["e","l","l"]
	Example 2:

	Input: ["cool","lock","cook"]
	Output: ["c","o"]


	Note:

	1 <= A.length <= 100
	1 <= A[i].length <= 100
	A[i][j] is a lowercase letter
	*/

	class common_characters
	{
		static std::map<char, std::size_t> to_char_map( const std::string& str )
		{
			std::map<char, std::size_t> map;

			for( auto chr : str )
			{
				map[ chr ]++;
			}

			return map;
		}

	public:

		static std::vector<std::string> find_common( const std::vector<std::string>& strings )
		{
			auto counts = std::map<char, std::size_t>();
			std::vector<bool> required( 26, true );

			for( auto index = 0; index < 26; ++index )
			{
				counts[ index + 'a' ] = SIZE_MAX;
			}

			for( const auto& str : strings )
			{
				const auto current = to_char_map( str );

				for( auto& [k, v] : current )
				{
					counts[ k ] = std::min( counts[ k ], v );
				}

				for( auto index = 0; index < 26; ++index )
				{
					if( current.find( 'a' + index ) == current.end() )
					{
						required[ index ] = false;
					}
				}
			}

			std::vector<std::string> result;

			for( auto& [k, v] : counts )
			{
				const auto current = k - 'a';

				if( required[ current ] )
				{
					for( auto rep = 0ULL; rep < v; ++rep )
					{
						result.emplace_back( 1, k );
					}
				}
			}

			return result;
		}
	};

	/* 13. Roman to Integer.

	Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

	Symbol       Value
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000

	For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII,
	which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

	Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
	Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the
	number nine, which is written as IX. There are six instances where subtraction is used:

	I can be placed before V (5) and X (10) to make 4 and 9.
	X can be placed before L (50) and C (100) to make 40 and 90.
	C can be placed before D (500) and M (1000) to make 400 and 900.
	Given a roman numeral, convert it to an integer.

	Example 1:

	Input: s = "III"
	Output: 3
	Example 2:

	Input: s = "IV"
	Output: 4
	Example 3:

	Input: s = "IX"
	Output: 9
	Example 4:

	Input: s = "LVIII"
	Output: 58
	Explanation: L = 50, V= 5, III = 3.
	Example 5:

	Input: s = "MCMXCIV"
	Output: 1994
	Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

	Constraints:

	1 <= s.length <= 15
	s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
	It is guaranteed that s is a valid roman numeral in the range [1, 3999].
	*/

	class roman_to_integer
	{
		static std::unordered_map<char, int> roman_;

		[[nodiscard]] static int get_value_at( const std::string& input,
			const int index )
		{
			if( index < 0 || index >= input.size() ) return 0;

			return roman_.at( input[ index ] );
		}

	public:

		static int roman_to_int( const std::string& input )
		{
			auto sum = 0, index = 0;

			while( index < input.length() )
			{
				const auto current = get_value_at( input, index );
				const auto next = get_value_at( input, index + 1 );

				if( current < next )
				{
					sum += next - current;
					index += 2;
				}
				else
				{
					sum += current;
					++index;
				}
			}

			return sum;
		}
	};

	std::unordered_map<char, int> roman_to_integer::roman_ = {
		{'M', 1000},
		{'D', 500},
		{'C', 100},
		{'L', 50},
		{'X', 10},
		{'V', 5},
		{'I', 1}
	};

	/*136. Single Number.

	Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

	Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?


	Example 1:

	Input: nums = [2,2,1]
	Output: 1
	Example 2:

	Input: nums = [4,1,2,1,2]
	Output: 4
	Example 3:

	Input: nums = [1]
	Output: 1


	Constraints:

	1 <= nums.length <= 3 * 104
	-3 * 104 <= nums[i] <= 3 * 104
	Each element in the array appears twice except for one element which appears only once.

	*/

	class single_number
	{

	public:

		/// <summary>
		/// O(N) run-time, O(1) space
		/// </summary>
		/// <param name="numbers">numbers</param>
		/// <returns>the number with 1 occurence</returns>
		static int singleNumber1( const std::vector<int>& numbers )
		{
			auto counts = std::unordered_map<int, int>();

			for( auto num : numbers )
			{
				counts[ num ]++;
			}

			for( auto& [k, v] : counts )
			{
				if( v == 1 ) return k;
			}

			return -1;
		}

		/// <summary>
		/// O(N) run-time, O(1) space
		/// </summary>
		/// <param name="numbers">numbers</param>
		/// <returns>number with 1 occurence.</returns>
		static int singleNumber2( const std::vector<int>& numbers )
		{
			auto seen = 0;

			for( auto num : numbers )
			{
				seen ^= num;
			}

			return seen;
		}
	};

	/* 202. Happy Number.

	Write an algorithm to determine if a number n is happy.

	A happy number is a number defined by the following process:

	Starting with any positive integer, replace the number by the sum of the squares of its digits.
	Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
	Those numbers for which this process ends in 1 are happy.
	Return true if n is a happy number, and false if not.

	*/

	class happy_number
	{
		static int get_sqr_sum_digits( int num )
		{
			auto total_sum = 0;

			while( num > 0 )
			{
				const auto digit = num % 10;
				num = num / 10;
				total_sum += digit * digit;
			}

			return total_sum;
		}

	public:

		static bool is_happy( int n )
		{
			auto seen = std::set<int>();

			while( n != 1 && seen.find( n ) == seen.end() )
			{
				seen.insert( n );
				n = get_sqr_sum_digits( n );
			}

			return n == 1;
		}
	};

	/*

	Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

	"abc" -> "bcd" -> ... -> "xyz"
	Given a list of non-empty strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

	Example:

	Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
	Output:
	[
	  ["abc","bcd","xyz"],
	  ["az","ba"],
	  ["acef"],
	  ["a","z"]
	]

	*/

	class group_shifted_sequence
	{

	public:

		static std::vector<std::vector<std::string>> groupStrings( const std::vector<std::string>& strings )
		{
			std::map<std::vector<int>, std::vector<std::string>> group_map;

			for( const auto& str : strings )
			{
				auto key = std::vector<int>();

				for( auto index = 1; index < str.length(); ++index )
				{
					const auto cur = str[ index ];
					const auto prev = str[ index - 1 ];

					const auto val = ( str[ index ] - str[ index - 1 ] + 26 ) % 26;

					key.push_back( val );
				}

				group_map[ key ].push_back( str );
			}

			auto results = std::vector<std::vector<std::string>>();

			for( auto& [k, v] : group_map )
			{
				results.push_back( v );
			}

			return results;
		}
	};
}