#pragma once

#include <unordered_map>
#include <vector>

namespace leetcode::backtrack
{
	/* 254. Factor Combinations.

	Numbers can be regarded as product of its factors. For example,

	8 = 2 x 2 x 2;
	  = 2 x 4.

	Write a function that takes an integer n and return all possible combinations of its factors.

	Note:

	You may assume that n is always positive.
	Factors should be greater than 1 and less than n.

	Example 1:
	Input: 1
	Output: []

	Example 2:
	Input: 37
	Output:[]

	Example 3:
	Input: 12
	Output:
	[
	  [2, 6],
	  [2, 2, 3],
	  [3, 4]
	]

	Example 4:
	Input: 32
	Output:
	[
	  [2, 16],
	  [2, 2, 8],
	  [2, 2, 2, 4],
	  [2, 2, 2, 2, 2],
	  [2, 4, 4],
	  [4, 8]
	]
	*/

	struct factor_combinations
	{
		static std::vector<std::vector<int>> get_factors( const int n )
		{
			std::vector<std::vector<int>> results;
			auto cur = std::vector<int>{ };

			factor( results, cur, n, 2 );

			return results;
		}

		static void factor( std::vector<std::vector<int>>& results, std::vector<int>& cur,
			const int n, const int start )
		{
			if( n <= 1 )
			{
				if( cur.size() > 1 )
				{
					results.emplace_back( std::vector<int>( cur ) );
				}

				return;
			}

			for( auto divisor = start; divisor <= n; ++divisor )
			{
				if( n % divisor == 0 )
				{
					cur.emplace_back( divisor );
					factor( results, cur, n / divisor, divisor );
					cur.erase( cur.end() - 1 );
				}
			}
		}
	};

	/* 79. Word Search.

	Given a 2D board and a word, find if the word exists in the grid.

	The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or
	vertically neighboring. The same letter cell may not be used more than once.

	Example:

	board =
	[
	  ['A','B','C','E'],
	  ['S','F','C','S'],
	  ['A','D','E','E']
	]

	Given word = "ABCCED", return true.
	Given word = "SEE", return true.
	Given word = "ABCB", return false.


	Constraints:

	board and word consists only of lowercase and uppercase English letters.
	1 <= board.length <= 200
	1 <= board[i].length <= 200
	1 <= word.length <= 10^3
	*/

	class word_search
	{
		static bool solve( std::vector<std::vector<char>>& board,
			const int row, const int col, int pos,
			const std::string& word )
		{
			const int num_rows = board.size();
			const int num_cols = board[ 0 ].size();

			if( pos == word.size() ) return true;

			if( row < 0 || row >= num_rows ) return false;
			if( col < 0 || col >= num_cols ) return false;
			if( board[ row ][ col ] != word[ pos ] ) return false;

			const auto chr = board[ row ][ col ];
			board[ row ][ col ] = ' ';

			++pos;

			const auto up = solve( board, row + 1, col, pos, word );
			const auto down = solve( board, row - 1, col, pos, word );
			const auto left = solve( board, row, col - 1, pos, word );
			const auto right = solve( board, row, col + 1, pos, word );

			const auto found = up || down || left || right;

			if( found )
			{
				return true;
			}

			// back track
			board[ row ][ col ] = chr;

			return false;
		}

	public:

		static bool exist( std::vector<std::vector<char>>& board,
			const std::string& word )
		{
			const int num_rows = board.size();
			if( num_rows == 0 ) return false;

			const int num_cols = board[ 0 ].size();
			if( num_cols == 0 ) return false;

			for( auto row = 0; row < num_rows; ++row )
			{
				for( auto col = 0; col < num_cols; ++col )
				{
					if( board[ row ][ col ] == word[ 0 ] &&
						solve( board, row, col, 0, word ) )
					{
						return true;
					}
				}
			}

			return false;
		}
	};

	/*52. N-Queens II.

	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

	Given an integer n, return the number of distinct solutions to the n-queens puzzle.

	Example:

	Input: 4
	Output: 2
	Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
	[
	 [".Q..",  // Solution 1
	  "...Q",
	  "Q...",
	  "..Q."],

	 ["..Q.",  // Solution 2
	  "Q...",
	  "...Q",
	  ".Q.."]
	]
	*/

	class n_queens_ii
	{

