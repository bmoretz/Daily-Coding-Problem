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
}