#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

/* Intersection.
 *
 * Given two (singly) linked lists, determine if the two lists intersect. Return the
 * intersecting node.
 *
 * Note that the intersection is defined based on reference, not value. That is,  if the kth node
 * of the first linked list is the exact same node (by reference) as the jth node of the second
 * linked list, then they are intersecting.
 */

template<typename Ty>
class intersection
{
	struct list_node
	{
		using node_pointer = list_node*;

		list_node()
			: value{ }, next{ }
		{ }

		explicit list_node( Ty val )
			: list_node()
		{
			value = std::move( val );
		}

		~list_node()
		{
			std::cout << "deleted node: " << this << 
				" with value " << value << std::endl;
		}

		Ty value;

		node_pointer next;
	};

	struct linked_list
	{
		using node_pointer = list_node*;

		node_pointer head;
		node_pointer tail;
		
		linked_list()
		{
			head = new list_node( Ty() );
			tail = head->next;
		}

		linked_list( const std::initializer_list<Ty>& values )
			: linked_list()
		{
			for( const auto& value : values )
				push_back( value );
		}

		linked_list( linked_list& other )
			: linked_list()
		{
			if( this == other )
				return;

			this = other;
		}
		
		linked_list& operator=( const linked_list& other )
		{
			if( this == &other ) return *this;

			auto node = other.head->next;

			while( node )
			{
				push_back( node->value );
				node = node->next;
			}

			return *this;
		}
		
		~linked_list()
		{
			auto node = head;

			while( node->next )
			{
				auto temp = node->next;

				delete node;

				node = temp;
			}

			delete node;
		}

		void reverse()
		{
			list_node* node = head->next, * prev = nullptr;

			while( node )
			{
				auto temp = node->next;

				node->next = prev;
				prev = node;
				node = temp;
			}

			tail = head->next;
			head->next = prev;
		}
		
		void append( list_node* node )
		{
			tail->next = node;

			while( node->next )
			{
				tail = node;
				node = node->next;
			}
		}
		
		node_pointer get_node( Ty value )
		{
			node_pointer node = head->next;

			while( node )
			{
				if( node->value == value )
					break;

				node = node->next;
			}

			return node;
		}

		void push_back( Ty value )
		{
			auto node = head;

			while( node->next )
			{
				node = node->next;
			}

			node->next = new list_node( value );
			tail = node->next;
		}
	};

	linked_list list1_, list2_;


public:
	intersection() = delete;
	
	intersection( const std::initializer_list<Ty>& l1,
		const std::initializer_list<Ty> l2, const Ty& intersect )
	{
		list1_ = linked_list( l1 );
		list2_ = linked_list( l2 );
		
		auto node = list1_.get_node( intersect );

		if( node ) 
		{
			list2_.append( node );
		}
		else
		{
			node = list2_.get_node( intersect );
			list1_.append( node );
		}
	}

	list_node* find_intersect()
	{
		list1_.reverse(); list2_.reverse();

		auto l = list1_.head->next, r = list2_.head->next;

		list_node* intersect = nullptr;
		
		while( l && r )
		{
			if( l != r )
				break;

			intersect = l;
			
			l = l->next;
			r = r->next;
		}

		return intersect;
	}
};

void test_harness()
{
	auto list = intersection<int>{
		{ 1, 2, 3, 4, 5, 6},
		{ 5, 6, 7 },
	3 };

	const auto intersect = list.find_intersect();

	std::cout << "lists intersect at node: " << intersect
		<< " with value " << intersect->value;
}

auto main() -> int
{
	test_harness();
}