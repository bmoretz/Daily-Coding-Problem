#pragma once

#include <ostream>
#include <utility>

#include "list_node.h"
#include "list_node_iterator.h"

namespace data_structures::lists
{
	using std::ostream;
	
	template <typename T>
	class linked_list;

	template <typename  T>
	ostream& operator<< ( ostream& os, const linked_list<T>& list );
	
	template<class Ty>
	class linked_list
	{
		class node_type : public list_node
		{
			friend class linked_list<Ty>;

			Ty value_;

		public:
			explicit node_type( Ty value ) :
				list_node()
			{
				value_ = std::move( value );
			}
		};

		template<class U>
		class iterator_type : public list_node_iterator {

			friend class linked_list<Ty>;
			[[nodiscard]] node_type* node() const { return static_cast< node_type* >( ptr_ ); }

		public:
			U& operator*() const { return static_cast<node_type *>( ptr_ )->value_; }
			U* operator->() const { return &static_cast< node_type *>( ptr_ )->value_; }
			explicit operator iterator_type<U const>() const { return ptr_; }
			explicit iterator_type( node_type* node ) : list_node_iterator{ node } {}
		};

		using node_pointer = std::unique_ptr<node_type>;

		node_pointer head_, tail_;
		size_t length_{};

		node_type* head() { return static_cast< node_type* >( head_->next_ ); }
		node_type* tail() { return static_cast< node_type* >( tail_.get() ); }

	public:

		using iterator = iterator_type<Ty>;
		using const_iterator = iterator_type<Ty const>;

		typedef linked_list<Ty> self_type;
		typedef linked_list<Ty>& reference;
		typedef const linked_list<Ty>& const_reference;
		typedef linked_list<Ty>* pointer;

		using size_type = std::size_t;
		using value_type = Ty;

		linked_list();

		explicit linked_list( std::initializer_list<Ty> init_list );
		linked_list( const self_type& other );
		linked_list( self_type&& other ) noexcept;

		~linked_list();

		void swap( reference other ) noexcept;

		void push_back( Ty item ) { insert( length_, item ); }
		void push_front( Ty item ) { insert( 0, item ); }
		void append( const_reference other );

		Ty pop_front();
		Ty pop_back();

		Ty at( size_type position );

		void erase( const_iterator iterator );
		void erase( iterator iterator );
		void remove_at( size_type position );

		void clear();

		iterator begin() { return iterator( head() ); }
		iterator end() { return iterator( tail() ); }

		const_iterator cbegin() { return const_iterator( head() ); }
		const_iterator cend() { return const_iterator( tail() ); }

		iterator rbegin() { return iterator( static_cast<node_type*>( tail_->prev_ ) ); }
		iterator rend() { return iterator( static_cast< node_type* >( head_.get() ) ); }

		[[nodiscard]] Ty front() const { return static_cast< node_type* >( head_->next_ )->value_; }
		[[nodiscard]] Ty back() const { return static_cast< node_type* >( tail_->prev_ )->value_; }

		[[nodiscard]] bool empty() const { return head_->next_ == tail_.get(); }
		[[nodiscard]] size_type size() const { return length_; }

		reference operator=( const self_type& other );
		reference operator=( self_type&& other ) noexcept;
		reference operator+( const self_type& other ) { append( other ); return *this; }

		void operator+=( const self_type& other ) { append( other ); }
		void operator+=( const Ty& value ) { push_back( value ); }

		template<typename U>
		friend ostream& operator<<( ostream& os, const linked_list& list );
		
	protected:
		void insert( size_type position, Ty value );
		node_type* get( size_type position );
	};

	template<typename T>
	ostream& operator<<( ostream& os, const linked_list<T>& list )
	{
		return os;
	}
	
	template <typename Ty>
	linked_list<Ty>::linked_list()
	{
		head_ = std::make_unique<node_type>( Ty() );
		tail_ = std::make_unique<node_type>( Ty() );

		head_->next_ = tail_.get();
		head_->prev_ = tail_.get();
		
		tail_->next_ = head_.get();
		tail_->prev_ = head_.get();
	}
	
	template <typename Ty>
	linked_list<Ty>::linked_list( const std::initializer_list<Ty> init_list ) :
		linked_list()
	{
		for( const auto& item : init_list )
		{
			push_back( item );
		}
	}

