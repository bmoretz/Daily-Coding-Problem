#include <bits/stdc++.h>

#include "../leetcode/tree.h"

using namespace leetcode::tree;

/* 543. Diameter of Binary Tree.

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree
is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5
      
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

class tree_diameter
{
public:
    static int diameter_of_binary_tree( tree_node* root )
    {
        if( root == nullptr ) return 0;

        auto depths = std::unordered_map<tree_node*, int>();
        auto stack = std::stack<tree_node*>();

        stack.push( root );

        auto max_width = 0;

        while( !stack.empty() )
        {
            auto node = stack.top();

            if( node->left && 
                depths.find( node->left.get() ) == depths.end() )
            {
                stack.push( node->left.get() );
            }
            else if( node->right.get() && 
                depths.find( node->right.get() ) == depths.end() )
            {
                stack.push( node->right.get() );
            }
            else
            {
                stack.pop();
            	
                auto left = depths[ node->left.get() ],
            		right = depths[ node->right.get() ];

                depths[ node ] = std::max( left, right ) + 1;
                max_width = std::max( max_width, left + right );
            }
        }

        return max_width;
    }
};

auto main() -> int
{
    const auto root = build_tree_in_order( { "4", "2","", "1", "3" } );

    const auto actual = tree_diameter::diameter_of_binary_tree( root.get() );
    const auto expected = 3;
	
	return 0;
}