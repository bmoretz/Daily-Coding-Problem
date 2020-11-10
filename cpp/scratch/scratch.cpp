#include <bits/stdc++.h>

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

	static int totalNQueens( const int board_size )
	{	
        auto board = std::vector<std::vector<int>>( board_size, std::vector<int>( board_size, 0 ) );
    	
        return backtrack_n_queens( board, 0, 0 );
    }
};

auto main() -> int
{
    auto actual = n_queens_ii::totalNQueens( 4 );

    const auto expected = std::vector<int>{ 1, 2, 3, 5 };
	
	return 0;
}