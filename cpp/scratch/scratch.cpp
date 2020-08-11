#include <bits/stdc++.h>
#include <random>

/* 1268. Search Suggestions System.

Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product
names from products after each character of searchWord is typed. Suggested products should have common prefix with the
searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
	["mobile","moneypot","monitor"],
	["mobile","moneypot","monitor"],
	["mouse","mousepad"],
	["mouse","mousepad"],
	["mouse","mousepad"]
]

Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]

Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= sum( products[i].length ) <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.
*/

class search_system
{	
	class search_tri
	{
		struct tree_node;

		std::unique_ptr<tree_node> root_;
		
		struct tree_node
		{
			char data;
			std::map<char, std::unique_ptr<tree_node>> children;
			
			explicit tree_node( const char value )
				: data{ value }
			{ }

			bool has_character( const char chr )
			{
				return children.find( chr ) != children.end();
			}

			tree_node* insert_child( const char chr )
			{
				if( children.find( chr ) == children.end() )
				{
					children[ chr ] = std::make_unique<tree_node>( chr );
				}

				return children[ chr ].get();
			}
			
			tree_node* get_children( const char chr )
			{
				return children[ chr ].get();
			}
		};
		
	public:

		search_tri()
		{
			root_ = std::make_unique<tree_node>( '\0' );
		}

		void insert_word( const std::string& word ) const
		{
			auto level = root_.get();
			
			for( const auto chr : word )
			{
				level = level->insert_child( chr );
			}

			level->data = '*';
		}

		static void search( const std::string& res, std::vector<std::string>& item, 
		                    const std::string& prefix, tree_node* node,
		                    const std::size_t max_result_size = 3 )
		{
			if( item.size() == max_result_size ) return;
			if( !node ) return;
			
			if( node->data == '*' )
				item.push_back( prefix + res );

			for( auto iter = node->children.begin(); 
				iter != node->children.end(); ++iter )
			{
				search( res + iter->first, item, prefix, node->children[ iter->first ].get() );
			}
		}
		
		std::vector<std::vector<std::string>> get_results( const std::string& term,
			const int max_results = 3 ) const
		{	
			auto results = std::vector<std::vector<std::string>>( term.size() );
			auto result_index = std::size_t();
			
			auto node = root_.get();
			auto prev = true;
			std::string prefix;
			
			for( auto chr : term )
			{
				if( node->children.find( chr ) != node->children.end() && prev )
				{
					prefix += chr;
					node = node->children[ chr ].get();
					std::vector<std::string> items;
					search( "", items, prefix, node );
					results[ result_index++ ] = items;
				}
				else
				{
					prev = false;
					++result_index;
				}
			}
			
			return results;
		}
	};
	
	search_tri searcher_;
	
public:
	
	/// <summary>
	/// suggest products
	/// </summary>
	/// <param name="products"></param>
	/// <param name="search_word"></param>
	/// <returns></returns>
	std::vector<std::vector<std::string>> suggest_products( const std::vector<std::string>& products,
		const std::string& search_word ) const
	{
		for( auto& word : products )
		{
			searcher_.insert_word( word );
		}
		
		return searcher_.get_results( search_word, 3 );
	}
};

auto main() -> int
{
	const auto input1 = std::pair<std::vector<std::string>, std::string>
	{
		std::vector<std::string> { "mobile", "mouse", "moneypot", "monitor", "mousepad" },
		"mouse"
	};

	const auto input2 = std::pair<std::vector<std::string>, std::string>
	{
		std::vector<std::string> {
		"havana" },
		"tatiana"
	};
	
	auto searcher = search_system();
	
	const auto results = searcher.suggest_products( input2.first, input2.second );
	
    return 0;
}