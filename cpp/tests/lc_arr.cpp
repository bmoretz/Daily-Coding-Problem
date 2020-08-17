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

    class max_sub_array_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( max_sub_array_tests, case1 )
    {
        const auto input = std::vector<int>{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 0, -1, 0, 0, 0, -1, 0, 1 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case3 )
    {
        const auto input = std::vector<int>{ 3, -1, 0, 2 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case4 )
    {
        const auto input = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 30;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_sub_array_tests, case5 )
    {
        const auto input = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4, 12, 4, 13, 1, 0, 1, 143 };

        const auto actual = max_sub_array::max_sub_array1( input );
        const auto expected = 200;

        EXPECT_EQ( actual, expected );
    }

    class buy_and_sell_stock_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( buy_and_sell_stock_tests, case1 )
    {
        const auto input = std::vector<int>{ 7, 1, 5, 3, 6, 4 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case2 )
    {
        const auto input = std::vector<int>{ 7, 6, 4, 3, 1 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case3 )
    {
        const auto input = std::vector<int>{ 7 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case4 )
    {
        const auto input = std::vector<int>{ 7, 1, 3, 2, 9, 4 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( buy_and_sell_stock_tests, case5 )
    {
        const auto input = std::vector<int>{ 7, 1, 3, 2, 9, 4, 2, 2, 1, 2, 6 };

        const auto actual = buy_and_sell_stock::max_profit( input );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    class maximum_circular_sum_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( maximum_circular_sum_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, -2, 3, -2 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case2 )
    {
        const auto input = std::vector<int>{ 5, -3, 5 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 10;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case3 )
    {
        const auto input = std::vector<int>{ 3, -1, 2, -1 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case4 )
    {
        const auto input = std::vector<int>{ 3, -2, 2, -3 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( maximum_circular_sum_tests, case5 )
    {
        const auto input = std::vector<int>{ -2, -3, -1 };

        const auto actual = maximum_circular_sum::max_subarray_sum_circular( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }
}