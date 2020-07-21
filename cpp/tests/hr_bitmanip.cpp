#include "pch.h"
#include <gtest/gtest.h>

#include "../hackerrank/bitmanip.h"

namespace hackerrank::bitmanip::tests
{
    class bit_array_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( bit_array_tests, run_test_cases )
    {
        const auto problem =
            bit_array{ "bitset-1-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}