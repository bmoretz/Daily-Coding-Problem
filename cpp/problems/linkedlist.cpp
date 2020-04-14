#include "pch.h"
#include "linkedlist.h"

#include <memory>
#include <set>

namespace linkedlist_problems
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
	template <typename Ty>
	template <typename ListType>
	void dedupe<Ty>::list<ListType>::push_back( ListType value )
	{
		auto new_node{ std::make_unique<node<ListType>>( value ) };

		node<ListType>* current = head.get();

		while( current->next )
		{
			current = current->next.get();
		}

		current->next = std::move( new_node );
	}

	/// <summary>
	/// remove_dupes
	///
	/// This approach does not use a temporary buffer
	/// </summary>
	template <typename Ty>
	template <typename ListType>
	void dedupe<Ty>::list<ListType>::remove_dupes()
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
}
