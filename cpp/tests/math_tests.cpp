#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../problems/math.h"

using namespace math_problems;

namespace problems::math_tests
{
    /// <summary>
    /// Testing class for ... .
    /// </summary>
    class t_tests :
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

    TEST_F( t_tests, case_empty )
    {

        const auto actual = true;

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }
}