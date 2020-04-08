#pragma once

#include "list_node.h"

#include <utility>

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

		typedef list_node<T> node_type;

		using node = list_node<T>*;
		using node_pointer = typename list_node<T>::pointer;

		node_pointer head_;
		node tail_;
		size_t length_;

	public:

		linked_list()
			: head_{}, tail_( nullptr ), length_{ 0 }
		{ }

		explicit linked_list( std::initializer_list<T> init_list );
		linked_list( const self_type& other ) : linked_list() { append_list( other ); }
		linked_list( self_type&& other ) noexcept;

		~linked_list() = default;
		
		void swap( self_type& other ) noexcept;

		void push_back( T item ) { insert( length_, item ); }
		void push_front( T item ) { insert( 0, item ); }
		void append_list( const linked_list<T>& other );
		void remove( size_t position );

		iterator begin() { return iterator( head_.get() ); }
		iterator end() { return iterator( tail_ ); }

		node front() const { return head_.get(); }
		node back() const { return tail_; }

		void insert( size_t position, T value );

		bool empty() const { return !head_; }
		size_t size() const { return length_; }

		reference operator=( const self_type& other ); // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
		reference operator=( self_type&& other ) noexcept;  // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
		reference operator+( const self_type& other ) { append_list( other ); return *this; }

		void operator+=( const self_type& other ) { append_list( other ); }
		void operator+=( const T& value ) { push_back( value ); };
	};

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

	template <typename T>
	linked_list<T>::linked_list( self_type&& other ) noexcept
		: tail_( other.tail_ ), length_( other.length_ )
	{
		head_ = std::move( other.head_ );

		other.tail_ = nullptr;
		other.length_ = 0;
	}
	
	template <typename T>
	typename linked_list<T>::reference linked_list<T>::operator=( const linked_list<T>& other )
	{
		if( &other == this )
			return *this;

		auto temp( other );

		temp.swap( *this );

		return *this;
	}

	template <typename T>
	typename linked_list<T>::reference linked_list<T>::operator=( self_type&& other ) noexcept
	{
		if( &this == other )
			return *this;

		head_ = std::move( other.head_ );
		tail_ = other.tail_;
		length_ = other.length_;
		
		other.tail_ = nullptr;
		other.length_ = 0;

		return *this;
	}

	template <typename T>
	void linked_list<T>::swap( self_type& other ) noexcept
	{
		std::swap( head_, other.head_ );
		std::swap( tail_, other.tail_ );
		std::swap( length_, other.length_ );
	}

	template <typename T>
	void linked_list<T>::append_list( const linked_list<T>& other )
	{
		node source = other.head_.get(), prev = tail_;

		while( source )
		{
			node_pointer new_node = std::make_unique<node_type>( source->data );

			if( prev )
			{
				prev->next = std::move( new_node );
				prev = prev->next.get();
			}
			else
			{
				head_ = std::move( new_node );
				prev = head_.get();
			}
			
			source = source->next.get();
			length_++;
		}

		tail_ = prev;
	}
	
	template <typename T>
	void linked_list<T>::insert( const size_t position, T value )
	{
		if( position > 0 && position > length_ + 1 )
			throw std::runtime_error( "invalid_list_position" );

		node prev = nullptr, current = head_.get();

		for( size_t index = 0; index < position; ++index ) {
			prev = current;
			current = current->next.get();
		}

		node_pointer new_node = std::make_unique<node_type>( value );

		if( prev )
		{
			prev->next = std::move( new_node );
		}
		else
		{
			new_node->next = std::move( head_ );
			head_ = std::move( new_node );
		}

		if( tail_ == prev )
			tail_ = tail_ ? prev->next.get() : head_.get();

		length_++;
	}

	template <typename T>
	void linked_list<T>::remove( const size_t position )
	{
		if( position > 0 && position > length_ )
			throw std::runtime_error( "invalid_list_position" );

		node prev = nullptr, current = head_.get();

		for( size_t index = 0; index < position; index++ ) {
			prev = current;
			current = current->next.get();
		}

		if( prev )
		{
			prev->next = std::move( current->next );

			if( tail_ == current )
				tail_ = prev->next.get();
		}
		else
		{
			if( head_->next )
			{
				head_ = std::move( head_->next );
			}
			else
			{
				head_ = nullptr;
				tail_ = nullptr;
			}
		}

		length_--;
	}
}