#include "pch.h"
#include <gtest/gtest.h>

#include "../hackerrank/str.h"

namespace hackerrank::str::tests
{
    /// <summary>
	/// Testing class for attribute parser.
	/// </summary>
    class attribute_parser_tests :
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
    // attribute parser, test cases
    //

    TEST_F( attribute_parser_tests, run_test_cases )
    {
	    const auto problem =
            attribute_parser{ "attribute-parser-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}