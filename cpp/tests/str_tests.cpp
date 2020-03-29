#include "pch.h"
#include <gtest/gtest.h>

#include "../problems/str.h"

using namespace std;
using namespace str_problems;

namespace string_tests
{
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

    TEST_F( is_unique_tests, unique1_invalid )
    {
        EXPECT_FALSE( str::is_unique2( string() ) );
    }

    TEST_F( is_unique_tests, unique1_unique_sets )
    {
        EXPECT_TRUE( str::is_unique1( "abcd" ) );
        EXPECT_TRUE( str::is_unique1( "etiaz" ) );
        EXPECT_TRUE( str::is_unique1( "opclea" ) );
        EXPECT_TRUE( str::is_unique1( "zeily" ) );
        EXPECT_TRUE( str::is_unique1( "zeily;" ) );
    }

    TEST_F( is_unique_tests, unique1_not_unique_sets )
    {
        EXPECT_FALSE( str::is_unique1( "abcda" ) );
        EXPECT_FALSE( str::is_unique1( "etiazi" ) );
        EXPECT_FALSE( str::is_unique1( "opcleac" ) );
        EXPECT_FALSE( str::is_unique1( "testaing" ) );
        EXPECT_FALSE( str::is_unique1( ";tes;" ) );
    }

    TEST_F( is_unique_tests, unique2_invalid )
    {
        EXPECT_FALSE( str::is_unique2( string() ) );
    }

    TEST_F( is_unique_tests, unique2_unique_sets )
    {
        EXPECT_TRUE( str::is_unique1( "abcd" ) );
        EXPECT_TRUE( str::is_unique1( "etiaz" ) );
        EXPECT_TRUE( str::is_unique1( "opclea" ) );
        EXPECT_TRUE( str::is_unique1( "zeily" ) );
        EXPECT_TRUE( str::is_unique1( "zeily;" ) );
    }

    TEST_F( is_unique_tests, unique2not_unique_sets )
    {
        EXPECT_FALSE( str::is_unique1( "abcda" ) );
        EXPECT_FALSE( str::is_unique1( "etiazi" ) );
        EXPECT_FALSE( str::is_unique1( "opcleac" ) );
        EXPECT_FALSE( str::is_unique1( "testaing" ) );
        EXPECT_FALSE( str::is_unique1( ";tes;" ) );
    }

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
        EXPECT_FALSE( str::is_permutation1( string(), string() ) );
    }

    TEST_F( is_permutation_tests, permutation1_perms )
    {
        EXPECT_TRUE( str::is_permutation1( "abcd", "dcab" ) );
        EXPECT_TRUE( str::is_permutation1( "this is a perm", "perm is a siht" ) );
        EXPECT_TRUE( str::is_permutation1( "permutation", "noitatumrep" ) );
        EXPECT_TRUE( str::is_permutation1( "1 2 3 4", "3 2 1 4" ) );
    }

    TEST_F( is_permutation_tests, permutation1_not_perms )
    {
        EXPECT_FALSE( str::is_permutation1( "abcd", "abcda" ) );
        EXPECT_FALSE( str::is_permutation1( "this is a perm", "pem is a siht" ) );
        EXPECT_FALSE( str::is_permutation1( "permutatio", "notatumrep" ) );
        EXPECT_FALSE( str::is_permutation1( "1 2 3 4", "3 4 1 4" ) );
    }

    TEST_F( is_permutation_tests, permutation2_invalid )
    {
        EXPECT_FALSE( str::is_permutation2( string(), string() ) );
    }

    TEST_F( is_permutation_tests, permutation2_perms )
    {
        EXPECT_TRUE( str::is_permutation2( "abcd", "dcab" ) );
        EXPECT_TRUE( str::is_permutation2( "this is a perm", "perm is a siht" ) );
        EXPECT_TRUE( str::is_permutation2( "permutation", "noitatumrep" ) );
        EXPECT_TRUE( str::is_permutation2( "1 2 3 4", "3 2 1 4" ) );
    }

    TEST_F( is_permutation_tests, permutation2_not_perms )
    {
        EXPECT_FALSE( str::is_permutation2( "abcd", "abcda" ) );
        EXPECT_FALSE( str::is_permutation2( "this is a perm", "pem is a siht" ) );
        EXPECT_FALSE( str::is_permutation2( "permutatio", "notatumrep" ) );
        EXPECT_FALSE( str::is_permutation2( "1 2 3 4", "3 4 1 4" ) );
    }

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

    TEST_F( urlify_tests, urlify1_base )
    {
        auto actual = str::urlify1( "t e s t", 13 );

        const auto expected = "t%20e%20s%20t";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_end_space )
    {
        auto actual = str::urlify1( "t e s t ", 16 );

        const auto expected = "t%20e%20s%20t%20";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_start_space )
    {
        auto actual = str::urlify1( " t e s t ", 19 );

        const auto expected = "%20t%20e%20s%20t%20";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_no_space )
    {
        auto actual = str::urlify1( "test", 4 );

        const auto expected = "test";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( urlify_tests, urlify1_all_space )
    {
        auto actual = str::urlify1( "   ", 9 );

        const auto expected = "%20%20%20";

        EXPECT_EQ( actual, expected );
    }
}