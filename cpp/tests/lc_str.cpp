#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/str.h"

namespace leetcode::str::tests
{
    class len_longest_substring_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( len_longest_substring_tests, lss1_case1 )
    {
        const std::string input = "a";

        const auto actual = 
            len_longest_substring::length_of_longest_substring1( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss1_case2 )
    {
        const std::string input = "ccabcdef";

        const auto actual = 
            len_longest_substring::length_of_longest_substring1( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss1_case3 )
    {
        const std::string input = "pwwkew";

        const auto actual = 
            len_longest_substring::length_of_longest_substring1( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss1_case4 )
    {
        const std::string input = "ohomm";

        const auto actual = len_longest_substring::length_of_longest_substring1( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss1_case5 )
    {
        const std::string input = "asjrgapa";

        const auto actual = len_longest_substring::length_of_longest_substring1( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss2_case1 )
    {
        const std::string input = "a";

        const auto actual =
            len_longest_substring::length_of_longest_substring2( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss2_case2 )
    {
        const std::string input = "ccabcdef";

        const auto actual =
            len_longest_substring::length_of_longest_substring2( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss2_case3 )
    {
        const std::string input = "pwwkew";

        const auto actual =
            len_longest_substring::length_of_longest_substring2( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss2_case4 )
    {
        const std::string input = "ohomm";

        const auto actual = 
            len_longest_substring::length_of_longest_substring2( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_longest_substring_tests, lss2_case5 )
    {
        const std::string input = "asjrgapa";

        const auto actual = 
            len_longest_substring::length_of_longest_substring2( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    class len_last_word_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( len_last_word_tests, case1 )
    {
        std::string input = "Hello World";

        const auto actual =
            length_of_last_word::len_last_word( input );
    	
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_last_word_tests, case2 )
    {
        std::string input = "NoWords";

        const auto actual =
            length_of_last_word::len_last_word( input );

        const auto expected = 7;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_last_word_tests, case3 )
    {
        std::string input = "this has many words";

        const auto actual =
            length_of_last_word::len_last_word( input );

        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_last_word_tests, case4 )
    {
        std::string input = "            many        spaces              ";

        const auto actual =
            length_of_last_word::len_last_word( input );

        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( len_last_word_tests, case5 )
    {
        std::string input = " fda fdsafdsa  FDSAfFDS ";

        const auto actual =
            length_of_last_word::len_last_word( input );

        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }
}
