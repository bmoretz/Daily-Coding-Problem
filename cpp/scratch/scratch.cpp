#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

/* List of Depths.
 *
 * Given a binary tree, design an algorithm which creates a linked list of all the nodes
 * at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 */

class list_of_depths
{
	struct list_node;

	using list_node_ptr = std::unique_ptr<list_node>;

	struct list_node
	{
		int value;
		list_node_ptr next;

		explicit list_node( const int& val )
			: value{ val }
		{ }
	};
	
	struct tree_node;

	using tree_node_ptr = std::unique_ptr<tree_node>;
	
	struct tree_node
	{
		int value;
		tree_node_ptr left, right;
		
		explicit tree_node( const int& val )
			: value( val )
		{}
	};

	tree_node_ptr root_;

	[[nodiscard]] tree_node_ptr build_tree( const std::vector<int>& values, const int& begin, const int& end ) const
	{
		if( begin >= end )
			return nullptr;

		const auto mid = begin + int( ceil( ( end - begin ) / 2 ) );

		auto root = std::make_unique<tree_node>( values[ mid ] );
		
		root->left = build_tree( values, begin, mid );

		root->right = build_tree( values, mid + 1, end );

		return root;
	}

	std::size_t num_children( const tree_node* node ) const
	{
		if( node == nullptr ) return 0;

		return std::max( 1 + num_children( node->left.get() ),
			1 + num_children( node->right.get() ) );
	}
	
public:

	using list_map = std::map<std::size_t, list_node_ptr>;
	
	list_of_depths() = delete;

	list_of_depths( const std::initializer_list<int>& init_values )
	{
		root_ = build_tree( init_values, 0, init_values.size() );
	}

	[[nodiscard]] std::size_t depth() const
	{
		return num_children( root_.get() );
	}

	[[nodiscard]] std::unique_ptr<list_map> build_node_list() const
	{
		using level_data = std::pair<std::size_t, tree_node*>;

		auto lists = std::make_unique<list_map>();
		auto level = std::queue<level_data>{};

		level.push( level_data( 0, root_.get() ) );

		while( !level.empty() )
		{
			const auto current = level.front();

			if( current.first == lists->size() )
			{
				lists->insert( 
					std::make_pair( current.first, 
						std::make_unique<list_node>( 0 ) 
				) );
			}

			auto node = lists->at( current.first ).get();

			while( node->next )
			{
				node = node->next.get();
			}

			node->next = std::make_unique<list_node>( current.second->value );
			
			level.pop();

			if( current.second->left ) 
				level.push( std::make_pair( 
					current.first + 1, 
					current.second->left.get() ) );
			
			if( current.second->right )
				level.push( std::make_pair( 
					current.first + 1, 
					current.second->right.get() ) );;

		}

		return lists;
	}
};

auto main() -> int
{
	const auto tree = list_of_depths{ 1, 2, 3, 4, 5, 6, 7 };

	auto lists = tree.build_node_list();
}