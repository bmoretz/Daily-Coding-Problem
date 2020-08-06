#include <bits/stdc++.h>

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
Accepted
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
			results[ index++ ] =  kv.second;
		}

		for( auto& digit : digits )
		{
			results[ index++ ] = digit;
		}
		
		return results;
	}
};

auto main() -> int
{
	auto input1 = std::vector<std::string>{
		"dig1 8 1 5 1",
		"let1 art can",
		"dig2 3 6",
		"let2 own kit dig",
		"let3 art zero"
	};

	auto input2 = std::vector<std::string>{
		"dig1 8 1 5 1",
		"let1 art can",
		"dig2 3 6",
		"let2 own kit dig",
		"let3 art zero"
	};

	auto input3 = std::vector<std::string>{
		"dig1 8 1 5 1",
		"let1 art can",
		"dig2 3 6",
		"let2 own kit dig",
		"let3 art zero",
		"digit3 4 9 1 3",
		"art1 life is a garden",
		"dig1 it"
	};
	
	const auto result = log_reorder::reorder_log_files( input1 );

	return 0;
}