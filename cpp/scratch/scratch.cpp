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

bool is_rotation( const string & s1, const string & s2 )
{
	if( s1.empty() || s2.empty() ) return false;
	if( s1.length() != s2.length() ) return false;

	auto i = size_t(), j = size_t();
	
	string rotated;
	
	while( j < s2.length() )
	{
		if( s1[i] == s2[j] )
		{
			const auto prev = j;
			
			while( i < s1.length() && s1[ i ] == s2[ j ] )
			{
				i++; j++;

				if( i == s1.length() )
					return true;

				if( j == s2.length() )
					j = 0;
			}
			
			i = 0;
			j = prev;
		}
		
		j++;
	}

	return false;
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