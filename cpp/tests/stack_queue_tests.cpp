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
}