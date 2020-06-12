#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <random>
#include <bitset>
#include <string>

/* Pairwise Swap.
 *
 * Write a program to swap odd and even bits in an integer with as
 * few instructions as possible (e.g., bit 0 and bit 1 are swapped,
 * bit 22 and bit 3 are swapped, and so on).
 */

auto pairwise_swap( const int num )
{
	// masks to get the odd/even numbers in the digit, i.e,
	 
	// BIN: 01010101010101010101010101010101
	static const auto even_mask = 0xaaaaaaaa;
	// BIN: 10101010101010101010101010101010
	static const auto odd_mask = 0x55555555;

	return ( ( num & even_mask ) >> 1 ) | ( ( num & odd_mask ) << 1 );
}

auto main() -> int
{
	const auto num = 120528;

	const auto res = pairwise_swap( num );
	
	const auto num_str = std::bitset<31>( num ).to_string();
	const auto res_str = std::bitset<31>( res ).to_string();
	
	std::cout << num_str << std::endl << res_str << std::endl << res;
}