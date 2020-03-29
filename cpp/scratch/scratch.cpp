// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

/* Check Permutation.
 *
 * Given two strings, write a method to decide if one is a permutation of the other.
 */

using namespace std;

map<char, int> char_map( const string & s )
{
	map<char, int> mp;

	for( auto character : s )
	{
		auto it = mp.find( character );

		if( it == mp.end() )
			mp[ character ] = 0;
		else
			it->second++;
	}

	return mp;
}

bool is_permutation( string p, string q )
{
	if( p.empty() || q.empty() ) return false;
	if( p.length() != q.length() ) return false;

	sort( p.begin(), p.end() );
	sort( q.begin(), q.end() );

	for( size_t index = 0; index < p.length(); ++index )
	{
		if( p[ index ] != q[ index ] )
			return false;
	}

	return true;
}

int main()
{
	string input1, input2;

	while( cin >> input1 && cin >> input2 )

	{
		cout << input1 << " , " << input2 << 
			" are permutations? " << is_permutation( input1, input2 ) << endl;
	}
}
