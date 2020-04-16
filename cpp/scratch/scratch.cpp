#include <iostream>
#include <string>
#include <vector>

/* Partition.
 *
 * Write code to partition a linked list around a value x, such that all nodes less than
 * x come before all nodes greater than or equal to x. If x is contained within the list,
 * the values of x only need to be after the elements less than x. The partition element
 * can appear anywhere in the "right partition"; it does not need to appear between the left
 * and right partitions.
 *
 * EXAMPLE
 *
 * Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1, partition = 5
 * Output: 3 -> 1 -> -> 2 -> 10 -> 5 -> 5 -> 8
 */

template<typename Ty>
class partition
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
	list_node* tail_;
	
public:

	partition()
	{
		head_ = std::make_unique<list_node>( Ty() );
		tail_ = head_->next.get();
	}
	
	void push_back( Ty value )
	{
		auto node = head_.get();

		while( node->next )
		{
			node = node->next.get();
		}

		node->next = std::make_unique<list_node>( value );
		tail_ = node->next.get();
	}

	void partition2( Ty value )
	{
		if( !head_->next ) return;

		auto s_head = std::make_unique<list_node>( Ty() );

		auto s_cur = s_head.get(), prev = head_.get();
		
		for( auto node = head_->next.get();
			node;
			node = node->next.get() )
		{
			if( node->data < value )
			{
				s_cur->next = std::move( node );
				prev->next = std::move( node->next );
			}
			
			prev = node;
		}

		s_cur->next = std::move( head_->next );

		std::swap( head_, s_head );
	}
	
	void partition1( Ty value )
	{
		if( !head_->next ) return;

		auto node = head_->next.get(), prev = head_.get();

		while( node )
		{
			if( node->data >= value )
			{
				tail_->next = std::move( prev->next );
				tail_ = tail_->next.get();
				
				prev->next = std::move( node->next );
				node = prev->next.get();
			}
			else
			{
				prev = node;
				node = node->next.get();
			}
		}
	}

	void display_values()
	{
		for( auto node = head_.get();
			node;
			node = node->next.get() )
		{
			std::cout << " -> " << node->data;
		}

		std::cout << std::endl;
	}
};

void test_harness()
{
	std::cout << "Enter test input to build list, c when complete:" << std::endl;

	std::string input;

	auto list = partition<int>();

	while( getline( std::cin, input ) )
	{
		try
		{
			if( input == "c" ) break;

			const auto value = std::stoi( input );
			list.push_back( value );
		}
		catch( const std::exception& ex )
		{
			std::cout << ex.what();
		}
	}

	list.display_values();

	std::cout << "enter value to partition list around:";
	std::getline( std::cin, input );

	const auto partition_value = std::stoi( input );

	list.partition1( partition_value );

	list.display_values();
}

auto main() -> int
{
	test_harness();
}