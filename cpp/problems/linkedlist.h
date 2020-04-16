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
}