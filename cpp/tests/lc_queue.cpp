#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/queue.h"

namespace leetcode::queue::tests
{
    class first_unique_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( first_unique_tests, case1 )
    {
	    const auto initial = std::vector<int>{ 7, 7, 7, 7, 7, 7 };

        auto firstUnique = first_unique( initial );

        EXPECT_EQ( firstUnique.show_first_unique(), -1 );

    	firstUnique.add( 7 );
        firstUnique.add( 3 );
        firstUnique.add( 3 );
        firstUnique.add( 7 );
        firstUnique.add( 17 );
    	
        EXPECT_EQ( firstUnique.show_first_unique(), 17 );
    }

    TEST_F( first_unique_tests, case2 )
    {
        const auto initial = std::vector<int>{ 7, 7, 7, 7, 7, 7 };

        auto firstUnique = first_unique( initial );

        EXPECT_EQ( firstUnique.show_first_unique(), -1 );

        firstUnique.add( 7 );
        firstUnique.add( 3 );
        firstUnique.add( 3 );
        firstUnique.add( 7 );
        firstUnique.add( 17 );

        EXPECT_EQ( firstUnique.show_first_unique(), 17 );

        firstUnique.add( 17 );

        EXPECT_EQ( firstUnique.show_first_unique(), -1 );
    }


    TEST_F( first_unique_tests, case3 )
    {
        const auto initial = std::vector<int>{ 2, 3, 5 };

        auto firstUnique = first_unique( initial );

        EXPECT_EQ( firstUnique.show_first_unique(), 2 );

        firstUnique.add( 3 );
        firstUnique.add( 3 );

        EXPECT_EQ( firstUnique.show_first_unique(), 2 );

        firstUnique.add( 2 );
        firstUnique.add( 5 );
    	
        EXPECT_EQ( firstUnique.show_first_unique(), -1 );
    }

    TEST_F( first_unique_tests, case4 )
    {
        const auto initial = std::vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8 };

        auto firstUnique = first_unique( initial );

        EXPECT_EQ( firstUnique.show_first_unique(), 1 );

        firstUnique.add( 1 );
        firstUnique.add( 2 );
        firstUnique.add( 6 );
        
        EXPECT_EQ( firstUnique.show_first_unique(), 3 );

        firstUnique.add( 3 );
        firstUnique.add( 5 );
        firstUnique.add( 4 );
    	
        EXPECT_EQ( firstUnique.show_first_unique(), 7 );
    }

    TEST_F( first_unique_tests, case5 )
    {
        const auto initial = std::vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        auto firstUnique = first_unique( initial );

        EXPECT_EQ( firstUnique.show_first_unique(), 1 );

        firstUnique.add( 1 );
        firstUnique.add( 2 );
        firstUnique.add( 6 );

        EXPECT_EQ( firstUnique.show_first_unique(), 3 );

        firstUnique.add( 3 );
        firstUnique.add( 5 );
        firstUnique.add( 4 );

        EXPECT_EQ( firstUnique.show_first_unique(), 7 );

        firstUnique.add( 7 );
    	
        EXPECT_EQ( firstUnique.show_first_unique(), 8 );
    }
}