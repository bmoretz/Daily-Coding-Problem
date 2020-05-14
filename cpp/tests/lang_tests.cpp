#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../problems/lang.h"

using namespace lang_problems;

namespace lang_tests
{
    /// <summary>
    /// Testing class for ... .
    /// </summary>
    class t1_tests :
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
    // prob 1
    //

    TEST_F( t1_tests, case_empty )
    {
        const auto actual = true;

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }
}