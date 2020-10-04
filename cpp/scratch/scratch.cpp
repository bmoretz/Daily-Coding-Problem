#include <bits/stdc++.h>

/* 238. Product of Array Except Self.

Given an array nums of n integers where n > 1,  return an array output such
that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class prod_except_self
{
public:
	
    static std::vector<int> product_except_self( const std::vector<int>& nums )
    {
        int N = nums.size();

        auto left = std::vector<int>( N );
        left[ 0 ] = 1;

        for( auto index = 1; index < N; ++index )
        {
            left[ index ] = nums[ index - 1 ] * left[ index - 1 ];
        }

        auto right = std::vector<int>( N );
        right[ N - 1 ] = 1;

        for( auto index = N - 2; index >= 0; --index )
        {
            right[ index ] = nums[ index + 1 ] * right[ index + 1 ];
        }

        auto result = std::vector<int>( N );

        for( auto index = 0; index < N; ++index )
        {
            result[ index ] = left[ index ] * right[ index ];
        }

        return result;
    }
};

auto main() -> int
{
    const auto actual = prod_except_self::product_except_self( { 1, 2, 3, 4 } );
    const auto expected = std::vector<int>{ 24, 12, 8, 6 };
	
	return 0;
}
