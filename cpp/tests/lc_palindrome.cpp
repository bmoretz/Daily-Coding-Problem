#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/palindrome.h"

namespace leetcode::palindrome::tests
{
    class longest_palindrome_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( longest_palindrome_tests, case1 )
    {
        const auto input = "babad";

        const auto actual = longest_palindrome::extract( input );
        const auto expected = "aba";
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_palindrome_tests, case2 )
    {
        const auto input = "ababad";

        const auto actual = longest_palindrome::extract( input );
        const auto expected = "ababa";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_palindrome_tests, case3 )
    {
        const auto input = "addeaababad";

        const auto actual = longest_palindrome::extract( input );
        const auto expected = "ababa";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_palindrome_tests, case4 )
    {
        const auto input = "deaaddeaababadazed";

        const auto actual = longest_palindrome::extract( input );
        const auto expected = "ababa";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_palindrome_tests, case5 )
    {
        const auto input = "b";

        const auto actual = longest_palindrome::extract( input );
        const auto expected = "b";

        EXPECT_EQ( actual, expected );
    }
}