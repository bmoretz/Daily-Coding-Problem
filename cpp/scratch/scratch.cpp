#include <bits/stdc++.h>
#include <array>

/* 819. Most Common Word.

Given a paragraph and a list of banned words, return the most frequent word that is not in
the list of banned words.  It is guaranteed there is at least one word that isn't banned,
and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the
paragraph are not case sensitive.  The answer is in lowercase.

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"

Explanation: 

"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 
Note:

1 <= paragraph.length <= 1000.
0 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.

*/

class most_common_word
{
	static std::vector<std::string> get_tokens( const std::string& data )
	{
		auto cleaned = std::string{ };
		cleaned.resize( data.size() );
		
		std::transform( data.begin(), data.end(), cleaned.begin(), 
			[]( const auto chr )
		{
			if( ::ispunct( chr ) ) return ' ';
			
			return static_cast<char>( ::tolower( chr ) );
		});
		
		std::istringstream iss( cleaned );

		std::vector<std::string> tokens( ( std::istream_iterator<std::string>( iss ) ),
			std::istream_iterator<std::string>() );

		return tokens;
	}
	
public:

	static std::string get_most_common( const std::string& paragraph,
		const std::vector<std::string>& banned )
	{
		std::set<std::string> exclude( banned.begin(), banned.end() );

		// get tokens
		auto tokens = get_tokens( paragraph );

		auto map = std::unordered_map<std::string, int>();

		std::pair<int, std::string> result = { -1, "" };

		for( auto& word : tokens )
		{	
			// skip banned
			if( exclude.find( word ) != exclude.end() )
				continue;

			++map[ word ];

			if( map[ word ] > result.first )
			{
				result = { map[ word ], word };
			}
		}

		return result.second;
	}
};

auto main() -> int
{
	const auto input1 = std::pair<std::string, std::vector<std::string>>
	{
		"Bob hit a ball, the hit BALL flew far after it was hit.",
		std::vector<std::string>{ "hit" }
	};
	
	const auto input2 = std::pair<std::string, std::vector<std::string>>
	{
		"a.",
		std::vector<std::string>{ }
	};

	const auto input3 = std::vector<int>
	{
		1, 2
	};
	
	const auto result = most_common_word::get_most_common( input2.first, input2.second );
	
	return 0;
}