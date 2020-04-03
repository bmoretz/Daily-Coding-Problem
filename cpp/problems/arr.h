#pragma once
#include <vector>

namespace arr_problems
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
		int width_;

	public:
		explicit Matrix( const int n )
		{
			_ASSERT( n >= 0 );

			for( auto row = 1; row < ( n + 1 ); ++row )
			{
				auto values = std::vector<int>();

				for( auto column = 1; column < ( n + 1 ); ++column )
				{
					auto value = ( ( row - 1 ) * n ) + column;

					values.push_back( value );
				}

				data_.push_back( values );
			}

			width_ = n;
		}

		int num_rows() const { return data_.size(); }
		int num_cols() const { return width_; }

		explicit Matrix( const std::vector<std::vector<int>> & values )
		{
			data_ = values;
			width_ = values[ 0 ].size();
		}

		std::vector<int> get_row( const int row ) const
		{
			_ASSERT( row >= 0 && row <= num_rows() );

			return data_[ row ];
		}

		bool operator==( const Matrix & other ) const
		{
			if( width_ != other.width_ ) return false;
			if( num_cols() != other.num_cols() || num_rows() != other.num_rows() ) return false;

			auto equal = true;

			for( auto row = 0; row < num_rows(); ++row )
			{
				equal &= data_[ row ] == other.data_[ row ];

				if( !equal ) break;
			}

			return equal;
		}
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