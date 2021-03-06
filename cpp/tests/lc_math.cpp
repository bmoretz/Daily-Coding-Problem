#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/math.h"

namespace leetcode::math::tests
{
    class min_moves_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( min_moves_tests, case1 )
    {
        auto input = std::vector<int>{ 1, 2, 3 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case2 )
    {
        auto input = std::vector<int>{ 1, 6, 2, 4 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 7;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case3 )
    {
        auto input = std::vector<int>{ 1, 0, 0, 8, 6 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 14;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case4 )
    {
        auto input = std::vector<int>{ 203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 2127271182;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( min_moves_tests, case5 )
    {
        auto input = std::vector<int>{ 1 };

        const auto actual = min_moves::min_moves2( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    class number_of_1s_substrings_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( number_of_1s_substrings_tests, case1 )
    {
        const auto input = "0110111";

        const auto actual = number_of_1s_substrings::number_of_subgroups( input );
        const auto expected = 9;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case2 )
    {
        const auto input = "101";

        const auto actual = number_of_1s_substrings::number_of_subgroups( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case3 )
    {
        const auto input = "111111";

        const auto actual = number_of_1s_substrings::number_of_subgroups( input );
        const auto expected = 21;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case4 )
    {
        const auto input = "000";

        const auto actual = number_of_1s_substrings::number_of_subgroups( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_1s_substrings_tests, case5 )
    {
        const auto input = "0101111111010111101111111111111111111111011111111111111111111111111111111111";

        const auto actual = number_of_1s_substrings::number_of_subgroups( input );
        const auto expected = 923;

        EXPECT_EQ( actual, expected );
    }

    class fibonacci_number_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( fibonacci_number_tests, case1 )
    {
        const auto input = 0;

        const auto actual = fibonacci_number::fib1( input );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case2 )
    {
        const auto input = 5;

        const auto actual = fibonacci_number::fib1( input );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case3 )
    {
        const auto input = 10;

        const auto actual = fibonacci_number::fib1( input );
        const auto expected = 55;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case4 )
    {
        const auto input = 20;

        const auto actual = fibonacci_number::fib1( input );
        const auto expected = 6765;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( fibonacci_number_tests, case5 )
    {
        const auto input = 30;

        const auto actual = fibonacci_number::fib1( input );
        const auto expected = 832040;

        EXPECT_EQ( actual, expected );
    }

    class reach_number_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( reach_number_tests, case1 )
    {
        const auto actual = reach_a_number::reach_number( 3 );
        const auto expected = 2;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( reach_number_tests, case2 )
    {
        const auto actual = reach_a_number::reach_number( 2 );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reach_number_tests, case3 )
    {
        const auto actual = reach_a_number::reach_number( 6 );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reach_number_tests, case4 )
    {
        const auto actual = reach_a_number::reach_number( 10 );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reach_number_tests, case5 )
    {
        const auto actual = reach_a_number::reach_number( 56 );
        const auto expected = 11;

        EXPECT_EQ( actual, expected );
    }

    class similar_color_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( similar_color_tests, case1 )
    {
        const auto input = "#09f166";

        const auto actual = similar_color::similar_rgb( input );
        const auto expected = "#11ee66";
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( similar_color_tests, case2 )
    {
        const auto input = "#09a191";

        const auto actual = similar_color::similar_rgb( input );
        const auto expected = "#119999";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( similar_color_tests, case3 )
    {
        const auto input = "#ffa31";

        const auto actual = similar_color::similar_rgb( input );
        const auto expected = "#ffaa00";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( similar_color_tests, case4 )
    {
        const auto input = "#ca1d3d";

        const auto actual = similar_color::similar_rgb( input );
        const auto expected = "#cc2244";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( similar_color_tests, case5 )
    {
        const auto input = "#09f166";

        const auto actual = similar_color::similar_rgb( input );
        const auto expected = "#11ee66";

        EXPECT_EQ( actual, expected );
    }

    class no_zero_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( no_zero_tests, case1 )
    {
        const auto input = "#09f166";

        const auto actual = similar_color::similar_rgb( input );
        const auto expected = "#11ee66";

        EXPECT_EQ( actual, expected );
    }

    class maximum_abs_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( maximum_abs_tests, case1 )
    {
        const auto arr1 = std::vector<int>{ 1, 2, 3, 4 };
        const auto arr2 = std::vector<int>{ -1, 4, 5, 6 };

        const auto actual = maximum_abs::max_abs_val_expr( arr1, arr2 );
        const auto expected = 13;
    	
        EXPECT_EQ( actual, expected );
    }

    class range_sum_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( range_sum_tests, case1 )
    {
        const auto operations = std::vector<std::vector<int>>{
            {1,3,2}, {2,4,3}, {0,2,-2}
        };

        auto actual = range_addition::get_modified_array( 5, operations );
        const auto expected = std::vector<int>{ -2, 0, 3, 5, 3 };

        EXPECT_EQ( actual, expected );
    }
}