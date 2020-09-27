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

		static bool is_valid( const std::vector<std::vector<int>>& grid,
			const int next_x, const int next_y )
		{
			const int num_rows = grid.size();
			const int num_cols = grid[ 0 ].size();

			const auto valid_row = next_x >= 0 && next_x < num_rows;
			
			if( !valid_row ) return false;
		
			const auto valid_column = next_y >= 0 && next_y < num_cols;
			
			if( !valid_column ) return false;
			
			return grid[ next_x ][ next_y ] == 0;
		}

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

			// no solution is possible
			if( grid[ 0 ][ 0 ] != 0 && grid[ num_rows - 1 ][ num_cols - 1 ] != 1 ) return -1;

			auto counter = std::vector<std::vector<int>>( num_rows, std::vector<int>( num_cols ) );

			std::queue<std::pair<std::size_t, std::size_t>> queue;

			queue.push( { 0, 0 } );
			counter[ 0 ][ 0 ] = 1;

			while( !queue.empty() )
			{
				const auto [x, y] = queue.front();

				if( x == num_rows - 1 && y == num_cols - 1 ) return counter[ x ][ y ];

				for( auto& [nx, ny] : get_next_choices() )
				{
					int next_x = x + nx;
					int next_y = y + ny;

					if( is_valid( grid, next_x, next_y ) )
					{
						if( counter[ next_x ][ next_y ] ) continue;

						queue.push( { next_x, next_y } );

						counter[ next_x ][ next_y ] = counter[ x ][ y ] + 1;
					}
				}

				queue.pop();
			}

			return -1;
		}
	};

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

	/*733. Flood Fill.

	An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

	Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

	To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

	At the end, return the modified image.

	Example 1:
	Input:
	image = [[1,1,1],[1,1,0],[1,0,1]]
	sr = 1, sc = 1, newColor = 2
	Output: [[2,2,2],[2,2,0],[2,0,1]]
	Explanation:
	From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
	by a path of the same color as the starting pixel are colored with the new color.
	Note the bottom corner is not colored 2, because it is not 4-directionally connected
	to the starting pixel.
	Note:

	The length of image and image[0] will be in the range [1, 50].
	The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
	The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

	*/

	class image_fill
	{
	public:

		/// <summary>
		/// flood fill
		///
		/// standard dfs search procedure via recursion
		/// 
		/// </summary>
		/// <param name="image">img</param>
		/// <param name="row">row</param>
		/// <param name="col">col</param>
		/// <param name="new_color">old col</param>
		/// <param name="old_color">new col</param>
		static void fill( std::vector<std::vector<int>>& image,
			const int row, const int col,
			const int new_color, const int old_color )
		{
			const int num_rows = image.size();
			const int num_cols = image[ 0 ].size();

			if( row < 0 || row >= num_rows ||
				col < 0 || col >= num_cols ) return;

			if( image[ row ][ col ] == new_color ||
				image[ row ][ col ] != old_color ) return;

			image[ row ][ col ] = new_color;

			fill( image, row - 1, col, new_color, old_color );
			fill( image, row + 1, col, new_color, old_color );
			fill( image, row, col - 1, new_color, old_color );
			fill( image, row, col + 1, new_color, old_color );
		}

		static std::vector<std::vector<int>> flood_fill( std::vector<std::vector<int>>& image,
			const int sr, const int sc, const int new_color )
		{
			if( image.empty() || image[ 0 ].empty() ) return image;

			const auto old_color = image[ sr ][ sc ];

			fill( image, sr, sc, new_color, old_color );

			return image;
		}
	};

	/*909. Snakes and Ladders.

	On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the board,
	and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:


	You start on square 1 of the board (which is always in the last row and first column).  Each move, starting from square x, consists of the following:

	You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
	(This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations, regardless of the size of the board.)
	If S has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to S.
	A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.  The destination of that snake or ladder is board[r][c].

	Note that you only take a snake or ladder at most once per move: if the destination to a snake or ladder is the start of another snake or ladder, you do not continue moving.  (For example, if the board is `[[4,-1],[-1,3]]`, and on the first move your destination square is `2`, then you finish your first move at `3`, because you do not continue moving to `4`.)

	Return the least number of moves required to reach square N*N.  If it is not possible, return -1.

	Example 1:

	Input: [
	[-1,-1,-1,-1,-1,-1],
	[-1,-1,-1,-1,-1,-1],
	[-1,-1,-1,-1,-1,-1],
	[-1,35,-1,-1,13,-1],
	[-1,-1,-1,-1,-1,-1],
	[-1,15,-1,-1,-1,-1]]

	Output: 4
	Explanation:
	At the beginning, you start at square 1 [at row 5, column 0].
	You decide to move to square 2, and must take the ladder to square 15.
	You then decide to move to square 17 (row 3, column 5), and must take the snake to square 13.
	You then decide to move to square 14, and must take the ladder to square 35.
	You then decide to move to square 36, ending the game.
	It can be shown that you need at least 4 moves to reach the N*N-th square, so the answer is 4.
	Note:

	2 <= board.length = board[0].length <= 20
	board[i][j] is between 1 and N*N or is equal to -1.
	The board square with number 1 has no snake or ladder.
	The board square with number N*N has no snake or ladder.
	*/

	class snakes_and_ladders
	{
		static std::map<int, std::pair<int, int>>
			coords_to_numbers( const std::vector<std::vector<int>>& board )
		{
			const int n = board.size();
			auto flag = 0, pos = 1;

			std::map<int, std::pair<int, int>> map;

			for( auto row = n - 1; row >= 0; --row )
			{
				if( flag )
				{
					for( auto col = n - 1; col >= 0; --col )
					{
						map[ pos ] = { row, col };
						pos++;
					}

					flag = 0;
				}
				else
				{
					for( auto col = 0; col < n; ++col )
					{
						map[ pos ] = { row, col };
						pos++;
					}

					flag = 1;
				}
			}

			return map;
		}

		static std::vector<std::vector<int>> build_graph(
			const std::vector<std::vector<int>>& board,
			const std::map<int, std::pair<int, int>>& map )
		{
			const int n = board.size();
			int grid = n * n;
			auto adj = std::vector<std::vector<int>>( grid + 1, std::vector<int>{ } );

			for( auto i = 1; i <= grid; i++ )
			{
				for( auto j = i + 1; j <= i + 6; j++ )
				{
					if( j <= grid )
					{
						const auto row = map.at( j ).first;
						const auto col = map.at( j ).second;

						if( board[ row ][ col ] == -1 )
						{
							adj[ i ].push_back( j );
						}
						else
						{
							adj[ i ].push_back( board[ row ][ col ] );
						}
					}
				}
			}

			return adj;
		}

	public:

		static int snakesAndLadders( const std::vector<std::vector<int>>& board )
		{
			const int n = board.size();
			const auto grid = n * n;
			const auto map = coords_to_numbers( board );
			const auto graph = build_graph( board, map );

			std::vector<int> dist( grid + 1, INT_MAX );
			std::queue<int>  queue;

			queue.push( 1 );
			dist[ 1 ] = 0;

			while( !queue.empty() )
			{
				const auto curr = queue.front();
				queue.pop();

				for( auto next : graph[ curr ] )
				{
					if( dist[ next ] == INT_MAX )
					{
						queue.push( next );
						dist[ next ] = dist[ curr ] + 1;

						if( next == grid )
							break;
					}
				}
			}

			return dist[ grid ] == INT_MAX ? -1 : dist[ grid ];
		}
	};

	/* 419. Battleships in a Board.

	Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented
	with '.'s. You may assume the following rules:

	You receive a valid board, made of only battleships or empty slots.

	Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns)
	or Nx1 (N rows, 1 column), where N can be of any size.

	At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

	Example:
	X..X
	...X
	...X

	In the above board there are 2 battleships.

	Invalid Example:
	...X
	XXXX
	...X

	This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
	Follow up:
	Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
	*/

	class count_battleships
	{
		static char SHIP_MARKER;

		static bool is_battleship( const std::vector<std::vector<char>>& board,
			const int row, const int col,
			std::vector<std::vector<bool>>& visited )
		{
			const int num_rows = board.size();
			const int num_cols = board[ 0 ].size();

			if( row < 0 || row >= num_rows ) return false;
			if( col < 0 || col >= num_cols ) return false;
			if( visited[ row ][ col ] || board[ row ][ col ] != SHIP_MARKER ) return false;

			visited[ row ][ col ] = true;

			is_battleship( board, row - 1, col, visited );
			is_battleship( board, row + 1, col, visited );
			is_battleship( board, row, col - 1, visited );
			is_battleship( board, row, col + 1, visited );

			return true;
		}

	public:

		static int countBattleships( const std::vector<std::vector<char>>& board )
		{
			if( board.empty() ) return 0;
			if( board[ 0 ].empty() ) return 0;

			const auto num_rows = board.size();
			const auto num_cols = board[ 0 ].size();

			auto visited = std::vector<std::vector<bool>>( num_rows,
				std::vector( num_cols, false ) );

			auto num_ships = 0;

			for( auto row = 0; row < num_rows; ++row )
			{
				for( auto col = 0; col < num_cols; ++col )
				{
					if( is_battleship( board, row, col, visited ) )
					{
						++num_ships;
					}
				}
			}

			return num_ships;
		}
	};

	char count_battleships::SHIP_MARKER = 'X';


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

	/* 547. Friend Circles.

	There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example,
	if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

	Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

	Example 1:

	Input:
	[[1,1,0],
	 [1,1,0],
	 [0,0,1]]

	Output: 2
	Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
	The 2nd student himself is in a friend circle. So return 2.


	Example 2:

	Input:
	[[1,1,0],
	 [1,1,1],
	 [0,1,1]]

	Output: 1
	Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
	so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
	
	Constraints:

	1 <= N <= 200
	M[i][i] == 1
	M[i][j] == M[j][i]
	*/

	class friend_circles
	{
		static void dfs( const std::vector<std::vector<int>>& grid,
			std::vector<bool>& visited,
			const int row )
		{
			for( auto col = 0; col < grid.size(); ++col )
			{
				if( grid[ row ][ col ] == 1 && visited[ col ] == 0 )
				{
					visited[ col ] = 1;
					dfs( grid, visited, col );
				}
			}
		}

	public:

		static int find_circle_num( const std::vector<std::vector<int>>& grid )
		{
			const int num_rows = grid.size();
			const int num_cols = grid[ 0 ].size();

			if( num_rows <= 0 || num_cols <= 0 ) return 0;

			auto visited = std::vector<bool>( num_rows, false );
			auto num_groups = 0;

			for( auto row = 0; row < num_rows; ++row )
			{
				if( !visited[ row ] )
				{
					dfs( grid, visited, row );
					num_groups++;
				}
			}

			return num_groups;
		}
	};
}