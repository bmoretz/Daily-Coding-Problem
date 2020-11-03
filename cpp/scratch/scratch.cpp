#include <bits/stdc++.h>

/*200. Number of Islands.

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

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

class num_islands_dfs
{
    struct point
    {
        int row, col;

        point( const int x, const int y )
            : row{ x }, col{ y }
        { }

        point operator+( const point& other ) const
        {
            return point( row + other.row, col + other.col );
        }
    };

    std::vector<point> directions = std::vector<point>
    {
        { 0, -1 }, {0, 1}, {-1, 0}, {1, 0}
    };

    void map_connected( const std::vector<std::vector<char>>& grid,
        std::vector<std::vector<bool>>& visited,
        const int row, const int col )
    {
        const int num_rows = grid.size();
        const int num_cols = grid[ 0 ].size();

        visited[ row ][ col ] = true;

        auto stack = std::stack<point>();
        stack.push( { row, col } );

        while( !stack.empty() )
        {
            const auto cur = stack.top();
            stack.pop();

            visited[ cur.row ][ cur.col ] = true;

            for( auto dir : directions )
            {
                auto next = cur + dir;

                if( next.row < 0 || next.row >= num_rows ||
                    next.col < 0 || next.col >= num_cols )
                    continue;

                if( visited[ next.row ][ next.col ] ||
                    grid[ next.row ][ next.col ] == '0' )
                    continue;

                stack.push( next );
            }
        }
    }

public:

    int num_islands( const std::vector<std::vector<char>>& grid )
    {
        if( grid.empty() || grid[ 0 ].empty() ) return 0;

        const int num_rows = grid.size();
        const int num_cols = grid[ 0 ].size();

        auto visited = std::vector<std::vector<bool>>
            ( grid.size(), std::vector<bool>( grid[ 0 ].size(), false ) );

        auto num_islands = 0;

        for( int row = 0; row < num_rows; ++row )
        {
            for( auto col = 0; col < num_cols; ++col )
            {
                if( !visited[ row ][ col ] && grid[ row ][ col ] == '1' )
                {
                    ++num_islands;
                    map_connected( grid, visited, row, col );
                }
            }
        }

        return num_islands;
    }
};

auto main() -> int
{
    auto actual = evaluate_rpn::eval_rpn( { "2","1","+","3","*" } );
    auto expected = 6;
		
	return 0;
}