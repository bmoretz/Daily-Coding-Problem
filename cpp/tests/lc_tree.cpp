#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/tree.h"

namespace leetcode::tree::tests
{
    class dup_substrees_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( dup_substrees_tests, case1 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, 4, NULL, 4, NULL, NULL, 4 };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();
    	
        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 2 );
    	
        EXPECT_EQ( actual.at( 0 )->val, 0 );
        EXPECT_EQ( actual.at( 1 )->val, 4 );
    }

    TEST_F( dup_substrees_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, 4, NULL, 2, 4, NULL, NULL, 4 };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 2 );
    	
        EXPECT_EQ( actual.at( 0 )->val, 0 );
        EXPECT_EQ( actual.at( 1 )->val, 4 );
    }

    TEST_F( dup_substrees_tests, case3 )
    {
        const auto input = std::vector<int>{ 2, 1, 1 };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );
    	
        EXPECT_EQ( actual.at( 0 )->val, 1 );
    }

    TEST_F( dup_substrees_tests, case4 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, NULL, NULL, 2, 3 };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );

        EXPECT_EQ( actual.at( 0 )->val, 0 );
    }

    TEST_F( dup_substrees_tests, case5 )
    {
        const auto input = std::vector<int>{ 1, 2, 3, 4, NULL, 2, 4, 2, 4 };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 2 );

        EXPECT_EQ( actual.at( 0 )->val, 2 );
        EXPECT_EQ( actual.at( 1 )->val, 4 );
    }
}