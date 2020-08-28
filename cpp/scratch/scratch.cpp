#include <bits/stdc++.h>
#include <array>

/*758. Bold Words in String.

Given a set of keywords words and a string S, make all appearances of all keywords
in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course
the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return
"a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Constraints:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.
Note: This question is the same as 616: https://leetcode.com/problems/add-bold-tag-in-string/

*/

class bold_words
{
	static std::vector<bool> extract_mask( const std::vector<std::string>& words, const std::string& string )
	{
		auto mask = std::vector<bool>( string.size(), false );

		for( const auto& str : words )
		{
			auto pos = 0ULL;

			while( ( pos = string.find( str, pos ) ) != std::string::npos )
			{
				for( auto index = 0ULL; index < str.size(); ++index )
				{
					mask[ pos + index ] = true;
				}

				++pos;
			}
		}

		return mask;
	}

	static std::string insert_tags( const std::string& string, std::vector<bool> mask )
	{
		std::string result;
		auto status = false;

		for( auto index = 0ULL; index < mask.size(); ++index )
		{
			if( status == 0 )
			{
				if( mask[ index ] )
				{
					result += "<b>";
					status = true;
				}
			}
			else if( status == 1 )
			{
				if( !mask[ index ] )
				{
					result += "</b>";
					status = false;
				}
			}

			result += string[ index ];
		}

		if( status )
		{
			result += "</b>";
		}

		return result;
	}
	
public:

	static std::string bold( const std::vector<std::string>& words, const std::string& string )
	{
		const auto mask = extract_mask( words, string );

		return insert_tags( string, mask );
	}
};

auto main() -> int
{
	auto input = std::pair<std::vector<std::string>, std::string>
	{
		{ "ab", "bc" },
		"aabcd"
	};

	const auto result = bold_words::bold( input.first, input.second );
	
	return 0;
}
