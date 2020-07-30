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
        const auto input = std::vector<std::string>{ "1", "2", "3", "4", "", "4", "", "", "4" };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();
    	
        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );
    	
        EXPECT_EQ( actual.at( 0 )->val, 4 );
    }

    TEST_F( dup_substrees_tests, case2 )
    {
        const auto input = std::vector<std::string>{ "1", "2", "3", "4", "", "2", "4", "", "", "4" };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 2 );
    	
        EXPECT_EQ( actual.at( 0 )->val, 4 );
    }

    TEST_F( dup_substrees_tests, case3 )
    {
        const auto input = std::vector<std::string>{ "2", "1", "1" };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );
    	
        EXPECT_EQ( actual.at( 0 )->val, 1 );
    }

    TEST_F( dup_substrees_tests, case4 )
    {
        const auto input = std::vector<std::string>{ "1", "2", "3", "", "", "2", "3" };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );

        EXPECT_EQ( actual.at( 0 )->val, 2 );
    }

    TEST_F( dup_substrees_tests, case5 )
    {
        const auto input = std::vector<std::string>{ "1", "2", "3", "4", "", "2", "4", "2", "4" };

        const auto tree = find_dup_subtrees::build_tree( input );

        auto find_dupes = find_dup_subtrees();

        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 2 );

        EXPECT_EQ( actual.at( 0 )->val, 2 );
        EXPECT_EQ( actual.at( 1 )->val, 4 );
    }

    class level_order_ii_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( level_order_ii_tests, case1 )
    {
        const auto input = std::vector<std::string>{ "3", "9", "20", "", "", "15", "7" };

        const auto tree = level_order_ii::build_tree( input );
        const auto actual = level_order_ii::level_order_bottom( tree.get() );

        const auto expected = std::vector<std::vector<int>>
    	{
            { 15, 7 },
            { 9, 20 },
            { 3 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( level_order_ii_tests, case2 )
    {
        const auto input = std::vector<std::string>{ "3", "9" };

        const auto tree = level_order_ii::build_tree( input );
        const auto actual = level_order_ii::level_order_bottom( tree.get() );

        const auto expected = std::vector<std::vector<int>>
    	{
            { 9 },
            { 3 },
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( level_order_ii_tests, case3 )
    {
        const auto input = std::vector<std::string>{ "3", "9", "20", "", "", "15", "7", "", "1", "", "", "1" };

        const auto tree = level_order_ii::build_tree( input );
        const auto actual = level_order_ii::level_order_bottom( tree.get() );

        const auto expected = std::vector<std::vector<int>>
        {
            { 1 },
            { 1 },
            { 15, 7 },
            { 9, 20 },
            { 3 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( level_order_ii_tests, case4 )
    {
        const auto input = std::vector<std::string>{ "0", "2", "4", "1", "", "3", "-1", "5", "1", "", "6", "", "8" };

        const auto tree = level_order_ii::build_tree( input );
        const auto actual = level_order_ii::level_order_bottom( tree.get() );

        const auto expected = std::vector<std::vector<int>>
        {
            { 5, 1, 6, 8 },
            { 1, 3, -1 },
            { 2, 4 },
            { 0 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( level_order_ii_tests, case5 )
    {
        const auto input = std::vector<std::string>{ "0", "2", "4" , "1", "", "3", "-1", "5", "1", "", "6", "", "8" };

        const auto tree = level_order_ii::build_tree( input );
        const auto actual = level_order_ii::level_order_bottom( tree.get() );

        const auto expected = std::vector<std::vector<int>>
        {
        	{ 5, 1, 6, 8 },
        	{ 1, 3, -1 },
        	{ 2, 4 },
        	{ 0 }
        };

        EXPECT_EQ( actual, expected );
    }
}