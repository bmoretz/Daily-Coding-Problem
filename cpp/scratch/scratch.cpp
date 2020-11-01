#include <bits/stdc++.h>

/*286. Walls and Gates.

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

class walls_and_gates
{
    static inline std::vector<std::pair<int, int>> dirs = std::vector<std::pair<int, int>>
    {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    static int mark_distances( std::vector<std::vector<int>>& rooms,
        std::vector<std::pair<int, int>>& gates )
    {
        const int num_rows = rooms.size();
        const int num_cols = rooms[ 0 ].size();

        auto queue = std::queue<std::pair<int, int>>();

    	// push all the locations that are gates on the map
        for( auto& gate : gates )
        {
            queue.push( gate );
        }

    	// now traverse the grid in a breath first
    	// order, so that each empty cell we encounter
    	// will get updated to its distance from the starting
    	// gate
        while( !queue.empty() )
        {
            const auto loc = queue.front();
            const auto current = rooms[ loc.first ][ loc.second ];

            for( const auto dir : dirs )
            {
                const std::pair<int, int> next = 
                {
                	loc.first + dir.first,
                    loc.second + dir.second
                };

                if( next.first < 0 || next.first >= num_rows )
                    continue;

                if( next.second < 0 || next.second >= num_cols )
                    continue;

                if( rooms[ next.first ][ next.second ] != INT_MAX )
                    continue;

                rooms[ next.first ][ next.second ] = rooms[ loc.first ][ loc.second ] + 1;

                queue.push( next );
            }

            queue.pop();
        }

        return INT_MAX;
    }

public:

    static void mark_map( std::vector<std::vector<int>>& rooms )
    {
        if( rooms.empty() || rooms[ 0 ].empty() ) return;

    	// first mark all the locations on the map that are
    	// gates.
        auto gates = std::vector<std::pair<int, int>>();

        for( auto row = 0ULL; row < rooms.size(); ++row )
        {
            for( auto col = 0LL; col < rooms[ 0 ].size(); ++col )
            {
                if( rooms[ row ][ col ] == 0 )
                    gates.emplace_back( row, col);
            }
        }

    	// pass all the locations that are gates
    	// to the mark distances function
        mark_distances( rooms, gates );
    }
};

auto main() -> int
{
    auto input = std::vector<std::vector<int>>{
        { 2147483647, -1, 0, 2147483647 },
        { 2147483647, 2147483647, 2147483647, -1 },
        { 2147483647, -1, 2147483647,-1 },
        { 0, -1, 2147483647, 2147483647 }
	};

    walls_and_gates::mark_map( input );

    const auto expected = std::vector<std::vector<int>>
    {
        { 3,-1,0,1 },
        { 2,2,1,-1 },
        { 1,-1,2,-1 },
        { 0,-1,3,4 }
    };
	
	return 0;
}