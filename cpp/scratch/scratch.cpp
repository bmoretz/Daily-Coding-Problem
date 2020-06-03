#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <random>
#include <bitset>

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

auto insertion1( const int n, const int m, const int i, const int j )
{
	const auto length = static_cast<int>( log2( n ) );
	const auto mid = i + j - 1;
	const auto top = ( n >> mid ) << mid;
	
	const auto nm = top | m << i;

	const auto bottom = n & static_cast<int>( pow(2, i ) );
	
	const auto combined = nm | bottom;

	return combined;
}

auto main() -> int
{
	const auto n = 1024;
	const auto m = 19;

	const auto res = insertion1( n, m, 2, 6 );
	
	auto nb = std::bitset<16>( res ).to_string();
}