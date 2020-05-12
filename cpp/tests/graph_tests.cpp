#include "pch.h"
#include <gtest/gtest.h>
#include <typeinfo>

#include "../problems/graph.h"

using namespace graph_problems;

namespace graph_tests
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
}