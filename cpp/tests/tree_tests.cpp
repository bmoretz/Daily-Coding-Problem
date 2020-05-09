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
}