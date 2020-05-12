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

/* Check Balanced.
 *
 * Implement a function to check if a binary tree is balanced. For the purposes of
 * this question, a balanced binary tree is defined to be a tree such that the heights
 * of the two subtrees of any node never differ by more than one.
 */

struct is_balanced
{
    struct tree_node;

    using tree_node_ptr = std::unique_ptr<tree_node>;

    struct tree_node
    {
        int value;
        tree_node_ptr left, right;
    	
        explicit tree_node( const int& val )
            : value{ val }
        {  }
    };

    tree_node_ptr root;

    [[nodiscard]] bool is_balanced1() const
	{
        if( !root ) return true;
		
        const auto left = height( root->left.get() );
        const auto right = height( root->right.get() );

        const int delta = left - right;

        return std::abs( delta ) <= 1;
	}

	[[nodiscard]] std::size_t height( const tree_node* node ) const
	{
        if( !node ) return 0;

        const auto l = 1 + height( node->left.get() );
        const auto r = 1 + height( node->right.get() );

        return std::max( l, r );
	}
};

auto main() -> int
{
    using node = is_balanced::tree_node;
	
    auto tree = is_balanced{ };

    tree.root = std::make_unique<node>( 4 );
	
    tree.root->left = std::make_unique<node>( 6 );
	
    tree.root->left->left = std::make_unique<node>( 2 );
    tree.root->left->left->left = std::make_unique<node>( 1 );
	
    tree.root->left->right = std::make_unique<node>( 5 );
	
    tree.root->left->right->left = std::make_unique<node>( 3 );
    tree.root->left->right->right = std::make_unique<node>( 2 );
	
    tree.root->right = std::make_unique<node>( 7 );

    auto bal = tree.is_balanced1();
}