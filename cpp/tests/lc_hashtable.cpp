#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/hashtable.h"

namespace leetcode::hashtable::tests
{
    class element_with_most_appearances_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( element_with_most_appearances_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 2, 2, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case3 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case4 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 3, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( element_with_most_appearances_tests, case5 )
    {
        const auto input = std::vector<int>{ 1, 1, 2, 2, 3, 3, 3 };

        const auto actual = element_with_most_appearances::find_special_integer( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    class visitor_patterns_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( visitor_patterns_tests, case1 )
    {
        const auto input = std::tuple<std::vector<std::string>, std::vector<int>, std::vector<std::string>>
        {
            { "joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"},
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
            { "home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career" }
        };

        const auto actual = visitor_patterns::most_visited_pattern(
            std::get<0>( input ),
            std::get<1>( input ),
            std::get<2>( input )
        );
    	
        const auto expected = std::vector<std::string>{ "home", "about", "career" };

        EXPECT_EQ( actual, expected );
    }
}