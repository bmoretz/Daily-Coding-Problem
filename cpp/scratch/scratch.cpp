#include <bits/stdc++.h>
#include <array>

/* 567. Permutation in String.

Given two strings s1 and s2, write a function to return true if s2 contains the
permutation of s1. In other words, one of the first string's permutations is the
substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

 Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class permutation_in_string
{
	/// <summary>
	/// get character frequency
	///
	/// gets a char frequency array where the index is the letter and the value
	/// at that position is the number of those characters in the string.
	/// </summary>
	/// <param name="str">string to map</param>
	/// <returns>char map as char array</returns>
	static std::array<unsigned short, 26> get_char_freq( const std::string& str )
	{
		std::array<unsigned short, 26> freq{};

		const int offset = 'a';

		for( int chr : str )
		{
			const auto value = chr - offset;
			freq[ value ]++;
		}

		return freq;
	}

public:

	/// <summary>
	/// check inclusion
	///
	/// using a sliding window to determine if there is an anagram of s1 inside s2.
	/// </summary>
	/// <param name="s1">string 1</param>
	/// <param name="s2">string 2</param>
	/// <returns>true if there is a permutation (anagram) of s1 inside s2.</returns>
	static bool checkInclusion( const std::string& s1, const std::string& s2 )
	{
		// no solution possible
		if( s1.length() > s2.length() ) return false;

		const std::size_t offset = 'a';

		// create maps of s1 and the first n (len of s1) chars of s2
		const auto s1_map = get_char_freq( s1 );
		auto s2_map = get_char_freq( s2.substr( 0, s1.size() ) );

		// if these equal we stop
		if( s1_map == s2_map )
			return true;

		// otherwise, for each index starting at s1 size
		for( auto index = s1.size(); index < s2.length(); ++index )
		{
			// remove the previous character which is offset by the size of s1 in s2	
			--s2_map[ s2[ index - s1.size() ] - offset ];
			// increment the current character of s2
			++s2_map[ s2[ index ] - offset ];

			// compare maps
			if( s1_map == s2_map )
				return true;
		}

		// no match
		return false;
	}
};

auto main() -> int
{
	const auto input1 = std::make_pair<std::string, std::string>( "ab", "eidbaooo" );
	const auto input2 = std::make_pair<std::string, std::string>( "ab", "eidboaoo" );
	const auto input3 = std::make_pair<std::string, std::string>( "adc", "dcda" );
	
	// const auto actual = word_break::wordBreak( input2.first, input2.second );
	const auto actual = permutation_in_string::checkInclusion( input3.first, input3.second );

	return 0;
}