#include <bits/stdc++.h>

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

class number_to_english
{
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

auto main() -> int
{
	const auto input = 1234567891;
    auto actual = number_to_english::number_to_words( input );

    const auto expected = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";
	
	return 0;
}