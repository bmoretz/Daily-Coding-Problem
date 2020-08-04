#pragma once

#include <vector>

namespace leetcode::linkedlist
{
	/*
	You are given two non-empty linked lists representing two non-negative integers. The digits are
	stored in reverse order and each of their nodes contain a single digit. Add the two numbers and
	return it as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example:

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807.
	*/

	struct add_numbers
	{
		struct list_node
		{
			int val;
			list_node* next;

			list_node() : val( 0 ), next( nullptr ) {}
			explicit list_node( const int x ) : val( x ), next( nullptr ) {}
			list_node( const int x, list_node* next ) : val( x ), next( next ) {}
		};

		static list_node* add_two_numbers( list_node* l1, list_node* l2 )
		{
			auto carry = 0;
			list_node* head = nullptr, * prev = nullptr;

			while( l1 != nullptr || l2 != nullptr || carry > 0 )
			{
				const auto left = l1 == nullptr ? 0 : l1->val;
				const auto right = l2 == nullptr ? 0 : l2->val;
				const auto value = left + right + carry;

				const auto current = new list_node( value % 10 );

				if( head == nullptr )
				{
					head = current;
				}
				else
				{
					prev->next = current;
				}

				carry = value > 9 ? 1 : 0;
				prev = current;

				if( l1 != nullptr ) l1 = l1->next;
				if( l2 != nullptr ) l2 = l2->next;
			}

			return head;
		}

		static auto build_list( const std::initializer_list<int>& values )
		{
			using node = list_node;

			node* head = nullptr, * prev = nullptr;

			for( auto value : values )
			{
				const auto current = new node( value );

				if( head == nullptr )
				{
					head = current;
				}
				else
				{
					prev->next = current;
				}

				prev = current;
			}

			return head;
		}

		static auto to_vector( list_node* node )
		{
			std::vector<int> result;

			while( node )
			{
				result.push_back( node->val );
				node = node->next;
			}
			
			return result;
		}
		
		static void clean_up( list_node* node )
		{
			while( node )
			{
				const auto temp = node->next;
				delete node;
				node = temp;
			}
		}
	};


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
		class node
		{
		public:
			int val;
			std::unique_ptr<node> next;
			node* random;

			explicit node( const int value )
				: val{ value }, random{ }
			{ }
		};

		static std::unique_ptr<node> copy_random_list( node* head )
		{
			if( head == nullptr ) return nullptr;

			auto new_head = std::make_unique<node>( head->val );
			auto old_new_map = std::map<node*, node*>{ { head, new_head.get() } };

			auto orig_node = head->next.get();
			auto prev = new_head.get();

			while( orig_node )
			{
				prev->next = std::make_unique<node>( orig_node->val );
				old_new_map[ orig_node ] = prev->next.get();

				prev = prev->next.get();
				orig_node = orig_node->next.get();
			}

			orig_node = head;

			while( orig_node )
			{
				if( orig_node->random != nullptr )
				{
					old_new_map[ head ]->random = old_new_map[ head->random ];
				}

				orig_node = orig_node->next.get();
			}

			return new_head;
		}

		static int tail_value;

		static std::unique_ptr<node> make_list( const std::vector<std::pair<int, int>>& values )
		{
			std::map<int, node*> map;

			auto head = std::make_unique<node>( values.front().first );

			map[ 0 ] = head.get();

			auto prev = head.get();

			for( auto index = 1UL; index < values.size(); ++index )
			{
				prev->next = std::make_unique<node>( values[ index ].first );
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
}