#include <bits/stdc++.h>

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

auto main() -> int
{
	auto input1 = std::vector<std::string>{ "eat","tea","tan","ate","nat","bat" };
	auto input2 = std::vector<std::string>{ "eat","tab", "tea","tan","ate","nat","bat" };
	auto input3 = std::vector<std::string>{ "eat","tea","tan","ate","nat","bat", "" };
	auto input4 = std::vector<std::string>{ "eat","tab", "tea","tan","ate","nat","bat", "bat", "101ab", "ab101" };
	auto input5 = std::vector<std::string>{ "eat","tab", "tea","tan","ate","nat","bat", "bat", "101ab", "ab101", "tab" };
	
	const auto result = group_anagrams::group_anagrams1( input3 );

	for( const auto& group : result )
	{
		for( const auto& value : group )
		{
			std::cout << value << ",";
		}

		std::cout << std::endl;
	}
	
	return 0;
}
