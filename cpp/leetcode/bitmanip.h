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
        static std::unordered_map<std::string, std::bitset<26>>
    		to_char_map( const std::vector<std::basic_string<char>>& unique_words )
        {
            std::unordered_map<std::string, std::bitset<26>> char_map;

            for( const auto& word : unique_words )
            {
                auto characters = std::bitset<26>();

                for( auto chr : word )
                {
                    characters |= 1ULL << ( chr - 'a' );
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

    /* 1310. XOR Queries of a Subarray.

    Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR
    of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.

    Example 1:

    Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]

    Output: [2,7,14,8]
    Explanation:
    The binary representation of the elements in the array are:
    1 = 0001
    3 = 0011
    4 = 0100
    8 = 1000
    The XOR values for queries are:
    [0,1] = 1 xor 3 = 2
    [1,2] = 3 xor 4 = 7
    [0,3] = 1 xor 3 xor 4 xor 8 = 14
    [3,3] = 8

    Example 2:

    Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
    Output: [8,0,4,4]


    Constraints:

    1 <= arr.length <= 3 * 10^4
    1 <= arr[i] <= 10^9
    1 <= queries.length <= 3 * 10^4
    queries[i].length == 2
    0 <= queries[i][0] <= queries[i][1] < arr.length
    */
	
    class xor_sub_query
    {
    public:

        /// <summary>
        /// xor queries, dynamic programming approach
        /// </summary>
        /// <param name="arr">array of integers</param>
        /// <param name="queries">array of query indexes</param>
        /// <returns>arr containing the results of the queries</returns>
        static std::vector<int> xor_queries( const std::vector<int>& arr,
            const std::vector<std::vector<int>>& queries )
        {
            const auto n = arr.size();

            std::vector<int> lookup( n + 1, 0 );

            // precompute lookup table
            for( auto index = std::size_t(); index < n; ++index )
            {
                lookup[ index + 1 ] = lookup[ index ] ^ arr[ index ];
            }

            // calculate query results
            std::vector<int> results( queries.size() );

            for( auto index = std::size_t(); index < queries.size(); ++index )
            {
                const std::size_t left = queries[ index ][ 0 ];
                const std::size_t right = queries[ index ][ 1 ];

                results[ index ] = lookup[ right + 1 ] ^ lookup[ left ];
            }

            return results;
        }
    };
}