#include "pch.h"
#include <gtest/gtest.h>

#include "../problems/linkedlist.h"

using namespace linkedlist_problems;

namespace problems::linkedlist_tests
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

    TEST_F( klast_tests, klast1_case2 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 1 );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( klast_tests, klast1_case3 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 2 );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( klast_tests, klast1_case4 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 5 );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( klast_tests, klast1_case5 )
    {
        auto list = klast{ 1, 2, 3, 4, 5, 6 };

        const auto actual = list.from_back1( 7 );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for delete middle.
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

    /// <summary>
    /// Testing class for partition.
    /// </summary>
    class partition_tests :
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
    // partition 1
    //

    TEST_F( partition_tests, partition1_invalid )
    {
        auto list = partition<int>();

        list.partition1( int() );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( partition_tests, partition1_case1 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1 };

        list.partition1( 5 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 3, 2, 1, 5, 8, 5, 10 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition1_case2 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1, 6, 8 };

        list.partition1( 3 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 2, 1, 8, 3, 5, 8, 5, 10, 6 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition1_case3 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1, 6, 8 };

        list.partition1( 6 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 3, 5, 5, 2, 1, 8, 8, 10, 6 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition1_case4 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1, 6, 8, 4, 7, 3 };

        list.partition1( 3 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 2, 1, 3, 3, 5, 8, 5, 10, 6, 8, 4, 7 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition1_case5 )
    {
        auto list = partition<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

        list.partition1( 6 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 9, 8, 7, 6 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    //
    // partition 2
    //

    TEST_F( partition_tests, partition2_invalid )
    {
        auto list = partition<int>();

        list.partition2( int() );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( partition_tests, partition2_case1 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1 };

        list.partition2( 5 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 3, 2, 1, 5, 8, 5, 10 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition2_case2 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1, 6, 8 };

        list.partition2( 3 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 2, 1, 3, 5, 8, 5, 10, 6, 8 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition2_case3 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1, 6, 8 };

        list.partition2( 6 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 3, 5, 5, 2, 1, 8, 10, 6, 8 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition2_case4 )
    {
        auto list = partition<int>{ 3, 5, 8, 5, 10, 2, 1, 6, 8, 4, 7, 3 };

        list.partition2( 3 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 2, 1, 3, 5, 8, 5, 10, 6, 8, 4, 7, 3 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( partition_tests, partition2_case5 )
    {
        auto list = partition<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

        list.partition2( 6 );

        const auto actual = list.get_values();
        const auto expected = std::vector<int>{ 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 9, 8, 7, 6 };

        EXPECT_EQ( actual, expected );

        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    /// <summary>
    /// Testing class for sum list.
    /// </summary>
    class sum_list_tests :
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
    // backward sum list
    //

    TEST_F( sum_list_tests, backward_sum_list_empty )
    {
	    const auto list = sum_list();

        const auto sum = list.backward_sum();
    	
        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sum_list_tests, backward_sum_list_identity )
    {
        const auto list = sum_list( { 9, 6 }, { } );

        const auto sum = list.backward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 6, 9 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }
	
    TEST_F( sum_list_tests, backward_sum_list__case1 )
    {
        // 55 + 39 = 94
        const auto list = sum_list{ { 5, 5 }, { 3, 9 } };

        const auto sum = list.backward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 4, 9 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( sum_list_tests, backward_sum_list_case2 )
    {
        // 617 + 295 = 912
        const auto list = sum_list{ { 6, 1, 7 }, { 2, 9, 5 } };

        const auto sum = list.backward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 2, 1, 9 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( sum_list_tests, backward_sum_list_case3 )
    {
        // 5612 + 87 = 5699
        const auto list = sum_list{ { 5, 6, 1, 2 }, { 8, 7 } };

        const auto sum = list.backward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 9, 9, 6, 5 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( sum_list_tests, backward_sum_list_case4 )
    {
        // 5612 + 88 = 5700
        const auto list = sum_list{ { 5, 6, 1, 2 }, { 8, 8 } };

        const auto sum = list.backward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 0, 0, 7, 5 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    //
    // forward sum list
    //

    TEST_F( sum_list_tests, forward_sum_list_empty )
    {
        const auto list = sum_list();

        const auto sum = list.forward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( sum_list_tests, forward_sum_list_identity )
    {
        const auto list = sum_list( { 9, 6 }, { } );

        const auto sum = list.forward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 6, 9 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( sum_list_tests, forward_sum_list_case2 )
    {
        // 617 + 295 = 912
        const auto list = sum_list{ { 7, 1, 6 }, { 5, 9, 2 } };

        const auto sum = list.forward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 9, 1, 2 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( sum_list_tests, forward_sum_list_case3 )
    {
        // 2196 + 87 = 2274
        const auto list = sum_list{ { 6, 9, 1, 2 }, { 8, 7 } };

        const auto sum = list.forward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 2, 2, 7, 4 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    TEST_F( sum_list_tests, forward_sum_list_case4 )
    {
        // 5612 + 88 = 5700
        const auto list = sum_list{ { 2, 1, 6, 5 }, { 8, 8 } };

        const auto sum = list.forward_sum();

        const auto actual = sum->get_values();
        const auto expected = std::vector<int>{ 5, 7, 0, 0 };

        EXPECT_EQ( actual, expected );
        EXPECT_TRUE( std::equal( actual.begin(), actual.end(), expected.begin() ) );
    }

    /// <summary>
    /// Testing class for is palindrome.
    /// </summary>
    class is_palindrome_tests :
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
    // is palindrome 1 tests
    //

    TEST_F( is_palindrome_tests, is_palindrome1_list_empty )
    {
        const auto list = is_palindrome<std::string> { };

        const auto actual = list.is_palindrome1();
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_palindrome_tests, is_palindrome1_case1 )
    {
        const auto list = is_palindrome<std::string>{ "a" };

        const auto actual = list.is_palindrome1();
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_palindrome_tests, is_palindrome1_case2 )
    {
        const auto list = is_palindrome<std::string>{ "a", "b" };

        const auto actual = list.is_palindrome1();
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_palindrome_tests, is_palindrome1_case3 )
    {
        const auto list = is_palindrome<std::string>{ "a", "b", "a" };

        const auto actual = list.is_palindrome1();
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_palindrome_tests, is_palindrome1_case4 )
    {
        const auto list = is_palindrome<std::string>{ "a", "b", "b", "a" };

        const auto actual = list.is_palindrome1();
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( is_palindrome_tests, is_palindrome1_case5 )
    {
        const auto list = is_palindrome<std::string>{ "a", "b", "d", "a" };

        const auto actual = list.is_palindrome1();
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for intersection.
    /// </summary>
    class intersection_tests :
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
    // intersection 1 tests
    //

    TEST_F( intersection_tests, intersection1_invalid )
    {
        const auto list = intersection{ {}, {}, 0 };

        const auto actual = list.find_intersect1();
        const auto expected = nullptr;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( intersection_tests, intersection1_case1 )
    {
        const auto list = intersection<int>{
            { 1, 2, 3, 4, 5, 6 },
            { 5, 6, 7 },
        3 };
    	
        const auto actual = list.find_intersect1();
        const auto expected = 3;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection1_case2 )
    {
        const auto list = intersection<int>{
            { 5, 6, 7 },
            { 1, 2, 3, 4, 5, 6 },
        3 };

        const auto actual = list.find_intersect1();
        const auto expected = 3;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection1_case3 )
    {
        const auto list = intersection<int>{
            { 5, 6, 7 },
            { 1, 2, 3, 4, 5, 6 },
        6 };

        const auto actual = list.find_intersect1();
        const auto expected = 6;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection1_case4 )
    {
        const auto list = intersection<int>{
            { 1 },
            { 2, },
        1 };

        const auto actual = list.find_intersect1();
        const auto expected = 1;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection1_case5 )
    {
        const auto list = intersection<int>{
            { 1, 2, 3, 4 },
            { 9, 8, 7, 6, 5 },
        4 };

        const auto actual = list.find_intersect1();
        const auto expected = 4;

        EXPECT_TRUE( actual->value == expected );
    }

    //
    // intersection 2 tests
    //

    TEST_F( intersection_tests, intersection2_invalid )
    {
        const auto list = intersection{ {}, {}, 0 };

        const auto actual = list.find_intersect2();
        const auto expected = nullptr;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( intersection_tests, intersection2_case1 )
    {
        const auto list = intersection<int>{
            { 1, 2, 3, 4, 5, 6 },
            { 5, 6, 7 },
        3 };

        const auto actual = list.find_intersect2();
        const auto expected = 3;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection2_case2 )
    {
        const auto list = intersection<int>{
            { 5, 6, 7 },
            { 1, 2, 3, 4, 5, 6 },
        3 };

        const auto actual = list.find_intersect2();
        const auto expected = 3;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection2_case3 )
    {
        const auto list = intersection<int>{
            { 5, 6, 7 },
            { 1, 2, 3, 4, 5, 6 },
        6 };

        const auto actual = list.find_intersect2();
        const auto expected = 6;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection2_case4 )
    {
        const auto list = intersection<int>{
            { 1 },
            { 2, },
        1 };

        const auto actual = list.find_intersect2();
        const auto expected = 1;

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( intersection_tests, intersection2_case5 )
    {
        const auto list = intersection<int>{
            { 1, 2, 3, 4 },
            { 9, 8, 7, 6, 5 },
        4 };

        const auto actual = list.find_intersect2();
        const auto expected = 4;

        EXPECT_TRUE( actual->value == expected );
    }

    /// <summary>
    /// Testing class for loop detection.
    /// </summary>
    class loop_detection_tests :
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
    // loop detection 1 tests
    //

    TEST_F( loop_detection_tests, loop_detect1_invalid )
    {
        auto list = loop_detect<std::string>();

        const auto actual = list.detect_loop1();
        const auto expected = nullptr;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( loop_detection_tests, loop_detect1_case1 )
    {
        auto list = loop_detect<std::string> { "A", "B", "C", "D", "E", "F" };

        list.set_loop( "C" );
    	
        const auto actual = list.detect_loop1();
        const auto expected = "C";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect1_case2 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        list.set_loop( "A" );

        const auto actual = list.detect_loop1();
        const auto expected = "A";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect1_case3 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        list.set_loop( "D" );

        const auto actual = list.detect_loop1();
        const auto expected = "D";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect1_case4 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        list.set_loop( "E" );

        const auto actual = list.detect_loop1();
        const auto expected = "E";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect1_case5 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        const auto actual = list.detect_loop1();
        const auto expected = nullptr;

        EXPECT_TRUE( actual == expected );
    }

    //
    // loop detection 1 tests
    //

    TEST_F( loop_detection_tests, loop_detect2_invalid )
    {
        auto list = loop_detect<std::string>();

        const auto actual = list.detect_loop2();
        const auto expected = nullptr;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( loop_detection_tests, loop_detect2_case1 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        list.set_loop( "C" );

        const auto actual = list.detect_loop1();
        const auto expected = "C";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect2_case2 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        list.set_loop( "A" );

        const auto actual = list.detect_loop2();
        const auto expected = "A";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect2_case3 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        list.set_loop( "D" );

        const auto actual = list.detect_loop2();
        const auto expected = "D";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect2_case4 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        list.set_loop( "E" );

        const auto actual = list.detect_loop2();
        const auto expected = "E";

        EXPECT_TRUE( actual->value == expected );
    }

    TEST_F( loop_detection_tests, loop_detect2_case5 )
    {
        auto list = loop_detect<std::string>{ "A", "B", "C", "D", "E", "F" };

        const auto actual = list.detect_loop2();
        const auto expected = nullptr;

        EXPECT_TRUE( actual == expected );
    }
}