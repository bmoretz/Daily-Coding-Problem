#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../hackerrank/stl.h"

using namespace hackerrank::stl;

namespace hackerrank::stl
{
    /// <summary>
    /// Testing class for vector sort.
    /// </summary>
    class vector_sort_tests :
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
    // vector sort, test cases
    //

    TEST_F( vector_sort_tests, run_test_cases )
    {
        const auto problem =
            vector_sort{ "vector-sort-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for vector erase.
    /// </summary>
    class vector_erase_tests :
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
    // vector erase, test cases
    //

    TEST_F( vector_erase_tests, run_test_cases )
    {
        const auto problem =
            vector_erase{ "vector-erase-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for lower bound.
    /// </summary>
    class lower_bound_tests :
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
    // lower bound, test cases
    //

    TEST_F( lower_bound_tests, run_test_cases )
    {
        const auto problem =
            lower_bound{ "cpp-lower-bound-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}