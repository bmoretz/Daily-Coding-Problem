#include <bits/stdc++.h>
#include <array>

/* 965. Univalued Binary Tree.

A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

Example 1:

Input: [1,1,1,1,1,null,1]
Output: true
Example 2:

Input: [2,2,2,5,2]
Output: false

Note:

The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].
*/

#include "../leetcode/tree.h"

using namespace leetcode::tree;

class is_univalued
{
	static bool is_unival( tree_node* node )
	{
		if( !node ) return false;

		auto left_sub = true;
		
		if( node->left )
		{
			if( node->val != node->left->val )
				return false;

			left_sub = is_unival( node->left.get() );
		}
		
		auto right_sub = true;

		if( node->right )
		{
			if( node->val != node->right->val )
				return false;
			
			right_sub = is_unival( node->right.get() );
		}

		return left_sub && right_sub;
	}
	
public:

	static bool isUnivalTree( tree_node* root )
	{
		if( !root ) return false;

		return is_unival( root );
	}
};

auto main() -> int
{
	auto input1 = std::vector<std::string>{ "1", "1", "1", "1", "1", "", "1" };
	auto input2 = std::vector<std::string>{ "2", "2", "2", "5", "2" };
	
	auto root = build_tree_in_order( input2 );
	
	const auto result = is_univalued::isUnivalTree( root.get() );
	
	return 0;
}