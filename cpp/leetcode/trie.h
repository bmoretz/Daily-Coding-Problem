#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

namespace leetcode::trie
{
    /*208. Implement Trie (Prefix Tree).

    Implement a trie with insert, search, and startsWith methods.

    Example:

    Trie trie = new Trie();

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");
    trie.search("app");     // returns true

    Note:

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.
    */

    class trie
    {
        /// <summary>
        /// trie node definition
        /// </summary>
        class trie_node
        {
        public:

            char val{};
            std::unordered_map<char, std::unique_ptr<trie_node>> children;
            bool is_word = false;

            explicit trie_node( const char value )
                : val{ value }
            {}
        };

        std::unique_ptr<trie_node> root_;

        trie_node* find_child( const std::string& to_find ) const
        {
            auto current = root_.get();

            for( auto chr : to_find )
            {
                if( current->children.find( chr ) ==
                    current->children.end() )
                {
                    return nullptr;
                }

                current = current->children[ chr ].get();
            }

            return current;
        }

    public:

        trie()
        {
            root_ = std::make_unique<trie_node>( 0 );
        }

        void insert( const std::string& word ) const
        {
            auto current = root_.get();

            for( auto chr : word )
            {
                if( current->children.find( chr ) == current->children.end() )
                {
                    current->children[ chr ] = std::make_unique<trie_node>( chr );
                }

                current = current->children[ chr ].get();
            }

            current->is_word = true;
        }

        bool search( const std::string& word ) const
        {
            const auto child = find_child( word );

            return child && child->is_word;
        }

        bool starts_with( const std::string& prefix ) const
        {
            return find_child( prefix );
        }
    };

    /*212. Word Search II.

    Given a 2D board and a list of words from the dictionary, find all words in the board.

    Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those
    horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

    Example:

    Input:
    board = [
      ['o','a','a','n'],
      ['e','t','a','e'],
      ['i','h','k','r'],
      ['i','f','l','v']
    ]
    words = ["oath","pea","eat","rain"]

    Output: ["eat","oath"]


    Note:

    All inputs are consist of lowercase letters a-z.
    The values of words are distinct.
    */

    class word_search_ii
    {
        struct trie_node
        {
            char val;
            std::unordered_map<char, trie_node*> children;
            std::string the_word;

            bool is_word = false;

            explicit trie_node( const char value )
                : val{ value }
            {}
        };

        static void insert_word( trie_node* root, const std::string& word )
        {
            auto cur = root;

            for( auto chr : word )
            {
                if( cur->children.find( chr ) == cur->children.end() )
                {
                    cur->children[ chr ] = new trie_node( chr );
                }

                cur = cur->children[ chr ];
            }

            cur->the_word = word;
            cur->is_word = true;
        }

        static void searcher( const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited,
            trie_node* root, const int row, const int col, std::vector<std::string>& results )
        {
            // if the current node is a terminal node, add the
            // word associated to the previous letter from the trie
            // to the result set.
            // this is done first because the index of the recursive
            // calls could be beyond the bounds of the board, but
            // we dont care because we are checking the previous letter
            // for a terminal condition.
            if( root->is_word )
            {
                results.push_back( root->the_word );
                root->is_word = false;
            }

            // out of bounds
            if( row < 0 || row >= board.size() ) return;
            if( col < 0 || col >= board[ 0 ].size() ) return;
            if( visited[ row ][ col ] ) return;

            // mark visited (temporary)
            visited[ row ][ col ] = true;
            const auto cur_letter = board[ row ][ col ];

            if( root->children.find( cur_letter ) != root->children.end() )
            {
                // traverse the adjacent cells
                const auto new_node = root->children[ cur_letter ];

                searcher( board, visited, new_node, row - 1, col, results );
                searcher( board, visited, new_node, row + 1, col, results );
                searcher( board, visited, new_node, row, col - 1, results );
                searcher( board, visited, new_node, row, col + 1, results );
            }

            // backtrack
            visited[ row ][ col ] = false;
        }

    public:

        static std::vector<std::string> find_words( const std::vector<std::vector<char>>& board,
            const std::vector<std::string>& words )
        {
            // initialize the result set vector
            auto results = std::vector<std::string>();

            // if we have an empty board, return
            if( board.empty() || board[ 0 ].empty() )
                return results;

            // initialize an empty trie root node
            const auto root = new trie_node( 0 );

            // add all the words to search for to the trie
            for( auto& word : words )
            {
                insert_word( root, word );
            }

            // visited for the dfs
            auto visited = std::vector<std::vector<bool>>( board.size(),
                std::vector<bool>( board[ 0 ].size(), false ) );

            for( auto row = 0; row < board.size(); ++row )
            {
                for( auto col = 0; col < board[ 0 ].size(); ++col )
                {
                    searcher( board, visited, root, row, col, results );
                }
            }

            return results;
        }
    };

	
}