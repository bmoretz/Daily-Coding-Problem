#pragma once

#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::bitmanip
{
    /* 318. Maximum Product of Word Lengths.

    Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words
    do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

    Example 1:

    Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
    Output: 16
    Explanation: The two words can be "abcw", "xtfn".

    Example 2:

    Input: ["a","ab","abc","d","cd","bcd","abcd"]
    Output: 4
    Explanation: The two words can be "ab", "cd".
    Example 3:

    Input: ["a","aa","aaa","aaaa"]
    Output: 0
    Explanation: No such pair of words.

    Constraints:

    0 <= words.length <= 10^3
    0 <= words[i].length <= 10^3
    words[i] consists only of lowercase English letters.
    */

    struct max_len_unique_prod
    {
        static std::unordered_map<std::string, std::bitset<26>> to_char_map( const std::vector<std::basic_string<char>>& unique_words )
        {
            std::unordered_map<std::string, std::bitset<26>> char_map;

            for( const auto& word : unique_words )
            {
                auto characters = std::bitset<26>();

                for( auto chr : word )
                {
                    characters |= 1 << ( chr - 'a' );
                }

                char_map[ word ] = characters;
            }

            return char_map;
        }

        static int max_product( const std::vector<std::string>& words )
        {
            // build a lookup of words -> character bit sets
            const auto char_map = to_char_map( words );

            auto max_len = std::size_t();

            for( auto outer = std::size_t(); outer < words.size(); ++outer )
            {
                const auto& left = words[ outer ];

                for( auto inner = outer + 1; inner < words.size(); ++inner )
                {
                    const auto& right = words[ inner ];

                    if( ( char_map.at( left ) & char_map.at( right ) ) == 0 )
                    {
                        max_len = std::max( max_len, left.size() * right.size() );
                    }
                }
            }

            return max_len;
        }
    };
}