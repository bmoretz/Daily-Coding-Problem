#include <bits/stdc++.h>

/*136. Single Number.

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?


Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

*/

class single_number
{
	
public:

	/// <summary>
	/// O(N) run-time, O(1) space
	/// </summary>
	/// <param name="numbers">numbers</param>
	/// <returns>the number with 1 occurence</returns>
	static int singleNumber1( const std::vector<int>& numbers )
	{
		auto counts = std::unordered_map<int, int>();

		for( auto num : numbers )
		{
			counts[ num ]++;
		}

		for( auto& [k, v] : counts )
		{
			if( v == 1 ) return k;
		}

		return -1;
	}

	/// <summary>
	/// O(N) run-time, O(1) space
	/// </summary>
	/// <param name="numbers">numbers</param>
	/// <returns>number with 1 occurence.</returns>
	static int singleNumber2( const std::vector<int>& numbers )
	{
		auto seen = 0;
		
		for( auto num : numbers ) 
		{
			seen ^= num;
		}
		
		return seen;
	}
};

auto main() -> int
{

	return 0;
}