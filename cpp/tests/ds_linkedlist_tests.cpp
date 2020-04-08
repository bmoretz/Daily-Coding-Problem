#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/linked_list.h"

namespace data_structure_tests
{
    namespace integer_linked_list_tests
    {
        typedef data_structures::linked_list<int> int_list;

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

        TEST_F( linked_lists_tests, push_back )
        {
            auto list = int_list{ };

            EXPECT_EQ( list.front(), nullptr );
            EXPECT_EQ( list.back(), nullptr );
            EXPECT_EQ( list.size(), 0 );

            list.push_back( 5 );

            EXPECT_EQ( list.size(), 1 );
            EXPECT_EQ( list.front(), list.back() );
            EXPECT_EQ( list.front()->data, 5 );

            list.push_back( 4 );

            EXPECT_EQ( list.size(), 2 );
            EXPECT_NE( list.front(), list.back() );
            EXPECT_EQ( list.front()->next.get(), list.back() );
            EXPECT_EQ( list.front()->data, 5 );
            EXPECT_EQ( list.front()->next->data, 4 );
            EXPECT_EQ( list.back()->data, 4 );

            list.push_back( 3 );

            EXPECT_EQ( list.size(), 3 );
            EXPECT_EQ( list.front()->data, 5 );
            EXPECT_EQ( list.front()->next->data, 4 );
            EXPECT_EQ( list.front()->next->next->data, 3 );
            EXPECT_EQ( list.back()->data, 3 );

            list.push_back( 2 );

            EXPECT_EQ( list.size(), 4 );
            EXPECT_EQ( list.front()->data, 5 );
            EXPECT_EQ( list.front()->next->data, 4 );
            EXPECT_EQ( list.front()->next->next->data, 3 );
            EXPECT_EQ( list.front()->next->next->next->data, 2 );
            EXPECT_EQ( list.back()->data, 2 );

            list.push_back( 1 );

            EXPECT_EQ( list.size(), 5 );
            EXPECT_EQ( list.front()->data, 5 );
            EXPECT_EQ( list.front()->next->data, 4 );
            EXPECT_EQ( list.front()->next->next->data, 3 );
            EXPECT_EQ( list.front()->next->next->next->data, 2 );
            EXPECT_EQ( list.front()->next->next->next->next->data, 1 );

            EXPECT_EQ( list.back()->data, 1 );
        }

        TEST_F( linked_lists_tests, push_front )
        {
            auto list = int_list{ };

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
            const auto list = int_list{ 5, 4, 3, 2, 1 };

            EXPECT_EQ( list.front()->data, 5 );
            EXPECT_EQ( list.front()->next->data, 4 );
            EXPECT_EQ( list.front()->next->next->data, 3 );
            EXPECT_EQ( list.front()->next->next->next->data, 2 );
            EXPECT_EQ( list.front()->next->next->next->next->data, 1 );

            EXPECT_EQ( list.back()->data, 1 );
        }

        TEST_F( linked_lists_tests, iterator )
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

        TEST_F( linked_lists_tests, add_lists )
        {
            auto list1 = int_list{ 0, 1, 2, 3, 4 };
            const auto list2 = int_list{ 5, 6, 7, 8, 9 };

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
            auto list = int_list{ 0, 1, 2 };

            EXPECT_EQ( list.front()->data, 0 );
            EXPECT_EQ( list.front()->next->data, 1 );
            EXPECT_EQ( list.front()->next->next->data, 2 );

            list += 3;

            EXPECT_EQ( list.back()->data, 3 );
        }

