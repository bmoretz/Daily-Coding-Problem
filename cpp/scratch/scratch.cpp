#include <bits/stdc++.h>

#include "../leetcode/tree.h"

using leetcode::tree::tree_node;
using leetcode::tree::build_tree_in_order;

/* 919. Complete Binary Tree Inserter.

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.
 

Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
Example 2:

Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 

Note:

The initial given tree is complete and contains between 1 and 1000 nodes.
CBTInserter.insert is called at most 10000 times per test case.
Every value of a given or inserted node is between 0 and 5000.
*/


class complete_binary_tree
{
    tree_node* root_ = nullptr;

public:

    explicit complete_binary_tree( tree_node* root )
    {
        root_ = root;
    }

    int insert( int v ) const
    {
        auto q = std::queue<tree_node*>();
        q.push( root_ );

        tree_node* cur = nullptr;

        while( !q.empty() )
        {
            cur = q.front();
            q.pop();

            if( cur->left )
            {
                q.push( cur->left.get() );
            }
            else
            {
                cur->left = std::make_unique<tree_node>( v );
                break;
            }

            if( cur->right )
            {
                q.push( cur->right.get() );
            }
            else
            {
                cur->right = std::make_unique<tree_node>( v );
                break;
            }
        }

        return cur->val;
    }

    tree_node* get_root() const
    {
        return root_;
    }
};

auto main() -> int
{
    const auto tree = build_tree_in_order( { "1", "", "3" } );

    const auto cbt = complete_binary_tree( tree.get() );

    cbt.insert( 2 );
	
    return 0;
}