// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <set>

/*Is Unique.

Implement an algorithm to determine if a string has all unique characters.

What if you cannot use additional data structures?
*/

using namespace std;

bool is_unique2( string str )
{
	auto unique = false;

	set<char> words = set<char>();

	for( auto iter = str.begin(); iter != str.end(); iter++ )
	{
		auto current = ( *iter );

		if( words.find( current ) != words.end() )
			return false;

		words.insert( current );
	}

	return true;
}

int main()
{
	string input;

	while( cin >> input ) {
		cout << input << " is unique? " << is_unique2( input ) << endl;
	}
}
