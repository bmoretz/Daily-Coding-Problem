#include <bits/stdc++.h>

/*142. Linked List Cycle II.

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next
pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list. 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

class detected_cycle_ii
{
    struct list_node;

    typedef std::unique_ptr<list_node> node_ptr;
	
	struct list_node
	{
        int value;
        list_node* next{};
        node_ptr next_ptr;
		
        explicit list_node( int _value )
            : value{ _value }
        { }
	};

public:

	/// <summary>
	/// constructs a new linked list with a cycle that points to the node at
	/// the index of the intersect parameter.
	/// </summary>
	/// <param name="values">list of values for the list</param>
	/// <param name="intersect">node to loop to</param>
	/// <returns>new linked list</returns>
	static node_ptr build_list( const std::vector<int>& values, 
        const int intersect )
	{
        const auto sentinel = std::make_unique<list_node>( 0 );
        auto node = sentinel.get();

        auto nodes = std::vector<list_node*>();
		
		for( auto val : values )
		{
            node->next_ptr = std::make_unique<list_node>( val );
            node->next = node->next_ptr.get();
            node = node->next_ptr.get();
            nodes.push_back( node );
		}

        node->next = nodes[ intersect ];
		
        return std::move( sentinel->next_ptr );
	}

	/// <summary>
	/// returns the node that forms a cycle in a given linked list
	/// </summary>
	/// <param name="head">the list</param>
	/// <returns>cycle node (if any)</returns>
    static list_node* detect_cycle( list_node* head )
    {
        if( !head ) return nullptr;

        auto slow = head, fast = head;
        list_node* intersect = nullptr;

        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;

            if( slow == fast )
            {
                intersect = slow;
                break;
            }
        }

        if( !intersect ) return nullptr;

        auto p1 = head, p2 = intersect;

        while( p1 != p2 )
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};

auto main() -> int
{
    const auto head = detected_cycle_ii::build_list( { 3, 2, 0, -4 },1 );

    auto actual = detected_cycle_ii::detect_cycle( head.get() );

    auto expected = head->next;

	return 0;
}