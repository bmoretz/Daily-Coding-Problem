#include "pch.h"

#include <gtest/gtest.h>

#include "../hackerrank/debug.h"

using namespace hackerrank::debug;

namespace hackerrank::debug_tests
{
    /// <summary>
    /// Testing class for variable_sized_arrays.
    /// </summary>
    class inherited_code_tests :
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
    // Inherited Code, test cases
    //

    TEST_F( inherited_code_tests, run_test_cases )
    {
        const auto problem =
	        inherited_code{ "inherited-code-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for exceptional_server.
    /// </summary>
    class exceptional_server_tests :
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
    // Exceptional Server, test cases
    //
	
    TEST_F( exceptional_server_tests, run_test_cases )
    {
    	// test execution takes too long.
    	
    	/*
        const auto problem =
            exceptional_server{ "exceptional-server-testcases" };

        EXPECT_TRUE( problem.run() );
        */
    }

    /// <summary>
    /// Testing class for hotel_room.
    /// </summary>
    class hotel_room_tests :
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
    // Exceptional Server, test cases
    //

    TEST_F( hotel_room_tests, run_test_cases )
    { 
        const auto problem =
            hotel_prices{ "hotel-prices-testcases" };

        EXPECT_TRUE( problem.run() );
    }

    /// <summary>
    /// Testing class for hotel_room.
    /// </summary>
    class exception_handling_tests :
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
    // Exceptional Server, test cases
    //

    TEST_F( exception_handling_tests, run_test_cases )
    {
        const auto problem =
            exception_handling{ "cpp-exception-handling-testcases" };

        EXPECT_TRUE( problem.run() );
    }
}