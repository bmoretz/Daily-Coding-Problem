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

		static int find_min( const std::vector<int>& numbers )
		{
			if( numbers.empty() ) return 0;

			auto start = 0ULL, stop = numbers.size() - 1;

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

	/* 4. Median of Two Sorted Arrays.

	Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

	Follow up: The overall run time complexity should be O(log (m+n)).

	Example 1:

	Input: nums1 = [1,3], nums2 = [2]
	Output: 2.00000
	Explanation: merged array = [1,2,3] and median is 2.
	Example 2:

	Input: nums1 = [1,2], nums2 = [3,4]
	Output: 2.50000
	Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
	Example 3:

	Input: nums1 = [0,0], nums2 = [0,0]
	Output: 0.00000
	Example 4:

	Input: nums1 = [], nums2 = [1]
	Output: 1.00000
	Example 5:

	Input: nums1 = [2], nums2 = []
	Output: 2.00000


	Constraints:

	nums1.length == m
	nums2.length == n
	0 <= m <= 1000
	0 <= n <= 1000
	1 <= m + n <= 2000
	-106 <= nums1[i], nums2[i] <= 106
	*/

	class median_of_two_sorted_arr
	{

	public:

		static double find_median_sorted_arrays( const std::vector<int>& nums1, const std::vector<int>& nums2 )
		{
			if( nums1.size() > nums2.size() )
				return find_median_sorted_arrays( nums2, nums1 );

			for( int left = 0, right = nums1.size(); left <= right; )
			{
				const auto pivot1 = ( left + right ) / 2;
				const auto pivot2 = ( nums1.size() + nums2.size() ) / 2 - pivot1;

				const auto l1 = pivot1 == 0 ? INT_MIN : nums1[ pivot1 - 1 ];
				const auto l2 = pivot2 == 0 ? INT_MIN : nums2[ pivot2 - 1 ];
				const auto r1 = pivot1 == nums1.size() ? INT_MAX : nums1[ pivot1 ];
				const auto r2 = pivot2 == nums2.size() ? INT_MAX : nums2[ pivot2 ];

				if( l1 > r2 )
				{
					right = pivot1 - 1;
				}
				else if( l2 > r1 )
				{
					left = pivot1 + 1;
				}
				else
				{
					const auto len = nums1.size() + nums2.size();

					return len % 2 ?
						std::min( r1, r2 ) : ( std::max( l1, l2 ) + std::min( r1, r2 ) ) / 2.;
				}

			}

			return -1;
		}
	};
}