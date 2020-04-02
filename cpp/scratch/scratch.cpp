// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

/* String Compression.
 *
 * Implement a method to perform basic string compression using the counts of repeated characters.
 *
 * For example, the string aabbccccaaa would become a2b1c5a3.
 *
 * If the "compressed" string would not become smaller than the original string, your method
 * should return the original string. You can assume the string has only uppercase and
 * lowercase letters (a-z).
 */

using namespace std;

string compressed( const string & input )
{
	if( input.empty() ) return input;

	auto prev = input[ 0 ];
	auto count = 1;

	string compressed;

	for( auto index = 1; index < input.length(); ++index )
	{
		const auto current = input[ index ];

		if( current == prev )
		{
			count++;
		}
		else
		{
			compressed += prev + to_string( count );
			count = 1;
		}
		
		prev = current;
	}

	compressed += prev + to_string( count );
	
	return compressed.length() < input.length() ? compressed : input;
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
				" compressed: " << compressed( input ) << endl;

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
