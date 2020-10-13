#include <bits/stdc++.h>

#include "../leetcode/tree.h"
using namespace leetcode::tree;

/* 675. Cut Off Trees for Golf Event.

You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.

The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
In one step you can walk in any of the four directions top, bottom, left and right also when standing in a point which is a tree you
can decide whether or not to cut off the tree.

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And
after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't
cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:

Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
 

Example 2:

Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
 

Example 3:

Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
 

Constraints:

1 <= forest.length <= 50
1 <= forest[i].length <= 50
0 <= forest[i][j] <= 10^9
*/

class trim_forest {

    static inline std::vector<int> all_dirs = { -1, 0, 1, 0, -1 };

    static int next_step( const std::vector<std::vector<int>>& forest,
        const int row, const int col,
        const int prev_row, const int prev_col )
    {
        if( row == prev_row && col == prev_col ) return 0;

        const auto num_rows = forest.size();
        const auto num_cols = forest[ 0 ].size();

        auto queue = std::queue<std::pair<int, int>>();

        queue.push( { row, col } );

        auto visited = std::vector<std::vector<int>>( num_rows, std::vector<int>( num_cols, 0 ) );

        visited[ row ][ col ] = 1;

        auto step = 0;

        while( !queue.empty() )
        {
            ++step;

            const auto sz = queue.size();

            for( auto index = 0; index < sz; ++index )
            {
                const auto [cur_row, cur_col] = queue.front();
                queue.pop();

                for( auto dir = 0; dir < 4; ++dir )
                {
                    auto next_row = cur_row + all_dirs[ dir ],
                        next_col = cur_col + all_dirs[ dir + 1 ];

                    if( next_row < 0 || next_row >= num_rows ) continue;
                    if( next_col < 0 || next_col >= num_cols ) continue;
                    if( visited[ next_row ][ next_col ] == 1 || forest[ next_row ][ next_col ] == 0 ) continue;

                    if( next_row == prev_row && next_col == prev_col )
                        return step;

                    visited[ next_row ][ next_col ] = 1;
                    queue.push( { next_row, next_col } );
                }

            }
        }

        return -1;
    }

public:

    static int cut_off_trees( const std::vector<std::vector<int>>& forest )
    {
        if( forest.empty() || forest[ 0 ].empty() ) return 0;

        const auto num_rows = forest.size();
        const auto num_cols = forest[ 0 ].size();

        auto trees = std::vector<std::vector<int>>();

        for( auto row = 0; row < num_rows; ++row )
        {
            for( auto col = 0; col < num_cols; ++col )
            {
                const auto tree_size = forest[ row ][ col ];

                if( tree_size > 1 )
                {
                    trees.push_back( { tree_size, row, col } );
                }
            }
        }

        std::sort( trees.begin(), trees.end() );

        auto answer = 0;

        for( auto index = 0, cur_row = 0, cur_col = 0;
            index < trees.size(); ++index )
        {
            const auto cur_tree = trees[ index ];
            const auto step = next_step( forest,
                cur_row, cur_col, 
                cur_tree[ 1 ], cur_tree[ 2 ] );

            if( step == -1 )
                return -1;

            answer += step;

            cur_row = cur_tree[ 1 ];
            cur_col = cur_tree[ 2 ];
        }

        return answer;
    }
};

auto main() -> int
{
    const auto input = std::vector<std::vector<int>>
    {
        {1, 2, 3},
        {0, 0, 4},
        {7, 6, 5}
    };
	
    const auto actual = trim_forest::cut_off_trees( input );
	
    const auto expected = 6;
	
	return 0;
}