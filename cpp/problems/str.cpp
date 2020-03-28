#include "pch.h"
#include "str.h"

using namespace std;

namespace str_problems 
{
	/// <summary>
	/// is_unique1
	/// 
	/// This approach uses a set data structure
	/// to store all the characters in the string
	/// while we iterate over it. If the set contains
	/// the current character, return false as the
	/// string is not unique.
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	bool str::is_unique1( std::string str )
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

	/// <summary>
	/// is_unique2
	/// 
	/// This approach uses an internal an internal bit array
	/// to store the characters seen in the string. If we already
	/// have that characters bit set when we see it again, return
	/// false to indicate the string does not contain all unique characters.
	/// </summary>
	/// <param name="str">string to test</param>
	/// <returns></returns>
	bool str::is_unique2( std::string str )
	{
		int seen = 0;
		int offset = ( int )'a';

		for( int index = 0; index < str.length(); ++index )
		{
			int value = ( ( int )str.at( index ) - offset );

			int position = 0x1 << value;

			if( seen >> value & 0x1 )
				return false;

			seen |= position;
		}

		return true;
	}
}