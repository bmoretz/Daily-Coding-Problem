#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/games.h"

namespace leetcode::games::tests
{
    class snake_game_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( snake_game_tests, case1 )
    {
        const auto width = 3, height = 2;
        auto food = std::vector<std::vector<int>>{ { 1, 2 }, { 0, 1 } };

        auto snake = SnakeGame( width, height, food );

        /*
        Initially the snake appears at position( 0, 0 ) and the food at( 1, 2 ).

        | S| | |
        | | |F |
         */

    	EXPECT_EQ( snake.move( "R" ), 0 );

        /*
        | |S| |
        | | |F |
        */

        EXPECT_EQ( snake.move( "D" ), 0 );
    	
        /*
        | | | |
        | |S | F |
        */

        // ( Snake eats the first food and right after that, the second food appears at( 0, 1 ) )
    	
        EXPECT_EQ( snake.move( "R" ), 1 );

        /*
        | |F| |
        | |S | S |
        */

    	EXPECT_EQ( snake.move( "U" ), 1 );
    	
        /*
        | |F | S|
        | | |S |
        */

        EXPECT_EQ( snake.move( "L" ), 2 );
    	
        /*
        | |S | S|
        | | |S |
        */

        EXPECT_EQ( snake.move( "U" ), -1 );
    }
}