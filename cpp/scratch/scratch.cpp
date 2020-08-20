#include <bits/stdc++.h>
#include "../leetcode/tree.h"

using leetcode::tree::tree_node;
using leetcode::tree::build_tree_in_order;

/* 653. Two Sum IV - Input is a BST.

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/

class two_sum_bst
{

public:

    static std::vector<int> flatten( const tree_node* root )
    {
        std::vector<int> results;

        flatten( root, results );

        return results;
    }

    static void flatten( const tree_node* root, std::vector<int>& results )
    {
        if( root == nullptr ) return;

        flatten( root->left.get(), results );
        results.push_back( root->val );
        flatten( root->right.get(), results );
    }

    static bool find_target( const tree_node* root, const int k )
    {
        auto numbers = flatten( root );

        std::set<int> targets( numbers.begin(), numbers.end() );

        for( auto num : numbers )
        {
            const auto target = k - num;

            if( target != num && targets.find( target ) != targets.end() )
            {
                return true;
            }
        }

        return false;
    }
};

auto main() -> int
{
    const auto input1 = build_tree_in_order( { "5", "3", "6", "2", "4", "7" } );
	
    const auto actual = two_sum_bst::find_target( input1.get(), 9 );
	
    return 0;
}