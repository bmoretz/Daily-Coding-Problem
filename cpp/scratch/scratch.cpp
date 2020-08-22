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

class word_break
{
	struct tree_node
	{
		bool is_valid = false;
		std::map<char, std::unique_ptr<tree_node>> children;
	};
	
public:

	static std::unique_ptr<tree_node> build_trie( const std::vector<std::string>& word_dict )
	{
		auto root = std::make_unique<tree_node>();

		auto node = root.get();
		
		for( auto& word : word_dict )
		{
			auto temp = root.get();

			for( auto c : word )
			{
				if( temp->children.find( c ) != temp->children.end() )
				{
					temp = temp->children[ c ].get();
				}
				else
				{
					temp->children[ c ] = std::make_unique<tree_node>();
					temp = temp->children[ c ].get();
				}

				temp->is_valid = true;
			}
		}

		return root;
	}
	
    static bool wordBreak( const std::string& str, const std::vector<std::string>& word_dict )
	{
		const auto trie = build_trie( word_dict );

		std::vector<bool> found( str.size() + 1, false );
		found[ 0 ] = true;

		for( auto index = 0ULL; index < str.size(); ++index )
		{
			if( found[index] )
			{
				auto node = trie.get();
				
				for( auto sub = index; sub < str.size(); ++sub )
				{
					const char current = str[ sub ];
					
					if( !node->children[ current ] ) break;

					node = node->children[ current ].get();

					found[ sub + 1 ] = found[ sub + 1 ] || node->is_valid;
				}
			}
		}

		return found[ str.size() ];
    }
};

auto main() -> int
{
    const auto input1 = std::pair<std::string, std::vector<std::string>>
	{
		"leetcode",
		{ "leet", "code" }
	};
	
	const auto input2 = std::vector<int>{ 1, 2, 3 };
	const auto input3 = std::vector<int>{ 1, 1, 1 };
	
    const auto actual = word_break::wordBreak( input1.first, input1.second );
	
    return 0;
}