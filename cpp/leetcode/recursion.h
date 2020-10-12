#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::recursion
{
    /*17. Letter Combinations of a Phone Number.

    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number
    could represent. Return the answer in any order.

    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Example 1:

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    Example 2:

    Input: digits = ""
    Output: []
    Example 3:

    Input: digits = "2"
    Output: ["a","b","c"]


    Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
    */

    class phone_book_combinations
    {
        static inline std::map<int, std::vector<char>> digit_map_ = std::map<int, std::vector<char>>{
            {2, {'a', 'b', 'c'}},
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}}
        };

        static void gen_perms( std::vector<std::string>& results,
            const std::string& digits, const std::string& cur,
            const int index )
        {
            if( cur.length() == digits.length() )
            {
                results.push_back( cur );
                return;
            }

            const auto cur_digit = digits[ index ] - '0';

            for( auto chr : digit_map_[ cur_digit ] )
            {
                gen_perms( results, digits, cur + chr, index + 1 );
            }
        }

    public:

        static std::vector<std::string> letter_combinations( const std::string& digits )
        {
            std::vector<std::string> results;

            if( digits.empty() ) return results;

            gen_perms( results, digits, "", 0 );

            return results;
        }
    };
}