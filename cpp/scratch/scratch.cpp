#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <string>
#include <tuple>
#include <set>
#include <iterator>
#include <numeric>
#include <ostream>

/* First Common Ancestor.
 *
 * Design an algorithm and write code to find the first common ancestor
 * of two nodes in a binary tree. Avoid storing additional nodes in a data
 * structure.
 *
 * NOTE: This is not necessarily a binary search tree.
 */

struct ancestor
{
    struct tree_node;

    using tree_node_ptr = std::unique_ptr<tree_node>;

	struct tree_node
	{
        int value;
        tree_node_ptr left{}, right{};
        const tree_node* parent{};

        tree_node( const int val, const tree_node * parent )
            : value{ val },
				parent { parent }
        { }

		void insert_left( int val ) { left = std::make_unique<tree_node>( val, this ); }
        void insert_right( int val ) { right = std::make_unique<tree_node>( val, this ); }
	};

	static const tree_node* common_ancestor1( const tree_node& tree, 
        const tree_node& first, const tree_node& second )
	{
        if( !( first.parent && second.parent ) ) return &tree;
		
        auto
            l_depth = get_depth( first ),
            r_depth = get_depth( second );

        auto l_node = &first, r_node = &second;

		// put both node pointers on the same level
		// so that we can walk up the tree in unison
        while( l_depth != r_depth )
        {
            if( l_depth > r_depth )
            {
                l_node = l_node->parent;
                l_depth--;
            }
            else
            {
                r_node = r_node->parent;
                r_depth--;
            }
        }

		while( l_node->parent != r_node->parent )
		{
            r_node = r_node->parent;
            l_node = l_node->parent;
		}

        return l_node->parent;
	}

	static int get_depth( const tree_node& tree_node )
	{
        auto depth = 0;
        auto node = &tree_node;
		
		while( node->parent )
		{
            node = node->parent;
            depth++;
		}

        return depth;
	}
};

/*
 *                      test tree
 *                           7
 *                    /            \
 *                   5               9
 *                /     \          /     \
 *              6       3        4         8
 *            /       /          \
 *           2       2              3
 *        /     \
 *       1       5
 *      /
 *     0 
 */
auto main() -> int
{
    using node = ancestor::tree_node;
	
    auto tree = std::make_unique<node>( 7, nullptr );

    tree->insert_left( 5 );

    tree->left->insert_left( 6 );

    tree->left->left->insert_left( 2 );
    tree->left->left->left->insert_left( 1 );
    tree->left->left->left->left->insert_left( 0 );
	
    tree->left->left->left->insert_right( 5 );
    tree->left->insert_right( 3 );
    tree->left->right->insert_left( 2 );

    tree->insert_right( 9 );

    tree->right->insert_left( 4 );
    tree->right->left->insert_left( 3 );
    tree->right->insert_right( 8 );

    const auto first = tree->left->left->left->left->left.get(); // 0
    const auto second = tree->right->right.get(); // 8

    // auto ancestor = ancestor::common_ancestor1( *tree, *first, *second );
    auto ancestor = ancestor::common_ancestor1( *tree, *first, *tree);
}