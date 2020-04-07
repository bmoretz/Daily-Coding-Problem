#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/linked_list.h"

using namespace std;
using namespace data_structures;

namespace data_structure_tests
{
    /// <summary>
    /// Testing class for singly linked list.
    /// </summary>
    class linked_lists_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    //
	// Linked List Tests (using ints's)
	//

    TEST_F( linked_lists_tests, push_back )
    {
        auto list = linked_list<int>();

        EXPECT_EQ( list.front(), nullptr );
        EXPECT_EQ( list.back(), nullptr );
    	
        list.push_back( 5 );
		
        EXPECT_EQ( list.front(), list.back() );
        EXPECT_EQ( list.front()->data, 5 );
    	
        list.push_back( 4 );

        EXPECT_NE( list.front(), list.back() );

    	EXPECT_EQ( list.front()->next.get(), list.back() );

    	EXPECT_EQ( list.front()->data, 5 );
        EXPECT_EQ( list.front()->next->data, 4 );
    	
        EXPECT_EQ( list.back()->data, 4 );

        list.push_back( 3 );

        EXPECT_EQ( list.front()->data, 5 );
        EXPECT_EQ( list.front()->next->data, 4 );
        EXPECT_EQ( list.front()->next->next->data, 3 );
    	
        EXPECT_EQ( list.back()->data, 3 );

        list.push_back( 2 );

        EXPECT_EQ( list.front()->data, 5 );
        EXPECT_EQ( list.front()->next->data, 4 );
        EXPECT_EQ( list.front()->next->next->data, 3 );
        EXPECT_EQ( list.front()->next->next->next->data, 2 );
    	
        EXPECT_EQ( list.back()->data, 2 );

        list.push_back( 1 );

        EXPECT_EQ( list.front()->data, 5 );
        EXPECT_EQ( list.front()->next->data, 4 );
        EXPECT_EQ( list.front()->next->next->data, 3 );
        EXPECT_EQ( list.front()->next->next->next->data, 2 );
        EXPECT_EQ( list.front()->next->next->next->next->data, 1 );
    	
        EXPECT_EQ( list.back()->data, 1 );
    }

    TEST_F( linked_lists_tests, push_front )
    {
        auto list = linked_list<int>();

        EXPECT_EQ( list.front(), nullptr );
        EXPECT_EQ( list.back(), nullptr );

        list.push_front( 3 );

        EXPECT_EQ( list.front()->data, 3 );
        EXPECT_EQ( list.back()->data, 3 );

        EXPECT_EQ( list.back()->next, nullptr );
    	
        list.push_front( 2 );

        EXPECT_NE( list.front(), list.back() );

        list.push_front( 1 );

        EXPECT_NE( list.front(), list.back() );

        EXPECT_EQ( list.front()->data, 1 );
        EXPECT_EQ( list.front()->next->data, 2 );
        EXPECT_EQ( list.front()->next->next->data, 3 );
    }
	
    TEST_F( linked_lists_tests, init_list )
    {
        const auto list = linked_list<int>{ 5, 4, 3, 2, 1 };

        EXPECT_EQ( list.front()->data, 5 );
        EXPECT_EQ( list.front()->next->data, 4 );
        EXPECT_EQ( list.front()->next->next->data, 3 );
        EXPECT_EQ( list.front()->next->next->next->data, 2 );
        EXPECT_EQ( list.front()->next->next->next->next->data, 1 );
    	
        EXPECT_EQ( list.back()->data, 1 );
    }

    TEST_F( linked_lists_tests, iterator )
    {
        auto list = linked_list<int>{ 0, 1, 2, 3, 4, 5 };

        auto expected = 0;

        for( const auto& node : list )
        {
            auto actual = node.data;
        	
            EXPECT_EQ( actual, expected );

            expected++;
        }
    }

    TEST_F( linked_lists_tests, add_lists )
    {
        auto list1 = linked_list<int>{ 0, 1, 2, 3, 4 };
        const auto list2 = linked_list<int>{ 5, 6, 7, 8, 9 };
    	
        list1 + list2;

        auto expected = 0;
    	
        for( const auto& node : list1 )
        {
            auto actual = node.data;

            EXPECT_EQ( actual, expected );

            expected++;
        }
    }

    TEST_F( linked_lists_tests, append_value )
    {
        auto list = linked_list<int>{ 0, 1, 2 };

        EXPECT_EQ( list.front()->data, 0 );
        EXPECT_EQ( list.front()->next->data, 1 );
        EXPECT_EQ( list.front()->next->next->data, 2 );

        list += 3;
    	
        EXPECT_EQ( list.back()->data, 3 );
    }

    TEST_F( linked_lists_tests, copy_constructor )
    {
        auto list = linked_list<int>{ 0, 1, 2 };

        EXPECT_EQ( list.front()->data, 0 );
        EXPECT_EQ( list.front()->next->data, 1 );
        EXPECT_EQ( list.front()->next->next->data, 2 );

        auto list_copy( list );

        EXPECT_EQ( list_copy.front()->data, 0 );
        EXPECT_EQ( list_copy.front()->next->data, 1 );
        EXPECT_EQ( list_copy.front()->next->next->data, 2 );

        EXPECT_NE( &list, &list_copy );

        EXPECT_NE( list.front(), list_copy.front() );
        EXPECT_NE( list.back(), list_copy.back() );

        list_copy.push_back( 4 );

        EXPECT_EQ( list_copy.back()->data, 4 );
    	
        EXPECT_NE( list.back()->data, list_copy.back()->data );
    }

    TEST_F( linked_lists_tests, copy_assignment )
    {
    	
    }
}