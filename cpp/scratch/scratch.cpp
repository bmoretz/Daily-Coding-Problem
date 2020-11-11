#include <bits/stdc++.h>

/*77. Combinations.

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
*/

class combinations
{
    static void combine( std::vector<int>& vec,
        const int index,
        const int start,
        const int N,
        const int K,
        std::vector<std::vector<int>>& results )
    {
        if( index == K )
        {
            results.emplace_back( vec.begin(), vec.end() );
            return;
        }

        for( auto n = start; n <= N; ++n )
        {
            vec.push_back( n );

            combine( vec, index + 1, n + 1, N, K, results );

            vec.erase( vec.begin() + index );
        }
    }

public:

    static std::vector<std::vector<int>> combine( const int N, const int K )
    {
        std::vector<std::vector<int>> results;

        auto temp = std::vector<int>();
    	
        combine( temp, 0, 1, N, K, results );

        return results;
    }
};

auto main() -> int
{
    auto actual = combinations::combine( 4, 2 );

    const auto expected = std::vector<std::vector<int>>
    {
        { {1,2}, { 1,3 }, { 1,4 }, { 2,3 }, { 2,4 }, { 3,4 } }
    };
	
	return 0;
}