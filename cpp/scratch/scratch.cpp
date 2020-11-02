#include <bits/stdc++.h>

/*200. Number of Islands.

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


Example 1:4

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

class num_islands_queue
{
    static inline std::vector<std::pair<int, int>> dirs = std::vector<std::pair<int, int>>
    {
        { 0, -1 }, { 0, 1}, {1, 0}, {-1, 0}
    };

    static void map_connected( std::vector<std::vector<std::string>>& grid,
        const int row, const int col )
    {
        const auto num_rows = grid.size();
        const auto num_cols = grid[ 0 ].size();

        auto queue = std::queue<std::pair<int, int>>();

        grid[ row ][ col ] = "0";
        queue.push( std::make_pair( row, col ) );

        while( !queue.empty() )
        {
            const auto loc = queue.front();
            queue.pop();

            for( const auto& dir : dirs )
            {
                const auto next = std::make_pair(
                    loc.first + dir.first,
                    loc.second + dir.second
                );

                if( next.first < 0 || next.first >= num_rows ||
                    next.second < 0 || next.second >= num_cols )
                    continue;

                if( grid[ next.first ][ next.second ] == "0" )
                    continue;

                grid[ next.first ][ next.second ] = "0";
                queue.push( next );
            }
        }
    }

public:

    static int numIslands( std::vector<std::vector<std::string>> grid )
    {
        if( grid.empty() || grid[ 0 ].empty() ) return 0;

        auto num_islands = 0;

        for( auto row = 0; row < grid.size(); ++row )
        {
            for( auto col = 0; col < grid[ 0 ].size(); ++col )
            {
                if( grid[ row ][ col ] == "1" )
                {
                    num_islands++;
                    map_connected( grid, row, col );
                }
            }
        }

        return num_islands;
    }
};

auto main() -> int
{
    auto input = std::vector<std::vector<std::string>>
	{
        {"1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","0","1","0","1","1"},
        {"0","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","0"},
        {"1","0","1","1","1","0","0","1","1","0","1","1","1","1","1","1","1","1","1","1"},
        {"1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
        {"1","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
        {"1","0","1","1","1","1","1","1","0","1","1","1","0","1","1","1","0","1","1","1"},
        {"0","1","1","1","1","1","1","1","1","1","1","1","0","1","1","0","1","1","1","1"},
        {"1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","1","1"},
        {"1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1"},
        {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
        {"0","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1"},
        {"0","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1"}
	};

    num_islands_queue::numIslands( input );
	
    const auto expected = 1;
	
	return 0;
}