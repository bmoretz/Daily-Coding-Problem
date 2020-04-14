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
		template<typename NodeType>
		struct node
		{
			explicit node( NodeType value )
				: data{ std::move( value ) }
			{ }

			NodeType data;
			std::unique_ptr<node<NodeType>> next;
		};

		template<typename ListType>
		struct list
		{
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
			void push_back( ListType value )
			{
				auto new_node{ std::make_unique<node<ListType>>( value ) };

				node<ListType>* current = head.get();

				while( current->next )
				{
					current = current->next.get();
				}

				current->next = std::move( new_node );
			}

			list()
			{
				auto new_node{ std::make_unique<node<ListType>>( ListType() ) };

				head = std::move( new_node );
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
				std::set<ListType> seen;

				node<ListType>* node = head->next.get(), * prev = nullptr;

				while( node->next )
				{
					auto value = node->data;

					if( seen.find( value ) == seen.end() )
					{
						seen.insert( value );
					}
					else
					{
						prev->next = std::move( node->next );
						node = prev;
					}

					prev = node;
					node = node->next.get();
				}
			}

			std::unique_ptr<node<ListType>> head;
		};

		list<Ty> list_;

	public:
		dedupe1() : list_{ } { }
		dedupe1( const std::initializer_list<Ty> init_list ) :
			dedupe1()
		{
			for( const auto& item : init_list )
			{
				list_.push_back( item );
			}
		}

		/// <summary>
		/// gets a vector copy of the linked list values for
		/// unit testing.
		/// </summary>	
		std::vector<Ty> get_values()
		{
			std::vector<Ty> values;

			for( auto node = list_.head->next.get();
				node->next != nullptr;
				node = node->next.get() )
			{
				values.push_back( node->data );
			}

			return values;
		}

		void remove_dupes() { list_.remove_dupes(); }
		void add_value( Ty value ) { list_.push_back( value ); }
	};

	template<typename Ty>
	class dedupe2
	{
		template<typename NodeType>
		struct node
		{
			explicit node( NodeType value )
				: data{ std::move( value ) }
			{ }

			NodeType data;
			std::unique_ptr<node<NodeType>> next;
		};

		template<typename ListType>
		struct list
		{
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
			void push_back( ListType value )
			{
				auto new_node{ std::make_unique<node<ListType>>( value ) };

				node<ListType>* current = head.get();

				while( current->next )
				{
					current = current->next.get();
				}

				current->next = std::move( new_node );
			}

			list()
			{
				auto new_node{ std::make_unique<node<ListType>>( ListType() ) };

				head = std::move( new_node );
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
				node<ListType>* cur = head->next.get(), * runner = nullptr;

				while( cur->next )
				{
					runner = cur->next.get();

					while( runner->next )
					{
						node<ListType>* prev = cur;

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

			std::unique_ptr<node<ListType>> head;
		};

		list<Ty> list_;

	public:
		dedupe2() : list_{ } { }
		dedupe2( const std::initializer_list<Ty> init_list ) :
			dedupe2()
		{
			for( const auto& item : init_list )
			{
				list_.push_back( item );
			}
		}
		
		void remove_dupes() { list_.remove_dupes(); }

		/// <summary>
		/// gets a vector copy of the linked list values for
		/// unit testing.
		/// </summary>	
		std::vector<Ty> get_values()
		{
			std::vector<Ty> values;

			for( auto node = list_.head->next.get();
				node->next != nullptr;
				node = node->next.get() )
			{
				values.push_back( node->data );
			}

			return values;
		}

		void add_value( Ty value ) { list_.push_back( value ); }
	};
}