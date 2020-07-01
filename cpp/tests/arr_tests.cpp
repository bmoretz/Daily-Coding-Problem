#include "pch.h"
#include <gtest/gtest.h>

#include "../problems/arr.h"

using namespace arr_problems;

namespace problems::arr_tests
{
    using namespace matrix_problems;

    /// <summary>
    /// Testing class for matrix rotation.
    /// </summary>
    class matrix_rotation_tests :
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
    // Matrix Rotate 1
    //

    TEST_F( matrix_rotation_tests, rotate1_case1 )
    {
        auto mat = matrix( 2 );

        matrix::set_incremental_values( mat );

        auto actual = rotate1::rotate( mat );

        const auto expected = matrix( {
            { 3, 1 },
            { 4, 2 }
            } );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_rotation_tests, rotate1_case2 )
    {
        auto mat = matrix( 3 );

        matrix::set_incremental_values( mat );

        auto actual = rotate1::rotate( mat );

        const auto expected = matrix( {
            { 7, 4, 1 },
            { 8, 5, 2 },
            { 9, 6, 3 }
            } );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_rotation_tests, rotate1_case3 )
    {
        auto mat = matrix( 4 );

        matrix::set_incremental_values( mat );

        auto actual = rotate1::rotate( mat );

        const auto expected = matrix( {
            { 13,  9, 5, 1 },
            { 14, 10, 6, 2 },
            { 15, 11, 7, 3 },
            { 16, 12, 8, 4 }
            } );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_rotation_tests, rotate1_case4 )
    {
        auto mat = matrix( 5 );

        matrix::set_incremental_values( mat );

        auto actual = rotate1::rotate( mat );

        const auto expected = matrix( {
            { 21, 16, 11,  6, 1 },
            { 22, 17, 12,  7, 2 },
            { 23, 18, 13,  8, 3 },
            { 24, 19, 14,  9, 4 },
            { 25, 20, 15, 10, 5 }
            } );

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for zero matrix.
    /// </summary>
    class zero_matrix_tests :
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
    // Zero Matrix 1
    //

    TEST_F( zero_matrix_tests, zero1_case1 )
    {
        auto actual = matrix( {
            {1, 0, 1, 1, 1},
            {1, 1, 0, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
		} );

        zero1::zero( actual );

        const auto expected = matrix( {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 0, 0, 1, 0},
            {0, 0, 0, 0, 0},
            {1, 0, 0, 1, 0},
		} );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( zero_matrix_tests, zero1_case2 )
    {
        auto actual = matrix( {
            {1, 1, 1, 1, 1},
            {1, 1, 0, 1, 1},
            {0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
		} );

        zero1::zero( actual );

        const auto expected = matrix( {
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 0, 1, 0},
		} );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( zero_matrix_tests, zero1_case3 )
    {
        auto actual = matrix( {
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
        } );

        zero1::zero( actual );

        const auto expected = matrix( {
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0},
        } );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( zero_matrix_tests, zero1_case4 )
    {
        auto actual = matrix( {
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 0, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
        } );

        zero1::zero( actual );

        const auto expected = matrix( {
            {1, 1, 0, 1, 1},
            {1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {1, 1, 0, 1, 1},
            {1, 1, 0, 1, 1},
        } );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( zero_matrix_tests, zero1_case5 )
    {
        auto actual = matrix( {
            {1, 0, 1, 0, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
        } );

        zero1::zero( actual );

        const auto expected = matrix( {
            {0, 0, 0, 0, 0},
            {1, 0, 1, 0, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 1, 0, 1},
		} );

        EXPECT_EQ( actual, expected );
    }
}