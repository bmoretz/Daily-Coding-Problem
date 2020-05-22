#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/heap.h"

namespace data_structure_tests::heap_tests
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
        	
            EXPECT_EQ( my_heap.top(), min );
        	
            ++size;
        }
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