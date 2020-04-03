#include "pch.h"
#include "arr.h"

#include <vector>

using namespace std;

namespace arr_problems
{
	namespace matrix_rotation
	{
		/// <summary>
		/// rotate matrix 1
		///
		/// This is a straight forward approach that allocates
		/// a separate (empty) set of vectors (using the dimensions
		/// of the passed matrix), and then takes each row in the source
		/// matrix and "pivots" the row to a column in the destination
		/// matrix.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N^2)</run-time>
		///		<space>O(N^2)</space>
		/// </complexity>
		/// <param name="m">source matrix</param>
		/// <returns>a new, rotated matrix</returns>
		Matrix matrix_rotate1::rotate( const matrix_rotation::Matrix & m )
		{
			auto matrix = vector<vector<int>>( m.height() );

			for( auto row = 0; row < m.height(); ++row )
			{
				auto values = m.get_row( row );

				for( auto index = 0; index < values.size(); ++index )
				{
					if( matrix[ index ].empty() )
						matrix[ index ] = vector<int>( m.width() );

					const auto dest_column = static_cast< int >( m.height() - row - 1 );

					matrix[ index ][ dest_column ] = values[ index ];
				}
			}

			return Matrix( matrix );
		}

		Matrix::Matrix( const int n ) :
			Matrix( n, n )
		{
		}

		int Matrix::height() const
		{
			return data_.size();
		}

		int Matrix::width() const
		{
			if( data_.empty() ) return 0;

			return data_[ 0 ].size();
		}

		Matrix::Matrix( const std::vector<std::vector<int>> & values )
		{
			data_ = values;
		}

		/// <summary>
		/// initializes the matrix to have n, m wide, vectors 
		/// </summary>
		/// <param name="rows">n rows</param>
		/// <param name="columns">m cols</param>
		Matrix::Matrix( const int rows, const int columns )
		{
			_ASSERT( rows >= 1 && columns >= 1 );

			data_ = std::vector<std::vector<int>>( rows, std::vector<int>( columns, 0 ) );
		}

		/// <summary>
		///	returns row specified by passed index.
		/// </summary>
		/// <param name="row">row index</param>
		/// <returns>the row</returns>
		std::vector<int> Matrix::get_row( const int row ) const
		{
			_ASSERT( row >= 0 && row <= height() );

			return data_[ row ];
		}

		/// <summary>
		/// Matrix to Matrix equality for unit tests.
		/// </summary>
		/// <param name="other">other matrix</param>
		/// <returns>true if equal by values</returns>
		bool Matrix::operator==( const Matrix & other ) const
		{
			if( width() != other.width() ) return false;
			if( height() != other.height() ) return false;

			auto equal = true;

			for( auto row = 0; row < height(); ++row )
			{
				equal &= data_[ row ] == other.data_[ row ];

				if( !equal ) break;
			}

			return equal;
		}

		/// <summary>
		/// Utility method to set all the values in a matrix to incremental values, i.e.,
		/// 1 2
		/// 3 4
		///
		/// for a 2x2 matrix.
		///
		/// previous contents lost/overwritten.
		/// </summary>
		/// <param name="matrix">the matrix to set</param>	
		void Matrix::set_incremental_values( Matrix & matrix )
		{
			for( auto row = 1; row < matrix.height() + 1; ++row )
			{
				for( auto column = 1; column < matrix.height() + 1; ++column )
				{
					const auto value = ( row - 1 ) * matrix.width() + column;
					const auto current_row = row - 1, current_col = column - 1;

					matrix.data_[ current_row ][ current_col ] = value;
				}
			}
		}
	}
}