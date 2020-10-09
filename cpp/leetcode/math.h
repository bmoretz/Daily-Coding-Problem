#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace leetcode::math
{
	/* Minimum Moves to Equal Array Elements II.

	Given a non-empty integer array, find the minimum number of moves required to make all array elements equal,
	where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

	You may assume the array's length is at most 10,000.

	Example:

	Input: [1,2,3]
	Output: 2

	Explanation:
	Only two moves are needed (remember each move increments or decrements one element):

	[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
	*/

	struct min_moves
	{
		/// <summary>
		/// min moves
		/// </summary>
		/// <complexity>
		///		<run-time>O(n log n)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="numbers"></param>
		/// <returns>the minimum number of moves to make all the array elements equal</returns>
		static int min_moves2( std::vector<int>& numbers )
		{
			auto result = 0;

			if( !numbers.empty() )
			{
				std::sort( std::begin( numbers ), std::end( numbers ) );

				const auto mid = numbers.at( ( numbers.size() - 1 ) / 2 );

				for( auto num : numbers )
				{
					result += std::abs( mid - num );
				}
			}

			return result;
		}
	};

	/* 1513. Number of Substrings With Only 1s.

	Given a binary string s (a string consisting only of '0' and '1's).
	Return the number of substrings with all characters 1's.

	Since the answer may be too large, return it modulo 10^9 + 7.

	Example 1:

	Input: s = "0110111"
	Output: 9
	Explanation: There are 9 substring in total with only 1's characters.

	"1" -> 5 times.
	"11" -> 3 times.
	"111" -> 1 time.

	Example 2:

	Input: s = "101"
	Output: 2
	Explanation: Substring "1" is shown 2 times in s.

	Example 3:

	Input: s = "111111"
	Output: 21
	Explanation: Each substring contains only 1's characters.
	Example 4:

	Input: s = "000"
	Output: 0
	*/

	struct number_of_1s_substrings
	{
		static std::unordered_map<std::size_t, std::size_t> get_ones_counts( const std::string& input )
		{
			std::unordered_map<std::size_t, std::size_t> groups;

			auto current_len = std::size_t();

			for( auto chr : input )
			{
				if( chr == '1' )
				{
					++current_len;
				}
				else if( current_len > 0 )
				{
					groups[ current_len ]++;
					current_len = std::size_t();
				}
			}

			if( current_len > 0 )
				groups[ current_len ]++;

			return groups;
		}

		/// <summary>
		/// number of subgroups
		/// </summary>
		/// <param name="str">input string</param>
		/// <returns>number of ways to choose subgroups of 1's</returns>
		static int number_of_subgroups( const std::string& str )
		{
			auto group_counts = get_ones_counts( str );
			auto perms = 0;
			const unsigned long long mod_op = std::pow( 10, 9 ) + 7;

			for( const auto& group : group_counts )
			{
				const auto intermediate = group.second * ( group.first * ( group.first + 1 ) / 2 );
				perms = ( static_cast< std::size_t >( perms ) + intermediate ) % mod_op;
			}

			return perms;
		}
	};

	/* 509. Fibonacci Number

	The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is
	the sum of the two preceding ones, starting from 0 and 1. That is,

	F(0) = 0,   F(1) = 1
	F(N) = F(N - 1) + F(N - 2), for N > 1.
	Given N, calculate F(N).

	Example 1:

	Input: 2
	Output: 1
	Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

	Example 2:

	Input: 3
	Output: 2
	Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

	Example 3:

	Input: 4
	Output: 3
	Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
	*/

	struct fibonacci_number
	{
		static int fib1( const int n )
		{
			std::unordered_map<unsigned long, unsigned long> lookup{ { 0, 0 }, { 1, 1 } };

			return fib( n, lookup );
		}

		static int fib( const int n, std::unordered_map<unsigned long, unsigned long>& lookup )
		{
			if( lookup.find( n ) == lookup.end() )
			{
				lookup[ n ] = fib( n - 1, lookup ) + fib( n - 2, lookup );
			}

			return lookup[ n ];
		}
	};

	/* 754. Reach a Number.

	You are standing at position 0 on an infinite number line. There is a goal at position target.

	On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

	Return the minimum number of steps required to reach the destination.

	Example 1:
	Input: target = 3
	Output: 2
	Explanation:
	On the first move we step from 0 to 1.
	On the second step we step from 1 to 3.
	
	Example 2:
	Input: target = 2
	Output: 3
	Explanation:
	On the first move we step from 0 to 1.
	On the second move we step  from 1 to -1.
	On the third move we step from -1 to 2.
	
	Note:
	target will be a non-zero integer in the range [-10^9, 10^9].
	*/

	class reach_a_number
	{
	public:
		static int reach_number( int target )
		{
			target = std::abs( target );
			auto k = 0;

			while( target > 0 )
				target -= ++k;

			return target % 2 == 0 ?
				k :
				k + 1 + k % 2;
		}
	};

	/* 800. Similar RGB Color.

	In the following, every capital letter represents some hexadecimal digit from 0 to f.

	The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

	Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

	Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

	Example 1:
	Input: color = "#09f166"
	Output: "#11ee66"
	Explanation:
	The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
	This is the highest among any shorthand color.
	Note:

	color is a string of length 7.
	color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
	Any answer which has the same (highest) similarity as the best answer will be accepted.
	All inputs and outputs should use lowercase letters, and the output is 7 characters.
	*/

	class similar_color
	{
		static double parse_hex_value( const std::string& color,
			const int offset )
		{
			const auto part = color.substr( offset, 2 );

			return static_cast< double >( std::stoi( "0x" + part, nullptr, 16 ) );
		}

		static std::map<int, std::pair<int, std::string>> build_conversion_map()
		{
			std::map<int, std::pair<int, std::string>> map;

			for( size_t index = 0, step = 0; index < 16; index++, step += 17 )
			{
				const auto offset = index < 10 ? '0' : 'a';
				const auto chr = static_cast< char >( offset ) + ( index > 9 ? index - 10 : index );

				map[ index ] = { step, std::string( 2, chr ) };
			}

			return map;
		}

		static std::string to_hex_color( const std::map<int, std::pair<int, std::string>>& map,
			std::vector<int>& pieces )
		{
			std::string hex_color = "#";

			for( auto piece : pieces )
			{
				hex_color += map.at( piece ).second;
			}

			return hex_color;
		}

	public:

		static std::string similar_rgb( const std::string& color )
		{
			const auto r_part = parse_hex_value( color, 1 );
			const auto g_part = parse_hex_value( color, 3 );
			const auto b_part = parse_hex_value( color, 5 );

			const auto value_map = build_conversion_map();

			std::vector<int> similar_pieces( 3 );
			auto min_val = std::numeric_limits<int>::max();
			const auto iters = value_map.size();

			for( size_t i = 0; i < iters; i++ )
			{
				for( size_t j = 0; j < iters; j++ )
				{
					for( size_t k = 0; k < iters; k++ )
					{
						const int val =
							-std::pow( r_part - value_map.at( i ).first, 2.0 ) -
							std::pow( g_part - value_map.at( j ).first, 2.0 ) -
							std::pow( b_part - value_map.at( k ).first, 2.0 );

						if( std::abs( val ) < min_val )
						{
							min_val = std::abs( val );

							similar_pieces[ 0 ] = i;
							similar_pieces[ 1 ] = j;
							similar_pieces[ 2 ] = k;
						}
					}
				}
			}

			return to_hex_color( value_map, similar_pieces );
		}
	};

	/* 1317. Convert Integer to the Sum of Two No-Zero Integers.

	Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.

	Return a list of two integers [A, B] where:

	A and B are No-Zero integers.
	A + B = n
	It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.



	Example 1:

	Input: n = 2
	Output: [1,1]
	Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
	Example 2:

	Input: n = 11
	Output: [2,9]
	Example 3:

	Input: n = 10000
	Output: [1,9999]
	Example 4:

	Input: n = 69
	Output: [1,68]
	Example 5:

	Input: n = 1010
	Output: [11,999]

	Constraints:

	2 <= n <= 10^4
	*/

	class no_zero_integers
	{
		static bool contains_zero( int num )
		{
			while( num )
			{
				if( num & 0x1 )  // odd?
					num /= 10;

				else  // even
				{
					// just do integer divide, and calculate modulo in next line
					const auto n_next = num / 10;

					// replaces "more expensive" modulo operation with integer multiply and subtraction
					if( ( num - ( 10 * n_next ) ) == 0 )
						return true;

					num = n_next;
				}
			}

			return false;
		}

	public:

		static std::vector<int> getNoZeroIntegers( const int n )
		{
			for( auto i = 1; i < n; ++i )
			{
				const auto left = n - i;

				if( contains_zero( left ) || contains_zero( i ) )
					continue;

				return { i, left };
			}

			return {};
		}
	};

	/*
	1131. Maximum of Absolute Value Expression.

	Given two arrays of integers with equal lengths, return the maximum value of:

	|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

	where the maximum is taken over all 0 <= i, j < arr1.length.

	Example 1:

	Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
	Output: 13
	Example 2:

	Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
	Output: 20


	Constraints:

	2 <= arr1.length == arr2.length <= 40000
	-10^6 <= arr1[i], arr2[i] <= 10^6
	*/

	class maximum_abs
	{

	public:
		static int max_abs_val_expr( const std::vector<int>& arr1, const std::vector<int>& arr2 )
		{
			auto maximum_distance = 0;

			for( auto p : { 1, -1 } )
			{
				for( auto q : { 1, -1 } )
				{
					auto max_val = INT_MIN;
					auto min_val = INT_MAX;

					for( auto index = 0; index < arr1.size(); ++index )
					{
						auto value = arr1[ index ] + p * arr2[ index ] + q * index;

						max_val = std::max( max_val, value );
						min_val = std::min( min_val, value );
					}

					maximum_distance = std::max( maximum_distance, max_val - min_val );
				}
			}

			return maximum_distance;
		}
	};
}
