#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::dynamic
{
	/* 1143. Longest Common Subsequence.

	Given two strings text1 and text2, return the length of their longest common subsequence.

	A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without
	changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common
	subsequence of two strings is a subsequence that is common to both strings.

	If there is no common subsequence, return 0.

	Example 1:

	Input: text1 = "abcde", text2 = "ace"
	Output: 3
	Explanation: The longest common subsequence is "ace" and its length is 3.
	Example 2:

	Input: text1 = "abc", text2 = "abc"
	Output: 3
	Explanation: The longest common subsequence is "abc" and its length is 3.
	Example 3:

	Input: text1 = "abc", text2 = "def"
	Output: 0
	Explanation: There is no such common subsequence, so the result is 0.


	Constraints:

	1 <= text1.length <= 1000
	1 <= text2.length <= 1000
	The input strings consist of lowercase English characters only.
	*/

	struct longest_common_subsequence
	{
		static std::vector<std::vector<int>> mem;

		static int lcs( const std::string& text1, const std::string& text2 )
		{
			const auto n = text1.size(), m = text2.size() + 1;

			mem = std::vector( n + 1, std::vector<int>( m + 1, -1 ) );

			return lcs( text1, text2, 0, 0 );
		}

		static int lcs( const std::string& text1, const std::string& text2,
			const std::size_t pos1, const std::size_t pos2 )
		{
			if( pos1 == text1.size() || pos2 == text2.size() ) return 0;

			if( mem[ pos1 ][ pos2 ] != -1 )
			{
				return mem[ pos1 ][ pos2 ];
			}

			const auto option1 = lcs( text1, text2, pos1 + 1, pos2 );

			const auto first_occ = text2.find_first_of( text1.at( pos1 ), pos2 );
			auto option2 = 0;

			if( first_occ != std::string::npos )
			{
				option2 = 1 + lcs( text1, text2, pos1 + 1, first_occ + 1 );
			}

			mem[ pos1 ][ pos2 ] = std::max( option1, option2 );

			return mem[ pos1 ][ pos2 ];
		}
	};

	std::vector<std::vector<int>> longest_common_subsequence::mem;

	/* 139. Word Break.

	Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can
	be segmented into a space-separated sequence of one or more dictionary words.

	Note:

	The same word in the dictionary may be reused multiple times in the segmentation.
	You may assume the dictionary does not contain duplicate words.

	Example 1:
	Input: s = "leetcode", wordDict = ["leet", "code"]
	Output: true
	Explanation: Return true because "leetcode" can be segmented as "leet code".

	Example 2:
	Input: s = "applepenapple", wordDict = ["apple", "pen"]
	Output: true
	Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
				 Note that you are allowed to reuse a dictionary word.

	Example 3:
	Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
	Output: false
	*/

	class word_break_ii
	{
	public:

		static bool word_break( const std::string& str, const std::vector<std::string>& word_dict )
		{
			if( word_dict.empty() || str.empty() ) return false;

			const auto length = str.length();

			std::vector<bool> dp( length + 1, false );
			dp[ 0 ] = true;

			for( int index = 1; index <= str.length(); ++index )
			{
				for( auto& word : word_dict )
				{
					const int start_index = index - word.length();

					if( start_index < 0 || dp[ start_index ] == false ) continue;;

					if( word == str.substr( start_index, word.size() ) )
					{
						dp[ index ] = true;
						break;
					}
				}
			}

			return dp[ length ];
		}
	};

	/* 343. Integer Break.

	Given a positive integer n, break it into the sum of at least two positive integers
	and maximize the product of those integers. Return the maximum product you can get.

	Example 1:

	Input: 2
	Output: 1
	Explanation: 2 = 1 + 1, 1 × 1 = 1.
	Example 2:

	Input: 10
	Output: 36
	Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
	*/

	class integer_break
	{
	public:

		static int break_int( const int n )
		{
			if( n <= 2 ) return 1;

			std::vector<int> memo( n + 1, 0 );

			memo[ 1 ] = 0;
			memo[ 2 ] = 1;

			for( auto i = 3; i <= n; ++i )
			{
				for( auto j = 1; j < i; ++j )
				{
					const auto s1 = j * ( i - j );
					const auto s2 = j * memo[ static_cast< int >( i - j ) ];
					const auto sln = std::max( s1, s2 );

					memo[ i ] = std::max( memo[ i ], sln );
				}
			}

			return memo[ n ];
		}
	};

	/* 1317. Convert Integer to the Sum of Two No-Zero Integers.

	Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.

	Return a list of two integers [A, B] where:

	A and B are No-Zero integers.
	A + B = n

	It's guaranteed that there is at least one valid solution. If there are many valid solutions you can return any of them.

	Example 1:

	Input: n = 2
	Output: [1,1]
	Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
	Example 2:

	Input: n = 11
	Output: [2,9]
	Example 3:

	Input: n = 10000
	Output: [1,9999]
	Example 4:

	Input: n = 69
	Output: [1,68]
	Example 5:

	Input: n = 1010
	Output: [11,999]

	Constraints:

	2 <= n <= 10^4
	*/

	class largest_divisible_subset
	{

	public:

		static std::vector<int> largestDivisibleSubset( std::vector<int>& numbers )
		{
			if( numbers.empty() ) return { };

			std::sort( numbers.begin(), numbers.end() );

			auto dp = std::vector<int>( numbers.size(), 1 );
			auto prev = std::vector<int>( numbers.size(), -1 );

			auto max_index = 0;

			for( auto index = 1; index < numbers.size(); ++index )
			{
				for( auto sub = 0; sub < index; ++sub )
				{
					if( numbers.at( index ) % numbers.at( sub ) == 0
						&& dp[ index ] < dp[ sub ] + 1 )
					{
						dp[ index ] = dp[ sub ] + 1;
						prev[ index ] = sub;
					}
				}

				if( dp[ index ] > dp[ max_index ] )
				{
					max_index = index;
				}
			}

			auto result = std::vector<int>();

			auto index = max_index;
			while( index >= 0 )
			{
				result.push_back( numbers.at( index ) );
				index = prev[ index ];
			}

			return result;
		}
	};

	/* 5. Longest Palindromic Substring.

	Given a string s, return the longest palindromic substring in s.

	Example 1:

	Input: s = "babad"
	Output: "bab"
	Note: "aba" is also a valid answer.
	Example 2:

	Input: s = "cbbd"
	Output: "bb"
	Example 3:

	Input: s = "a"
	Output: "a"
	Example 4:

	Input: s = "ac"
	Output: "a"


	Constraints:

	1 <= s.length <= 1000
	s consist of only digits and English letters (lower-case and/or upper-case),
	*/

	class longest_palindromic_string
	{

	public:

		static std::string longestPalindrome( const std::string& input )
		{
			const auto n = input.length();

			if( n < 2 ) return input;

			auto dp = std::vector<std::vector<bool>>( n,
				std::vector<bool>( n, false ) );

			auto idx = -1, max_len = 0;

			for( auto index = 0; index < n; ++index )
			{
				dp[ index ][ index ] = true;
				idx = 1;
				max_len = 1;
			}

			for( auto index = 0; index < n - 1; ++index )
			{
				if( input[ index ] == input[ index + 1 ] )
				{
					dp[ index ][ index + 1 ] = true;
					idx = index;
					max_len = 2;
				}
			}

			for( auto len = 3; len <= n; ++len )
			{
				for( auto start = 0; start < n - len + 1; ++start )
				{
					const auto stop = start + len - 1;

					if( input[ start ] == input[ stop ] && dp[ start + 1 ][ stop - 1 ] )
					{
						dp[ start ][ stop ] = true;
						idx = start;
						max_len = stop - start + 1;
					}
				}
			}

			return input.substr( idx, max_len );
		}
	};

	/* 322. Coin Change.

	You are given coins of different denominations and a total amount of money amount. Write a function to
	compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up
	by any combination of the coins, return -1.

	You may assume that you have an infinite number of each kind of coin.

	Example 1:

	Input: coins = [1,2,5], amount = 11
	Output: 3
	Explanation: 11 = 5 + 5 + 1

	Example 2:

	Input: coins = [2], amount = 3
	Output: -1
	Example 3:

	Input: coins = [1], amount = 0
	Output: 0

	Example 4:

	Input: coins = [1], amount = 1
	Output: 1

	Example 5:

	Input: coins = [1], amount = 2
	Output: 2

	Constraints:

	1 <= coins.length <= 12
	1 <= coins[i] <= 231 - 1
	0 <= amount <= 104
	*/

	class coin_changer
	{

	public:

		static int coin_change( const std::vector<int>& coins, const int amount )
		{
			auto memo = std::vector<int>( amount + 1, amount + 1 );

			memo[ 0 ] = 0;

			for( auto amt = 1; amt <= amount; ++amt )
			{
				for( auto coin : coins )
				{
					if( coin <= amt )
					{
						memo[ amt ] = std::min(
							memo[ amt ],
							memo[ amt - coin ] + 1 
						);
					}
				}
			}

			return memo[ amount ] > amount ? -1 : memo[ amount ];
		}
	};

	/* 139. Word Break.

	Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented
	into a space-separated sequence of one or more dictionary words.

	Note:

	The same word in the dictionary may be reused multiple times in the segmentation.
	You may assume the dictionary does not contain duplicate words.
	Example 1:

	Input: s = "leetcode", wordDict = ["leet", "code"]
	Output: true
	Explanation: Return true because "leetcode" can be segmented as "leet code".
	Example 2:

	Input: s = "applepenapple", wordDict = ["apple", "pen"]
	Output: true
	Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
				 Note that you are allowed to reuse a dictionary word.
	Example 3:

	Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
	Output: false
	*/

	class word_breaks
	{
		static auto to_set( const std::vector<std::string>& words )
		{
			auto set = std::set<std::string>();

			for( auto& word : words )
			{
				set.insert( word );
			}

			return set;
		}

	public:

		static bool word_break( const std::string& input,
			const std::vector<std::string>& word_dict )
		{
			auto word_set = to_set( word_dict );

			auto dp = std::vector<bool>( input.length() + 1 );
			dp[ 0 ] = true;

			for( auto stop = 1; stop <= input.length(); ++stop )
			{
				for( auto start = 0; start < stop; ++start )
				{
					const auto sub = input.substr( start, stop - start );

					if( dp[ start ] && word_set.find( sub ) != word_set.end() )
					{
						dp[ stop ] = true;
					}
				}
			}

			return dp[ input.length() ];
		}
	};

	/*279. Perfect Squares.

	Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

	Example 1:

	Input: n = 12
	Output: 3
	Explanation: 12 = 4 + 4 + 4.
	Example 2:

	Input: n = 13
	Output: 2
	Explanation: 13 = 4 + 9.
	*/

	class perfect_squares
	{
	public:

		static int num_squares( const int num )
		{
			auto squares = std::vector<int>();

			for( auto index = 1; index * index <= num; ++index )
				squares.push_back( index * index );

			auto dp = std::vector<int>( num + 1 );
			dp[ 0 ] = 0;

			for( auto index = 1; index <= num; ++index )
			{
				auto min = INT_MAX;

				for( auto square : squares )
				{
					if( square <= index )
					{
						min = std::min( dp[ index - square ] + 1, min );
					}

					dp[ index ] = min;
				}
			}

			return dp[ num ];
		}
	};

	/*309. Best Time to Buy and Sell Stock with Cooldown.

	Say you have an array for which the ith element is the price of a given stock on day i.

	Design an algorithm to find the maximum profit. You may complete as many transactions as you like
	(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

	You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
	After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

	Example:

	Input: [1,2,3,0,2]
	Output: 3
	Explanation: transactions = [buy, sell, cooldown, buy, sell]
	*/

	class buy_and_sell_stock_ii
	{
	public:

		static int max_profit( const std::vector<int>& prices )
		{
			if( prices.size() < 2 )
				return 0;

			const int N = prices.size();
			auto result = 0;

			std::vector<int> buy( N, 0 );
			std::vector<int> sell( N, 0 );

			buy[ 0 ] = -prices[ 0 ];

			for( auto index = 1; index < N; ++index )
			{
				sell[ index ] = std::max( buy[ index - 1 ] + prices[ index ], sell[ index - 1 ] - prices[ index - 1 ] + prices[ index ] );

				//record the max sell[i]
				if( result < sell[ index ] )
					result = sell[ index ];

				if( 1 == index )
				{
					buy[ index ] = buy[ 0 ] + prices[ 0 ] - prices[ 1 ];
				}
				else
				{
					buy[ index ] = std::max( sell[ index - 2 ] - prices[ index ], buy[ index - 1 ] + prices[ index - 1 ] - prices[ index ] );
				}
			}

			return result;
		}
	};
}