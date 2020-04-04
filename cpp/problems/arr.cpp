#include "pch.h"
#include "arr.h"

#include <vector>

using namespace std;

namespace arr_problems
{
	namespace matrix_problems
	{
		matrix::matrix( const int n ) :
			matrix( n, n )
		{
		}

		int matrix::height() const
		{
			return data_.size();
		}

		int matrix::width() const
		{
			if( data_.empty() ) return 0;

			return data_[ 0 ].size();
		}

		matrix::matrix( const vector<vector<int>> & values )
		{
			data_ = values;
		}

		/// <summary>
		/// initializes the matrix_problems to have n, m wide, vectors 
		/// </summary>
		/// <param name="rows">n rows</param>
		/// <param name="columns">m cols</param>
		matrix::matrix( const int rows, const int columns )
		{
			_ASSERT( rows >= 1 && columns >= 1 );

			data_ = std::vector<vector<int>>( rows, vector<int>( columns, 0 ) );
		}

		/// <summary>
		///	returns row specified by passed index.
		/// </summary>
		/// <param name="row">row index</param>
		/// <returns>the row</returns>
		vector<int> matrix::get_row( const int row ) const
		{
			_ASSERT( row >= 0 && row <= height() );

			return data_[ row ];
		}

		/// <summary>
		/// Matrix to Matrix equality for unit tests.
		/// </summary>
		/// <param name="other">other matrix_problems</param>
		/// <returns>true if equal by values</returns>
		bool matrix::operator==( const matrix & other ) const
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

		vector<int> matrix::operator[]( const int row ) const
		{
			_ASSERT( row >= 0 && row <= height() );

			return data_[ row ];
		}

		vector<int> & matrix::operator[]( const int row )
		{
			_ASSERT( row >= 0 && row <= height() );

			return data_[ row ];
		}
		
		/// <summary>
		/// Utility method to set all the values in a matrix_problems to incremental values, i.e.,
		/// 1 2
		/// 3 4
		///
		/// for a 2x2 matrix_problems.
		///
		/// previous contents lost/overwritten.
		/// </summary>
		/// <param name="matrix">the matrix_problems to set</param>	
		void matrix::set_incremental_values( matrix & matrix )
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

		/////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/// <summary>
		/// rotate matrix_problems 1
		///
		/// This is a straight forward approach that allocates
		/// a separate (empty) set of vectors (using the dimensions
		/// of the passed matrix_problems), and then takes each row in the source
		/// matrix_problems and "pivots" the row to a column in the destination
		/// matrix_problems.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N^2)</run-time>
		///		<space>O(N^2)</space>
		/// </complexity>
		/// <param name="m">source matrix_problems</param>
		/// <returns>a new, rotated matrix_problems</returns>
		matrix rotate1::rotate( const matrix & m )
		{
			auto vectors = vector<vector<int>>( m.height() );

			for( auto row = 0; row < m.height(); ++row )
			{
				auto values = m.get_row( row );

				for( auto index = 0; index < values.size(); ++index )
				{
					if( vectors[ index ].empty() )
						vectors[ index ] = vector<int>( m.width() );

					const auto dest_column = static_cast< int >( m.height() - row - 1 );

					vectors[ index ][ dest_column ] = values[ index ];
				}
			}

			return matrix( vectors );
		}

		/// <summary>
		/// zero matrix 1
		///
		/// This approach is the a brute force solution that
		/// first iterates the matrix to store the rows and
		/// columns that need to be zeroed out. We take this
		/// inventory before we mutate any values in the matrix
		/// so that we do not inadvertently lose a zero value
		/// by prematurely writing over values.
		///
		/// After inventory is taken, we simply zero the columns
		/// that are not going to get cleared out be zeroing the rows
		/// later, and then finally zero out all the rows we have marked.
		/// </summary>
		/// <complexity>
		///		<run-time>O(M*N)</run-time>
		///		<space>O(Zr + Zc)</space>
		/// </complexity>
		/// <param name="matrix">the matrix to zero</param>
		void zero1::zero(matrix& matrix)
		{
			auto zero_rows = vector<int>(), zero_columns = vector<int>();

			for( auto row = 0; row < matrix.height(); ++row )
			{
				for( auto column = 0; column < matrix.width(); ++column )
				{
					const auto value = matrix[ row ][ column ];

					if( value == 0 )
					{
						if( find( zero_rows.begin(), zero_rows.end(), row ) == zero_rows.end() )
							zero_rows.push_back( row );

						if( find( zero_columns.begin(), zero_columns.end(), column ) == zero_columns.end() )
							zero_columns.push_back( column );
					}
				}
			}

			for( auto column : zero_columns )
			{
				for( auto row = 0; row < matrix.height(); ++row )
				{
					// we are going to zero the whole row latter, so ok to skip.
					if( find( zero_rows.begin(), zero_rows.end(), row ) != zero_rows.end() )
						continue;

					matrix[ row ][ column ] = 0;
				}
			}

			for( auto row : zero_rows )
			{
				for( auto column = 0; column < matrix.width(); ++column )
				{
					matrix[ row ][ column ] = 0;
				}
			}
		}
	}
}