#include <bits/stdc++.h>

/*328. Odd Even Linked List.

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are
talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 
Constraints:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].
*/

class even_odd_list
{
    struct list_node;

    typedef std::unique_ptr<list_node> node_ptr;

	struct list_node
	{
        int val;
        node_ptr next;
        
		explicit list_node( const int val )
            : val{ val }
		{ }
	};
	
public:

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

	static std::vector<int> to_vector( list_node* head )
    {
        auto result = std::vector<int>();

        auto node = head;

    	while( node )
    	{
            result.push_back( node->val );
            node = node->next.get();
    	}

        return result;
    }
	
    static node_ptr odd_even_list( list_node* head )
    {
	    auto odd_head = std::make_unique<list_node>( 0 ),
    		even_head = std::make_unique<list_node>( 0 );
    	
	    auto odd = odd_head.get(),
    		even = even_head.get();

        auto node = head;
        auto index = 1;

        while( node )
        {
            if( index % 2 == 0 )
            {
                even->next = std::make_unique<list_node>( node->val );
                even = even->next.get();
            }
            else
            {
                odd->next = std::make_unique<list_node>( node->val );
                odd = odd->next.get();
            }

            node = node->next.get();
            ++index;
        }

		odd->next = std::move( even_head->next );

        return std::move( odd_head->next );
    }
};

auto main() -> int
{
    const auto head = even_odd_list::build_list( { 1, 2, 3, 4, 5 } );

    const auto new_list = even_odd_list::odd_even_list( head.get() );
	
    auto actual = even_odd_list::to_vector( new_list.get() );
	
    auto expected = std::vector<int>{ 1, 3, 5, 2, 4, 6 };

	return 0;
}