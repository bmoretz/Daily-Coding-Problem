#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

/* Validate BST.
 *
 * Implement a function to check if a binary tree is a binary search tree.
 */

struct validate_bst
{
    struct tree_node;

    using tree_node_ptr = std::unique_ptr<tree_node>;

    struct tree_node
    {
        int value;
        tree_node_ptr left, right;

        explicit tree_node(const int& val)
            : value { val }
    	{  }
    };

    static auto is_bst( const tree_node* node )
    {
        if( !node ) return true;

        if( is_bst( node->left.get() ) && is_bst( node->right.get() ) )
        {
            const auto is_left = node->left ? node->value >= node->left->value : true;
            const auto is_right = node->right ? node->value < node->right->value : true;
        	
            return is_left && is_right;
        }
    	
        return false;
    }
};

auto main() -> int
{
    using node = validate_bst::tree_node;

    auto tree = std::make_unique<node>( 4 );
    tree->left = std::make_unique<node>( 7 );
	
    const auto is_bst = validate_bst::is_bst( tree.get() );

	
}