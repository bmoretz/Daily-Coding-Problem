#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::hashtable
{

	/* 1287. Element Appearing More Than 25% In Sorted Array.

	Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

	Return that integer.

	Example 1:

	Input: arr = [1,2,2,6,6,6,6,7,10]
	Output: 6

	Constraints:

	1 <= arr.length <= 10^4
	0 <= arr[i] <= 10^5
	*/

	struct element_with_most_appearances
	{
		static int find_special_integer( const std::vector<int>& arr )
		{
			std::unordered_map<int, int> counts;
			auto max_freq = -1;

			for( auto cur : arr )
			{
				counts[ cur ]++;

				if( max_freq == -1 || counts[ cur ] > counts[ max_freq ] )
				{
					max_freq = cur;
				}
			}

			return max_freq;
		}
	};
}