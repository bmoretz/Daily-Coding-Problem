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
        auto list = dedupe<int>();

        list.dedupe1();
    	
        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case1 )
    {
        auto list = dedupe {1, 2, 3, 4, 5 };

        list.dedupe1();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case2 )
    {
        auto list = dedupe{ 1, 2, 2, 2, 3, 4, 4, 5, 5 };

        list.dedupe1();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case3 )
    {
        auto list = dedupe{ 1, 1, 1, 2, 3, 4, 4, 5, 5 };

        list.dedupe1();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case4 )
    {
        auto list = dedupe{ 1, 1, 1, 1, 1 };

        list.dedupe1();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe1_case5 )
    {
        auto list = dedupe{ 1, 2, 2, 2 };

        list.dedupe1();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2 };

        EXPECT_EQ( actual, expected );
    }

    //
    // Dedupe 2
    //

    TEST_F( dedupe_tests, dedupe2_invalid )
    {
        auto list = dedupe<int>();

        list.dedupe2();

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case1 )
    {
        auto list = dedupe{ 1, 2, 3, 4, 5 };

        list.dedupe2();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case2 )
    {
        auto list = dedupe{ 1, 2, 2, 2, 3, 4, 4, 5, 5 };

        list.dedupe2();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case3 )
    {
        auto list = dedupe{ 1, 1, 1, 2, 3, 4, 4, 5, 5 };

        list.dedupe2();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case4 )
    {
        auto list = dedupe{ 1, 1, 1, 1, 1 };

        list.dedupe2();

        const auto actual = list.get_values();
        const auto expected = std::vector{ 1 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, dedupe2_case5 )
    {
        auto list = dedupe{ 1, 2, 2, 2 };

        list.dedupe2();

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
        auto list = klast<int>();

        const auto actual = list.from_back1(3);
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( klast_tests, klast1_case1 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 0 );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case2 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 1 );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case3 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 2 );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case4 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 5 );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dedupe_tests, klast1_case5 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 7 );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for dedupe.
    /// </summary>
    class delete_middle_tests :
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
    // delete middle 1
    //

    TEST_F( delete_middle_tests, del_mid1_invalid )
    {
        auto list = delete_middle<std::string>();

        list.delete_middle1();
        
        const auto actual = list.get_values();
        const auto expected = std::vector<std::string>{ };
  
        EXPECT_EQ( actual, expected );
    }

    TEST_F( delete_middle_tests, del_mid1_case1 )
    {
        auto list = delete_middle{ "a", "b", "c" };

        list.delete_middle1();

        const auto actual = list.get_values();
        const auto expected = std::vector<std::string>{ "a", "c" };

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( delete_middle_tests, del_mid1_case2 )
    {
        auto list = delete_middle{ "a", "b", "c", "d", "e" };

        list.delete_middle1();

        const auto actual = list.get_values();
        const auto expected = std::vector<std::string>{ "a", "b", "d", "e" };
    	
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( delete_middle_tests, del_mid1_case3 )
    {
        auto list = delete_middle{ "a", "b", "c", "d", "e", "f" };

        list.delete_middle1();

        const auto actual = list.get_values();
        const auto expected = std::vector<std::string>{ "a", "b", "c", "e", "f" };

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( delete_middle_tests, del_mid1_case4 )
    {
        auto list = delete_middle{ "a", "b", "c", "d", "e", "f", "g" };

        list.delete_middle1();

        const auto actual = list.get_values();
        const auto expected = std::vector<std::string>{ "a", "b", "c", "e", "f", "g" };

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( delete_middle_tests, del_mid1_case5 )
    {
        auto list = delete_middle{ "a", "b" };

        list.delete_middle1();

        const auto actual = list.get_values();
        const auto expected = std::vector<std::string>{ "a", "b" };

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }
}