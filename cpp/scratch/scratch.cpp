#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

/* Palindrome:
 *
 * Implement a function to check if a linked list is a palindrome.
 */

template<typename Ty>
class is_palindrome
{
	struct list_node
	{
		using node_pointer = list_node*;

		list_node()
			: next{ }, prev{ }
		{

		}

		explicit list_node( Ty value )
			: list_node()
		{
			data = std::move( value );
		}

		Ty data;

		node_pointer next, prev;
	};

	using node_pointer = list_node *;

	node_pointer head_, tail_;

public:
	is_palindrome()
	{
		head_ = new list_node( Ty() );
		tail_ = head_->next;
	}

	is_palindrome( const std::initializer_list<Ty>& values )
	{
		for( const auto& value : values )
		{
			push_back( value );
		}
	}
	
	~is_palindrome()
	{
		auto node = head_;

		while( node->next )
		{
			auto temp = node->next;
			delete node;
			node = temp;
		}

		delete node;
	}

	void push_back( Ty value )
	{
		node_pointer node = head_;

		while( node->next )
			node = node->next;

		auto new_node = new list_node( value );

		node->next = new_node;
		new_node->prev = node;

		tail_ = new_node;
	}

	[[nodiscard]] bool is_palindrome1() const
	{
		node_pointer start = head_->next, end = tail_;

		if( start == end ) return false;
		
		auto is_pal = true;

		while( start != end )
		{
			is_pal &= start->data == end->data;

			if( start->next == end )
				break;
			
			end = end->prev;
			start = start->next;
		}

		return is_pal;
	}

	[[nodiscard]] std::vector<Ty> get_values() const
	{
		std::vector<Ty> values;

		auto node = head_->next;

		while( node )
		{
			values.push_back( node->data );
			node = node->next;
		}

		return values;
	}
};

void test_harness()
{
	std::cout << "Enter test input to build list, c when complete:" << std::endl;

	std::string input;

	auto list = is_palindrome<std::string>();
	
	while( getline( std::cin, input ) )
	{
		try
		{
			if( input == "C" ) break;

			list.push_back( input );
		}
		catch( const std::exception& ex )
		{
			std::cout << ex.what();
		}
	}

	for( const auto& val : list.get_values() )
	{
		std::cout << val;
	}

	std::cout << std::endl;

	std::cout << "is palindrome ? " << list.is_palindrome1();
}

auto main() -> int
{
	test_harness();
}