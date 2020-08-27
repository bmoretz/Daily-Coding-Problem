#include <bits/stdc++.h>
#include <array>

/*78. Subsets.

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class subsets
{
public:
	
	static std::vector<std::vector<int>> generate( const std::vector<int>& numbers )
	{
		std::vector<std::vector<int>> perms;

		if( numbers.empty() )
			return perms;

		auto temp = std::vector<int>{ };

		perms.push_back( temp );

		for( auto number : numbers )
		{
			const auto len = perms.size();

			for( auto inner = 0ULL; inner < len; ++inner )
			{
				temp = perms[ inner ];
				temp.push_back( number );
				perms.push_back( temp );
			}
		}

		return perms;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<int>{ 1, 2, 3 };

	const auto result = subsets::generate( input1 );
	
	return 0;
}