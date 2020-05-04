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

    /// <summary>
    /// Testing class for my_queue.
    /// </summary>
    class my_queue_tests :
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
    // My Queue 1
    //

    TEST_F( my_queue_tests, my_queue1_empty )
    {
        auto queue = my_queue<int>{ };

        auto actual = std::vector<int>{};

        while( !queue.empty() )
            actual.push_back( queue.dequeue() );

        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( my_queue_tests, my_queue1_case1 )
    {
        auto queue = my_queue<int>{ 1, 2, 3, 4, 5 };

        auto actual = std::vector<int>{};

        while( !queue.empty() )
            actual.push_back( queue.dequeue() );

        const auto expected = std::vector<int>{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( my_queue_tests, my_queue1_case2 )
    {
        auto queue = my_queue<int>{ 1, 2, 3 };

        EXPECT_EQ( queue.dequeue(), 1 );
        EXPECT_EQ( queue.dequeue(), 2 );
        EXPECT_EQ( queue.dequeue(), 3 );
    }

    TEST_F( my_queue_tests, my_queue1_case3 )
    {
        auto queue = my_queue<int>{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( queue.dequeue(), 1 );
        EXPECT_EQ( queue.dequeue(), 2 );

        queue.enqueue( 6 );
        queue.enqueue( 7 );
    	
        auto actual = std::vector<int>{};

        while( !queue.empty() )
            actual.push_back( queue.dequeue() );

        const auto expected = std::vector<int>{ 3, 4, 5, 6, 7 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( my_queue_tests, my_queue1_case4 )
    {
        auto queue = my_queue<int>{ 5, 4, 3, 2, 1 };

        EXPECT_EQ( queue.dequeue(), 5 );
        EXPECT_EQ( queue.dequeue(), 4 );

        queue.enqueue( 6 );
        queue.enqueue( 7 );

        auto actual = std::vector<int>{};

        while( !queue.empty() )
            actual.push_back( queue.dequeue() );

        const auto expected = std::vector<int>{ 3, 2, 1, 6, 7 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( my_queue_tests, my_queue1_case5 )
    {
        auto queue = my_queue<int>{ 5, 4, 3, 2, 1 };

        EXPECT_EQ( queue.dequeue(), 5 );
        EXPECT_EQ( queue.dequeue(), 4 );

        queue.enqueue( 6 );
        queue.enqueue( 7 );

        EXPECT_EQ( queue.dequeue(), 3 );
    	
        auto actual = std::vector<int>{};

        while( !queue.empty() )
            actual.push_back( queue.dequeue() );

        const auto expected = std::vector<int>{ 2, 1, 6, 7 };

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for sort stack.
    /// </summary>
    class sort_stack_tests :
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
    // Sort Stack 1
    //

    TEST_F( sort_stack_tests, sort_stack1_empty )
    {
        auto stack = sort_stack<int>{ };

        auto actual = std::vector<int>{};

        stack.sort1();
    	
        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_stack_tests, sort_stack1_case1 )
    {
        auto stack = sort_stack<int>{ 3, 2, 4, 7, 6 };

        auto actual = std::vector<int>{};

        stack.sort1();

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{ 7, 6, 4, 3, 2 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_stack_tests, sort_stack1_case2 )
    {
        auto stack = sort_stack<int>{ -21, 23, 31, 2, 0, 4, 1 };

        auto actual = std::vector<int>{};

        stack.sort1();

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{ 31, 23, 4, 2, 1, 0, -21 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_stack_tests, sort_stack1_case3 )
    {
        auto stack = sort_stack<int>{ -21, 23, 31, 2, 0, 4, 1, -21, 4 };

        auto actual = std::vector<int>{};

        stack.sort1();

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{ 31, 23, 4, 4, 2, 1, 0, -21, -21 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_stack_tests, sort_stack1_case4 )
    {
        auto stack = sort_stack<int>{ -21, 23, 31, 2, 0, 4, 1, -21, 4, -33 };

        auto actual = std::vector<int>{};

        stack.sort1();

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{ 31, 23, 4, 4, 2, 1, 0, -21, -21, -33 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_stack_tests, sort_stack1_case5 )
    {
        auto stack = sort_stack<int>{ -21, 23, 31, 2, 0, 4, 1, -21, 4, -33, -100, 100 };

        auto actual = std::vector<int>{};

        stack.sort1();

        while( !stack.empty() )
            actual.push_back( stack.pop() );

        const auto expected = std::vector<int>{ 100, 31, 23, 4, 4, 2, 1, 0, -21, -21, -33, -100 };

        EXPECT_EQ( actual, expected );
    }
}