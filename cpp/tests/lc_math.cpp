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

    class number_of_1s_substrings_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( number_of_1s_substrings_tests, case1 )
    {
        const auto sln = number_of_1s_substrings::number_of_subgroups;
    	
        const auto input = "0110111";

        const auto actual = sln( input );
        const auto expected = 9;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case2 )
    {
        const auto sln = number_of_1s_substrings::number_of_subgroups;

        const auto input = "101";

        const auto actual = sln( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case3 )
    {
        const auto sln = number_of_1s_substrings::number_of_subgroups;

        const auto input = "111111";

        const auto actual = sln( input );
        const auto expected = 21;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case4 )
    {
        const auto sln = number_of_1s_substrings::number_of_subgroups;

        const auto input = "000";

        const auto actual = sln( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case5 )
    {
        const auto sln = number_of_1s_substrings::number_of_subgroups;

        const auto input = "0101111111010111101111111111111111111111011111111111111111111111111111111111";

        const auto actual = sln( input );
        const auto expected = 923;

        EXPECT_EQ( actual, expected );
    }

    class fibonacci_number_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( fibonacci_number_tests, case1 )
    {
        const auto sln = fibonacci_number::fib1;

        const auto input = 0;

        const auto actual = sln( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case2 )
    {
        const auto sln = fibonacci_number::fib1;

        const auto input = 5;

        const auto actual = sln( input );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case3 )
    {
        const auto sln = fibonacci_number::fib1;

        const auto input = 10;

        const auto actual = sln( input );
        const auto expected = 55;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case4 )
    {
        const auto sln = fibonacci_number::fib1;

        const auto input = 20;

        const auto actual = sln( input );
        const auto expected = 6765;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case5 )
    {
        const auto sln = fibonacci_number::fib1;

        const auto input = 30;

        const auto actual = sln( input );
        const auto expected = 832040;

        EXPECT_EQ( actual, expected );
    }
}