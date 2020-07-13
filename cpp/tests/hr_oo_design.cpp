#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../hackerrank/oo_design.h"

using namespace hackerrank::oo_design;

namespace hackerrank::oo_design
{
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

    TEST_F( virtual_functions_tests, run_test_cases )
    {
        const auto problem =
	        virtual_functions{ "virtual-functions-testcases" };

        EXPECT_TRUE( problem.run() );
    }

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

    TEST_F( override_ostream_tests, run_test_cases )
    {
        const auto problem =
            override_ostream{ "overloading-ostream-operator-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class abstract_classes_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( abstract_classes_tests, run_test_cases )
    {
        const auto problem =
            abstract_classes{ "abstract-classes-polymorphism-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    class multiple_inherited_functions_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( multiple_inherited_functions_tests, run_test_cases )
    {
        const auto problem =
            multiple_inherited_functions{ "accessing-inherited-functions-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}