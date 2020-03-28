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
}