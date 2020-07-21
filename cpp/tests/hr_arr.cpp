#include "pch.h"
#include <gtest/gtest.h>

#include "../hackerrank/arr.h"

namespace hackerrank::arr::tests
{
    /// <summary>
    /// Testing class for variable_sized_arrays.
    /// </summary>
    class variable_sized_arrays_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    //
    // Variable Sized Arrays, test cases
    //

    TEST_F( variable_sized_arrays_tests, run_test_cases )
    {
        auto problem =
            variable_sized_arrays{ "variable-sized-arrays-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}