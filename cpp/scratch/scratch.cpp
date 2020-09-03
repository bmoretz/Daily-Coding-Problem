#include <bits/stdc++.h>
#include <array>

/* 973. K Closest Points to Origin.

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/

class closest_to_origin
{
	static auto to_min_distance_heap( const std::vector<std::vector<int>>& points )
	{
		std::priority_queue<
			std::pair<double, std::vector<int>>,
			std::vector<std::pair<double, std::vector<int>>>,
			std::greater<>> heap;

		for( auto& point : points )
		{
			const auto x = -point[ 0 ], y = -point[ 1 ];

			const auto distance = std::sqrt( y * y + x * x );

			heap.push( { distance, point } );
		}

		return heap;
	}
	
public:

	static std::vector<std::vector<int>> kClosest( const std::vector<std::vector<int>>& points, const int K )
	{
		auto heap = to_min_distance_heap( points );

		std::vector<std::vector<int>> result;

		for( auto index = 0; index < K; ++index )
		{
			const auto& [d, point] = heap.top();

			result.push_back( point );

			heap.pop();
		}

		return result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::vector<int>>
	{
		{ 1, 3 },
		{ -2, 2 }
	};

	const auto input2 = std::vector<std::vector<int>>
	{
		{ 3, 3 },
		{ 5, -1 },
		{ -2, 4 }
	};

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
	
	const auto result = closest_to_origin::kClosest( input3, 2 );
	
	return 0;
}