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

    class stock_spanner_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( stock_spanner_tests, case1 )
    {
        auto spanner = stock_spanner();

        EXPECT_EQ( spanner.next( 100 ), 1 );
        EXPECT_EQ( spanner.next( 80 ), 1 );
        EXPECT_EQ( spanner.next( 60 ), 1 );
        EXPECT_EQ( spanner.next( 70 ), 2 );
        EXPECT_EQ( spanner.next( 60 ), 1 );
        EXPECT_EQ( spanner.next( 75 ), 4 );
        EXPECT_EQ( spanner.next( 85 ), 6 );
    }

    class daily_temperatures_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( daily_temperatures_tests, case1 )
    {
        const auto input = std::vector<int>{ 73, 74, 75, 71, 69, 72, 76, 73 };

        const auto actual = next_hottest_temperature::daily_temperatures( input );
        const auto expected = std::vector<int>{ 1, 1, 4, 2, 1, 1, 0, 0 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( daily_temperatures_tests, case2 )
    {
        const auto input = std::vector<int>{ 73, 74, 75, 66, 69, 72, 81, 73 };

        const auto actual = next_hottest_temperature::daily_temperatures( input );
        const auto expected = std::vector<int>{ 1, 1, 4, 1, 1, 1, 0, 0 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( daily_temperatures_tests, case3 )
    {
        const auto input = std::vector<int>{ 73, 74, 75, 71, 69, 72, 76, 73, 83, 91, 84 };

        const auto actual = next_hottest_temperature::daily_temperatures( input );
        const auto expected = std::vector<int>{ 1, 1, 4, 2, 1, 1, 2, 1, 1, 0, 0 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( daily_temperatures_tests, case4 )
    {
        const auto input = std::vector<int>{ 73, 74, 75, 71, 69, 72, 76, 73 };

        const auto actual = next_hottest_temperature::daily_temperatures( input );
        const auto expected = std::vector<int>{ 1, 1, 4, 2, 1, 1, 0, 0 };

        EXPECT_EQ( actual, expected );
    }

    class evaluate_rpn_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( evaluate_rpn_tests, case1 )
    {
        const auto actual = evaluate_rpn::eval_rpn( { "2", "1", "+", "3", "*" } );
        const auto expected = 9;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( evaluate_rpn_tests, case2 )
    {
        const auto actual = evaluate_rpn::eval_rpn( { "4", "13", "5", "/", "+" } );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    class num_islands_bfs_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( num_islands_bfs_tests, case1 )
    {
        const auto input = std::vector<std::vector<char>>
        {
            {'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},
            {'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},
            {'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},
            {'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},
            {'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'}
        };

        const auto actual = num_islands_dfs::num_islands( input );

        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    class string_decoder_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( string_decoder_tests, case1 )
    {
        const auto input = "abc3[cd]xyz";

        const auto actual = string_decoder::decode_string( input );
        const auto expected = "abccdcdcdxyz";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_decoder_tests, case2 )
    {
        const auto input = "2[abc]3[cd]ef";

        const auto actual = string_decoder::decode_string( input );
        const auto expected = "abcabccdcdcdef";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_decoder_tests, case3 )
    {
        const auto input = "3[a2[c]]";

        auto actual = string_decoder::decode_string( input );
        auto expected = "accaccacc";

        EXPECT_EQ( actual, expected );
    }
}