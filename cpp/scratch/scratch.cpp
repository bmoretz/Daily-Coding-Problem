#include <bits/stdc++.h>

/*19. Remove Nth Node From End of List.

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

class remove_kth_node_from_end
{
    struct list_node;

    typedef std::unique_ptr<list_node> node_ptr;
	
	struct list_node
	{
        int value;
        node_ptr next;
		
        explicit list_node( const int value )
            : value{ value }
        { }
	};

public:

	/// <summary>
	/// constructs a new linked list from the values in the passed
	/// in vector.
	/// </summary>
	/// <param name="values">list of values for the list</param>
	/// <returns>new linked list</returns>
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
            result.push_back( node->value );
            node = node->next.get();
		}
		
        return result;
	}
	
    static list_node* remove_nth_from_end( list_node* head, const int n )
    {
        if( !head ) return nullptr;
		
        auto lead = head, lag = head;

        for( auto index = 0; index < n; ++index )
        {
            lead = lead->next.get();
        }

        if( !lead )
            return lag->next.get();

        auto prev = head;

        while( lead )
        {
            prev = lag;
            lead = lead->next.get();
            lag = lag->next.get();
        }

        prev->next = std::move( lag->next );

        return head;
    }
};

auto main() -> int
{
    const auto head = remove_kth_node_from_end::build_list( { 1, 2, 3, 4, 5 } );

    const auto new_list = remove_kth_node_from_end::remove_nth_from_end( head.get(), 2 );

    auto actual = remove_kth_node_from_end::to_vector( new_list );
	
    auto expected = std::vector<int>{ 1, 2, 4, 5 };

	return 0;
}