#pragma once

#include "list_node.h"

namespace data_structures::lists
{
	class list_node_iterator
	{
	public:

		explicit list_node_iterator( list_node* node ) 
			: ptr_( node )
		{ }

		list_node_iterator& operator++()
		{
			this->ptr_ = this->ptr_->next_;

			return *this;
		}

		list_node_iterator& operator--()
		{
			this->ptr_ = this->ptr_->prev_;

			return *this;
		}

		list_node& operator*() { return *ptr_; }
		list_node* operator->() { return ptr_; }

		using iterator_category = std::bidirectional_iterator_tag;

		typedef list_node_iterator self_type;

		typedef list_node_iterator& reference;
		typedef list_node_iterator* pointer;

		bool operator==( const self_type& other ) { return ptr_ == other.ptr_; }
		bool operator!=( const self_type& other ) { return ptr_ != other.ptr_; }

	protected:
		list_node* ptr_;
	};
}