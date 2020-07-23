#include <bits/stdc++.h>

/* Minimum Moves to Equal Array Elements II.
 
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal,
where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input: [1,2,3]
Output: 2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

struct Solution
{
	/// <summary>
	/// min moves
	/// </summary>
	/// <complexity>
	///		<run-time>O(n log n)</run-time>
	///		<space>O(1)</space>
	/// </complexity>
	/// <param name="numbers"></param>
	/// <returns>the minimum number of moves to make all the array elements equal</returns>
	int minMoves2( std::vector<int>& numbers ) const
	{
		auto result = 0;
		
		if( !numbers.empty() )
		{
			std::sort( std::begin( numbers ), std::end( numbers ) );
			
			const auto mid = numbers.at( ( numbers.size() - 1 ) / 2 );

			for( auto num : numbers )
			{
				result += std::abs( mid - num );
			}
		}
		
		return result;
	}
};

auto main() -> int
{
	Solution sln;

	auto input1 = std::vector<int>{ 1, 2, 3 };
	auto input2 = std::vector<int>{ 1, 6, 2, 4 };
	auto input3 = std::vector<int>{ 1, 6, 2, 4 };
	auto input4 = std::vector<int>{ 1 };
	auto input5 = std::vector<int>{ 1, 0, 0, 8, 6 };
	auto input6 = std::vector<int>{ 203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143 };
	
	const auto result = sln.minMoves2( input6 );

	std::cout << "Result: " << result;
	
	return 0;
}
