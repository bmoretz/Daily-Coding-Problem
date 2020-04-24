#pragma once

#include <memory>
#include <vector>
#include <set>

#include "linkedlist.h"

namespace linkedlist_problems
{
	/* Remove Duplicates.
	 *
	 * Write code to remove duplicates from an unsorted linked list.
	 *
	 * FOLLOW UP
	 *
	 * How would you solve this problem if a temporary buffer is not allowed?
	 */

	template<typename Ty>
	class dedupe
	{
		struct node
		{
			explicit node( Ty value )
				: data{ std::move( value ) }
			{ }

			Ty data;
			std::unique_ptr<node> next;
		};

		/// <summary>
		/// push_back
		///
		/// utility method for linked list dedupe to build the
		/// internal linked list data structure.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>	
		void push_back( Ty value )
		{
			auto new_node{ std::make_unique<node>( value ) };

			node* current = head_.get();

			while( current->next )
			{
				current = current->next.get();
			}

			current->next = std::move( new_node );
		}

		std::unique_ptr<node> head_;
	public:

		dedupe()
		{
			auto new_node{ std::make_unique<node> ( Ty() ) };

			head_ = std::move( new_node );
		}
		
		dedupe( const std::initializer_list<Ty> init_list ) :
			dedupe()
		{
			for( const auto& item : init_list )
			{
				push_back( item );
			}
		}

		/// <summary>
		/// gets a vector copy of the linked list values for
		/// unit testing.
		/// </summary>	
		std::vector<Ty> get_values()
		{
			std::vector<Ty> values;

			for( auto node = head_->next.get();
				node != nullptr;
				node = node->next.get() )
			{
				values.push_back( node->data );
			}

			return values;
		}
		
		/// <summary>
		/// dedupe1
		///
		/// This approach does uses a temporary buffer to
		/// complete this operation with minimal run-time
		/// complexity.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// </summary>	
		void dedupe1()
		{
			if( head_->next == nullptr ) return;
			
			std::set<Ty> seen;

			node* node = head_->next.get(), * prev = nullptr;

			while( node )
			{
				auto value = node->data;

				if( seen.find( value ) == seen.end() )
				{
					seen.insert( value );
				}
				else
				{
					prev->next = node->next ? std::move( node->next ) : nullptr;
					node = prev;
				}

				prev = node;
				node = node->next.get();
			}
		}

		/// <summary>
		/// dedupe 2
		///
		/// this approach does not use any additional temporary
		/// storage, only the raw pointers. 
		/// <complexity>
		///		<run-time>O(N^2)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>
		void dedupe2()
		{
			if( head_->next == nullptr ) return;

			node* cur = head_->next.get(), * runner = nullptr;

			while( cur )
			{
				runner = cur->next.get();

				while( runner )
				{
					node* prev = cur;

					if( cur->data == runner->data )
					{
						prev->next = std::move( runner->next );
						runner = prev;
					}

					prev = runner;
					runner = runner->next.get();
				}

				cur = cur->next.get();
			}
		}
	};

	/* Return k-th to Last.
	 *
	 * Implement an algorithm to find the kth to last element of a singly
	 * linked list.
	 */

	template<typename Ty>
	class klast
	{
		struct node
		{
			explicit node( Ty value )
				: data{ std::move( value ) }
			{
			}

			Ty data;
			std::unique_ptr<node> next;
		};

		std::unique_ptr<node> head_;

	public:

		klast()
		{
			auto new_node{ std::make_unique<node>( Ty() ) };

			head_ = std::move( new_node );
		}

		klast( const std::initializer_list<Ty> init_list ) :
			klast()
		{
			for( const auto& item : init_list )
			{
				push_back( item );
			}
		}
		
		void push_back( Ty value )
		{
			auto new_node{ std::make_unique<node>( value ) };

			node* current = head_.get();

			while( current->next )
			{
				current = current->next.get();
			}

			current->next = std::move( new_node );
		}

