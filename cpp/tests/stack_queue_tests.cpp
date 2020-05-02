#include "pch.h"
#include <gtest/gtest.h>

#include "../problems/stack_queue.h"

using namespace stack_queue_problems;

namespace stack_queue_tests
{
    /// <summary>
    /// Testing class for min stack.
    /// </summary>
    class min_stack_tests :
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
    // Min Stack 1
    //

    TEST_F( min_stack_tests, min_stack1_empty )
    {
        auto stack = min_stack<int>{ };

        auto actual = std::vector<int>{};

        while( !stack.empty() )
        {
            actual.push_back( stack.min() );

            const auto prev = stack.pop();
        }

        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }
	
    TEST_F( min_stack_tests, min_stack1_case1 )
    {
	    auto stack = min_stack<int>{ 2, 5, 1, 7, 8 };

        auto actual = std::vector<int>{};

    	while( !stack.empty() )
    	{
            actual.push_back( stack.min() );

            const auto prev = stack.pop();
    	}
    	
        const auto expected = std::vector<int>{ 2, 2, 1, 1, 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_stack_tests, min_stack1_case2 )
    {
        auto stack = min_stack<int>{ 9, 3, 1, 2, 3, 1 };

        auto actual = std::vector<int>{};

        while( !stack.empty() )
        {
            actual.push_back( stack.min() );

            const auto prev = stack.pop();
        }

        const auto expected = std::vector<int>{ 9, 3, 1, 1, 1, 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_stack_tests, min_stack1_case3 )
    {
        auto stack = min_stack<int>{ 5, 4, 3, 2, 1 };

        auto actual = std::vector<int>{};

        while( !stack.empty() )
        {
            actual.push_back( stack.min() );

            const auto prev = stack.pop();
        }

        const auto expected = std::vector<int>{ 5, 4, 3, 2, 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_stack_tests, min_stack1_case4 )
    {
        auto stack = min_stack<int>{ 5, 5, 5, 5, 5 };

        auto actual = std::vector<int>{};

        while( !stack.empty() )
        {
            actual.push_back( stack.min() );

            const auto prev = stack.pop();
        }

        const auto expected = std::vector<int>{ 5, 5, 5, 5, 5 };

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for stack of plates.
    /// </summary>
    class stack_of_plates_tests :
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
    // Stack of Plates 1
    //

    TEST_F( stack_of_plates_tests, stack_of_plates1_empty )
    {
        auto stack = stack_of_stacks1<int>{ { }, 3 };

        auto actual = std::vector<int>{};

        while( !stack.empty() )
            actual.push_back( stack.pop() );
    	
        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( stack_of_plates_tests, stack_of_plates1_case1 )
    {
        auto stack = stack_of_stacks1<int>{ { 5, 8, 9 }, 3 };

        auto actual = std::vector<int>{ };

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{ 9, 8, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( stack_of_plates_tests, stack_of_plates1_case2 )
    {
        auto stack = stack_of_stacks1<int>{
	        {
		        5, 8, 9,
	        	12, 15, 18,
	        	20, 22, 23
	        }, 3 };

        auto actual = std::vector<int>{ };

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{
        	9, 12, 15,
        	18, 20, 22,
        	23, 8, 5
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( stack_of_plates_tests, stack_of_plates1_case3 )
    {
        auto stack = stack_of_stacks1<int>{
            {
                5, 8, 9,
                12, 15, 18,
                20, 22, 23
            }, 3 };

        auto actual = std::vector<int>{ };

        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 1 ) );

        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 1 ) );

        actual.push_back( stack.pop() );
        actual.push_back( stack.pop() );
        actual.push_back( stack.pop() );

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{
            18, 20, 22,
        	23, 15, 12,
        	9, 8, 5
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( stack_of_plates_tests, stack_of_plates1_case4 )
    {
        auto stack = stack_of_stacks1<int>{
            {
                5, 8, 9,
                12, 15, 18,
                20, 22, 23
            }, 3 };

        auto actual = std::vector<int>{ };

        actual.push_back( stack.pop_at( 2 ) );
        actual.push_back( stack.pop_at( 2 ) );
        actual.push_back( stack.pop_at( 2 ) );

        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 1 ) );

        actual.push_back( stack.pop() );
        actual.push_back( stack.pop() );
        actual.push_back( stack.pop() );

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{
            23, 22, 20,
            18, 15, 12,
            9, 8, 5
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( stack_of_plates_tests, stack_of_plates1_case5 )
    {
        auto stack = stack_of_stacks1<int>{
            {
                5, 8, 9,
                12, 15, 18,
                20, 22, 23
            }, 3 };

        auto actual = std::vector<int>{ };

        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 2 ) );
        actual.push_back( stack.pop_at( 0 ) );

        actual.push_back( stack.pop_at( 0 ) );
        actual.push_back( stack.pop_at( 1 ) );
        actual.push_back( stack.pop_at( 0 ) );

        actual.push_back( stack.pop() );
        actual.push_back( stack.pop() );
        actual.push_back( stack.pop() );

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{
            18, 23, 9,
        	12, 22, 15,
        	20, 8, 5
        };

        EXPECT_EQ( actual, expected );
    }
}