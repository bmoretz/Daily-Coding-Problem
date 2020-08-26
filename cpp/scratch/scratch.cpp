#include <bits/stdc++.h>
#include <array>

/*1207. Unique Number of Occurrences.

Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

class unique_occurrences
{
	static std::unordered_map<int, int> to_map( const std::vector<int>& values )
	{
		std::unordered_map<int, int> map;

		for( auto val : values )
		{
			++map[ val ];
		}

		return map;
	}
	
public:
	
	static bool uniqueOccurrences( const std::vector<int>& values )
	{
		const auto map = to_map( values );

		auto unique = std::set<int>();

		for( auto& [key, value] : map )
		{
			unique.insert( value );
		}
		
		return unique.size() == map.size();
	}
};

auto main() -> int
{
	const auto input1 = std::vector<int>{ 1, 2, 2, 1, 1, 3 };
	const auto input2 = std::vector<int>{ 1, 8, 3, 5 };
	const auto input3 = std::vector<int>{ 3354, 4316, 3259, 4904, 4598, 474, 3166, 6322, 8080, 9009 };
	const auto input4 = std::vector<int>{ 2, 4, 3 };
	const auto input5 = std::vector<int>{ 2, 4, 3 };
	
	// const auto actual = word_break::wordBreak( input2.first, input2.second );
	const auto actual = unique_occurrences::uniqueOccurrences( input3 );

	return 0;
}