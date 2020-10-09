#include <bits/stdc++.h>

#include "../leetcode/tree.h"

using namespace leetcode::tree;

/* 139. Word Break.

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented
into a space-separated sequence of one or more dictionary words.

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

class word_breaks
{
	static auto to_set( const std::vector<std::string>& words )
    {
        auto set = std::set<std::string>();

        for( auto& word : words )
        {
            set.insert( word );
        }

        return set;
    }

public:

	static bool word_break( const std::string& input, 
        const std::vector<std::string>& word_dict )
    {
        auto word_set = to_set( word_dict );

        auto dp = std::vector<bool>( input.length() + 1 );
        dp[ 0 ] = true;

        for( auto stop = 1; stop <= input.length(); ++stop )
        {
            for( auto start = 0; start < stop; ++start )
            {
                const auto sub = input.substr( start, stop - start );

                if( dp[ start ] && word_set.find( sub ) != word_set.end() )
                {
                    dp[ stop ] = true;
                }
            }
        }

        return dp[ input.length() ];
    }
};

auto main() -> int
{
    const auto input1 = std::pair<std::string, std::vector<std::string>>(
        "aaaaaaa",
        { "aaa", "aaaa" }
	);

    const auto actual = word_breaks::word_break( input1.first, input1.second );

    const auto expected = 20;
	
	return 0;
}