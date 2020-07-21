#pragma once

#include "list_node.h"

namespace data_structures::linkedlist
{
	class list_node_iterator
	{
	public:

		typedef list_node_iterator self_type;

		typedef list_node_iterator& reference;
		typedef list_node_iterator* pointer;
		
		explicit list_node_iterator( list_node* node ) 
			: ptr_( node )
		{ }

		reference operator++()
		{
			this->ptr_ = this->ptr_->next_;

			return *this;
		}

		reference operator--()
		{
			this->ptr_ = this->ptr_->prev_;

			return *this;
		}

		list_node& operator*() const { return *ptr_; }
		list_node* operator->() const { return ptr_; }

		using iterator_category = std::bidirectional_iterator_tag;

		bool operator==( const self_type& other ) const { return ptr_ == other.ptr_; }
		bool operator!=( const self_type& other ) const { return ptr_ != other.ptr_; }

	protected:
		list_node* ptr_;
	};
}