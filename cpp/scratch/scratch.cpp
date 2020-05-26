#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <random>
#include <unordered_map>

/* Paths with Sum.
 *
 * You are given a binary tree in which each node contains an integer value
 * (which might be positive or negative). Design an algorithm to count the number
 * of paths that sum to a given value. The path does not need to start or end at
 * the root or a leaf, but it must go downwards (traveling only from parent nodes
 * to child nodes).
 */

struct path_sum
{
	struct tree_node;

	using tree_node_ptr = std::unique_ptr<tree_node>;

	struct tree_node
	{
		int value;
		tree_node_ptr left{}, right{};

		explicit tree_node( const int value ) :
			value{ value }
		{ }
	};

	static auto find_sum( const tree_node* node,
		const int target )
	{
		auto path_map = std::unordered_map<int, int>();

		return find_sum( node, target, 0, path_map );
	}

	static auto find_sum( const tree_node* node,
		const int target,
		int running_total,
		std::unordered_map<int, int>& path_map ) -> int
	{
		if( !node ) return 0;

		running_total += node->value;

		const auto sum = running_total - target;

		auto total_paths = 0;

		if( path_map.find( sum ) != path_map.end() )
			total_paths = path_map.at( sum );

		if( running_total == target )
			total_paths++;

		update_path_map( path_map, running_total, 1 );
		
		total_paths += find_sum( node->left.get(), target, running_total, path_map );
		total_paths += find_sum( node->right.get(), target, running_total, path_map );

		update_path_map( path_map, running_total, -1 );

		return total_paths;
	}

	static auto update_path_map( std::unordered_map<int, int>& path_map, 
		const int key, const int delta ) -> void
	{
		auto count = 0;

		if( path_map.find( key ) != path_map.end() )
			count = path_map.at( key );
		
		const auto new_count = count + delta;

		if( new_count == 0 )
		{
			path_map.erase( key );
		}
		else
		{
			path_map.insert_or_assign( key, new_count );
		}
	}
};

path_sum::tree_node_ptr build_test_tree()
{
	using node = path_sum::tree_node;

	auto root = std::make_unique<node>( 7 );

	root->left = std::make_unique<node>( 5 );

	root->left->left = std::make_unique<node>( 3 );
	root->left->left->left = std::make_unique<node>( -3 );
	root->left->left->left->left = std::make_unique<node>( 1 );
	root->left->left->left->right = std::make_unique<node>( -2 );
	
	root->left->left->right = std::make_unique<node>( 4 );
	
	root->left->right = std::make_unique<node>( -3 );
	root->left->right->left = std::make_unique<node>( 2 );
	root->left->right->right = std::make_unique<node>( 1 );
	
	root->right = std::make_unique<node>( 8 );

	root->right->left = std::make_unique<node>( -3 );
	root->right->left->right = std::make_unique<node>( 2 );
	
	root->right->right = std::make_unique<node>( 5 );
	root->right->right->right = std::make_unique<node>( -2 );

	return root;
}

auto main() -> int
{
	const auto tree = build_test_tree();

	const auto tgt_sum = 1;

	const auto sums = path_sum::find_sum( tree.get(), tgt_sum );
	
	std::cout << "Paths with sum " << tgt_sum << sums;
}