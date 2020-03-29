#include "pch.h"
#include "str.h"

#include <set>
#include <algorithm>

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
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="str">the string to check</param>
	/// <returns></returns>
	bool str::is_unique1( const std::string & str )
	{
		if( str.empty() ) return false;

		auto words = set<char>();

		for( auto iter = str.begin(); iter != str.end(); ++iter )
		{
			const auto current = *iter;

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
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(1)</space>
	/// </complexity>
	/// <param name="str">string to test</param>
	/// <returns></returns>
	bool str::is_unique2( const std::string & str )
	{
		if( str.empty() ) return false;

		auto seen = 0;

		const auto offset = static_cast<int>('a');

		for( auto character : str )
		{
			const auto value = character - offset;
			const auto position = 0x1 << value;

			if( seen >> value & 0x1 )
				return false;

			seen |= position;
		}

		return true;
	}

	/// <summary>
	/// is_permutation1
	/// 
	/// This approach uses a character occurence map
	/// of the two strings. If there are any differences 
	/// in the two maps, we return false (first one, short-circuit).
	/// </summary>
	/// <complexity>
	///		<run-time>O(PQ)</run-time>
	///		<space>O(P + Q)</space>
	/// </complexity>
	/// <param name="p">string p</param>
	/// <param name="q">string q</param>
	/// <returns>true if p and q are permutations of each other.</returns>
	bool str::is_permutation1( const string & p, const string & q )
	{
		if( p.empty() || q.empty() ) return false;
		if( p.length() != q.length() ) return false;

		auto p_map = utility::char_map( p ), q_map = utility::char_map( q );

		for( auto item : p_map )
		{
			auto other = q_map.find( item.first );

			if( other == q_map.end() || item.second != other->second )
				return false;
		}

		return true;
	}

	/// <summary>
	/// is_permutation2
	/// 
	/// This approach sorts both of the passed in strings
	/// and then performs an element-by-element comparision
	/// on the sorted results. If any difference is found
	/// in the sorted results, we know they cannot be
	/// permutations of each other.
	/// </summary>
	/// <complexity>
	///		<run-time>O(n log n)</run-time>
	///		<space>O(P + Q)</space>
	/// </complexity>
	/// <param name="p">string p</param>
	/// <param name="q">string q</param>
	/// <returns>true if p and q are permutations of each other.</returns>
	bool str::is_permutation2( string p, string q )
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

	/// <summary>
	/// urlify1
	/// 
	/// This approach initializes a new buffer
	/// string the length of the expected output size
	/// parameter, and populates each character from the
	/// input array. We keep track of the current result
	/// position with a second output_pos variable, incrementing
	/// it within each character assignment operation.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="input">string to urlify</param>
	/// <param name="length">output buffer size</param>
	/// <returns>urlify'd string</returns>
	string str::urlify1( const string & input, const size_t length )
	{
		if( input.length() == 0 ) return nullptr;

		auto output = string( length, ' ' );
		auto output_pos = 0;

		for( auto current : input )
		{
			if( current == ' ' )
			{
				output[ output_pos++ ] = '%';
				output[ output_pos++ ] = '2';
				output[ output_pos++ ] = '0';
				continue;
			}

			output[ output_pos++ ] = current;
		}

		_ASSERT( output.length() == length );

		return output;
	}

	/// <summary>
	/// char_map
	/// 
	/// Creates a map of the number of occurrences of a 
	/// character has in the passed in string.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="s">the string</param>
	/// <returns>map of occurrences</returns>
	map<char, int> utility::char_map( const string & s )
	{
		map<char, int> mp;

		for( auto character : s )
		{
			auto it = mp.find( character );

			if( it == mp.end() )
			{
				mp[ character ] = 0;
			}
			else
			{
				it->second++;
			}
		}

		return mp;
	}
}