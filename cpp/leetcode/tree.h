#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>

namespace leetcode::tree
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

	static std::unique_ptr<tree_node> build_tree_in_order( const std::vector<std::string>& values )
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
	
	/* 652 - Find Duplicate Subtrees.

	Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to
	return the root node of any one of them.

	Two trees are duplicate if they have the same structure with same node values.

	Example 1:

			1
		   / \
		  2   3
		 /   / \
		4   2   4
		   /
		  4
	The following are two duplicate subtrees:

		  2
		 /
		4
	and

		4
	Therefore, you need to return above trees' root in the form of a list.

	*/
	struct find_dup_subtrees
	{
		int t{};
		std::unordered_map<std::string, int> trees;
		std::unordered_map<int, int> count;
		std::vector<tree_node*> result;

		std::vector<tree_node*> find_duplicate_subtrees( tree_node* root )
		{
			preorder( root );

			return result;
		}

		std::string preorder( tree_node* node )
		{
			if( node == nullptr ) return "#";

			std::ostringstream key;
			key << std::to_string( node->val ) << ","
				<< preorder( node->left.get() ) << ","
				<< preorder( node->right.get() );

			if( trees.find( key.str() ) != trees.end() && trees.at( key.str() ) == 1 )
			{
				result.push_back( node );
			}

			trees[ key.str() ]++;

			return key.str();
		}
	};

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

	struct level_order_ii
	{
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
	};
}