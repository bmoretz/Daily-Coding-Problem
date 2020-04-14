#include <iostream>
#include <string>
#include <vector>

/* Return k-th to Last.
 *
 * Implement an algorithm to find the kth to last element of a singly
 * linked list.
 */

template<typename Ty>
class klast1
{
	struct node
	{
		explicit node( Ty value )
			: data{ std::move( value ) }
		{	
		}
		
		Ty data;
		std::unique_ptr<node> next;
	};

	std::unique_ptr<node> head_;
	
public:

	klast1()
	{
		auto new_node{ std::make_unique<node>( Ty() ) };

		head_ = std::move( new_node );
	}
	
	void push_back( Ty value )
	{
		auto new_node{ std::make_unique<node>( value ) };

		node* current = head_.get();

		while( current->next )
		{
			current = current->next.get();
		}

		current->next = std::move( new_node );
	}

	Ty from_back( const size_t position )
	{
		node *requested = head_.get(), *current = head_->next.get();
		size_t seen = 0;

		while( current != nullptr )
		{
			if( seen < position )
				seen++;
			else
				requested = requested->next.get();

			current = current->next.get();
		}

		return requested != nullptr ? requested->data : Ty();
	}
	
	void display_values()
	{
		for( auto node = head_->next.get();
			node != nullptr;
			node = node->next.get() )
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
	
	auto list = klast1<int>();
	
	while( getline( std::cin, input ) )
	{
		try
		{
			if( input == "c" ) break;
			
			const auto value = std::stoi( input );

			list.push_back( value );
		}
		catch( const std::exception & ex )
		{
			std::cout << ex.what();
		}
	}

	list.display_values();

	std::cout << "enter position to retrieve: ";

	std::getline( std::cin, input);

	const auto element = list.from_back( std::stoi( input ) );

	std::cout << element;
}

auto main() -> int
{
	test_harness();
}