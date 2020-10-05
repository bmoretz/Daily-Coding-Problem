#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/backtrack.h"

namespace leetcode::backtrack::tests
{
	class factor_combinations_tests :
		public testing::Test
	{
	protected:
		void SetUp() override
		{
		}

		void TearDown() override
		{
		}
	};

	TEST_F( factor_combinations_tests, case1 )
	{
		const auto input = 1;

		const auto actual = factor_combinations::get_factors( input );

		const auto expected = std::vector<std::vector<int>>{};

		EXPECT_EQ( actual, expected );
	}

	TEST_F( factor_combinations_tests, case2 )
	{
		const auto input = 6;

		const auto actual = factor_combinations::get_factors( input );

		const auto expected = std::vector<std::vector<int>>
		{
			{2, 3}
		};

		EXPECT_EQ( actual, expected );
	}

	TEST_F( factor_combinations_tests, case3 )
	{
		const auto input = 12;

		const auto actual = factor_combinations::get_factors( input );

		const auto expected = std::vector<std::vector<int>>
		{
			{2, 2, 3},
			{2, 6},
			{3, 4}
		};

		EXPECT_EQ( actual, expected );
	}

	TEST_F( factor_combinations_tests, case4 )
	{
		const auto input = 36;

		const auto actual = factor_combinations::get_factors( input );

		const auto expected = std::vector<std::vector<int>>
		{
			{2, 2, 3, 3},
			{2, 2, 9},
			{2, 3, 6},
			{2, 18},
			{3, 3, 4},
			{3, 12},
			{4, 9},
			{6, 6}
		};

		EXPECT_EQ( actual, expected );
	}

	TEST_F( factor_combinations_tests, case5 )
	{
		const auto input = 180;

		const auto actual = factor_combinations::get_factors( input );

		const auto expected = std::vector<std::vector<int>>
		{
			{2, 2, 3, 3, 5}, {2, 2, 3, 15}, {2, 2, 5, 9}, {2, 2, 45},
			{2, 3, 3, 10}, {2, 3, 5, 6}, {2, 3, 30}, {2, 5, 18}, {2, 6, 15},
			{2, 9, 10}, {2, 90}, {3, 3, 4, 5}, {3, 3, 20}, {3, 4, 15}, {3, 5, 12},
			{3, 6, 10}, {3, 60}, {4, 5, 9}, {4, 45}, {5, 6, 6}, {5, 36}, {6, 30},
			{9, 20}, {10, 18}, {12, 15}
		};

		EXPECT_EQ( actual, expected );
	}

	class word_search_tests :
		public testing::Test
	{
	protected:
		void SetUp() override
		{
		}

		void TearDown() override
		{
		}
	};

	TEST_F( word_search_tests, case1 )
	{
		auto input1 = std::vector<std::vector<char>>
		{
			{ 'A','B','C','E' },
			{ 'S','F','C','S' },
			{ 'A','D','E','E' }
		};

		const auto actual = word_search::exist( input1, "ABCCED" );

		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( word_search_tests, case2 )
	{
		auto input1 = std::vector<std::vector<char>>
		{
			{ 'A','B','C','E' },
			{ 'S','F','C','S' },
			{ 'A','D','E','E' }
		};

		const auto actual = word_search::exist( input1, "SEE" );

		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( word_search_tests, case3 )
	{
		auto input1 = std::vector<std::vector<char>>
		{
			{ 'A','B','C','E' },
			{ 'S','F','C','S' },
			{ 'A','D','E','E' }
		};

		const auto actual = word_search::exist( input1, "ABCB" );

		const auto expected = false;

		EXPECT_EQ( actual, expected );
	}

	class course_schedule_tests :
		public testing::Test
	{
	protected:
		void SetUp() override
		{
		}

		void TearDown() override
		{
		}
	};

	TEST_F( course_schedule_tests, case1 )
	{
		const auto prereqs = std::vector<std::vector<int>>
		{
			{0, 1}
		};
		
		const auto actual = course_schedule::can_finish( 2, prereqs );

		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( course_schedule_tests, case2 )
	{
		const auto prereqs = std::vector<std::vector<int>>
		{
			{1, 0},
			{0, 1}
		};

		const auto actual = course_schedule::can_finish( 2, prereqs );

		const auto expected = false;

		EXPECT_EQ( actual, expected );
	}
}