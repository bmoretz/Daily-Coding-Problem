﻿#include <bits/stdc++.h>

/*648. Replace Words.

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word
successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the
sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
Example 3:

Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
Output: "a a a a a a a a bbb baba a"
Example 4:

Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 5:

Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
Output: "it is ab that this solution is ac"
 
Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 10^6
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Each two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/

class replace_words
{
    struct trie_node
    {
        std::unordered_map<char, trie_node*> children;
        std::string word;
        bool is_terminal{false};
    };

    static std::vector<std::string> to_words( const std::string& sentence )
    {
        auto result = std::vector<std::string>();

        std::string token;
        std::stringstream ss( sentence );

        while( std::getline( ss, token, ' ' ) )
        {
            result.push_back( token );
        }

        return result;
    }

    trie_node* root_ = new trie_node();

    void insert_word( const std::string& word ) const
    {
        auto node = root_;

        for( auto chr : word )
        {
            if( node->children.find( chr ) == node->children.end() )
            {
                node->children[ chr ] = new trie_node();
            }

            node = node->children[ chr ];
        }

        node->word = word;
        node->is_terminal = true;
    }

    trie_node* get_replacement( const std::string& word ) const
    {
        auto node = root_;

        for( auto chr : word )
        {
            if( node->is_terminal || node->children.find( chr ) == node->children.end() )
                break;

            node = node->children[ chr ];
        }

        return node;
    }

public:

    std::string replaceWords( const std::vector<std::string>& dictionary, 
        const std::string& sentence ) const
    {
        for( auto& word : dictionary )
        {
            insert_word( word );
        }

        auto tokens = to_words( sentence );

        std::string result;

        for( auto& token : tokens )
        {
	        const auto replacement = get_replacement( token );

            if( replacement && replacement->is_terminal )
            {
                result += replacement->word;
            }
            else
            {
                result += token;
            }

            result += " ";
        }

        if( !result.empty() && result[ result.size() - 1 ] == ' ' )
            result.erase( result.end() - 1 );

        return result;
    }
};

auto main() -> int
{
	const auto replacer = replace_words();
	
    auto input = std::vector<std::string>{ "a", "aa", "aaa", "aaaa" };
	
    const auto actual = replacer.replaceWords( input, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa" );

    const auto expected = "a a a a a a a a bbb baba a";
	
	return 0;
}