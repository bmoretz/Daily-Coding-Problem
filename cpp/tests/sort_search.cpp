#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/sort_search.h"

namespace leetcode::sort_search::tests
{
    class sort_search_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( sort_search_tests, case1 )
    {
        const auto input = std::vector<int>
        {
            3, 4, 5, 1, 2
        };

        const auto actual = rotated_min::findMin( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_search_tests, case2 )
    {
        const auto input = std::vector<int>
        {
            4, 5, 6, 7, 0, 1, 2
        };

        const auto actual = rotated_min::findMin( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sort_search_tests, case3 )
    {
        const auto input = std::vector<int>
        {
            1, 2
        };

        const auto actual = rotated_min::findMin( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }
}