#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/heap.h"

namespace data_structure::heap_tests
{
    using namespace data_structures::heap;

    /// <summary>
    /// Testing class for heap.
    /// </summary>
    class heap_tests :
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
    // heap tests
    //

    TEST_F( heap_tests, pop_empty )
    {
        ASSERT_ANY_THROW( heap<int>().pop() );
    }

    TEST_F( heap_tests, push_increasing )
    {
        auto my_heap = heap<int>();

        const auto values
    		= std::vector{ 5, 4, 3, 2, 1 };

    	auto min = values.front(),
    		size = 0;
    	
        for( auto val : values )
        {
            EXPECT_EQ( my_heap.size(), size );
        	
            my_heap.push( val );

            min = std::min( min, val );
        	
            EXPECT_EQ( my_heap.peek(), min );
        	
            ++size;
        }
    }

	TEST_F( heap_tests, pop_single )
    {
        auto my_heap = heap<int>();

        EXPECT_TRUE( my_heap.empty() );
        EXPECT_EQ( my_heap.size(), 0 );
    	
        my_heap.push( 4 );

        EXPECT_EQ( my_heap.size(), 1 );
    	
        const auto actual = my_heap.pop();
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( heap_tests, pop_double )
    {
        auto my_heap = heap<int>();

        EXPECT_TRUE( my_heap.empty() );
        EXPECT_EQ( my_heap.size(), 0 );

        my_heap.push( 4 );
        my_heap.push( 5 );
    	
        EXPECT_EQ( my_heap.size(), 2 );

        EXPECT_EQ( my_heap.pop(), 4 );
        EXPECT_EQ( my_heap.pop(), 5 );
    }

    TEST_F( heap_tests, pop_triple )
    {
        auto my_heap = heap<int>();

        EXPECT_TRUE( my_heap.empty() );
        EXPECT_EQ( my_heap.size(), 0 );

        my_heap.push( 4 );
        my_heap.push( 5 );
        my_heap.push( 6 );
    	
        EXPECT_EQ( my_heap.size(), 3 );

        auto actual = std::vector<int>();

    	while( !my_heap.empty() )
    	{
            actual.push_back( my_heap.pop() );
    	}
    	
        const auto expected = std::vector<int>{ 4, 5, 6 };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( heap_tests, pop_n )
    {
        auto my_heap = heap<int>();

        EXPECT_TRUE( my_heap.empty() );
        EXPECT_EQ( my_heap.size(), 0 );

        auto values = std::vector<int>{
			2, 3, 6, 1, 4, 8, 0, 2, 9, 7
        };

        auto min = INT_MAX;
    	
        for( auto item : values )
        {
            my_heap.push( item );
        	
            min = std::min( item, min );

            EXPECT_EQ( my_heap.peek(), min );
        }
    	
        EXPECT_EQ( my_heap.size(), 10 );
        
        auto actual = std::vector<int>();

        while( !my_heap.empty() )
        {
            actual.push_back( my_heap.pop() );
        }

        std::sort( values.begin(), values.end() );

        EXPECT_EQ( actual, values );
    }
	
    TEST_F( heap_tests, init_list )
    {
    	/*
        auto s = heap<int>( { 1, 2, 3, 4, 5 } );

        auto actual = std::vector<int>();

        EXPECT_EQ( s.size(), 5 );

        while( !s.empty() )
        {
            actual.push_back( s.top() );
            s.pop();
        }

        EXPECT_EQ( s.size(), 0 );

        const auto expected = std::vector<int>( { 5, 4, 3, 2, 1 } );

        EXPECT_EQ( actual, expected );
        */
    }

    TEST_F( heap_tests, copy_ctor )
    {
    	/*
        const auto s1 = heap<int>( { 1, 2, 3, 4, 5 } );

        auto s2 = s1;

        auto actual = std::vector<int>();

        while( !s2.empty() )
        {
            actual.push_back( s2.top() );
            s2.pop();
        }

        const auto expected = std::vector<int>( { 5, 4, 3, 2, 1 } );

        EXPECT_EQ( actual, expected );
        */
    }

    TEST_F( heap_tests, self_assignment )
    {
    	/*
        auto s1 = heap<int>( { 1, 2, 3, 4, 5 } );

        const auto s2 = &s1;

        s1 = *s2;

        EXPECT_TRUE( &s1 == s2 );
        */
    }
}