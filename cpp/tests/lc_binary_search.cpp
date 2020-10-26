#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/binary_search.h"

namespace leetcode::binary_search::tests
{
    class find_k_closest_elements_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( find_k_closest_elements_tests, case1 )
    {
        const auto input = std::vector<int>{ 1 };

        const auto actual = find_k_closest_elements::findClosestElements( input, 1, 1 );
        const auto expected = std::vector<int>{ 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( find_k_closest_elements_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 3 };

        const auto actual = find_k_closest_elements::findClosestElements( input, 1, 2 );
        const auto expected = std::vector<int>{ 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( find_k_closest_elements_tests, case3 )
    {
        const auto input = std::vector<int>{ 0, 0, 1, 2, 3, 3, 4, 7, 7, 8 };

        const auto actual = find_k_closest_elements::findClosestElements( input, 3, 5 );
        const auto expected = std::vector<int>{ 3, 3, 4 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( find_k_closest_elements_tests, case4 )
    {
        const auto input = std::vector<int>{ 0, 0, 0, 1, 3, 5, 6, 7, 8, 8 };

        const auto actual = find_k_closest_elements::findClosestElements( input, 2, 2 );
        const auto expected = std::vector<int>{ 1, 3 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( find_k_closest_elements_tests, case5 )
    {
        const auto input = std::vector<int>{ 0, 1, 1, 1, 2, 3, 6, 7, 8, 9 };

        const auto actual = find_k_closest_elements::findClosestElements( input, 9, 4 );
        const auto expected = std::vector<int>{ 0, 1, 1, 1, 2, 3, 6, 7, 8 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( find_k_closest_elements_tests, case6 )
    {
        const auto input = std::vector<int>{ 1, 2, 5, 5, 6, 6, 7, 7, 8, 9 };

        const auto actual = find_k_closest_elements::findClosestElements( input, 7, 7 );
        const auto expected = std::vector<int>{ 5, 5, 6, 6, 7, 7, 8 };

        EXPECT_EQ( actual, expected );
    }
}