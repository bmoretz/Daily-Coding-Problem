#include <bits/stdc++.h>

/*218. The Skyline Problem.

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are
given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by
these buildings collectively (Figure B).

Buildings Skyline Contour

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and
right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You
may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is
the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline,
and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable;
the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

class skyline
{
public:

	static std::vector<std::vector<int>> get_skyline( std::vector<std::vector<int>>& buildings )
    {
        // the skyline can only change at the critical points which are either the beginning
        // or the end of a building
        std::set<int> critical;

    	for( auto bldg : buildings ) 
        {
            critical.insert( bldg[ 0 ] );
            critical.insert( bldg[ 1 ] );
        }

        std::vector<std::vector<int>> skyline;

        auto last_height = 0;

        std::priority_queue<std::pair<int, int>> active;

        auto bldg = buildings.begin();

        for( const auto crit : critical ) 
        {
            // any building that started on or before the critical point could be active at
            // the critical point
            while( bldg != buildings.end() and bldg->at( 0 ) <= crit )
            {
                active.push( { bldg->at( 2 ), bldg->at( 1 ) } );
                ++bldg;
            }

            // any building that ends or or before the critical point is not active at
            // the critical point
            while( !active.empty() and active.top().second <= crit )
                active.pop();

            // the height at the critical point is simply the tallest active building
            // note: no active building implies we are at the right edge of a building
            //       hence height is zero.
            int height = 0;
            if( !active.empty() )
                height = active.top().first;

            // the skyline only changes when the height at a critical point changes
            if( height != last_height )
            {
                skyline.push_back( { crit, height } );
                last_height = height;
            }
        }

        return skyline;
    }
};

auto main() -> int
{
    auto input = std::vector<std::vector<int>>
    {
        { 2, 9, 10 },
        { 3, 7, 15 },
        { 5, 12, 12 },
        { 15, 20, 10 },
        { 19, 24, 8 }
    };
	
    const auto actual = skyline::get_skyline( input );

    const auto expected = std::vector<std::vector<int>>
    {
        {2, 10},
        {3, 15},
        {7, 12},
        {12, 0},
        {15, 10},
        {20, 8},
    	{24, 0}
    };
	
	return 0;
}