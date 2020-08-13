#include <bits/stdc++.h>
#include <random>

/* 200. Number of Islands.

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by
connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

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
*/

class number_of_islands
{
public:

	/// <summary>
	/// connected
	///
	/// does a dfs on the grid and visits all the nodes that are connected to the
	/// passed in index.
	/// </summary>
	/// <param name="grid">the grid</param>
	/// <param name="visited">visited markers</param>
	/// <param name="row">row index</param>
	/// <param name="column">column index</param>
	static void connected( const std::vector<std::vector<char>>& grid,
		std::vector<std::vector<bool>>& visited,
		const std::size_t row, const std::size_t column )
	{
		const auto rows = grid.size();
		const auto columns = grid[ 0 ].size();

		if( row < 0 || row >= rows || column < 0 || column >= columns ||
			visited[ row ][ column ] || grid[ row ][ column ] == '0' ) return;

		visited[ row ][ column ] = true;

		connected( grid, visited, row + 1, column );
		connected( grid, visited, row - 1, column );
		connected( grid, visited, row, column + 1 );
		connected( grid, visited, row, column - 1 );
	}

	static int num_islands( const std::vector<std::vector<char>>& grid )
	{
		if( grid.empty() ) return 0;
		if( grid[ 0 ].empty() ) return 0;

		auto visited = std::vector<std::vector<bool>>(
			grid.size(),
			std::vector<bool>( grid[ 0 ].size() )
		);

		auto islands = 0;

		for( auto row = std::size_t(); row < grid.size(); ++row )
		{
			for( auto column = std::size_t(); column < grid[ 0 ].size(); ++column )
			{
				if( grid[ row ][ column ] == '1' && !visited[ row ][ column ] )
				{
					islands++;
					connected( grid, visited, row, column );
				}
			}
		}

		return islands;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::vector<char>>
	{
		{ '1', '1', '1', '1', '0' },
		{ '1', '1', '0', '1', '0' },
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '0', '0', '0' }
	};

	const auto input2 = std::vector<std::vector<char>>
	{
		{ '1', '1', '0', '0', '0' },
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '1', '0', '0' },
		{ '0', '0', '0', '1', '1' }
	};
	
	const auto result = number_of_islands::num_islands( input2 );

	std::cout << result << std::endl;
	
	return 0;
}