		/// <summary>
		/// klast
		///
		/// This approach uses two pointers to implement this functionality.
		/// The first pointer directly iterates the nodes, counting how many it has seen.
		/// Once we have seen k-1 nodes, we start incrementing the runner from the head,
		/// once we reach the end the runner will be pointed to the trailing k list_node.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="position">places from the back</param>
		/// <returns>requested list_node</returns>
		Ty from_back1( const size_t position )
		{
			node* requested = head_.get(), * current = head_->next.get();
			size_t seen = 0;

			while( current != nullptr )
			{
				if( seen < position )
					seen++;
				else
					requested = requested->next.get();

				current = current->next.get();
			}

			return requested != nullptr ? requested->data : Ty();
		}

		/// <summary>
		/// gets a vector copy of the linked list values for
		/// unit testing.
		/// </summary>
		std::vector<Ty> get_values()
		{
			std::vector<Ty> values;

			for( auto node = head_->next.get();
				node != nullptr;
				node = node->next.get() )
			{
				values.push_back( node->data );
			}

			return values;
		}
	};

	/* Delete Middle Node.
	 *
	 * Implement an algorithm to delete a list_node in the middle (i.e., any list_node but
	 * the first and last list_node, not necessarily the exact middle) of a singly linked
	 * list, given only access to that list_node.
	 *
	 * EXAMPLE:
	 *
	 * Input: the list_node c from the linked list:
	 * a -> b -> c -> d -> e -> f
	 *
	 * Result: nothing is returned, but the list now looks like
	 * a -> b -> d -> e -> f
	 */

	template<typename Ty>
	class delete_middle
	{
		struct list_node
		{
			using node_pointer = std::unique_ptr<list_node>;

			explicit list_node( Ty value ) :
				data( std::move( value ) )
			{ }

			Ty data;

			node_pointer next;
		};

		typename list_node::node_pointer head_;

	public:

		delete_middle()
		{
			head_ = std::make_unique<list_node>( Ty() );
		}

		delete_middle( const std::initializer_list<Ty> init_list ) :
			delete_middle()
		{
			for( const auto& item : init_list )
			{
				push_back( item );
			}
		}
		
		void push_back( Ty value )
		{
			auto node = head_.get();

			while( node->next )
				node = node->next.get();

			node->next = std::make_unique<list_node>( value );
		}

		/// <summary>
		/// delete middle 1
		///
		/// This is a brute force approach first calculates the length of the list, then
		/// calculates the index of the node to remove and re-iterates to that
		/// position and removes the node. Only advantage here is O(1) space
		/// complexity.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>
		void delete_middle1()
		{
			auto len = size_t();

			for( auto node = head_->next.get();
				node;
				node = node->next.get() )
			{
				len++;
			}

			if( len > 2 )
			{
				const auto mid = ceil( len / 2 );

				auto to_remove = head_->next.get();
				list_node* prev = nullptr;

				for( auto index = size_t();
					index < mid;
					++index )
				{
					prev = to_remove;
					to_remove = to_remove->next.get();
				}

				prev->next = std::move( to_remove->next );
			}
		}

		/// <summary>
		/// gets a vector copy of the linked list values for
		/// unit testing.
		/// </summary>
		std::vector<Ty> get_values()
		{
			std::vector<Ty> values;

			for( auto node = head_->next.get();
				node != nullptr;
				node = node->next.get() )
			{
				values.push_back( node->data );
			}

			return values;
		}
	};

	/* Partition.
	 *
	 * Write code to partition a linked list around a value x, such that all nodes less than
	 * x come before all nodes greater than or equal to x. If x is contained within the list,
	 * the values of x only need to be after the elements less than x. The partition element
	 * can appear anywhere in the "right partition"; it does not need to appear between the left
	 * and right partitions.
	 *
	 * EXAMPLE
	 *
	 * Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1, partition = 5
	 * Output: 3 -> 1 -> -> 2 -> 10 -> 5 -> 5 -> 8
	 */

	template<typename Ty>
	class partition
	{
		struct list_node
		{
			using node_pointer = std::unique_ptr<list_node>;

			explicit list_node( Ty value ) :
				data( std::move( value ) )
			{ }

			Ty data;

			node_pointer next;
		};

		typename list_node::node_pointer head_;
		list_node* tail_;

	public:

		partition()
		{
			head_ = std::make_unique<list_node>( Ty() );
			tail_ = head_->next.get();
		}

		partition( const std::initializer_list<Ty> init_list ) :
			partition()
		{
			for( const auto& item : init_list )
			{
				push_back( item );
			}
		}
		
