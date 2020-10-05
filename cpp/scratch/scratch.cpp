#include <bits/stdc++.h>

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

auto main() -> int
{
	const auto input1 = std::pair<std::string, std::string>( "ADOBECODEBANC", "ABC" );
    const auto actual = minimum_window_substring::min_window( input1.first, input1.second );
	
    const auto expected = "BANC";
	
	return 0;
}
