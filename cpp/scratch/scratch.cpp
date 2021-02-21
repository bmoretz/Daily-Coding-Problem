#include <bits/stdc++.h>

/*

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of non-empty strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

*/

class group_shifted_sequence
{
	
public:

	static std::vector<std::vector<std::string>> groupStrings( const std::vector<std::string>& strings )
	{
		std::map<std::vector<int>, std::vector<std::string>> group_map;

		for( const auto& str : strings )
		{
			auto key = std::vector<int>();

			for( auto index = 1; index < str.length(); ++index )
			{
				const auto cur = str[ index ];
				const auto prev = str[ index - 1 ];

				const auto val = ( str[ index ] - str[ index - 1 ] + 26 ) % 26;
				
				key.push_back( val );
			}

			group_map[ key ].push_back( str );
		}

		auto results = std::vector<std::vector<std::string>>();

		for( auto &[k, v] : group_map )
		{
			results.push_back( v );
		}
		
		return results;
	}
};

auto main() -> int
{
	//const auto input = std::vector<std::string>{ "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
	const auto input = std::vector<std::string>{ "aa","bb","b" };
	
	auto result = group_shifted_sequence::groupStrings( input );
	
	return 0;
}