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
#include <string>

/* Successor.
 *
 * Write an algorithm to find the "next" node (i.e., in-order successor) of a given
 * node in a binary search tree. You may assume that each node has a link to its
 * parent.
 */

struct successor
{
    struct tree_node;

    using tree_node_ptr = std::unique_ptr<tree_node>;

    struct tree_node
    {
        tree_node* parent{};
        int value;
        tree_node_ptr left{ }, right{ };

        explicit tree_node( tree_node* parent, const int& val )
            : parent{ parent }, value{ val }
        {  }

        bool operator>=( const tree_node& other ) const { return value >= other.value; }
        bool operator<=( const tree_node& other ) const { return value <= other.value; }
        bool operator<( const tree_node& other ) const { return value < other.value; }
        bool operator>( const tree_node& other ) const { return value > other.value; }
        bool operator==( tree_node& other ) const { return value == other.value; }
    };

    static tree_node_ptr build_tree( const std::vector<int>& values,
        const int& begin, const int& end, tree_node* parent = nullptr )
    {
        using std::ceil;

        if( begin >= end ) return nullptr;

        const auto mid = begin + static_cast< int >( ceil( ( end - begin ) / 2 ) );

        auto node = std::make_unique<tree_node>( parent, values[ mid ] );

        node->left = build_tree( values, begin, mid, node.get() );
        node->right = build_tree( values, mid + 1, end, node.get() );

        return node;
    }

	static tree_node* get_successor( const tree_node& node )
    {
        tree_node* next = nullptr;

        if( node.parent && node >= *node.parent )
        {
            next = node.parent;

            while( node > *next )
                next = next->parent;

            return next;
        }

        if( node.right )
        {
            next = node.right.get();

            while( next->left )
            {
                next = next->left.get();
            }
        }

        return next;
    }
};

auto main() -> int
{
    const auto values = { 2, 3, 5 , 7, 9, 12, 15, 18, 20 };
	
    const auto tree = 
        successor::build_tree( values, 0, values.size() );

    const auto candidate =
        tree->left->right.get();
	
    auto next = successor::get_successor( *candidate );

}

/*
std::string to_tuple_string( const int value )
{
    return std::to_string( value );
}

std::string to_tuple_string( const float value )
{
    return std::to_string( value );
}

std::string to_tuple_string( const char value )
{
    return std::to_string( value );
}

template<typename ...P>
std::string to_tuple_string( const P& ... p )
{
    return ( p + ... );
}

auto main() -> int
{
    using my_type = std::tuple<int, float>;

    const auto my_tuple = my_type( 1, 3.45f );

    const auto str = to_tuple_string( my_tuple );
	
    std::cout << to_tuple_string( my_tuple );
}
*/