		static int backtrack_n_queens( std::vector<std::vector<int>>& board,
			const int row, int count )
		{
			const int num_rows = board.size();
			const int num_cols = board[ 0 ].size();

			for( auto col = 0; col < num_cols; col++ )
			{
				if( board[ row ][ col ] == 0 )
				{
					// this is where we will backtrack to
					const auto prev_board = board;

					place_queen( board, row, col );

					if( row == num_rows - 1 )
					{
						count++;
					}
					else
					{
						count = backtrack_n_queens( board, row + 1, count );
					}

					// backtrack the last queen

					board = prev_board;
				}
			}

			return count;
		}

		static void place_queen( std::vector<std::vector<int>>& board,
			const int row, const int col )
		{
			const auto num_rows = board.size();
			const auto num_cols = board[ 0 ].size();

			for( auto pos = 0; pos < num_rows; pos++ )
			{
				// fill vertically
				board[ pos ][ col ] = 1;

				// fill horizontally
				board[ row ][ pos ] = 1;

				// fill the NE diagonal
				const auto j = row + col - pos;
				if( j >= 0 && j < num_cols ) {
					board[ pos ][ j ] = 1;
				}

				// fill the SE diagonal
				const auto k = row - col + pos;
				if( k >= 0 && k < num_rows ) {
					board[ k ][ pos ] = 1;
				}
			}
		}

	public:

		static int total_n_queens( const int board_size )
		{
			auto board = std::vector<std::vector<int>>( board_size, std::vector<int>( board_size, 0 ) );

			return backtrack_n_queens( board, 0, 0 );
		}
	};

	/*489. Robot Room Cleaner.

	Given a robot cleaner in a room modeled as a grid.

	Each cell in the grid can be empty or blocked.

	The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

	When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

	Design an algorithm to clean the entire room using only the 4 given APIs shown below.

	interface Robot {
	  // returns true if next cell is open and robot moves into the cell.
	  // returns false if next cell is obstacle and robot stays on the current cell.
	  boolean move();

	  // Robot will stay on the same cell after calling turnLeft/turnRight.
	  // Each turn will be 90 degrees.
	  void turnLeft();
	  void turnRight();

	  // Clean the current cell.
	  void clean();
	}

	Example:

	Input:
	room = [
	  [1,1,1,1,1,0,1,1],
	  [1,1,1,1,1,0,1,1],
	  [1,0,1,1,1,1,1,1],
	  [0,0,0,1,0,0,0,0],
	  [1,1,1,1,1,1,1,1]
	],
	row = 1,
	col = 3

	Explanation:
	All grids in the room are marked by either 0 or 1.
	0 means the cell is blocked, while 1 means the cell is accessible.
	The robot initially starts at the position of row=1, col=3.
	From the top left corner, its position is one row below and three columns right.
	Notes:

	The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words,
	you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
	The robot's initial position will always be in an accessible cell.
	The initial direction of the robot will be facing up.
	All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
	Assume all four edges of the grid are all surrounded by wall.
	*/

	class robot_room_cleaner
	{
		class robot;

		static inline std::vector<std::pair<int, int>> directions_ = {
			{-1, 0}, {0, 1}, {1, 0}, {0, -1}
		};

		std::set<std::pair<int, int>> visited_;

		robot* robot_{};

		void go_back() const
		{
			robot_->turnRight();
			robot_->turnRight();

			robot_->move();

			robot_->turnRight();
			robot_->turnRight();
		}

		void backtrack( const std::pair<int, int> pos, const int dir )
		{
			visited_.insert( pos );

			robot_->clean();

			for( auto index = 0; index < 4; ++index )
			{
				const auto next_dir = ( dir + index ) % 4;
				const auto next_pos = std::make_pair( pos.first + directions_[ next_dir ].first,
					pos.second + directions_[ next_dir ].second );

				if( visited_.find( next_pos ) == visited_.end() && robot_->move() )
				{
					backtrack( next_pos, next_dir );
					go_back();
				}

				robot_->turnRight();
			}
		}

	public:

		class robot
		{
		public:

			robot() { }

			// Returns true if the cell in front is open and robot moves into the cell.
			// Returns false if the cell in front is blocked and robot stays in the current cell.
			bool move();

			// Robot will stay in the same cell after calling turnLeft/turnRight.
			// Each turn will be 90 degrees.
			void turnLeft();
			void turnRight();

			// Clean the current cell.
			void clean();
		};

		void clean_room( robot& robot )
		{
			this->robot_ = &robot;

			backtrack( std::make_pair( 0, 0 ), 0 );
		}
	};

