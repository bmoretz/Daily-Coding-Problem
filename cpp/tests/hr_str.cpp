#include "pch.h"
#include <gtest/gtest.h>

#include "../hackerrank/str.h"

using namespace hackerrank::str;

namespace hackerrank::str_tests
{
    /// <summary>
    /// Testing class for string stream tutorial.
    /// </summary>
    class tutorial_string_stream_tests :
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
    // string stream tutorial, test cases
    //

    TEST_F( tutorial_string_stream_tests, run_test_cases )
    {
        auto problem =
            tutorial_string_stream{ "c-tutorial-stringstream-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}