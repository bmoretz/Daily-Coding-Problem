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

	A linked list is given such that each node contains an additional random pointer which could
	point to any node in the list or null.

	Return a deep copy of the list.

	The Linked List is represented in the input/output as a list of n nodes. Each node is represented
	as a pair of [val, random_index] where:

	val: an integer representing Node.val
	random_index: the index of the node (range from 0 to n-1) where random pointer points to,
	or null if it does not point to any node.

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

		/// <summary>
		/// this approach makes a copy of the nodes in the original list and stores them
		/// in a hash map by old node / new node -> k, v pairs. This ensures that all the nodes
		/// that will be in the new deep copy list will exist when we iterate the original list
		/// a second time to fill in the random node pointer mappings.
		/// </summary>
		/// <complexity>
		///		<run-time>O(n)</run-time>
		///		<space>O(n)</space>
		/// </complexity>
		/// <param name="head">the list to copy</param>
		/// <returns>deep copy of the passed in list</returns>
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

		/// <summary>
		/// helper method for unit testing, takes a vector of value/random pairs and builds a linked
		/// list.
		/// </summary>
		/// <complexity>
		///		<run-time>O(n)</run-time>
		///		<space>O(n)</space>
		/// </complexity>
		/// <param name="values">vector of val/random index values</param>
		/// <returns>linked list with values & pointers to specified random nodes</returns>
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

	/* 21. Merge Two Sorted Lists.

	Merge two sorted linked lists and return it as a new sorted list. The new list should be made by
	splicing together the nodes of the first two lists.

	Example:

	Input: 1->2->4, 1->3->4
	Output: 1->1->2->3->4->4
	*/

	struct merge_sorted_lists
	{
		struct list_node
		{
			int val;
			list_node* next;
			list_node() : val( 0 ), next( nullptr ) {}
			explicit list_node( const int x ) : val( x ), next( nullptr ) {}
			list_node( const int x, list_node* next ) : val( x ), next( next ) {}
		};

		/// <summary>
		/// merge lists
		///
		/// uses a sentinel node as a place-holder to append the sorted list elements,
		/// upon completion we simply store the sentinels next node which will be the
		/// head of the new weaved list, and delete the sentinel.
		/// </summary>
		/// <param name="l1">list 1</param>
		/// <param name="l2">list 2</param>
		/// <returns>sorted l1 + l2</returns>
		static list_node* merge_two_lists( list_node* l1, list_node* l2 )
		{
			const auto sentinel = new list_node( -1 );

			auto prev = sentinel;

			while( l1 != nullptr && l2 != nullptr )
			{
				if( l1->val <= l2->val )
				{
					prev->next = l1;
					l1 = l1->next;
				}
				else
				{
					prev->next = l2;
					l2 = l2->next;
				}

				prev = prev->next;
			}

			prev->next = l1 == nullptr ? l2 : l1;

			const auto head = sentinel->next;

			delete sentinel;

			return head;
		}

		static list_node* make_list( const std::vector<int>& values )
		{
			const auto sentinel = new list_node( -1 );
			auto prev = sentinel;

			for( const auto value : values )
			{
				prev->next = new list_node( value );
				prev = prev->next;
			}

			const auto head = sentinel->next;

			delete sentinel;

			return head;
		}

		static void cleanup_list( list_node* node )
		{
			while( node )
			{
				const auto tmp = node->next;
				delete node;
				node = tmp;
			}

			node = nullptr;
		}
	};

	/*25. Reverse Nodes in k-Group
	Hard

	2730

	373

	Add to List

	Share
	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

	k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

	Follow up:

	Could you solve the problem in O(1) extra memory space?
	You may not alter the values in the list's nodes, only nodes itself may be changed.


	Example 1:


	Input: head = [1,2,3,4,5], k = 2
	Output: [2,1,4,3,5]
	Example 2:


	Input: head = [1,2,3,4,5], k = 3
	Output: [3,2,1,4,5]
	Example 3:

	Input: head = [1,2,3,4,5], k = 1
	Output: [1,2,3,4,5]
	Example 4:

	Input: head = [1], k = 1
	Output: [1]


	Constraints:

	The number of nodes in the list is in the range sz.
	1 <= sz <= 5000
	0 <= Node.val <= 1000
	1 <= k <= sz
	*/

	class reverse_k_groups
	{
	public:

		struct list_node
		{
			int val;
			list_node* next;

			list_node() : val( 0 ), next( nullptr ) {}
			explicit list_node( const int x ) : val( x ), next( nullptr ) {}
			list_node( const int x, list_node* next ) : val( x ), next( next ) {}
		};

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

		// utility to get the length of the list
		static int get_length( list_node* head )
		{
			auto length = 0;
			auto node = head;

			while( node )
			{
				++length;
				node = node->next;
			}

			return length;
		}

		static list_node* reverse_k_group( list_node* head, const int k )
		{
			// the resulting reversed list
			const auto sentinel = std::make_unique<list_node>( 0 );
			auto new_node = sentinel.get();

			// get the length of the list so
			// we can keep track of when to stop
			// the reversal process
			auto index = 0, length = get_length( head );

			auto node = head;

			// while we have a reversal group remaining
			while( index + k <= length )
			{
				// save the current node as the new tail
				// so we can move the sentinel's pointer
				// up to the current location (this node
				// will be the last node in the reversed list)

				// ex 1 -> 2 > 3 --> 3 -> 2 -> 1
				list_node* prev = nullptr, * new_tail = node;
				// standard list reversal process

				// save next, next = prev, prev = node
				for( auto pos = 0; pos < k; ++pos )
				{
					const auto next = node->next;
					node->next = prev;

					prev = node;
					node = next;
				}

				// add the reversed group to the new list
				new_node->next = prev;
				// now the current sentinel node is pointing at the last
				// element in the list
				new_node = new_tail;
				index += k;
			}

			// no more groups left, so the tail will
			// just be the remaining elements of the original list
			if( node != nullptr )
				new_node->next = node;

			return sentinel->next;
		}
	};
}