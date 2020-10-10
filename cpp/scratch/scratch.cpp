#include <bits/stdc++.h>

#include "../leetcode/tree.h"

using namespace leetcode::tree;

/*103. Binary Tree Zigzag Level Order Traversal.

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right,
then right to left for the next level and alternate between).

For example:

Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
   
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

class zig_zag_level_order
{
public:
	
    static std::vector<std::vector<int>> zigzag_level_order( tree_node* root )
    {
        // process nodes in level order with a queue, the
        // key -> level, value -> node
        auto queue = std::queue<std::pair<int, tree_node*>>();

        if( root != nullptr )
            queue.push( std::make_pair( 0, root ) );

        auto result = std::vector<std::vector<int>>();

        while( !queue.empty() )
        {
            const auto& [level, node] = queue.front();

            if( node->left != nullptr )
            {
                queue.push( std::make_pair( level + 1, node->left.get() ) );
            }

            if( node->right != nullptr )
            {
                queue.push( std::make_pair( level + 1, node->right.get() ) );
            }

            // ensure the result vector has storage space
            if( result.size() <= level )
            {
                result.push_back( {} );
            }

            // if its an odd row, put the value at the front
            if( level % 2 == 1 )
            {
                result[ level ].insert( result[ level ].begin(), node->val );
            }
            else
            {
                // normal ordering
                result[ level ].push_back( node->val );
            }

            queue.pop();
        }

        return result;
    }
};

auto main() -> int
{
    const auto input1 = build_tree_in_order( { "3", "9", "20", "", "", "15", "7" } );
    const auto actual = zig_zag_level_order::zigzag_level_order( input1.get() );

    const auto expected = std::vector<std::vector<int>>{
    	{ 3 },
        { 20, 9 },
        { 15, 7 }
    };
	
	return 0;
}