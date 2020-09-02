#include <bits/stdc++.h>
#include <array>

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

auto main() -> int
{
	const auto input1 = std::vector<std::vector<char>>
	{
		{ 'X', '.', '.', 'X' },
		{ '.', '.', '.', 'X' },
		{ '.', '.', '.', 'X' }
	};
	
	const auto result = count_battleships::countBattleships( input1 );
	
	return 0;
}