#include <bits/stdc++.h>
#include <array>

/*1002. Find Common Characters.

Given an array A of strings made only from lowercase letters, return a list of all characters that
show up in all strings within the list (including duplicates).  For example, if a character occurs 3
times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

class common_characters
{
	static std::map<char, std::size_t> to_char_map( const std::string& str )
	{
		std::map<char, std::size_t> map;

		for( auto chr : str )
		{
			map[ chr ]++;
		}

		return map;
	}
	
public:

	static std::vector<std::string> find_common( const std::vector<std::string>& strings )
	{
		auto counts = std::map<char, std::size_t>();
		std::vector<bool> required( 26, true );

		for( auto index = 0; index < 26; ++index )
		{
			counts[ index + 'a' ] = SIZE_MAX;
		}

		for( const auto& str : strings )
		{
			const auto current = to_char_map( str );

			for( auto& [k, v] : current )
			{
				counts[ k ] = std::min( counts[ k ], v );
			}

			for( auto index = 0; index < 26; ++index )
			{
				if( current.find( 'a' + index ) == current.end() )
				{
					required[ index ] = false;
				}
			}
		}

		std::vector<std::string> result;

		for( auto& [k, v] : counts )
		{
			const auto current = k - 'a';
			
			if( required[ current ] )
			{
				for( auto rep = 0ULL; rep < v; ++rep )
				{
					result.emplace_back( 1, k );
				}
			}
		}

		return result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::string>
	{
		"bella",
		"label",
		"roller"
	};

	const auto input2 = std::vector<std::string>
	{
		"cool",
		"lock",
		"cook"
	};

	const auto input3 = std::vector<std::string>
	{
		"acabcddd",
		"bcbdbcbd",
		"baddbadb",
		"cbdddcac",
		"aacbcccd",
		"ccccddda",
		"cababaab",
		"addcaccd"
	};
	
	const auto result = common_characters::find_common( input1 );
	
	return 0;
}