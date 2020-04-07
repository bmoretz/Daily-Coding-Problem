#pragma once

#include "list_node.h"

#include <iostream>
#include <iterator>
#include <cassert>

namespace data_structures
{
	template<typename  T>
	class linked_list
	{
		class iterator
		{
		public:

			using node = list_node<T>;

			typedef iterator self_type;

			typedef node& reference;
			typedef node* pointer;

			explicit iterator( pointer node ) :
				ptr_( node )
			{ }

			self_type operator++()
			{
				if( ptr_ )
					ptr_ = ptr_->next.get();

				return *this;
			}

			reference operator*() { return *ptr_; }
			pointer operator->() { return ptr_; }

			bool operator==( const self_type& other ) { return ptr_ == other.ptr_; }
			bool operator!=( const self_type& other ) { return ptr_ != other.ptr_; }

		private:
			pointer ptr_;
		};

		typedef linked_list<T> self_type;
		typedef linked_list<T>& reference;
		typedef linked_list<T>* pointer;

		using node = list_node<T>*;
		using node_pointer = typename list_node<T>::pointer;

		node_pointer head_ = {};
		node tail_ = nullptr;

	public:

		linked_list() = default;
		~linked_list() = default;

		explicit linked_list( std::initializer_list<T> init_list );
		linked_list( const self_type& other );
		
		void push_back( T item );
		void push_front( T item );
		void append_list(const linked_list<T>& other);

		iterator begin() { return iterator( head_.get() ); }
		iterator end() { return iterator( tail_ ); }

		node front() const { return head_.get(); }
		node back() const { return tail_; }

		bool empty() const
		{
			return !head_;
		}

		//pointer operator=( const self_type& other );
		
		reference operator+( const self_type& other ) { append_list( other ); return *this; }
		
		void operator+=( const self_type& other ) { append_list( other ); }
		void operator+=( const T& value ) { push_back( value ); };
	};

	template <typename T>
	linked_list<T>::linked_list( const self_type& other )
	{
		if( other.empty() ) return;

		node node = other.head_.get();

		while( node )
		{
			push_back( node->data );
			node = node->next.get();
		}
	}
	
	template <typename T>
	void linked_list<T>::push_back( T item )
	{
		node new_node = new list_node<T>( std::move( item ) );

		if( tail_ )
			tail_->next.reset( new_node );
		else
			head_.reset( new_node );

		tail_ = new_node;
	}
	
	template <typename T>
	void linked_list<T>::push_front( T item )
	{
		node new_node = new list_node<T>( std::move( item ) );
		
		if( head_ )
			new_node->next.reset( head_.get() );
		else
			tail_ = new_node;

		head_.reset( new_node );
	}

	template <typename T>
	void linked_list<T>::append_list( const linked_list<T>& other )
	{
		node node = other.head_.get();

		while( node )
		{
			push_back( node->data );
			node = node->next.get();
		}
	}

	template <typename T>
	linked_list<T>::linked_list( const std::initializer_list<T> init_list ) :
		linked_list()
	{
		if( init_list.size() == 0 )
			return;

		for( auto& item : init_list )
		{
			push_back( item );
		}
	}
}
