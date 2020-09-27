#include <bits/stdc++.h>
#include <array>

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

class Solution {
public:

    std::string reverseStr( const std::string& input, const int k ) const
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

auto main() -> int
{
	auto input1 = std::vector<std::string>{ };
	
	return 0;
}
