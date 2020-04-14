#pragma once

#include <memory>

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
			void push_back( ListType value );

			list()
			{
				auto new_node{ std::make_unique<node<ListType>>( ListType() ) };

				head = std::move( new_node );
			}

			void remove_dupes();

			std::unique_ptr<node<ListType>> head;
		};

		list<Ty> list_;

	public:
		dedupe1() : list_{ } { }

		void remove_dupes() { list_.remove_dupes(); }
		void add_value( Ty value ) { list_.push_back( value ); }
	};
}