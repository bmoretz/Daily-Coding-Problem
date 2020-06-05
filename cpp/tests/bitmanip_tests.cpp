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

    /// <summary>
	/// Testing class for decimal to binary (string).
	/// </summary>
    class dec_to_bin_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( dec_to_bin_tests, dec_to_bin_case1 )
    {
        const auto n = .72;

        const auto actual = dec_to_bin( n );
        const auto expected = ".0100100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case2 )
    {
        const auto n = .69;

        const auto actual = dec_to_bin( n );
        const auto expected = ".0100010";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case3 )
    {
        const auto n = 0.121841878;

        const auto actual = dec_to_bin( n );
        const auto expected = ".010111001111010100111100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case4 )
    {
        const auto n = 0.1e-32;

        const auto actual = dec_to_bin( n );
        const auto expected = "ERROR";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case5 )
    {
        const auto n = 0.1e-12;

        const auto actual = dec_to_bin( n );
        const auto expected = ".010011000100101100111111";

        EXPECT_EQ( actual, expected );
    }
}