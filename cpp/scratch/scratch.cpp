#include <bits/stdc++.h>
#include <random>
#include <unordered_set>

/* 1091. Shortest Path in Binary Matrix.

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).

Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

Example 1:

Input: [[0,1],[1,0]]

Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]

Output: 4

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1.
*/

class shortest_path_binary_matrix
{

	static std::vector<std::pair<int, int>> get_next_choices()
	{
		return std::vector<std::pair<int, int>>
        {
            { 1, 1 }, { 0, 1 }, { 1, 0 }, { 0, -1 },
            { -1, 0 }, { -1, -1 }, { 1, -1 }, { -1, 1 }
        };
	}
	
public:

	/// <summary>
	/// shortest path
	///
	/// breath first search approach
	/// </summary>
	/// <param name="grid">the grid</param>
	/// <returns></returns>
    static int shortest_path( const std::vector<std::vector<int>>& grid )
    {
        if( grid.empty() ) return 0;

        const auto num_rows = grid.size();
        const auto num_cols = grid[ 0 ].size();

        if( grid[ 0 ][ 0 ] != 0 && grid[ num_rows - 1 ][ num_cols - 1 ] != 1 ) return -1; // no solution is possible

        auto counter = std::vector<std::vector<int>>( num_rows, std::vector<int>( num_cols ) );

        std::queue<std::pair<std::size_t, std::size_t>> queue;

        queue.push( { 0, 0 } );
        counter[ 0 ][ 0 ] = 1;

        while( !queue.empty() )
        {
            const auto [x, y] = queue.front();

            queue.pop();

            if( x == num_rows - 1 && y == num_cols - 1 ) return counter[ x ][ y ];

            for( auto& [nx, ny] : get_next_choices() )
            {
                auto next_x = x + nx;
                auto next_y = y + ny;

                if( next_x >= 0 && next_x < num_rows &&
                    next_y >= 0 && next_y < num_cols &&
                    grid[ next_x ][ next_y ] == 0 )
                {
                    if( counter[ next_x ][ next_y ] ) continue;
                	
                    queue.push( { next_x, next_y } );

                    counter[ next_x ][ next_y ] = counter[ x ][ y ] + 1;
                }
            }
        }

        return -1;
    }
};

auto main() -> int
{
    const auto input1 = std::vector<std::vector<int>>
    {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    const auto input2 = std::vector<std::vector<int>>
    {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    const auto input3 = std::vector<std::vector<int>>
    {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    const auto input4 = std::vector<std::vector<int>>
    {
        {0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0}
    };
	
    const auto steps = shortest_path_binary_matrix::shortest_path( input4 );

    std::cout << steps;
	
    return 0;
}