#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/bfs.h"

namespace leetcode::bfs::tests
{
    class open_the_lock_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( open_the_lock_tests, case1 )
    {
        auto deadends = std::vector<std::string>
        {
            "0201","0101","0102","1212","2002"
        };

        auto actual = open_the_lock::open_lock( deadends, "0202" );

        const auto expected = 6;
    }
}
