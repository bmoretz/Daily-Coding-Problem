#pragma once

#include <algorithm>
#include <queue>
#include <vector>

namespace leetcode::matrix
{
	/* 240. Search a 2D Matrix II.

	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

	Integers in each row are sorted in ascending from left to right.
	Integers in each column are sorted in ascending from top to bottom.
	Example:

	Consider the following matrix:

	[
	  [1,   4,  7, 11, 15],
	  [2,   5,  8, 12, 19],
	  [3,   6,  9, 16, 22],
	  [10, 13, 14, 17, 24],
	  [18, 21, 23, 26, 30]
	]

	Given target = 5, return true.
	Given target = 20, return false.
	*/

	struct matrix_search_ii
	{
		/// <summary>
		/// matrix search
		///
		/// straight forward approach that searches a matrix for the target value.
		/// </summary>
		/// <param name="matrix">the matrix to search</param>
		/// <param name="target">target value</param>
		/// <returns>true if the value is in the matrix.</returns>
		static bool search_matrix( const std::vector<std::vector<int>>& matrix, const int target )
		{
			for( const auto& row : matrix )
			{
				if( row.empty() || row.at( 0 ) > target )
					continue;

				if( std::binary_search( row.begin(), row.end(), target ) )
					return true;
			}

			return false;
		}
	};

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

		/// <summary>
		/// number of islands
		///
		/// returns the number of connected components in the matrix.
		/// </summary>
		/// <param name="grid">the grid to search</param>
		/// <returns>number of connected components</returns>
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
}