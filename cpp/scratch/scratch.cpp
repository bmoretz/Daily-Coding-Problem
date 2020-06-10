#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <random>
#include <bitset>
#include <string>

/* Next Number.
 *
 * Given a positive integer, print the next smallest and the next
 * largest number that have the same number of 1 bits in their
 * binary representation.
 */

auto next_number( const int num )
{
	const auto neg = ~num;
	auto max_one = static_cast< int >( std::floor( log2( num ) ) );

	// find the position of largest index which contains a 1
	while( true )
	{
		const auto mask = 1 << max_one;

		if( ( mask & num ) == mask )
			break;

		--max_one;
	}

	// find the smallest index position which contains a 1
	auto smallest_one = 0;

	while( ( neg & 1 << smallest_one ) == 1 << smallest_one )
		++smallest_one;

	// the next largest number will swap the smallest 1 with the
	// position that contains the next zero after the smallest 1
	auto next_zero = smallest_one + 1;

	while( ( num & 1 << next_zero ) == 1 << next_zero )
		++next_zero;
	
	const auto next_largest = ( num ^ 1 << smallest_one ) | 1 << next_zero;

	// the next smallest will move the next one (or, the only one iff only 1)
	// down into the place of the maximum zero position. If there are no zeros
	// between the largest one and the end (i.e., 1111) then we already have
	// the smallest possible digit with n 1's, so just use it.
	auto next_one = max_one - 1;

	while( ( num & 1 << next_one ) != 1 << next_one )
		--next_one;

	auto smallest_zero = 0;

	while( ( neg & 1 << smallest_zero ) != 1 << smallest_zero )
		smallest_zero++;

	auto next_smallest = 0;

	if( next_one == smallest_one )
	{
		// all the binary positions are 1's, we
		// can't change any positions and and get
		// a smaller number with the same amount of 1's
		next_smallest = num;
	}
	else if( next_one < 0 )
	{
		// there is only one 1 in the binary representation,
		// just move it down one position.
		next_smallest = 1 << ( max_one - 1 );
	}
	else if( next_one < next_zero )
	{
		// there is no space in the beginning to move a digit down,
		// so we have to move the most significant digit down 1 place.
		next_smallest = ( num ^ 1 << max_one ) | 1 << next_zero;
	}
	else
	{
		// finally, base case is swap the next 1 with the smallest zero
		next_smallest = ( num ^ 1 << next_one ) | 1 << smallest_zero;
	}
	
	return std::make_tuple( next_smallest, next_largest );
}

auto main() -> int
{
	const auto num = 24;

	const auto next = next_number( num );
	
	std::cout << std::get<0>( next ) << "," << std::get<1>( next );
}