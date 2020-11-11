#include <bits/stdc++.h>

#include "../leetcode/tree.h"
using namespace leetcode::tree;

/*100. Same Tree.

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/

class equal_trees_rec
{
    static bool are_equal( tree_node* left, tree_node* right )
    {
        if( !left && !right ) return true;
        if( !left || !right ) return false;
        if( left->val != right->val ) return false;

        return
            are_equal( left->left.get(), right->left.get() ) &&
            are_equal( left->right.get(), right->right.get() );
    }

public:

    static bool is_same_tree( tree_node* p, tree_node* q )
	{
        return are_equal( p, q );
    }
};

class equal_trees_iter
{

    static bool are_equal( tree_node* left, tree_node* right )
    {
        if( !left && !right ) return true;
        if( !left || !right ) return false;

        return left->val == right->val;
    }

public:

    static bool is_same_tree( tree_node* p, tree_node* q )
    {
        auto tree = std::queue<std::pair<tree_node*, tree_node*>>();

        if( p || q )
            tree.push( std::make_pair( p, q ) );

        while( !tree.empty() )
        {
            const auto [left, right] = tree.front();
            tree.pop();

            if( !are_equal( left, right ) )
                return false;

            if( left->left || right->left )
                tree.push( std::make_pair( left->left.get(), right->left.get() ) );

            if( left->right || right->right )
                tree.push( std::make_pair( left->right.get(), right->right.get() ) );
        }

        return true;
    }
};

auto main() -> int
{
    auto l_tree = build_tree_in_order( std::vector<std::string>{ "1", "2" } );
    auto r_tree = build_tree_in_order( std::vector<std::string>{ "1", "", "2" } );

    const auto actual = equal_trees_iter::is_same_tree( l_tree.get(), r_tree.get() );

    const auto expected = false;
	
	return 0;
}