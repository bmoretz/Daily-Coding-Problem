#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

constexpr unsigned exponent = 31;
constexpr unsigned two_to_exponent = 1u << exponent;

struct bit_array final : problem
{
	explicit bit_array( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}

	bool solve()
	{
		// set up variables and constants and read input
		unsigned int N, S, P, Q, mu, nu;

		const unsigned int m = 1 << 31;

		std::cin >> N >> S >> P >> Q;

		// set up sequence
		unsigned int* a = new unsigned int[ N ];

		a[ 0 ] = S % m;
		for( int i = 1; i < N; i++ ) 
		{
			a[ i ] = ( a[ i - 1 ] * P + Q ) % m;
		}

		// begin cycle detection (-> floyd's algorithm)
		for( auto i = 0; i < N; i++ ) 
		{
			if( ( 2 * i ) + 1 > N - 1 ) 
			{
				// no cycle found -> N distinct values, output N, clean up and terminate execution
				std::cout << N;
				delete[] a;
				return true;
			}
        	
			if( a[ i ] == a[ ( 2 * i ) + 1 ] ) 
			{
				// cycle detected, break loop to proceed with algorithm
				nu = i + 1;
				break;
			}
		}

		// find first element of cycle
		for( auto i = 0; i < N; i++ )
		{
			if( a[ i ] == a[ i + nu ] ) 
			{
				mu = i;
				break;
			}
		}

		// find first reoccurence of first cycle element
		for( int i = mu + 1; i < N; i++ ) 
		{
			if( a[ mu ] == a[ i ] ) {

				std::cout << i << std::endl;
				break;
			}
		}

		delete[] a;
		
		return false;
	}

	int main()
	{
		return solve();
	}
};

auto main() -> int
{
	const auto problem =
		bit_array{"bitset-1-testcases"};

	return problem.run();
}
