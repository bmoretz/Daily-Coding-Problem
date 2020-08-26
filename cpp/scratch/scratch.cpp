#include <bits/stdc++.h>
#include <array>

/*1167. Minimum Cost to Connect Sticks.

You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Example 1:

Input: sticks = [2,4,3]
Output: 14

Example 2:

Input: sticks = [1,8,3,5]
Output: 30

Constraints:

1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4
*/

class connect_sticks
{
public:

	/// <summary>
	/// connect sticks
	///
	/// uses a min heap to take the shortest two sticks to make a new stick,
	/// and each time a new stick is created we accumulate the result variable
	/// with the new stick length, and then push the new stick onto the pile. We
	/// quit accumulating the stick lengths once we have a single stick in the pile.
	/// </summary>
	/// <param name="sticks">stick lengths</param>
	/// <returns>minimum sum of their cumulative lengths.</returns>
	static int connectSticks( const std::vector<int>& sticks )
	{
		auto heap = std::vector<int>( sticks );
		auto result = 0;

		std::make_heap( heap.begin(), heap.end(), std::greater<>{} );
		
		while( heap.size() > 1 )
		{
			std::pop_heap( heap.begin(), heap.end(), std::greater<>{} );
			const auto s1 = heap.back();
			heap.pop_back();

			std::pop_heap( heap.begin(), heap.end(), std::greater<>{} );
			const auto s2 = heap.back();
			heap.pop_back();

			const auto new_stick = s1 + s2;
			result += new_stick;

			heap.push_back( new_stick );
		}

		return result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<int>{ 2, 4, 3 };
	const auto input2 = std::vector<int>{ 1, 8, 3, 5 };
	const auto input3 = std::vector<int>{ 3354, 4316, 3259, 4904, 4598, 474, 3166, 6322, 8080, 9009 };
	const auto input4 = std::vector<int>{ 2, 4, 3 };
	const auto input5 = std::vector<int>{ 2, 4, 3 };
	
	// const auto actual = word_break::wordBreak( input2.first, input2.second );
	const auto actual = connect_sticks::connectSticks( input3 );

	return 0;
}