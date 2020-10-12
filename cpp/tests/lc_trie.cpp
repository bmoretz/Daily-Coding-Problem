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
}