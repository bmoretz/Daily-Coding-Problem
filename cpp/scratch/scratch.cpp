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

class sort_arr_quick
{
    static void qsort( std::vector<int>& numbers, const int low, const int high )
    {
        if( high <= low ) return;

        const auto part = partition( numbers, low, high );

        qsort( numbers, low, part - 1 );
        qsort( numbers, part + 1, high );
    }

    static int partition( std::vector<int>& numbers, const int low, const int high )
    {
	    const auto pivot = numbers[ high ];

	    auto left = low;

        for( auto right = low; right < high; ++right )
        {
            if( numbers[ right ] < pivot )
            {
                const auto tmp = numbers[ left ];
                numbers[ left ] = numbers[ right ];
                numbers[ right ] = tmp;

                ++left;
            }
        }

        const auto tmp = numbers[ left ];
        numbers[ left ] = numbers[ high ];
        numbers[ high ] = tmp;

        return left;
    }

public:
	
    static std::vector<int> sortArray( std::vector<int>& nums )
    {
        const auto N = nums.size();

        qsort( nums, 0, N - 1 );

        return nums;
    }
};

auto main() -> int
{
    auto input = std::vector<int>{ 3, 1, 3 };
	
    auto actual = sort_arr_quick::sortArray( input );

    const auto expected = std::vector<int>{ 1, 2, 3, 5 };
	
	return 0;
}