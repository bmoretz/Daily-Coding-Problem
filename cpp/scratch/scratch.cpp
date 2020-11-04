#include <bits/stdc++.h>

/* 542. 01 Matrix.

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1. 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
 
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 
Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

class binary_matrix
{
    struct point
    {
        int x, y;

        point( const int _x, const int _y )
            : x{ _x }, y{ _y }
        {}

        point operator+( const point other ) const
        {
            return point( x + other.x, y + other.y );
        }
    };

    static inline std::vector<point> directions = {
        {0, -1}, {0, 1}, {1, 0}, {-1, 0}
    };

    static void calculate_distances( const std::vector<std::vector<int>>& matrix,
        std::queue<point>& to_search,
        std::vector<std::vector<int>>& distances )
    {
        const int num_rows = matrix.size();
        const int num_cols = matrix[ 0 ].size();

        while( !to_search.empty() )
        {
            const auto loc = to_search.front();
            to_search.pop();

            for( auto dir : directions )
            {
                const auto next = loc + dir;

                if( next.x < 0 || next.x >= num_rows ||
                    next.y < 0 || next.y >= num_cols )
                    continue;

                if( distances[ next.x ][ next.y ] > distances[ loc.x ][ loc.y ] + 1 )
                {
                    distances[ next.x ][ next.y ] = distances[ loc.x ][ loc.y ] + 1;
                    to_search.push( next );
                }
            }
        }
    }

public:

    static std::vector<std::vector<int>> update_matrix( const std::vector<std::vector<int>>& matrix )
    {
        if( matrix.empty() || matrix[ 0 ].empty() ) return matrix;

        const int num_rows = matrix.size();
        const int num_cols = matrix[ 0 ].size();

        auto to_search = std::queue<point>();
        auto distances = std::vector<std::vector<int>>( num_rows, std::vector<int>( num_cols, INT_MAX ) );

        for( auto row = 0; row < num_rows; ++row )
        {
            for( auto col = 0; col < num_cols; ++col )
            {
                if( matrix[ row ][ col ] == 0 )
                {
                    to_search.push( { row, col } );
                    distances[ row ][ col ] = 0;
                }
            }
        }

        calculate_distances( matrix, to_search, distances );

        return distances;
    }
};

auto main() -> int
{
    auto input = std::vector<std::vector<int>>
    {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 1, 1, 1 }
    };
	
    auto actual = binary_matrix::update_matrix( input );
	
    auto expected = std::vector<std::vector<int>>
    {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 1, 2, 1 }
    };
	
	return 0;
}