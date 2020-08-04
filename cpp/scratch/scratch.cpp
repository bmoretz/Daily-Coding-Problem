#include <bits/stdc++.h>

/* 138. Copy List with Random Pointer.

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.
*/

struct copy_list
{
	class Node
	{
	public:
		int val;
		std::unique_ptr<Node> next;
		Node* random;

		explicit Node( const int value )
			: val{ value }, random{ }
		{ }
	};
	
	static Node* copyRandomList( Node* head )
	{
		if( head == nullptr ) return nullptr;

		const auto new_head = std::make_unique<Node>( head->val );

		auto old_new_map = std::map<Node*, Node*>{ { head, new_head.get() } };

		auto node = head->next.get();
		auto prev = new_head.get();
		
		while( node )
		{
			prev->next = std::make_unique<Node>( node->val );
			old_new_map[ node ] = prev->next.get();

			prev = prev->next.get();
			node = node->next.get();
		}

		node = head;
		
		while( node != nullptr )
		{
			if( node->random != nullptr )
			{
				old_new_map[ head ]->random = old_new_map[ head->random ];
			}

			node = node->next.get();
		}

		return new_head.get();
	}
	
	static int tail_value;
	
	static std::unique_ptr<Node> make_list( const std::vector<std::pair<int, int>>& values )
	{
		std::map<int, Node*> map;

		auto head = std::make_unique<Node>( values.front().first );

		map[ 0 ] = head.get();

		auto prev = head.get();
		
		for( auto index = 1UL; index < values.size(); ++index )
		{
			prev->next = std::make_unique<Node>( values[ index ].first );
			map[ index ] = prev->next.get();
			prev = prev->next.get();
		}

		for( auto index = 0UL; index < values.size(); ++index )
		{
			const auto node_link = values.at( index ).second;
			
			if( node_link != tail_value )
			{
				map[ index ]->random = map[ node_link ];
			}
		}
		
		return head;
	}
};

int copy_list::tail_value = 1001;

auto main() -> int
{
	const auto input1 = copy_list::make_list
	({
			{3, copy_list::tail_value},
			{3, 0},
			{3, copy_list::tail_value}
		} );
	
	const auto result = copy_list::copyRandomList( input1.get() );

	std::cout << result->val;
	
	return 0;
}