#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <random>
#include <bitset>

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

auto flip_to_win( const int num )
{
	const auto n = static_cast< int >( ceil( log2( num ) ) );
	const auto neg = ~num << 1;

	auto counter = 0;
	auto parts = std::vector<int>();

	const auto debug = std::bitset<11>( neg ).to_string();
	
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

	auto results = std::vector<int>(parts.size() / 2  + 1 );
	
	std::transform(
		parts.begin(), parts.end() - 1,
		parts.begin() + 1,
		std::back_inserter( results ),
		std::plus<>() );

	const auto max_sum = *std::max_element( results.begin(), results.end() );
	
	return  max_sum + 1;
}

auto main() -> int
{
	// const auto num = 1982;
	const auto num = 3221009;
	
	const auto res = flip_to_win( num );

	std::cout << res;
}