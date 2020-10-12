#include <bits/stdc++.h>

#include "../leetcode/tree.h"
using namespace leetcode::tree;

/*236. Lowest Common Ancestor of a Binary Tree.

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

class lowest_common_ancestor_bfs
{
    static std::unordered_map<tree_node*, tree_node*> get_hierarchy( tree_node* root )
    {
        auto map = std::unordered_map<tree_node*, tree_node*>();
        auto queue = std::queue<std::pair<tree_node*, tree_node*>>();

    	// push the root node into the queue
        queue.push( std::make_pair( nullptr, root ) );

        while( !queue.empty() )
        {
        	// current node
            const auto& [parent, node] = queue.front();

        	// if we haven't seen this node before
            if( map.find( node ) == map.end() )
            {
            	// store it's parent
                map[ node ] = parent;

            	// process children
            	
                if( node->left )
                {
                    queue.push( std::make_pair( node, node->left.get() ) );
                }

                if( node->right )
                {
                    queue.push( std::make_pair( node, node->right.get() ) );
                }
            }

            queue.pop();
        }

        return map;
    }

public:

    static tree_node* lowest_common_ancestor( tree_node* root, tree_node* p, tree_node* q )
    {
    	// get the hierarchy of the tree [node->parent] form
        auto hierarchy = get_hierarchy( root );

        auto seen = std::set<tree_node*>();

        auto node = p;
        // start at p, process
    	// all of its parent nodes from lowest
    	// to the root
        while( node != nullptr )
        {
            seen.insert( node );

            node = hierarchy[ node ];
        }

        node = q;
        // now process q
    	// the first result that we find
    	// will be the solution
        while( node != nullptr )
        {
            if( seen.find( node ) != seen.end() )
                return node;

            node = hierarchy[ node ];
        }

    	// no common ancestors
        return nullptr;
    }
};

auto main() -> int
{
    auto root = build_tree_in_order( 
        std::vector<std::string>{ "3", "5", "1", "6", "2", "0", "8", "", "", "7", "4" } );

    const auto actual = lowest_common_ancestor_bfs::lowest_common_ancestor( root.get(), root->left.get(), root->right.get() );
	
    const auto expected = root.get();
	
	return 0;
}