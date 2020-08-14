#include <bits/stdc++.h>
#include <random>
#include <unordered_set>

/* 348. Design Tic-Tac-Toe.

Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

Follow up:
Could you do better than O(n2) per move() operation?
*/

class tic_tac_toe
{
    std::vector<int> rows_, columns_;
    int target_, diagonal_, antidiagonal_;

public:

    explicit tic_tac_toe( const int n )
        : diagonal_{}, antidiagonal_{}
    {
        target_ = n;
        rows_.resize( n );
        columns_.resize( n );
    }

    int move( const int row, const int col, const int player )
    {
        auto result = 0;
        const auto increment = player == 1 ? 1 : -1;

        columns_[ col ] += increment;
        rows_[ row ] += increment;

        diagonal_ += row == col ? increment : 0;
        antidiagonal_ += row == target_ - 1 - col ? increment : 0;

        if( abs( rows_[ row ] ) == target_ || abs( columns_[ col ] ) == target_ ||
            abs( diagonal_ ) == target_ || abs( antidiagonal_ ) == target_ )
        {
            result = player == 1 ? 1 : 2;
        }

        return result;
    }
};

auto main() -> int
{
    auto toe = tic_tac_toe( 3 );

    toe.move( 0, 0, 1 ); // ->Returns 0 ( no one wins )
    /*
	| X| | |
        | | | |    // Player 1 makes a move at (0, 0).
        | | | |
	*/
    toe.move( 0, 2, 2 ); // ->Returns 0 ( no one wins )
    /*
    | X| |O|
    | | | |    // Player 2 makes a move at (0, 2).
    | | | |
    */

    toe.move( 2, 2, 1 ); // ->Returns 0 ( no one wins )
    /*
	| X| |O|
    | | | |    // Player 1 makes a move at (2, 2).
    | | |X |
    */

    toe.move( 1, 1, 2 ); // ->Returns 0 ( no one wins )
    /*
	| X| |O|
    | |O| |    // Player 2 makes a move at (1, 1).
    | | |X |
    */

    toe.move( 2, 0, 1 ); // ->Returns 0 ( no one wins )
    /*
	| X| |O|
    | |O| |    // Player 1 makes a move at (2, 0).
    |X| |X |
    */

    toe.move( 1, 0, 2 ); // ->Returns 0 ( no one wins )
    /*
	| X| |O|
    |O | O| |    // Player 2 makes a move at (1, 0).
    |X| |X |
    */

    toe.move( 2, 1, 1 ); // ->Returns 1 ( player 1 wins )
    /*
	| X| |O|
    |O | O| |    // Player 1 makes a move at (2, 1).
    |X | X | X |
	*/
	
    return 0;
}