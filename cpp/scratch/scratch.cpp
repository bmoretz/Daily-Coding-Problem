#include <bits/stdc++.h>

/*425. Word Squares.

Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

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

auto main() -> int
{
    const auto input = std::vector<std::string>{
        "area", "lead", "wall", "lady", "ball", "walt"
    };

    const auto actual = word_squares::wordSquares( input );

    const auto expected = std::vector<std::vector<std::string>>
    {
		
    };
	
	return 0;
}