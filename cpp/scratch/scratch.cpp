// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "../problems/arr.h"

/* Zero Matrix.
 *
 * Write an algorithm such that if an element in an MxN matrix_problems is zero,
 * its entire row and column are set to zero.
 */

using namespace std;
using namespace arr_problems::matrix_problems;

void zero_matrix( matrix & matrix )
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

void test_harness()
{
	string input;;

	cout << "Enter test input:";

	while( getline( cin, input ) )
	{
		try
		{
			cout << input << " : " <<
				" Matrix: " << endl;
			
			cout << "Enter test input:";
		}
		catch( const exception & ex )
		{
			cout << ex.what();
		}
	}
}

auto main() -> int
{
	auto test_mat = matrix(
	{
		{1, 0, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
	});

	zero_matrix( test_mat )
}
