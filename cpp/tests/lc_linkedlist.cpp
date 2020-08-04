#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/linkedlist.h"

namespace leetcode::linkedlist::tests
{
    class sum_two_numbers_test :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( sum_two_numbers_test, twosum_1 )
    {
        const auto l1 = add_numbers::build_list( { 9, 9, 9 } );
        const auto l2 = add_numbers::build_list( { 1 } );

        const auto result = add_numbers::add_two_numbers( l1, l2 );

        add_numbers::clean_up( l1 );
        add_numbers::clean_up( l2 );
    	
        const auto actual = add_numbers::to_vector( result );

        add_numbers::clean_up( result );
    	
        const auto expected = std::vector<int>{ 0, 0, 0, 1 };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( sum_two_numbers_test, twosum_2 )
    {
        const auto l1 = add_numbers::build_list( { 2, 4, 3 } );
        const auto l2 = add_numbers::build_list( { 5, 6, 4 } );

        const auto result = add_numbers::add_two_numbers( l1, l2 );

        add_numbers::clean_up( l1 );
        add_numbers::clean_up( l2 );
    	
        const auto actual = add_numbers::to_vector( result );

        add_numbers::clean_up( result );
    	
        const auto expected = std::vector<int>{ 7, 0, 8 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sum_two_numbers_test, twosum_3 )
    {
        const auto l1 = add_numbers::build_list( { 2, 4, 3, 8 } );
        const auto l2 = add_numbers::build_list( { 5, 6, 4 } );

        const auto result = add_numbers::add_two_numbers( l1, l2 );

    	add_numbers::clean_up( l1 );
        add_numbers::clean_up( l2 );
    	
        const auto actual = add_numbers::to_vector( result );

        add_numbers::clean_up( result );
    	
        const auto expected = std::vector<int>{ 7, 0, 8, 8 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sum_two_numbers_test, twosum_4 )
    {
        const auto l1 = add_numbers::build_list( { } );
        const auto l2 = add_numbers::build_list( { 5, 6, 4 } );

        const auto result = add_numbers::add_two_numbers( l1, l2 );

        add_numbers::clean_up( l1 );
        add_numbers::clean_up( l2 );

        const auto actual = add_numbers::to_vector( result );

        add_numbers::clean_up( result );

        const auto expected = std::vector<int>{ 5, 6, 4 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sum_two_numbers_test, twosum_5 )
    {
        const auto l1 = add_numbers::build_list( { 2, 4, 3, 8 } );
        const auto l2 = add_numbers::build_list( { } );

        const auto result = add_numbers::add_two_numbers( l1, l2 );

        add_numbers::clean_up( l1 );
        add_numbers::clean_up( l2 );

        const auto actual = add_numbers::to_vector( result );

        add_numbers::clean_up( result );

        const auto expected = std::vector<int>{ 2, 4, 3, 8 };

        EXPECT_EQ( actual, expected );
    }

    class copy_list_test :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( copy_list_test, case1 )
    {
        const auto head = copy_list::make_list
        ( {
                {3, copy_list::tail_value},
                {3, 0},
                {3, copy_list::tail_value}
            } );

        const auto copy = copy_list::copy_random_list( head.get() );

        auto orig_node = head.get();
        auto copy_node = copy.get();

    	while( orig_node || copy_node )
    	{
            EXPECT_EQ( orig_node->val, copy_node->val );

    		if( orig_node->random )
				EXPECT_EQ( orig_node->random->val, orig_node->random->val );

            orig_node = orig_node->next.get();
            copy_node = copy_node->next.get();
    	}
    }

    TEST_F( copy_list_test, case2 )
    {
        const auto head = copy_list::make_list
        ( {
                {7, copy_list::tail_value},
				{13, 0},
                {11, 4},
				{10, 2},
				{1, 0}
            } );

        const auto copy = copy_list::copy_random_list( head.get() );

        auto orig_node = head.get();
        auto copy_node = copy.get();

        while( orig_node || copy_node )
        {
            EXPECT_EQ( orig_node->val, copy_node->val );

            if( orig_node->random )
                EXPECT_EQ( orig_node->random->val, orig_node->random->val );

            orig_node = orig_node->next.get();
            copy_node = copy_node->next.get();
        }
    }

    TEST_F( copy_list_test, case3 )
    {
        const auto head = copy_list::make_list
        ( {
                {1, 1},
				{2, 1}
            } );

        const auto copy = copy_list::copy_random_list( head.get() );

        auto orig_node = head.get();
        auto copy_node = copy.get();

        while( orig_node || copy_node )
        {
            EXPECT_EQ( orig_node->val, copy_node->val );

            if( orig_node->random )
                EXPECT_EQ( orig_node->random->val, orig_node->random->val );

            orig_node = orig_node->next.get();
            copy_node = copy_node->next.get();
        }
    }
}