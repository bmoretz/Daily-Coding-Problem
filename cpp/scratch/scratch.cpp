#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "../data-structures/linked_list.h"

using namespace data_structures::lists;

using int_list = linked_list<int>;

/* Remove Duplicates.
 *
 * Write code to remove duplicates from an unsorted linked list.
 *
 * FOLLOW UP
 *
 * How would you solve this problem if a temporary buffer is not allowed?
 */

template<typename T>
linked_list<T> remove_duplicates( linked_list<T> list )
{
	if( list.empty() ) return list;

	std::set<int> seen;
	auto deduped = linked_list<T>();

	for( const auto& item : list )
	{
		if( seen.find( item ) == seen.end() )
		{
			seen.insert( item );
			deduped.push_back( item );
		}
	}

	return deduped;
}

void print_list( int_list list )
{
	for( const auto& item : list )
	{
		std::cout << item;
	}

	std::cout << std::endl;
}

void test_harness()
{
	std::cout << "Enter test input to build list, c when complete:" << std::endl;

	std::string input;
	auto list = int_list();
	
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

	std::cout << "List Contents: " << std::endl;
	print_list( list );

	auto dedup_list = remove_duplicates( list );

	std::cout << "List Contents deduped: " << std::endl;

	print_list( dedup_list );
}

auto main() -> int
{
	test_harness();
}