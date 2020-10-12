#include <bits/stdc++.h>

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

    bool starts_with( std::string& prefix ) const
    {
        return find_child( prefix );
    }
};

auto main() -> int
{
    auto searcher = trie();

    searcher.insert( "apple" );
    searcher.search( "apple" );   // returns true
    searcher.search( "app" );     // returns false
    searcher.starts_with( "app" ); // returns true
    searcher.insert( "app" );
    searcher.search( "app" );     // returns true
	
	return 0;
}