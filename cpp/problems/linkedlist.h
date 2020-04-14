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
	class dedupe1
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

		dedupe1()
		{
			auto new_node{ std::make_unique<node> ( Ty() ) };

			head_ = std::move( new_node );
		}
		
		dedupe1( const std::initializer_list<Ty> init_list ) :
			dedupe1()
		{
			for( const auto& item : init_list )
			{
				push_back( item );
			}
		}

		/// <summary>
		/// remove_dupes
		///
		/// This approach does uses a temporary buffer to
		/// complete this operation with minimal run-time
		/// complexity.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// </summary>	
		void remove_dupes()
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

	template<typename Ty>
	class dedupe2
	{
		struct node
		{
			explicit node( Ty value )
				: data{ std::move( value ) }
			{ }

			Ty data;
			std::unique_ptr<node> next;
		};

		std::unique_ptr<node> head_;

	public:

		dedupe2()
		{
			auto new_node{ std::make_unique<node>( Ty() ) };

			head_ = std::move( new_node );
		}
		
		dedupe2( const std::initializer_list<Ty> init_list ) :
			dedupe2()
		{
			for( const auto& item : init_list )
			{
				push_back( item );
			}
		}

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
		
		/// <summary>
		/// remove dupes
		///
		/// this approach does not use any additional temporary
		/// storage, only the raw pointers. 
		/// <complexity>
		///		<run-time>O(N^2)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>
		void remove_dupes()
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


	/* Return k-th to Last.
	 *
	 * Implement an algorithm to find the kth to last element of a singly
	 * linked list.
	 */

	template<typename Ty>
	class klast1
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

		klast1()
		{
			auto new_node{ std::make_unique<node>( Ty() ) };

			head_ = std::move( new_node );
		}

		klast1( const std::initializer_list<Ty> init_list ) :
			klast1()
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
		/// once we reach the end the runner will be pointed to the trailing k node.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="position">places from the back</param>
		/// <returns>requested node</returns>
		Ty from_back( const size_t position )
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
}