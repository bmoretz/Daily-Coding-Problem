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

/* BST Sequence.
 *
 * A binary search tree was created by traversing through an array from left
 * to right and inserting each element. Given a binary search tree with distinct
 * elements, print all possible arrays that could have led to this tree.
 *
 * EXAMPLE:
 *
 * Input:
 *            2
 *         /     \
 *       1         3
 *
 * Output:
 *
 *  {2, 1, 3}, {2, 3, 1}
 */

template<typename Ty>
struct bst_sequence
{
    using list_ptr = std::unique_ptr<std::list<Ty>>;
    using result_set = std::unique_ptr<std::vector<list_ptr>>;
	
    struct tree_node;

    using tree_node_ptr = std::unique_ptr<tree_node>;
	
	struct tree_node
	{
        Ty value;
        tree_node_ptr left{}, right{};

        explicit tree_node( const Ty& val ) :
			value{ val }
		{  }

		explicit tree_node( Ty&& val ) :
			value{ std::move( val ) }
        { }
	};

	static result_set get_sequences( const tree_node* node,
        result_set results = std::make_unique<std::vector<list_ptr>>() )
	{	
        if( !node )
        {
            results->push_back( std::make_unique<std::list<Ty>>() );
            return results;
        }

        auto prefix = std::make_unique<std::list<Ty>>();

        prefix->push_back( node->value );

        auto left_seq = get_sequences( node->left.get() );
        auto right_seq = get_sequences( node->right.get() );

        for( auto& left : *left_seq )
        {
            for( auto& right : *right_seq )
            {
                auto weaved = std::make_unique<std::vector<list_ptr>>();

                weave_lists( *left, *right,
                    *weaved, *prefix );
                 
                for( auto& weave : *weaved )
                {
                    results->push_back( std::move( weave ) );
                }
            }
        }
		
		return results;
	}

	static void weave_lists( std::list<Ty>& first, std::list<Ty>& second,
        std::vector<list_ptr>& results, std::list<Ty>& prefix )
	{
		if( first.empty() || second.empty() )
		{
            auto result = std::make_unique<std::list<Ty>>( prefix );

            for( const auto& f : first )
                result->push_back( f );

            for( const auto& s : second )
                result->push_back( s );

            results.push_back( std::move( result ) );
			
			return;
		}

        auto head_first = first.front();
        first.pop_front();
		
        prefix.push_back( head_first );
        weave_lists( first, second, results, prefix );
        prefix.pop_back();
        first.push_front( head_first );

        auto head_second = second.front();
        second.pop_front();
		
        prefix.push_back( head_second );
        weave_lists( first, second, results, prefix );
        prefix.pop_back();
        second.push_back( head_second );
	}
	
	static tree_node_ptr build_tree( const std::vector<Ty>& values, 
        const int& begin, const int& end )
	{
        if( begin >= end ) return nullptr;

        const auto mid = begin + std::ceil( ( end - begin ) / 2 );
		
        auto node = std::make_unique<tree_node>( values[ mid ] );

        node->left = build_tree( values, begin, mid );
        node->right = build_tree( values, mid + 1, end );

        return node;
	}
};

auto main() -> int
{
    using int_seq = bst_sequence<int>;

    // const auto values = { 1, 2, 3, 4, 5, 6, 7 };
    const auto values = { 1, 2, 3, 4, 5, 6 };
	
    const auto root = 
        int_seq::build_tree( values, 0, values.size() );

    const auto results = int_seq::get_sequences( root.get() );

    for( auto& result : *results )
    {
        std::ostringstream res;

        res << "{";
    	
        for( auto it = result->begin(); 
            it != result->end(); ++it  )
        {
            res << *it << ", ";
        }

        res << result->back() << "},";
    	
        std::cout << res.str() << std::endl;
    }
}