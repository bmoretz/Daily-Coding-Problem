#pragma once

#include <utility>

namespace data_structures
{
	template<typename  T>
	class linked_list
	{
		template<typename T>
		struct list_node
		{
			friend linked_list;

			typedef list_node<T> self_type;
			typedef list_node<T>& reference;
			typedef const list_node<T>& const_reference;
			typedef list_node<T>* pointer;

			explicit list_node( const T& val )
				: data{ std::move( val ) }
			{ }

			explicit list_node( const T&& val )
				: data{ std::move( val ) }
			{ }

			T data;

			~list_node()
			{
				std::cout << "deleted node: " << this << " with value: " << data << std::endl;
			}

		private:
			pointer next_ = nullptr, prev_ = nullptr;
		};
		
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
					ptr_ = ptr_->next_;

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
		typedef const linked_list<T>& const_reference;
		typedef linked_list<T>* pointer;

		typedef size_t size_type;

		typedef list_node<T> node_type;

		using node = typename node_type::pointer;
		using node_reference = typename node_type::reference;
		using const_node_reference = typename node_type::const_reference;
		using node_pointer = std::unique_ptr<node_type>;

		node_pointer head_, tail_;
		size_t length_{};
		
	public:

		linked_list();

		explicit linked_list( std::initializer_list<T> init_list );
		linked_list( const self_type& other );
		linked_list( self_type&& other ) noexcept;

		~linked_list();

		void swap( reference other ) noexcept;

		void push_back( T item ) { insert( length_, item ); }
		void push_front( T item ) { insert( 0, item ); }
		void append( const_reference other );
		
		const_node_reference at( size_type position ) { return *get( position ); }
		const_node_reference find( T value );

		void remove( T value );
		void remove_at( size_type position );
		
		iterator begin() { return iterator( head_->next_ ); }
		iterator end() { return iterator( tail_->prev_ ); }

		[[nodiscard]] const_node_reference front() const { return *head_->next_; }
		[[nodiscard]] const_node_reference back() const { return *tail_->prev_; }

		[[nodiscard]] bool empty() const { return head_->next == tail_.get(); }
		[[nodiscard]] size_type size() const { return length_; }

		reference operator=( const self_type& other ); // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
		reference operator=( self_type&& other ) noexcept;  // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
		reference operator+( const self_type& other ) { append( other ); return *this; }

		void operator+=( const self_type& other ) { append( other ); }
		void operator+=( const T& value ) { push_back( value ); }

	protected:
		void insert( size_type position, T value );
		node get( size_type position );
	};

	template <typename T>
	linked_list<T>::linked_list()
	{
		head_ = std::make_unique<node_type>( T() );
		tail_ = std::make_unique<node_type>( T() );

		head_->next_ = tail_.get();
		head_->prev_ = tail_.get();
		
		tail_->next_ = head_.get();
		tail_->prev_ = head_.get();
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
		: linked_list()
	{
		swap( other );
	}

	template <typename T>
	linked_list<T>::~linked_list()
	{
		if( !head_ ) return; // destroyed from move
		
		for( node current = head_->next_; current != tail_.get(); )
		{
			node temp = current;

			current = current->next_;

			delete temp;
		}
	}

	template <typename T> // NOLINT(cppcoreguidelines-c-copy-assignment-signature
	typename linked_list<T>::reference linked_list<T>::operator=( const self_type& other )  // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
	{
		if( this == &other ) return *this;
		
		auto temp( other );

		temp.swap( *this );

		return *this;
	}

	template <typename T> // NOLINT(cppcoreguidelines-c-copy-assignment-signature
	typename linked_list<T>::reference linked_list<T>::operator=( self_type&& other ) noexcept  // NOLINT(cppcoreguidelines-c-copy-assignment-signature, misc-unconventional-assign-operator)
	{
		if( this == &other )
			return *this;

		// clean up this
		for( node current = head_->next_; current != tail_.get(); )
		{
			node temp = current;

			current = current->next_;

			delete temp;
			
			length_--;
		}

		// this <- other
		head_ = std::move( other.head_ );
		tail_ = std::move( other.tail_ );
		length_ = other.length_;
		other.length_ = 0;
		
		return *this;
	}

	template <typename T>
	void linked_list<T>::swap( reference other ) noexcept
	{
		std::swap( head_, other.head_ );
		std::swap( tail_, other.tail_ );
		std::swap( length_, other.length_ );
	}

	template <typename T>
	void linked_list<T>::append( const_reference other )
	{
		node dest = tail_->prev_;

		for( node source = other.head_->next_; 
			source != other.tail_.get();
			source = source->next_ )
		{
			node new_node{ new node_type( source->data ) };

			if( new_node == nullptr )
				throw std::bad_alloc();
			
			new_node->prev_ = dest;
			dest->next_ = new_node;

			dest = new_node;
			length_++;
		}

		dest->next_ = tail_.get();
		tail_->prev_ = dest;
	}

	template <typename T>
	typename linked_list<T>::const_node_reference linked_list<T>::find( T value )
	{
		node search = head_->next_;
		
		for( ; search != tail_.get();
			search = search->next_ )
		{
			if( search->data == value )
				break;
		}

		return *search;
	}

	template <typename T>
	void linked_list<T>::insert( const size_type position, T value )
	{
		if( position > length_ + 1 )
			throw std::runtime_error( "INVALID_LIST_POSITION" );

		node next = get( position );
		node prev = next->prev_;
		
		node new_node{ new node_type( value ) };

		if( new_node == nullptr )
			throw std::bad_alloc();
		
		new_node->next_ = next;
		new_node->prev_ = prev;

		prev->next_ = new_node;
		next->prev_ = new_node;
		
		length_++;
	}

	template <typename T>
	typename linked_list<T>::node linked_list<T>::get( const size_type position )
	{
		if( position > length_ )
			throw std::runtime_error( "INVALID_LIST_POSITION" );

		const auto mid = ceil( length_ / 2 );

		node node;
		
		if( position <= mid )
		{
			node = head_->next_;

			for( size_type index = 0; index < position; index++ )
				node = node->next_;
		}
		else
		{
			node = tail_.get();

			for( size_type index = length_; index > position; index-- )
				node = node->prev_;
		}
		
		return node;
	}

	template <typename T>
	void linked_list<T>::remove( T value )
	{
		for( node node = head_->next_;
			node != tail_.get();
			node = node->next_ )
		{
			if( node->data == value )
			{
				auto temp = node;
				
				node->prev_->next_ = node->next_;
				node->next_->prev_ = node->prev_;

				delete temp;

				length_--;
				break;
			}
		}
	}

	template <typename T>
	void linked_list<T>::remove_at( const size_type position )
	{
		if( position > length_ )
			throw std::runtime_error( "INVALID_LIST_POSITION" );

		node node = head_->next_;

		for( size_type index = 0; index < position; index++ )
			node = node->next_;

		node->prev_->next_ = node->next_;
		node->next_->prev_ = node->prev_;

		delete node;

		length_--;
	}
}