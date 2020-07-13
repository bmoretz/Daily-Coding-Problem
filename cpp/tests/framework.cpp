#include "pch.h"
#include <gtest/gtest.h>

#include "../hackerrank/sample.h"

using namespace hackerrank::sample;

namespace hackerrank::framework_tests
{
	/// <summary>
	/// some simple test cases to test / debug the problem
	/// solving framework.
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

    TEST_F( tutorial_string_stream_tests, run_test_cases )
    {
        const auto problem =
            tutorial_string_stream{ "c-tutorial-stringstream-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class tutorial_string_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( tutorial_string_tests, run_test_cases )
    {
        const auto problem =
            tutorial_string{ "c-tutorial-strings-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class tutorial_struct_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( tutorial_struct_tests, run_test_cases )
    {
        const auto problem =
            tutorial_struct{ "c-tutorial-struct-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class box_it_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( box_it_tests, run_test_cases )
    {
        const auto problem =
            box_it{ "box-it-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class inheritance_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( inheritance_tests, run_test_cases )
    {
        const auto problem =
            inheritance{ "inheritance-introduction-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class ra_inheritance_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( ra_inheritance_tests, run_test_cases )
    {
        const auto problem =
            ra_inheritance{ "rectangle-area-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class ma_inheritance_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( ma_inheritance_tests, run_test_cases )
    {
        const auto problem =
            mult_inheritance{ "multi-level-inheritance-cpp-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}