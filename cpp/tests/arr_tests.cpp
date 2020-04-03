#include "pch.h"
#include <gtest/gtest.h>

#include "../problems/arr.h"

using namespace std;
using namespace arr_problems;

namespace arr_tests
{
    using namespace matrix_rotation;
	
    /// <summary>
    /// Testing class for is_unique.
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
	    auto mat = Matrix( 2 );

        Matrix::set_incremental_values( mat );
    	
        auto actual = matrix_rotate1::rotate( mat );

	    const vector<vector<int>> matrix
    	{
    		{ 3, 1 },
			{ 4, 2 }
    	};
    	
        const auto expected = Matrix( matrix );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_rotation_tests, rotate1_case2 )
    {
        auto mat = Matrix( 3 );

        Matrix::set_incremental_values( mat );
    	
        auto actual = matrix_rotate1::rotate( mat );

        const vector<vector<int>> matrix
    	{
    		{ 7, 4, 1 },
        	{ 8, 5, 2 },
            { 9, 6, 3 }
    	};

        const auto expected = Matrix( matrix );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_rotation_tests, rotate1_case3 )
    {
        auto mat = Matrix( 4 );

        Matrix::set_incremental_values( mat );
    	
        auto actual = matrix_rotate1::rotate( mat );

        const vector<vector<int>> matrix
        {
            { 13,  9, 5, 1 },
            { 14, 10, 6, 2 },
            { 15, 11, 7, 3 },
            { 16, 12, 8, 4 }
        };

        const auto expected = Matrix( matrix );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_rotation_tests, rotate1_case4 )
    {
        auto mat = Matrix( 5 );

        Matrix::set_incremental_values( mat );
    	
    	auto actual = matrix_rotate1::rotate( mat );

        const vector<vector<int>> matrix
        {
            { 21, 16, 11,  6, 1 },
            { 22, 17, 12,  7, 2 },
            { 23, 18, 13,  8, 3 },
            { 24, 19, 14,  9, 4 },
            { 25, 20, 15, 10, 5 }
        };

        const auto expected = Matrix( matrix );

        EXPECT_EQ( actual, expected );
    }
}