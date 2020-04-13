#pragma once

#include <iostream>

namespace data_structures::lists
{
	class list_node
	{
		list_node* next_, * prev_;
		friend class list_node_iterator;
		template<class T> friend class linked_list;

	protected:
		void unlink()
		{
			pointer next = next_, prev = prev_;

			next->prev_ = prev;
			prev->next_ = next;

			next_ = this;
			prev = this;
		}

	public:
		typedef list_node self_type;
		typedef list_node& reference;
		typedef list_node* pointer;
		typedef const list_node& const_reference;

		list_node()
			: next_( this ), prev_( this )
		{ }

		~list_node()
		{
			unlink();
		}
	};
}