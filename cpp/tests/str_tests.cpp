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

    /// <summary>
	/// Testing class for Palindrome Permutations.
	/// </summary>
    class palindrome_permutation_tests :
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
    // Palindrome Permutations 1
    //

    TEST_F( palindrome_permutation_tests, palperm1_empty )
    {
        auto actual = palperm1::is_palindrome_permutation( string() );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( palindrome_permutation_tests, palperm1_base )
    {
        auto actual = palperm1::is_palindrome_permutation( "taco cat");

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( palindrome_permutation_tests, palperm1_case1 )
    {
        auto actual = palperm1::is_palindrome_permutation( "atco cta" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( palindrome_permutation_tests, palperm1_case2 )
    {
        auto actual = palperm1::is_palindrome_permutation( "A nut for a jar of tuna" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( palindrome_permutation_tests, palperm1_case3 )
    {
        auto actual = palperm1::is_palindrome_permutation( "Amore, Roma." );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( palindrome_permutation_tests, palperm1_case4 )
    {
        auto actual = palperm1::is_palindrome_permutation( "Was it a car or a cat I saw ?" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( palindrome_permutation_tests, palperm1_case5 )
    {
        auto actual = palperm1::is_palindrome_permutation( "Ed, I saw Harpo Marx ram Oprah W. aside." );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }


    /// <summary>
    /// Testing class for One Away.
    /// </summary>
    class one_away_tests :
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
    // One Away 1
    //

    TEST_F( one_away_tests, oneaway1_empty )
    {
        auto actual = one_away1::one_away( string(), string() );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( one_away_tests, oneaway1_case1 )
    {
        auto actual = one_away1::one_away( "pale", "ple" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( one_away_tests, oneaway1_case2 )
    {
        auto actual = one_away1::one_away( "pales", "pale" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( one_away_tests, oneaway1_case3 )
    {
        auto actual = one_away1::one_away( "pale", "balep" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( one_away_tests, oneaway1_case4 )
    {
        auto actual = one_away1::one_away( "pale", "bake" );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( one_away_tests, oneaway1_case5 )
    {
        auto actual = one_away1::one_away( "PALE", "baLe" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( one_away_tests, oneaway1_case6 )
    {
        auto actual = one_away1::one_away( "PALE    ", "b    aLe" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( one_away_tests, oneaway1_case7 )
    {
        auto actual = one_away1::one_away( "PALE", "PALEB" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for String Compress.
    /// </summary>
    class string_compression_tests :
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
    // String Compression 1
    //

    TEST_F( string_compression_tests, compress1_empty )
    {
        auto actual = compress_str1::compressed( string() );

        const auto expected = string();

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_compression_tests, compress1_case1 )
    {
        auto actual = compress_str1::compressed( "aabcccccaa" );

        const auto expected = "a2b1c5a2";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_compression_tests, compress1_case2 )
    {
        auto actual = compress_str1::compressed( "fffff" );

        const auto expected = "f5";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_compression_tests, compress1_case3 )
    {
        auto actual = compress_str1::compressed( "fffffaaaaac" );

        const auto expected = "f5a5c1";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_compression_tests, compress1_case4 )
    {
        auto actual = compress_str1::compressed( "f" );

        const auto expected = "f";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_compression_tests, compress1_case5 )
    {
        auto actual = compress_str1::compressed( "bb" );

        const auto expected = "bb";

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for String Rotation.
    /// </summary>
    class string_rotation_tests :
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
    // String Rotation 1
    //

    TEST_F( string_rotation_tests, rotation1_empty )
    {
        EXPECT_FALSE( string_rotation1::is_rotation( string(), string() ) );
        EXPECT_FALSE( string_rotation1::is_rotation( "test", string() ) );
        EXPECT_FALSE( string_rotation1::is_rotation( string(), "test" ) );
    }

    TEST_F( string_rotation_tests, rotation1_case1 )
    {
        auto actual = string_rotation1::is_rotation( "waterbottle", "erbottlewat" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_rotation_tests, rotation1_case2 )
    {
        auto actual = string_rotation1::is_rotation( "waterbottle", "erbottlewa" );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_rotation_tests, rotation1_case3 )
    {
        auto actual = string_rotation1::is_rotation( "test", "estt" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_rotation_tests, rotation1_case4 )
    {
        auto actual = string_rotation1::is_rotation( "waterbottle", "bottlewater" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_rotation_tests, rotation1_case5 )
    {
        auto actual = string_rotation1::is_rotation( "water bottle", " bottlewater" );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( string_rotation_tests, rotation1_case6 )
    {
        auto actual = string_rotation1::is_rotation( "water bottle", " bottle water" );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }
}