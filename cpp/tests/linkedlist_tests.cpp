#include "pch.h"
#include <gtest/gtest.h>

#include "../problems/linkedlist.h"

using namespace linkedlist_problems;

namespace linkedlist_tests
{
    /// <summary>
    /// Testing class for dedupe.
    /// </summary>
    class dedupe_tests :
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
    // Dedupe 1
    //

    TEST_F( dedupe_tests, dedupe1_invalid )
    {
        auto list = dedupe1<int>();

        list.remove_dupes();
    	
        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case1 )
    {
        auto list = dedupe1 {1, 2, 3, 4, 5 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case2 )
    {
        auto list = dedupe1{ 1, 2, 2, 2, 3, 4, 4, 5, 5 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case3 )
    {
        auto list = dedupe1{ 1, 1, 1, 2, 3, 4, 4, 5, 5 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case4 )
    {
        auto list = dedupe1{ 1, 1, 1, 1, 1 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case5 )
    {
        auto list = dedupe1{ 1, 2, 2, 2 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2 };

        EXPECT_EQ( actual, expected );
    }

    //
    // Dedupe 2
    //

    TEST_F( dedupe_tests, dedupe2_invalid )
    {
        auto list = dedupe2<int>();

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case1 )
    {
        auto list = dedupe2{ 1, 2, 3, 4, 5 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case2 )
    {
        auto list = dedupe2{ 1, 2, 2, 2, 3, 4, 4, 5, 5 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case3 )
    {
        auto list = dedupe2{ 1, 1, 1, 2, 3, 4, 4, 5, 5 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case4 )
    {
        auto list = dedupe2{ 1, 1, 1, 1, 1 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case5 )
    {
        auto list = dedupe2{ 1, 2, 2, 2 };

        list.remove_dupes();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2 };

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for dedupe.
    /// </summary>
    class klast_tests :
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
    // klast 1
    //

    TEST_F( klast_tests, klast1_invalid )
    {
        auto list = klast1<int>();

        const auto actual = list.from_back(3);
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( klast_tests, klast1_case1 )
    {
        auto list = klast1{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back( 0 );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case2 )
    {
        auto list = klast1{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back( 1 );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case3 )
    {
        auto list = klast1{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back( 2 );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case4 )
    {
        auto list = klast1{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back( 5 );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case5 )
    {
        auto list = klast1{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back( 7 );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }
}