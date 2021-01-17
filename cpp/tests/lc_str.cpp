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

    class reverse_words_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( reverse_words_tests, case1 )
    { 
        auto input = std::string("       the    sky     is    blue            ");

        const auto actual = word_reverser::reverse_words( input );
        const auto expected = "blue is sky the";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_words_tests, case2 )
    {
        auto input = std::string( "hello world!" );

        const auto actual = word_reverser::reverse_words( input );
        const auto expected = "world! hello";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_words_tests, case3 )
    {
        auto input = std::string( "a good   example" );

        const auto actual = word_reverser::reverse_words( input );
        const auto expected = "example good a";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_words_tests, case4 )
    {
        auto input = std::string( "                   " );

        const auto actual = word_reverser::reverse_words( input );
        const auto expected = "";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_words_tests, case5 )
    {
        auto input = std::string( "                      blue               " );

        const auto actual = word_reverser::reverse_words( input );
        const auto expected = "blue";

        EXPECT_EQ( actual, expected );
    }

    class log_reorder_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( log_reorder_tests, case1 )
    {
        auto input = std::vector<std::string>{
            "dig1 8 1 5 1",
            "let1 art can",
            "dig2 3 6",
            "let2 own kit dig",
            "let3 art zero"
        };

        const auto actual = log_reorder::reorder_log_files( input );
        const auto expected = std::vector<std::string>
    	{
			"let1 art can",
    		"let3 art zero",
    		"let2 own kit dig",
    		"dig1 8 1 5 1",
    		"dig2 3 6"
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( log_reorder_tests, case2 )
    {
    	
        auto input = std::vector<std::string>{
	        "dig1 8 1 5 1",
	        "let1 art can",
	        "dig2 3 6",
	        "let2 own kit dig",
	        "let3 art zero",
        	"art0 a new type of art"
        };

        const auto actual = log_reorder::reorder_log_files( input );
        const auto expected = std::vector<std::string>
        {
			"art0 a new type of art",
        	"let1 art can",
        	"let3 art zero",
        	"let2 own kit dig",
        	"dig1 8 1 5 1",
        	"dig2 3 6"
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( log_reorder_tests, case3 )
    {
        auto input = std::vector<std::string>{
            "dig1 8 1 5 1",
            "let1 art can",
            "dig2 3 6",
            "let2 own kit dig",
            "let3 art zero",
            "digit3 4 9 1 3",
            "art1 life is a garden",
            "dig1 it"
        };

        const auto actual = log_reorder::reorder_log_files( input );
        const auto expected = std::vector<std::string>
        {
        	"let1 art can",
        	"let3 art zero",
        	"dig1 it",
        	"art1 life is a garden",
        	"let2 own kit dig",
        	"dig1 8 1 5 1",
        	"dig2 3 6",
        	"digit3 4 9 1 3"
        };

        EXPECT_EQ( actual, expected );
    }

    class bold_words_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( bold_words_tests, case1 )
    {
        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            { "ab", "bc" },
            "aabcd"
        };

        const auto actual = bold_words::bold( input.first, input.second );
        const auto expected = "a<b>abc</b>d";
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( bold_words_tests, case2 )
    {
        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            { "ab", "bc", "ed" },
            "aabcdaeed"
        };

        const auto actual = bold_words::bold( input.first, input.second );
        const auto expected = "a<b>abc</b>dae<b>ed</b>";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( bold_words_tests, case3 )
    {
        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            { "ab", "bc", "ed" },
            "aabcdaeed"
        };

        const auto actual = bold_words::bold( input.first, input.second );
        const auto expected = "a<b>abc</b>dae<b>ed</b>";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( bold_words_tests, case4 )
    {
        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            { "aaa", "aab", "bc" },
            "aaabbcciq"
        };

        const auto actual = bold_words::bold( input.first, input.second );
        const auto expected = "<b>aaabbc</b>ciq";

        EXPECT_EQ( actual, expected );
    }
	
    TEST_F( bold_words_tests, case5 )
    {
        const auto input = std::pair<std::vector<std::string>, std::string>
        {
            { "aaa", "aab", "bc", "ef" },
            "aaabbcciqjewefae"
        };

        const auto actual = bold_words::bold( input.first, input.second );
        const auto expected = "<b>aaabbc</b>ciqjew<b>ef</b>ae";

        EXPECT_EQ( actual, expected );
    }

    class most_common_word_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( most_common_word_tests, case1 )
    {
        const auto input = std::pair<std::string, std::vector<std::string>>
        {
            "Bob hit a ball, the hit BALL flew far after it was hit.",
            std::vector<std::string>{ "hit" }
        };

        const auto actual = most_common_word::get_most_common( input.first, input.second );
        const auto expected = "ball";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( most_common_word_tests, case2 )
    {
        const auto input = std::pair<std::string, std::vector<std::string>>
        {
            "B.",
            std::vector<std::string>{ "hit" }
        };

        const auto actual = most_common_word::get_most_common( input.first, input.second );
        const auto expected = "b";

        EXPECT_EQ( actual, expected );
    }

    class minimum_window_substring_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( minimum_window_substring_tests, case1 )
    {
        const auto input1 = std::pair<std::string, std::string>( "ADOBECODEBANC", "ABC" );
        const auto actual = minimum_window_substring::min_window( input1.first, input1.second );

        const auto expected = "BANC";
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( minimum_window_substring_tests, case2 )
    {
        const auto input1 = std::pair<std::string, std::string>( "abc", "b" );
        const auto actual = minimum_window_substring::min_window( input1.first, input1.second );

        const auto expected = "b";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( minimum_window_substring_tests, case3 )
    {
        const auto input1 = std::pair<std::string, std::string>( "a", "a" );
        const auto actual = minimum_window_substring::min_window( input1.first, input1.second );

        const auto expected = "a";

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
        auto actual = std::vector<char>{ 'h', 'e', 'l', 'l', 'o' };

        reverse_string::reverse( actual );

        const auto expected = std::vector<char>{ 'o', 'l', 'l', 'e', 'h' };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_string_tests, case2 )
    {
        auto actual = std::vector<char>{ 'h' };

        reverse_string::reverse( actual );

        const auto expected = std::vector<char>{ 'h' };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reverse_string_tests, case3 )
    {
        auto actual = std::vector<char>{ 'h', 'e', 'l' };

        reverse_string::reverse( actual );

        const auto expected = std::vector<char>{ 'l', 'e', 'h' };

        EXPECT_EQ( actual, expected );
    }

    class longest_common_prefix_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( longest_common_prefix_tests, case1 )
    {
        const auto input = std::vector<std::string>{ "flower", "flow", "flight" };

        const auto actual = longest_common_prefix::max_common_prefix( input );

        const auto expected = "fl";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_common_prefix_tests, case2 )
    {
        const auto input = std::vector<std::string>{ "dog", "racecar", "car" };

        const auto actual = longest_common_prefix::max_common_prefix( input );

        const auto expected = "";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( longest_common_prefix_tests, case3 )
    {
        const auto input = std::vector<std::string>{ };

        const auto actual = longest_common_prefix::max_common_prefix( input );

        const auto expected = "";

        EXPECT_EQ( actual, expected );
    }
}
