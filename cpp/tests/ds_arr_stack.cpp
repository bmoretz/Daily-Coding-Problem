#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/arr_stack.h"

namespace data_structure_tests::arr_stack_tests
{
    using namespace data_structures::arr_stack;

    /// <summary>
    /// Testing class for stack.
    /// </summary>
    class arr_stack_tests :
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
    // stack tests
    //

    TEST_F( arr_stack_tests, pop_empty )
    {
        ASSERT_ANY_THROW( stack<int>().pop() );
    }

    TEST_F( arr_stack_tests, push )
    {
        auto s = stack<int>();

    	for( auto val : { 1, 2, 3, 4, 5 } )
    	{
            s.push( val );
    	}
		
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
    }

    TEST_F( arr_stack_tests, init_list )
    {
        auto s = stack<int>( { 1, 2, 3, 4, 5 } );

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
    }
	
    TEST_F( arr_stack_tests, copy_ctor )
    {
        const auto s1 = stack<int>( { 1, 2, 3, 4, 5 } );

        auto s2 = s1;

        auto actual = std::vector<int>();
    	
    	while( !s2.empty() )
    	{
            actual.push_back( s2.top() );
            s2.pop();
    	}

    	const auto expected = std::vector<int>( { 5, 4, 3, 2, 1 } );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( arr_stack_tests, self_assignment )
    {
        auto s1 = stack<int>( { 1, 2, 3, 4, 5 } );

        const auto s2 = &s1;

        s1 = *s2;

        EXPECT_TRUE( &s1 == s2 );
    }
}