		void push_back( Ty value )
		{
			auto node = head_.get();

			while( node->next )
			{
				node = node->next.get();
			}

			node->next = std::make_unique<list_node>( value );
			tail_ = node->next.get();
		}

		/// <summary>
		/// This is a brute force solution that uses a doubly-linked
		/// list to keep track of the head and the tail. During the partition
		/// we look at all nodes in a forward iteration, if a node has a value
		/// greater than the pivot, we push it to the back of the list.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="value">the value to pivot around</param>
		void partition1( Ty value )
		{
			if( !head_->next ) return;

			auto node = head_->next.get(), prev = head_.get();

			auto end = tail_;

			while( true ) // short-circuit after we have seen the original tail
			{
				if( node->data >= value )
				{
					tail_->next = std::move( prev->next );
					tail_ = tail_->next.get();
					
					prev->next = std::move( node->next );
					
					node = prev->next.get();
				}
				else
				{
					prev = node;
					node = node->next.get();
				}

				if( node == end ) break;
			}

			tail_ = prev;
		}

		/// <summary>
		/// partition 2
		///
		/// This approach has the same asymptotic complexity as
		/// the previous approach, however, the code is more readable
		/// and the algorithm is slightly more robust. We first create
		/// a new sentinel node for the elements smaller than the pivot,
		/// and as we iterate the original list, we move nodes with values
		/// smaller than the pivot to the s_list. Once we traverse, we will have
		/// two lists, s which contains values smaller than the pivot and the
		/// original values which are larger than the pivot. We append the
		/// original list to the tail of the new, s list, and then swap the head
		/// elements of the two lists to put the final ordered list in place.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="value">the pivot value</param>
		void partition2( Ty value )
		{
			if( !head_->next ) return;

			auto s_head = std::make_unique<list_node>( Ty() );

			auto s_cur = s_head.get(), prev = head_.get();

			for( auto node = head_->next.get();
				node;
				node = node->next.get() )
			{
				if( node->data < value )
				{
					s_cur->next = std::move( prev->next );
					s_cur = s_cur->next.get();
					
					prev->next = std::move( node->next );
					node = prev;
				}

				prev = node;
			}

			s_cur->next = std::move( head_->next );

			std::swap( head_, s_head );
		}
		
		/// <summary>
		/// gets a vector copy of the linked list values for
		/// unit testing.
		/// </summary>
		std::vector<Ty> get_values()
		{
			std::vector<Ty> values;

			for( auto node = head_->next.get();
				node != nullptr;
				node = node->next.get() )
			{
				values.push_back( node->data );
			}

			return values;
		}
	};

	/* Sum Lists.
	 *
	 *You have two numbers represented by a linked list, where each node
	 *contains a single digit. The digits are stored in reverse order,
	 *such that the 1's digit is at the head of the list. Write a function
	 *that adds the two numbers and returns the sum as a linked list.
	 *
	 *EXAMPLE:
	 *
	 *Input: ( 7 -> 1 -> 6 ) + ( 5 -> 9 -> 2 ). That is, 617 + 295.
	 *Output: 2 -> 1 -> 9. That is, 912.
	 *
	 *FOLLOW-UP:
	 *Suppose the digits are stored in forward order. Repeat the problem.
	 *
	 *EXAMPLE:
	 *
	 *Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
	 *Output: 9 -> 1 -> 2. That is, 912.
	 *
	 */

	class sum_list
	{
		struct list_node
		{
			explicit list_node( const int value )
				: value{ value }, prev( nullptr )
			{ }

			int value;

			std::unique_ptr<list_node> next;
			list_node* prev;
		};

		class list_iterator
		{
			list_node* node_;

		public:

			typedef list_iterator self_type;
			typedef list_iterator* pointer;
			typedef list_iterator& reference;

			explicit list_iterator( list_node* node )
				: node_( node )
			{ }

			reference operator++()
			{
				if( node_ )
					node_ = node_->next.get();

				return *this;
			}

			reference operator--()
			{
				if( node_ )
					node_ = node_->prev;

				return *this;
			}

			int& operator*() const { return node_->value; }
			int operator->() const { return node_->value; }
			