	/*37. Sudoku Solver.

	Write a program to solve a Sudoku puzzle by filling the empty cells.

	A sudoku solution must satisfy all of the following rules:

	Each of the digits 1-9 must occur exactly once in each row.
	Each of the digits 1-9 must occur exactly once in each column.
	Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
	The '.' character indicates empty cells.

	Example 1:

	Input: board =
	[
		["5","3",".",".","7",".",".",".","."],
		["6",".",".","1","9","5",".",".","."],
		[".","9","8",".",".",".",".","6","."],
		["8",".",".",".","6",".",".",".","3"],
		["4",".",".","8",".","3",".",".","1"],
		["7",".",".",".","2",".",".",".","6"],
		[".","6",".",".",".",".","2","8","."],
		[".",".",".","4","1","9",".",".","5"],
		[".",".",".",".","8",".",".","7","9"]
	]

	Output:
	[
		["5","3","4","6","7","8","9","1","2"],
		["6","7","2","1","9","5","3","4","8"],
		["1","9","8","3","4","2","5","6","7"],
		["8","5","9","7","6","1","4","2","3"],
		["4","2","6","8","5","3","7","9","1"],
		["7","1","3","9","2","4","8","5","6"],
		["9","6","1","5","3","7","2","8","4"],
		["2","8","7","4","1","9","6","3","5"],
		["3","4","5","2","8","6","1","7","9"]
	]

	Explanation: The input board is shown above and the only valid solution is shown below:

	Constraints:

	board.length == 9
	board[i].length == 9
	board[i][j] is a digit or '.'.
	It is guaranteed that the input board has only one solution.
	*/

	class sudoku_solver
	{
		static bool solve( std::vector<std::vector<char>>& board )
		{
			const int num_rows = board.size();
			const int num_cols = board[ 0 ].size();

			for( auto row = 0; row < num_rows; ++row )
			{
				for( auto col = 0; col < num_cols; ++col )
				{
					if( board[ row ][ col ] == '.' )
					{
						for( auto candidate = '1';
							candidate <= '9';
							++candidate )
						{
							if( is_valid( board, row, col, candidate ) )
							{
								board[ row ][ col ] = candidate;

								if( solve( board ) )
									return true;

								board[ row ][ col ] = '.';
							}
						}

						return false;
					}
				}
			}

			return true;
		}

		static bool is_valid( std::vector<std::vector<char>>& board,
			const int r, const int c, const char candidate )
		{
			const int num_rows = board.size();
			const int num_cols = board[ 0 ].size();

			for( auto row = 0; row < num_rows; ++row )
				if( board[ row ][ c ] == candidate )
					return false;

			for( auto col = 0; col < num_cols; ++col )
				if( board[ r ][ col ] == candidate )
					return false;

			for( auto row = ( r / 3 ) * 3; row < ( r / 3 + 1 ) * 3; ++row )
				for( auto col = ( c / 3 ) * 3; col < ( c / 3 + 1 ) * 3; ++col )
					if( board[ row ][ col ] == candidate )
						return false;

			return true;
		}

	public:

		static void solve_sudoku( std::vector<std::vector<char>>& board )
		{
			solve( board );
		}
	};

	/*77. Combinations.

	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

	You may return the answer in any order.

	Example 1:

	Input: n = 4, k = 2
	Output:
	[
	  [2,4],
	  [3,4],
	  [2,3],
	  [1,2],
	  [1,3],
	  [1,4],
	]
	Example 2:

	Input: n = 1, k = 1
	Output: [[1]]


	Constraints:

	1 <= n <= 20
	1 <= k <= n
	*/

	class combinations
	{
		static void combine( std::vector<int>& vec,
			const int index,
			const int start,
			const int N,
			const int K,
			std::vector<std::vector<int>>& results )
		{
			if( index == K )
			{
				results.emplace_back( vec.begin(), vec.end() );
				return;
			}

			for( auto n = start; n <= N; ++n )
			{
				vec.push_back( n );

				combine( vec, index + 1, n + 1, N, K, results );

				vec.erase( vec.begin() + index );
			}
		}

	public:

		static std::vector<std::vector<int>> combine( const int N, const int K )
		{
			std::vector<std::vector<int>> results;

			auto temp = std::vector<int>();

			combine( temp, 0, 1, N, K, results );

			return results;
		}
	};
}