	template <typename Ty>
	linked_list<Ty>::linked_list( const self_type& other )
		: linked_list()
	{
		append( other );
	}

	template <typename Ty>
	linked_list<Ty>::linked_list( self_type&& other ) noexcept
		: linked_list()
	{
		swap( other );
	}

	template <typename Ty>
	linked_list<Ty>::~linked_list()
	{
		if( !head_ ) return; // destroyed from move
		
		clear();
	}

	template <typename Ty>
	linked_list<Ty>& linked_list<Ty>::operator=( const self_type& other )
	{
		if( this == &other ) return *this;
		
		auto temp( other );

		temp.swap( *this );

		return *this;
	}

	template <typename Ty>
	linked_list<Ty>& linked_list<Ty>::operator=( self_type&& other ) noexcept
	{
		if( this == &other )
			return *this;
		
		clear();
		
		// this <- other
		head_ = std::move( other.head_ );
		tail_ = std::move( other.tail_ );
		length_ = other.length_;
		other.length_ = 0;
		
		return *this;
	}

	template <typename Ty>
	void linked_list<Ty>::swap( reference other ) noexcept
	{
		std::swap( head_, other.head_ );
		std::swap( tail_, other.tail_ );
		std::swap( length_, other.length_ );
	}

	template <typename T>
	void linked_list<T>::append( const_reference other )
	{
		auto dest = tail_->prev_;

		for( auto source = other.head_->next_; 
			source != other.tail_.get();
			source = source->next_ )
		{
			auto new_node{ new node_type( static_cast<node_type*>( source )->value_ ) };

			if( new_node == nullptr )
				throw std::bad_alloc();
			
			new_node->prev_ = dest;
			dest->next_ = new_node;

			dest = new_node;
			length_++;
		}

		dest->next_ = tail();
		tail_->prev_ = dest;
	}

	template <typename Ty>
	Ty linked_list<Ty>::pop_front()
	{
		if( length_ <= 0 )
			throw std::runtime_error( "ATTEMPT_POP_EMPTY_LIST" );

		const auto value = front();

		erase( begin() );

		return value;
	}

	template <typename Ty>
	Ty linked_list<Ty>::pop_back()
	{
		if( length_ <= 0 )
			throw std::runtime_error( "ATTEMPT_POP_EMPTY_LIST" );

		const auto value = back();

		erase( rbegin() );

		return value;
	}

	template <typename Ty>
	Ty linked_list<Ty>::at( const size_type position )
	{
		if( position >= length_ )
			throw std::runtime_error( "INVALID_LIST_POSITION" );

		return get( position )->value_;
	}

	template <class Ty>
	void linked_list<Ty>::erase( const_iterator iterator )
	{
		delete iterator.node();

		length_--;
	}

	template <class Ty>
	void linked_list<Ty>::erase(iterator iterator)
	{
		delete iterator.node();

		length_--;
	}

	template <typename Ty>
	void linked_list<Ty>::insert( const size_type position, Ty value )
	{
		if( position > length_ + 1)
			throw std::runtime_error( "INVALID_LIST_POSITION" );
		
		node_type* next = get( position );
		
		auto new_node{ new node_type( value ) };

		if( new_node == nullptr )
			throw std::bad_alloc();

		auto prev = next->prev_;
		
		new_node->next_ = next;
		new_node->prev_ = prev;

		prev->next_ = new_node;
		next->prev_ = new_node;
		
		length_++;
	}

	template <typename Ty>
	typename linked_list<Ty>::node_type* linked_list<Ty>::get( const size_type position )
	{
		const auto mid = ceil( length_ / 2 );

		node_type* node;

		if( position <= mid )
		{
			node = head();

			for( size_type index = 0; index < position; index++ )
				node = static_cast< node_type* >( node->next_ );
		}
		else
		{
			node = tail();

			for( size_type index = length_; index > position; index-- )
				node = static_cast<node_type*>( node->prev_ );
		}

		return static_cast<node_type *> ( node );
	}

	template <typename Ty>
	void linked_list<Ty>::remove_at( const size_type position )
	{
		if( position >= length_ )
			throw std::runtime_error( "REMOVE_PAST_END_ATTEMPT" );
		
		node_type* node = get( position );
		
		delete node;

		length_--;
	}

	template <class Ty>
	void linked_list<Ty>::clear()
	{
		while( !empty() )
			erase( begin() );
	}
}
