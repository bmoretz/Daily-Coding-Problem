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
    }

    class frequency_stack_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( frequency_stack_tests, case1 )
    {
        auto fs = frequency_stack();

        fs.push( 5 );
        fs.push( 7 );
        fs.push( 5 );
        fs.push( 7 );
        fs.push( 4 );
        fs.push( 5 );

        {
            const auto actual = fs.pop();
            const auto expected = 5;

            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = fs.pop();
            const auto expected = 7;

            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = fs.pop();
            const auto expected = 5;

            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = fs.pop();
            const auto expected = 4;

            EXPECT_EQ( actual, expected );
        }
    }

    class autocomplete_system_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( autocomplete_system_tests, case1 )
    {
        auto word_list = std::vector<std::string>{ "i love you","island","iroman","i love leetcode" };
        auto word_freq = std::vector<int>{ 5, 3, 2, 2 };

        auto ac = autocomplete_system( word_list, word_freq );

        {
            const auto actual = ac.input( 'i' );
            const auto expected = std::vector<std::string>{ "i love you", "island", "i love leetcode" };
        	
            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = ac.input( ' ' );
            const auto expected = std::vector<std::string>{ "i love you", "i love leetcode" };

            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = ac.input( 'a' );
            const auto expected = std::vector<std::string>{ };

            EXPECT_EQ( actual, expected );
        }
    }
}