			bool operator==( const self_type& other ) const { return node_ == other.node_; }
			bool operator!=( const self_type& other ) const { return node_ != other.node_; }
		};

		class num_list
		{
			std::unique_ptr<list_node> head_{};
			list_node* tail_{};
			std::size_t length_{ };
			
		public:

			using iterator = list_iterator;

			[[nodiscard]] bool empty() const { return !head_->next; }

			[[nodiscard]] iterator begin() const { return iterator( head_->next.get() ); }

			[[nodiscard]] iterator end() const { return iterator( tail_->next.get() ); }

			[[nodiscard]] iterator rbegin() const { return iterator( tail_ ); }

			[[nodiscard]] iterator rend() const { return iterator( head_.get() ); }

			[[nodiscard]] std::size_t size() const { return length_; }
			
			explicit num_list()
			{
				head_ = std::make_unique<list_node>( 0 );
				tail_ = head_.get();
				head_->prev = tail_;
			}

			explicit num_list( const std::vector<int>& values )
				: num_list()
			{
				for( const auto& value : values )
				{
					push_back( value );
				}
			}

			num_list( const std::initializer_list<int>& values )
			{
				for( const auto& value : values )
				{
					push_back( value );
				}
			}

			num_list( num_list& other )
			{
				head_ = std::move( other.head_ );
				tail_ = other.tail_;
			}

			num_list( const num_list& other )
				: num_list()
			{
				for( auto item : other )
				{
					push_back( item );
				}
			}

			num_list( num_list&& other ) noexcept
				: num_list()
			{
				std::swap( head_, other.head_ );
				std::swap( tail_, other.tail_ );
			}

			~num_list() = default;
			
			num_list& operator=( const num_list& other )
			{
				if( this == &other ) return *this;

				auto temp( other );

				std::swap( temp, *this );

				return *this;
			}

			num_list& operator=( num_list&& other ) noexcept
			{
				if( this == &other )
					return *this;

				head_ = std::move( other.head_ );
				tail_ = other.tail_;

				return *this;
			}

			void push_front( int value )
			{
				auto new_node = std::make_unique<list_node>( value );

				if( head_->next )
				{
					new_node->next = std::move( head_->next );
					new_node->next->prev = new_node.get();
				}
				
				new_node->prev = head_.get();
				head_->next = std::move( new_node );

				length_++;
			}
			
			void push_back( int value )
			{
				auto node = head_.get();

				while( node->next )
					node = node->next.get();

				node->next = std::make_unique<list_node>( value );
				node->next->prev = node;

				tail_ = node->next.get();

				length_++;
			}

			[[nodiscard]] std::vector<int> get_values() const
			{
				std::vector<int> values;

				auto node = head_->next.get();

				while( node )
				{
					values.push_back( node->value );
					node = node->next.get();
				}

				return values;
			}

			bool operator==( const num_list& other )
			{
				return *this == other;
			}
		};

		using list_pointer = std::unique_ptr<num_list>;

		list_pointer num_one_, num_two_;

	public:

		explicit sum_list()
		{
			num_one_ = std::make_unique<num_list>();
			num_two_ = std::make_unique<num_list>();
		}

		explicit sum_list( const std::vector<int>& one,
			const std::vector<int>& two )
		{
			num_one_ = std::make_unique<num_list>( one );
			num_two_ = std::make_unique<num_list>( two );
		}

		/// <summary>
		/// sum list (backward)
		///
		/// This approach is straight forward iteration over the nodes,
		/// calculate the sum, put the 10's digit in the result array and
		/// carry the remainder (if any) over to the next digit.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <returns></returns>
		[[nodiscard]] list_pointer backward_sum() const
		{
			auto result = std::make_unique<num_list>();

			const auto left = num_one_.get();
			const auto right = num_two_.get();

			auto l_digit = num_one_->rbegin();
			auto r_digit = num_two_->rbegin();

			auto remainder = 0;

			while( l_digit != left->rend() || r_digit != right->rend() || remainder )
			{
				const auto num1 = l_digit == left->end() ? 0 : *l_digit;
				const auto num2 = r_digit == right->end() ? 0 : *r_digit;

				const auto digit = num1 + num2 + remainder;

				result->push_back( digit % 10 );

				remainder = digit > 9 ? 1 : 0;

				--l_digit;
				--r_digit;
			}

			return result;
		}

