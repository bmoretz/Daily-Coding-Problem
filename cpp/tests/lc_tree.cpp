#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/tree.h"

namespace leetcode::tree::tests
{
    class dup_subtrees_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( dup_subtrees_tests, case1 )
    {
        const auto input = std::vector<std::string>{ "1", "2", "3", "4", "", "4", "", "", "4" };
        const auto tree = build_tree_in_order( input );
    	
        auto find_dupes = find_dup_subtrees();
        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );
        EXPECT_EQ( actual.at( 0 )->val, 4 );
    }

    TEST_F( dup_subtrees_tests, case2 )
    {
        const auto input = std::vector<std::string>{ "1", "2", "3", "4", "", "2", "4", "", "", "4" };
        const auto tree = build_tree_in_order( input );
    	
        auto find_dupes = find_dup_subtrees();
        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 2 );
    	
        EXPECT_EQ( actual.at( 0 )->val, 4 );
    }

    TEST_F( dup_subtrees_tests, case3 )
    {
        const auto input = std::vector<std::string>{ "2", "1", "1" };
        const auto tree = build_tree_in_order( input );

        auto find_dupes = find_dup_subtrees();
        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );
        EXPECT_EQ( actual.at( 0 )->val, 1 );
    }

    TEST_F( dup_subtrees_tests, case4 )
    {
        const auto input = std::vector<std::string>{ "1", "2", "3", "", "", "2", "3" };
        const auto tree = build_tree_in_order( input );
    	
        auto find_dupes = find_dup_subtrees();
        const auto actual = find_dupes.find_duplicate_subtrees( tree.get() );

        EXPECT_EQ( actual.size(), 1 );
        EXPECT_EQ( actual.at( 0 )->val, 2 );
    }

    TEST_F( dup_subtrees_tests, case5 )
    {
        const auto input = std::vector<std::string>{ "1", "2", "3", "4", "", "2", "4", "2", "4" };
        const auto tree = build_tree_in_order( input );

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
        const auto tree = build_tree_in_order( input );

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
        const auto tree = build_tree_in_order( input );

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
        const auto tree = build_tree_in_order( input );

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
        const auto tree = build_tree_in_order( input );

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
        const auto tree = build_tree_in_order( input );
    	
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

    class lowest_common_ancestor_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( lowest_common_ancestor_tests, case1 )
    {
        const auto root = build_tree_in_order( {
			"1", "2", "3", "4"
		} );

        const auto lca = lowest_common_ancestor::lca_deepest_leaves( root.get() );

        const auto actual = flatten_tree( lca );
        const auto expected = std::vector<std::string>{ "4" };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( lowest_common_ancestor_tests, case2 )
    {
        const auto root = build_tree_in_order( {
			"1", "2", "3"
		} );

        const auto lca = lowest_common_ancestor::lca_deepest_leaves( root.get() );

        const auto actual = flatten_tree( lca );
        const auto expected = std::vector<std::string>{ "1", "2", "3" };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( lowest_common_ancestor_tests, case3 )
    {
        const auto root = build_tree_in_order( {
			"1", "2", "3", "4", "5"
        } );

        const auto lca = lowest_common_ancestor::lca_deepest_leaves( root.get() );

        const auto actual = flatten_tree( lca );
        const auto expected = std::vector<std::string>{ "2", "4", "5" };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( lowest_common_ancestor_tests, case4 )
    {
        const auto root = build_tree_in_order( {
			"1", "2", "", "3", "4", "", "6", "", "5"
		} );

        const auto lca = lowest_common_ancestor::lca_deepest_leaves( root.get() );

        const auto actual = flatten_tree( lca );
        const auto expected = std::vector<std::string>{ "2", "3", "4", "", "6", "", "5" };

        EXPECT_EQ( actual, expected );
    }
	
    TEST_F( lowest_common_ancestor_tests, case5 )
    {
        const auto root = build_tree_in_order( {
                "1", "2", "", "3", "4", "", "6", "", "5"
		} );

        const auto lca = lowest_common_ancestor::lca_deepest_leaves( root.get() );

        const auto actual = flatten_tree( lca );
        const auto expected = std::vector<std::string>{ "2", "3", "4", "", "6", "", "5" };

        EXPECT_EQ( actual, expected );
    }
}