#include <bits/stdc++.h>

/* 16. 3Sum Closest.

Given an array nums of n integers and an integer target, find three integers in nums such that the sum
is closest to target. Return the sum of the three integers. You may assume
that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class tree_sum_closest_sw
{

public:

    static int three_sum_closest( std::vector<int>& numbers, 
        const int target )
    {
        int diff = std::numeric_limits<int>::max(), N = numbers.size();

        std::sort( numbers.begin(), numbers.end() );

        for( auto index = 0; index < N && diff != 0; ++index )
        {
	        auto low = index + 1, high = N - 1;

            while( low < high )
            {
                const auto sum = numbers[ index ] + numbers[ low ] + numbers[ high ];

                if( abs( target - sum ) < abs( diff ) )
                {
                    diff = target - sum;
                }

                if( sum < target )
                {
                    ++low;
                }
                else
                {
                    --high;
                }
            }
        }

        return target - diff;
    }
};

auto main() -> int
{
    auto input1 = std::pair<std::vector<int>, int> ( 
        { -1, 2, 1, -4 },
        1
    );
	
    const auto actual = tree_sum_closest_sw::three_sum_closest( input1.first, input1.second );
	
    const auto expected = 2;
	
	return 0;
}
