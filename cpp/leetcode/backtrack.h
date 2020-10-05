#pragma once

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

	/* 207. Course Schedule.

	There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

	Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

	Example 1:

	Input: numCourses = 2, prerequisites = [[1,0]]
	Output: true
	Explanation: There are a total of 2 courses to take.
				 To take course 1 you should have finished course 0. So it is possible.
	Example 2:

	Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
	Output: false
	Explanation: There are a total of 2 courses to take.
				 To take course 1 you should have finished course 0, and to take course 0 you should
				 also have finished course 1. So it is impossible.

	Constraints:

	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
	You may assume that there are no duplicate edges in the input prerequisites.
	1 <= numCourses <= 10^5
	*/

	class course_schedule
	{
		static bool is_cyclic( int course, const std::map<int, std::vector<int>>& courses,
			std::vector<bool>& checked, std::vector<bool>& path )
		{
			if( checked[ course ] ) return false;
			if( path[ course ] ) return true;

			if( courses.find( course ) == courses.end() ) return false;

			path[ course ] = true;

			auto result = false;

			for( auto child : courses.at( course ) )
			{
				result = is_cyclic( child, courses, checked, path );

				if( result )
					break;
			}

			path[ course ] = false;
			checked[ course ] = true;

			return result;
		}

	public:

		static bool can_finish( const int num_courses,
			const std::vector<std::vector<int>>& prerequisites )
		{
			std::map<int, std::vector<int>> courses;

			for( auto& pre : prerequisites )
			{
				const auto c = pre.at( 0 );
				const auto p = pre.at( 1 );

				courses[ c ].push_back( p );
			}

			auto checked = std::vector<bool>( num_courses );
			auto path = std::vector<bool>( num_courses );

			for( auto course = 0; course < num_courses; ++course )
			{
				if( is_cyclic( course, courses, checked, path ) )
				{
					return false;
				}
			}

			return true;
		}
	};
}