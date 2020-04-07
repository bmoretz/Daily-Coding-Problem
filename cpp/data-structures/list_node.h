#pragma once

#include <memory>

namespace data_structures
{
	template<typename T>
	struct list_node
	{
		using pointer = std::unique_ptr<list_node>;

		T data;
		pointer next = { };

		explicit list_node( T val )
			: data{ std::move( val ) }
		{ }
	};
}