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
					ptr_ = ptr_->next;

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

		typedef size_t size_type;

		typedef list_node<T> node_type;

		using node = typename list_node<T>::pointer;
		using node_reference = typename list_node<T>::reference;
		using node_pointer = std::unique_ptr<node_type>;

		node_pointer head_, tail_;
		size_t length_{};

	public:

		linked_list();

		explicit linked_list( std::initializer_list<T> init_list );
		linked_list( const self_type& other );
		linked_list( self_type&& other ) noexcept;

		~linked_list();

		void swap( self_type& other ) noexcept;

		void push_back( T item ) { insert( length_, item ); }
		void push_front( T item ) { insert( 0, item ); }
		void append( const linked_list<T>& other );

		node_reference get( const size_type position );
		bool remove( const node_reference node );

		iterator begin() { return iterator( head_->next ); }
		iterator end() { return iterator( tail_->prev ); }

		[[nodiscard]] node front() const { return head_->next; }
		[[nodiscard]] node back() const { return tail_->prev; }

		void insert( size_type position, T value );

		[[nodiscard]] bool empty() const { return head_->next == tail_.get(); }
		[[nodiscard]] size_type size() const { return length_; }

		reference operator=( const self_type& other ); // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
		reference operator=( self_type&& other ) noexcept;  // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
		reference operator+( const self_type& other ) { append( other ); return *this; }

		void operator+=( const self_type& other ) { append( other ); }
		void operator+=( const T& value ) { push_back( value ); }
	};

	template <typename T>
	linked_list<T>::linked_list()
	{
		head_ = std::make_unique<node_type>( 67 );
		tail_ = std::make_unique<node_type>( 69 );

		head_->next = tail_.get();
		tail_->next = head_.get();
	}

	template <typename T>
	linked_list<T>::linked_list( const std::initializer_list<T> init_list ) :
		linked_list()
	{
		for( auto& item : init_list )
		{
			push_back( item );
		}
	}

	template <typename T>
	linked_list<T>::linked_list( const self_type& other )
		: linked_list()
	{
		append( other );
	}

	template <typename T>
	linked_list<T>::linked_list( self_type&& other ) noexcept
		: length_( other.length_ )
	{
		head_ = std::move( other.head_ );
		other.head_ = {};
		
		tail_ = std::move( other.tail_ );
		other.tail_ = {};
		
		other.length_ = 0;
	}

	template <typename T>
	linked_list<T>::~linked_list()
	{
		for( node current = head_->next; current != tail_.get(); )
		{
			node temp = current;

			current = current->next;

			delete temp;
		}
	}

	template <typename T>
	typename linked_list<T>::reference linked_list<T>::operator=( const self_type& other )
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
		tail_ = std::move( other.tail_ );
		length_ = other.length_;

		other.head_ = nullptr;
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
	void linked_list<T>::append( const linked_list<T>& other )
	{
		node dest = tail_->prev;

		for( node source = other.head_->next; 
			source != other.tail_.get();
			source = source->next )
		{
			node new_node{ new node_type( source->data ) };

			new_node->prev = dest;
			dest->next = new_node;

			dest = new_node;
			length_++;
		}

		dest->next = tail_.get();
	}

	template <typename T>
	typename linked_list<T>::node_reference linked_list<T>::get( const size_type position )
	{
		if( position > 0 && position > length_ )
			throw std::runtime_error( "invalid_list_position" );

		node requested = nullptr;
		
		for( auto current = head_->next, index = 0;
			current != tail_->prev;
			current = current->next, index++ )
		{
			if( index == position )
				requested = *current;
		}

		return requested;
	}

	template <typename T>
	void linked_list<T>::insert( const size_type position, T value )
	{
		if( position > 0 && position > length_ + 1 )
			throw std::runtime_error( "invalid_list_position" );

		node prev = head_.get(), current = head_->next;

		for( size_type index = 0; index < position; ++index ) {
			prev = current;
			current = current->next;
		}

		node new_node{ new node_type( value ) };

		if( new_node == nullptr )
			throw std::bad_alloc();
		
		prev->next = new_node;
		new_node->next = current;
		new_node->prev = prev;
		current->prev = new_node;
		
		length_++;
	}

	template <typename T>
	bool linked_list<T>::remove( const node_reference node )
	{
		auto success = false;
		
		for( auto current = head_->next;
			current != tail_.get();
			current = current->next )
		{
			if( current == node )
			{
				auto temp = current;
				
				current->prev->prev = current->next;
				current->next->prev = current->prev;

				delete temp;

				length_--;

				success = true;
			}
		}

		return success;
	}
}