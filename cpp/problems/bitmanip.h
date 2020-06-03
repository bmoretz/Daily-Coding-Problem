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
	inline auto insertion1( const int n, const int m, const int i, const int j )
	{
		const auto length = static_cast< int >( log2( n ) );
		const auto mid = i + j - 1;
		const auto top = ( n >> mid ) << mid;

		const auto nm = top | m << i;

		const auto bottom = n & static_cast< int >( pow( 2, i ) );

		const auto combined = nm | bottom;

		return combined;
	}

}