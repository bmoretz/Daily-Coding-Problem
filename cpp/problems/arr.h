#pragma once

#include <vector>

namespace arr_problems
{
	namespace matrix_rotation
	{
		/// <summary>
		/// Simple Matrix representation using a vector of vector<int>'s.
		///
		/// This class is used to encapsulate simple matrix like behavior
		/// for the matrix rotation problem (initialization, equality, etc).
		/// </summary>
		class Matrix
		{
			std::vector<std::vector<int>> data_;

		public:
			explicit Matrix(const int n);

			explicit Matrix(const int rows, const int columns);

			int height() const;

			int width() const;

			explicit Matrix(const std::vector<std::vector<int>>& values);

			std::vector<int> get_row(const int row) const;

			bool operator==(const Matrix& other) const;
			static void set_incremental_values(Matrix& matrix);
		};

		/* Rotate Matrix.
		 *
		 * Given an image represented by an NxN matrix, where each pixel
		 * in the image is 4 bytes, write a method to rotate the image by 90
		 * degrees.
		 *
		 * Can you do this in place?
		 */

		class matrix_rotate1
		{
		public:
			static Matrix rotate( const Matrix & m );
		};
	}
}