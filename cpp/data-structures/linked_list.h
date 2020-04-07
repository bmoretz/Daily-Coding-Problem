#pragma once

#include "list_node.h"
#include <memory>

namespace data_structures
{
	template<typename T>
	using link = list_node<T> *;
	
	template<typename  T>
	class linked_list
	{
		using node_pointer = typename list_node<T>::pointer;
		
		node_pointer head_ = {};
		link<T> tail_ = nullptr;

	public:

		explicit linked_list( std::initializer_list<T> init_list );
		
		linked_list() :
			head_( nullptr ), tail_( nullptr )
		{
		}

		void push_back( T item );
		void push_back( const linked_list<T> & source );

		link<T> first() const
		{
			return head_.get();
		}

		link<T> last() const
		{
			return tail_;
		}
		
		bool empty() const
		{
			return !head_;
		}
	};

	template <typename T>
	void linked_list<T>::push_back( T item )
	{
		auto new_node = new list_node<T>( std::move( item ) );

		if( tail_ )
			tail_->next.reset( new_node );
		else
			head_.reset( new_node );

		tail_ = new_node;
	}

	template <typename T>
	void linked_list<T>::push_back( const linked_list<T> & source )
	{
		if( source.empty() ) return;

		auto node = source.head_;

		while( node )
		{
			push_back( node.data );
			
			node.reset( node->next );
		}
	}
	
	
	template <typename T>
	linked_list<T>::linked_list( const std::initializer_list<T> init_list ) :
		linked_list()
	{
		if( init_list.size() == 0 )
			return;
		
		for( auto it = init_list.begin(); it != init_list.end(); ++it )
		{
			push_back( *it );
		}
	}
}