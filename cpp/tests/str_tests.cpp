#include "pch.h"
#include <gtest/gtest.h>

#include "../problems/str.h"

using namespace std;
using namespace str_problems;

namespace string_tests
{
    /// <summary>
    /// Testing class for is_unique.
    /// </summary>
	class is_unique_tests :
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
    // Is Unique 1
    //

    TEST_F( is_unique_tests, unique1_invalid )
    {
        EXPECT_FALSE( unique1::is_unique( string() ) );
    }

    TEST_F( is_unique_tests, unique1_unique_sets )
    {
        EXPECT_TRUE( unique1::is_unique( "abcd" ) );
        EXPECT_TRUE( unique1::is_unique( "etiaz" ) );
        EXPECT_TRUE( unique1::is_unique( "opclea" ) );
        EXPECT_TRUE( unique1::is_unique( "zeily" ) );
        EXPECT_TRUE( unique1::is_unique( "zeily;" ) );
    }

    TEST_F( is_unique_tests, unique1_not_unique_sets )
    {
        EXPECT_FALSE( unique1::is_unique( "abcda" ) );
        EXPECT_FALSE( unique1::is_unique( "etiazi" ) );
        EXPECT_FALSE( unique1::is_unique( "opcleac" ) );
        EXPECT_FALSE( unique1::is_unique( "testaing" ) );
        EXPECT_FALSE( unique1::is_unique( ";tes;" ) );
    }

    //
    // Is Unique 2
    //

    TEST_F( is_unique_tests, unique2_invalid )
    {
        EXPECT_FALSE( unique2::is_unique( string() ) );
    }

    TEST_F( is_unique_tests, unique2_unique_sets )
    {
        EXPECT_TRUE( unique2::is_unique( "abcd" ) );
        EXPECT_TRUE( unique2::is_unique( "etiaz" ) );
        EXPECT_TRUE( unique2::is_unique( "opclea" ) );
        EXPECT_TRUE( unique2::is_unique( "zeily" ) );
        EXPECT_TRUE( unique2::is_unique( "zeily;" ) );
    }

    TEST_F( is_unique_tests, unique2not_unique_sets )
    {
        EXPECT_FALSE( unique2::is_unique( "abcda" ) );
        EXPECT_FALSE( unique2::is_unique( "etiazi" ) );
        EXPECT_FALSE( unique2::is_unique( "opcleac" ) );
        EXPECT_FALSE( unique2::is_unique( "testaing" ) );
        EXPECT_FALSE( unique2::is_unique( ";tes;" ) );
    }

    /// <summary>
    /// Testing class for is_permutation.
    /// </summary>
    class is_permutation_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( is_permutation_tests, permutation1_invalid )
    {
        EXPECT_FALSE( is_permutation1::is_permutation( string(), string() ) );
    }

    TEST_F( is_permutation_tests, permutation1_perms )
    {
        EXPECT_TRUE( is_permutation1::is_permutation( "abcd", "dcab" ) );
        EXPECT_TRUE( is_permutation1::is_permutation( "this is a perm", "perm is a siht" ) );
        EXPECT_TRUE( is_permutation1::is_permutation( "permutation", "noitatumrep" ) );
        EXPECT_TRUE( is_permutation1::is_permutation( "1 2 3 4", "3 2 1 4" ) );
    }

    TEST_F( is_permutation_tests, permutation1_not_perms )
    {
        EXPECT_FALSE( is_permutation1::is_permutation( "abcd", "abcda" ) );
        EXPECT_FALSE( is_permutation1::is_permutation( "this is a perm", "pem is a siht" ) );
        EXPECT_FALSE( is_permutation1::is_permutation( "permutatio", "notatumrep" ) );
        EXPECT_FALSE( is_permutation1::is_permutation( "1 2 3 4", "3 4 1 4" ) );
    }

    TEST_F( is_permutation_tests, permutation2_invalid )
    {
        EXPECT_FALSE( is_permutation2::is_permutation( string(), string() ) );
    }

    TEST_F( is_permutation_tests, permutation2_perms )
    {
        EXPECT_TRUE( is_permutation2::is_permutation( "abcd", "dcab" ) );
        EXPECT_TRUE( is_permutation2::is_permutation( "this is a perm", "perm is a siht" ) );
        EXPECT_TRUE( is_permutation2::is_permutation( "permutation", "noitatumrep" ) );
        EXPECT_TRUE( is_permutation2::is_permutation( "1 2 3 4", "3 2 1 4" ) );
    }

    TEST_F( is_permutation_tests, permutation2_not_perms )
    {
        EXPECT_FALSE( is_permutation2::is_permutation( "abcd", "abcda" ) );
        EXPECT_FALSE( is_permutation2::is_permutation( "this is a perm", "pem is a siht" ) );
        EXPECT_FALSE( is_permutation2::is_permutation( "permutatio", "notatumrep" ) );
        EXPECT_FALSE( is_permutation2::is_permutation( "1 2 3 4", "3 4 1 4" ) );
    }

	/// <summary>
	/// Testing class for Urlify.
	/// </summary>
    class urlify_tests :
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
    // Urlify 1
    //

    TEST_F( urlify_tests, urlify1_base )
    {
        auto actual = urlify1::urlify( "Mr John Smith    ", 13 );

        const auto expected = "Mr%20John%20Smith";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_end_space )
    {
        auto actual = urlify1::urlify( "MrJohnSmith   ", 12 );

        const auto expected = "MrJohnSmith%20";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_start_space )
    {
        auto actual = urlify1::urlify( " Mr John Smith      ", 14 );

        const auto expected = "%20Mr%20John%20Smith";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_no_space )
    {
        auto actual = urlify1::urlify( "MrJohnSmith", 4 );

        const auto expected = "MrJohnSmith";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_all_space )
    {
        auto actual = urlify1::urlify( "         ", 3 );

        const auto expected = "%20%20%20";

        EXPECT_EQ( actual, expected );
    }

	//
    // Urlify 2
    //

    TEST_F( urlify_tests, urlify2_base )
    {
        auto actual = urlify2::urlify( "Mr John Smith    ", 13 );

        const auto expected = "Mr%20John%20Smith";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify2_end_space )
    {
        auto actual = urlify2::urlify( "MrJohnSmith   ", 12 );

        const auto expected = "MrJohnSmith%20";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify2_start_space )
    {
        auto actual = urlify2::urlify( " Mr John Smith      ", 14 );

        const auto expected = "%20Mr%20John%20Smith";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify2_no_space )
    {
        auto actual = urlify2::urlify( "MrJohnSmith", 11 );

        const auto expected = "MrJohnSmith";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify2_all_space )
    {
        auto actual = urlify2::urlify( "         ", 3 );

        const auto expected = "%20%20%20";

        EXPECT_EQ( actual, expected );
    }
}