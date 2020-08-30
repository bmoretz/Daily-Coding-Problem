#include <bits/stdc++.h>
#include <array>

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
		const auto graph =build_graph( board, map );

		std::vector<int> dist( grid + 1, INT_MAX );
		std::queue<int>  queue;

		queue.push( 1 );
		dist[ 1 ] = 0;

		while( !queue.empty() )
		{
			auto curr = queue.front();
			queue.pop();

			for( auto next : graph[curr] )
			{
				if( dist[next] == INT_MAX )
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

auto main() -> int
{
	const auto input1 = std::vector<std::vector<int>>
	{
		{ -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1 },
		{ -1, 35, -1, -1, 13, -1 },
		{ -1, -1, -1, -1, -1, -1 },
		{ -1, 15, -1, -1, -1, -1 }
	};
	
	const auto result = snakes_and_ladders::snakesAndLadders( input1 );
	
	return 0;
}