        TEST_F( linked_lists_tests, copy_constructor )
        {
            auto list = int_list{ 0, 1, 2 };

            EXPECT_EQ( list.size(), 3 );
            EXPECT_EQ( list.front()->data, 0 );
            EXPECT_EQ( list.front()->next->data, 1 );
            EXPECT_EQ( list.front()->next->next->data, 2 );

            auto list_copy( list );

            EXPECT_EQ( list_copy.size(), 3 );
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

        TEST_F( linked_lists_tests, swap )
        {
            auto list1 = int_list{ 1, 2, 3 };
            auto list2 = int_list{ 4, 5, 6 };

            EXPECT_EQ( list1.size(), 3 );
            EXPECT_EQ( list2.size(), 3 );

            list1.swap( list2 );

            EXPECT_EQ( list1.front()->data, 4 );
            EXPECT_EQ( list1.front()->next->data, 5 );
            EXPECT_EQ( list1.front()->next->next->data, 6 );

            EXPECT_EQ( list2.front()->data, 1 );
            EXPECT_EQ( list2.front()->next->data, 2 );
            EXPECT_EQ( list2.front()->next->next->data, 3 );
        }

        TEST_F( linked_lists_tests, copy_assignment_equal )
        {
            auto list1 = int_list{ 1, 2, 3 };

            EXPECT_EQ( list1.size(), 3 );
            EXPECT_EQ( list1.front()->data, 1 );
            EXPECT_EQ( list1.front()->next->data, 2 );
            EXPECT_EQ( list1.front()->next->next->data, 3 );
        	
            auto list2 = int_list{ };

            EXPECT_EQ( list2.size(), 0 );
        	
            list2 = list1;
        	
            EXPECT_EQ( list1.size(), 3 );
            EXPECT_EQ( list1.front()->data, 1 );
            EXPECT_EQ( list1.front()->next->data, 2 );
            EXPECT_EQ( list1.front()->next->next->data, 3 );

            EXPECT_EQ( list2.size(), 3 );
            EXPECT_EQ( list2.front()->data, 1 );
            EXPECT_EQ( list2.front()->next->data, 2 );
            EXPECT_EQ( list2.front()->next->next->data, 3 );

            EXPECT_NE( list1.front(), list2.front() );
            EXPECT_NE( list1.front()->next, list2.front()->next );
            EXPECT_NE( list1.front()->next->next, list2.front()->next->next );
            EXPECT_NE( list1.back(), list2.back() );
        }

        TEST_F( linked_lists_tests, move_assignment_operator )
        {
            auto list1 = int_list{ 1, 2, 3 };

            EXPECT_EQ( list1.size(), 3 );
            EXPECT_EQ( list1.front()->data, 1 );
            EXPECT_EQ( list1.front()->next->data, 2 );
            EXPECT_EQ( list1.front()->next->next->data, 3 );

            auto list2 = std::move( list1 );

            EXPECT_NE( list1.front(), list2.front() );  // NOLINT(bugprone-use-after-move, hicpp-invalid-access-moved)

            EXPECT_EQ( list1.size(), 0 );
            EXPECT_EQ( list1.front(), nullptr );
            EXPECT_EQ( list1.back(), nullptr );

            EXPECT_EQ( list2.size(), 3 );
            EXPECT_EQ( list2.front()->data, 1 );
            EXPECT_EQ( list2.front()->next->data, 2 );
            EXPECT_EQ( list2.front()->next->next->data, 3 );
        }

        TEST_F( linked_lists_tests, move_constructor )
        {
            auto list1 = int_list{ 1, 2, 3 };

            EXPECT_EQ( list1.size(), 3 );
            EXPECT_EQ( list1.front()->data, 1 );
            EXPECT_EQ( list1.front()->next->data, 2 );
            EXPECT_EQ( list1.front()->next->next->data, 3 );

            auto list2 = std::move( list1 );

            EXPECT_EQ( list1.size(), 0 );  // NOLINT(bugprone-use-after-move, hicpp-invalid-access-moved)
            EXPECT_EQ( list1.front(), nullptr ); // NOLINT(bugprone-use-after-move)
            EXPECT_EQ( list1.back(), nullptr ); // NOLINT(bugprone-use-after-move)

            EXPECT_EQ( list2.size(), 3 );
            EXPECT_EQ( list2.front()->data, 1 );
            EXPECT_EQ( list2.front()->next->data, 2 );
            EXPECT_EQ( list2.front()->next->next->data, 3 );
        }

        TEST_F( linked_lists_tests, insert_head )
        {
            auto list = int_list{ 1, 2, 3 };

            EXPECT_EQ( list.front()->data, 1 );

            list.insert( 0, 4 );

            EXPECT_EQ( list.front()->data, 4 );
            EXPECT_EQ( list.front()->next->data, 1 );
            EXPECT_EQ( list.front()->next->next->data, 2 );
            EXPECT_EQ( list.front()->next->next->next->data, 3 );
        }

        TEST_F( linked_lists_tests, insert_tail )
        {
            auto list = int_list{ 1, 2, 3 };

            EXPECT_EQ( list.front()->data, 1 );

            list.insert( 3, 4 );

            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.front()->next->data, 2 );
            EXPECT_EQ( list.front()->next->next->data, 3 );
            EXPECT_EQ( list.front()->next->next->next->data, 4 );
            EXPECT_EQ( list.back()->data, 4 );
        }

