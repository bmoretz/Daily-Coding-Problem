#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::str
{
	struct len_longest_substring
	{
		/// <summary>
		/// length of longest substring, sliding window
		/// </summary>
		/// <param name="str">input string</param>
		/// <complexity>
		///		<run-time>O(n)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// <returns>length of the longest substring.</returns>
		static int length_of_longest_substring2( const std::string& str )
		{
			const auto n = str.length();

			std::set<char> seen;

			auto longest = 0UL, start = 0UL, stop = 0UL;

			while( start < n && stop < n )
			{
				if( seen.find( str.at( stop ) ) == std::end( seen ) )
				{
					seen.insert( str.at( stop++ ) );
					longest = std::max( longest, stop - start );
				}
				else
				{
					seen.erase( str.at( start++ ) );
				}
			}

			return longest;
		}

		/// <summary>
		/// length of longest substring, brute force approach
		/// </summary>
		/// <complexity>
		///		<run-time>O(n^2)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// <param name="str">input string</param>
		/// <returns>length of the longest substring.</returns>
		static int length_of_longest_substring1( const std::string& str )
		{
			if( str.length() == 1 ) return 1;

			auto longest = 0ULL;

			for( auto start = 0UL; start < str.length() - 1; ++start )
			{
				for( auto stop = start + 1; stop < str.length(); ++stop )
				{
					const auto sub = str.substr( start, stop );
					const auto unique = std::set<char>( std::begin( sub ), std::end( sub ) );

					if( sub.length() == unique.size() )
					{
						longest = std::max( longest, sub.length() );
					}
				}
			}

			return longest;
		}
	};

	/* Length of Last Word.

	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of
	last word (last word means the last appearing word if we loop from left to right) in the string.

	If the last word does not exist, return 0.

	Note: A word is defined as a maximal substring consisting of non-space characters only.

	Example:

	Input: "Hello World"
	Output: 5

	*/

	struct length_of_last_word
	{
		/// <summary>
		/// trims the trailing spaces from a given input and returns the number
		/// of characters trimmed.
		/// </summary>
		/// <param name="str"></param>
		/// <returns></returns>
		static std::size_t rtrim( std::string& str )
		{
			auto trimmed = std::size_t();

			for( auto index = str.length();
				index > 0 && str.at( index - 1 ) == ' '; --index, ++trimmed )
			{
				str.erase( index - 1 );
			}

			return trimmed;
		}

		/// <summary>
		/// returns the length of the last word
		/// </summary>
		/// <complexity>
		///		<run-time>O(n)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="str">the input string</param>
		/// <returns>length of last word</returns>
		static std::size_t len_last_word( std::string& str )
		{
			if( str.empty() ) return 0;

			const auto len = str.length();
			const auto trimmed = rtrim( str );
			const auto last_space = str.rfind( ' ' );

			return len - trimmed - last_space - 1;
		}
	};

	/* 49. Group Anagrams.

	Given an array of strings, group anagrams together.

	Example:

	Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
	Output:
	[
	  ["ate","eat","tea"],
	  ["nat","tan"],
	  ["bat"]
	]
	Note:

	All inputs will be in lowercase.
	The order of your output does not matter.
	*/

	struct group_anagrams
	{
		static std::vector<std::vector<std::string>> to_vector( const std::unordered_map<std::string, std::vector<std::string>>& map )
		{
			std::vector<std::vector<std::string>> results;

			std::for_each( map.begin(), map.end(),
				[&results]( const std::pair<std::string, std::vector<std::string>>& entry )
				{
					results.push_back( entry.second );
				} );

			return results;
		}

		/// <summary>
		/// group anagrams 1
		///
		/// straight forward approach: take a copy of each of the strings and sort it for use a key
		/// in a hash-map. Then to get the resulting groups simply flatten the values of the hash-map
		/// to a nested vector.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N + M), where n is the number of strings and m is the number of groups.</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// <param name="input">vector of strings</param>
		/// <returns>grouped anagrams</returns>
		static std::vector<std::vector<std::string>> group_anagrams1( const std::vector<std::string>& input )
		{
			std::unordered_map<std::string, std::vector<std::string>> groups;

			for( const auto& str : input )
			{
				auto key = str;

				std::sort( key.begin(), key.end() );

				groups[ key ].push_back( str );
			}

			return to_vector( groups );
		}
	};

	/* 1328. Break a Palindrome.

	Given a palindromic string palindrome, replace exactly one character by any lowercase English letter so that the string becomes the
	lexicographically smallest possible string that isn't a palindrome.

	After doing so, return the final string.  If there is no way to do so, return the empty string.

	Example 1:

	Input: palindrome = "abccba"
	Output: "aaccba"

	Example 2:

	Input: palindrome = "a"
	Output: ""

	Constraints:
		1 <= palindrome.length <= 1000
		palindrome consists of only lowercase English letters.
	*/

	struct break_palindrome
	{
		/// <summary>
		/// break palindrome
		///
		/// straight forward approach to replace the first non-a with an a, if we can't
		/// then just move up to the next ordering level by replacing the last character with a b.
		/// </summary>
		/// <param name="input">the input string</param>
		/// <returns>broken palindrome</returns>
		static std::string break_palindrome1( std::string input )
		{
			if( input.size() == 1 ) {
				return "";
			}

			auto start = std::size_t(), stop = input.size() - 1;

			while( start < stop )
			{
				if( input[ start ] != 'a' )
				{
					input[ start ] = 'a';
					return input;
				}

				start++; stop--;
			}

			input[ input.size() - 1 ] = 'b';

			return input;
		}
	};

	/* 151. Reverse Words in a String.

	Given an input string, reverse the string word by word.
	*/

	struct word_reverser
	{
		static void trim( std::string& str )
		{
			while( !str.empty() && std::isspace( str.front() ) )
				str.erase( 0, 1 );

			while( !str.empty() && std::isspace( str.back() ) )
				str.erase( str.size() - 1, 1 );
		}

		static std::string reverse_words( std::string& input )
		{
			if( input.empty() ) return input;

			trim( input );

			auto pos = std::size_t();
			std::string buff, result;

			while( pos < input.size() )
			{
				if( std::isspace( input.at( pos ) ) )
				{
					if( !result.empty() )
						result.insert( 0, " " );

					result.insert( 0, buff );
					buff.clear();
					++pos;

					while( std::isspace( input.at( pos ) ) )
						++pos;
				}

				buff.push_back( input.at( pos++ ) );
			}

			if( !buff.empty() )
			{
				if( !result.empty() )
					result.insert( 0, " " );

				result.insert( 0, buff );
			}

			return result;
		}
	};

	/* 937. Reorder Data in Log Files.

	You have an array of logs.  Each log is a space delimited string of words.

	For each log, the first word in each log is an alphanumeric identifier.  Then, either:

	Each word after the identifier will consist only of lowercase letters, or;
	Each word after the identifier will consist only of digits.
	We will call these two varieties of logs letter-logs and digit-logs.
	It is guaranteed that each log has at least one word after its identifier.

	Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered
	lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs
	should be put in their original order.

	Return the final order of the logs.

	Example 1:

	Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
	Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

	Constraints:

	0 <= logs.length <= 100
	3 <= logs[i].length <= 100
	logs[i] is guaranteed to have an identifier, and a word after the identifier.
	*/

	struct log_reorder
	{
		enum class log_type
		{
			letter = 0,
			digit = 1
		};

		/// <summary>
		/// parse log data
		///
		/// takes in a log file and returns its type and its storage key
		/// </summary>
		/// <param name="log"></param>
		/// <returns></returns>
		static std::pair<log_type, std::string> parse_log_data( const std::string& log )
		{
			const auto split_position = log.find_first_of( ' ' );

			const auto log_id = log.substr( 0, split_position );
			const auto log_value = log.substr( split_position + 1, log.size() );

			const auto is_digit = std::isdigit( log_value.at( 0 ) );
			const auto type = static_cast< log_type >( is_digit == 0 ? 0 : 1 );

			return std::make_pair( type, log_value + ' ' + log_id );
		}

		/// <summary>
		/// separates the logs by type (digit, letter) and then stores them in the appropriate
		/// data structure for later reconstruction.
		/// </summary>
		/// <param name="logs">input data set</param>
		/// <returns>ordered log set</returns>
		static std::vector<std::string> reorder_log_files( std::vector<std::string>& logs )
		{
			std::map<std::string, std::string> letters;
			std::vector<std::string> digits;

			for( const auto& log : logs )
			{
				const auto parsed = parse_log_data( log );

				if( parsed.first == log_type::letter )
				{
					letters[ parsed.second ] = log;
				}
				else
				{
					digits.push_back( log );
				}
			}

			std::vector<std::string> results( letters.size() + digits.size() );
			auto index = std::size_t();

			for( const auto& kv : letters )
			{
				results[ index++ ] = kv.second;
			}

			for( auto& digit : digits )
			{
				results[ index++ ] = digit;
			}

			return results;
		}
	};

	/*758. Bold Words in String.

	Given a set of keywords words and a string S, make all appearances of all keywords
	in S bold. Any letters between <b> and </b> tags become bold.

	The returned string should use the least number of tags possible, and of course
	the tags should form a valid combination.

	For example, given that words = ["ab", "bc"] and S = "aabcd", we should return
	"a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

	Constraints:

	words has length in range [0, 50].
	words[i] has length in range [1, 10].
	S has length in range [0, 500].
	All characters in words[i] and S are lowercase letters.
	Note: This question is the same as 616: https://leetcode.com/problems/add-bold-tag-in-string/

	*/

	class bold_words
	{
		static std::vector<bool> extract_mask( const std::vector<std::string>& words, const std::string& string )
		{
			auto mask = std::vector<bool>( string.size(), false );

			for( const auto& str : words )
			{
				auto pos = 0ULL;

				while( ( pos = string.find( str, pos ) ) != std::string::npos )
				{
					for( auto index = 0ULL; index < str.size(); ++index )
					{
						mask[ pos + index ] = true;
					}

					++pos;
				}
			}

			return mask;
		}

		static std::string insert_tags( const std::string& string, std::vector<bool> mask )
		{
			std::string result;
			auto status = false;

			for( auto index = 0ULL; index < mask.size(); ++index )
			{
				if( status == 0 )
				{
					if( mask[ index ] )
					{
						result += "<b>";
						status = true;
					}
				}
				else if( status == 1 )
				{
					if( !mask[ index ] )
					{
						result += "</b>";
						status = false;
					}
				}

				result += string[ index ];
			}

			if( status )
			{
				result += "</b>";
			}

			return result;
		}

	public:

		static std::string bold( const std::vector<std::string>& words, const std::string& string )
		{
			const auto mask = extract_mask( words, string );

			return insert_tags( string, mask );
		}
	};

	/* 819. Most Common Word.

	Given a paragraph and a list of banned words, return the most frequent word that is not in
	the list of banned words.  It is guaranteed there is at least one word that isn't banned,
	and that the answer is unique.

	Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the
	paragraph are not case sensitive.  The answer is in lowercase.

	Example:

	Input:
	paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
	banned = ["hit"]
	Output: "ball"

	Explanation:

	"hit" occurs 3 times, but it is a banned word.
	"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
	Note that words in the paragraph are not case sensitive,
	that punctuation is ignored (even if adjacent to words, such as "ball,"),
	and that "hit" isn't the answer even though it occurs more because it is banned.

	Note:

	1 <= paragraph.length <= 1000.
	0 <= banned.length <= 100.
	1 <= banned[i].length <= 10.
	The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
	paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
	There are no hyphens or hyphenated words.
	Words only consist of letters, never apostrophes or other punctuation symbols.

	*/

	class most_common_word
	{
		static std::vector<std::string> get_tokens( const std::string& data )
		{
			auto cleaned = std::string{ };
			cleaned.resize( data.size() );

			std::transform( data.begin(), data.end(), cleaned.begin(),
				[]( const auto chr )
				{
					if( ::ispunct( chr ) ) return ' ';

					return static_cast< char >( ::tolower( chr ) );
				} );

			std::istringstream iss( cleaned );

			std::vector<std::string> tokens( ( std::istream_iterator<std::string>( iss ) ),
				std::istream_iterator<std::string>() );

			return tokens;
		}

	public:

		static std::string get_most_common( const std::string& paragraph,
			const std::vector<std::string>& banned )
		{
			std::set<std::string> exclude( banned.begin(), banned.end() );

			// get tokens
			auto tokens = get_tokens( paragraph );

			auto map = std::unordered_map<std::string, int>();

			std::pair<int, std::string> result = { -1, "" };

			for( auto& word : tokens )
			{
				// skip banned
				if( exclude.find( word ) != exclude.end() )
					continue;

				++map[ word ];

				if( map[ word ] > result.first )
				{
					result = { map[ word ], word };
				}
			}

			return result.second;
		}
	};

	/* 541. Reverse String II.

	Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the
	start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater
	than or equal to k characters, then reverse the first k characters and left the other as original.

	Example:
	Input: s = "abcdefg", k = 2
	Output: "bacdfeg"

	Restrictions:
		The string consists of lower English letters only.
		Length of the given string and k will in the range [1, 10000]
	*/

	class rev_string_ii
	{
	public:

		static std::string reverse_str( const std::string& input, const int k )
		{
			auto result = std::string();
			auto stack = std::stack<char>();

			auto is_rev = true;

			for( auto index = std::size_t(); index < input.size(); index += k )
			{
				const auto stop = std::min( index + k, input.size() );

				if( is_rev )
				{
					for( auto sub = index; sub < stop; ++sub )
					{
						stack.push( input.at( sub ) );
					}

					while( !stack.empty() )
					{
						result.push_back( stack.top() );
						stack.pop();
					}
				}
				else
				{
					for( auto sub = index; sub < stop; ++sub )
					{
						result.push_back( input.at( sub ) );
					}
				}

				is_rev = !is_rev;
			}

			while( !stack.empty() )
			{
				result.push_back( stack.top() );
				stack.pop();
			}

			return result;
		}
	};


	/* 76. Minimum Window Substring.

	Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

	Example:

	Input: S = "ADOBECODEBANC", T = "ABC"
	Output: "BANC"

	Note:
	If there is no such window in S that covers all characters in T, return the empty string "".
	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
	*/

	class minimum_window_substring
	{
		static std::unordered_map<char, int> to_freq( const std::string& str )
		{
			auto freq = std::unordered_map<char, int>();

			for( auto chr : str )
			{
				freq[ chr ]++;
			}

			return freq;
		}

	public:

		static std::string min_window( const std::string& input,
			const std::string& to_find )
		{
			auto counts = to_freq( to_find );

			auto left = 0, right = 0;
			auto remain = to_find.length();
			auto min_len = std::numeric_limits<int>::max();
			auto min_loc = -1;

			while( right < input.length() )
			{
				if( remain != 0 )
				{
					auto chr = input[ right ];

					if( counts.find( chr ) != counts.end() &&
						--counts[ chr ] >= 0 )
					{
						--remain;
					}

					right++;
				}

				while( left < right && remain == 0 )
				{
					if( right - left < min_len )
					{
						min_len = right - left;
						min_loc = left;
					}

					auto chr = input[ left ];

					if( counts.find( chr ) != counts.end() &&
						++counts[ chr ] > 0 )
					{
						++remain;
					}

					left++;
				}
			}

			return min_loc == -1 ?
				"" :
				input.substr( min_loc, min_len );
		}
	};

	/*344. Reverse String.

	Write a function that reverses a string. The input string is given as an array of characters char[].

	Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

	You may assume all the characters consist of printable ascii characters.

	Example 1:

	Input: ["h","e","l","l","o"]
	Output: ["o","l","l","e","h"]
	Example 2:

	Input: ["H","a","n","n","a","h"]
	Output: ["h","a","n","n","a","H"]

	*/

	class reverse_string
	{
	public:

		static void reverse( std::vector<char>& characters )
		{
			auto left = 0ULL, right = characters.size() - 1;

			while( left < right )
			{
				std::swap( characters[ left++ ], characters[ right-- ] );
			}
		}
	};
}