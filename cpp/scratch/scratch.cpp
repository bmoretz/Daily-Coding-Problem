#include <bits/stdc++.h>

/*370. Range Addition.

Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray
A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
Explanation:

Initial state:
[0,0,0,0,0]

After applying operation [1,3,2]:
[0,2,2,2,0]

After applying operation [2,4,3]:
[0,2,5,5,3]

After applying operation [0,2,-2]:
[-2,0,3,5,3]
*/

class range_addition
{

public:

    static std::vector<int> get_modified_array( const int length, 
        const std::vector<std::vector<int>>& updates )
    {
        auto result = std::vector<int>( length );

        for( auto& op : updates )
        {
            const auto start = op[ 0 ], stop = op[ 1 ], inc = op[ 2 ];

            result[ start ] += inc;

            if( stop < length - 1 )
                result[ stop + 1 ] -= inc;
        }

        std::partial_sum( result.begin(), result.end(), result.begin() );

        return result;
    }
};

auto main() -> int
{
    const auto operations = std::vector<std::vector<int>>{
        {1,3,2}, {2,4,3}, {0,2,-2}
    };
	
    auto actual = range_addition::get_modified_array( 5, operations );
    auto expected = std::vector<int> { -2, 0, 3, 5, 3 };
	
	return 0;
}