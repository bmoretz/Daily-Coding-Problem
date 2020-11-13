#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/trie.h"

namespace leetcode::trie::tests
{
    class trie_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( trie_tests, case1 )
    {
        auto searcher = trie();
    	
        searcher.insert( "apple" );
    	
        EXPECT_EQ( searcher.search( "apple" ), true );
        EXPECT_EQ( searcher.search( "app" ), false );

        EXPECT_EQ( searcher.starts_with( "app" ), true );
    	
        searcher.insert( "app" );
        EXPECT_EQ( searcher.search( "app" ), true );
    }

    class word_search_ii_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( word_search_ii_tests, case1 )
    {
        const auto board = std::vector<std::vector<char>>
        {
            { 'o', 'a', 'a', 'n' },
            { 'e', 't', 'a', 'e' },
            { 'i', 'h', 'k', 'r' },
            { 'i', 'f', 'l', 'v' }
        };

        const auto to_find = std::vector<std::string>
        {
            "oath", "pea", "eat", "rain"
        };

        const auto actual = word_search_ii::find_words( board, to_find );

        const auto expected = std::vector<std::string>
    	{
            "oath", "eat"
        };

        EXPECT_EQ( actual, expected );
    }

    class replace_words_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( replace_words_tests, case1 )
    {
        const auto replacer = replace_words();

        const auto input = std::vector<std::string>{ "a", "aa", "aaa", "aaaa" };

        const auto actual = replacer.replaceWords( input, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa" );

        const auto expected = "a a a a a a a a bbb baba a";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( replace_words_tests, case2 )
    {
        const auto replacer = replace_words();

        const auto input = std::vector<std::string>{ "cat","bat","rat" };

        const auto actual = replacer.replaceWords( input, "the cattle was rattled by the battery" );

        const auto expected = "the cat was rat by the bat";

        EXPECT_EQ( actual, expected );
    }

    class word_searcher_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( word_searcher_tests, case1 )
    {
        const auto searcher = word_dictionary();

        searcher.add_word( "bad" );
        searcher.add_word( "dad" );
        searcher.add_word( "mad" );

        {
            const auto actual = searcher.search( "pad" );
            const auto expected = false;
        	
            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = searcher.search( "bad" );
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = searcher.search( ".ad" );
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }

        {
            const auto actual = searcher.search( "..d" );
            const auto expected = true;

            EXPECT_EQ( actual, expected );
        }
    }
}