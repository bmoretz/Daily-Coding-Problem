#include <bits/stdc++.h>

/*912. Sort an Array.

Given an array of integers nums, sort the array in ascending order.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
*/

class sort_arr_merge
{
    static std::vector<int> merge_sort( const std::vector<int>& numbers )
    {
        const auto n = numbers.size();
    	
        if( n <= 1 )
            return numbers;

        const int pivot = n/2;

        auto left = merge_sort( std::vector<int>( numbers.begin(), numbers.begin() + pivot ) );
        auto right = merge_sort( std::vector<int>( numbers.begin() + pivot, numbers.end() ));

        auto result = std::vector<int>( n );

        auto left_ptr = 0, right_ptr = 0;

        for( auto index = 0; index < n; ++index )
        {
            const auto left_val = left_ptr < left.size() ? left[ left_ptr ] : INT_MAX;
            const auto right_val = right_ptr < right.size() ? right[ right_ptr ] : INT_MAX;
        	
            if( left_val < right_val )
            {
                result[ index ] = left[ left_ptr++ ];
            }
            else
            {
                result[ index ] = right[ right_ptr++ ];
            }
        }

        return result;
    }

public:

    static std::vector<int> sortArray( std::vector<int>& numbers )
    {
        return merge_sort( numbers );
    }
};

auto main() -> int
{
    auto input = std::vector<int>{ 3, 1, 3 };
	
    auto actual = sort_arr_merge::sortArray( input );

    const auto expected = std::vector<int>{ 1, 2, 3, 5 };
	
	return 0;
}