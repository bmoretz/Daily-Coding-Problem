#include <bits/stdc++.h>

/* 107. Binary Tree Level Order Traversal II. 

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

struct binary_tree_level_order_ii
{
	struct tree_node
	{
		int val;
		std::unique_ptr<tree_node> left, right;

		explicit  tree_node( const int x ) :
			val( x ), left( nullptr ), right( nullptr ) {}

		tree_node( const tree_node& other ) = delete;

		tree_node( tree_node&& other ) noexcept
			: val{ other.val }
		{
			left.swap( other.left );
			right.swap( other.right );
		}

		tree_node& operator=( const tree_node& other ) noexcept
		{
			if( this == &other )
				return *this;

			val = other.val;
			left.reset( other.left.get() );
			right.reset( other.right.get() );

			return *this;
		}

		tree_node& operator=( tree_node&& other ) noexcept
		{
			if( this == &other )
				return *this;

			val = other.val;
			left = std::move( other.left );
			right = std::move( other.right );

			return *this;
		}

		~tree_node() = default;
	};

	static void traverse( const tree_node* node, int level, std::map<int, std::vector<int>>& results )
	{
		if( node == nullptr ) return;

		results[ level++ ].push_back( node->val );

		traverse( node->left.get(), level, results );
		traverse( node->right.get(), level, results );
	}
	
	static std::vector<std::vector<int>> level_order_bottom( const tree_node* root )
	{
		auto level_order = std::map<int, std::vector<int>>();

		traverse( root, 0, level_order );

		auto result = std::vector<std::vector<int>>();

		for( auto level = level_order.size(); level > 0; --level )
		{
			result.push_back( level_order[ level - 1 ] );
		}
		
		return result;
	}

	static std::unique_ptr<tree_node> build_tree( const std::vector<std::string>& values )
	{
		if( values.size() == std::size_t() ) return nullptr;
		
		std::queue<tree_node*> nodes;

		auto index = std::size_t();

		const auto root_value = std::stoi( values[ index++ ] );
		auto root = std::make_unique<tree_node>( root_value );
		nodes.push( root.get() );

		while( index < values.size() )
		{
			auto node = nodes.front();

			if( index < values.size() && !values[ index ].empty() )
			{
				node->left = std::make_unique<tree_node>( std::stoi( values[ index ] ) );
				nodes.push( node->left.get() );
			}

			index++;

			if( index < values.size() && !values[ index ].empty() )
			{
				node->right = std::make_unique<tree_node>( std::stoi( values[ index ] ) );
				nodes.push( node->right.get() );
			}

			index++;
			
			nodes.pop();
		}

		return std::move( root );
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::string>{ "3", "9", "20", "", "", "15", "7" };
	const auto input2 = std::vector<std::string>{ "3", "9" };
	const auto input3 = std::vector<std::string>{ "3", "9", "20", "", "", "15", "7", "", "1", "", "", "1" };
	const auto input4 = std::vector<std::string>{ "0", "2", "4", "1", "", "3", "-1", "5", "1", "", "6", "", "8" };
	const auto input5 = std::vector<std::string>{ "0", "2", "4" , "1", "", "3", "-1", "5", "1", "", "6", "", "8" };

	const auto root = binary_tree_level_order_ii::build_tree( input1 );
	const auto result = binary_tree_level_order_ii::level_order_bottom( root.get() );

	return 0;
}
