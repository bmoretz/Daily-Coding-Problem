#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/containers.h"

namespace leetcode::containers::tests
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

    class randomized_set_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( randomized_set_tests, case1 )
    {
        auto rnd = randomized_set(100);

	    EXPECT_TRUE( rnd.insert( 1 ) );
        EXPECT_TRUE( rnd.insert( 2 ) );
    	
        EXPECT_FALSE( rnd.insert( 1 ) );
        EXPECT_FALSE( rnd.insert( 2 ) );

        EXPECT_EQ( rnd.get_random(), 1 );
    }

    TEST_F( randomized_set_tests, case2 )
    {
        auto rnd = randomized_set( 100 );

        EXPECT_TRUE( rnd.insert( 1 ) );
        EXPECT_TRUE( rnd.insert( 2 ) );
        EXPECT_TRUE( rnd.insert( 3 ) );
        EXPECT_TRUE( rnd.insert( 4 ) );
        EXPECT_TRUE( rnd.insert( 5 ) );
    	
        EXPECT_FALSE( rnd.insert( 1 ) );
        EXPECT_FALSE( rnd.insert( 2 ) );

        EXPECT_EQ( rnd.get_random(), 3 );
        EXPECT_EQ( rnd.get_random(), 5 );
        EXPECT_EQ( rnd.get_random(), 1 );
    }

    TEST_F( randomized_set_tests, case3 )
    {
        auto rnd = randomized_set( 100 );

        EXPECT_TRUE( rnd.insert( 1 ) );
        EXPECT_TRUE( rnd.insert( 2 ) );
        EXPECT_TRUE( rnd.insert( 3 ) );
        EXPECT_TRUE( rnd.insert( 4 ) );
        EXPECT_TRUE( rnd.insert( 5 ) );

        EXPECT_FALSE( rnd.insert( 1 ) );
        EXPECT_FALSE( rnd.insert( 2 ) );
        EXPECT_FALSE( rnd.insert( 3 ) );
        EXPECT_FALSE( rnd.insert( 4 ) );

        EXPECT_EQ( rnd.get_random(), 3 );
        EXPECT_EQ( rnd.get_random(), 5 );
        EXPECT_EQ( rnd.get_random(), 1 );
    }
}