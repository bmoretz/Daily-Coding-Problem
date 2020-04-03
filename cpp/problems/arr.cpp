#include "pch.h"
#include "arr.h"

#include <vector>

using namespace std;

namespace arr_problems
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
	Matrix matrix_rotate1::rotate( const Matrix & m )
	{
		auto matrix = vector<vector<int>>( m.num_rows() );

		for( auto row = 0; row < m.num_rows(); ++row )
		{
			auto values = m.get_row( row );

			for( auto index = 0; index < values.size(); ++index )
			{
				if( matrix[ index ].empty() )
					matrix[ index ] = vector<int>( m.num_cols() );

				const auto dest_column = static_cast< int >( m.num_rows() - row - 1 );

				matrix[ index ][ dest_column ] = values[ index ];
			}
		}

		return Matrix( matrix );
	}
}