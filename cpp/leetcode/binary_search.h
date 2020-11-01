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
        static int find_closest( const std::vector<int>& arr, const int target )
        {
            const int N = arr.size();
            auto left = 0, right = N - 1;

            // binary search that will return
            // the exact element if found,
            // otherwies left and right will
            // point to the two closest elements
            // to the target
            while( left + 1 < right )
            {
                const auto mid = left + ( right - left ) / 2;

                if( arr[ mid ] == target )
                    return mid;

                if( arr[ mid ] < target )
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }

            // there is no exact match, so look at the delta 
            // between the two remaining elements pointed to
            // by left/right pointers, and return the index
            // of the element of the closer one (ties going)
            // to the smaller number
            return std::abs( target - arr[ left ] ) <=
                std::abs( target - arr[ right ] ) ?
                left : right;
        }

    public:

        // Log(N) + K
        static std::vector<int> findClosestElements( const std::vector<int>& arr,
            const int k, const int x )
        {
            // start with the index of the cloest element
            // Log(N)
            const auto closest = find_closest( arr, x );

            // left and right both point to the closest element,
            // and we have 1 result (the closest), so we need
            // an additional k-1 elements.
            auto left = closest, right = closest, remain = k - 1;

            // here, we preprocess the indexes of the elements in the
            // result space so that if we move right to take an element
            // we dont have to use push_back/insert in the result vector
            // because the insert for the smaller elements would be O(K)
            // where K is the number of elements smaller than the target
            // that would be in our result set.

            // use two-pointers approach to expand the search space
            while( remain )
            {
                const auto left_delta = left == 0 ? INT_MAX :
                    std::abs( x - arr[ left - 1 ] );

                const auto right_delta = right == arr.size() - 1 ? INT_MAX :
                    std::abs( x - arr[ right + 1 ] );

                // with ties going to the smaller number
                if( left_delta <= right_delta )
                {
                    --left;
                }
                else
                {
                    ++right;
                }

                --remain;
            }

            // build the result vector O(K)
            auto results = std::vector<int>();
            for( auto index = left; index <= right; ++index )
            {
                results.push_back( arr[ index ] );
            }

            return results;
        }
    };

    /*33. Search in Rotated Sorted Array.

    You are given an integer array nums sorted in ascending order, and an integer target.

    Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

    If target is found in the array return its index, otherwise, return -1.

    Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
    Example 3:

    Input: nums = [1], target = 0
    Output: -1


    Constraints:

    1 <= nums.length <= 5000
    -10^4 <= nums[i] <= 10^4
    All values of nums are unique.
    nums is guranteed to be rotated at some pivot.
    -10^4 <= target <= 10^4

    */

    class search_rotated_array
    {
        static int find_rotated_index( const std::vector<int>& arr )
        {
            const auto N = arr.size();

            int low = 0, high = N - 1;

            // if its already sorted
            // return the lower bound
            if( arr[ low ] < arr[ high ] )
                return low;

            while( low <= high )
            {
                const auto mid = low + ( high - low ) / 2;

                // terminal conditions
                if( arr[ mid ] > arr[ mid + 1 ] )
                    return mid + 1;

                if( arr[ mid - 1 ] > arr[ mid ] )
                    return mid;

                // if the number at the pivot
                // is larger than the upper
                // bound, we need to narrow
                // the search to that range
                if( arr[ mid ] > arr[ high ] )
                {
                    low = mid + 1;
                }
                else
                {
                    // otherwise move 
                    // the upperbound down
                    high = mid - 1;
                }
            }

            return 0;
        }

        static int bin_search( const std::vector<int>& arr,
            const int start, const int stop,
            const int target )
        {
            auto low = start, high = stop;

            while( low <= high )
            {
                const auto mid = low + ( high - low ) / 2;

                // check pivot for target
                if( arr[ mid ] == target )
                    return mid;

                // cut search space in half & resume
                if( arr[ mid ] < target )
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            // doesn't exist
            return -1;
        }

    public:

        static int search( const std::vector<int>& numbers, 
            const int target )
        {
            const auto N = numbers.size();

            // for an input of <= 3 we just use a simple
            // linear search to cut out the edge cases
            // for n = 1, n = 2, n = 3;
            if( N <= 3 )
            {
                for( auto index = 0; index < N; ++index )
                {
                    if( numbers[ index ] == target )
                        return index;
                }

                return -1;
            }

            // for N > 3, find the pivot index
            const auto pivot = find_rotated_index( numbers );

            // then partition the search space according to the 
            // two remaining conditions:

            // #1 target is between [0, pivot], where pivot != 0
            if( pivot > 0 && target >= numbers[ 0 ] && target <= numbers[ pivot - 1 ] )
            {
                return bin_search( numbers, 0, pivot - 1, target );
            }

            // #2 target is in [pivot, N-1] (0 inclusive, which also handles the base case of the input being sorted)
            return bin_search( numbers, pivot, N - 1, target );
        }
    };
}