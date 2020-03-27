#include "pch.h"
#include "str.h"

using namespace std;

bool str::is_unique1( std::string str )
{
	auto unique = false;

	set<char> words = set<char>();

	for( int index = 0; index < str.length(); ++index )
	{
		auto current = str.at( index );

		if( words.find( current ) != words.end() )
			return false;

		words.insert( current );
	}

	return true;
}

bool str::is_unique2( std::string str )
{
	return false;
}
