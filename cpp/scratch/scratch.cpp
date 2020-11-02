#include <bits/stdc++.h>

/*279. Perfect Squares.

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

class perfect_squares
{
public:

    static int num_squares( const int num )
    {
        auto squares = std::vector<int>();

        for( auto index = 1; index * index <= num; ++index )
            squares.push_back( index * index );

        auto dp = std::vector<int>( num + 1 );
        dp[ 0 ] = 0;

        for( auto index = 1; index <= num; ++index )
        {
            auto min = INT_MAX;

            for( auto square : squares)
            {
                if(square <= index )
                {
                    min = std::min( dp[ index - square] + 1, min );
                }

                dp[ index ] = min;
            }
        }

        return dp[ num ];
    }
};

auto main() -> int
{
    auto actual = perfect_squares::num_squares( 12 );
	
    const auto expected = 3;
	
	return 0;
}