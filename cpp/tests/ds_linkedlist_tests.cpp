#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/linked_list.h"

namespace data_structure_tests::integer_linked_list_tests
{
    typedef data_structures::linked_list<int> int_list;

    /// <summary>
    /// Testing class for singly linked list.
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

        EXPECT_EQ( actual.data, 1 );
    }

    TEST_F( linked_list_tests, at_tail )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );

        auto actual = list.at( 2 );

        EXPECT_EQ( actual.data, 3 );
    }

    TEST_F( linked_list_tests, get_head )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );

        auto actual = list.find( 1 );

        EXPECT_EQ( actual.data, 1 );
    }

    TEST_F( linked_list_tests, push_front_empty )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_back( 1 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.back().data, 1 );
    }

    TEST_F( linked_list_tests, push_back )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_back( 3 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front().data, 3 );
        EXPECT_EQ( list.back().data, 3 );

        list.push_back( 2 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front().data, 3 );
        EXPECT_EQ( list.back().data, 2 );

        list.push_back( 1 );

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.front().data, 3 );
        EXPECT_EQ( list.back().data, 1 );
    }

    TEST_F( linked_list_tests, push_front )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_front( 3 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front().data, 3 );
        EXPECT_EQ( list.back().data, 3 );

        list.push_front( 2 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front().data, 2 );
        EXPECT_EQ( list.back().data, 3 );

        list.push_front( 1 );

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.back().data, 3 );
    }

    TEST_F( linked_list_tests, init_list )
    {
        auto list = int_list{ 5, 4, 3, 2, 1 };

        EXPECT_EQ( list.size(), 5 );

        EXPECT_EQ( list.front().data, 5 );
        EXPECT_EQ( list.back().data, 1 );

        EXPECT_EQ( list.at( 4 ).data, 1 );
        EXPECT_EQ( list.at( 3 ).data, 2 );
        EXPECT_EQ( list.at( 2 ).data, 3 );
        EXPECT_EQ( list.at( 1 ).data, 4 );
        EXPECT_EQ( list.at( 0 ).data, 5 );
    }

    TEST_F( linked_list_tests, iterator )
    {
        auto list = int_list{ 0, 1, 2, 3, 4, 5 };

        auto expected = 0;

        for( const auto& node : list )
        {
            auto actual = node.data;

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

        for( const auto& node : list1 )
        {
            auto actual = node.data;

            EXPECT_EQ( actual, expected );

            expected++;
        }
    }

    TEST_F( linked_list_tests, append_value )
    {
        auto list = int_list{ 0, 1, 2 };

        EXPECT_EQ( list.size(), 3 );
    	
        list += 3;

        EXPECT_EQ( list.size(), 4 );
        EXPECT_EQ( list.back().data, 3 );

        EXPECT_EQ( list.at( 0 ).data, 0 );
        EXPECT_EQ( list.at( 1 ).data, 1 );
        EXPECT_EQ( list.at( 2 ).data, 2 );
        EXPECT_EQ( list.at( 3 ).data, 3 );
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

        EXPECT_EQ( list1.at( 0 ).data, 4 );
        EXPECT_EQ( list1.at( 1 ).data, 5 );
        EXPECT_EQ( list1.at( 2 ).data, 6 );

        EXPECT_EQ( list2.at( 0 ).data, 1 );
        EXPECT_EQ( list2.at( 1 ).data, 2 );
        EXPECT_EQ( list2.at( 2 ).data, 3 );
    }

    TEST_F( linked_list_tests, copy_constructor )
    {
        auto list = int_list{ 0, 1, 2 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ).data, 0 );
        EXPECT_EQ( list.at( 1 ).data, 1 );
        EXPECT_EQ( list.at( 2 ).data, 2 );

        auto list_copy( list );

        EXPECT_EQ( list_copy.size(), 3 );
        EXPECT_EQ( list_copy.at( 0 ).data, 0 );
        EXPECT_EQ( list_copy.at( 1 ).data, 1 );
        EXPECT_EQ( list_copy.at( 2 ).data, 2 );

        list_copy.push_back( 4 );

        EXPECT_EQ( list_copy.back().data, 4 );

        EXPECT_NE( list.back().data, list_copy.back().data );
    }
	
    TEST_F( linked_list_tests, copy_assignment_equal )
    {
        auto list1 = int_list{ 0, 1, 2 };

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ).data, 0 );
        EXPECT_EQ( list1.at( 1 ).data, 1 );
        EXPECT_EQ( list1.at( 2 ).data, 2 );
                       
        auto list2 = int_list{ 3, 4, 5 };

        EXPECT_EQ( list2.size(), 3 );

        list2 = list1;

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ).data, 0 );
        EXPECT_EQ( list1.at( 1 ).data, 1 );
        EXPECT_EQ( list1.at( 2 ).data, 2 );

        EXPECT_EQ( list2.size(), 3 );
        EXPECT_EQ( list2.at( 0 ).data, 0 );
        EXPECT_EQ( list2.at( 1 ).data, 1 );
        EXPECT_EQ( list2.at( 2 ).data, 2 );
    }

    TEST_F( linked_list_tests, self_copy )
    {
        auto list1 = int_list{ 0, 1, 2 };

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ).data, 0 );
        EXPECT_EQ( list1.at( 1 ).data, 1 );
        EXPECT_EQ( list1.at( 2 ).data, 2 );

        list1 = list1;

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ).data, 0 );
        EXPECT_EQ( list1.at( 1 ).data, 1 );
        EXPECT_EQ( list1.at( 2 ).data, 2 );
    }

    TEST_F( linked_list_tests, move_assignment_operator )
    {
        auto list1 = int_list{ 1, 2, 3 };

        EXPECT_EQ( list1.size(), 3 );
        EXPECT_EQ( list1.at( 0 ).data, 1 );
        EXPECT_EQ( list1.at( 1 ).data, 2 );
        EXPECT_EQ( list1.at( 2 ).data, 3 );

        auto list2 = int_list{ 4, 5, 6 };

        EXPECT_EQ( list2.size(), 3 );
        EXPECT_EQ( list2.at( 0 ).data, 4 );
        EXPECT_EQ( list2.at( 1 ).data, 5 );
        EXPECT_EQ( list2.at( 2 ).data, 6 );
    	
        list2 = std::move( list1 );

        // list1 = invalid state

        EXPECT_EQ( list1.size(), 0 ); // NOLINT(bugprone-use-after-move, hicpp-invalid-access-moved)

        EXPECT_EQ( list2.size(), 3 );
        EXPECT_EQ( list2.at( 0 ).data, 1 );
        EXPECT_EQ( list2.at( 1 ).data, 2 );
        EXPECT_EQ( list2.at( 2 ).data, 3 );
    }

    TEST_F( linked_list_tests, move_constructor )
    {
        auto list1 = int_list{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( list1.size(), 5 );
    	
        EXPECT_EQ( list1.at( 0 ).data, 1 );
        EXPECT_EQ( list1.at( 1 ).data, 2 );
        EXPECT_EQ( list1.at( 2 ).data, 3 );
        EXPECT_EQ( list1.at( 3 ).data, 4 );
        EXPECT_EQ( list1.at( 4 ).data, 5 );
    	
        auto list2 = std::move( list1 );

        // list1 = invalid state

        EXPECT_EQ( list1.size(), 0 );  // NOLINT(bugprone-use-after-move, hicpp-invalid-access-moved)

        EXPECT_EQ( list2.size(), 5 );
    	
        EXPECT_EQ( list2.at( 0 ).data, 1 );
        EXPECT_EQ( list2.at( 1 ).data, 2 );
        EXPECT_EQ( list2.at( 2 ).data, 3 );
        EXPECT_EQ( list2.at( 3 ).data, 4 );
        EXPECT_EQ( list2.at( 4 ).data, 5 );
    }

    TEST_F( linked_list_tests, move_constructor_copy )
    {
        auto outer = int_list();

        {
            auto inner = int_list{ 1, 2, 3, 4, 5 };

            EXPECT_EQ( inner.size(), 5 );
        	
            EXPECT_EQ( inner.at( 0 ).data, 1 );
            EXPECT_EQ( inner.at( 1 ).data, 2 );
            EXPECT_EQ( inner.at( 2 ).data, 3 );
            EXPECT_EQ( inner.at( 3 ).data, 4 );
            EXPECT_EQ( inner.at( 4 ).data, 5 );
        	
            outer = std::move( inner );
        }

        EXPECT_EQ( outer.size(), 5 );
        EXPECT_EQ( outer.at( 0 ).data, 1 );
        EXPECT_EQ( outer.at( 1 ).data, 2 );
        EXPECT_EQ( outer.at( 2 ).data, 3 );
        EXPECT_EQ( outer.at( 3 ).data, 4 );
        EXPECT_EQ( outer.at( 4 ).data, 5 );
    }

    TEST_F( linked_list_tests, large_list )
    {
        auto list = int_list{};

    	for( auto index = 0; index < 100000; index++ )
    	{
            list.push_back( index );
    	}
    	
        auto actual = list.find( 6 );

        const auto expected = *list.end();
    }
	
    TEST_F( linked_list_tests, empty_insert_delete )
    {
        auto list = int_list{ };

        EXPECT_EQ( list.size(), 0 );

        list.push_back( 1 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.back().data, 1 );

        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 0 );
    }

    TEST_F( linked_list_tests, remove_single )
    {
        auto list = int_list{ 1 };

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.back().data, 1 );

        list.remove( 1 );

        EXPECT_EQ( list.size(), 0 );
    }

    TEST_F( linked_list_tests, remove_head_double )
    {
        auto list = int_list{ 1, 2 };

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.back().data, 2 );

        list.remove( 1 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front().data, 2 );
        EXPECT_EQ( list.back().data, 2 );
    }

    TEST_F( linked_list_tests, remove_tail_double )
    {
        auto list = int_list{ 1, 2 };

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.back().data, 2 );

        list.remove( 2 );

        EXPECT_EQ( list.size(), 1 );
        EXPECT_EQ( list.front().data, 1 );
        EXPECT_EQ( list.back().data, 1 );
    }

    TEST_F( linked_list_tests, remove_head_triple )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ).data, 1 );
        EXPECT_EQ( list.at( 1 ).data, 2 );
        EXPECT_EQ( list.at( 2 ).data, 3 );

        list.remove_at( 0 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.at( 0 ).data, 2 );
        EXPECT_EQ( list.at( 1 ).data, 3 );
    }

    TEST_F( linked_list_tests, remove_tail_triple )
    {
        auto list = int_list{ 1, 2, 3 };

        EXPECT_EQ( list.size(), 3 );
        EXPECT_EQ( list.at( 0 ).data, 1 );
        EXPECT_EQ( list.at( 1 ).data, 2 );
        EXPECT_EQ( list.at( 2 ).data, 3 );

        list.remove_at( 2 );

        EXPECT_EQ( list.size(), 2 );
        EXPECT_EQ( list.at( 0 ).data, 1 );
        EXPECT_EQ( list.at( 1 ).data, 2 );
        EXPECT_EQ( list.back().data, 2 );
    }

    TEST_F( linked_list_tests, no_find )
    {
        auto list = int_list{ 1, 2, 3, 4, 5 };

        auto actual = list.find( 6 );

        const auto expected = *list.end();
    }	
}