#include <bits/stdc++.h>

/* 139. Word Break.

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can
be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class word_break_ii
{
public:

	static bool word_break( const std::string& str, const std::vector<std::string>& word_dict )
	{
		if( word_dict.empty() || str.empty() ) return false;

		const auto length = str.length();

		std::vector<bool> dp( length + 1, false );
		dp[ 0 ] = true;

		for( int index = 1; index <= str.length(); ++index )
		{
			for( auto& word : word_dict )
			{
				const int start_index = index - word.length();

				if( start_index < 0 || dp[ start_index ] == false ) continue;;

				if( word == str.substr(start_index, word.size() ) )
				{
					dp[ index ] = true;
					break;
				}
			}
		}

		return dp[ length ];
	}
};

auto main() -> int
{
    const auto input1 = std::pair<std::string, std::vector<std::string>>
	{
		"leetcode",
		{ "leet", "code" }
	};
	
	const auto input2 = std::pair<std::string, std::vector<std::string>>
	{
		"catsandog",
		{ "cats","dog","sand","and","cat" }
	};

	const auto input3 = std::pair<std::string, std::vector<std::string>>
	{
		"applepenapple",
		{ "apple", "pen" }
	};

	const auto input4 = std::pair<std::string, std::vector<std::string>>
	{
		"catsandog",
		{ "cats", "dog", "sand", "and", "cat" }
	};

	const auto input5 = std::pair<std::string, std::vector<std::string>>
	{
		"abcd",
		{ "abcd", "a","abc","b","cd" }
	};

    // const auto actual = word_break::wordBreak( input2.first, input2.second );
	const auto actual = word_break_ii::word_break( input4.first, input4.second );
	
    return 0;
}