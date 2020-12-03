#include <bits/stdc++.h>

/*61. Rotate List.

Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

class rotate_list
{
    struct list_node;

    typedef std::unique_ptr<list_node> node_ptr;

	struct list_node
	{
        int val;
        node_ptr next;

		explicit list_node( const int val )
            : val{val}
        {}
	};
	
public:

	static std::vector<int> to_vector( list_node* head )
	{
        auto node = head;
        auto result = std::vector<int>();
		
		while( node )
		{
            result.push_back( node->val );
            node = node->next.get();
		}

        return result;
	}
	
	static node_ptr build_list( const std::vector<int>& values )
	{
        const auto sentinel = std::make_unique<list_node>( 0 );
        auto node = sentinel.get();

		for( auto val : values )
		{
            node->next = std::make_unique<list_node>( val );
            node = node->next.get();
		}

        return std::move( sentinel->next );
	}
	
    static node_ptr rotate_right( list_node* head, const int k )
    {
        auto sentinel = std::make_unique<list_node>( 0 );
        auto new_list = sentinel.get();

        auto nodes = std::vector<list_node*>();

        auto node = head;

        while( node )
        {
            nodes.push_back( node );
            node = node->next.get();
        }

        if( nodes.empty() ) return nullptr;

        auto head_index = nodes.size() - ( k % nodes.size() );

        if( head_index >= nodes.size() )
            head_index = 0;

        std::cout << head_index;

        auto new_head = nodes[ head_index ];

        while( new_head )
        {
            new_list->next = std::make_unique<list_node>( new_head->val );
            new_list = new_list->next.get();

            new_head = new_head->next.get();
        }

        for( auto index = 0; index < head_index; ++index )
        {
            new_list->next = std::make_unique<list_node>( nodes[ index ]->val );
            new_list = new_list->next.get();
        }

        return std::move( sentinel->next );
    }
};

auto main() -> int
{
    const auto head = rotate_list::build_list( { 1, 2, 3, 4, 5 } );
    const auto new_list = rotate_list::rotate_right( head.get(), 2 );
	
    auto actual = rotate_list::to_vector( new_list.get() );
	
    auto expected = std::vector<int>{ 4, 5, 1, 2, 3 };

	return 0;
}