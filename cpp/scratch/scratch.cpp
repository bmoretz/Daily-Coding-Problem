#include <bits/stdc++.h>

/* 95. Unique Binary Search Trees II.

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]

Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
Constraints:

0 <= n <= 8
*/

#include "../leetcode/tree.h"

using namespace leetcode::tree;

class generate_bst_trees
{
    static std::vector<tree_node*> gen_trees( const int beg, const int end )
    {
        if( end < beg ) return { nullptr };
        if( end == beg ) return { new tree_node( beg ) };

        std::vector<tree_node*> trees;

        for( auto index = beg; index <= end; ++index )
        {
            auto left_trees = gen_trees( beg, index - 1 );
            auto right_trees = gen_trees( index + 1, end );

            for( auto& left : left_trees )
            {
                for( auto& right : right_trees )
                {
                    auto node = new tree_node( index );
                	
                    node->left.reset( left );
                    node->right.reset( right );
                    
                    trees.push_back( node );
                }
            }
        }

        return trees;
    }

public:

    static std::vector<tree_node*> generate_trees( const int n )
    {
        if( n == 0 ) return {};

        return gen_trees( 1, n );
    }
};

auto main() -> int
{
    auto input = std::vector<std::vector<int>>
    {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 1, 1, 1 }
    };
	
    auto actual = generate_bst_trees::generate_trees( 3 );
	

	
	return 0;
}