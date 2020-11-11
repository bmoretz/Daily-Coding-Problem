#include <bits/stdc++.h>

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

auto main() -> int
{
    auto input = std::vector<std::vector<char>>
    {
        { '5','3','.','.','7','.','.','.','.' },
        { '6','.','.','1','9','5','.','.','.' },
        { '.','9','8','.','.','.','.','6','.' },
        { '8','.','.','.','6','.','.','.','3' },
        { '4','.','.','8','.','3','.','.','1' },
        { '7','.','.','.','2','.','.','.','6' },
        { '.','6','.','.','.','.','2','8','.' },
        { '.','.','.','4','1','9','.','.','5' },
        { '.','.','.','.','8','.','.','7','9' }
    };

    sudoku_solver::solve_sudoku( input );

    const auto expected = std::vector<std::vector<char>>
    {
        { '5','3','4','6','7','8','9','1','2' },
        { '6','7','2','1','9','5','3','4','8' },
        { '1','9','8','3','4','2','5','6','7' },
        { '8','5','9','7','6','1','4','2','3' },
        { '4','2','6','8','5','3','7','9','1' },
        { '7','1','3','9','2','4','8','5','6' },
        { '9','6','1','5','3','7','2','8','4' },
        { '2','8','7','4','1','9','6','3','5' },
        { '3','4','5','2','8','6','1','7','9' }
    };
	
	return 0;
}