#include <bits/stdc++.h>

/*336. Palindrome Pairs.

Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words
words[i] + words[j] is a palindrome.

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]] 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.
*/

class palindrome_pairs
{
	// trie structure
    struct trie_node
    {
        std::unordered_map<char, trie_node*> children;
        int word_id{ -1 }; // -1 used to represent not a word
        std::vector<int> prefixes; // word ids
    };

	// checks to see if str[index, end) is a palindrome
    static bool has_palindrome_remaining( const std::string& str, const int index )
    {
        int left = index, right = str.length() - 1;

        while( left < right )
        {
            if( str[ left ] != str[ right ] )
                return false;

            left++; right--;
        }

        return true;
    }

	// builds a trie from our word list
    static trie_node* build_trie( const std::vector<std::string>& words )
    {
        const auto root = new trie_node();

        for( auto word_id = 0; word_id < words.size(); ++word_id )
        {
        	// reverse the word in the word list
            auto word = words[ word_id ];
            std::reverse( word.begin(), word.end() );
        	
            auto node = root;

        	// insert the reversed word in the trie
            for( auto index = 0; index < word.size(); ++index )
            {
            	// if word[index, end) is a palindrome, then
            	// save its word id to the node
                if( has_palindrome_remaining( word, index ) )
                {
                    node->prefixes.push_back( word_id );
                }

                const auto chr = word[ index ];

                if( node->children.find( chr ) == node->children.end() )
                {
                    node->children[ chr ] = new trie_node();
                }

                node = node->children[ chr ];
            }

        	// node id / word it represents
            node->word_id = word_id;
        }

        return root;
    }

public:

	// returns palindrome pairs
    static std::vector<std::vector<int>> palindromePairs( const std::vector<std::string>& words )
    {
    	// root of the trie that contains all of the words in reverse
	    const auto root = build_trie( words );

        auto results = std::vector<std::vector<int>>();

        for( auto word_id = 0; word_id < words.size(); ++word_id )
        {
            const auto& word = words[ word_id ];

            auto node = root;

        	// iterate down the trie to find a palindrome 
            for( auto index = 0; index < word.size(); ++index )
            {
            	// if we have a valid word match & a palindrome save the result
                if( node->word_id != -1 && node->word_id != word_id &&
                    has_palindrome_remaining( word, index ) )
                {
                    results.push_back( { word_id, node->word_id } );
                }

                const auto chr = word[ index ];

                node = node->children[ chr ];

                if( !node )
                    break;
            }

            if( !node ) continue;

            if( node->word_id != -1 && node->word_id != word_id )
            {
                results.push_back( { word_id, node->word_id } );
            }

            for( auto other_id : node->prefixes )
            {
                results.push_back( { word_id, other_id } );
            }
        }

        return results;
    }
};

auto main() -> int
{
    const auto input1 = std::vector<std::string>{
        "abcd", "dcba", "lls", "s", "sssll"
    };

    const auto input = std::vector<std::string>{
        "a", ""
    };
	
    const auto actual = palindrome_pairs::palindromePairs( input );

    const auto expected = std::vector<std::vector<std::string>>
    {
		
    };
	
	return 0;
}