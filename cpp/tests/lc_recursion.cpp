#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/recursion.h"

namespace leetcode::recursion::tests
{
    class phone_book_combinations_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( phone_book_combinations_tests, case1 )
    {
        const auto actual = phone_book_combinations::letter_combinations( "23" );

        const auto expected = std::vector<std::string>{
            "ad","ae","af","bd","be","bf","cd","ce","cf"
        };
    	
        EXPECT_EQ( actual, expected );
    }

    class gen_parenthesis_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( gen_parenthesis_tests, case1_rec )
    {
        const auto actual = gen_parenthesis::generate_parenthesis( 3 );

        const auto expected = std::vector<std::string>
        {
            "((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( gen_parenthesis_tests, case1_iter )
    {
        const auto actual = gen_parens_iter::generate_parenthesis( 3 );

        const auto expected = std::vector<std::string>
        {
            "((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"
        };

        EXPECT_EQ( actual, expected );
    }
	
    class number_to_english_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( number_to_english_tests, case1 )
    {
        const auto input = 1234567891;
        auto actual = number_to_english::number_to_words( input );

        const auto expected = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";

        EXPECT_EQ( actual, expected );
    }

    class target_sum_rec_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( target_sum_rec_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 1, 1, 1, 1 };

        const auto actual = target_sum_rec::find_target_sum_ways( input, 3 );
        const auto expected = 5;
    	
        EXPECT_EQ( actual, expected );
    }
}