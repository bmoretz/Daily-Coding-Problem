#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/interval.h"

namespace leetcode::interval::tests
{
    class merge_interval_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( merge_interval_tests, case1 )
    {
        auto input = std::vector<std::vector<int>>
        {
            { 1, 3 },
            { 2, 6 },
            { 8, 10 },
            { 15, 18}
        };
    	
        const auto actual = merge_intervals::merge( input );
    	
        const auto expected = std::vector<std::vector<int>>
        {
        	{ 1, 6 },
        	{ 8, 10 },
        	{ 15, 18 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( merge_interval_tests, case2 )
    {
        auto input = std::vector<std::vector<int>>
        {
	        { 1, 4 },
	        { 4, 5 }
        };

        const auto actual = merge_intervals::merge( input );

        const auto expected = std::vector<std::vector<int>>
        {
			{ 1, 5 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( merge_interval_tests, case3 )
    {
        auto input = std::vector<std::vector<int>>
        {
            { 1, 4 },
            { 4, 5 }
        };

        const auto actual = merge_intervals::merge( input );

        const auto expected = std::vector<std::vector<int>>
        {
            { 1, 5 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( merge_interval_tests, case4 )
    {
        auto input = std::vector<std::vector<int>>
        {
            { }
        };

        const auto actual = merge_intervals::merge( input );

        const auto expected = std::vector<std::vector<int>>
        {
            { }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( merge_interval_tests, case5 )
    {
        auto input = std::vector<std::vector<int>>
        {
	        { 1, 3 },
	        { 2, 6 },
	        { 8, 10 },
	        { 15, 18 },
	        { 5, 10 },
	        { 3, 8 },
	        { 1, 10 },
	        { 0, 0 },
	        { 4, 9 },
	        { 3, 7 }
        };

        const auto actual = merge_intervals::merge( input );

        const auto expected = std::vector<std::vector<int>>
        {
        	{ 0, 0 },
        	{ 1, 10 },
        	{ 15, 18 }
        };

        EXPECT_EQ( actual, expected );
    }

    class disjoint_intervals_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( disjoint_intervals_tests, case1 )
    {
        const auto input = std::vector<int>{ 5, 0, 3, 8, 6 };

        const auto actual = disjoint_intervals::partition_disjoint( input );
        const auto expected = 3;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( disjoint_intervals_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 1, 1, 0, 6, 12 };

        const auto actual = disjoint_intervals::partition_disjoint( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( disjoint_intervals_tests, case3 )
    {
        const auto input = std::vector<int>{ 1, 1, 1, 0, 4, 6, 12 };

        const auto actual = disjoint_intervals::partition_disjoint( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }
}