#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include <map>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are
stored in reverse order and each of their nodes contain a single digit. Add the two numbers and
return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct add_numbers
{
	struct list_node
	{
		int val;
		list_node* next;

		list_node() : val( 0 ), next( nullptr ) {}
		explicit list_node( const int x ) : val( x ), next( nullptr ) {}
		list_node( const int x, list_node* next ) : val( x ), next( next ) {}
	};

	static list_node* add_two_numbers( list_node* l1, list_node* l2 )
	{
		auto carry = 0;
		list_node *head = nullptr, *prev = nullptr;
		
		while( l1 != nullptr || l2 != nullptr || carry > 0 )
		{
			const auto left = l1 == nullptr ? 0 : l1->val;
			const auto right = l2 == nullptr ? 0 : l2->val;
			const auto value = left + right + carry;
			
			const auto current = new list_node( value % 10 );
			
			if( head == nullptr )
			{
				head = current;
			}
			else
			{
				prev->next = current;
			}

			carry = value > 9 ? 1 : 0;
			prev = current;
			
			if( l1 != nullptr ) l1 = l1->next;
			if( l2 != nullptr ) l2 = l2->next;
		}

		return head;
	}

	static auto build_list( const std::initializer_list<int>& values )
	{
		using node = list_node;

		node* head = nullptr, * prev = nullptr;

		for( auto value : values )
		{
			const auto current = new node( value );

			if( head == nullptr )
			{
				head = current;
			}
			else
			{
				prev->next = current;
			}

			prev = current;
		}

		return head;
	}
};

auto main() -> int
{
	const auto l1 = add_numbers::build_list( { 9, 9, 9 } );
	const auto l2 = add_numbers::build_list( { 1 } );

	const auto result = add_numbers::add_two_numbers( l1, l2 );

	return 0;
}
