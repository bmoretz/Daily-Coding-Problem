#include <bits/stdc++.h>

#include "../leetcode/tree.h"

using namespace leetcode::tree;

/* 11. Container With Most Water.

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines
are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis
forms a container, such that the container contains the most water.

Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2 

Constraints:

2 <= height.length <= 3 * 104
0 <= height[i] <= 3 * 104
*/

class container_with_most_water
{
public:

    static int max_area( const std::vector<int>& height )
    {
        auto max_area = std::numeric_limits<int>::min();

        // initialize the two pointers
        int left = 0, right = height.size() - 1;

        while( left != right )
        {
            const auto l_val = height[ left ];
            const auto r_val = height[ right ];

            // the area is always going to be the smallest of
            // the two towers * the number bucket
            const auto area = std::min( l_val, r_val ) * ( right - left );

            // if this is bigger than the max area, update it
            max_area = std::max( max_area, area );

            // move past the smaller of the two
            // towers 
            if( l_val < r_val )
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return max_area;
    }
};

auto main() -> int
{
    const auto input1 = std::vector<int>{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    const auto actual = container_with_most_water::max_area( input1 );

    const auto expected = 49;
	
	return 0;
}