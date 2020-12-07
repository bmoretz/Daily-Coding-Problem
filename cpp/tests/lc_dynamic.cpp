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

	class break_integer_tests :
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

	TEST_F( break_integer_tests, case1 )
	{
		const auto input = 10;

		const auto actual = integer_break::break_int( 5 );
		const auto expected = 6;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( break_integer_tests, case2 )
	{
		const auto input = 10;

		const auto actual = integer_break::break_int( 10 );
		const auto expected = 36;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( break_integer_tests, case3 )
	{
		const auto input = 10;

		const auto actual = integer_break::break_int( 15 );
		const auto expected = 243;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( break_integer_tests, case4 )
	{
		const auto input = 10;

		const auto actual = integer_break::break_int( 20 );
		const auto expected = 1458;

		EXPECT_EQ( actual, expected );
	}

	class largest_divisible_subset_tests :
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

	TEST_F( largest_divisible_subset_tests, case1 )
	{
		auto input = std::vector<int>{ 1, 2, 3 };

		const auto actual = largest_divisible_subset::largestDivisibleSubset( input );
		const auto expected = std::vector<int>{ 2, 1 };
		
		EXPECT_EQ( actual, expected );
	}

	TEST_F( largest_divisible_subset_tests, case2 )
	{
		auto input = std::vector<int>{ 1, 2, 4, 8 };

		const auto actual = largest_divisible_subset::largestDivisibleSubset( input );
		const auto expected = std::vector<int>{ 8, 4, 2, 1 };

		EXPECT_EQ( actual, expected );
	}

	TEST_F( largest_divisible_subset_tests, case3 )
	{
		auto input = std::vector<int>{ 1, 2, 4, 8, 12, 15, 7 };

		const auto actual = largest_divisible_subset::largestDivisibleSubset( input );
		const auto expected = std::vector<int>{ 8, 4, 2, 1 };

		EXPECT_EQ( actual, expected );
	}

	TEST_F( largest_divisible_subset_tests, case4 )
	{
		auto input = std::vector<int>{ 1, 2, 4, 8, 12, 15, 18, 20, 3, 7 };

		const auto actual = largest_divisible_subset::largestDivisibleSubset( input );
		const auto expected = std::vector<int>{ 8, 4, 2, 1 };

		EXPECT_EQ( actual, expected );
	}

	class longest_palindromic_string_tests :
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

	TEST_F( longest_palindromic_string_tests, case1 )
	{
		const auto input1 = "babad";

		const auto actual = longest_palindromic_string::longestPalindrome( input1 );

		const auto expected = "aba";

		EXPECT_EQ( actual, expected );
	}

	TEST_F( longest_palindromic_string_tests, case2 )
	{
		const auto input1 = "babad";

		const auto actual = longest_palindromic_string::longestPalindrome( input1 );

		const auto expected = "aba";

		EXPECT_EQ( actual, expected );
	}

	class coin_changer_tests :
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

	TEST_F( coin_changer_tests, case1 )
	{
		const auto input1 = std::vector<int>{ 1, 2, 5};

		const auto actual = coin_changer::coin_change( input1, 11 );

		const auto expected = 3;

		EXPECT_EQ( actual, expected );
	}

	class word_break_tests :
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

	TEST_F( word_break_tests, case1 )
	{
		const auto input = std::pair<std::string, std::vector<std::string>>(
			"aaaaaaa",
			{ "aaa", "aaaa" }
		);

		const auto actual = word_breaks::word_break( input.first, input.second );

		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( word_break_tests, case2 )
	{
		const auto input = std::pair<std::string, std::vector<std::string>>(
			"leetcode",
			{ "leet", "code" }
		);

		const auto actual = word_breaks::word_break( input.first, input.second );

		const auto expected = true;

		EXPECT_EQ( actual, expected );
	}

	class perfect_squares_tests :
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

	TEST_F( perfect_squares_tests, case1 )
	{
		const int actual = perfect_squares::num_squares( 12 );
		const int expected = 3;
		
		EXPECT_EQ( actual, expected );
	}

	TEST_F( perfect_squares_tests, case2 )
	{
		const int actual = perfect_squares::num_squares( 5849 );
		const int expected = 2;

		EXPECT_EQ( actual, expected );
	}

	class buy_and_sell_stock_ii_tests :
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

	TEST_F( buy_and_sell_stock_ii_tests, case1 )
	{
		const auto prices = std::vector<int>{ 1, 2, 3, 0, 2 };

		const auto actual = buy_and_sell_stock_ii::max_profit( prices );
		const auto expected = 3;
	}
}