		/// <summary>
		/// sum list (forward)
		///
		/// This approach is a bit more involved than the more
		/// straight-forward approach of summing forward. Here we
		/// need to pad the shorter number (digit-wise) with zeros
		/// so that the digits line up equally in both numbers. Once
		/// we get the alignment correct, it's simply a matter of redoing
		/// the same calculation from above.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] list_pointer forward_sum() const
		{
			auto result = std::make_unique<num_list>();

			const auto left = num_one_.get();
			const auto right = num_two_.get();

			if( left->size() > right->size() )
			{
				for( auto r_pad = left->size() - right->size(); r_pad != 0; r_pad-- )
					right->push_back( 0 );
			}
			else if( right->size() > left->size() )
			{
				for( auto l_pad = right->size() - left->size(); l_pad != 0; l_pad-- )
					left->push_back( 0 );
			}

			auto l_digit = num_one_->begin();
			auto r_digit = num_two_->begin();

			auto remainder = 0;

			while( l_digit != left->end() || r_digit != right->end() || remainder )
			{
				const auto num1 = l_digit != left->end() ? *l_digit : 0;
				const auto num2 = r_digit != right->end() ? *r_digit : 0;

				const auto digit = num1 + num2 + remainder;

				result->push_front( digit % 10 );

				remainder = digit > 9 ? 1 : 0;

				++l_digit;
				++r_digit;
			}

			return result;
		}
	};

	/* Is Palindrome.
	 *
	 * Implement a function to check if a linked list is a palindrome.
	 */

	template<typename Ty>
	class is_palindrome
	{
		struct list_node
		{
			using node_pointer = list_node*;

			list_node()
				: next{ }, prev{ }
			{

			}

			explicit list_node( Ty value )
				: list_node()
			{
				data = std::move( value );
			}

			Ty data;

			node_pointer next, prev;
		};

		using node_pointer = list_node*;

		node_pointer head_, tail_;

	public:
		is_palindrome()
		{
			head_ = new list_node( Ty() );
			tail_ = head_->next;
		}

		is_palindrome( const std::initializer_list<Ty>& values )
			: is_palindrome()
		{
			for( const auto& value : values )
			{
				push_back( value );
			}
		}

		~is_palindrome()
		{
			auto node = head_;

			while( node->next )
			{
				auto temp = node->next;
				delete node;
				node = temp;
			}

			delete node;
		}

		void push_back( Ty value )
		{
			node_pointer node = head_;

			while( node->next )
				node = node->next;

			auto new_node = new list_node( value );

			node->next = new_node;
			new_node->prev = node;

			tail_ = new_node;
		}

		/// <summary>
		/// is palindrome 1
		///
		/// this approach uses a doubly linked list to
		/// iterate over both sides of the list. We can
		/// compare head to tail, and if they are the same
		/// values until we reach the middle ( or, past the middle
		/// in the case of an even length list), then the list
		/// is indeed a palindrome.
		/// </summary>
		/// <returns>true if palindrome</returns>
		[[nodiscard]] bool is_palindrome1() const
		{
			node_pointer start = head_->next, end = tail_;

			if( start == end ) return false;
			
			auto is_pal = true;

			while( start != end )
			{
				is_pal &= start->data == end->data;

				if( start->next == end )
					break;

				end = end->prev;
				start = start->next;
			}

			return is_pal;
		}

		[[nodiscard]] std::vector<Ty> get_values() const
		{
			std::vector<Ty> values;

			auto node = head_->next;

			while( node )
			{
				values.push_back( node->data );
				node = node->next;
			}

			return values;
		}
	};

	/* Intersection.
	 *
	 * Given two (singly) linked lists, determine if the two lists intersect. Return the
	 * intersecting node.
	 *
	 * Note that the intersection is defined based on reference, not value. That is, if the kth node
	 * of the first linked list is the exact same node (by reference) as the jth node of the second
	 * linked list, then they are intersecting.
	 */

	template<typename Ty>
	class intersection
	{
		struct list_node
		{
			using node_pointer = list_node*;

			list_node()
				: value{ }, next{ }
			{ }

