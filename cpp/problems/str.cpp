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
	bool unique1::is_unique( const std::string & str )
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
	bool unique2::is_unique( const std::string & str )
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
	bool is_permutation1::is_permutation( const string & p, const string & q )
	{
		if( p.empty() || q.empty() ) return false;
		if( p.length() != q.length() ) return false;

		auto p_map = char_map( p ), q_map = char_map( q );

		for( auto item : p_map )
		{
			auto other = q_map.find( item.first );

			if( other == q_map.end() || item.second != other->second )
				return false;
		}

		return true;
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
	map<char, int> is_permutation1::char_map( const string & s )
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
	bool is_permutation2::is_permutation( string p, string q )
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
	/// This approach uses a forward iteration
	/// method on the characters in the array
	/// until a space is encountered. Once a
	/// space is found, then we push the remaining
	/// characters in the string backwards two places.
	/// Once the characters have been pushed back, we
	/// insert the delimiter character in place and continue
	/// the forward loop.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N^2)</run-time>
	///		<space>O(1)</space>
	/// </complexity>
	/// <param name="input">string to urlify</param>
	/// <param name="length">output buffer size</param>
	/// <returns>urlify'd string</returns>
	string urlify1::urlify( string input, const size_t length )
	{
		if( input.length() == 0 ) return input;

		size_t n_spaces = 1;

		for( auto index = 0; index < input.length(); index++ )
		{
			if( input[ index ] == ' ' )
			{
				for( auto sub = ( n_spaces * 2 - 1 ) + length; sub > index + 2; sub-- )
				{
					input[ sub ] = input[ sub - 2 ];
					input[ sub - 1 ] = input[ sub - 3 ];
				}

				input[ index++ ] = '%';
				input[ index++ ] = '2';
				input[ index ] = '0';

				n_spaces++;
			}
		}

		return input;
	}

	/// <summary>
	/// count_spaces
	/// 
	/// This method takes a string and an length and returns
	/// the number of spaces encountered between the beginning
	/// and the length index.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(1)</space>
	/// </complexity>
	/// <param name="input">string to search</param>
	/// <param name="length">number of characters to search</param>
	/// <returns>number of spaces in input[0, length]</returns>
	size_t urlify2::count_spaces( const string & input, const size_t length )
	{
		if( input.empty() ) return 0;

		auto n_spaces = size_t();

		for( auto index = size_t(); index < length; ++index )
		{
			if( input[ index ] == ' ' )
				n_spaces++;
		}

		return n_spaces;
	}

	/// <summary>
	/// urlify2
	/// 
	/// This approach uses backwards iteration to first count
	/// the total number of spaces in the string. This number is
	/// then used to construct an offset which points to the last
	/// character in the array. The input array is updated by:
	/// position = [current index]
	/// offset = [number of spaces * 2]
	/// Therefore,
	/// length + offset = end of array index
	/// when a space is encountered, we increment the space counter
	/// so that we can decrement our offset by 2 * S, S = number of spaces.
	/// 
	/// This approach leaves us with room to insert the '%20' character backwards
	/// while we are filling in the rest of the array with the offset position.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(1)</space>
	/// </complexity>
	/// <param name="input">the string to update</param>
	/// <param name="length">the length of the valid string</param>
	/// <returns>urlifiy'd string contents</returns>
	string urlify2::urlify( string input, const size_t length )
	{
		if( input.length() == 0 ) return input;

		const auto n_spaces = count_spaces( input, length );
		const auto offset = n_spaces * 2;

		auto encountered = 0, position = static_cast<int>(length) - 1;

		do
		{
			const auto current = input[ position ];
			const auto new_position = position + offset - ( encountered * 2 );

			if( current == ' ' )
			{
				input[ new_position ] = '0';
				input[ new_position - 1 ] = '2';
				input[ new_position - 2 ] = '%';

				encountered++;
			}
			else
			{
				input[ new_position ] = input[ position ];
			}

			position--;

		} while( position != -1 );

		return input;
	}
}