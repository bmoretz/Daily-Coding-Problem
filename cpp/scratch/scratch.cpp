#include <bits/stdc++.h>

/*494. Target Sum.

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2
symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

class target_sum_rec
{
    static void flip_pos( const std::vector<int>& numbers, const int index,
        const int sum, const int target, int& result )
    {
        if( index == numbers.size() )
        {
            if( sum == target )
                result++;
        }
        else
        {
            flip_pos( numbers, index + 1, sum + numbers[ index ], target, result );
            flip_pos( numbers, index + 1, sum - numbers[ index ], target, result );
        }
    }

public:

    static int find_target_sum_ways( const std::vector<int>& numbers, const int target )
    {
        auto result = 0;

        flip_pos( numbers, 0, 0, target, result );

        return result;
    }
};

auto main() -> int
{
    const auto input = std::vector<int> { 1, 1, 1, 1, 1 };
	
    auto actual = target_sum_rec::find_target_sum_ways( input, 3 );
    auto expected = 5;
		
	return 0;
}