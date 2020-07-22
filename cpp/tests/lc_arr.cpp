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

    TEST_F( two_sum_tests, twosum_1 )
    {
        const auto numbers = { 2, 7, 11, 15 };
        const auto target = 9;

        const auto actual = target_two_sum::two_sum1( numbers, target );
        const auto expected = std::vector<int>{ 0, 1 };
    	
        EXPECT_EQ( actual, expected );
    }
}