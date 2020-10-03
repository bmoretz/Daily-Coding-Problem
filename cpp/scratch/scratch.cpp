#include <bits/stdc++.h>

/* 126. Word Ladder II.

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s)
from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:

beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class word_ladder_ii {

    static std::string to_wildcard( const std::string& word, const int index )
    {
        return word.substr( 0, index ) + "*" + word.substr( index + 1, word.length() );
    }

    static std::unordered_map<std::string, std::vector<std::string>> to_graph( const std::vector<std::string>& word_list )
    {
        std::unordered_map<std::string, std::vector<std::string>> graph;

        for( auto& word : word_list )
        {
            for( auto index = std::size_t(); index < word.length(); ++index )
            {
                graph[ to_wildcard( word, index ) ].push_back( word );
            }
        }

        return graph;
    }

public:

    static std::vector<std::vector<std::string>> findLadders( const std::string& begin_word,
        const std::string& end_word, 
        const std::vector<std::string>& word_list )
    {
        auto graph = to_graph( word_list );

        auto queue = std::queue<std::vector<std::string>>();
        queue.push( { begin_word } );
        std::set<std::string> seen;

        auto result = std::vector<std::vector<std::string>>();

        auto found = false;

        while( !queue.empty() )
        {
            auto len = queue.size();
            std::vector<std::string> seen_cur_level;

            for( auto level = 0; level < len; ++level )
            {
                std::vector<std::string> current_level = queue.front();
                queue.pop();

                auto prev = current_level.back();

                for( auto index = 0; index < prev.size(); ++index )
                {
                    const auto wc = to_wildcard( prev, index );

                    for( auto& adj_word : graph[ wc ] )
                    {
                        if( seen.find( adj_word ) != seen.end() )
                            continue;

                        std::vector<std::string> cur = current_level;

                        cur.push_back( adj_word );
                        seen_cur_level.push_back( adj_word );

                        if( adj_word == end_word )
                        {
                            found = true;
                            result.push_back( cur );
                        }
                        else
                        {
                            queue.push( cur );
                        }
                    }
                }
            }

            if( found )
                break;

            for( auto w : seen_cur_level )
                seen.insert( w );
        }

        return result;
    }
};

auto main() -> int
{

    const auto result = word_ladder_ii::findLadders( "hit", "cog", { "hot","dot","dog","lot","log","cog" } );
	
	
	return 0;
}
