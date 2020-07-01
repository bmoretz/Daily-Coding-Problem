#include "pch.h"

#include <gtest/gtest.h>

#include "../hackerrank/debug.h"

using namespace hackerrank::debug;

namespace hackerrank::debug_tests
{
    /// <summary>
    /// Testing class for variable_sized_arrays.
    /// </summary>
    class inherited_code_tests :
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
    // Inherited Code, test cases
    //

    TEST_F( inherited_code_tests, run_test_cases )
    {
        const auto problem =
	        inherited_code{ "inherited-code-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}