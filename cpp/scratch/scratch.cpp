#include <bits/stdc++.h>
#include <array>

/* 863. All Nodes Distance K in Binary Tree.

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
*/

#include "../leetcode/tree.h"

using namespace leetcode::tree;

class binary_tree_distance
{
	static void get_hierarchy( tree_node* root, 
		std::unordered_map<tree_node*, tree_node*>& map,
		int level = 0 )
	{
		if( !root ) return;

		if( root->left )
		{
			map[ root->left.get() ] = root;
			get_hierarchy( root->left.get(), map );
		}
		
		if( root->right )
		{
			map[ root->right.get() ] = root;
			get_hierarchy( root->right.get(), map );
		}
	}

	static void search( tree_node* node, const int k,
		const std::unordered_map<tree_node*, tree_node*>& nodes,
		std::set<tree_node*>& visited,
		std::vector<int>& result )
	{
		if( !node ) return;
		if( visited.find( node ) != visited.end() ) return;

		visited.insert( node );

		if( k == 0 )
		{
			result.push_back( node->val );

			return;
		}

		if( node->left )
			search( node->left.get(), k - 1, nodes, visited, result );

		if( node->right )
			search( node->right.get(), k - 1, nodes, visited, result );

		if( nodes.find( node ) != nodes.end() )
		{
			const auto parent = nodes.at( node );

			if( parent )
				search( parent, k - 1, nodes, visited, result );
		}
	}
	
public:

	static std::vector<int> distanceK( tree_node* root,
		tree_node* target, const int k )
	{
		std::unordered_map<tree_node*, tree_node*> tree_map;
		
		get_hierarchy( root, tree_map );

		std::set<tree_node*> visited;
		std::vector<int> result;
		
		search( target, k, tree_map, visited, result );
		
		return result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::string>{ "3", "5", "1", "6", "2", "0" , "8", "", "", "7", "4" };

	const auto root = build_tree_in_order( input1 );
	const auto node = root->left.get();
	
	const auto result = binary_tree_distance::distanceK( root.get(), node, 2 );
	
	return 0;
}