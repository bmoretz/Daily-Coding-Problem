#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../problems/tree.h"

using namespace tree_problems;

namespace tree_tests
{
    /// <summary>
    /// Testing class for min tree.
    /// </summary>
    class min_tree_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    //
    // Min Tree
    //

    TEST_F( min_tree_tests, min_tree_empty )
    {
    	const auto tree = min_tree{ { } };
    	
        const auto actual = tree.depth();
        const auto expected = 0;
    }

    TEST_F( min_tree_tests, min_tree_case1 )
    {
        const auto tree = min_tree{1};

        const auto actual = tree.depth();
        const auto expected = 1;
    }

    TEST_F( min_tree_tests, min_tree_case2 )
    {
        const auto tree = min_tree{ 1, 2, 3 };

        const auto actual = tree.depth();
        const auto expected = 2;
    }

    TEST_F( min_tree_tests, min_tree_case3 )
    {
        const auto tree = min_tree{ 1, 2, 3, 4 };

        const auto actual = tree.depth();
        const auto expected = 3;
    }

    TEST_F( min_tree_tests, min_tree_case4 )
    {
        const auto tree = min_tree{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        const auto actual = tree.depth();
        const auto expected = 4;
    }

    TEST_F( min_tree_tests, min_tree_case5 )
    {
        const auto tree = min_tree{ 1, 3, 5, 7, 8, 9 };

        const auto actual = tree.depth();
        const auto expected = 3;
    }

    /// <summary>
    /// Testing class for depth list.
    /// </summary>
    class depth_list_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    //
    // Depth List (bfs)
    //

    TEST_F( depth_list_tests, depth_list_bfs_empty )
    {
        const auto tree = list_of_depths{ };

        const auto node_list = tree.build_node_list_bfs();

        EXPECT_EQ( node_list->size(), 0 );
    }

    TEST_F( depth_list_tests, depth_list_bfs_case1 )
    {
        const auto tree = list_of_depths{ 1, 2, 3, 4, 5, 6, 7 };

        const auto node_list = tree.build_node_list_bfs();

        EXPECT_EQ( node_list->size(), tree.depth() );

    	// Level 1: 0 (sentinel), 4
        auto actual_level_zero = std::vector<int>{ };
    	
        auto level_zero_node = node_list->at( 0 ).get();

    	while( level_zero_node )
    	{
            actual_level_zero.push_back( level_zero_node->value );
            level_zero_node = level_zero_node->next.get();
    	}

        const auto expected_level_zero = std::vector<int>{ 0, 4 };

        EXPECT_EQ( actual_level_zero, expected_level_zero );

        // Level 2: 0 (sentinel), 2, 6

        auto actual_level_one = std::vector<int>{ };
    	
        auto level_one_node = node_list->at( 1 ).get();

        while( level_one_node )
        {
            actual_level_one.push_back( level_one_node->value );
            level_one_node = level_one_node->next.get();
        }

        const auto expected_level_one = std::vector<int>{ 0, 2, 6 };

        EXPECT_EQ( actual_level_one, expected_level_one );

        // Level 3: 0 (sentinel), 1, 3, 5, 7

        auto actual_level_two = std::vector<int>{ };

        auto level_two_node = node_list->at( 2 ).get();

        while( level_two_node )
        {
            actual_level_two.push_back( level_two_node->value );
            level_two_node = level_two_node->next.get();
        }

        const auto expected_level_two = std::vector<int>{ 0, 1, 3, 5, 7 };

        EXPECT_EQ( actual_level_two, expected_level_two );
    }

    TEST_F( depth_list_tests, depth_list_bfs_case2 )
    {
        const auto tree = list_of_depths{ 1, 2, 3, 4, 5, 6, 7, 8 };

        const auto node_list = tree.build_node_list_bfs();

        EXPECT_EQ( node_list->size(), tree.depth() );

        // Level 1: 0 (sentinel), 5
        auto actual_level_zero = std::vector<int>{ };

        auto level_zero_node = node_list->at( 0 ).get();

        while( level_zero_node )
        {
            actual_level_zero.push_back( level_zero_node->value );
            level_zero_node = level_zero_node->next.get();
        }

        const auto expected_level_zero = std::vector<int>{ 0, 5 };

        EXPECT_EQ( actual_level_zero, expected_level_zero );

        // Level 2: 0 (sentinel), 3, 7

        auto actual_level_one = std::vector<int>{ };

        auto level_one_node = node_list->at( 1 ).get();

        while( level_one_node )
        {
            actual_level_one.push_back( level_one_node->value );
            level_one_node = level_one_node->next.get();
        }

        const auto expected_level_one = std::vector<int>{ 0, 3, 7 };

        EXPECT_EQ( actual_level_one, expected_level_one );

        // Level 3: 0 (sentinel), 1, 3, 5, 7

        auto actual_level_two = std::vector<int>{ };

        auto level_two_node = node_list->at( 2 ).get();

        while( level_two_node )
        {
            actual_level_two.push_back( level_two_node->value );
            level_two_node = level_two_node->next.get();
        }

        const auto expected_level_two = std::vector<int>{ 0, 2, 4, 6, 8 };

        EXPECT_EQ( actual_level_two, expected_level_two );

        // Level 4: 0 (sentinel), 1

        auto actual_level_three = std::vector<int>{ };

        auto level_three_node = node_list->at( 3 ).get();

        while( level_three_node )
        {
            actual_level_three.push_back( level_three_node->value );
            level_three_node = level_three_node->next.get();
        }

        const auto expected_level_three = std::vector<int>{ 0, 1 };

        EXPECT_EQ( actual_level_three, expected_level_three );
    }


    //
    // Depth List (dfs)
    //

    TEST_F( depth_list_tests, depth_list_dfs_empty )
    {
        const auto tree = list_of_depths{ };

        const auto node_list = tree.build_node_list_dfs();

        EXPECT_EQ( node_list->size(), 0 );
    }

    TEST_F( depth_list_tests, depth_list_dfs_case1 )
    {
        const auto tree = list_of_depths{ 1, 2, 3, 4, 5, 6, 7 };

        const auto node_list = tree.build_node_list_dfs();

        EXPECT_EQ( node_list->size(), tree.depth() );

        // Level 1: 0 (sentinel), 4
        auto actual_level_zero = std::vector<int>{ };

        auto level_zero_node = node_list->at( 0 ).get();

        while( level_zero_node )
        {
            actual_level_zero.push_back( level_zero_node->value );
            level_zero_node = level_zero_node->next.get();
        }

        const auto expected_level_zero = std::vector<int>{ 0, 4 };

        EXPECT_EQ( actual_level_zero, expected_level_zero );

        // Level 2: 0 (sentinel), 2, 6

        auto actual_level_one = std::vector<int>{ };

        auto level_one_node = node_list->at( 1 ).get();

        while( level_one_node )
        {
            actual_level_one.push_back( level_one_node->value );
            level_one_node = level_one_node->next.get();
        }

        const auto expected_level_one = std::vector<int>{ 0, 6, 2 };

        EXPECT_EQ( actual_level_one, expected_level_one );

        // Level 3: 0 (sentinel), 1, 3, 5, 7

        auto actual_level_two = std::vector<int>{ };

        auto level_two_node = node_list->at( 2 ).get();

        while( level_two_node )
        {
            actual_level_two.push_back( level_two_node->value );
            level_two_node = level_two_node->next.get();
        }

        const auto expected_level_two = std::vector<int>{ 0, 7, 5, 3, 1 };

        EXPECT_EQ( actual_level_two, expected_level_two );
    }

    TEST_F( depth_list_tests, depth_list_dfs_case2 )
    {
        const auto tree = list_of_depths{ 1, 2, 3, 4, 5, 6, 7, 8 };

        const auto node_list = tree.build_node_list_dfs();

        EXPECT_EQ( node_list->size(), tree.depth() );

        // Level 1: 0 (sentinel), 5
        auto actual_level_zero = std::vector<int>{ };

        auto level_zero_node = node_list->at( 0 ).get();

        while( level_zero_node )
        {
            actual_level_zero.push_back( level_zero_node->value );
            level_zero_node = level_zero_node->next.get();
        }

        const auto expected_level_zero = std::vector<int>{ 0, 5 };

        EXPECT_EQ( actual_level_zero, expected_level_zero );

        // Level 2: 0 (sentinel), 3, 7

        auto actual_level_one = std::vector<int>{ };

        auto level_one_node = node_list->at( 1 ).get();

        while( level_one_node )
        {
            actual_level_one.push_back( level_one_node->value );
            level_one_node = level_one_node->next.get();
        }

        const auto expected_level_one = std::vector<int>{ 0, 7, 3 };

        EXPECT_EQ( actual_level_one, expected_level_one );

        // Level 3: 0 (sentinel), 1, 3, 5, 7

        auto actual_level_two = std::vector<int>{ };

        auto level_two_node = node_list->at( 2 ).get();

        while( level_two_node )
        {
            actual_level_two.push_back( level_two_node->value );
            level_two_node = level_two_node->next.get();
        }

        const auto expected_level_two = std::vector<int>{ 0, 8, 6, 4, 2 };

        EXPECT_EQ( actual_level_two, expected_level_two );

        // Level 4: 0 (sentinel), 1

        auto actual_level_three = std::vector<int>{ };

        auto level_three_node = node_list->at( 3 ).get();

        while( level_three_node )
        {
            actual_level_three.push_back( level_three_node->value );
            level_three_node = level_three_node->next.get();
        }

        const auto expected_level_three = std::vector<int>{ 0, 1 };

        EXPECT_EQ( actual_level_three, expected_level_three );
    }
}