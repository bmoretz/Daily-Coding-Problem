#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/math.h"

namespace leetcode::math::tests
{
    class min_moves_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( min_moves_tests, case1 )
    {
        auto input = std::vector<int>{ 1, 2, 3 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case2 )
    {
        auto input = std::vector<int>{ 1, 6, 2, 4 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 7;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case3 )
    {
        auto input = std::vector<int>{ 1, 0, 0, 8, 6 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 14;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case4 )
    {
        auto input = std::vector<int>{ 203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 2127271182;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case5 )
    {
        auto input = std::vector<int>{ 1 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }
}