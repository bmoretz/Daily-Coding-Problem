#pragma once

#include <vector>

namespace bitmanip_problems
{
	/* Insertion.
	 *
	 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
	 * Write a method to insert M into N such that M starts at bit j and ends at
	 * bit i. You can assume that the bits j through i have enough space to fit all of M.
	 * That is, if M = 10011, you can assume that there are at least 5 bit between j and
	 * i. You would not, for example, have j = 3 and i = 2, because M could not fully fit
	 * between bit 3 and bit 2.
	 *
	 * EXAMPLE:
	 *
	 * Input: N = 10000000000, M = 10011, i = 2, j = 6
	 * Output: M = 10001001100
	 */

	/// <summary>
	/// insertion 1
	///
	/// this approach finds the number of digits in n, saves the top value by
	/// shifting n down by the length - the length of the middle (j + i). Then
	/// we can simply combine n and m into one binary string by shifting the top
	/// up by its length and or'ing it together with m. Finally, we extract the bottom
	/// (bits 0 - i), by and'ing it with 2^i, and then the result is just the OR result
	/// of these two.
	/// </summary>
	/// <param name="n">first (master) binary digit</param>
	/// <param name="m">second binary digit (to be inserted)</param>
	/// <param name="i">index of where m should start in n</param>
	/// <param name="j">index of where m should end in m</param>
	/// <returns>n + m inserted at positions i-j</returns>
	static auto insertion1( const int n, const int m, const int i, const int j )
	{
		// total number of bits.
		const auto length = static_cast< int >( log2( n ) );
		// length of the middle
		const auto mid = i + j - 1;
		// split out the top: n|0's
		const auto top = ( n >> mid ) << mid;

		// n|m|0's
		const auto nm = top | m << i;

		// 0's|n
		const auto bottom = n & static_cast< int >( pow( 2, i ) );

		// n|m|n
		const auto combined = nm | bottom;

		return combined;
	}

	/* Binary to String.
	 *
	 * Given a real number between 0 and 1 (e.g., 0.72) that is passed in as
	 * a double, print the binary representation. If the number cannot be
	 * represented accurately in binary with at most 32 characters, print
	 * "ERROR".
	 */

	/// <summary>
	/// decimal to binary (string)
	///
	/// this approach just converts the decimal (float) number to its base 10
	/// (decimal) representation by dividing it by .1f and checking if the delta
	/// is < epsilon (error threshold). Once we have a decimal number, the number
	/// of binary digits = log2( N ), so we start there and for each power of 2
	/// that is less than the number, we put a 1 in that digits place, and then
	/// subtract that amount from the base 10. Continue until we have no digits
	/// left to examine.
	/// </summary>
	/// <param name="dec">floating point number</param>
	/// <returns>binary string representation.</returns>
	static auto dec_to_bin( const std::float_t dec )
	{
		// must be in range (0,1)
		if( dec >= 1 || dec <= 0 )
			return std::string( "ERROR" );

		// convert to base 10
		auto n = dec, rem = dec;
		const auto epsilon = 0.1e-30;

		while( rem > epsilon )
		{
			n /= 0.1f;
			rem = n - static_cast< int >( n );  // NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions)
		}

		auto n_digits = std::ceil( log2( n ) );

		// must be 0 <= length <= 32 digits.
		if( n_digits < 0 || n_digits > 32 )
			return std::string( "ERROR" );

		auto result = std::string( "." );

		while( n_digits )
		{
			const auto cur = static_cast< int >( pow( 2, n_digits ) );

			if( n >= cur )
			{
				result += "1";
				n -= cur;
			}
			else
			{
				result += "0";
			}

			--n_digits;
		}

		return result;
	}

	/* Flip Bit to Win.
	 *
	 * You have an integer and you can flip exactly one bit from a
	 * 0 to 1. Write code to find the lengths of the longest sequence
	 * of 1's you could create.
	 *
	 * EXAMPLE:
	 *
	 * Input: 1755 (or: 11011101111)
	 * Output: 8
	 */

	/// <summary>
	/// flip bit to win
	///
	/// This approach first calculates how many digits we are working with,
	/// (n), and then we negate the binary of the passed in number (we shift the
	/// negation to ensure the loop captures the last 1 if the bit is set). Then we
	/// iterate over the digits (0->n) until we find a 1 in the negation,
	/// this will give us the length of all the distinct groups in the passed
	/// in number. Once we have this, we can calculate the distinct adjacent
	/// sums (std::transform). The result will be the max adjacent sum + 1 (for
	/// the flipped bit to join them).
	/// </summary>
	/// <complexity>
	/// O(n) where n = # of digits in the number.
	/// </complexity>
	/// <param name="num">binary digits to work with</param>
	/// <returns>max adjacent sum by flipping a bit (0 -> 1)</returns>
	static auto flip_to_win( const int num )
	{
		const auto n = static_cast< int >( ceil( log2( num ) ) );
		const auto neg = ~num << 1;

		auto counter = 0;
		auto parts = std::vector<int>();

		for( auto index = 0; index < n; ++index )
		{
			const auto mask = 1 << ( n - index );

			if( ( neg & mask ) == mask )
			{
				parts.push_back( counter );
				counter = 0;
			}
			else
			{
				++counter;
			}
		}

		parts.push_back( counter );

		auto results = std::vector<int>( parts.size() / 2 + 1 );

		std::transform(
			parts.begin(), parts.end() - 1,
			parts.begin() + 1,
			std::back_inserter( results ),
			std::plus<>() );

		const auto max_sum = *std::max_element( results.begin(), results.end() );

		return  max_sum + 1;
	}
}