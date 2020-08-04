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

    class group_anagrams_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( group_anagrams_tests, case1 )
    {
	    const auto sln = group_anagrams::group_anagrams1;
    	
        const auto input = std::vector<std::string>{ "eat", "tea", "tan", "ate", "nat", "bat" };

        const auto actual = sln( input );

        const auto expected = std::vector<std::vector<std::string>>{
        	{ "eat", "tea", "ate" },
        	{ "tan", "nat" },
            { "bat" }
        };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( group_anagrams_tests, case2 )
    {
        const auto sln = group_anagrams::group_anagrams1;

        const auto input = std::vector<std::string>{ "eat", "tab", "tea", "tan", "ate", "nat", "bat" };

        const auto actual = sln( input );

        const auto expected = std::vector<std::vector<std::string>>{
        	{ "eat", "tea", "ate" },
        	{ "tab", "bat" },
        	{ "tan", "nat" }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( group_anagrams_tests, case3 )
    {
        const auto sln = group_anagrams::group_anagrams1;

        const auto input = std::vector<std::string>{ "eat","tea","tan","ate","nat","bat", "" };

        const auto actual = sln( input );

        const auto expected = std::vector<std::vector<std::string>>{
            { "" },
        	{ "eat", "tea", "ate" },
        	{ "tan", "nat" }, { "bat" }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( group_anagrams_tests, case4 )
    {
        const auto sln = group_anagrams::group_anagrams1;

        const auto input = std::vector<std::string>{ "eat","tab", "tea","tan","ate","nat","bat", "bat", "101ab", "ab101" };

        const auto actual = sln( input );

        const auto expected = std::vector<std::vector<std::string>>{
            { "eat", "tea", "ate" },
        	{ "tab", "bat", "bat" },
        	{ "101ab", "ab101" },
        	{ "tan", "nat" }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( group_anagrams_tests, case5 )
    {
        const auto sln = group_anagrams::group_anagrams1;

        const auto input = std::vector<std::string>{ "eat","tab", "tea","tan","ate","nat","bat", "bat", "101ab", "ab101", "tab" };

        const auto actual = sln( input );

        const auto expected = std::vector<std::vector<std::string>>{
            { "eat", "tea", "ate" },
            { "tab", "bat", "bat", "tab" },
            { "101ab", "ab101" },
            { "tan", "nat" }
        };

        EXPECT_EQ( actual, expected );
    }

    class break_palindrome_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( break_palindrome_tests, case1 )
    {
        const auto input = "abccba";

        const auto actual = break_palindrome::break_palindrome1( input );
        const auto expected = "aaccba";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( break_palindrome_tests, case2 )
    {
        const auto input = "repaper";

        const auto actual = break_palindrome::break_palindrome1( input );
        const auto expected = "aepaper";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( break_palindrome_tests, case3 )
    {
        const auto input = "aba";

        const auto actual = break_palindrome::break_palindrome1( input );
        const auto expected = "abb";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( break_palindrome_tests, case4 )
    {
        const auto input = "a";

        const auto actual = break_palindrome::break_palindrome1( input );
        const auto expected = "";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( break_palindrome_tests, case5 )
    {
        const auto input = "acca";

        const auto actual = break_palindrome::break_palindrome1( input );
        const auto expected = "aaca";

        EXPECT_EQ( actual, expected );
    }

    class reverse_string_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( reverse_string_tests, case1 )
    { 
        auto input = std::string("       the    sky     is    blue            ");

        const auto actual = reverse_string::reverse_words( input );
        const auto expected = "blue is sky the";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_string_tests, case2 )
    {
        auto input = std::string( "hello world!" );

        const auto actual = reverse_string::reverse_words( input );
        const auto expected = "world! hello";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_string_tests, case3 )
    {
        auto input = std::string( "a good   example" );

        const auto actual = reverse_string::reverse_words( input );
        const auto expected = "example good a";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_string_tests, case4 )
    {
        auto input = std::string( "                   " );

        const auto actual = reverse_string::reverse_words( input );
        const auto expected = "";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_string_tests, case5 )
    {
        auto input = std::string( "                      blue               " );

        const auto actual = reverse_string::reverse_words( input );
        const auto expected = "blue";

        EXPECT_EQ( actual, expected );
    }
}