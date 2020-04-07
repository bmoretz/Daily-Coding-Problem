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
	// Linked List Tests
	//

    TEST_F( linked_lists_tests, push_back_tests )
    {
        auto list = linked_list<int>();

        EXPECT_EQ( list.first(), nullptr );
        EXPECT_EQ( list.last(), nullptr );
    	
        list.push_back( 5 );
		
        // should point to same list_node
        EXPECT_EQ( list.first(), list.last() );
        EXPECT_EQ( list.first()->data, 5 );
    	
        list.push_back( 4 );

        // should point to different list_node
        EXPECT_NE( list.first(), list.last() );

    	// head should point to tail
        EXPECT_EQ( list.first()->next.get(), list.last() );

    	// test data values
        EXPECT_EQ( list.first()->data, 5 );
        EXPECT_EQ( list.last()->data, 4 );

        list.push_back( 3 );

        EXPECT_EQ( list.first()->data, 5 );
        EXPECT_EQ( list.first()->next->data, 4 );
        EXPECT_EQ( list.last()->data, 3 );

        list.push_back( 2 );

        EXPECT_EQ( list.first()->data, 5 );
        EXPECT_EQ( list.first()->next->data, 4 );
        EXPECT_EQ( list.first()->next->next->data, 3 );
        EXPECT_EQ( list.last()->data, 2 );

        list.push_back( 1 );

        EXPECT_EQ( list.first()->data, 5 );
        EXPECT_EQ( list.first()->next->data, 4 );
        EXPECT_EQ( list.first()->next->next->data, 3 );
        EXPECT_EQ( list.first()->next->next->next->data, 2 );
        EXPECT_EQ( list.last()->data, 1 );
    }

    TEST_F( linked_lists_tests, push_back_prev_tests )
    {
        auto list = linked_list<int>();

        EXPECT_EQ( list.first(), nullptr );
    	EXPECT_EQ( list.last(), nullptr );

        list.push_back( 1 );

        EXPECT_EQ( list.first(), list.last() );

        list.push_back( 2 );

        EXPECT_EQ( list.first()->data, 1 );
        EXPECT_EQ( list.last()->data, 2 );
    }
	
    TEST_F( linked_lists_tests, init_list_1 )
    {
        auto list = linked_list<int>{ 5, 4, 3, 2, 1 };

        EXPECT_EQ( list.first()->data, 5 );
        EXPECT_EQ( list.first()->next->data, 4 );
        EXPECT_EQ( list.first()->next->next->data, 3 );
        EXPECT_EQ( list.first()->next->next->next->data, 2 );
        EXPECT_EQ( list.last()->data, 1 );
    }
}