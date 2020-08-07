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
}