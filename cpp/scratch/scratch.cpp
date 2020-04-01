// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

/* One Away.
 * 
 * There are three types of edits that can be performed on strings:
 * 
 * insert a character,
 * remove a character,
 * replace a character
 * 
 * Given two strings, write a function to check if they are one edit (or zero edits) away.
 * 
 * EXAMPLE:
 * 
 * pale, ple -> true
 * pales, pale -> true
 * pale, bale -> true
 * pale, bake -< false
 */

using namespace std;

string::size_type find_first_invariant( const std::string & str, const char search )
{
	auto position = string::npos;

	for( auto iter = str.begin(); iter != str.end(); ++iter )
	{
		if( toupper( *iter ) == toupper( search ) ) {
			position = iter - str.begin();
			break;
		}
	}

	return position;
}

bool one_away( const string & str1, const string & str2 )
{
	if( str1.empty() || str2.empty() ) return false;

	string longer, shorter;

	if( str1.length() > str2.length() )
	{
		longer = str1;
		shorter = str2;
	}
	else
	{
		longer = str2;
		shorter = str1;
	}

	if( longer.length() - shorter.length() > 1 ) return false;

	for( auto character : shorter )
	{
		const auto location = find_first_invariant( longer, character );

		if( location != string::npos )
			longer.erase( location, 1 );
	}

	return longer.length() <= 1;
}

void test_harness()
{
	string input1, input2;

	cout << "Enter test input 1 and 2:";

	while( getline( cin, input1 ) && getline( cin, input2 ) )
	{
		try
		{
			cout << input1 << " : " << input2 <<
				" are one away?: " << ( one_away( input1, input2 ) == 1 ? "true" : "false" ) << endl;

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
