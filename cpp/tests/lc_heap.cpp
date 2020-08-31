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

    class meeting_rooms_ii_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( meeting_rooms_ii_tests, case1 )
    {
        const auto input = std::vector<std::vector<int>>{ { 0, 30 }, { 5, 10 }, { 15, 20 } };

        const auto actual = meeting_rooms_ii::schedule( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( meeting_rooms_ii_tests, case2 )
    {
        const auto input = std::vector<std::vector<int>>{
        	{ 490, 946 },
        	{ 132, 833 },
        	{ 677, 836 },
        	{ 77, 995 },
        	{ 499, 585 },
        	{ 72, 883 },
        	{ 863, 900 },
        	{ 193, 981 }
        };

        const auto actual = meeting_rooms_ii::schedule( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( meeting_rooms_ii_tests, case3 )
    {
        const auto input = std::vector<std::vector<int>>{
        	{ 2, 15 },
        	{ 36, 45 },
        	{ 9, 29 },
        	{ 16, 23 },
        	{ 4, 9 }
        };

        const auto actual = meeting_rooms_ii::schedule( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( meeting_rooms_ii_tests, case4 )
    {
        const auto input = std::vector<std::vector<int>>{
        	{ 6, 15 },
        	{ 13, 20 },
        	{ 6, 17 }
        };

        const auto actual = meeting_rooms_ii::schedule( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( meeting_rooms_ii_tests, case5 )
    {
        const auto input = std::vector<std::vector<int>>{
        	{ 2, 15 },
        	{ 36, 45 },
        	{ 9, 29 },
        	{ 16, 23 },
        	{ 4, 9 }
        };

        const auto actual = meeting_rooms_ii::schedule( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( meeting_rooms_ii_tests, case6 )
    {
        const auto input = std::vector<std::vector<int>>{
        	{ 490, 946 },
        	{ 132, 833 },
        	{ 677, 836 },
        	{ 77, 995 },
        	{ 499, 585 },
        	{ 72, 883 },
        	{ 863, 900 },
        	{ 193, 981 }
        };

        const auto actual = meeting_rooms_ii::schedule( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    class connect_sticks_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( connect_sticks_tests, case1 )
    {
        const auto input = std::vector<int>{ 2, 4, 3 };

        const auto actual = connect_sticks::connect( input );
        const auto expected = 14;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( connect_sticks_tests, case2 )
    {
        const auto input = std::vector<int>{ 1, 8, 3, 5 };

        const auto actual = connect_sticks::connect( input );
        const auto expected = 30;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( connect_sticks_tests, case3 )
    {
        const auto input = std::vector<int>{ 3354, 4316, 3259, 4904, 4598, 474, 3166, 6322, 8080, 9009 };

        const auto actual = connect_sticks::connect( input );
        const auto expected = 151646;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( connect_sticks_tests, case4 )
    {
        const auto input = std::vector<int>{ 213, 12, 1441, 121, 45, 921 };

        const auto actual = connect_sticks::connect( input );
        const auto expected = 4691;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( connect_sticks_tests, case5 )
    {
        const auto input = std::vector<int>{ 123, 41, 91, 45, 891, 99, 21, 323 };

        const auto actual = connect_sticks::connect( input );
        const auto expected = 3386;

        EXPECT_EQ( actual, expected );
    }

    class top_k_frequent_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( top_k_frequent_tests, case1 )
    {
        const auto input = std::vector<std::string>
        {
            "i", "love", "leetcode", "i", "love", "coding"
        };

        const auto actual = top_k_frequent::top_k( input, 2 );
        const auto expected = std::vector<std::string>
    	{
    		"i", "love"
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( top_k_frequent_tests, case2 )
    {
        const auto input = std::vector<std::string>
        {
            "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"
        };

        const auto actual = top_k_frequent::top_k( input, 4 );
        const auto expected = std::vector<std::string>
        {
            "the", "is", "sunny", "day"
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( top_k_frequent_tests, case3 )
    {
        const auto input = std::vector<std::string>
        {
            "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is", "day", "way"
        };

        const auto actual = top_k_frequent::top_k( input, 4 );
        const auto expected = std::vector<std::string>
        {
			"the", "is", "day", "sunny"
        };

        EXPECT_EQ( actual, expected );
    }

    class max_prod_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( max_prod_tests, case1 )
    {
        const auto input = std::vector<int>
        {
            1, 2, 3
        };

        const auto actual = max_prod::maximumProduct( input );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_prod_tests, case2 )
    {
        const auto input = std::vector<int>
        {
            1, 2, 3, 4
        };

        const auto actual = max_prod::maximumProduct( input );
        const auto expected = 24;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_prod_tests, case3 )
    {
        const auto input = std::vector<int>
        {
            -4, -3, -2, -1, 60
        };

        const auto actual = max_prod::maximumProduct( input );
        const auto expected = 720;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( max_prod_tests, case4 )
    {
        const auto input = std::vector<int>
        {
            -4, 2, -1, 60
        };

        const auto actual = max_prod::maximumProduct( input );
        const auto expected = 240;

        EXPECT_EQ( actual, expected );
    }
}