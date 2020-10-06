#include <bits/stdc++.h>

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

auto main() -> int
{
    const auto input1 = std::pair<std::vector<int>, std::vector<int>>( {1, 3}, {2} );
	
    const auto actual = median_of_two_sorted_arr::find_median_sorted_arrays( input1.first, input1.second );
	
    const auto expected = 6;
	
	return 0;
}
