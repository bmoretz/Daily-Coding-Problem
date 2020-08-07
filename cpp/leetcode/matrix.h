#pragma once

#include <algorithm>
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
}