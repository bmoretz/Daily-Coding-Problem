// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

/* String Rotation.
 *
 * Assume you have a method isSubstring which checks if one word is a
 * substring of another. Given two strings, s1 and s2, write code to check
 * if s2 is a rotation of s1 using only one call to isSubstring.
 *
 * e.g.,
 * "waterbottle" is a rotation of "erbottlewat"
 */

using namespace std;

vector<string> get_rotations( const string & input )
{
	if( input.empty() ) return vector<string>();

	auto n_rotations = input.length();
	auto rotations = vector<string>();

	auto current = input;

	while( n_rotations > 0 )
	{
		rotations.push_back( current );

		current.push_back( current[ 0 ] );
		current.erase( 0, 1 );

		n_rotations--;
	}

	return rotations;
}

bool is_substring( const string & haystack, const string & needle )
{
	return haystack.find( needle ) != string::npos;
}

bool is_rotation( const string & s1, const string & s2 )
{
	auto rotations = get_rotations( s1 );

	auto rotations_string = string();

	for( auto it = rotations.begin(); it != rotations.end(); ++it )
	{
		rotations_string += *it + "|";
	}

	return is_substring( rotations_string, s2 );
}

void test_harness()
{
	string input1, input2;

	cout << "Enter test input:";

	while( getline( cin, input1 ) && getline( cin, input2) )
	{
		try
		{
			cout << input1 << " : " << input2 <<
				" is rotation: " << is_rotation(input1, input2) << endl;
			
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