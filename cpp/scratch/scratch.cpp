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
#include <sstream>

/* Check Subtree.
 *
 * T1 and T2 are two very large binary trees, with T1 much bigger
 * than T2. Create an algorithm to determine if T2 is a subtree of T1.
 *
 * A tree T2 is a subtree of T1 if there exists a node n in T1 such that
 * the subtree of n is identical to T2. That is, if you cut off the tree
 * at node n, the two trees would be identical.
 */

struct check_subtree
{	
    struct tree_node;

    using tree_node_ptr = std::unique_ptr<tree_node>;

    struct tree_node
    {
        int value;
        tree_node_ptr left{}, right{};
        const tree_node* parent{};

        explicit tree_node( const int& value, 
            const tree_node* parent = nullptr )
            : value{ value },
				parent{ parent }
        {}

    	tree_node( const tree_node& other )
            : value{ other.value }, left{ other.left.get() },
    			right{ other.right.get() }, parent{ other.parent }
        {
        }

    	tree_node( tree_node&& other ) noexcept
            : value{ other.value }, parent{ other.parent }
        {
            left = std::move( other.left );
            right = std::move( other.right );
        }
    	
    	tree_node* insert_left( const int& value )
        {
            left = std::make_unique<tree_node>( value, this );

            return left.get();
        }

    	tree_node* insert_right( const int & value )
        {
            right = std::make_unique<tree_node>( value, this );

            return right.get();
        }
    };

	static auto post_order( const tree_node* node ) -> std::unique_ptr<std::vector<std::string>>
	{
        auto result = std::make_unique<std::vector<std::string>>();

        post_order( node, *result );

        return result;
	}

	static auto post_order( const tree_node* node, std::vector<std::string>& values ) -> void
	{
        if( !node )
        {
            values.emplace_back( "----" );
            return;
        }
		
        values.push_back( std::to_string( node->value ) );
		
        post_order( node->left.get(), values );

        post_order( node->right.get(), values );
	}
	
    static auto is_subtree( const tree_node* t1, const tree_node* t2 ) -> bool
    {
        const auto t1_order = post_order( t1 );
        const auto t2_order = post_order( t2 );

		for( auto index = std::size_t(); index < t1_order->size(); ++index )
		{
			if( t1_order->at( index ) == t2_order->front() )
			{
                auto exists = true;
				
				for( auto sub_index = std::size_t(1); 
                    sub_index < t2_order->size() && index + sub_index < t1_order->size(); 
                    ++sub_index )
				{
                    exists &= t1_order->at( index + sub_index ) == t2_order->at( sub_index );
				}

                if( exists ) return true;
			}
		}

        return false;
    }
};

/*          test tree
*
*                 6
*            /           \
*          4                 8
*        /    \            /     \
*       2       5           7       9
*     /    \        /   \       \
*    1        3     4      8     10
*  /     \        /     /
* 2         1     2     8
*          /              \
*         6                  2
 *                                                        
 *
 * 
 */

std::unique_ptr<check_subtree::tree_node> build_test_tree()
{
    using node = check_subtree::tree_node;
	
    auto root = std::make_unique<node>( 6 );

    auto l = root->insert_left( 4 );

    auto ll = l->insert_left( 2 );

    ll->insert_left( 1 );

    auto llr = ll->insert_right( 3 );

    llr->insert_left( 2 );

    auto llrr = llr->insert_right( 1 );
    llrr->insert_left( 6 );

    l->insert_right( 5 );

    auto r = root->insert_right( 8 );

    auto rl = r->insert_left( 7 );

    rl->insert_left( 4 );

    auto rlr = rl->insert_right( 8 );
    rlr->insert_left( 2 );

    auto rr = r->insert_right( 9 );

    auto rrr = rr->insert_right( 10 );

    auto rrrl = rrr->insert_left( 8 );
    rrrl->insert_right( 2 );

    return root;
}

auto main() -> int
{
    using node = check_subtree::tree_node;

    const auto t1 = build_test_tree();

    const auto t2 = std::make_unique<node>( 10 );
    auto r = t2->insert_right( 8 );
    r->insert_left( 2 );

    auto result = check_subtree::is_subtree( t1.get(), t2.get() );

    std::cout << result;
}