        TEST_F( linked_lists_tests, insert_empty )
        {
            auto list = int_list{ };

            EXPECT_EQ( list.size(), 0 );
            EXPECT_EQ( list.front(), nullptr );
            EXPECT_EQ( list.back(), nullptr );

            list.push_back( 1 );

            EXPECT_EQ( list.size(), 1 );
            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.back()->data, 1 );
        }

        TEST_F( linked_lists_tests, insert_empty_delete )
        {
            auto list = int_list{ };

            EXPECT_EQ( list.size(), 0 );
            EXPECT_EQ( list.front(), nullptr );
            EXPECT_EQ( list.back(), nullptr );

            list.push_back( 1 );

            EXPECT_EQ( list.size(), 1 );
            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.back()->data, 1 );

            list.remove( 0 );

            EXPECT_EQ( list.size(), 0 );
            EXPECT_EQ( list.front(), nullptr );
            EXPECT_EQ( list.back(), nullptr );
        }
    	
        TEST_F( linked_lists_tests, insert_invalid )
        {
            auto list = int_list{ 1, 2, 3 };

            EXPECT_EQ( list.front()->data, 1 );

            try
            {
                list.insert( 5, 4 );
                FAIL() << "This should throw an error.";
            }
            catch( std::runtime_error& e )
            {
                EXPECT_EQ( std::string( e.what() ), "invalid_list_position" );
            }

            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.front()->next->data, 2 );
            EXPECT_EQ( list.front()->next->next->data, 3 );
        }

        TEST_F( linked_lists_tests, remove_invalid )
        {
            auto list = int_list{ 1, 2, 3 };

            EXPECT_EQ( list.front()->data, 1 );

            try
            {
                list.remove( 5 );
                FAIL() << "This should throw an error.";
            }
            catch( std::runtime_error& e )
            {
                EXPECT_EQ( std::string( e.what() ), "invalid_list_position" );
            }

            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.front()->next->data, 2 );
            EXPECT_EQ( list.front()->next->next->data, 3 );
        }
    	
        TEST_F( linked_lists_tests, remove_head_single )
        {
            auto list = int_list{ 1 };

            EXPECT_EQ( list.size(), 1 );
            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.back()->data, 1 );

            list.remove( 0 );

            EXPECT_EQ( list.size(), 0 );
            EXPECT_EQ( list.front(), nullptr );
            EXPECT_EQ( list.back(), nullptr );
        }

        TEST_F( linked_lists_tests, delete_head_double )
        {
            auto list = int_list{ 1, 2 };

            EXPECT_EQ( list.size(), 2 );
            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.front()->next->data, 2 );

            list.remove( 0 );

            EXPECT_EQ( list.size(), 1 );
            EXPECT_EQ( list.front(), list.back() );
            EXPECT_EQ( list.front()->data, 2 );
            EXPECT_EQ( list.back()->data, 2 );
        }

        TEST_F( linked_lists_tests, delete_head_tripple )
        {
            auto list = int_list{ 1, 2, 3 };

            EXPECT_EQ( list.size(), 3 );
            EXPECT_EQ( list.front()->data, 1 );
            EXPECT_EQ( list.front()->next->data, 2 );
            EXPECT_EQ( list.front()->next->next->data, 3 );

            list.remove( 0 );

            EXPECT_EQ( list.size(), 2 );
            EXPECT_EQ( list.front()->data, 2 );
            EXPECT_EQ( list.front()->next->data, 3 );
            EXPECT_EQ( list.back()->data, 3 );
        }
    }
}