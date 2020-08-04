#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/arr.h"

namespace leetcode::arr::tests
{
    class two_sum_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( two_sum_tests, case1 )
    {
        const auto numbers = { 2, 7, 11, 15 };
        const auto target = 9;

        const auto actual = target_two_sum::two_sum1( numbers, target );
        const auto expected = std::vector<int>{ 0, 1 };
    	
        EXPECT_EQ( actual, expected );
    }

    class maximum_two_prod_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( maximum_two_prod_tests, case1 )
    {
        auto input = std::vector<int>{ 3, 4, 5, 2 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 12;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case2 )
    {
        auto input = std::vector<int>{ 1, 5, 4, 5 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 16;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case3 )
    {
        auto input = std::vector<int>{ 3, 7 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 12;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case4 )
    {
        auto input = std::vector<int>{ 3, 7 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 12;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_two_prod_tests, case5 )
    {
        auto input = std::vector<int>{ 1, 2, 5, 3, 6 };

        const auto actual = maximum_two_prod::max_product1( input );
        const auto expected = 20;

        EXPECT_EQ( actual, expected );
    }

    class contiguous_array_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( contiguous_array_tests, case1 )
    {
        const auto input = std::vector<int>{ 0, 1 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case2 )
    {
        const auto input = std::vector<int>{ 0, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case3 )
    {
        const auto input = std::vector<int>{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 26;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case4 )
    {
        const auto input = std::vector<int>{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 22;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case5 )
    {
        const auto input = std::vector<int>{ 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 ,1, 0, 0, 1, 1, 1, 0 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 20;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( contiguous_array_tests, case6 )
    {
        const auto input = std::vector<int>{ 0, 1, 1, 0, 1, 1 };

        const auto actual = contiguous_array::find_max_length( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }
}