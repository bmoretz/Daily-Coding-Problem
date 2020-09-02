#include <bits/stdc++.h>
#include <array>

/* 94. Binary Tree Inorder Traversal.

Given a binary tree, return the in-order traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include "../leetcode/tree.h"

using namespace leetcode::tree;

class binary_tree_traversal
{
	static void traverse_inorder( tree_node* root, std::vector<int>& result )
	{
		if( !root ) return;

		traverse_inorder( root->left.get(), result );

		result.push_back( root->val );

		traverse_inorder( root->right.get(), result );
	}
	
public:

	static std::vector<int> inorder_traversal1( tree_node* root )
	{
		std::vector<int> result;

		traverse_inorder( root, result );
		
		return result;
	}

	static std::vector<int> inorder_traversal2( tree_node* root )
	{
		std::vector<int> result;
		
		auto stack = std::stack<tree_node*>();
		auto node = root;

		stack.push( node );
		
		while( node || !stack.empty() )
		{
			while( node )
			{
				stack.push( node );
				node = node->left.get();
			}

			node = stack.top();
			
			result.push_back( node->val );

			stack.pop();

			node = node->right.get();
		}

		return result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::string>{ "1", "", "2", "3" };
	
	const auto root = build_tree_in_order( input1 );

	const auto result = binary_tree_traversal::inorder_traversal2( root.get() );
	
	return 0;
}