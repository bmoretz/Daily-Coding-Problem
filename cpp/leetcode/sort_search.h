#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

namespace leetcode::sort_search
{
	/* 153. Find Minimum in Rotated Sorted Array.

	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

	(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

	Find the minimum element.

	You may assume no duplicate exists in the array.

	Example 1:
	Input: [3,4,5,1,2]
	Output: 1

	Example 2:
	Input: [4,5,6,7,0,1,2]
	Output: 0
	*/

	class rotated_min
	{
	public:

		static int findMin( const std::vector<int>& numbers )
		{
			if( numbers.empty() ) return 0;

			int start = 0, stop = numbers.size() - 1;

			while( numbers.at( start ) > numbers.at( stop ) )
			{
				const auto mid = ( start + stop ) / 2;

				if( numbers.at( start ) > numbers.at( mid ) )
				{
					stop = mid;
				}
				else
				{
					start = mid + 1;
				}
			}

			return numbers.at( start );
		}
	};
}