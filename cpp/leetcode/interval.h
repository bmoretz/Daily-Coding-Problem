#pragma once

#include <algorithm>
#include <vector>

namespace leetcode::interval
{
	/* 56. Merge Intervals.

	Given a collection of intervals, merge all overlapping intervals.

	Example 1:

	Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
	Output: [[1,6],[8,10],[15,18]]
	Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

	Example 2:

	Input: intervals = [[1,4],[4,5]]
	Output: [[1,5]]
	Explanation: Intervals [1,4] and [4,5] are considered overlapping.
	NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

	Constraints:

	intervals[i][0] <= intervals[i][1]
	*/

	struct merge_intervals
	{
		static bool are_overlapping( const std::vector<int>& first, const std::vector<int>& second )
		{
			const auto fol = first.front() <= second.front() && second.front() <= first.back();
			const auto sol = second.front() <= first.front() && first.front() <= second.back();

			return fol || sol;
		}

		static std::vector<std::vector<int>> merge( std::vector<std::vector<int>>& intervals )
		{
			if( intervals.size() <= 1 ) return intervals;

			std::sort( intervals.begin(), intervals.end(),
				[]( const auto& first, const auto& second )
				{
					return first[ 0 ] < second[ 0 ];
				} );

			std::vector<std::vector<int>> merged;

			merged.push_back( intervals[ 0 ] );

			auto index = 1UL;

			while( index < intervals.size() )
			{
				auto& last = merged.back();
				auto& cur = intervals.at( index );

				if( are_overlapping( last, cur ) )
				{
					merged.back()[ 1 ] = std::max( merged.back()[ 1 ], cur[ 1 ] );
				}
				else
				{
					if( last.back() < cur.front() )
					{
						merged.push_back( cur );
					}
				}

				++index;
			}

			return merged;
		}
	};

	/* 915. Partition Array into Disjoint Intervals.

	Given an array A, partition it into two (contiguous) subarrays left and right so that:

	Every element in left is less than or equal to every element in right.
	left and right are non-empty.
	left has the smallest possible size.
	Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

	Example 1:

	Input: [5,0,3,8,6]
	Output: 3
	Explanation: left = [5,0,3], right = [8,6]
	Example 2:

	Input: [1,1,1,0,6,12]
	Output: 4
	Explanation: left = [1,1,1,0], right = [6,12]

	Note:

	2 <= A.length <= 30000
	0 <= A[i] <= 10^6
	It is guaranteed there is at least one way to partition A as described.
	*/

	class disjoint_intervals
	{

	public:

		static int partition_disjoint( const std::vector<int>& arr )
		{
			const int n = arr.size();

			std::vector<int> max_left( n ), min_right( n );

			auto max = arr[ 0 ];
			for( auto index = 0ULL; index < n; ++index )
			{
				max = std::max( max, arr[ index ] );

				max_left[ index ] = max;
			}

			auto min = arr[ n - 1 ];
			for( auto index = n - 1; index >= 0; --index )
			{
				min = std::min( min, arr[ index ] );
				min_right[ index ] = min;
			}

			for( auto index = 1; index < n; ++index )
			{
				if( max_left[ index - 1 ] <= min_right[ index ] )
					return index;
			}

			return 0;
		}
	};
}