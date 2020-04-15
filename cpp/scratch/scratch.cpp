#include <iostream>
#include <string>
#include <vector>

/* Delete Middle Node.
 *
 * Implement an algorithm to delete a list_node in the middle (i.e., any list_node but
 * the first and last list_node, not necessarily the exact middle) of a singly linked
 * list, given only access to that list_node.
 *
 * EXAMPLE:
 *
 * Input: the list_node c from the linked list:
 * a -> b -> c -> d -> e -> f
 *
 * Result: nothing is returned, but the list now looks like
 * a -> b -> d -> e -> f
 */

template<typename Ty>
class delete_middle1
{
	struct list_node
	{
		using node_pointer = std::unique_ptr<list_node>;
		
		explicit list_node( Ty value ) :
			data( std::move( value ) )
		{ }

		Ty data;

		node_pointer next;
	};

	typename list_node::node_pointer head_;
	
public:

	delete_middle1()
	{
		head_ = std::make_unique<list_node>( Ty() );
	}

	void push_back( Ty value )
	{
		auto node = head_.get();

		while( node->next )
			node = node->next.get();

		node->next = std::make_unique<list_node>( value );	
	}

	void del_mid()
	{
		auto len = size_t();

		for( auto node = head_->next.get();
			node;
			node = node->next.get() )
		{
			len++;
		}

		if( len > 2 )
		{
			const auto mid = ceil( len / 2 );

			auto to_remove = head_->next.get();
			list_node* prev = nullptr;

			for( auto index = size_t();
				index < mid;
				++index )
			{
				prev = to_remove;
				to_remove = to_remove->next.get();
			}

			prev->next = std::move( to_remove->next );
		}
	}
	
	void display_values()
	{
		for( auto node = head_->next.get();
			node;
			node = node->next.get())
		{
			std::cout << node->data;
		}

		std::cout << std::endl;
	}
};

void test_harness()
{
	std::cout << "Enter test input to build list, c when complete:" << std::endl;

	std::string input;
	
	auto list = delete_middle1<std::string>();
	
	while( getline( std::cin, input ) )
	{
		try
		{
			if( input == "C" ) break;
			
			list.push_back( input );
		}
		catch( const std::exception & ex )
		{
			std::cout << ex.what();
		}
	}

	list.display_values();

	std::cout << "deleting middle" << std::endl;

	list.del_mid();

	list.display_values();
}

auto main() -> int
{
	test_harness();
}