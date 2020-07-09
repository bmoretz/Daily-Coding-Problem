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

    TEST_F( lower_bound_tests, run_test_cases )
    {
        const auto problem =
            lower_bound{ "cpp-lower-bound-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for set.
    /// </summary>
    class stl_set_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( stl_set_tests, run_test_cases )
    {
        const auto problem =
            stl_set{ "cpp-sets-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for map.
    /// </summary>
    class stl_map_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( stl_map_tests, run_test_cases )
    {
        const auto problem =
            stl_map{ "cpp-maps-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for pretty print.
    /// </summary>
    class pretty_print_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( pretty_print_tests, run_test_cases )
    {
        const auto problem =
            pretty_print{ "prettyprint-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for print k max.
    /// </summary>
    class print_k_max_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( print_k_max_tests, run_test_cases )
    {
        const auto problem =
            stl_dequeue{ "deque-stl-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}