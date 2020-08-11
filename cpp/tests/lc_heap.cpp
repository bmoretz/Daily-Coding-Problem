#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/heap.h"

namespace leetcode::heap::tests
{
    class k_negations_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( k_negations_tests, case1 )
    {
        auto input = std::vector<int>{ 4, 2, 3 };
        const auto k = 2;
    	
        const auto actual = k_negations::largest_sum_after_k_negations( input, k );
        const auto expected = 9;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( k_negations_tests, case2 )
    {
        auto input = std::vector<int>{ 2, -3, -1, 5, -4 };
        const auto k = 2;

        const auto actual = k_negations::largest_sum_after_k_negations( input, k );
        const auto expected = 13;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( k_negations_tests, case3 )
    {
        auto input = std::vector<int>{ 3, -1, 0, 2 };
        const auto k = 2;

        const auto actual = k_negations::largest_sum_after_k_negations( input, k );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( k_negations_tests, case4 )
    {
        auto input = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4 };
        const auto k = 4;

        const auto actual = k_negations::largest_sum_after_k_negations( input, k );
        const auto expected = 94;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( k_negations_tests, case5 )
    {
        auto input = std::vector<int>{ 2,-3,-1,5,-4, -1, -3, -51, 23, 2, 5, -4, 12, 4, 13, 1, 0, 1, 143 };
        const auto k = 5;

        const auto actual = k_negations::largest_sum_after_k_negations( input, k );
        const auto expected = 274;

        EXPECT_EQ( actual, expected );
    }

    class median_finder_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( median_finder_tests, case1 )
    {
        auto mf = median_finder_stream{ };

        const auto actual = mf.find_median();
        const auto expected = 0;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( median_finder_tests, case2 )
    {
        auto mf = median_finder_stream{ };

        mf.add_number( 5 );
        mf.add_number( 3 );
    	
        const auto actual = mf.find_median();
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( median_finder_tests, case3 )
    {
        auto mf = median_finder_stream{ };

        mf.add_number( 5 );
        mf.add_number( 3 );
        mf.add_number( 2 );
        mf.add_number( 8 );

        const auto actual = mf.find_median();
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( median_finder_tests, case4 )
    {
        auto mf = median_finder_stream{ };

        mf.add_number( 5 ); 
        mf.add_number( 3 );
        mf.add_number( 2 );
        mf.add_number( 8 );
        mf.add_number( 10 );
        mf.add_number( 1 );
    	
        const auto actual = mf.find_median();
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( median_finder_tests, case5 )
    {
        auto mf = median_finder_stream{ };

        mf.add_number( 5 );
        mf.add_number( 3 );
        mf.add_number( 2 );
        mf.add_number( 8 );
        mf.add_number( 10 );
        mf.add_number( 1 );
        mf.add_number( 0 );
        mf.add_number( 7 );
        mf.add_number( 2 );
        mf.add_number( 5 );
    	
        const auto actual = mf.find_median();
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }
}