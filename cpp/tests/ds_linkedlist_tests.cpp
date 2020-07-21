#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/linked_list.h"

namespace data_structures::linkedlist::tests
{
    using int_list = linked_list<int>;

    /// <summary>
    /// Testing class for doubly linked circular linked list.
    /// </summary>
    class linked_list_tests :
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

    TEST_F( linked_list_tests, at_head )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );

        auto actual = list.at( 0 );

        EXPECT_EQ( actual, 1 );
    }

    TEST_F( linked_list_tests, at_tail )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );

        auto actual = list.at( 2 );

        EXPECT_EQ( actual, 3 );
    }

    TEST_F( linked_list_tests, get_head )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );

        auto actual = list.at( 0 );

        EXPECT_EQ( actual, 1 );
    }

    TEST_F( linked_list_tests, push_front_empty )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_back( 1 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 1 );
    }

    TEST_F( linked_list_tests, push_back )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_back( 3 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front(), 3 );
        EXPECT_EQ( list.back(), 3 );

        list.push_back( 2 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front(), 3 );
        EXPECT_EQ( list.back(), 2 );

        list.push_back( 1 );

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.front(), 3 );
        EXPECT_EQ( list.back(), 1 );
    }

    TEST_F( linked_list_tests, push_front )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_front( 3 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front(), 3 );
        EXPECT_EQ( list.back(), 3 );

        list.push_front( 2 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front(), 2 );
        EXPECT_EQ( list.back(), 3 );

        list.push_front( 1 );

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 3 );
    }

    TEST_F( linked_list_tests, init_list )
    {
        auto list = int_list{ 5, 4, 3, 2, 1 };

        EXPECT_EQ( list.size(), 5 );

        EXPECT_EQ( list.front(), 5 );
        EXPECT_EQ( list.back(), 1 );

        EXPECT_EQ( list.at( 4 ), 1 );
        EXPECT_EQ( list.at( 3 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );
        EXPECT_EQ( list.at( 1 ), 4 );
        EXPECT_EQ( list.at( 0 ), 5 );
    }

    TEST_F( linked_list_tests, out_of_bounds )
    {
        auto list = int_list{ 1, 2, 3, 4 };

        try
        {
            auto no_exist = list.at( 4 );
        	
            FAIL() << "This should throw an error.";
        }
        catch( std::runtime_error& e )
        {
            EXPECT_EQ( std::string( e.what() ), "INVALID_LIST_POSITION" );
        }
    }

    TEST_F( linked_list_tests, append_value )
    {
        auto list = int_list{ 0, 1, 2 };

        EXPECT_EQ( list.size(), 3 );
    	
        list += 3;

        EXPECT_EQ( list.size(), 4 );
        EXPECT_EQ( list.back(), 3 );

        EXPECT_EQ( list.at( 0 ), 0 );
        EXPECT_EQ( list.at( 1 ), 1 );
        EXPECT_EQ( list.at( 2 ), 2 );
        EXPECT_EQ( list.at( 3 ), 3 );
    }

    TEST_F( linked_list_tests, swap )
    {
        auto list1 = int_list{ 1, 2, 3 };
        auto list2 = int_list{ 4, 5, 6 };

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list2.size(), 3 );

        list1.swap( list2 );

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list2.size(), 3 );

        EXPECT_EQ( list1.at( 0 ), 4 );
        EXPECT_EQ( list1.at( 1 ), 5 );
        EXPECT_EQ( list1.at( 2 ), 6 );

        EXPECT_EQ( list2.at( 0 ), 1 );
        EXPECT_EQ( list2.at( 1 ), 2 );
        EXPECT_EQ( list2.at( 2 ), 3 );
    }

    TEST_F( linked_list_tests, copy_constructor )
    {
        auto list = int_list{ 0, 1, 2 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ), 0 );
        EXPECT_EQ( list.at( 1 ), 1 );
        EXPECT_EQ( list.at( 2 ), 2 );

        auto list_copy( list );

        EXPECT_EQ( list_copy.size(), 3 );
        EXPECT_EQ( list_copy.at( 0 ), 0 );
        EXPECT_EQ( list_copy.at( 1 ), 1 );
        EXPECT_EQ( list_copy.at( 2 ), 2 );

        list_copy.push_back( 4 );

        EXPECT_EQ( list_copy.back(), 4 );

        EXPECT_NE( list.back(), list_copy.back() );
    }
	
    TEST_F( linked_list_tests, copy_assignment_equal )
    {
        auto list1 = int_list{ 0, 1, 2 };

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ), 0 );
        EXPECT_EQ( list1.at( 1 ), 1 );
        EXPECT_EQ( list1.at( 2 ), 2 );
                       
        auto list2 = int_list{ 3, 4, 5 };

        EXPECT_EQ( list2.size(), 3 );

        list2 = list1;

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ), 0 );
        EXPECT_EQ( list1.at( 1 ), 1 );
        EXPECT_EQ( list1.at( 2 ), 2 );

        EXPECT_EQ( list2.size(), 3 );
        EXPECT_EQ( list2.at( 0 ), 0 );
        EXPECT_EQ( list2.at( 1 ), 1 );
        EXPECT_EQ( list2.at( 2 ), 2 );
    }

    TEST_F( linked_list_tests, self_copy )
    {
        auto list1 = int_list{ 0, 1, 2 };

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ), 0 );
        EXPECT_EQ( list1.at( 1 ), 1 );
        EXPECT_EQ( list1.at( 2 ), 2 );

        list1 = list1;

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ), 0 );
        EXPECT_EQ( list1.at( 1 ), 1 );
        EXPECT_EQ( list1.at( 2 ), 2 );
    }

    TEST_F( linked_list_tests, move_assignment_operator )
    {
        auto list1 = int_list{ 1, 2, 3 };

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ), 1 );
        EXPECT_EQ( list1.at( 1 ), 2 );
        EXPECT_EQ( list1.at( 2 ), 3 );

        auto list2 = int_list{ 4, 5, 6 };

        EXPECT_EQ( list2.size(), 3 );
        EXPECT_EQ( list2.at( 0 ), 4 );
        EXPECT_EQ( list2.at( 1 ), 5 );
        EXPECT_EQ( list2.at( 2 ), 6 );
    	
        list2 = std::move( list1 );

        // list1 = invalid state

        EXPECT_EQ( list1.size(), 0 ); // NOLINT(bugprone-use-after-move, hicpp-invalid-access-moved)

        EXPECT_EQ( list2.size(), 3 );
        EXPECT_EQ( list2.at( 0 ), 1 );
        EXPECT_EQ( list2.at( 1 ), 2 );
        EXPECT_EQ( list2.at( 2 ), 3 );
    }

    TEST_F( linked_list_tests, move_constructor )
    {
        auto list1 = int_list{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( list1.size(), 5 );
    	
        EXPECT_EQ( list1.at( 0 ), 1 );
        EXPECT_EQ( list1.at( 1 ), 2 );
        EXPECT_EQ( list1.at( 2 ), 3 );
        EXPECT_EQ( list1.at( 3 ), 4 );
        EXPECT_EQ( list1.at( 4 ), 5 );
    	
        auto list2 = std::move( list1 );

        // list1 = invalid state

        EXPECT_EQ( list1.size(), 0 );  // NOLINT(bugprone-use-after-move, hicpp-invalid-access-moved)

        EXPECT_EQ( list2.size(), 5 );
    	
        EXPECT_EQ( list2.at( 0 ), 1 );
        EXPECT_EQ( list2.at( 1 ), 2 );
        EXPECT_EQ( list2.at( 2 ), 3 );
        EXPECT_EQ( list2.at( 3 ), 4 );
        EXPECT_EQ( list2.at( 4 ), 5 );
    }

    TEST_F( linked_list_tests, move_constructor_copy )
    {
        auto outer = int_list();

        {
            auto inner = int_list{ 1, 2, 3, 4, 5 };

            EXPECT_EQ( inner.size(), 5 );
        	
            EXPECT_EQ( inner.at( 0 ), 1 );
            EXPECT_EQ( inner.at( 1 ), 2 );
            EXPECT_EQ( inner.at( 2 ), 3 );
            EXPECT_EQ( inner.at( 3 ), 4 );
            EXPECT_EQ( inner.at( 4 ), 5 );
        	
            outer = std::move( inner );
        }

        EXPECT_EQ( outer.size(), 5 );
        EXPECT_EQ( outer.at( 0 ), 1 );
        EXPECT_EQ( outer.at( 1 ), 2 );
        EXPECT_EQ( outer.at( 2 ), 3 );
        EXPECT_EQ( outer.at( 3 ), 4 );
        EXPECT_EQ( outer.at( 4 ), 5 );
    }
	
    TEST_F( linked_list_tests, empty_insert_delete )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_back( 1 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 1 );

        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 0 );
    }

    TEST_F( linked_list_tests, remove_single )
    {
        auto list = int_list{ 1 };

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 1 );

        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 0 );
    }

    TEST_F( linked_list_tests, remove_head_double )
    {
        auto list = int_list{ 1, 2 };

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 2 );

        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front(), 2 );
        EXPECT_EQ( list.back(), 2 );
    }

    TEST_F( linked_list_tests, remove_tail_double )
    {
        auto list = int_list{ 1, 2 };

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 2 );

        list.remove_at( 1 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 1 );
    }

    TEST_F( linked_list_tests, remove_head_triple )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );

        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.at( 0 ), 2 );
        EXPECT_EQ( list.at( 1 ), 3 );
    }

    TEST_F( linked_list_tests, remove_past_end )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );

        try
        {
            list.remove_at( 3 );
            FAIL() << "This should throw an error.";
        }
        catch( std::runtime_error& e )
        {
            EXPECT_EQ( std::string( e.what() ), "REMOVE_PAST_END_ATTEMPT" );
        }
    	
        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );
    }
	
    TEST_F( linked_list_tests, remove_tail_triple )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );

        list.remove_at( 2 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.back(), 2 );
    }

    TEST_F( linked_list_tests, remove_middle )
    {
        auto list = int_list{ 1, 2, 3, 4, 5, 6 };
    	
        EXPECT_EQ( list.size(), 6 );

        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );
        EXPECT_EQ( list.at( 3 ), 4 );
        EXPECT_EQ( list.at( 4 ), 5 );
        EXPECT_EQ( list.at( 5 ), 6 );

        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 6 );
    	
        list.remove_at( 4 );

        EXPECT_EQ( list.size(), 5 );
    	
        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );
        EXPECT_EQ( list.at( 3 ), 4 );
        EXPECT_EQ( list.at( 4 ), 6 );

        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 6 );
    	
        list.remove_at( 3 );

        EXPECT_EQ( list.size(), 4 );
    	
        EXPECT_EQ( list.at( 0 ), 1 );
        EXPECT_EQ( list.at( 1 ), 2 );
        EXPECT_EQ( list.at( 2 ), 3 );
        EXPECT_EQ( list.at( 3 ), 6 );

        EXPECT_EQ( list.front(), 1 );
        EXPECT_EQ( list.back(), 6 );
    	
        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 3 );
    	
        EXPECT_EQ( list.at( 0 ), 2 );
        EXPECT_EQ( list.at( 1 ), 3 );
        EXPECT_EQ( list.at( 2 ), 6 );

        EXPECT_EQ( list.front(), 2 );
        EXPECT_EQ( list.back(), 6 );
    	
        list.remove_at( 2 );

        EXPECT_EQ( list.size(), 2 );
    	
        EXPECT_EQ( list.at( 0 ), 2 );
        EXPECT_EQ( list.at( 1 ), 3 );

        EXPECT_EQ( list.front(), 2 );
        EXPECT_EQ( list.back(), 3 );
    	
        list.remove_at( 1 );

        EXPECT_EQ( list.size(), 1 );
    	
        EXPECT_EQ( list.at( 0 ), 2 );

        EXPECT_EQ( list.front(), 2 );
        EXPECT_EQ( list.back(), 2 );

        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 0 );

        EXPECT_EQ( list.front(), 0 );
        EXPECT_EQ( list.back(), 0 );
    }

    TEST_F( linked_list_tests, pop_front_empty )
    {
        auto list = int_list{};

        try
        {
            list.pop_back();
            FAIL() << "This should throw an error.";
        }
        catch( std::runtime_error& e )
        {
            EXPECT_EQ( std::string( e.what() ), "ATTEMPT_POP_EMPTY_LIST" );
        }
    }

    TEST_F( linked_list_tests, pop_back_empty )
    {
        auto list = int_list{};

        try
        {
            list.pop_back();
            FAIL() << "This should throw an error.";
        }
        catch( std::runtime_error& e )
        {
            EXPECT_EQ( std::string( e.what() ), "ATTEMPT_POP_EMPTY_LIST" );
        }
    }

    TEST_F( linked_list_tests, pop_front )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.pop_front(), 1 );
    	
        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.pop_front(), 2 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.pop_front(), 3 );

        EXPECT_EQ( list.size(), 0 );
        EXPECT_TRUE( list.empty() );
    }

    TEST_F( linked_list_tests, pop_back )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.pop_back(), 3 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.pop_back(), 2 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.pop_back(), 1 );

        EXPECT_EQ( list.size(), 0 );
        EXPECT_TRUE( list.empty() );
    }

    TEST_F( linked_list_tests, pop_alt )
    {
        auto list = int_list{ 1, 2, 3, 4, 5 };

        EXPECT_FALSE( list.empty() );
        EXPECT_EQ( list.size(), 5 );
        EXPECT_EQ( list.pop_front(), 1 );

        EXPECT_EQ( list.size(), 4 );
        EXPECT_EQ( list.pop_back(), 5 );

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.pop_front(), 2 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.pop_back(), 4 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.pop_front(), 3 );

        EXPECT_EQ( list.size(), 0 );
        EXPECT_TRUE( list.empty() );
    }

    TEST_F( linked_list_tests, find_element )
    {
        auto list = int_list{ 1, 2, 3, 4, 5 };

        const auto to_find = 3;
    	
        auto actual = std::find_if(list.begin(), list.end(),
			[&]( const auto& value ) { return value == to_find; });

        EXPECT_TRUE( actual != std::end( list ) );
        EXPECT_EQ( *actual, to_find );
    }

    TEST_F( linked_list_tests, no_find_element )
    {
        auto list = int_list{ 1, 2, 3, 4, 5 };

        const auto to_find = 6;

        auto actual = std::find_if( list.begin(), list.end(),
            [&]( const auto& value ) { return value == to_find; } );

        EXPECT_TRUE( actual == std::end( list ) );
        EXPECT_EQ( *actual, int() );
    }

    TEST_F( linked_list_tests, iterator )
    {
        auto list = int_list{ 0, 1, 2, 3, 4, 5 };

        auto expected = 0;

        for( const auto& value : list )
        {
            auto actual = value;

            EXPECT_EQ( actual, expected );

            expected++;
        }
    }

    TEST_F( linked_list_tests, add_lists )
    {
        auto list1 = int_list{ 0, 1, 2, 3, 4 };
        const auto list2 = int_list{ 5, 6, 7, 8, 9 };

        list1 = list1 + list2;

        auto expected = 0;

        for( const auto& value: list1 )
        {
            EXPECT_EQ( value, expected );

            expected++;
        }
    }

    TEST_F( linked_list_tests, reverse_iterator )
    {
        auto list = int_list{ 1, 2, 3, 4, 5 };

        auto expected = 5;
    	
    	for( auto it = list.rbegin(); it != list.rend(); --it )
    	{
            const auto actual = *it;

            EXPECT_EQ( actual, expected );

            expected--;
    	}
    }

	TEST_F( linked_list_tests, to_string1 )
    {
        auto list = int_list{ 1, 2, 3, 4, 5 };

        auto actual = list.to_string();

        const auto expected = "1 -> 2 -> 3 -> 4 -> 5";

        EXPECT_EQ( actual, expected );
    }
}