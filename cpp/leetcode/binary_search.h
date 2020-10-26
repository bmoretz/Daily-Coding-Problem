#pragma once

#include <array>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

namespace leetcode::binary_search
{
    /*658. Find K Closest Elements.

    Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be
    sorted in ascending order. If there is a tie, the smaller elements are always preferred.

    Example 1:

    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]
    Example 2:

    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4]


    Constraints:

    1 <= k <= arr.length
    1 <= arr.length <= 10^4
    Absolute value of elements in the array and x will not exceed 104
    */

    class find_k_closest_elements
    {
        static int find_closest( const std::vector<int>& arr,
            const int target )
        {
            if( arr.size() == 1 ) return 0;

            const int N = arr.size();
            auto left = 0, right = N - 1;

            // binary search
            while( left < right )
            {
                const auto mid = left + ( right - left ) / 2;

                // if we find the target, return
                // its index.
                if( arr[ mid ] == target )
                    return mid;

                if( arr[ mid ] < target )
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }

            // we haven't found the exact target, so look at the
            // neighbor elements of the closest match, and look at the
            // deltas of the lower & upper elements to the target
            const auto lower_delta = left > 0 ?
                std::abs( target - arr[ left - 1 ] ) : INT_MAX;
            const auto upper_delta = right < N - 1 ?
                std::abs( target - arr[ right ] ) : INT_MAX;

            // return the index of the number closest to the target
            return lower_delta <= upper_delta ? left - 1 : left;
        }

    public:

        static std::vector<int> findClosestElements( const std::vector<int>& arr,
            const int k,
            const int target )
        {
            const auto start = find_closest( arr, target );

            // we already have 1 match that is guaranteed to be in the result
            // set at the index returned by the search, so we only need to find
            // k - 1 closest matches
            auto left = start, right = start, remain = k - 1;

            // find the remaining matches using
            // a two-pointer approach for the elements
            // above and below the closest match
            while( remain > 0 )
            {
                const auto lower_delta = left > 0 ?
                    std::abs( target - arr[ left - 1 ] ) : INT_MAX;

                const auto upper_delta = right < arr.size() - 1 ?
                    std::abs( target - arr[ right + 1 ] ) : INT_MAX;

                // move our pointers up/down based on
                // proximity to the target (<= because ties go to the smaller number)
                if( lower_delta <= upper_delta )
                {
                    --left;
                }
                else
                {
                    ++right;
                }

                --remain;
            }

            // increment right because the ending pointer
            // position must be inclusive of the last element
            // of our subset.
            right++;

            return std::vector<int>( arr.begin() + left, arr.begin() + right );
        }
    };
}