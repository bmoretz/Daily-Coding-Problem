#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/matrix.h"

namespace leetcode::matrix::tests
{
    class matrix_search_ii_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( matrix_search_ii_tests, case1 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            { 1,   4,  7, 11, 15 },
            { 2,   5,  8, 12, 19 },
            { 3,   6,  9, 16, 22 },
            { 10, 13, 14, 17, 24 },
            { 18, 21, 23, 26, 30 }
        };

        const auto actual = matrix_search_ii::search_matrix( input, 20 );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_search_ii_tests, case2 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            { 1,   4,  7, 11, 15 },
            { 2,   5,  8, 12, 19 },
            { 3,   6,  9, 16, 22 },
            { 10, 13, 14, 17, 24 },
            { 18, 21, 23, 26, 30 }
        };

        const auto actual = matrix_search_ii::search_matrix( input, 5 );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_search_ii_tests, case3 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            {
                241, 348, 801, 822, 1204, 1438, 1917, 1954, 2030, 2253, 2547, 2723, 3147, 3259, 3635, 3963, 4251, 4440,
                4848, 5195, 5264, 5410, 5537, 5844, 6138, 6604, 6693, 6876, 7148, 7307, 7504, 7788, 7821, 7990, 8112, 8447,
                8588, 8988, 9104, 9532, 9742, 10148, 10391, 10828, 11296, 11699, 12059, 12245, 12741, 12754, 13119, 13178,
                13436, 13798, 14233, 14510, 14775, 15049, 15154, 15192, 15395, 15803, 15941, 16388, 16655, 16676, 16901,
                17220, 17686, 18077, 18239, 18666, 18973, 19323, 19356, 19464, 19743, 19933, 20030, 20183, 20228, 20515,
                20974, 21429, 21524, 21896, 22298, 22447, 22622, 23109, 23214, 23701, 24096, 24434, 24514, 24834, 25029,
                25303, 25336, 25747, 26012, 26455, 26844, 27226, 27291, 27566, 27885, 28343, 28412, 28625, 28806, 29107,
                29358, 29637, 29649, 29970, 30137, 30253, 30657, 31069, 31177, 31576, 31988, 32146, 32545, 32715, 32963,
                32971, 33096, 33530, 33603, 33721, 34091, 34449, 34630, 34886, 35129, 35211, 35659, 36136, 36429, 36734,
                36956, 37137, 37625, 37905, 37980, 38138, 38553, 38563, 38877, 38984, 39065, 39501, 39623, 40118, 40504,
                40782, 40860, 41168, 41508, 41833, 42278, 42757, 43127, 43206, 43399, 43450, 43725, 43884, 44155, 44457,
                44818, 44894
            }
        };

        const auto actual = matrix_search_ii::search_matrix( input, 42757 );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_search_ii_tests, case4 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            {
                241, 348, 801, 822, 1204, 1438, 1917, 1954, 2030, 2253, 2547, 2723, 3147, 3259, 3635, 3963, 4251, 4440,
                4848, 5195, 5264, 5410, 5537, 5844, 6138, 6604, 6693, 6876, 7148, 7307, 7504, 7788, 7821, 7990, 8112, 8447,
                8588, 8988, 9104, 9532, 9742, 10148, 10391, 10828, 11296, 11699, 12059, 12245, 12741, 12754, 13119, 13178,
                13436, 13798, 14233, 14510, 14775, 15049, 15154, 15192, 15395, 15803, 15941, 16388, 16655, 16676, 16901,
                17220, 17686, 18077, 18239, 18666, 18973, 19323, 19356, 19464, 19743, 19933, 20030, 20183, 20228, 20515,
                20974, 21429, 21524, 21896, 22298, 22447, 22622, 23109, 23214, 23701, 24096, 24434, 24514, 24834, 25029,
                25303, 25336, 25747, 26012, 26455, 26844, 27226, 27291, 27566, 27885, 28343, 28412, 28625, 28806, 29107,
                29358, 29637, 29649, 29970, 30137, 30253, 30657, 31069, 31177, 31576, 31988, 32146, 32545, 32715, 32963,
                32971, 33096, 33530, 33603, 33721, 34091, 34449, 34630, 34886, 35129, 35211, 35659, 36136, 36429, 36734,
                36956, 37137, 37625, 37905, 37980, 38138, 38553, 38563, 38877, 38984, 39065, 39501, 39623, 40118, 40504,
                40782, 40860, 41168, 41508, 41833, 42278, 42757, 43127, 43206, 43399, 43450, 43725, 43884, 44155, 44457,
                44818, 44894
            }
        };

        const auto actual = matrix_search_ii::search_matrix( input, 102721 );
        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( matrix_search_ii_tests, case5 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            {
                241, 348, 801, 822, 1204, 1438, 1917, 1954, 2030, 2253, 2547, 2723, 3147, 3259, 3635, 3963, 4251, 4440,
                4848, 5195, 5264, 5410, 5537, 5844, 6138, 6604, 6693, 6876, 7148, 7307, 7504, 7788, 7821, 7990, 8112, 8447,
                8588, 8988, 9104, 9532, 9742, 10148, 10391, 10828, 11296, 11699, 12059, 12245, 12741, 12754, 13119, 13178,
                13436, 13798, 14233, 14510, 14775, 15049, 15154, 15192, 15395, 15803, 15941, 16388, 16655, 16676, 16901,
                17220, 17686, 18077, 18239, 18666, 18973, 19323, 19356, 19464, 19743, 19933, 20030, 20183, 20228, 20515,
                20974, 21429, 21524, 21896, 22298, 22447, 22622, 23109, 23214, 23701, 24096, 24434, 24514, 24834, 25029,
                25303, 25336, 25747, 26012, 26455, 26844, 27226, 27291, 27566, 27885, 28343, 28412, 28625, 28806, 29107,
                29358, 29637, 29649, 29970, 30137, 30253, 30657, 31069, 31177, 31576, 31988, 32146, 32545, 32715, 32963,
                32971, 33096, 33530, 33603, 33721, 34091, 34449, 34630, 34886, 35129, 35211, 35659, 36136, 36429, 36734,
                36956, 37137, 37625, 37905, 37980, 38138, 38553, 38563, 38877, 38984, 39065, 39501, 39623, 40118, 40504,
                40782, 40860, 41168, 41508, 41833, 42278, 42757, 43127, 43206, 43399, 43450, 43725, 43884, 44155, 44457,
                44818, 44894
            }
        };

        const auto actual = matrix_search_ii::search_matrix( input, 24434 );
        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    class number_of_islands_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( number_of_islands_tests, case1 )
    {
        const auto input = std::vector<std::vector<char>>
        {
	        { '1', '1', '0', '0', '0' },
	        { '1', '1', '0', '0', '0' },
	        { '0', '0', '1', '0', '0' },
	        { '0', '0', '0', '1', '1' }
        };

        const auto actual = number_of_islands::num_islands( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_islands_tests, case2 )
    {
        const auto input = std::vector<std::vector<char>>
        {
            { '1', '1', '1', '1', '0' },
            { '1', '1', '0', '1', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '0', '0', '0' }
        };

        const auto actual = number_of_islands::num_islands( input );
        const auto expected = 1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_islands_tests, case3 )
    {
        const auto input = std::vector<std::vector<char>>
        {
            { '1', '1', '1', '1', '0' },
            { '1', '1', '0', '1', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '0', '0', '0' },
            { '0', '0', '0', '1', '0' },
            { '0', '0', '1', '1', '0' },
            { '0', '0', '0', '0', '0' }
        };

        const auto actual = number_of_islands::num_islands( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_islands_tests, case4 )
    {
        const auto input = std::vector<std::vector<char>>
        {
            { '1', '1', '1', '1', '0' },
            { '1', '1', '0', '1', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '0', '0', '0' },
            { '0', '0', '0', '1', '0' },
            { '0', '0', '1', '1', '0' },
            { '0', '0', '0', '0', '1' }
        };

        const auto actual = number_of_islands::num_islands( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( number_of_islands_tests, case5 )
    {
        const auto input = std::vector<std::vector<char>>
        {
            { '1', '1', '1', '1', '0' },
            { '1', '1', '0', '1', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '0', '0', '0' },
            { '0', '0', '0', '1', '0' },
            { '0', '0', '1', '1', '0' },
            { '0', '0', '0', '1', '1' }
        };

        const auto actual = number_of_islands::num_islands( input );
        const auto expected = 2;

        EXPECT_EQ( actual, expected );
    }

    class shortest_path_binary_matrix_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( shortest_path_binary_matrix_tests, case1 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            {0, 0, 0},
            {1, 1, 0},
            {1, 1, 0}
        };

        const auto actual = shortest_path_binary_matrix::shortest_path( input );
        const auto expected = 4;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( shortest_path_binary_matrix_tests, case2 )
    {
        const auto input = std::vector<std::vector<int>>
        {
	        {0, 0, 0},
	        {1, 1, 0},
	        {1, 1, 1}
        };

        const auto actual = shortest_path_binary_matrix::shortest_path( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( shortest_path_binary_matrix_tests, case3 )
    {
        const auto input = std::vector<std::vector<int>>
        {
	        {1, 0, 0},
	        {1, 0, 0},
	        {1, 1, 0}
        };

        const auto actual = shortest_path_binary_matrix::shortest_path( input );
        const auto expected = -1;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( shortest_path_binary_matrix_tests, case4 )
    {
        const auto input = std::vector<std::vector<int>>
        {
	        {0, 0, 0, 0, 1, 1},
	        {0, 1, 0, 0, 1, 0},
	        {1, 1, 0, 1, 0, 0},
	        {0, 1, 0, 0, 1, 1},
	        {0, 1, 0, 0, 0, 1},
	        {0, 0, 1, 0, 0, 0}
        };

        const auto actual = shortest_path_binary_matrix::shortest_path( input );
        const auto expected = 7;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( shortest_path_binary_matrix_tests, case5 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            {0, 0, 0, 0, 1, 1},
            {0, 1, 0, 0, 1, 0},
            {1, 1, 1, 1, 0, 0},
            {0, 1, 0, 0, 1, 0},
            {0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0}
        };

        const auto actual = shortest_path_binary_matrix::shortest_path( input );
        const auto expected = 8;

        EXPECT_EQ( actual, expected );
    }

    class distinct_islands_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( distinct_islands_tests, case1 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            { 1, 1, 0, 0, 0 },
            { 1, 1, 0, 0, 0 },
            { 0, 0, 0, 1, 1 },
            { 0, 0, 0, 1, 1 }
        };

        const auto actual = distinct_islands::num_distinct_islands( input );
        const auto expected = 1;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( distinct_islands_tests, case2 )
    {
        const auto input = std::vector<std::vector<int>>
        {
	        { 1, 1, 0, 1, 1 },
	        { 1, 0, 0, 0, 0 },
	        { 0, 0, 0, 0, 1 },
	        { 1, 1, 0, 1, 1 }
        };

        const auto actual = distinct_islands::num_distinct_islands( input );
        const auto expected = 3;

        EXPECT_EQ( actual, expected );
    }

    class image_fill_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( image_fill_tests, case1 )
    {
        auto input = std::vector<std::vector<int>>
        {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
        };

        const auto actual = image_fill::flood_fill( input, 1, 1, 2 );
        const auto expected = std::vector<std::vector<int>>
        {
			{ 2, 2, 2 },
        	{ 2, 2, 0 },
        	{ 2, 0, 1 }
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( image_fill_tests, case2 )
    {
        auto input = std::vector<std::vector<int>>
        {
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 1, 0}
        };

        const auto actual = image_fill::flood_fill( input, 1, 1, 2 );
        const auto expected = std::vector<std::vector<int>>
        {
            {2, 2, 2, 2},
            {2, 2, 0, 0},
            {2, 0, 1, 0}
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( image_fill_tests, case3 )
    {
        auto input = std::vector<std::vector<int>>
        {
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 1, 0},
            {1, 0, 1, 0}
        };

        const auto actual = image_fill::flood_fill( input, 1, 1, 2 );
        const auto expected = std::vector<std::vector<int>>
        {
            {2, 2, 2, 2},
            {2, 2, 0, 0},
            {2, 0, 1, 0},
            {2, 0, 1, 0}
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( image_fill_tests, case4 )
    {
        auto input = std::vector<std::vector<int>>
        {
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 1, 0},
            {1, 0, 1, 0},
            {1, 0, 1, 0},
        };

        const auto actual = image_fill::flood_fill( input, 1, 1, 2 );
        const auto expected = std::vector<std::vector<int>>
        {
            {2, 2, 2, 2},
            {2, 2, 0, 0},
            {2, 0, 1, 0},
            {2, 0, 1, 0},
            {2, 0, 1, 0},
        };

        EXPECT_EQ( actual, expected );
    }
}