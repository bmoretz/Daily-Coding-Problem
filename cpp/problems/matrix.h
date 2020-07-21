#pragma once

#include <vector>

namespace problems::matrix
{
	/// <summary>
	/// Simple Matrix representation using a vector of vector<int>'s.
	///
	/// This class is used to encapsulate simple matrix_problems like behavior
	/// for the matrix_problems rotation problem (initialization, equality, etc).
	/// </summary>
	class matrix
	{
		std::vector<std::vector<int>> data_;

	public:
		explicit matrix( int n );

		explicit matrix( int rows, int columns );

		int height() const;

		int width() const;

		explicit matrix( const std::vector<std::vector<int>>& values );

		std::vector<int> get_row( int row ) const;

		bool operator==( const matrix& other ) const;
		std::vector<int> operator[]( int row ) const;
		std::vector<int>& operator[]( int row );

		static void set_incremental_values( matrix& matrix );
	};

	/* Rotate Matrix.
	 *
	 * Given an image represented by an NxN matrix_problems, where each pixel
	 * in the image is 4 bytes, write a method to rotate the image by 90
	 * degrees.
	 *
	 * Can you do this in place?
	 */

	class rotate1
	{
	public:
		static matrix rotate( const matrix& m );
	};

	/* Zero Matrix.
	 *
	 * Write an algorithm such that if an element in an MxN matrix_problems is zero,
	 * its entire row and column are set to zero.
	 */

	class zero1
	{
	public:
		static void zero( matrix& matrix );
	};
}