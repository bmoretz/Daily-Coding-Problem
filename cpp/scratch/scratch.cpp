#include <bits/stdc++.h>
#include <array>

/* 127. Word Ladder.

Given two words (beginWord and endWord), and a dictionary's word list, find the
length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class word_ladder
{
	static std::string to_wildcard( const std::string& str, const std::size_t index )
	{
		return str.substr( 0, index ) + '*' + str.substr( index + 1, str.size() );
	}
	
	static std::unordered_map<std::string, std::vector<std::string>> to_word_graph( const std::vector<std::string>& word_list )
	{
		std::unordered_map<std::string, std::vector<std::string>> graph;

		for( auto& word : word_list )
		{	
			for( auto char_index = 0ULL; char_index < word.size(); ++char_index )
			{
				const auto new_word = to_wildcard( word, char_index );

				graph[ new_word ].push_back( word );
			}
		}
		
		return graph;
	}

	static int find_word_path( const std::string& begin_word, const std::string& end_word,
		std::unordered_map<std::string, std::vector<std::string>> word_graph )
	{
		auto queue = std::queue<std::pair<std::string, int>>();
		auto visited = std::set<std::string>();

		queue.push( std::make_pair( begin_word, 1 ) );
		visited.insert( begin_word );

		while( !queue.empty() )
		{
			const auto& [word, level] = queue.front();

			for( auto char_index = 0ULL; char_index < word.size(); ++char_index )
			{
				const auto wildcard = to_wildcard( word, char_index );

				for( auto& adj_word : word_graph[ wildcard ] )
				{
					if( adj_word == end_word )
					{
						return level + 1;
					}

					if( visited.find( adj_word ) == visited.end() )
					{
						visited.insert( adj_word );
						queue.push( { adj_word, level + 1 } );
					}
				}
			}

			queue.pop();
		}

		return 0;
	}
	
public:

	static int ladderLength( const std::string& begin_word, const std::string& end_word,
		const std::vector<std::string>& word_list )
	{
		const auto word_graph = to_word_graph( word_list );

		return find_word_path( begin_word, end_word, word_graph );
	}
};

auto main() -> int
{
	const auto input1 = std::tuple<std::string, std::string, std::vector<std::string>>
	{
		"hit", "cog",
		{ "hot", "dot", "dog", "lot", "log", "cog" }
	};

	const auto result = word_ladder::ladderLength( std::get<0>( input1 ), std::get<1>( input1 ), std::get<2>( input1 ) );
	
	return 0;
}