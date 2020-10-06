#include <bits/stdc++.h>

/* 42. Trapping Rain Water.

Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
(blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class trapping_rain_water {

    static std::vector<int> get_left_max( const std::vector<int>& numbers )
    {
        auto vec = std::vector<int>( numbers.size() );
        vec[ 0 ] = numbers[ 0 ];

        for( auto index = 1; index < numbers.size(); ++index )
        {
            vec[ index ] = std::max( numbers[ index ], vec[ index - 1 ] );
        }

        return vec;
    }

    static std::vector<int> get_right_max( const std::vector<int>& numbers )
    {
        auto vec = std::vector<int>( numbers.size() );
        vec[ numbers.size() - 1 ] = numbers[ numbers.size() - 1 ];

        for( int index = numbers.size() - 2; index >= 0; --index )
        {
            vec[ index ] = std::max( numbers[ index ], vec[ index + 1 ] );
        }

        return vec;
    }

public:

    static int trap( const std::vector<int>& height )
    {
        if( height.empty() ) return 0;

        auto left = get_left_max( height );
        auto right = get_right_max( height );

        auto result = 0;

        for( auto index = 1; index < height.size() - 1; ++index )
        {
            result += std::min( left[ index ], right[ index ] ) - height[ index ];
        }

        return result;
    }
};

auto main() -> int
{
    const auto input1 = std::vector<int>{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    const auto actual = trapping_rain_water::trap( input1 );
	
    const auto expected = 6;
	
	return 0;
}
