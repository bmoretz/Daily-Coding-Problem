#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/simulation.h"

namespace leetcode::simulation::tests
{
    class prison_cells_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( prison_cells_tests, case1 )
    {
        const auto input = std::vector<int>
        {
            0, 1, 0, 1, 1, 0, 0, 1
        };

        const auto actual = prison_cells::prisonAfterNDays( input, 7 );
        const auto expected = std::vector<int>{ 0, 0, 1, 1, 0, 0, 0, 0 };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( prison_cells_tests, case2 )
    {
        const auto input = std::vector<int>
        {
            0, 1, 0, 1, 1, 0, 0, 1
        };

        const auto actual = prison_cells::prisonAfterNDays( input, 20 );
        const auto expected = std::vector<int>{ 0, 0, 1, 0, 1, 1, 0, 0 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( prison_cells_tests, case3 )
    {
        const auto input = std::vector<int>
        {
            0, 1, 0, 1, 1, 0, 0, 1
        };

        const auto actual = prison_cells::prisonAfterNDays( input, 100 );
        const auto expected = std::vector<int>{ 0, 0, 0, 0, 1, 1, 1, 0 };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( prison_cells_tests, case4 )
    {
        const auto input = std::vector<int>
        {
            0, 1, 0, 1, 1, 0, 0, 1
        };

        const auto actual = prison_cells::prisonAfterNDays( input, 10000 );
        const auto expected = std::vector<int>{ 0, 0, 0, 0, 0, 1, 0, 0 };

        EXPECT_EQ( actual, expected );
    }
}