#include <iostream>
#include <string>
#include <vector>
#include <set>


/* Remove Duplicates.
 *
 * Write code to remove duplicates from an unsorted linked list.
 *
 * FOLLOW UP
 *
 * How would you solve this problem if a temporary buffer is not allowed?
 */

template<typename T>
class dedupe
{
	template<typename T>
	struct node
	{
		explicit node( T value )
			: data{ std::move( value ) }
		{	
		}
		
		~node()
		{
			std::cout << "deleted node: " << this << "with value: " << data << std::endl;
		}

		T data;
		std::unique_ptr<node<T>> next;
	};

	template<typename T>
	struct list
	{
		void push_back( T value )
		{
			auto new_node{ std::make_unique<node<T>>( value ) };

			node<T>* current = head.get();

			while( current->next )
			{
				current = current->next.get();
			}

			current->next = std::move( new_node );
		}

		list()
		{
			auto new_node{ std::make_unique<node<T>>( T() ) };

			head = std::move( new_node );
		}

		void remove_dupes()
		{
			std::set<T> seen;

			node<T>* cur = head->next.get(), *runner = nullptr;

			while( cur->next )
			{
				runner = cur->next.get();

				while( runner->next )
				{
					node<T>* prev = cur;
					
					if( cur->data == runner->data )
					{
						prev->next = std::move( runner->next );
						runner = prev;
					}

					prev = runner;
					runner = runner->next.get();
				}
				
				cur = cur->next.get();
			}
		}

		std::unique_ptr<node<T>> head;
	};

	list<T> list_;

public:
	dedupe() : list_{ } { }

	void remove_dupes() { list_.remove_dupes(); }
	
	void display_values()
	{
		for( auto node = list_.head->next.get();
			node->next != nullptr;
			node = node->next.get() )
		{
			std::cout << node->data;
		}

		std::cout << std::endl;
	}
	
	void add_value( T value ) { list_.push_back( value ); }
};

void test_harness()
{
	std::cout << "Enter test input to build list, c when complete:" << std::endl;

	std::string input;
	
	auto list = dedupe<int>();
	
	while( getline( std::cin, input ) )
	{
		try
		{
			if( input == "c" ) break;
			
			const auto value = std::stoi( input );

			list.add_value( value );
		}
		catch( const std::exception & ex )
		{
			std::cout << ex.what();
		}
	}

	list.display_values();

	list.remove_dupes();

	list.display_values();
}

auto main() -> int
{
	test_harness();
}