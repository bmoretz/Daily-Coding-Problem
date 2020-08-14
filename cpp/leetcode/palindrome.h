#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>

namespace leetcode::palindrome
{
    /* 5. Longest Palindromic Substring.

    Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

    Example 1:
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

    Example 2:
    Input: "cbbd"
    Output: "bb"
    */

    class longest_palindrome
    {
    public:

        static std::string extract( const std::string& str )
        {
            if( str.size() <= 1 ) return str;

            auto max_index = 0ULL,
                max_length = 1ULL,
                index = 0ULL;

            while( index < str.size() )
            {
                auto start = index, end = index;

                while( end + 1 < str.size() && str[ end ] == str[ end + 1 ] )
                {
	                end++;
                }

                index = end + 1;

                while( start > 0 && end < str.length() && 
						str[ start - 1 ] == str[ end + 1 ] )
                {
                    start--, end++;
                }

                const auto current = end - start + 1;

                if( current >= max_length )
                {
                    max_index = start;
                    max_length = current;
                }
            }

            return str.substr( max_index, max_length );
        }
    };
}