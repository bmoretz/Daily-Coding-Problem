#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <random>
#include <bitset>
#include <string>

/* Conversion:
 *
 * Write a function to determine the number of bits you would
 * need to flip to convert integer A to integer B.
 *
 * EXAMPLE:
 *
 * Input: 29 (or: 11101), 15 (or: 01111)
 * Output: 2
 */

auto conversion( const int a, const int b )
{
	const auto need_changed = ~( a & b );
	const auto digits = std::ceil( log2( std::max( a, b) ) );
	
	auto ctr = 0;
	
	for( auto index = 0; index < digits; ++index )
	{
		const auto mask = 1 << index;

		if( ( need_changed & ( 1 << index ) ) == mask )
			++ctr;
	}

	return ctr;
}

auto main() -> int
{
	const auto a = 126, b = 5;

	const auto res = conversion( a, b );

	std::cout << res;
}