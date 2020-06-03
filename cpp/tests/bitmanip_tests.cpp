#include "pch.h"
#include <gtest/gtest.h>
#include <bitset>

#include "../problems/bitmanip.h"

using namespace bitmanip_problems;

namespace bitmanip_tests
{
    /// <summary>
    /// Testing class for insertion.
    /// </summary>
    class insertion_tests :
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
    // Insertion 1
    //

    TEST_F( insertion_tests, insertion1_case1 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 19; // 10011

        const auto res = insertion1( n, m, 2, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10001001100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case2 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 31; // 11111

        const auto res = insertion1( n, m, 2, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10001111100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case3 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 63; // 111111

        const auto res = insertion1( n, m, 2, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10011111100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case4 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 63; // 111111

        const auto res = insertion1( n, m, 0, 5 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10000111111";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case5 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 63; // 111111

        const auto res = insertion1( n, m, 1, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10001111110";

        EXPECT_EQ( actual, expected );
    }
}