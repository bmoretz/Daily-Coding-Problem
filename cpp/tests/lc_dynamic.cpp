#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/dynamic.h"

namespace leetcode::dynamic::tests
{
	class longest_common_subsequence_tests :
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

	TEST_F( longest_common_subsequence_tests, case1 )
	{
		const auto input = std::pair<std::string, std::string>{ "abcde", "ace" };

		const auto actual = longest_common_subsequence::lcs( input.first, input.second );

		const auto expected = 3;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( longest_common_subsequence_tests, case2 )
	{
		const auto input = std::pair<std::string, std::string>{ "abc", "abc" };

		const auto actual = longest_common_subsequence::lcs( input.first, input.second );

		const auto expected = 3;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( longest_common_subsequence_tests, case3 )
	{
		const auto input = std::pair<std::string, std::string>{ "abc", "def" };

		const auto actual = longest_common_subsequence::lcs( input.first, input.second );

		const auto expected = 0;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( longest_common_subsequence_tests, case4 )
	{
		const auto input = std::pair<std::string, std::string>{ "dddddeeeeefffff", "def" };

		const auto actual = longest_common_subsequence::lcs( input.first, input.second );

		const auto expected = 3;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( longest_common_subsequence_tests, case5 )
	{
		const auto input = std::pair<std::string, std::string>{ "actgattag", "gtgtgatcg" };

		const auto actual = longest_common_subsequence::lcs( input.first, input.second );

		const auto expected = 5;

		EXPECT_EQ( actual, expected );
	}

	class word_break_ii_tests :
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

	TEST_F( word_break_ii_tests, case1 )
	{
		const auto input = std::pair<std::string, std::vector<std::string>>
		{
			"leetcode",
			{ "leet", "code" }
		};

		const auto actual = word_break_ii::word_break( input.first, input.second );
		const auto expected = true;
		
		EXPECT_EQ( actual, expected );
	}

	TEST_F( word_break_ii_tests, case2 )
	{
		const auto input = std::pair<std::string, std::vector<std::string>>
		{
			"catsandog",
			{ "cats","dog","sand","and","cat" }
		};

		const auto actual = word_break_ii::word_break( input.first, input.second );
		const auto expected = false;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( word_break_ii_tests, case3 )
	{
		const auto input = std::pair<std::string, std::vector<std::string>>
		{
			"applepenapple",
			{ "apple", "pen" }
		};

		const auto actual = word_break_ii::word_break( input.first, input.second );
		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( word_break_ii_tests, case4 )
	{
		const auto input = std::pair<std::string, std::vector<std::string>>
		{
			"catsandog",
			{ "cats", "dog", "sand", "an", "cat" }
		};

		const auto actual = word_break_ii::word_break( input.first, input.second );
		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( word_break_ii_tests, case5 )
	{
		const auto input = std::pair<std::string, std::vector<std::string>>
		{
			"abcd",
			{ "abcd", "a","abc","b","cd" }
		};

		const auto actual = word_break_ii::word_break( input.first, input.second );
		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}
}