#include <bits/stdc++.h>

#include "../leetcode/tree.h"
using namespace leetcode::tree;

/*426. Convert Binary Search Tree to Sorted Doubly Linked List.

Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked
list. For a circular doubly linked list, the predecessor of the first element is the last element,
and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor,
and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

Example 1:

Input: root = [4,2,5,1,3]

Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

Example 2:

Input: root = [2,1,3]
Output: [1,2,3]
Example 3:

Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.
Example 4:

Input: root = [1]
Output: [1]
 
Constraints:

-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
All values of Node.val are unique.
0 <= Number of Nodes <= 2000
*/


class bst_to_dll
{	
    static void to_queue( tree_node* node, std::queue<int>& queue )
    {
        if( !node ) return;

        to_queue( node->left.get(), queue );
        queue.push( node->val );
        to_queue( node->right.get(), queue );
    }

public:

    static tree_node* tree_to_doubly_list( tree_node* root )
    {
        if( !root ) return nullptr;

        auto queue = std::queue<int>();

        to_queue( root, queue );

        const auto sentinel = std::make_unique<tree_node>( 0 );
        auto cur = sentinel.get(), prev = sentinel->left.get();

        while( !queue.empty() )
        {
            const auto val = queue.front();
            queue.pop();

            cur->right = std::make_unique<tree_node>( val );
            cur->left.reset( prev );

            prev = cur;
            cur = cur->right.get();
        }

        cur->left.reset( prev );
        cur->right.reset(sentinel->right.get() );
        sentinel->right->left.reset( cur );

        return sentinel->right.get();
    }
};

auto main() -> int
{
    auto input = build_tree_in_order( std::vector<std::string>{ "4", "2", "5", "1", "3" } );
    
    const auto actual = bst_to_dll::tree_to_doubly_list( input.get() );

    const auto expected = false;
	
	return 0;
}