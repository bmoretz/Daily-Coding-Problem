#include <bits/stdc++.h>
#include <array>

/* 994. Rotting Oranges.

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/

class rotting_oranges
{
	static std::pair<std::queue<std::pair<int, int>>, int> take_inventory( const std::vector<std::vector<int>>& grid )
	{
		const auto num_rows = grid.size();
		const auto num_cols = grid[ 0 ].size();

		std::queue<std::pair<int, int>> rotten;
		auto num_fresh = 0;

		for( auto row = 0; row < num_rows; ++row )
		{
			for( auto col = 0; col < num_cols; ++col )
			{
				if( grid[ row ][ col ] == 2 )
				{
					rotten.push( { row, col } );
				}
				else if( grid[ row ][ col ] == 1 )
				{
					++num_fresh;
				}
			}
		}

		return { rotten, num_fresh };
	}

public:

	static int orangesRotting( std::vector<std::vector<int>>& grid )
	{
		if( grid.empty() || grid[ 0 ].empty() ) return 0;

		const auto num_rows = grid.size();
		const auto num_cols = grid[ 0 ].size();

		auto [rotten, fresh] = take_inventory( grid );

		const auto directions = std::vector<std::pair<int, int>>{
			{ 0, -1 }, { 0, 1 },
			{ -1, 0 }, { 1, 0 }
		};

		auto num_minutes = 0;

		while( !rotten.empty() && fresh > 0 )
		{
			num_minutes++;

			auto iter = rotten.size();

			while( iter-- > 0 )
			{
				const auto& [row, col] = rotten.front();

				for( auto& direction : directions )
				{
					const auto [next_row, next_col] = std::pair<int, int>{
						row + direction.first,
						col + direction.second
					};

					if( next_row >= 0 && next_row < num_rows &&
						next_col >= 0 && next_col < num_cols &&
						grid[ next_row ][ next_col ] == 1 )
					{
						grid[ next_row ][ next_col ] = 2;
						--fresh;

						rotten.push( { next_row, next_col } );
					}
				}

				rotten.pop();
			}
		}

		return fresh == 0 ? num_minutes : -1;
	}
};

auto main() -> int
{
	auto input1 = std::vector<std::vector<int>>
	{
		{ 2, 1, 1 },
		{ 1, 1, 0 },
		{ 0, 1, 1 }
	};

	auto input3 = std::vector<std::vector<int>>
	{
		{ 0, 1 }
	};

	auto input4 = std::vector<std::vector<int>>
	{
		{ { 1 }, { 2 } }
	};
	
	const auto result = rotting_oranges::orangesRotting( input4 );
	
	return 0;
}