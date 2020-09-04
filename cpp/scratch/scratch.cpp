#include <bits/stdc++.h>
#include <array>

/* 800. Similar RGB Color.

In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

Example 1:
Input: color = "#09f166"
Output: "#11ee66"
Explanation:  
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
Note:

color is a string of length 7.
color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
Any answer which has the same (highest) similarity as the best answer will be accepted.
All inputs and outputs should use lowercase letters, and the output is 7 characters.
*/

class similar_color
{
    static double parse_hex_value( const std::string& color,
        const int offset )
    {
        const auto part = color.substr( offset, 2 );

        return static_cast< double >( std::stoi( "0x" + part, nullptr, 16 ) );
    }

	static std::map<int, std::pair<int, std::string>> build_conversion_map()
    {
        std::map<int, std::pair<int, std::string>> map;

        for( size_t index = 0, step = 0; index < 16; index++, step += 17 )
        {
            const auto offset = index < 10 ? '0' : 'a';
            const auto chr = static_cast< char >( offset ) + ( index > 9 ? index - 10 : index );

            map[ index ] = { step, std::string( 2, chr ) };
        }

        return map;
    }

	static std::string to_hex_color( const std::map<int, std::pair<int, std::string>>& map, 
        std::vector<int>& pieces )
    {
        std::string hex_color = "#";
    	
    	for( auto piece : pieces )
    	{
            hex_color += map.at( piece ).second;
    	}

        return hex_color;
    }
	
public:

    static std::string similarRGB( const std::string& color )
    {
        const auto r_part = parse_hex_value( color, 1 );
        const auto g_part = parse_hex_value( color, 3 );
        const auto b_part = parse_hex_value( color, 5 );

        const auto value_map = build_conversion_map();

        std::vector<int> similar_pieces( 3 );
        auto min_val = std::numeric_limits<int>::max();
        const auto iters = value_map.size();

        for( size_t i = 0; i < iters; i++ )
        {
            for( size_t j = 0; j < iters; j++ )
            {
                for( size_t k = 0; k < iters; k++ )
                {
                    const int val =
                        -std::pow( r_part - value_map.at( i ).first, 2.0 ) -
                        std::pow( g_part - value_map.at( j ).first, 2.0 ) -
                        std::pow( b_part - value_map.at( k ).first, 2.0 );

                    if( std::abs( val ) < min_val )
                    {
                        min_val = std::abs( val );

                        similar_pieces[ 0 ] = i;
                        similar_pieces[ 1 ] = j;
                        similar_pieces[ 2 ] = k;
                    }
                }
            }
        }

        return to_hex_color( value_map, similar_pieces );
    }
};

auto main() -> int
{
	const auto input1 = "#09f166";
	const auto input2 = std::vector<int>{ 1, 1, 1, 0, 6, 12 };

	const auto input3 = std::vector<std::vector<int>>
	{
		{ -5, 4 },
		{ -6, -5 },
		{ 4, 6 }
	};

	const auto input4 = std::vector<std::vector<int>>
	{
		{ -5, 4 },
		{ -6, -5 },
		{ 4, 6 },
		{ 4, 6 },
		{ -5, 2 }
	};
	
	const auto result = similar_color::similarRGB( input1 );
	
	return 0;
}