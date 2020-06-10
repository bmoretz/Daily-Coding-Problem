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

class next_number
{
	static bool get_bit( const int num, const int pos )
	{
		const auto mask = 1 << pos;

		return ( num & mask ) >> pos;
	}

	static int length( const int num )
	{
		return static_cast< int >( std::floor( log2( num ) ) );
	}

	static int next_one( const int num, const int start )
	{
		auto position = start;

		while( get_bit( num, position ) != 1 )
			--position;

		return position;
	}

	static int prev_one( const int num, const int start )
	{
		auto min_one = start;

		for( auto index = start; index < length( num ); ++index )
		{
			const auto mask = 1 << index;

			if( ( num & 1 << index ) == mask )
				break;

			++min_one;
		}

		return min_one;
	}

	static int count_ones( const int num, const int start )
	{
		auto num_ones = 0;

		for( auto index = start; index > -1; index-- )
		{
			const auto mask = 1 << index;

			if( ( num & mask ) == mask )
				num_ones++;
		}

		return num_ones;
	}

	static auto larger( const int num, const int n )
	{
		const auto num_ones = count_ones( num, n - 1 );

		auto next_larger = 0;

		if( get_bit( num, n - 1 ) == 0 && num_ones > 0 )
		{
			const auto exchange_bit = next_one( num, n - 1 );

			next_larger = num ^ 1 << exchange_bit;
			next_larger |= 1 << ( exchange_bit + 1 );
		}
		else
		{
			next_larger = 1 << ( n + 1 );

			for( auto index = 0; index < num_ones; ++index )
				next_larger |= 1 << index;
		}

		return next_larger;
	}

	static auto smaller( const int num, const int n )
	{
		const auto num_ones = count_ones( num, n - 1 );
		const auto num_zeros = n - num_ones;

		// no zeros to switch, this is the smallest
		// number with n 1's.
		if( num_zeros == 0 )
			return num;

		const auto next_zero = next_one( ~num, n - 1 );

		auto next_smallest = 0;

		if( get_bit( num, n - 1 ) == 1 && num_zeros > 0 )
		{
			const auto exchange_bit = next_one( ~num, n - 2 );

			next_smallest = num ^ 1 << ( n - 1 );
			next_smallest |= 1 << exchange_bit;
		}
		else
		{
			next_smallest = num ^ ( 1 << n );
			next_smallest |= 1 << next_zero;
		}
		
		return next_smallest;
	}

public:

	static auto get_next( const int num )
	{
		const auto n = length( num );
		
		return std::make_tuple( smaller( num, n ), larger( num, n ) );
	}
};

auto main() -> int
{
	const auto num = 326;
	
	const auto next = next_number::get_next( num );
	
	std::cout << std::get<0>( next ) << "," << std::get<1>( next );
}