#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/design.h"

namespace leetcode::design::tests
{
    class tic_tac_toe_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( tic_tac_toe_tests, case1 )
    {
        auto toe = tic_tac_toe( 3 );

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 0, 0, 1 ), 0 );
        /*
        | X| | |
            | | | |    // Player 1 makes a move at (0, 0).
            | | | |
         */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 0, 2, 2 ), 0 );
    	
        /*
        | X| |O|
        | | | |    // Player 2 makes a move at (0, 2).
        | | | |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 2, 2, 1 ), 0 );
        /*
        | X| |O|
        | | | |    // Player 1 makes a move at (2, 2).
        | | |X |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 1, 1, 2 ), 0 );
    	
        /*
        | X| |O|
        | |O| |    // Player 2 makes a move at (1, 1).
        | | |X |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 2, 0, 1 ), 0 );
    	
        /*
        | X| |O|
        | |O| |    // Player 1 makes a move at (2, 0).
        |X| |X |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 1, 0, 2 ), 0 );

    	/*
        | X| |O|
        |O | O| |    // Player 2 makes a move at (1, 0).
        |X| |X |
        */

        // ->Returns 1 ( player 1 wins )
        EXPECT_EQ( toe.move( 2, 1, 1 ), 1 );
    	
        /*
        | X| |O|
        |O | O| |    // Player 1 makes a move at (2, 1).
        |X | X | X |
        */
    }

    TEST_F( tic_tac_toe_tests, case2 )
    {
        auto toe = tic_tac_toe( 3 );

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 0, 0, 1 ), 0 );
        /*
        | X| | |
            | | | |    // Player 1 makes a move at (0, 0).
            | | | |
         */

         // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 0, 2, 2 ), 0 );

        /*
        | X| |O|
        | | | |    // Player 2 makes a move at (0, 2).
        | | | |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 2, 2, 1 ), 0 );
        /*
        | X| |O|
        | | | |    // Player 1 makes a move at (2, 2).
        | | |X |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 1, 0, 2 ), 0 );

        /*
        | X| |O|
        | |O| |    // Player 2 makes a move at (1, 1).
        | | |X |
        */

        // ->Returns 1 ( player 1 wins )
        EXPECT_EQ( toe.move( 1, 1, 1 ), 1 );
    }

    TEST_F( tic_tac_toe_tests, case3 )
    {
        auto toe = tic_tac_toe( 3 );

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 0, 0, 1 ), 0 );
        /*
        | X| | |
            | | | |    // Player 1 makes a move at (0, 0).
            | | | |
         */

         // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 0, 2, 2 ), 0 );

        /*
        | X| |O|
        | | | |    // Player 2 makes a move at (0, 2).
        | | | |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 2, 2, 1 ), 0 );
        /*
        | X| |O|
        | | | |    // Player 1 makes a move at (2, 2).
        | | |X |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 1, 1, 2 ), 0 );

        /*
        | X| |O|
        | |O| |    // Player 2 makes a move at (1, 1).
        | | |X |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 2, 0, 1 ), 0 );

        /*
        | X| |O|
        | |O| |    // Player 1 makes a move at (2, 0).
        |X| |X |
        */

        // ->Returns 0 ( no one wins )
        EXPECT_EQ( toe.move( 1, 0, 2 ), 0 );

        /*
        | X| |O|
        |O | O| |    // Player 2 makes a move at (1, 0).
        |X| |X |
        */

        // ->Returns 1 ( player 1 wins )
        EXPECT_EQ( toe.move( 2, 1, 1 ), 1 );

        /*
        | X| |O|
        |O | O| |    // Player 1 makes a move at (2, 1).
        |X | X | X |
        */
    }

    class vector_iterator_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( vector_iterator_tests, case1 )
    {
        const auto vectors = std::vector<std::vector<int>>{
            {1}, {}
        };

        auto iter = vector_iterator( vectors );

        {
            auto actual = iter.has_next();
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.next();
            const auto expected = 1;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.has_next();
            const auto expected = false;

            EXPECT_EQ( actual, expected );
        }
    }

    TEST_F( vector_iterator_tests, case2 )
    {
        const auto vectors = std::vector<std::vector<int>>{
            {}, {-1}
        };

        auto iter = vector_iterator( vectors );

        {
            auto actual = iter.has_next();
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.next();
            const auto expected = -1;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.has_next();
            const auto expected = false;

            EXPECT_EQ( actual, expected );
        }
    }

    TEST_F( vector_iterator_tests, case3 )
    {
        const auto vectors = std::vector<std::vector<int>>{
            {1,2}, {3}, {4}
        };

        auto iter = vector_iterator( vectors );

        {
            auto actual = iter.has_next();
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.next();
            const auto expected = 1;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.next();
            const auto expected = 2;

            EXPECT_EQ( actual, expected );
        }
    	
        {
            auto actual = iter.has_next();
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.next();
            const auto expected = 3;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.has_next();
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.next();
            const auto expected = 4;

            EXPECT_EQ( actual, expected );
        }

        {
            auto actual = iter.has_next();
            const auto expected = false;

            EXPECT_EQ( actual, expected );
        }
    }

    class hash_set_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( hash_set_tests, case1 )
    {
        auto hash_set = my_hash_set();

        hash_set.add( 1 );
        hash_set.add( 2 );

        EXPECT_EQ( hash_set.contains( 1 ), true );
        EXPECT_EQ( hash_set.contains( 3 ), false );
    	
        hash_set.add( 2 );

        EXPECT_EQ( hash_set.contains( 2 ), true );
    	
        hash_set.remove( 2 );

        EXPECT_EQ( hash_set.contains( 2 ), false );
    }
}