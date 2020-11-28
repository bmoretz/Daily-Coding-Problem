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

		static inline int tail_value = 1001;

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

	/*707. Design Linked List.

	Design your implementation of the linked list. You can choose to use a singly or doubly linked list.

	A node in a singly linked list should have two attributes: val and next. val is the value of the current node,
	and next is a pointer/reference to the next node.

	If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the
	linked list. Assume all nodes in the linked list are 0-indexed.

	Implement the MyLinkedList class:

	MyLinkedList() Initializes the MyLinkedList object.

	int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.

	void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion,
		the new node will be the first node of the linked list.

	void addAtTail(int val) Append a node of value val as the last element of the linked list.

	void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of
		the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.

	void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

	Example 1:

	Input
	["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
	[[], [1], [3], [1, 2], [1], [1], [1]]

	Output

	[null, null, null, null, 2, null, 3]

	Explanation

	MyLinkedList myLinkedList = new MyLinkedList();
	myLinkedList.addAtHead(1);
	myLinkedList.addAtTail(3);
	myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
	myLinkedList.get(1);              // return 2
	myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
	myLinkedList.get(1);              // return 3

	Constraints:

	0 <= index, val <= 1000
	Please do not use the built-in LinkedList library.
	At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
	*/

	class my_linked_list
	{
		struct node;

		typedef std::unique_ptr<node> node_ptr;

		struct node
		{
			int val;
			node_ptr next;

			explicit node( const int _val )
			{
				val = _val;
			}
		};

		node_ptr head_;

	public:

		my_linked_list()
		{
			head_ = std::make_unique<node>( 0 );
		}

		/// <summary>
		/// Get the value of the index-th node in the linked list. If the index is invalid, return -1.
		/// </summary>
		/// <param name="index">position of the element to get</param>
		/// <returns>the value of the element (if valid index)</returns>
		int get( const int index ) const
		{
			auto node = head_->next.get();

			for( auto cur = 0; node && cur < index; ++cur )
				node = node->next.get();

			return node ? node->val : -1;
		}

		/// <summary>
		/// Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
		/// </summary>
		/// <param name="val"></param>
		void add_at_head( int val ) const
		{
			auto old_head = std::move( head_->next );

			head_->next = std::make_unique<node>( val );

			if( old_head )
				head_->next->next = std::move( old_head );
		}

		/// <summary>
		/// Append a node of value val to the last element of the linked list.
		/// </summary>
		/// <param name="val"></param>
		void add_at_tail( int val ) const
		{
			auto cur = head_->next.get();

			while( cur->next )
			{
				cur = cur->next.get();
			}

			cur->next = std::make_unique<node>( val );
		}

		/// <summary>
		/// Add a node of value val before the index-th node in the linked list. If index equals to the length of
		/// linked list, the node will be appended to the end of linked list. If index is greater than
		/// the length, the node will not be inserted.
		/// </summary>
		/// <param name="index">position to insert</param>
		/// <param name="val">value </param>
		void add_at_index( const int index, const int val ) const
		{
			auto cur = head_.get();

			for( auto pos = 0; pos < index; ++pos )
				cur = cur->next.get();

			auto next = std::move( cur->next );

			cur->next = std::make_unique<node>( val );
			cur->next->next = std::move( next );
		}

		/// <summary>
		/// Delete the index-th node in the linked list, if the index is valid.
		/// </summary>
		/// <param name="index">index of the node</param>
		void delete_at_index( const int index ) const
		{
			auto cur = head_->next.get();
			auto prev = head_.get();

			for( auto pos = 0; cur && pos < index; ++pos )
			{
				prev = cur;
				cur = cur->next.get();
			}

			if( !cur ) return;

			prev->next = std::move( cur->next );
		}
	};

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
}