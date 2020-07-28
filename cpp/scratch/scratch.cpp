#include <bits/stdc++.h>

/* 1513. Number of Substrings With Only 1s.
 
Given a binary string s (a string consisting only of '0' and '1's).
Return the number of substrings with all characters 1's.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.

"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.

Example 2:

Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.

Example 3:

Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.
Example 4:

Input: s = "000"
Output: 0
*/

struct number_of_1s_substrings
{
	static std::unordered_map<std::size_t, std::size_t> get_ones_counts( const std::string& input )
	{
		std::unordered_map<std::size_t, std::size_t> groups;

		auto current_len = std::size_t();

		for( auto chr : input )
		{
			if( chr == '1' )
			{
				++current_len;
			}
			else if( current_len > 0 )
			{
				groups[ current_len ]++;
				current_len = std::size_t();
			}
		}

		if( current_len > 0 )
			groups[ current_len ]++;

		return groups;
	}

	/// <summary>
	/// number of subgroups
	/// </summary>
	/// <param name="str">input string</param>
	/// <returns>number of ways to choose subgroups of 1's</returns>
	static int number_of_subgroups( const std::string& str ) const
	{
		auto group_counts = get_ones_counts( str );
		auto perms = 0;
		const unsigned long long mod_op = std::pow(10, 9 ) + 7;

		for( const auto& group : group_counts )
		{
			const auto intermediate = group.second * ( group.first * ( group.first + 1 ) / 2 );
			perms = ( static_cast<std::size_t>( perms ) + intermediate ) % mod_op;
		}

		return perms;
	}
};

auto main() -> int
{
	auto input1 = "0110111";
	auto input2 = "101";
	auto input3 = "111111";
	auto input4 = "000";
	auto input5 = "0101111111010111101111111111111111111111011111111111111111111111111111111111";
	
	number_of_1s_substrings sln;
	
	const auto result = sln.number_of_subgroups( input1 );
	
	std::cout << "Result: " << result << std::endl;
	
	return 0;
}
