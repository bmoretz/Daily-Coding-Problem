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

		const auto offset = static_cast< int >( 'a' );

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
		if( input.length() == 0 ) return {};

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
		if( input.length() == 0 ) return {};

		const auto n_spaces = count_spaces( input, length );
		const auto offset = n_spaces * 2;

		auto encountered = 0, position = static_cast< int >( length ) - 1;

		do
		{
			const auto current = input[ position ];
			const unsigned int space_offset = encountered * 2;
			const auto new_position = position + offset - space_offset;

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

	/// <summary>
	/// char_map
	/// 
	/// This method takes a string and returns a look-up
	/// of the characters contained in the string as keys
	/// and the number of occurrences as values.
	/// 
	/// This version of char_map does not count spaces, commas,
	/// or any non-alpha-numeric characters.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="input">the string to map</param>
	/// <returns>map of characters and their respective counts.</returns>
	map<char, int> palperm1::char_map( const string & input )
	{
		map<char, int> map;

		if( input.empty() ) return map;

		static const auto lower = static_cast< int >( 'a' ),
			upper = static_cast< int >( 'z' );

		for( auto character : input )
		{
			const auto current = tolower( character );

			if( current < lower || current > upper )
				continue;

			if( map.find( current ) != map.end() )
				map[ current ]++;
			else
				map[ current ] = 1;
		}

		return map;
	}

	/// <summary>
	/// is_palindrome_permutation
	///
	/// This approach first makes a character map out of the
	/// input string (excluding non-alpha-numeric/whitespace characters)
	/// and then counts the occurrences of characters that have odd counts.
	/// In order for the string to be a permutation of a palindrome, we
	/// cannot have more than 1 occurence of an odd character, in which
	/// case we can safely short-circuit the loop.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="input"></param>
	/// <returns>if input is a palindrome permutation</returns>
	bool palperm1::is_palindrome_permutation( const string & input )
	{
		if( input.empty() ) return false;

		auto map = char_map( input );

		auto n_odd = 0;

		for( auto iter = map.begin(); iter != map.end(); ++iter )
		{
			if( iter->second % 2 == 1 ) {
				n_odd++;

				if( n_odd >= 1 )
					break;
			}
		}

		return n_odd <= 1;
	}

	/// <summary>
	/// find_first_invariant
	///
	/// This method is essentially a case-invariant
	/// version of std::find.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(1)</space>
	/// </complexity>
	/// <param name="str">The string to search</param>
	/// <param name="search">the character to find</param>
	/// <returns>first position of search in str</returns>
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

	/// <summary>
	/// one_away1
	///
	/// This is a brute-force version that simply
	/// takes the shorter string character by character
	/// away from the longer string, and then returns
	/// true if the remaining length of the longer string
	/// is greater than 1. There is one short-circuit condition
	/// on the lengths, anything greater than a delta of 1 is immediately
	/// returned as false.
	/// </summary>
	/// <complexity>
	///		<run-time>O(K*J)</run-time>
	///		<space>O(K + J)</space>
	/// </complexity>
	/// <param name="str1">first string</param>
	/// <param name="str2">second string</param>
	/// <returns>true if first and second are 1 edit away</returns>
	bool one_away1::one_away( const string & str1, const string & str2 )
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

	/// <summary>
	/// compressed1
	///
	/// This approach simply iterates over the input
	/// string starting at the 1st offset, having saved the
	/// first character in the previous variable. Each iteration
	/// we check to see if prev == current, and if so, increment,
	/// otherwise we copy the compressed version of the character
	/// (letter + count) to the final compressed string. After the loop
	/// terminates we copy the remaining characters in the string to the output
	/// buffer (this also handles the base case of a single character, many times).
	///
	/// We finally return the smaller of the two strings, input and compressed.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="input">string to compress</param>
	/// <returns>the smaller of the two strings, input and compressed</returns>
	string compress_str1::compressed( const string & input )
	{
		if( input.empty() ) return {};

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

	/// <summary>
	/// string_rotations
	///
	/// returns a set of all rotations of the passed in string.
	/// </summary>
	/// <complexity>
	///		<run-time>O(N)</run-time>
	///		<space>O(N)</space>
	/// </complexity>
	/// <param name="input">the string to rotate</param>
	/// <returns>all possible rotations</returns>
	std::vector<std::string> string_rotation1::get_rotations( const std::string & input )
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

	/// <summary>
	/// is_substring
	///
	/// returns true of needle is in haystack.
	/// </summary>
	/// <param name="haystack">string to search</param>
	/// <param name="needle">what to find</param>
	/// <returns>returns true of needle is in haystack</returns>
	bool string_rotation1::is_substring( const std::string & haystack, const std::string & needle )
	{
		return haystack.find( needle ) != string::npos;
	}

	/// <summary>
	/// is rotation 1
	///
	/// This approach generates all possible rotations of the input string s1,
	/// and then generates a pipe delimited compound string that contains all the
	/// rotations. This compound string can then be used for the single call of
	/// is_substring to determine if s1 is a rotation of s2.
	/// </summary>
	///		<run-time>O(N)</run-time>
	///		<space>O(N + L)</space>
	/// </complexity>
	/// <param name="s1">first string</param>
	/// <param name="s2">second string</param>
	/// <returns>true if s2 is a rotation of s1</returns>
	bool string_rotation1::is_rotation( const std::string & s1, const std::string & s2 )
	{
		if( s1.empty() || s2.empty() ) return false;
		if( s1.length() != s2.length() ) return false;

		auto rotations = get_rotations( s1 );

		auto rotations_string = string();

		for( auto it = rotations.begin(); it != rotations.end(); ++it )
		{
			rotations_string += *it + "|";
		}

		return is_substring( rotations_string, s2 );
	}

	/// <summary>
	/// string rotation 2
	///
	/// This approach uses a "two pointers" approach to walking the strings,
	/// which effectively eliminates the need for even one call to "is_substring" by
	/// walking the pointer through s2 until we find the first character in s1. Once we find
	/// a possible rotation start, we walk both forward while they match (looping s2 back to zero
	/// if we reach the end), and if we can walk all the way through the end of s1 while matching,
	/// they are rotations. If we find a discrepancy during the walk of s11, we restart the s1 pointer
	/// and continue s2 from the previous iterations end.
	/// </summary>
	/// </summary>
	///		<run-time>O(I + J)</run-time>
	///		<space>O(1)</space>
	/// </complexity>
	/// <param name="s1">string to search</param>
	/// <param name="s2">string to find</param>
	/// <returns>true if s1 is a rotation of s2</returns>
	bool string_rotation2::is_rotation( const std::string & s1, const std::string & s2 )
	{
		if( s1.empty() || s2.empty() ) return false;
		if( s1.length() != s2.length() ) return false;

		auto i = size_t(), j = size_t();

		while( j < s2.length() )
		{
			if( s1[ i ] == s2[ j ] )
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
}