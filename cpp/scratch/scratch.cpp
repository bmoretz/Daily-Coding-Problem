#include <bits/stdc++.h>

/*189. Rotate Array.

Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

*/

class rotate_array
{
public:

	/// <summary>
	/// rotate 1
	///
	/// O(N) run-time, O(N) space
	/// </summary>
	/// <param name="numbers">array to rotate</param>
	/// <param name="k">number of places</param>
	static void rotate1( std::vector<int>& numbers, const std::size_t k )
	{	
		const auto N = numbers.size();
		const auto places = k % N;

		if( places == 0 ) return;
		
		auto temp = std::vector<int>( N, 0 );

		auto ptr = N - places, pos = std::size_t();

		while( ptr < N )
		{
			temp[ pos++ ] = numbers[ ptr++ ];
		}

		ptr = 0;

		while( ptr < N - places )
		{
			temp[ pos++ ] = numbers[ ptr++ ];
		}

		std::swap( temp, numbers );
	}

	/// <summary>
	/// rotate 2
	///
	/// O(N) run-time, O(k) space
	/// </summary>
	/// <param name="numbers">array to rotate</param>
	/// <param name="k">number of places</param>
	static void rotate2( std::vector<int>& numbers, const std::size_t k )
	{
		const auto N = numbers.size();
		const auto places = k % N;

		if( places == 0 ) return;
		
		auto temp = std::vector<int>( places, 0 );

		auto ptr = N - places, pos = std::size_t();

		while( ptr < N )
		{
			temp[ pos++ ] = numbers[ ptr++ ];
		}

		ptr = N - 1, pos = N - places - 1;
		
		while( ptr >= places )
		{
			numbers[ ptr-- ] = numbers[ pos-- ];
		}
		
		ptr = 0, pos = 0;

		while( ptr < places )
		{
			numbers[ pos++ ] = temp[ ptr++ ];
		}
	}

	/// <summary>
	/// rotate 3
	///
	/// O(N) run-time, O(1) space
	/// </summary>
	/// <param name="numbers">array to rotate</param>
	/// <param name="k">number of places</param>
	static void rotate3( std::vector<int>& numbers, const std::size_t k )
    {
		const auto N = numbers.size();
		const auto places = k % N;

		auto ptr = std::size_t();

		for( auto pos = std::size_t(); ptr < N; pos++ )
		{
			auto current = pos;
			auto prev = numbers[ pos ];

			do
			{
				const auto next = ( current + places ) % N;
				const auto temp = numbers[ next ];
				numbers[ next ] = prev;
				prev = temp;
				current = next;
				ptr++;
			} while( pos != current );
		}
    }
};

auto main() -> int
{
    auto input = std::vector<int>{ 1,2,3,4,5,6,7 };
	
    rotate_array::rotate3( input, 2 );
	
	const auto expected = 4;
	
	return 0;
}