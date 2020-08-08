#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/hashtable.h"

namespace leetcode::hashtable::tests
{
    class lru_cache_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( lru_cache_tests, case1 )
    {
        auto cache = lru_cache<int, int>( 2 );

        cache.put( 1, 1 );
        cache.put( 2, 2 );

        EXPECT_EQ( cache.get( 1 ), 1 );
        cache.put( 3, 3 ); // evicts key 2
        EXPECT_EQ( cache.get( 2 ), -1 );
    	
    	cache.put( 4, 4 ); // evicts key 1

        EXPECT_EQ( cache.get( 1 ), -1 );
        EXPECT_EQ( cache.get( 3 ), 3 );
        EXPECT_EQ( cache.get( 4 ), 4 );
    }

    TEST_F( lru_cache_tests, case2 )
    {
        auto cache = lru_cache<int, int>( 2 );

        cache.put( 2, 1 );
        cache.put( 2, 2 );

        EXPECT_EQ( cache.get( 2 ), 2 );
    	
        cache.put( 1, 1 );
        cache.put( 4, 1 );
    	
        EXPECT_EQ( cache.get( 2 ), -1 );
    }

    TEST_F( lru_cache_tests, case3 )
    {
        auto cache = lru_cache<int, int>( 2 );

        cache.put( 2, 1 );

        EXPECT_EQ( cache.get( 2 ), 1 );
    	
        cache.put( 2, 2 );

        EXPECT_EQ( cache.get( 3 ), -1 );
        EXPECT_EQ( cache.get( 2 ), 2 );
    	
        cache.put( 1, 1 );
        cache.put( 4, 1 );

        EXPECT_EQ( cache.get( 2 ), -1 );
    }

    class element_with_most_appearances_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( element_with_most_appearances_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 2, 2, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case3 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case4 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 3, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case5 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 2, 3, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }
}