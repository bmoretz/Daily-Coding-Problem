#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../hackerrank/oo_design.h"

using namespace hackerrank::oo_design;

namespace hackerrank::oo_design
{
    /// <summary>
    /// Testing class for virtual functions.
    /// </summary>
    class virtual_functions_tests :
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

    TEST_F( virtual_functions_tests, run_test_cases )
    {
        const auto problem =
	        hackerrank::oo_design::virtual_functions{ "virtual-functions-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for override_ostream.
    /// </summary>
    class override_ostream_tests :
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
    // override_ostream, test cases
    //

    TEST_F( override_ostream_tests, run_test_cases )
    {
        const auto problem =
            override_ostream{ "overloading-ostream-operator-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}