#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/sort_search.h"

namespace leetcode::sort_search::tests
{
    class rotated_min_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( rotated_min_tests, case1 )
    {
        const auto input = std::vector<int>
        {
            3, 4, 5, 1, 2
        };

        const auto actual = rotated_min::find_min( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( rotated_min_tests, case2 )
    {
        const auto input = std::vector<int>
        {
            4, 5, 6, 7, 0, 1, 2
        };

        const auto actual = rotated_min::find_min( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( rotated_min_tests, case3 )
    {
        const auto input = std::vector<int>
        {
            1, 2
        };

        const auto actual = rotated_min::find_min( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    class median_of_two_sorted_arr_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( median_of_two_sorted_arr_tests, case1 )
    {
        const auto input = std::pair<std::vector<int>, std::vector<int>>( { 1, 3 }, { 2 } );

        const auto actual = median_of_two_sorted_arr::find_median_sorted_arrays( input.first, input.second );
    	
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( median_of_two_sorted_arr_tests, case2 )
    {
        const auto input = std::pair<std::vector<int>, std::vector<int>>( { 1, 3 }, { 2, 4 } );

        const auto actual = median_of_two_sorted_arr::find_median_sorted_arrays( input.first, input.second );

        const auto expected = 2.5;

        EXPECT_EQ( actual, expected );
    }

    class sort_arr_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( sort_arr_tests, merge_case1 )
    {
        auto input = std::vector<int>{ 3, 1, 3 };

        auto actual = sort_arr_merge::sort_array( input );

        const auto expected = std::vector<int>{ 1, 3, 3 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_arr_tests, merge_case2 )
    {
        auto input = std::vector<int>{ 2, 5, 1, 3 };

        auto actual = sort_arr_merge::sort_array( input );

        const auto expected = std::vector<int>{ 1, 2, 3, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_arr_tests, quick_case1 )
    {
        auto input = std::vector<int>{ 3, 1, 3 };

        auto actual = sort_arr_merge::sort_array( input );

        const auto expected = std::vector<int>{ 1, 3, 3 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_arr_tests, quick_case2 )
    {
        auto input = std::vector<int>{ 2, 5, 1, 3 };

        auto actual = sort_arr_merge::sort_array( input );

        const auto expected = std::vector<int>{ 1, 2, 3, 5 };

        EXPECT_EQ( actual, expected );
    }
}