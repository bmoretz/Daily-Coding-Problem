#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../problems/tree.h"

namespace problems::tree::tests
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

    TEST_F( min_tree_tests, empty )
    {
    	const auto tree = min_tree{ { } };
    	
        const auto actual = tree.depth();
        const auto expected = 0;
    }

    TEST_F( min_tree_tests, case1 )
    {
        const auto tree = min_tree{1};

        const auto actual = tree.depth();
        const auto expected = 1;
    }

    TEST_F( min_tree_tests, case2 )
    {
        const auto tree = min_tree{ 1, 2, 3 };

        const auto actual = tree.depth();
        const auto expected = 2;
    }

    TEST_F( min_tree_tests, case3 )
    {
        const auto tree = min_tree{ 1, 2, 3, 4 };

        const auto actual = tree.depth();
        const auto expected = 3;
    }

    TEST_F( min_tree_tests, case4 )
    {
        const auto tree = min_tree{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        const auto actual = tree.depth();
        const auto expected = 4;
    }

    TEST_F( min_tree_tests, case5 )
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

    TEST_F( depth_list_tests, bfs_empty )
    {
        const auto tree = list_of_depths{ };

        const auto node_list = tree.build_node_list_bfs();

        EXPECT_EQ( node_list->size(), 0 );
    }

    TEST_F( depth_list_tests, bfs_case1 )
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

    TEST_F( depth_list_tests, bfs_case2 )
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

    TEST_F( depth_list_tests, dfs_empty )
    {
        const auto tree = list_of_depths{ };

        const auto node_list = tree.build_node_list_dfs();

        EXPECT_EQ( node_list->size(), 0 );
    }

    TEST_F( depth_list_tests, dfs_case1 )
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

    TEST_F( depth_list_tests, dfs_case2 )
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

    /// <summary>
    /// Testing class for depth list.
    /// </summary>
    class is_balanced_tests :
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
    // is balanced
    //

    TEST_F( is_balanced_tests, empty )
    {
        const auto tree = is_balanced{ };

        const auto actual = tree.is_balanced1();
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }
	
    TEST_F( is_balanced_tests, case1 )
    {
        using node = is_balanced::tree_node;
    	
        auto tree = is_balanced{ };

        tree.root = std::make_unique<node>( 4 );
    	
        const auto actual = tree.is_balanced1();
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_balanced_tests, case2 )
    {
        using node = is_balanced::tree_node;

        auto tree = is_balanced{ };

        tree.root = std::make_unique<node>( 4 );
        tree.root->left = std::make_unique<node>( 6 );
    	
        const auto actual = tree.is_balanced1();
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_balanced_tests, case3 )
    {
        using node = is_balanced::tree_node;

        auto tree = is_balanced{ };

        tree.root = std::make_unique<node>( 4 );

        tree.root->left = std::make_unique<node>( 6 );

        tree.root->left->left = std::make_unique<node>( 2 );
        tree.root->left->left->left = std::make_unique<node>( 1 );

        tree.root->left->right = std::make_unique<node>( 5 );

        const auto actual = tree.is_balanced1();
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_balanced_tests, case4 )
    {
        using node = is_balanced::tree_node;

        auto tree = is_balanced{ };

        tree.root = std::make_unique<node>( 4 );

        tree.root->left = std::make_unique<node>( 6 );

        tree.root->left->left = std::make_unique<node>( 2 );
        tree.root->left->left->left = std::make_unique<node>( 1 );
    	
        tree.root->right = std::make_unique<node>( 9 );
    	
        tree.root->right->right = std::make_unique<node>( 5 );
        tree.root->right->right->left = std::make_unique<node>( 2 );
        tree.root->right->right->right = std::make_unique<node>( 1 );

        const auto actual = tree.is_balanced1();
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_balanced_tests, case5 )
    {
        using node = is_balanced::tree_node;

        auto tree = is_balanced{ };

        tree.root = std::make_unique<node>( 4 );

        tree.root->left = std::make_unique<node>( 6 );

        tree.root->left->left = std::make_unique<node>( 2 );
        tree.root->left->left->left = std::make_unique<node>( 1 );

    	tree.root->left->left->left->left = std::make_unique<node>( 0 );
        tree.root->left->left->left->left->left = std::make_unique<node>( -1 );
    	
        tree.root->right = std::make_unique<node>( 9 );

        tree.root->right->right = std::make_unique<node>( 5 );
        tree.root->right->right->left = std::make_unique<node>( 2 );
        tree.root->right->right->right = std::make_unique<node>( 1 );

        const auto actual = tree.is_balanced1();
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for is bst.
    /// </summary>
    class is_bst_tests :
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
    // validate bst
    //

    TEST_F( is_bst_tests, empty )
    {
        using node = validate_bst::tree_node;
    	
        const auto tree = nullptr;

        const auto actual = validate_bst::is_bst( tree );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_bst_tests, case1 )
    {
        using node = validate_bst::tree_node;

        const auto tree = std::make_unique<node>( 4 );

        const auto actual = validate_bst::is_bst( tree.get() );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_bst_tests, case2 )
    {
        using node = validate_bst::tree_node;

        auto tree = std::make_unique<node>( 4 );

        tree->left = std::make_unique<node>( 7 );
        tree->right = std::make_unique<node>( 8 );
    	
        const auto actual = validate_bst::is_bst( tree.get() );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_bst_tests, case3 )
    {
        using node = validate_bst::tree_node;

        auto tree = std::make_unique<node>( 4 );

        tree->left = std::make_unique<node>( 3 );
        tree->right = std::make_unique<node>( 8 );

        const auto actual = validate_bst::is_bst( tree.get() );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_bst_tests, case4 )
    {
        using node = validate_bst::tree_node;

        auto tree = std::make_unique<node>( 4 );

        tree->left = std::make_unique<node>( 2 );
    	
        tree->left->left = std::make_unique<node>( 1 );
        tree->left->right = std::make_unique<node>( 3 );
    	
        tree->right = std::make_unique<node>( 7 );
        tree->right->left = std::make_unique<node>( 6 );
        tree->right->right = std::make_unique<node>( 8 );
    	
        const auto actual = validate_bst::is_bst( tree.get() );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_bst_tests, case5 )
    {
        using node = validate_bst::tree_node;

        auto tree = std::make_unique<node>( 4 );

        tree->left = std::make_unique<node>( 2 );

        tree->left->left = std::make_unique<node>( 1 );

    	tree->left->left->left = std::make_unique<node>( 5 );
    	
    	tree->left->right = std::make_unique<node>( 3 );

        tree->right = std::make_unique<node>( 7 );
        tree->right->left = std::make_unique<node>( 6 );
        tree->right->right = std::make_unique<node>( 8 );

        const auto actual = validate_bst::is_bst( tree.get() );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for successor.
    /// </summary>
    class successor_tests :
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
    // successor
    //

    TEST_F( successor_tests, empty )
    {
        using node = successor::tree_node;
    	
        const auto tree = node { nullptr, 0 };

        const auto actual = successor::get_successor( tree );
        const auto expected = nullptr;

        EXPECT_EQ( actual, expected );
    }

	/*                      Test Tree
	 *
	 *                            9
	 *                       /        \
	 *                     5           18
	 *                   /   \        /    \
	 *                 3       7  15        20
	 *               /           /
	 *             2          12     
	 */

    TEST_F( successor_tests, case1 )
    {
        const auto values = { 2, 3, 5 , 7, 9, 12, 15, 18, 20 };
    	
        const auto tree =
            successor::build_tree( values, 0, values.size() );

		// node(9)->next == 12
        const auto candidate = tree.get();

        const auto actual = successor::get_successor( *candidate );
        const auto expected = 12;

        EXPECT_NE( actual, nullptr );
        EXPECT_EQ( actual->value, expected );
    }

    TEST_F( successor_tests, case2 )
    {
        const auto values = { 2, 3, 5 , 7, 9, 12, 15, 18, 20 };

        const auto tree =
            successor::build_tree( values, 0, values.size() );

        // node(7)->next == 9
        const auto candidate = 
            tree->left->right.get();

        EXPECT_EQ( candidate->value, 7 );
    	
        const auto actual = successor::get_successor( *candidate );
        const auto expected = 9;

        EXPECT_NE( actual, nullptr );
        EXPECT_EQ( actual->value, expected );
    }

    TEST_F( successor_tests, case3 )
    {
        const auto values = { 2, 3, 5 , 7, 9, 12, 15, 18, 20 };

        const auto tree =
            successor::build_tree( values, 0, values.size() );

        // node(2)->next == 3
        const auto candidate =
            tree->left->left->left.get();

        EXPECT_EQ( candidate->value, 2 );

        const auto actual = successor::get_successor( *candidate );
        const auto expected = 3;

        EXPECT_NE( actual, nullptr );
        EXPECT_EQ( actual->value, expected );
    }

    TEST_F( successor_tests, case4 )
    {
        const auto values = { 2, 3, 5 , 7, 9, 12, 15, 18, 20 };

        const auto tree =
            successor::build_tree( values, 0, values.size() );

        // node(18)->next == 20
        const auto candidate =
            tree->right.get();

        EXPECT_EQ( candidate->value, 18 );

        const auto actual = successor::get_successor( *candidate );
        const auto expected = 20;

        EXPECT_NE( actual, nullptr );
        EXPECT_EQ( actual->value, expected );
    }

    TEST_F( successor_tests, case5 )
    {
        const auto values = { 2, 3, 5 , 7, 9, 12, 15, 18, 20 };

        const auto tree =
            successor::build_tree( values, 0, values.size() );

        // node(20)->next == none
        const auto candidate =
            tree->right->right.get();

        EXPECT_EQ( candidate->value, 20 );

        const auto actual = successor::get_successor( *candidate );
        const auto expected = nullptr;

        EXPECT_EQ( actual, nullptr );
    }

    /// <summary>
    /// Testing class for common ancestor.
    /// </summary>
    class ancestor_tests :
        public ::testing::Test {

        using node_ptr = std::unique_ptr<ancestor::tree_node>;
    	
    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }

        /*
	     *                      test tree
	     *                           7
	     *                    /            \
	     *                   5               9
	     *                /     \          /     \
	     *              6       3        4         8
	     *            /       /          \
	     *           2       2              3
	     *        /     \
	     *       1       5
	     *      /
	     *     0
	     */
        [[nodiscard]] node_ptr test_tree() const
        {
            using node = ancestor::tree_node;

            auto tree = std::make_unique<node>( 7, nullptr );

            tree->insert_left( 5 );

            tree->left->insert_left( 6 );

            tree->left->left->insert_left( 2 );
            tree->left->left->left->insert_left( 1 );
            tree->left->left->left->left->insert_left( 0 );

            tree->left->left->left->insert_right( 5 );
            tree->left->insert_right( 3 );
            tree->left->right->insert_left( 2 );

            tree->insert_right( 9 );

            tree->right->insert_left( 4 );
            tree->right->left->insert_right( 3 );
            tree->right->insert_right( 8 );

            return tree;
        }
    };

    //
    // common ancestor tests
    //

    TEST_F( ancestor_tests, empty )
    {
        const auto tree = test_tree();

        const auto actual = ancestor::common_ancestor1( *tree, *tree, *tree );
        const auto expected = tree.get();

        EXPECT_EQ( actual, expected );
    }
	
    TEST_F( ancestor_tests, case1 )
    {
        const auto tree = test_tree();

    	// 7 -> 5 -> 6 -> 2 -> 1 -> 0
        const auto first = tree->left->left->left->left->left.get();
    	// 7 -> 9 -> 8
        const auto second = tree->right->right.get();
    	
        const auto actual = ancestor::common_ancestor1( *tree, *first, *second );
        const auto expected = tree.get();

        EXPECT_EQ( actual, expected );
    }

    TEST_F( ancestor_tests, case2 )
    {
        const auto tree = test_tree();

        // 7 -> 5 -> 6 -> 2 -> 1-> 0
        const auto first = tree->left->left->left->left->left.get();
        // 7 -> 5-> 3
        const auto second = tree->left->right.get();

        const auto actual = ancestor::common_ancestor1( *tree, *first, *second );

    	// 7-> 5
        const auto expected = tree->left.get();

        EXPECT_EQ( actual, expected );
    }

    TEST_F( ancestor_tests, case3 )
    {
        const auto tree = test_tree();

        // 7 -> 5 -> 6 -> 2 -> 1-> 0
        const auto first = tree->left->left->left->left->left.get();
        // 7 -> 5-> 3 -> 2
        const auto second = tree->left->right->left.get();

        const auto actual = ancestor::common_ancestor1( *tree, *first, *second );

        // 7-> 5
        const auto expected = tree->left.get();

        EXPECT_EQ( actual, expected );
    }

    TEST_F( ancestor_tests, case4 )
    {
        const auto tree = test_tree();

        // 7 -> 5 -> 6 -> 2 -> 1-> 0
        const auto first = tree->left->left->left->left->left.get();
        // 7 -> 9
        const auto second = tree->right.get();

        const auto actual = ancestor::common_ancestor1( *tree, *first, *second );

        // 7
        const auto expected = tree.get();

        EXPECT_EQ( actual, expected );
    }

    TEST_F( ancestor_tests, case5 )
    {
        const auto tree = test_tree();

        // 7 -> 5 -> 6 -> 2 -> 5
        const auto first = tree->left->left->left->right.get();
        // 7 -> 9 -> 4 -> 3
        const auto second = tree->right->left->right.get();

        const auto actual = ancestor::common_ancestor1( *tree, *first, *second );

        // 7
        const auto expected = tree.get();

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for bst sequence.
    /// </summary>
    class bst_sequence_tests :
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
    // bst sequence
    //

    TEST_F( bst_sequence_tests, empty )
    {
        using int_seq = bst_sequence<int>;

        const auto tree =
            int_seq::build_tree( {}, 0, 0 );

        const auto actual = 
            int_seq::get_sequences( tree.get() );

        const std::vector<std::list<int>> expected = { { } };

    	for( auto index = std::size_t(); 
            index < expected.size(); ++index )
    	{
            const auto a_list = *actual->at( index );
            const auto& e_list = expected.at( index );

            EXPECT_EQ( a_list, e_list );
    	}
    }

    TEST_F( bst_sequence_tests, case1 )
    {
        using int_seq = bst_sequence<int>;

        const auto values = { 1, 2, 3 };
    	
        const auto tree =
            int_seq::build_tree( values, 0, values.size() );

        const auto actual =
            int_seq::get_sequences( tree.get() );

        const std::vector<std::list<int>> expected = {
        	{ 2, 1, 3 },
            { 2, 3, 1 }
        };

        for( auto index = std::size_t();
            index < expected.size(); ++index )
        {
            const auto a_list = *actual->at( index );
            const auto& e_list = expected.at( index );

            EXPECT_EQ( a_list, e_list );
        }
    }

    TEST_F( bst_sequence_tests, case2 )
    {
        using int_seq = bst_sequence<int>;

        const auto values = { 1, 2, 3, 4, 5 };

        const auto tree =
            int_seq::build_tree( values, 0, values.size() );

        const auto actual =
            int_seq::get_sequences( tree.get() );

        const std::vector<std::list<int>> expected = {
            { 3, 2, 1, 5, 4 },
            { 3, 2, 5, 1, 4 },
            { 3, 2, 5, 4, 1 },
            { 3, 4, 2, 1, 5 },
            { 3, 4, 2, 5, 1 },
            { 3, 4, 5, 2, 1 }
        };

        for( auto index = std::size_t();
            index < expected.size(); ++index )
        {
            const auto a_list = *actual->at( index );
            const auto& e_list = expected.at( index );

            EXPECT_EQ( a_list, e_list );
        }
    }

    TEST_F( bst_sequence_tests, case3 )
    {
        using int_seq = bst_sequence<int>;

        const auto values = { 1, 2, 3, 4, 5 };

        const auto tree =
            int_seq::build_tree( values, 0, values.size() );

        const auto actual =
            int_seq::get_sequences( tree.get() );

        const std::vector<std::list<int>> expected = {
            { 3, 2, 1, 5, 4 },
            { 3, 2, 5, 1, 4 },
            { 3, 2, 5, 4, 1 },
            { 3, 4, 2, 1, 5 },
            { 3, 4, 2, 5, 1 },
            { 3, 4, 5, 2, 1 }
        };

        for( auto index = std::size_t();
            index < expected.size(); ++index )
        {
            const auto a_list = *actual->at( index );
            const auto& e_list = expected.at( index );

            EXPECT_EQ( a_list, e_list );
        }
    }

    TEST_F( bst_sequence_tests, case4 )
    {
        using int_seq = bst_sequence<int>;

        const auto values = { 1, 2, 3, 4, 5, 6 };

        const auto tree =
            int_seq::build_tree( values, 0, values.size() );

        const auto actual =
            int_seq::get_sequences( tree.get() );

        const std::vector<std::list<int>> expected = {
			{ 4, 2, 1, 3, 6, 5 },
			{ 4, 2, 1, 6, 3, 5 },
			{ 4, 2, 1, 6, 5, 3 },
			{ 4, 2, 5, 1, 3, 6 },
			{ 4, 2, 5, 1, 6, 3 },
			{ 4, 2, 5, 6, 1, 3 },
			{ 4, 6, 2, 1, 3, 5 },
			{ 4, 6, 2, 1, 5, 3 },
			{ 4, 6, 2, 5, 1, 3 },
			{ 4, 6, 5, 2, 1, 3 },
			{ 4, 2, 3, 1, 5, 6 },
			{ 4, 2, 3, 5, 1, 6 },
			{ 4, 2, 3, 5, 6, 1 },
			{ 4, 2, 6, 3, 1, 5 },
			{ 4, 2, 6, 3, 5, 1 },
			{ 4, 2, 6, 5, 3, 1 },
			{ 4, 5, 2, 3, 1, 6 },
			{ 4, 5, 2, 3, 6, 1 },
			{ 4, 5, 2, 6, 3, 1 },
			{ 4, 5, 6, 2, 3, 1 },
        };

        for( auto index = std::size_t();
            index < expected.size(); ++index )
        {
            const auto a_list = *actual->at( index );
            const auto& e_list = expected.at( index );

            EXPECT_EQ( a_list, e_list );
        }
    }
	
    TEST_F( bst_sequence_tests, case5 )
    {
        using int_seq = bst_sequence<int>;

        const auto values = { 1, 2, 3, 4, 5, 6, 7 };

        const auto tree =
            int_seq::build_tree( values, 0, values.size() );

        const auto actual =
            int_seq::get_sequences( tree.get() );

        const std::vector<std::list<int>> expected = {
            { 4, 2, 1, 3, 6, 5, 7 },
            { 4, 2, 1, 6, 3, 5, 7 },
            { 4, 2, 1, 6, 5, 3, 7 },
            { 4, 2, 1, 6, 5, 7, 3 },
            { 4, 2, 7, 1, 3, 5, 6 },
            { 4, 2, 7, 1, 5, 3, 6 },
            { 4, 2, 7, 1, 5, 6, 3 },
            { 4, 2, 7, 6, 1, 3, 5 },
            { 4, 2, 7, 6, 1, 5, 3 },
            { 4, 2, 7, 6, 5, 1, 3 },
            { 4, 5, 2, 1, 3, 6, 7 },
            { 4, 5, 2, 1, 6, 3, 7 },
            { 4, 5, 2, 1, 6, 7, 3 },
            { 4, 5, 2, 7, 1, 3, 6 },
            { 4, 5, 2, 7, 1, 6, 3 },
            { 4, 5, 2, 7, 6, 1, 3 },
            { 4, 5, 6, 2, 1, 3, 7 },
            { 4, 5, 6, 2, 1, 7, 3 },
            { 4, 5, 6, 2, 7, 1, 3 },
            { 4, 5, 6, 7, 2, 1, 3 },
            { 4, 2, 1, 3, 6, 7, 5 },
            { 4, 2, 1, 6, 3, 7, 5 },
            { 4, 2, 1, 6, 7, 3, 5 },
            { 4, 2, 1, 6, 7, 5, 3 },
            { 4, 2, 5, 1, 3, 7, 6 },
            { 4, 2, 5, 1, 7, 3, 6 },
            { 4, 2, 5, 1, 7, 6, 3 },
            { 4, 2, 5, 6, 1, 3, 7 },
            { 4, 2, 5, 6, 1, 7, 3 },
            { 4, 2, 5, 6, 7, 1, 3 },
            { 4, 7, 2, 1, 3, 6, 5 },
            { 4, 7, 2, 1, 6, 3, 5 },
            { 4, 7, 2, 1, 6, 5, 3 },
            { 4, 7, 2, 5, 1, 3, 6 },
            { 4, 7, 2, 5, 1, 6, 3 },
            { 4, 7, 2, 5, 6, 1, 3 },
            { 4, 7, 6, 2, 1, 3, 5 },
            { 4, 7, 6, 2, 1, 5, 3 },
            { 4, 7, 6, 2, 5, 1, 3 },
            { 4, 7, 6, 5, 2, 1, 3 },
            { 4, 2, 3, 1, 7, 6, 5 },
            { 4, 2, 3, 7, 1, 6, 5 },
            { 4, 2, 3, 7, 6, 1, 5 },
            { 4, 2, 3, 7, 6, 5, 1 },
            { 4, 2, 5, 3, 1, 6, 7 },
            { 4, 2, 5, 3, 6, 1, 7 },
            { 4, 2, 5, 3, 6, 7, 1 },
            { 4, 2, 5, 7, 3, 1, 6 },
            { 4, 2, 5, 7, 3, 6, 1 },
            { 4, 2, 5, 7, 6, 3, 1 },
            { 4, 6, 2, 3, 1, 7, 5 },
            { 4, 6, 2, 3, 7, 1, 5 },
            { 4, 6, 2, 3, 7, 5, 1 },
            { 4, 6, 2, 5, 3, 1, 7 },
            { 4, 6, 2, 5, 3, 7, 1 },
            { 4, 6, 2, 5, 7, 3, 1 },
            { 4, 6, 7, 2, 3, 1, 5 },
            { 4, 6, 7, 2, 3, 5, 1 },
            { 4, 6, 7, 2, 5, 3, 1 },
            { 4, 6, 7, 5, 2, 3, 1 },
            { 4, 2, 3, 1, 5, 6, 7 },
            { 4, 2, 3, 5, 1, 6, 7 },
            { 4, 2, 3, 5, 6, 1, 7 },
            { 4, 2, 3, 5, 6, 7, 1 },
            { 4, 2, 7, 3, 1, 6, 5 },
            { 4, 2, 7, 3, 6, 1, 5 },
            { 4, 2, 7, 3, 6, 5, 1 },
            { 4, 2, 7, 5, 3, 1, 6 },
            { 4, 2, 7, 5, 3, 6, 1 },
            { 4, 2, 7, 5, 6, 3, 1 },
            { 4, 6, 2, 3, 1, 5, 7 },
            { 4, 6, 2, 3, 5, 1, 7 },
            { 4, 6, 2, 3, 5, 7, 1 },
            { 4, 6, 2, 7, 3, 1, 5 },
            { 4, 6, 2, 7, 3, 5, 1 },
            { 4, 6, 2, 7, 5, 3, 1 },
            { 4, 6, 5, 2, 3, 1, 7 },
            { 4, 6, 5, 2, 3, 7, 1 },
            { 4, 6, 5, 2, 7, 3, 1 },
            { 4, 6, 5, 7, 2, 3, 1 }
        };

        for( auto index = std::size_t();
            index < expected.size(); ++index )
        {
            const auto a_list = *actual->at( index );
            const auto& e_list = expected.at( index );

            EXPECT_EQ( a_list, e_list );
        }
    }

    /// <summary>
    /// Testing class for check subtree.
    /// </summary>
    class check_subtree_tests :
        public ::testing::Test {

    protected:
        /*          test tree
        *
        *                 6
        *            /           \
        *          4                 8
        *        /    \            /     \
        *       2       5           7       9
        *     /    \        /   \       \
        *    1        3     4      8     10
        *  /     \        /     /
        * 2         1     2     8
        *          /              \
        *         6                  2
         *
         *
         *
         */

        [[nodiscard]] auto build_test_tree() const -> std::unique_ptr<check_subtree::tree_node>
        {
            using node = check_subtree::tree_node;

            auto root = std::make_unique<node>( 6 );

            auto l = root->insert_left( 4 );

            auto ll = l->insert_left( 2 );

            ll->insert_left( 1 );

            auto llr = ll->insert_right( 3 );

            llr->insert_left( 2 );

            auto llrr = llr->insert_right( 1 );
            llrr->insert_left( 6 );

            l->insert_right( 5 );

            auto r = root->insert_right( 8 );

            auto rl = r->insert_left( 7 );

            rl->insert_left( 4 );

            auto rlr = rl->insert_right( 8 );
            rlr->insert_left( 2 );

            auto rr = r->insert_right( 9 );

            auto rrr = rr->insert_right( 10 );

            auto rrrl = rrr->insert_left( 8 );
            rrrl->insert_right( 2 );

            return root;
        }
    	
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    //
    // check subtree subtree
    //

    TEST_F( check_subtree_tests, empty )
    {
        const auto actual = check_subtree::is_subtree( nullptr, nullptr );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

	/*      t2
	 *      3
	 *        \
	 *          1
	 *        /
	 *      6
	 */
    TEST_F( check_subtree_tests, case1 )
    {
        using node = check_subtree::tree_node;
    	
		const auto t1 = build_test_tree();

        auto t2 = std::make_unique<node>( 3 );
        auto r = t2->insert_right( 1 );
        r->insert_left( 6 );
    	
        const auto actual = check_subtree::is_subtree( t1.get(), t2.get() );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    /*      t2
     *      7
     *   /    \
     *  4       8
     *        /
     *      2
     */
    TEST_F( check_subtree_tests, case2 )
    {
        using node = check_subtree::tree_node;

        const auto t1 = build_test_tree();

        auto t2 = std::make_unique<node>( 7 );
        t2->insert_left( 4 );
        auto r = t2->insert_right( 8 );
        r->insert_left( 2 );

        const auto actual = check_subtree::is_subtree( t1.get(), t2.get() );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    /*      t2
     *      10
     *    /    
     *   8      
     *    \    
     *      2
     */
    TEST_F( check_subtree_tests, case3 )
    {
        using node = check_subtree::tree_node;

        const auto t1 = build_test_tree();

        auto t2 = std::make_unique<node>( 10 );
        auto l = t2->insert_left( 8 );
        l->insert_right( 2 );

        const auto actual = check_subtree::is_subtree( t1.get(), t2.get() );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    /*      t2
     *      10
     *        \
     *          8
     *        /
     *      2
     */
    TEST_F( check_subtree_tests, case4 )
    {
        using node = check_subtree::tree_node;

        const auto t1 = build_test_tree();

        auto t2 = std::make_unique<node>( 10 );
        auto r = t2->insert_right( 8 );
        r->insert_left( 2 );

        const auto actual = check_subtree::is_subtree( t1.get(), t2.get() );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    /*      t2
     *      4
     *        \
     *          5
     *             \
     *                1
     */
    TEST_F( check_subtree_tests, case5 )
    {
        using node = check_subtree::tree_node;

        const auto t1 = build_test_tree();

        auto t2 = std::make_unique<node>( 4 );
        auto r = t2->insert_right( 5 );
        r->insert_right( 1 );

        const auto actual = check_subtree::is_subtree( t1.get(), t2.get() );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for random node.
    /// </summary>
    class random_node_tests :
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
    // random node
    //

    TEST_F( random_node_tests, case1 )
    {
        // basic functionality.
        const auto rand = 
            random_node<int>( { 1, 2, 3 }, 1234 );
    	
        const auto actual = rand.pick_random();
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( random_node_tests, case2 )
    {
    	// basic functionality.
        const auto rand =
            random_node<int>( { 1, 2, 3 }, 585 );

        const auto actual = rand.pick_random();
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( random_node_tests, balanced_tree )
    {
    	// actually test the probability function.
    	
        // fix the tree to be balanced tree with 7 nodes
        const auto values = std::initializer_list<int>
			{ 4, 2, 6, 1, 3, 5, 7 };

        const auto rand =
            random_node<int>( values, 2358 );

    	// storage for 10k draws
        auto results = std::map<int, int>();

        const std::size_t iters = 1e6;
    	
		for( auto index = std::size_t(); index < iters; ++index )
		{
            results[ rand.pick_random() ]++;
		}

        double max = 0.0f, min = 0.0f;
    	
    	for( const auto& [key, value] : results )
    	{
            auto freq = static_cast< double >( value ) / iters;
    		
            max = std::max( max, freq );
            min = std::min( max, freq );
    	}

        const auto epsilon = 0.001; // error tolerance

        EXPECT_LT( max - min, epsilon );
    }

    TEST_F( random_node_tests, unbalanced_tree )
    {
        // actually test the probability function.

        // fix the tree to be an unbalanced tree with 11 nodes
        const auto values = std::initializer_list<int>
			{ 4, 3, 6, 2, 1, 0, 5, 7, 9, 10, 11 };

        // seed the generator
        const auto rand =
            random_node<int>( values, 6358 );

        // storage for 10k draws
        auto results = std::map<int, int>();

        const std::size_t iters = 1e6;

        for( auto index = std::size_t(); index < iters; ++index )
        {
            results[ rand.pick_random() ]++;
        }

        double max = 0.0f, min = 0.0f;

        for( const auto& [key, value] : results )
        {
            auto freq = static_cast< double >( value ) / iters;

            max = std::max( max, freq );
            min = std::min( max, freq );
        }

        const auto epsilon = 0.001; // error tolerance

        EXPECT_LT( max - min, epsilon );
    }

    /// <summary>
    /// Testing class for path sums.
    /// </summary>
    class path_sum_tests :
        public ::testing::Test {

    	/*              Test Tree
    	 *                           7
    	 *                   /                 \
    	 *                  5                   8
    	 *              /       \           /       \
    	 *           3           -3        -3        5
    	 *         /    \      /     \          \       \   
    	 *       -3        4  2        1        -2      -2
    	 *     /   \
    	 *   1      -2
    	 */
    public:
        static path_sum::tree_node_ptr build_test_tree()
        {
            using node = path_sum::tree_node;

            auto root = std::make_unique<node>( 7 );

            root->left = std::make_unique<node>( 5 );

            root->left->left = std::make_unique<node>( 3 );
            root->left->left->left = std::make_unique<node>( -3 );
            root->left->left->left->left = std::make_unique<node>( 1 );
            root->left->left->left->right = std::make_unique<node>( -2 );

            root->left->left->right = std::make_unique<node>( 4 );

            root->left->right = std::make_unique<node>( -3 );
            root->left->right->left = std::make_unique<node>( 2 );
            root->left->right->right = std::make_unique<node>( 1 );

            root->right = std::make_unique<node>( 8 );

            root->right->left = std::make_unique<node>( -3 );
            root->right->left->right = std::make_unique<node>( 2 );

            root->right->right = std::make_unique<node>( 5 );
            root->right->right->right = std::make_unique<node>( -2 );

            return root;
        }
    	
    protected:
    	
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    //
    // path sums
    //

    TEST_F( path_sum_tests, none )
    {
        using node = path_sum::tree_node;
    	
        const auto root = 
            std::make_unique<node>( 4 );

        const auto target_sum = 1;

        const auto actual = 
            path_sum::find_sum( root.get(), target_sum );

    	const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }
	
    TEST_F( path_sum_tests, case1 )
    {
        const auto root = 
            build_test_tree();

        const auto target_sum = 12;
    	
        const auto actual = 
            path_sum::find_sum( root.get(), target_sum );

    	const auto expected = 4;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( path_sum_tests, case2 )
    {
        const auto root =
            build_test_tree();

        const auto target_sum = 20;

        const auto actual =
            path_sum::find_sum( root.get(), target_sum );

        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( path_sum_tests, case3 )
    {
        const auto root =
            build_test_tree();

        const auto target_sum = 7;

        const auto actual =
            path_sum::find_sum( root.get(), target_sum );

        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( path_sum_tests, case4 )
    {
        const auto root =
            build_test_tree();

        const auto target_sum = 16;

        const auto actual =
            path_sum::find_sum( root.get(), target_sum );

        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( path_sum_tests, case5 )
    {
        const auto root =
            build_test_tree();

        const auto target_sum = 3;

        const auto actual =
            path_sum::find_sum( root.get(), target_sum );

        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }
}