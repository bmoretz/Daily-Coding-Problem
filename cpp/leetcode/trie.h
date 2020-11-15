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
            // we don't care because we are checking the previous letter
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

    /*677. Map Sum Pairs.

    Implement the MapSum class:

    MapSum() Initializes the MapSum object.
    void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
    int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

    Example 1:

    Input
    ["MapSum", "insert", "sum", "insert", "sum"]
    [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
    Output
    [null, null, 3, null, 5]

    Explanation
    MapSum mapSum = new MapSum();
    mapSum.insert("apple", 3);
    mapSum.sum("ap");           // return 3 (apple = 3)
    mapSum.insert("app", 2);
    mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

    Constraints:

    1 <= key.length, prefix.length <= 50
    key and prefix consist of only lowercase English letters.
    1 <= val <= 1000
    At most 50 calls will be made to insert and sum.
    */

    class map_sum
    {
        struct trie_node
        {
            std::unordered_map<char, std::unique_ptr<trie_node>> children;
            std::unordered_map<std::string, int> values;
        };

        std::unique_ptr<trie_node> root_;

    public:

        map_sum()
        {
            root_ = std::make_unique<trie_node>();
        }

        void insert( const std::string& key, const int val ) const
        {
            auto node = root_.get();

            for( auto chr : key )
            {
                if( node->children.find( chr ) == node->children.end() )
                {
                    node->children[ chr ] = std::make_unique<trie_node>();
                }

                node = node->children[ chr ].get();
                node->values[ key ] = val;
            }
        }

        int sum( const std::string& prefix ) const
        {
            auto node = root_.get();

            for( auto chr : prefix )
            {
                if( node->children.find( chr ) == node->children.end() )
                {
                    return 0;
                }

                node = node->children[ chr ].get();

            }

            auto result = 0;

            for( auto& [k, v] : node->values )
            {
                result += v;
            }

            return result;
        }
    };

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
            bool is_terminal{ false };
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
            bool is_terminal{ false };
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

    /*425. Word Squares.

    Given a set of words (without duplicates), find all word squares you can build from them.

    A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 <= k <
    max(numRows, numColumns).

    For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the
    same both horizontally and vertically.

    b a l l
    a r e a
    l e a d
    l a d y

    Note:
    There are at least 1 and at most 1000 words.
    All words will have the exact same length.
    Word length is at least 1 and at most 5.
    Each word contains only lowercase English alphabet a-z.
    Example 1:

    Input:
    ["area","lead","wall","lady","ball"]

    Output:
    [
      [ "wall",
        "area",
        "lead",
        "lady"
      ],
      [ "ball",
        "area",
        "lead",
        "lady"
      ]
    ]

    Explanation:
    The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
    Example 2:

    Input:
    ["abat","baba","atan","atal"]

    Output:
    [
      [ "baba",
        "abat",
        "baba",
        "atan"
      ],
      [ "baba",
        "abat",
        "baba",
        "atal"
      ]
    ]

    Explanation:
    The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
    */

    class word_squares
    {
        // trie structure that maps characters -> children (standard)
        // and we also save each full word that starts with the same letters
        // e.g., for wall | walt -> w | a | l, both words would be stored in the
        // first 3 nodes (w, a & l)
        struct trie_node
        {
            std::unordered_map<char, trie_node*> children;
            std::vector<std::string> prefixes;
        };

        // add a word to the trie
        static void insert_word( trie_node* root,
            const std::string& word )
        {
            auto node = root;

            for( auto chr : word )
            {
                if( node->children.find( chr ) == node->children.end() )
                {
                    node->children[ chr ] = new trie_node();
                }

                node = node->children[ chr ];

                node->prefixes.push_back( word );
            }
        }

        // takes a list of words and returns a trie (the root)
        static trie_node* build_trie( const std::vector<std::string>& words )
        {
            const auto root = new trie_node();

            for( const auto& word : words )
            {
                insert_word( root, word );
            }

            return root;
        }

        // try to place words in the grid based on the position
        static void try_place_words( std::vector<std::vector<std::string>>& result,
            std::vector<std::string>& board,
            const std::vector<std::string>& words,
            trie_node* trie,
            const int row )
        {
            const int num_rows = board.size();

            // terminal condition, we've reached past the end of
            // the length of the word (row > N)
            if( row == num_rows )
            {
                result.push_back( board );
                return;
            }

            auto node = trie;

            // iterate the trie letter by letter of the current
            // word getting the possible next list of next words
            // character by character
            for( auto index = 0; index < row; ++index )
            {
                const auto chr = board[ index ][ row ];

                // if any non-match, this combination can't work
                if( node->children.find( chr ) == node->children.end() )
                    return;

                node = node->children[ chr ];
            }

            // replace (with backtracking) each word that could be a
            // potential match
            for( const auto& replace : node->prefixes )
            {
                board[ row ] = replace;

                try_place_words( result, board, words, trie, row + 1 );
            }
        }

    public:

        static std::vector<std::vector<std::string>> wordSquares( const std::vector<std::string>& words )
        {
            const int N = words[ 0 ].size();
            const auto trie = build_trie( words ); // ptr to our trie root

            // the result set of the word combinations that work
            auto result = std::vector<std::vector<std::string>>();

            // the current board will be a list of N words (n=length of any given word since all same length)
            auto board = std::vector<std::string>( N );

            for( auto index = 0; index < words.size(); ++index )
            {
                // place the word in the first row
                board[ 0 ] = words[ index ];

                // then recursively try to fill the remaining positions
                try_place_words( result, board, words, trie, 1 );
            }

            return result;
        }
    };
}