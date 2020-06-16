#include "pch.h"
#include <gtest/gtest.h>
#include <bitset>
#include <regex>

#include "../problems/bitmanip.h"

using namespace bitmanip_problems;

namespace bitmanip_tests
{
    /// <summary>
    /// Testing class for insertion.
    /// </summary>
    class insertion_tests :
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
    // Insertion 1
    //

    TEST_F( insertion_tests, insertion1_case1 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 19; // 10011

        const auto res = insertion1( n, m, 2, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10001001100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case2 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 31; // 11111

        const auto res = insertion1( n, m, 2, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10001111100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case3 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 63; // 111111

        const auto res = insertion1( n, m, 2, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10011111100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case4 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 63; // 111111

        const auto res = insertion1( n, m, 0, 5 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10000111111";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( insertion_tests, insertion1_case5 )
    {
        const auto n = 1024; // 10000000000
        const auto m = 63; // 111111

        const auto res = insertion1( n, m, 1, 6 );

        const auto actual = std::bitset<11>( res ).to_string();
        const auto expected = "10001111110";

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
	/// Testing class for decimal to binary (string).
	/// </summary>
    class dec_to_bin_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( dec_to_bin_tests, dec_to_bin_case1 )
    {
        const auto n = .72;

        const auto actual = dec_to_bin( n );
        const auto expected = ".0100100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case2 )
    {
        const auto n = .69;

        const auto actual = dec_to_bin( n );
        const auto expected = ".0100010";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case3 )
    {
        const auto n = 0.121841878;

        const auto actual = dec_to_bin( n );
        const auto expected = ".010111001111010100111100";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case4 )
    {
        const auto n = 0.1e-32;

        const auto actual = dec_to_bin( n );
        const auto expected = "ERROR";

        EXPECT_EQ( actual, expected );
    }

    TEST_F( dec_to_bin_tests, dec_to_bin_case5 )
    {
        const auto n = 0.1e-12;

        const auto actual = dec_to_bin( n );
        const auto expected = ".010011000100101100111111";

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for flip to win.
    /// </summary>
    class flip_to_win_tests :
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
    // Flip Bit to Win 1
    //

    TEST_F( flip_to_win_tests, flip_to_win1_case1 )
    {
        const auto num = 1775; // 11011101111

        const auto actual = flip_to_win( num );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( flip_to_win_tests, flip_to_win1_case2 )
    {
        const auto num = 1982; // 11110111110

        const auto actual = flip_to_win( num );
        const auto expected = 10;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( flip_to_win_tests, flip_to_win1_case3 )
    {
        const auto num = 20487; // 101000000000111

        const auto actual = flip_to_win( num );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( flip_to_win_tests, flip_to_win1_case4 )
    {
        const auto num = 3258749; // 1100011011100101111101

        const auto actual = flip_to_win( num );
        const auto expected = 7;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( flip_to_win_tests, flip_to_win1_case5 )
    {
        const auto num = 3221009; // 1100010010011000010001

        const auto actual = flip_to_win( num );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for next number.
    /// </summary>
    class next_number_tests :
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
    // Next Number 1
    //

    TEST_F( next_number_tests, next_number_case1 )
    {
        const auto num = 8; // 1000

        const auto actual = next_number::get_next( num );
        // 4 -> 0100
		// 16 -> 10000
    	const auto expected = std::make_tuple( 4, 16 );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( next_number_tests, next_number_case2 )
    {
        const auto num = 12; // 1100

        const auto actual = next_number::get_next( num );
    	// 10 -> 1010
    	// 17 -> 10001
        const auto expected = std::make_tuple( 10, 17 );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( next_number_tests, next_number_case3 )
    {
        const auto num = 11; // 0 1011

        const auto actual = next_number::get_next( num );
    	// 7 -> 0111
        // 13 -> 1101
        const auto expected = std::make_tuple( 7, 13 );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( next_number_tests, next_number_case4 )
    {
        const auto num = 24; // 01 1000

        const auto actual = next_number::get_next( num );
    	// 20 -> 01 0100
        // 33 -> 10 0001
        const auto expected = std::make_tuple( 20, 33 );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( next_number_tests, next_number_case5 )
    {
        const auto num = 326; // 101000110

        const auto actual = next_number::get_next( num );
        // 198 -> 11000110
        // 390 -> 110000110
        const auto expected = std::make_tuple( 198, 390 );

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for conversion.
    /// </summary>
    class conversion_tests :
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
    // Conversion 1
    //

    TEST_F( conversion_tests, conversion_tests_case1 )
    {
        const auto a = 29; // 11101
    	const auto b = 15; // 01111

        const auto actual = conversion1( a, b );
        const auto expected = 2;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( conversion_tests, conversion_tests_case2 )
    {
        const auto a = 65; // 1000001
        const auto b = 8; // 1000

        const auto actual = conversion1( a, b );
        const auto expected = 7;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( conversion_tests, conversion_tests_case3 )
    {
        const auto a = 126; // 1111110
        const auto b = 5; //   0000101

        const auto actual = conversion1( a, b );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( conversion_tests, conversion_tests_case4 )
    {
        const auto a = 84; // 1010100
        const auto b = 81; // 1010001

        const auto actual = conversion1( a, b );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( conversion_tests, conversion_tests_case5 )
    {
        const auto a = 92; // 1011100
        const auto b = 665; //   1010011001

        const auto actual = conversion1( a, b );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for pairwise swap.
    /// </summary>
    class pairwise_swap_tests :
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
    // Pairwise Swap 1
    //

    TEST_F( pairwise_swap_tests, pairwise_swap_tests_case1 )
    {
        const auto num = 172; // 10101100

        const auto actual = pairwise_swap( num );
        const auto expected = 92; // 0001011100

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pairwise_swap_tests, pairwise_swap_tests_case2 )
    {
        const auto num = 843; // 1101010101

        const auto actual = pairwise_swap( num );
        const auto expected = 903; // 1110000111

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pairwise_swap_tests, pairwise_swap_tests_case3 )
    {
        const auto num = 1586; // 11000110010

        const auto actual = pairwise_swap( num );
        const auto expected = 2353; // 0100110001

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pairwise_swap_tests, pairwise_swap_tests_case4 )
    {
        const auto num = 8563; // 10000101110011

        const auto actual = pairwise_swap( num );
        const auto expected = 4787; // 1010110011

        EXPECT_EQ( actual, expected );
    }

    TEST_F( pairwise_swap_tests, pairwise_swap_tests_case5 )
    {
        const auto num = 120528; // 011101011011010000

        const auto actual = pairwise_swap( num );
        const auto expected = 190944; // 0101110100111100000

        EXPECT_EQ( actual, expected );
    }

    /// <summary>
    /// Testing class for draw line.
    /// </summary>
    class draw_line_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }

    	static auto format_for_testing( const std::string& input )
    	{
            return std::regex_replace( input, std::regex( "[^0-1]" ), std::string() );
    	}
    };

    //
    // Draw Line 1
    //

    TEST_F( draw_line_tests, draw_line_tests_case1 )
    {
        const auto screen = byte_screen( 5, 5 );

        screen.draw_line( 2, 6, 3 );
    	
        const auto actual = format_for_testing( screen.get_display() );

        const auto expected = format_for_testing(
            "0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0011111000000000000000000000000000000000\
			0000000000000000000000000000000000000000");

        EXPECT_EQ( actual, expected );
    }

    TEST_F( draw_line_tests, draw_line_tests_case2 )
    {
        const auto screen = byte_screen( 5, 5 );

        screen.draw_line( 5, 10, 2 );

        const auto actual = format_for_testing( screen.get_display() );

        const auto expected = format_for_testing(
            "0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000011111100000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000");

        EXPECT_EQ( actual, expected );
    }

    TEST_F( draw_line_tests, draw_line_tests_case3 )
    {
        const auto screen = byte_screen( 5, 5 );

        screen.draw_line( 5, 10, 4 );

        const auto actual = format_for_testing( screen.get_display() );

        const auto expected = format_for_testing(
            "0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000011111100000000000000000000000000000");

        EXPECT_EQ( actual, expected );
    }

    TEST_F( draw_line_tests, draw_line_tests_case4 )
    {
        const auto screen = byte_screen( 5, 5 );

        screen.draw_line( 0, 39, 0 );

        const auto actual = format_for_testing( screen.get_display() );

        const auto expected = format_for_testing(
            "1111111111111111111111111111111111111111\
            0000000000000000000000000000000000000000\
            0000000000000000000000000000000000000000\
            0000000000000000000000000000000000000000\
            0000000000000000000000000000000000000000" );

        EXPECT_EQ( actual, expected );
    }

    TEST_F( draw_line_tests, draw_line_tests_case5 )
    {
        const auto screen = byte_screen( 5, 5 );

        screen.draw_line( 5, 10, 2 );

        const auto actual = format_for_testing( screen.get_display() );

        const auto expected = format_for_testing(
            "0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000011111100000000000000000000000000000\
			0000000000000000000000000000000000000000\
			0000000000000000000000000000000000000000" );

        EXPECT_EQ( actual, expected );
    }
}