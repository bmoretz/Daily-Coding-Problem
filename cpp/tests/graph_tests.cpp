#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../problems/graph.h"

using namespace graph_problems;

namespace problems::graph_tests
{
    /// <summary>
    /// Testing class for has path.
    /// </summary>
    class has_path_tests :
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
    // Has Path 1
    //

    TEST_F( has_path_tests, dfs_case1 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C' };

        graph.connect( {
            { 'A', 'B' },
            {'B', 'C' }
		} );

        const auto actual = has_route::has_route1( graph, 'A', 'C' );
    	
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, dfs_case2 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F' };

        graph.connect( {
	        { 'A', 'B' },
	        { 'A', 'C' },
	        { 'A', 'D' },
	        { 'B', 'C' },
	        { 'C', 'E' },
	        { 'E', 'F' }
		} );

        const auto actual = has_route::has_route1( graph, 'A', 'C' );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, dfs_case3 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F' };

        graph.connect( {
            { 'A', 'B' },
            { 'A', 'C' },
            { 'A', 'D' },
            { 'B', 'C' },
            { 'C', 'E' },
            { 'E', 'F' }
            } );

        const auto actual = has_route::has_route1( graph, 'A', 'F' );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, dfs_case4 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F' };

        graph.connect( {
            { 'A', 'B' },
            { 'A', 'C' },
            { 'A', 'D' },
            { 'B', 'C' },
            { 'C', 'E' },
            { 'E', 'F' },
            { 'D', 'E' }
            } );

        const auto actual = has_route::has_route1( graph, 'D', 'F' );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, dfs_case5 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

        graph.connect( {
            { 'A', 'B' },
            { 'A', 'C' },
            { 'A', 'D' },
            { 'B', 'C' },
            { 'C', 'E' },
            { 'E', 'F' },
            { 'D', 'E' },
            { 'C', 'G' }
		} );

        const auto actual = has_route::has_route1( graph, 'D', 'G' );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, bfs_case1 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C' };

        graph.connect( {
            { 'A', 'B' },
            {'B', 'C' }
            } );

        const auto actual = has_route::has_route2( graph, 'A', 'C' );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, bfs_case2 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F' };

        graph.connect( {
            { 'A', 'B' },
            { 'A', 'C' },
            { 'A', 'D' },
            { 'B', 'C' },
            { 'C', 'E' },
            { 'E', 'F' }
            } );

        const auto actual = has_route::has_route2( graph, 'A', 'C' );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, bfs_case3 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F' };

        graph.connect( {
            { 'A', 'B' },
            { 'A', 'C' },
            { 'A', 'D' },
            { 'B', 'C' },
            { 'C', 'E' },
            { 'E', 'F' }
            } );

        const auto actual = has_route::has_route2( graph, 'A', 'F' );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, bfs_case4 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F' };

        graph.connect( {
            { 'A', 'B' },
            { 'A', 'C' },
            { 'A', 'D' },
            { 'B', 'C' },
            { 'C', 'E' },
            { 'E', 'F' },
            { 'D', 'E' }
            } );

        const auto actual = has_route::has_route2( graph, 'D', 'F' );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( has_path_tests, bfs_case5 )
    {
        auto graph = has_route::graph{ 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

        graph.connect( {
            { 'A', 'B' },
            { 'A', 'C' },
            { 'A', 'D' },
            { 'B', 'C' },
            { 'C', 'E' },
            { 'E', 'F' },
            { 'D', 'E' },
            { 'C', 'G' }
            } );

        const auto actual = has_route::has_route2( graph, 'D', 'G' );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for build order.
    /// </summary>
    class build_order_tests :
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
    // Build Order
    //

    TEST_F( build_order_tests, empty )
    {
        const auto builder = build_order();

        const auto actual = builder.get_build_order();
        const auto expected = "";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( build_order_tests, case1 )
    {
        const auto builder = build_order(
            // projects
            { 'A', 'B', 'C', 'D', 'E', 'F' },
            // dependencies
        {
            {'A', 'D'},
            {'F', 'B'},
            { 'B', 'D' },
            { 'F', 'A' },
            { 'D', 'C' }
        } );

        const auto actual = builder.get_build_order();
        const auto expected = "F, E, B, A, D, C";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( build_order_tests, case2 )
    {
        const auto builder = build_order(
            // projects
            { 'A', 'B', 'C', 'D', 'E', 'F' },
            // dependencies
        {
            {'A', 'D'},
            {'F', 'B'},
            { 'B', 'D' },
            { 'F', 'A' },
            { 'D', 'C' },
            { 'C', 'F' } // add a cycle
        } );

        const auto actual = builder.get_build_order();
        const auto expected = "CYCLICAL PROJECT REFERENCE DETECTED. CANNOT CONTINUE BUILD.";

		EXPECT_EQ( actual, expected );
    }

    TEST_F( build_order_tests, case3 )
    {
        const auto builder = build_order(
            // projects
            { 'A', 'B', 'C', 'D', 'E', 'F' },
            // dependencies
        {
            {'A', 'D'},
            {'F', 'B'},
            { 'B', 'D' },
            { 'F', 'A' },
            { 'D', 'C' },
            { 'C', 'E' }
        } );

        const auto actual = builder.get_build_order();
        const auto expected = "F, B, A, D, C, E";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( build_order_tests, case4 )
    {
        const auto builder = build_order(
            // projects
            { 'A', 'B', 'C', 'D', 'E', 'F' },
            // dependencies
        {
            {'A', 'D'},
            {'F', 'B'},
            { 'B', 'D' },
            { 'F', 'A' },
            { 'D', 'C' },
            { 'C', 'E' },
            { 'E', 'F' } // cycle
        } );

        const auto actual = builder.get_build_order();
        const auto expected = "CYCLICAL PROJECT REFERENCE DETECTED. CANNOT CONTINUE BUILD.";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( build_order_tests, case5 )
    {
        const auto builder = build_order(
            // projects
            { 'A', 'B', 'C', 'D', 'E', 'F' },
            // dependencies
        {
            {'A', 'D'},
            {'F', 'B'},
            { 'B', 'D' },
            { 'F', 'A' },
            { 'D', 'C' },
            { 'C', 'E' },
            { 'B', 'A' } 
        } );

        const auto actual = builder.get_build_order();
        const auto expected = "F, B, A, D, C, E";

        EXPECT_EQ( actual, expected );
    }
}