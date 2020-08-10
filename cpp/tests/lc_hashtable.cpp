#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/hashtable.h"

namespace leetcode::hashtable::tests
{
    class element_with_most_appearances_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( element_with_most_appearances_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 2, 2, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case3 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case4 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 3, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case5 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 2, 3, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }
}