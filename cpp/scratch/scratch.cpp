#include <bits/stdc++.h>
#include <array>

/* 343. Integer Break.

Given a positive integer n, break it into the sum of at least two positive integers
and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/

class integer_break
{
public:

	static int break_int( const int n )
	{
		if( n <= 2 ) return 1;

		std::vector<int> memo( n + 1, 0 );

		memo[ 1 ] = 0;
		memo[ 2 ] = 1;

		for( auto i = 3; i <= n; ++i )
		{
			for( auto j = 1; j < i; ++j )
			{
				const auto s1 = j * ( i - j );
				const auto s2 = j * memo[ i - j ];
				const auto sln = std::max( s1, s2 );
				
				memo[ i ] = std::max( memo[ i ], sln );
			}
		}

		return memo[ n ];
	}
};

auto main() -> int
{
	const auto input1 = 10;
	const auto input2 = 36;

	const auto input3 = std::vector<int>
	{
		1, 2
	};
	
	const auto result = integer_break::break_int( input1 );
	
	return 0;
}