			explicit list_node( Ty val )
				: list_node()
			{
				value = std::move( val );
			}

			Ty value;

			node_pointer next;
		};

		struct linked_list
		{
			using node_pointer = list_node*;

			node_pointer head{};
			node_pointer tail;

			linked_list()

			{
				head = new list_node( Ty() );
				tail = head->next;
			}

			linked_list( const std::initializer_list<Ty>& values )
				: linked_list()
			{
				for( const auto& value : values )
					push_back( value );
			}

			linked_list( linked_list& other )
				: linked_list()
			{
				if( this == other )
					return;

				this = other;
			}

			linked_list& operator=( const linked_list& other )
			{
				if( this == &other ) return *this;

				auto node = other.head->next;

				while( node )
				{
					push_back( node->value );
					node = node->next;
				}

				return *this;
			}

			void append( list_node* node )
			{
				if( !tail ) return;
				
				tail->next = node;

				while( node->next )
				{
					tail = node;
					node = node->next;
				}
			}

			node_pointer get_node( Ty value )
			{
				node_pointer node = head->next;

				while( node )
				{
					if( node->value == value )
						break;

					node = node->next;
				}

				return node;
			}

			void push_back( Ty value )
			{
				auto node = head;

				while( node->next )
				{
					node = node->next;
				}

				node->next = new list_node( value );
				tail = node->next;
			}

			[[nodiscard]] std::size_t length() const
			{
				node_pointer node = head->next;
				auto length = std::size_t();

				while( node )
				{
					length++;
					node = node->next;
				}

				return length;
			}
		};

		linked_list list1_, list2_;


	public:
		intersection() = delete;

		/// <summary>
		/// the constructor is responsible for creating and making the
		/// contained lists cross-reference each other.
		/// </summary>
		/// <param name="l1">list 1</param>
		/// <param name="l2">list 2</param>
		/// <param name="intersect">where the intersection should be set</param>
		intersection( const std::initializer_list<Ty>& l1,
			const std::initializer_list<Ty> l2, const Ty& intersect )
		{
			list1_ = linked_list( l1 );
			list2_ = linked_list( l2 );

			auto node = list1_.get_node( intersect );

			if( node )
			{
				list2_.append( node );
			}
			else
			{
				node = list2_.get_node( intersect );
				list1_.append( node );
			}
		}

		/// <summary>
		/// the container destructor must be responsible for cleaning
		/// up both the contained lists due to the intersection operation
		/// making the tail of one of the internal lists point to nodes
		/// it did not originally allocate.
		/// </summary>
		~intersection()
		{
			auto l_node = list1_.head, r_node = list2_.head;

			auto intersect = find_intersect1();

			while( l_node )
			{
				if( l_node == intersect )
					break;

				auto temp = l_node->next;

				delete l_node;

				l_node = temp;
			}

			while( r_node )
			{
				auto temp = r_node->next;

				delete r_node;

				r_node = temp;
			}
		}

		/// <summary>
		/// intersect 2
		///
		/// This approach is a direct brute force iteration
		/// over both the lists. We simply start at the head
		/// of the first list and check it against every node
		/// in the second list looking for a match, if found
		/// we can terminate early.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N^2)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <returns>intersecting node (if any)</returns>
		[[nodiscard]] list_node* find_intersect1() const
		{
			list_node* l_node = list1_.head;

			list_node* intersect = nullptr;

			while( l_node && !intersect )
			{
				list_node* r_node = list2_.head;

				while( r_node )
				{
					if( l_node == r_node )
					{
						intersect = l_node;
						break;
					}

					r_node = r_node->next;
				}

				l_node = l_node->next;
			}

			return intersect;
		}

		/// <summary>
		/// intersection 2
		///
		/// this approach finds the length of both lists and
		/// then determines the delta of the lengths in order
		/// to increment the longer list forward so that both
		/// lists can run in parallel increments. By incrementing
		/// in parallel this way, we can compare l_node to r_node
		/// and if there is an intersection we are guaranteed to
		/// find it since they will both have the same tails.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N+M)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <returns>intersecting node (if any)</returns>
		[[nodiscard]] list_node* find_intersect2() const
		{
			list_node* left, * right;

			auto n_left = list1_.length(), n_right = list2_.length();

			auto delta = 0;

			if( n_left >= n_right )
			{
				left = list1_.head;
				right = list2_.head;

				delta = n_left - n_right;
			}
			else
			{
				left = list2_.head;
				right = list1_.head;

				delta = n_right - n_left;
			}

			while( delta > 0 )
			{
				left = left->next;
				delta--;
			}

			list_node* intersect = nullptr;

			while( left && right )
			{
				if( left == right )
				{
					intersect = left;
					break;
				}

				left = left->next;
				right = right->next;
			}

			return intersect;
		}
	};

