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

    class search_recommendation_system_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( search_recommendation_system_tests, case1 )
    {
        const auto searcher = search_recommendation_system();

        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            std::vector<std::string> { "mobile", "mouse", "moneypot", "monitor", "mousepad" },
            "mouse"
        };

        const auto results = searcher.suggest_products( input.first, input.second );

        EXPECT_EQ( results.size(), 5 );

        const auto expected1 = std::vector<std::string> { "mobile", "moneypot", "monitor" };
        EXPECT_EQ( results[ 0 ], expected1 );

        const auto expected2 = std::vector<std::string>{ "mobile","moneypot","monitor" };
        EXPECT_EQ( results[ 1 ], expected2 );

        const auto expected3 = std::vector<std::string>{ "mouse","mousepad" };
        EXPECT_EQ( results[ 2 ], expected3 );

        const auto expected4 = std::vector<std::string>{ "mouse","mousepad" };
        EXPECT_EQ( results[ 3 ], expected4 );

        const auto expected5 = std::vector<std::string>{ "mouse","mousepad" };
        EXPECT_EQ( results[ 4 ], expected5 );
    }

    TEST_F( search_recommendation_system_tests, case2 )
    {
        const auto searcher = search_recommendation_system();

        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            std::vector<std::string> { "havana" },
            "havana"
        };

        const auto results = searcher.suggest_products( input.first, input.second );

        EXPECT_EQ( results.size(), 6 );

        const auto expected1 = std::vector<std::string>{ "havana" };
        EXPECT_EQ( results[ 0 ], expected1 );

        const auto expected2 = std::vector<std::string>{ "havana" };
        EXPECT_EQ( results[ 1 ], expected2 );

        const auto expected3 = std::vector<std::string>{ "havana" };
        EXPECT_EQ( results[ 2 ], expected3 );

        const auto expected4 = std::vector<std::string>{ "havana" };
        EXPECT_EQ( results[ 3 ], expected4 );

        const auto expected5 = std::vector<std::string>{ "havana" };
        EXPECT_EQ( results[ 4 ], expected5 );
    }

    TEST_F( search_recommendation_system_tests, case3 )
    {
        const auto searcher = search_recommendation_system();

        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            std::vector<std::string> { "bags", "baggage", "banner", "box", "cloths" },
            "bags"
        };

        const auto results = searcher.suggest_products( input.first, input.second );

        EXPECT_EQ( results.size(), 4 );

        const auto expected1 = std::vector<std::string>{ "baggage", "bags", "banner" };
        EXPECT_EQ( results[ 0 ], expected1 );

        const auto expected2 = std::vector<std::string>{ "baggage","bags","banner" };
        EXPECT_EQ( results[ 1 ], expected2 );

        const auto expected3 = std::vector<std::string>{ "baggage", "bags" };
        EXPECT_EQ( results[ 2 ], expected3 );

        const auto expected4 = std::vector<std::string>{ "bags" };
        EXPECT_EQ( results[ 3 ], expected4 );
    }

    TEST_F( search_recommendation_system_tests, case4 )
    {
        const auto searcher = search_recommendation_system();

        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            std::vector<std::string> { "havana" },
            "tatiana"
        };

        const auto results = searcher.suggest_products( input.first, input.second );

        EXPECT_EQ( results.size(), 7 );

        const auto expected1 = std::vector<std::string>{ };
        EXPECT_EQ( results[ 0 ], expected1 );

        const auto expected2 = std::vector<std::string>{ };
        EXPECT_EQ( results[ 1 ], expected2 );

        const auto expected3 = std::vector<std::string>{ };
        EXPECT_EQ( results[ 2 ], expected3 );

        const auto expected4 = std::vector<std::string>{ };
        EXPECT_EQ( results[ 3 ], expected4 );

        const auto expected5 = std::vector<std::string>{ };
        EXPECT_EQ( results[ 4 ], expected5 );

        const auto expected6 = std::vector<std::string>{ };
        EXPECT_EQ( results[ 5 ], expected5 );
    }

    class bounded_blocking_queue_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( bounded_blocking_queue_tests, case1 )
    {
        // initialize the queue with capacity = 2.
        auto queue = bounded_blocking_queue( 2 );

        // The producer thread enqueues 1 to the queue.
        queue.enqueue( 1 );

        // The consumer thread calls dequeue and returns 1 from the queue.
        queue.dequeue();

        // Since the queue is empty, the consumer thread is blocked.
        queue.dequeue();

        // The producer thread enqueues 0 to the queue. The consumer thread is unblocked and returns 0 from the queue.
        queue.enqueue( 0 );

        // The producer thread enqueues 2 to the queue.
        queue.enqueue( 2 );

        // The producer thread enqueues 3 to the queue.
        queue.enqueue( 3 );

        // The producer thread is blocked because the queue's capacity (2) is reached.
        queue.enqueue( 4 );

        // The consumer thread returns 2 from the queue. The producer thread is unblocked and enqueues 4 to the queue.
        queue.dequeue();

        // 2 elements remaining in the queue. size() is always called at the end of each test case.
        queue.size();
    }
}