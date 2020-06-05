#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <random>
#include <bitset>

/* Binary to String.
 *
 * Given a real number between 0 and 1 (e.g., 0.72) that is passed in as
 * a double, print the binary representation. If the number cannot be
 * represented accurately in binary with at most 32 characters, print
 * "ERROR".
 */

auto dec_to_bin( const std::float_t dec )
{
	// must in in range (0,1)
	if( dec >= 1 || dec <= 0 )
		return std::string("ERROR");
	
	// convert to base 10
	auto n = dec, rem = dec;
	const auto epsilon = 0.1e-30;

	while( rem > epsilon )
	{
		n /= 0.1f;
		rem = n - static_cast< int >( n );  // NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions)
	}
	
	auto n_digits = std::ceil( log2( n ) );

	// must in in range (0,1)
	if( n_digits < 0 || n_digits > 32 )
		return std::string( "ERROR" );

	auto result = std::string(".");
	
	while( n_digits >= 0 )
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

auto main() -> int
{
	const auto n = 0.1e-12;

	auto res = dec_to_bin( n );

	std::cout << res;
}