	/* Loop detection.
	 *
	 * Given a circular linked list, implement an algorithm that returns
	 * the node at the beginning of the loop.
	 *
	 * DEFINITION.
	 *
	 * Circular linked list: A (corrupt) linked list in which a node's next pointer
	 * points to an earlier node, so as to make a loop in a linked list.
	 *
	 * EXAMPLE.
	 *
	 * Input: A -> B -> C -> D -> E -> C [the same C as earlier]
	 * Output: C
	 */

	template <typename Ty>
	class loop_detect
	{
		struct list_node
		{
			using node_pointer = list_node*;

			list_node() = delete;

			explicit list_node( Ty value )
				: value( std::move( value ) )
			{  }

			~list_node()
			{
				std::cout << "deleted node: " << this <<
					" with value " << value << std::endl;
			}

			Ty value;
			node_pointer next{};
		};

		using node_pointer = list_node*;

		node_pointer head_, tail_;

	public:
		explicit loop_detect()
		{
			head_ = new list_node( Ty() );
			tail_ = head_->next;
		}

		~loop_detect()
		{
			std::set<list_node*> seen;

			node_pointer node = head_;

			while( node )
			{
				seen.insert( node );

				node_pointer next = nullptr;

				if( seen.find( node->next ) == seen.end() )
					next = node->next;

				delete node;

				node = next;
			}
		}

		loop_detect( loop_detect& other )
		{
			if( this == other )
				return;

			this = other;
		}

		loop_detect( const std::initializer_list<Ty>& init_list )
			: loop_detect()
		{
			for( const auto& item : init_list )
			{
				push_back( item );
			}
		}
		
		loop_detect& operator=( const loop_detect& other )
		{
			if( this == &other ) return *this;

			auto node = other.head_->next;

			while( node )
			{
				push_back( node->value );
				node = node->next;
			}

			return *this;
		}

		void push_back( Ty value )
		{
			node_pointer node = head_;

			while( node->next )
			{
				node = node->next;
			}

			node->next = new list_node{ value };
			tail_ = node->next;
		}

		void set_loop( Ty value )
		{
			auto node = head_->next;

			while( node )
			{
				if( node->value == value )
				{
					tail_->next = node;
					break;
				}

				node = node->next;
			}
		}

		/// <summary>
		/// loop detect 1
		///
		/// This is the brute force approach to detect a loop node
		/// in a linked list. We use two pointers, one to iterate over the
		/// list, and another sub-pointer to iterate it over it again,
		/// to check if any existing node points to both the next node in
		/// list, and an existing node in the list.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N^2)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <returns>the loop node</returns>
		node_pointer detect_loop1()
		{
			auto node = head_->next;

			list_node* loop_node = nullptr;

			while( node && !loop_node )
			{
				auto candidate = head_;

				while( node != candidate )
				{
					if( candidate->next == node->next ) {
						loop_node = candidate->next;
						break;
					}

					candidate = candidate->next;
				}

				node = node->next;
			}

			return loop_node;
		}
		
		/// <summary>
		/// loop detect 2
		/// 
		/// This approach is a substantial improvement over the brute
		/// force approach. We simply iterate over the list once using
		/// a single pointer, and save that pointer in a set each iteration.
		/// If we encounter a node that exists in the set, then we have a loop.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// </summary>
		/// <returns>the loop node</returns>
		node_pointer detect_loop2()
		{
			std::set<list_node*> seen;

			node_pointer node = head_->next;

			list_node* loop_node = nullptr;

			while( node )
			{
				if( seen.find( node ) != seen.end() )
				{
					loop_node = node;
					break;
				}

				seen.insert( node );

				node = node->next;
			}

			return loop_node;
		}
	};
}