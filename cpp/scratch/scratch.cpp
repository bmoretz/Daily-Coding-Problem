#include <bits/stdc++.h>

/*211. Design Add and Search Words Data Structure.

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.'
where dots can be matched with any letter.
 
Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
*/

class word_dictionary
{
    struct trie_node
    {
        std::unordered_map<char, std::unique_ptr<trie_node>> children;
        bool is_terminal{false};
    };

    std::unique_ptr<trie_node> root_;

public:

    word_dictionary()
    {
        root_ = std::make_unique<trie_node>();
    }

    void add_word( const std::string& word ) const
    {
        auto node = root_.get();

        for( auto chr : word )
        {
            if( node->children.find( chr ) == node->children.end() )
            {
                node->children[ chr ] = std::make_unique<trie_node>();
            }

            node = node->children[ chr ].get();
        }

        node->is_terminal = true;
    }

    static bool search_node( const std::string& str, trie_node* node )
    {
        for( auto index = 0; index < str.length(); ++index )
        {
            auto chr = str.at( index );

            if( node->children.find( chr ) == node->children.end() )
            {
                if( chr == '.' )
                {
                    for( auto& [k, v] : node->children )
                    {
                        const auto child = node->children[ k ].get();
                        const auto sub = str.substr( index + 1, str.length() );

                        if( search_node( sub, child ) )
                            return true;
                    }
                }

                return false;
            }
            else
            {
                node = node->children[ chr ].get();
            }
        }

        return node->is_terminal;
    }

    bool search( const std::string& word ) const
    {
        return search_node( word, root_.get() );
    }
};

auto main() -> int
{
    const auto searcher = word_dictionary();
	
    searcher.add_word( "bad" );
    searcher.add_word( "dad" );
    searcher.add_word( "mad" );
	
    searcher.search( "pad" );
	
	return 0;
}