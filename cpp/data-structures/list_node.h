#pragma once

#include <utility>

namespace data_structures
{
	template<typename T>
	struct list_node
	{
		typedef list_node<T> self_type;
		typedef list_node<T>& reference;
		typedef list_node<T>* pointer;

		pointer next = nullptr, prev = nullptr;
		T data;

		explicit list_node( const T& val )
			: data{ std::move( val ) }
		{ }

		explicit list_node( const T&& val )
			: data{ std::move( val ) }
		{ }

		~list_node()
		{
			std::cout << "deleted node: " << this << " with value: " << data << std::endl;
		}
	};
}