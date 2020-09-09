#include <bits/stdc++.h>
#include <array>

/* 285. Inorder Successor in BST.

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:


Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Note:

If the given node has no in-order successor in the tree, return null.+
It's guaranteed that the values of the tree are unique.
*/

#include "../leetcode/tree.h"

using namespace leetcode::tree;

class in_order_successor
{
public:

	static tree_node* inorderSuccessor( tree_node* root, tree_node* p )
	{
		if( !root || !p ) return nullptr;

		auto queue = std::queue<tree_node*>();;

		queue.push( root );

		auto diff = INT_MAX;
		tree_node* result = nullptr;
		
		while( !queue.empty() )
		{
			const auto node = queue.front();
			queue.pop();

			const auto delta = node->val - p->val;

			if( delta > 0 && node != p && delta < diff )
			{
				diff = delta;
				result = node;
			}

			if( node->left )
				queue.push( node->left.get() );

			if( node->right )
				queue.push( node->right.get() );
		}

		return result;
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