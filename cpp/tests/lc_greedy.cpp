#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/greedy.h"

namespace leetcode::greedy::tests
{
	class partition_labels_tests :
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

	TEST_F( partition_labels_tests, case1 )
	{
		const auto input = "ab";
		
		const auto actual = partition_labels::partition( input );
		const auto expected = std::vector<int>{ 1, 1 };

		EXPECT_EQ( actual, expected );
	}

	TEST_F( partition_labels_tests, case2 )
	{
		const auto input = "aa";

		const auto actual = partition_labels::partition( input );
		const auto expected = std::vector<int>{ 2 };

		EXPECT_EQ( actual, expected );
	}

	TEST_F( partition_labels_tests, case3 )
	{
		const auto input = "aca";

		const auto actual = partition_labels::partition( input );
		const auto expected = std::vector<int>{ 3 };

		EXPECT_EQ( actual, expected );
	}

	TEST_F( partition_labels_tests, case4 )
	{
		const auto input = "ababcbacadefegdehijhklij";

		const auto actual = partition_labels::partition( input );
		const auto expected = std::vector<int>{ 9, 7, 8 };

		EXPECT_EQ( actual, expected );
	}

	TEST_F( partition_labels_tests, case5 )
	{
		const auto input = "ababcbacadefegdehijhklijffkeflfeklmzlk";

		const auto actual = partition_labels::partition( input );
		const auto expected = std::vector<int>{ 9, 29 };

		EXPECT_EQ( actual, expected );
	}
}