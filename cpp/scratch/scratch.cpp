#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>

/* Loop detection.
 *
 * Given a circular linked list, implement an algorithm that returns
 * the node at the beginning of the loop.
 *
 * DEFINITION.
 *
 * Circular linked list: A (corrupt) linked list in which a node's next pointer
 * points to an earlier node, so as to make a loop in a linked list.
 *
 * EXAMPLE.
 *
 * Input: A -> B -> C -> D -> E -> C [the same C as earlier]
 * Output: C
 */

template <typename Ty>
class loop_detect
{
	struct list_node
	{
		using node_pointer = list_node*;

		list_node() = delete;

		explicit list_node( Ty value )
			: value( std::move( value ) )
		{  }

		~list_node()
		{
			std::cout << "deleted node: " << this <<
				" with value " << value << std::endl;
		}

		Ty value;
		node_pointer next{};
	};

	using node_pointer = list_node*;

	node_pointer head_, tail_;

public:
	explicit loop_detect()
	{
		head_ = new list_node( Ty() );
		tail_ = head_->next;
	}

	~loop_detect()
	{
		std::set<list_node*> seen;

		node_pointer node = head_;

		while( node )
		{
			seen.insert( node );

			node_pointer next = nullptr;

			if( seen.find( node->next ) == seen.end() )
				next = node->next;

			delete node;

			node = next;
		}
	}

	loop_detect( loop_detect& other )
	{
		if( this == other )
			return;

		this = other;
	}

	loop_detect& operator=( const loop_detect& other )
	{
		if( this == &other ) return *this;

		auto node = other.head_->next;

		while( node )
		{
			push_back( node->value );
			node = node->next;
		}

		return *this;
	}

	void push_back( Ty value )
	{
		node_pointer node = head_;

		while( node->next )
		{
			node = node->next;
		}

		node->next = new list_node{ value };
		tail_ = node->next;
	}

	void set_loop( Ty value )
	{
		auto node = head_->next;

		while( node )
		{
			if( node->value == value )
			{
				tail_->next = node;
				break;
			}

			node = node->next;
		}
	}
	
	node_pointer detect_loop2()
	{
		std::set<list_node*> seen;

		node_pointer node = head_->next;

		list_node* loop_node = nullptr;

		while( node )
		{
			if( seen.find( node ) != seen.end() )
			{
				loop_node = node;
				break;
			}

			seen.insert( node );

			node = node->next;
		}

		return loop_node;
 	}

	node_pointer detect_loop1()
	{
		auto node = head_->next;

		list_node* loop_node = nullptr;

		while( node && !loop_node )
		{
			auto candidate = head_->next;

			while( node != candidate )
			{
				if( candidate->next == node->next ) {
					loop_node = candidate->next;
					break;
				}

				candidate = candidate->next;
			}

			node = node->next;
		}

		return loop_node;
	}
};

void test_harness()
{
	std::cout << "Enter values for the test list, type C to quit.: \n";

	std::string input;
	auto list = loop_detect<std::string>();
	
	while( std::getline( std::cin, input) )
	{
		if( input == "C" )
			break;
		
		list.push_back( input );
	}

	std::cout << "Enter the node to loop: \n";

	std::getline( std::cin, input );

	list.set_loop( input );

	const auto loop_node = list.detect_loop1();

	std::cout << "Loop node: " << loop_node << "\n";
}

auto main() -> int
{
	test_harness();
}