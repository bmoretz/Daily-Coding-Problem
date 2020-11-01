#include "pch.h"
#include <gtest/gtest.h>

#include "../data-structures/arr_queue.h"

namespace data_structures::arr_queue::tests
{
    /// <summary>
    /// Testing class for circular array queue implementation.
    /// </summary>
    class arr_queue_tests :
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
    // arr queue tests
    //

    TEST_F( arr_queue_tests, dequeue_empty )
    {
        auto my_q = queue<int>( 3 );

        EXPECT_TRUE( my_q.is_empty() );
        EXPECT_FALSE( my_q.de_queue() );
    }

    TEST_F( arr_queue_tests, enqueue_full )
    {
        auto my_q = queue<int>( 3 );

        EXPECT_TRUE( my_q.is_empty() );
        EXPECT_FALSE( my_q.de_queue() );

        EXPECT_TRUE( my_q.en_queue( 1 ) );
        EXPECT_TRUE( my_q.en_queue( 2 ) );
        EXPECT_TRUE( my_q.en_queue( 3 ) );

        EXPECT_FALSE( my_q.en_queue( 4 ) );
    }

    TEST_F( arr_queue_tests, head_tail )
    {
        auto my_q = queue<int>( 3 );

        EXPECT_TRUE( my_q.is_empty() );
        EXPECT_FALSE( my_q.de_queue() );

        EXPECT_TRUE( my_q.en_queue( 1 ) );
        EXPECT_TRUE( my_q.en_queue( 2 ) );
        EXPECT_TRUE( my_q.en_queue( 3 ) );

        EXPECT_EQ( my_q.front(), 1 );
        EXPECT_EQ( my_q.rear(), 3 );
    }

    TEST_F( arr_queue_tests, overwrite_head )
    {
        auto my_q = queue<int>( 3 );

        EXPECT_TRUE( my_q.is_empty() );
        EXPECT_FALSE( my_q.de_queue() );

        EXPECT_TRUE( my_q.en_queue( 1 ) );
        EXPECT_TRUE( my_q.en_queue( 2 ) );
        EXPECT_TRUE( my_q.en_queue( 3 ) );

        EXPECT_EQ( my_q.front(), 1 );
        EXPECT_EQ( my_q.rear(), 3 );

        EXPECT_EQ( my_q.de_queue(), true );
        EXPECT_EQ( my_q.en_queue( 4 ), true );

        EXPECT_EQ( my_q.front(), 2 );
        EXPECT_EQ( my_q.rear(), 4 );
    }
}