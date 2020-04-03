// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/* Rotate Matrix.
 *
 * Given an image represented by an NxN matrix, where each pixel
 * in the image is 4 bytes, write a method to rotate the image by 90
 * degrees.
 *
 * Can you do this in place?
 */

using namespace std;

class Matrix
{
	vector<vector<int>> data_;
	int width_;
	
public:
	explicit Matrix( const int n )
	{
		_ASSERT( n >= 0 );
		
		for( auto row = 1; row < ( n + 1 ); ++row )
		{
			auto values = vector<int>();

			for( auto column = 1; column < ( n + 1 ); ++column )
			{
				auto value = ( ( row - 1 ) * n ) + column;

				values.push_back( value );
			}

			data_.push_back( values );
		}

		width_ = n;
	}

	int height() const { return data_.size(); }
	int width() const { return width_; }

	explicit Matrix( const vector<vector<int>> & values)
	{
		data_ = values;
		width_ = values[ 0 ].size();
	}

	vector<int> get_row( const int row ) const
	{
		_ASSERT( row >= 0 && row <= height() );

		return data_[ row ];
	}
};

Matrix rotate( Matrix & matrix )
{
	for( auto row = 0; row < matrix.height(); ++row )
	{
		for( auto column = 0; column < matrix.width(); ++column )
		{
		}
	}

	return Matrix( matrix );
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

			auto mat = Matrix( stoi( input ) );

			auto result = rotate( mat );
			
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
    test_harness();
}
