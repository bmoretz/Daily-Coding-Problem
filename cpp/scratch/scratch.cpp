#include <bits/stdc++.h>

/* 694. Number of Distinct Islands.

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally
(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be
translated (and not rotated or reflected) to equal the other.

Example 1:

	11000
	11000
	00011
	00011

Given the above grid map, return 1.

Example 2:
	11011
	10000
	00001
	11011

Given the above grid map, return 3.

Notice that:
	11
	1
	and
	 1
	11

are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class distinct_islands
{
	/// <summary>
	/// using depth first search to explore an island and save its exploration path.
	/// </summary>
	/// <param name="grid">grid to search</param>
	/// <param name="visited">visited cells</param>
	/// <param name="row">row</param>
	/// <param name="col">column</param>
	/// <param name="path">current path</param>
	/// <param name="direction">direction to explore</param>
	static void explore(
		const std::vector<std::vector<int>>& grid,
		std::vector<std::vector<bool>>& visited,
		const int row, const int col,
		std::string& path, const char direction )
	{
		const auto num_rows = grid.size();
		const auto num_cols = grid[ 0 ].size();

		if( row < 0 || row >= num_rows ||
			col < 0 || col >= num_cols ||
			visited[ row ][ col ] || grid[ row ][ col ] == 0 )
		{
			path.push_back( 'f' );
			return;
		}

		visited[ row ][ col ] = true;
		path.push_back( direction );

		explore( grid, visited, row - 1, col, path, 'u' );
		explore( grid, visited, row + 1, col, path, 'd' );
		explore( grid, visited, row, col - 1, path, 'l' );
		explore( grid, visited, row, col + 1, path, 'r' );
	}

public:
	/// <summary>
	/// dfs method for counting the number of unique islands.
	/// </summary>
	/// <param name="grid">grid of islands</param>
	/// <returns>number of distinct islands.</returns>
	static int num_distinct_islands( const std::vector<std::vector<int>>& grid )
	{
		if( grid.empty() || grid[ 0 ].empty() ) return 0;

		const auto num_rows = grid.size();
		const auto num_cols = grid[ 0 ].size();
		
		auto visited = std::vector<std::vector<bool>>( num_rows, 
			std::vector<bool>( num_cols, false ) );
		
		auto islands = std::set<std::string>();

		for( auto row = std::size_t(); row < num_rows; ++row )
		{
			for( auto col = std::size_t(); col < num_cols; col++ )
			{
				if( grid[ row ][ col ] == 1 )
				{
					std::string path;

					explore( grid, visited, row, col, path, 'o' );

					if( path != "f" )
						islands.insert( path );
				}
			}
		}

		return islands.size();
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::vector<int>>
	{
		{ 1, 1, 0, 0, 0 },
		{ 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 1, 1 }
	};
	
	const auto input2 = std::vector<std::vector<int>>
	{
		{ 1, 1, 0, 1, 1 },
		{ 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 0, 1, 1 }
	};
	
    // const auto actual = word_break::wordBreak( input2.first, input2.second );
	const auto actual = distinct_islands::num_distinct_islands( input2 );
	
    return 0;
}