#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/stack.h"

namespace leetcode::stack::tests
{
    class valid_parenthesis_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( valid_parenthesis_tests, case1 )
    {
        const auto input = "(*)))";

        const auto actual = valid_parenthesis::check_valid_string( input );
        const auto expected = false;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( valid_parenthesis_tests, case2 )
    {
        const auto input = "((((((*)))";

        const auto actual = valid_parenthesis::check_valid_string( input );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( valid_parenthesis_tests, case3 )
    {
        const auto input = "((((((*)))12121";

        const auto actual = valid_parenthesis::check_valid_string( input );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( valid_parenthesis_tests, case4 )
    {
        const auto input = "((((((*)))*****";

        const auto actual = valid_parenthesis::check_valid_string( input );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( valid_parenthesis_tests, case5 )
    {
        const auto input = "((((((*)))*****)))(";

        const auto actual = valid_parenthesis::check_valid_string( input );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( valid_parenthesis_tests, case6 )
    {
        const auto input = "((((((*)))*****)))(((";

        const auto actual = valid_parenthesis::check_valid_string( input );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( valid_parenthesis_tests, case7 )
    {
        const auto input = "(())((())()()(*)(*()(())())())()()((()())((()))(*";

        const auto actual = valid_parenthesis::check_valid_string( input );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    class basic_calculator_ii_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( basic_calculator_ii_tests, case1 )
    {
        const auto input = " 3+5 / 2 ";

        const auto actual = basic_calculator_ii::calculate( input );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( basic_calculator_ii_tests, case2 )
    {
        const auto input = "3+2*2";

        const auto actual = basic_calculator_ii::calculate( input );
        const auto expected = 7;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( basic_calculator_ii_tests, case3 )
    {
        const auto input = "3   +  2   * 2     *  -  5 +     120/  -56";

        const auto actual = basic_calculator_ii::calculate( input );
        const auto expected = -19;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( basic_calculator_ii_tests, case4 )
    {
        const auto input = " 3+5 / 2 ";

        const auto actual = basic_calculator_ii::calculate( input );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( basic_calculator_ii_tests, case5 )
    {
        const auto input = "0-2147483647";

        const auto actual = basic_calculator_ii::calculate( input );
        const auto expected = -2147483647;

        EXPECT_EQ( actual, expected );
    }

    class browser_history_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( browser_history_tests, case1 )
    {
        auto browserHistory = browser_history( "leetcode.com" );

        browserHistory.visit( "google.com" );
        browserHistory.visit( "facebook.com" );
        browserHistory.visit( "youtube.com" );
    	
        EXPECT_EQ( browserHistory.back( 1 ), "facebook.com" );
        EXPECT_EQ( browserHistory.back( 1 ), "google.com" );
        EXPECT_EQ( browserHistory.forward( 1 ) , "facebook.com" );

        browserHistory.visit( "linkedin.com" );
        browserHistory.forward( 2 );

        EXPECT_EQ( browserHistory.back( 2 ), "google.com" );
        EXPECT_EQ( browserHistory.back( 7 ), "leetcode.com" );
    }
}