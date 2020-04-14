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

        EXPECT_EQ( 1, 1 );
    }

    TEST_F( dedupe_tests, dedupe1_case1 )
    {
        auto list = dedupe1<int>{ 1, 2, 3, 4, 5 };

        list.remove_dupes();

        auto actual = list.get_values();
        auto expected = std::vector<int>{ 1, 2, 3, 4, 5 };

        EXPECT_EQ( actual, expected );
    }
}