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

    class unique_occurrences_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( unique_occurrences_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 2, 2, 1, 1, 3 };

        const auto actual = unique_occurrences::unique( input );
        const auto expected = true;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( unique_occurrences_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 2, 2, 1, 1, 3, 3 };

        const auto actual = unique_occurrences::unique( input );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( unique_occurrences_tests, case3 )
    {
        const auto input = std::vector<int>{ 1, 2, 2, 1, 1, 3, 1, 2, 2 };

        const auto actual = unique_occurrences::unique( input );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( unique_occurrences_tests, case4 )
    {
        const auto input = std::vector<int>{ };

        const auto actual = unique_occurrences::unique( input );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( unique_occurrences_tests, case5 )
    {
        const auto input = std::vector<int>{ 1, 2, 2, 1, 1, 3 };

        const auto actual = unique_occurrences::unique( input );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    class common_characters_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( common_characters_tests, case1 )
    {
        const auto input = std::vector<std::string>
        {
            "bella",
            "label",
            "roller"
        };

        const auto actual = common_characters::find_common( input );
        const auto expected = std::vector<std::string>{ "e", "l", "l" };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( common_characters_tests, case2 )
    {
        const auto input = std::vector<std::string>
        {
	        "cool",
	        "lock",
	        "cook"
        };

        const auto actual = common_characters::find_common( input );
        const auto expected = std::vector<std::string>{ "c", "o" };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( common_characters_tests, case3 )
    {
        const auto input = std::vector<std::string>
        {
	        "acabcddd",
	        "bcbdbcbd",
	        "baddbadb",
	        "cbdddcac",
	        "aacbcccd",
	        "ccccddda",
	        "cababaab",
	        "addcaccd"
        };

        const auto actual = common_characters::find_common( input );
        const auto expected = std::vector<std::string>{ };

        EXPECT_EQ( actual, expected );
    }

    class roman_to_integer_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( roman_to_integer_tests, case1 )
    {
        const auto actual = roman_to_integer::roman_to_int( "III" );
        const auto expected = 3;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( roman_to_integer_tests, case2 )
    {
        const auto actual = roman_to_integer::roman_to_int( "IV" );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( roman_to_integer_tests, case3 )
    {
        const auto actual = roman_to_integer::roman_to_int( "LXV" );
        const auto expected = 65;

        EXPECT_EQ( actual, expected );
    }

    class happy_number_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( happy_number_tests, case1 )
    {
        const auto actual = happy_number::is_happy( 19 );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( happy_number_tests, case2 )
    {
        const auto actual = happy_number::is_happy( 89 );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( happy_number_tests, case3 )
    {
        const auto actual = happy_number::is_happy( 2 );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    class group_shifted_sequence_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( group_shifted_sequence_tests, case1 )
    {
        const auto input = std::vector<std::string>{ "aa","bb","b" };

        auto actual = group_shifted_sequence::groupStrings( input );

        const auto expected = std::vector<std::vector<std::string>>{ { "b" }, { "aa","bb" } };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( group_shifted_sequence_tests, case2 )
    {
        const auto input = std::vector<std::string>{ "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };

        auto actual = group_shifted_sequence::groupStrings( input );

        const auto expected = std::vector<std::vector<std::string>>{
        	{ "a","z" },
        	{ "abc","bcd","xyz" },
        	{ "acef" },
            { "az","ba" }
        };

        EXPECT_EQ( actual, expected );
    }
}