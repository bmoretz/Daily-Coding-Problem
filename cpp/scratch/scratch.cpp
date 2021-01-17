#include <bits/stdc++.h>

/*14. Longest Common Prefix.

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/

class longest_common_prefix
{
public:

	static std::string max_common_prefix( const std::vector<std::string>& strings )
    {
		if( strings.empty() ) return "";
		
        auto position = 0;
		auto result = std::string();
		auto valid = true;
		
		while( valid )
		{
			if( strings[ 0 ].empty() ) break;
			if( strings[ 0 ].length() <= position )
				break;

			for( auto index = 1ULL; index < strings.size(); ++index )
			{
				valid &= position <= strings[ index ].size() && 
					strings[ index ][ position ] == strings[ 0 ][ position ];

				if( !valid ) break;
			}

			if( valid )
				result += strings[ 0 ][ position ];

			position++;
		}
		
        return result;
    }
};

auto main() -> int
{
    auto input = std::vector<std::string>{ "a" };
	
    const auto actual = longest_common_prefix::max_common_prefix( input );
	
	const auto expected = 4;
	
	return 0;
}