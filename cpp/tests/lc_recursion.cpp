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
}