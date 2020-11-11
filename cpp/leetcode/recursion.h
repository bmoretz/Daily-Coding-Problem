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

    /*22. Generate Parentheses.

    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    Example 1:

    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
    Example 2:

    Input: n = 1
    Output: ["()"]

    Constraints:

    1 <= n <= 8
    */
	
    class gen_parenthesis
    {
        static bool is_valid( const std::string& str )
        {
            auto balance = 0;

            for( auto c : str )
            {
                if( c == '(' )
                    ++balance;
                else
                    --balance;

                if( balance < 0 )
                    return false;
            }

            return balance == 0;
        }

        static void generate( std::vector<std::string>& results,
            std::string& current, const int pos )
        {
            // if we have a full length string end the recursion
            if( pos == current.length() )
            {
                // if this set is valid, save it
                if( is_valid( current ) )
                    results.push_back( current );
            }
            else
            {
                // other wise, generate pairs with open
                current[ pos ] = '(';
                generate( results, current, pos + 1 );
                // backtrack the current char and generate all subpairs starting with
                // a closing brace
                current[ pos ] = ')';
                generate( results, current, pos + 1 );
            }
        }

    public:

        static std::vector<std::string> generate_parenthesis( const int n )
        {
            auto combinations = std::vector<std::string>();

            // create a buffer string of 2*n length (2 chars for each pair)
            auto buff = std::string( n * 2, ' ' );

            // gen recursively
            generate( combinations, buff, 0 );

            return combinations;
        }
    };

    class gen_parens_iter
    {
        static bool is_valid( const std::string& input )
        {
            auto balance = 0;

            for( auto chr : input )
            {
                if( chr == '(' )
                {
                    ++balance;
                }
                else
                {
                    if( balance == 0 )
                        return false;

                    --balance;
                }
            }

            return balance == 0;
        }

    public:

        static std::vector<std::string> generate_parenthesis( const int n )
        {
            const auto len = 2 * n;

            auto candidates = std::vector<std::string>();

            candidates.emplace_back( len, ' ' );
            candidates.emplace_back( len, ' ' );

            auto seen = std::set<std::string>();

            for( auto index = 0; index < len; ++index )
            {
                auto temp = std::vector<std::string>();

                for( auto str : candidates )
                {
                    str[ index ] = '(';

                    if( index < len - 1 )
                    {
                        temp.emplace_back( str.begin(), str.end() );
                    }
                    else
                    {
                        if( is_valid( str ) && seen.find( str ) == seen.end() )
                        {
                            seen.insert( str );
                        }
                    }

                    str[ index ] = ')';

                    if( index < len - 1 )
                    {
                        temp.emplace_back( str.begin(), str.end() );
                    }
                    else
                    {
                        if( is_valid( str ) && seen.find( str ) == seen.end() )
                        {
                            seen.insert( str );
                        }
                    }
                }

                candidates = temp;
            }

            return std::vector<std::string>( seen.begin(), seen.end() );
        }
    };
	
    /* 273. Integer to English Words.

    Convert a non-negative integer num to its English words representation.

    Example 1:

    Input: num = 123
    Output: "One Hundred Twenty Three"
    Example 2:

    Input: num = 12345
    Output: "Twelve Thousand Three Hundred Forty Five"
    Example 3:

    Input: num = 1234567
    Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
    Example 4:

    Input: num = 1234567891
    Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

    Constraints:

    0 <= num <= 231 - 1
    */

    class number_to_english {

        static inline std::unordered_map<int, std::string> under_twenty_ =
        {
            { 0, "Zero" },
            { 1, "One" },
            { 2, "Two" },
            { 3, "Three" },
            { 4, "Four" },
            { 5, "Five" },
            { 6, "Six" },
            { 7, "Seven" },
            { 8, "Eight" },
            { 9, "Nine" },
            { 10, "Ten" },
            { 11, "Eleven" },
            { 12, "Twelve" },
            { 13, "Thirteen" },
            { 14, "Fourteen" },
            { 15, "Fifteen" },
            { 16, "Sixteen" },
            { 17, "Seventeen" },
            { 18, "Eighteen" },
            { 19, "Nineteen" }
        };

        static inline std::unordered_map<int, std::string> tens_ =
        {
            {10, "Ten"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"}
        };

        static inline std::unordered_map<int, std::string> places_ =
        {
            { 1e2, "Hundred" },
            { 1e3, "Thousand" },
            { 1e4, "Ten Thousand" },
            { 1e5, "Hundred Thousand" },
            { 1e6, "Million" },
            { 1e7, "Ten Million" },
            { 1e8, "Hundred Million" },
            { 1e9, "Billion" }
        };

    public:

        static inline int billion = 1e9;
        static inline int hundred_million = 1e8;
        static inline int ten_million = 1e7;
        static inline int million = 1e6;
        static inline int hundred_thousand = 1e5;
        static inline int ten_thousand = 1e4;
        static inline int thousand = 1e3;
        static inline int hundred = 1e2;
        static inline int ten = 1e1;

        static std::string get_english( int num )
        {
            if( num >= billion )
            {
                std::cout << num;

                const auto digit = num / billion;

                const auto current = get_english( digit ) + ' ' + places_[ billion ];

                const auto rem = num % billion;

                return current + ( rem == 0 ? "" : ' ' + get_english( rem ) );
            }

            if( num >= hundred_million )
            {
                const auto digit = num / million;

                const auto current = get_english( digit ) + ' ' + places_[ million ];

                const auto rem = num % million;

                return current + ( rem == 0 ? "" : ' ' + get_english( rem ) );
            }

            if( num >= ten_million )
            {
                const auto digit = num / million;

                const auto current = get_english( digit ) + ' ' + places_[ million ];

                const auto rem = num % million;

                return current + ( rem == 0 ? "" : ' ' + get_english( rem ) );
            }

            if( num >= million )
            {
                const auto digit = num / million;

                const auto current = under_twenty_[ digit ] + ' ' + places_[ million ];

                const auto rem = num % million;

                return current + ( rem == 0 ? "" : ' ' + get_english( rem ) );
            }

            if( num >= hundred_thousand )
            {
                auto digit = num / thousand;
                const auto current = get_english( digit ) + ' ' + places_[ thousand ];

                const auto rem = num % thousand;

                return current + ( rem == 0 ? "" : ' ' + get_english( num % thousand ) );
            }

            if( num >= ten_thousand )
            {
                auto digit = num / thousand;
                const auto current = get_english( digit ) + ' ' + places_[ thousand ];

                const auto rem = num % thousand;

                return current + ( rem == 0 ? "" : ' ' + get_english( num % thousand ) );
            }

            if( num >= thousand )
            {
                auto digit = num / thousand;
                const auto current = under_twenty_[ digit ] + ' ' + places_[ thousand ];

                const auto rem = num % thousand;

                return current + ( rem == 0 ? "" : ' ' + get_english( num % thousand ) );
            }

            if( num >= 100 )
            {
                auto digit = num / hundred;

                const auto current = get_english( digit ) + ' ' + places_[ hundred ];

                auto rem = num % hundred;

                return current + ( rem == 0 ? "" : ' ' + get_english( rem ) );
            }

            if( num >= 20 )
            {
                auto digit = num / ten;

                const auto current = tens_[ digit * 10 ];

                auto rem = num % ten;

                return current + ( rem == 0 ? "" : ' ' + get_english( rem ) );
            }

            return under_twenty_[ num ];
        }

        static std::string number_to_words( const int num )
        {
            if( num == 0 ) return "Zero";

            return get_english( num );
        }
    };

    /*494. Target Sum.

    You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2
    symbols + and -. For each integer, you should choose one from + and - as its new symbol.

    Find out how many ways to assign symbols to make sum of integers equal to target S.

    Example 1:

    Input: nums is [1, 1, 1, 1, 1], S is 3.
    Output: 5
    Explanation:

    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3

    There are 5 ways to assign symbols to make the sum of nums be target 3.

    Constraints:

    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.
    */

    class target_sum_rec
    {
        static void flip_pos( const std::vector<int>& numbers, const int index,
            const int sum, const int target, int& result )
        {
            if( index == numbers.size() )
            {
                if( sum == target )
                    result++;
            }
            else
            {
                flip_pos( numbers, index + 1, sum + numbers[ index ], target, result );
                flip_pos( numbers, index + 1, sum - numbers[ index ], target, result );
            }
        }

    public:

        static int find_target_sum_ways( const std::vector<int>& numbers, const int target )
        {
            auto result = 0;

            flip_pos( numbers, 0, 0, target, result );

            return result;
        }
    };

}