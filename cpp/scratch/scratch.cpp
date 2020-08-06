#include <bits/stdc++.h>

/* 21. Merge Two Sorted Lists.

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by
splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

struct merge_sorted_lists
{
	struct list_node
	{
		int val;
		list_node* next;
		list_node() : val( 0 ), next( nullptr ) {}
		explicit list_node( const int x ) : val( x ), next( nullptr ) {}
		list_node( const int x, list_node* next ) : val( x ), next( next ) {}		
	};

	/// <summary>
	/// merge lists
	///
	/// uses a sentinel node as a place-holder to append the sorted list elements,
	/// upon completion we simply store the sentinels next node which will be the
	/// head of the new weaved list, and delete the sentinel.
	/// </summary>
	/// <param name="l1">list 1</param>
	/// <param name="l2">list 2</param>
	/// <returns>sorted l1 + l2</returns>
	static list_node* merge_two_lists( list_node* l1, list_node* l2 )
	{
		const auto sentinel = new list_node( -1 );

		auto prev = sentinel;
		
		while( l1 != nullptr && l2 != nullptr )
		{
			if( l1->val <= l2->val )
			{
				prev->next = l1;
				l1 = l1->next;
			}
			else
			{
				prev->next = l2;
				l2 = l2->next;
			}
			
			prev = prev->next;
		}

		prev->next = l1 == nullptr ? l2 : l1;
		
		const auto head = sentinel->next;

		delete sentinel;

		return head;
	}

	static list_node* make_list( const std::vector<int>& values )
	{
		const auto sentinel = new list_node( -1 );
		auto prev = sentinel;
		
		for( const auto value : values )
		{
			prev->next = new list_node( value );
			prev = prev->next;
		}

		const auto head = sentinel->next;

		delete sentinel;
		
		return head;
	}

	static void cleanup_list( list_node * node )
	{
		while( node )
		{
			const auto tmp = node->next;
			delete node;
			node = tmp;
		}

		node = nullptr;
	}
};

auto main() -> int
{
	const auto l1 = merge_sorted_lists::make_list( { 1, 2, 4 } );
	const auto l2 = merge_sorted_lists::make_list( { 1, 3, 4 } );
	
	const auto result = merge_sorted_lists::merge_two_lists( l1, l2 );

	merge_sorted_lists::cleanup_list( result );
	
	std::cout << result;
	
	return 0;
}