#include "pch.h"
#include <gtest/gtest.h>

#include "../hackerrank/lang.h"

using namespace hackerrank::lang;

namespace hackerrank::bitmanip_tests
{
    class cpp_template_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( cpp_template_tests, run_test_cases )
    {
        const auto problem =
            cpp_template{ "c-class-templates-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class cpp_preprocessor_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( cpp_preprocessor_tests, run_test_cases )
    {
        const auto problem =
            cpp_preprocessor{ "preprocessor-solution-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class cpp_operator_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( cpp_operator_tests, run_test_cases )
    {
        const auto problem =
            cpp_operator_overloading{ "operator-overloading-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class cpp_operator_overload_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( cpp_operator_overload_tests, run_test_cases )
    {
        const auto problem =
            overload_operators{ "overload-operators-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class workshop_optimization_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( workshop_optimization_tests, run_test_cases )
    {
        const auto problem =
            workshop_optimization{ "attending-workshops-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class template_specialization_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( template_specialization_tests, run_test_cases )
    {
        const auto problem =
            template_specialization{ "cpp-class-template-specialization-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}